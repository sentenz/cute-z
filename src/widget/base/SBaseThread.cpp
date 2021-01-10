#include "SBaseThread.h"

#include <QApplication>
#include <QWidget>
#ifdef S_DEBUG_SYSTEM
#include <QDebug>
#endif


SBaseThread::SBaseThread(QObject * parent) :
    QThread(parent)
{
    this->setObjectName("SBaseThread");
    this->setConnect();
}

SBaseThread::~SBaseThread()
{
    this->abort();
}

void SBaseThread::setConnect()
{
    connect(this, &SBaseThread::signalError, [this]{ this->m_running = false; });
    connect(this, &SBaseThread::signalError, this, &SBaseThread::signalRun);
}

void SBaseThread::proceed()
{
    QMutexLocker locker(&this->mutex);

    if (!this->isRunning())
    {
        this->m_init = true;
        this->m_running = true;
        emit this->signalRun(true);
        this->start(QThread::TimeCriticalPriority);
    }
}

void SBaseThread::resume()
{
    if (this->m_running)
    {
        emit this->signalRun(true);
    }

    QMutexLocker locker(&this->mutex);
    this->m_pause = false;
    this->condition.wakeOne();
}

void SBaseThread::pause()
{
    emit this->signalRun(false);

    QMutexLocker locker(&this->mutex);
    this->m_pause = true;

    /* Pause thread */
    if (this->m_pause)
    {
        /* Set thread in sleep condition. Call resume() to proceed. */
        this->condition.wait(&this->mutex);
    }
}

void SBaseThread::stop()
{
    QMutexLocker locker(&this->mutex);
    this->pause();
}

void SBaseThread::abort()
{
    this->mutex.lock();
    this->m_abort = true;
    this->mutex.unlock();

    this->m_init = false;
    this->m_pause = false;

    this->terminate();
    this->wait(100);
}

void SBaseThread::asserts()
{
    /* Abort thread */
    if (this->m_abort)
    {
        this->m_abort = false;
        return;
    }
}

bool
SBaseThread::isInit() const
{
    return this->m_init;
}

bool
SBaseThread::isRunning() const
{
    return this->m_running;
}

bool
SBaseThread::isPause() const
{
    return this->m_pause;
}
