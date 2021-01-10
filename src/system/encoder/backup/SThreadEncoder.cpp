#include "SThreadEncoder.h"
#include "../build/SGlobal.h"

#include <QApplication>
#include <QWidget>
#include <QFileSystemWatcher>
#include <QSettings>
#include <QDebug>

SThreadEncoder::SThreadEncoder(QObject *parent) : QThread(parent)
{
    this->setObjectName("SThreadEncoder");

    this->setupWidget();
    this->setConnect();
    this->slotReadSettings();
}

SThreadEncoder::~SThreadEncoder()
{
    this->abort();

    if (this->settings != nullptr)
    {
        delete this->settings;
        this->settings = nullptr;
    }   
    #ifdef S_UNUSED
    if (this->nfc != nullptr)
    {
        delete this->nfc;
        this->nfc = nullptr;
    }
    #endif
}

void SThreadEncoder::setupWidget()
{
    /// WATCHER
    ///
    this->fileSystemWatcher = new QFileSystemWatcher(this);
    this->fileSystemWatcher->addPath(::GlobalSettingDir + ::GlobalSettingConfig);
}

void SThreadEncoder::setConnect()
{
    /// WATCHER
    ///
    connect(this->fileSystemWatcher, &QFileSystemWatcher::directoryChanged, this, &SThreadEncoder::slotReadSettings);
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
    QMutexLocker locker(&this->mutex);
    this->m_pause = false;
    this->condition.wakeOne();
}

void SThreadEncoder::stop()
{
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
            #ifdef S_UNUSED
            if (this->nfc != nullptr)
            {
                delete this->nfc;
                this->nfc = nullptr;
            }

            this->nfc = new NfcMfClassic;

            if (this->nfc->init() == -1)
            {
                this->m_init = false;
                this->m_pause = true;
                emit this->signalConnect(false);
            }
            else
            {
                this->m_init = true;
                this->m_pause = true;
                emit this->signalConnect(true);
            }
            #else
            this->m_init = true;
            this->m_pause = true;
            emit this->signalConnect(true);
            #endif

            continue;
        }

        /// Restart / Resume
        #ifdef S_UNUSED
        if (this->nfc->transmitBlock(Action::Read, 2, this->m_data))
        {
            emit this->signalDataTransferred(this->m_data[0]);
        }
        else
        {
            /*
            this->m_init = false;
            this->m_pause = true;
            emit this->signalConnect(false);
            */
        }
        #else
            static uint8_t count = 0;

            // todo

            emit this->signalDataTransferred(++count);

            this->msleep(10);
        #endif
    }
}

double SThreadEncoder::minimumValue() const
{
    return this->m_minValue;
}

double SThreadEncoder::maximumValue() const
{
    return this->m_maxValue;
}

QString SThreadEncoder::direction() const
{
    return this->m_direction;
}

void SThreadEncoder::slotReadSettings()
{
    /*
    this->settings = new QSettings(::GlobalSettingDir + ::GlobalSettingSettings, QSettings::IniFormat);

    if (!QStringList(this->settings->allKeys().filter("custom/system/encoder", Qt::CaseInsensitive)).isEmpty())
    {
        this->settings->beginGroup("custom/system/encoder");
    }
    else if (!QStringList(this->settings->allKeys().filter("default/system/encoder", Qt::CaseInsensitive)).isEmpty())
    {
        this->settings->beginGroup("default/system/encoder");
    }

//    this->m_minValue = this->settings->value("minValue", 1).toInt();
//    this->m_maxValue = this->settings->value("maxValue", 32).toInt();
//    this->m_direction = this->settings->value("direction", "").toString();

    this->settings->sync();
    this->settings->endGroup();

    delete this->settings;
    this->settings = nullptr;
    */
}
