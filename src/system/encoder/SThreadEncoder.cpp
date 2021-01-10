#include "SThreadEncoder.h"
#include "../build/SGlobal.h"
#include "../driver/SEncoder25PRSBE.h"

#include <QApplication>
#include <QWidget>
#ifdef S_DEBUG_SYSTEM
#include <QDeadlineTimer>
#include <QDebug>
#endif


SThreadEncoder::SThreadEncoder(QObject *parent) : QThread(parent)
{
    this->setObjectName("SThreadEncoder");

    this->setupWidget();
    this->setConnect();
    this->init();
}

SThreadEncoder::~SThreadEncoder()
{
    this->abort();

    if (this->encoder != nullptr)
    {
        delete this->encoder;
        this->encoder = nullptr;
    }
}

void SThreadEncoder::setupWidget()
{
}

void SThreadEncoder::setConnect()
{
    connect(this, &SThreadEncoder::signalError, [this]{ this->m_running = false; });
    connect(this, &SThreadEncoder::signalError, this, &SThreadEncoder::signalRun);
}

void SThreadEncoder::init()
{
    QMutexLocker locker(&this->mutex);

    if (!this->isRunning())
    {
        this->start(QThread::TimeCriticalPriority);
    }
    else
    {
        this->m_restart = true;
    }
}

void SThreadEncoder::resume()
{
    if (this->m_running)
    {
        emit this->signalRun(true);
    }

    QMutexLocker locker(&this->mutex);
    this->m_pause = false;
    this->condition.wakeOne();
}

void SThreadEncoder::pause()
{
    emit this->signalRun(false);

    QMutexLocker locker(&this->mutex);
    this->m_pause = true;
}

void SThreadEncoder::stop()
{
    emit this->signalRun(false);

    QMutexLocker locker(&this->mutex);
    this->m_pause = true;
}

void SThreadEncoder::abort()
{
    this->mutex.lock();
    this->m_abort = true;
    this->mutex.unlock();

    this->m_init = false;
    this->m_restart = false;
    this->m_pause = false;

    this->terminate();
    this->wait(100);
}

void SThreadEncoder::run()
{
    forever
    {
#ifdef S_DEBUG_SYSTEM
        QDeadlineTimer deadline(50);
        do {
        } while (!deadline.hasExpired() && !this->m_abort && !this->m_pause);
#endif
        // Pause thread
        this->mutex.lock();
        if (this->m_pause)
        {
            // thread stop to execute until someone calls resume()
            this->condition.wait(&this->mutex);
        }
        this->mutex.unlock();


        // Abort
        if (this->m_abort)
        {
            this->m_abort = false;
            return;
        }

        // Init
        if (!this->m_init)
        {
#ifdef S_DEBUG_SYSTEM
            if (false)
#else
            if (this->encoder != nullptr)
            {
                delete this->encoder;
                this->encoder = nullptr;
            }

            this->encoder = new SEncoder25PRSBE;
            if (!this->encoder->init())
#endif
            {
                this->m_init = false;
                this->m_pause = true;

                emit this->signalError();
            }
            else
            {
                this->m_init = true;
            }

            continue;
        }

        // Restart / Resume
        if (this->m_restart)
        {
            this->m_restart = false;
            break;
        }

        // Get process data
#ifdef S_DEBUG_SYSTEM
        int retval = 0;
        this->m_data = -10.123;
#else
        int retval = this->encoder->get(&this->m_data);
#endif
        if (retval == -1)
        {
            emit this->signalError();
            this->abort();
        }
        else if (retval == -2)
        {
            emit this->signalError();
            this->m_pause = true;
        }
        else if (retval == 0)
        {
            if (!this->m_running)
            {
                emit this->signalRun(true);
            }
            this->m_running = true;

            emit this->signalData(this->m_data);
        }
    }
}
