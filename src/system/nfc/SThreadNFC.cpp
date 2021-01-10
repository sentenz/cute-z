#include "SThreadNFC.h"
#include "../build/SGlobal.h"
#include "../utils/nfcmfclassic.hpp"

#include <QApplication>
#include <QWidget>
#ifdef S_DEBUG_SYSTEM
#include <QDeadlineTimer>
#include <QDebug>
#endif


SThreadNFC::SThreadNFC(QObject * parent)
    : QThread(parent)
{
    this->setObjectName("SThreadNFC");

    this->setupWidget();
    this->setConnect();
    this->init();
}

SThreadNFC::~SThreadNFC()
{
    this->abort();

    if (this->nfc != nullptr)
    {
        delete this->nfc;
        this->nfc = nullptr;
    }
}

void SThreadNFC::setupWidget()
{
}

void SThreadNFC::setConnect()
{
    connect(this, &SThreadNFC::signalError, [this]{ this->m_running = false; });
    connect(this, &SThreadNFC::signalError, this, &SThreadNFC::signalRun);
}

void SThreadNFC::init()
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

void SThreadNFC::resume()
{
    if (this->m_running)
    {
        emit this->signalRun(true);
    }

    QMutexLocker locker(&this->mutex);
    this->m_pause = false;
    this->condition.wakeOne();
}

void SThreadNFC::pause()
{
    emit this->signalRun(false);

    QMutexLocker locker(&this->mutex);
    this->m_pause = true;
}

void SThreadNFC::stop()
{
    emit this->signalRun(false);

    QMutexLocker locker(&this->mutex);
    this->m_pause = true;
}

void SThreadNFC::abort()
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

void SThreadNFC::run()
{
    forever
    {
#ifdef S_DEBUG_SYSTEM
        QDeadlineTimer deadline(1000);
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
            if (this->nfc != nullptr)
            {
                delete this->nfc;
                this->nfc = nullptr;
            }

            this->nfc = new NfcMfClassic;
            if (this->nfc->init() < 0)
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

        // Emit signal run one time
        if (!this->m_running)
        {
            emit this->signalRun(true);
        }
        this->m_running = true;

        // Read/Write data
        switch (this->m_mode)
        {
        case NFC::Run:
        case NFC::Read:
        {
#ifdef S_DEBUG_SYSTEM
            this->m_data[0] += 1;
#else
            if (this->nfc->transmitBlock(Action::Read, 2, this->m_data))
#endif
            {
                emit this->signalData(this->m_data[0]);
            }
        }
            break;

        case NFC::Write:
        {
#ifdef S_DEBUG_SYSTEM
            this->m_data[0] += 1;
#else
            if (this->nfc->transmitBlock(Action::Write, 2, this->m_data))
#endif
            {
                emit this->signalData(this->m_data[0]);
            }
        }
            break;

        default:
            break;
        }
    }
}

void SThreadNFC::write(const uint8_t value)
{
    QMutexLocker locker(&this->mutex);
    this->m_data[0] = value;
}

void SThreadNFC::setMode(const NFC mode)
{
    QMutexLocker locker(&this->mutex);
    this->m_mode = mode;
}
