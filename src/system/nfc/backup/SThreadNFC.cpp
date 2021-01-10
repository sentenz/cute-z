#include "SThreadNFC.h"
#include "../build/SGlobal.h"
#include "../utils/nfcmfclassic.hpp"

#include <QApplication>
#include <QWidget>
#include <QDebug>

SThreadNFC::SThreadNFC(QObject *parent) : QThread(parent)
{
    this->setObjectName("SThreadNFC");

    this->setupWidget();
    this->setConnect();
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
    QMutexLocker locker(&this->mutex);
    this->m_pause = false;
    this->condition.wakeOne();
}

void SThreadNFC::stop()
{
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
        /// Pause
        this->mutex.lock();
        if (this->m_pause)
        {
            // thread stop to execute until someone calls resume()
            this->condition.wait(&this->mutex);
        }
        this->mutex.unlock();

        /// Abort
        if (this->m_abort)
        {
            this->m_abort = false;
            return;
        }

        /// Initialisation
        if (!this->m_init)
        {
            if (this->nfc != nullptr)
            {
                delete this->nfc;
                this->nfc = nullptr;
            }

            this->nfc = new NfcMfClassic;

            if (this->nfc->init() < 0)
            {
                this->m_init = false;
                this->m_pause = true;
                this->m_established = false;

                emit this->signalConnect(false);
            }
            else
            {
                this->m_init = true;
                this->m_pause = true;
                this->m_established = true;

                emit this->signalConnect(true);
            }

            continue;
        }

        /// Restart / Resume
        if (this->m_restart)
        {
            this->m_restart = false;
            break;
        }

        switch (this->m_mode)
        {
            case NFC::Read:
            {
                if (this->nfc->transmitBlock(Action::Read, 2, this->m_data))
                {
                    emit this->signalDataTransferred(this->m_data[0]);
                }
            }
                break;

            case NFC::Write:
            {
                if (this->nfc->transmitBlock(Action::Write, 2, this->m_data))
                {
                    emit this->signalDataTransferred(this->m_data[0]);
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
    this->m_data[0] = value;
}

void SThreadNFC::setMode(const NFC mode)
{
    this->m_mode = mode;
}

bool SThreadNFC::communicationEstablished() const
{
    return this->m_established;
}
