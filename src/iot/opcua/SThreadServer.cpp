/* This work is licensed under a Creative Commons CCZero 1.0 Universal License.
 * See http://creativecommons.org/publicdomain/zero/1.0/ for more information. */

#include "SThreadServer.h"
#ifdef S_DEBUG_SYSTEM
#include <QDeadlineTimer>
#include <QDebug>
#endif

#ifdef UA_ENABLE_AMALGAMATION
#include "open62541.h"
#else
#include <open62541/plugin/log_stdout.h>
#include <open62541/server.h>
#include <open62541/server_config_default.h>
#endif

//#include "opcua/generated/umati/namespace_umati_generated.h"
#include "opcua/generated/model/namespace_model.h"


SThreadServer::SThreadServer(QObject * parent)
    : QThread(parent)
{
    this->setObjectName("SThreadServer");

    this->init();
}

SThreadServer::~SThreadServer()
{
    this->abort();

    if (this->server != NULL)
    {
        UA_Server_run_shutdown(this->server);
        UA_Server_delete(this->server);
    }
}

bool SThreadServer::setupWidget()
{
    this->server = UA_Server_new();
    UA_ServerConfig_setDefault(UA_Server_getConfig(this->server));

    UA_StatusCode retval = UA_Server_run_startup(server);
    if(retval != UA_STATUSCODE_GOOD)
    {
        UA_Server_delete(this->server);
        this->server = NULL;
        return false;
    }

    // create nodes from nodeset
    retval = namespace_model(server);
//    retval = namespace_umati_generated(this->server);
    if(retval != UA_STATUSCODE_GOOD)
    {
        UA_Server_delete(this->server);
        this->server = NULL;
        return false;
    }

    return retval == UA_STATUSCODE_GOOD ? true : false;
}

void SThreadServer::setConnect()
{
    connect(this, &SThreadServer::signalError, [this]{ this->m_running = false; });
    connect(this, &SThreadServer::signalError, this, &SThreadServer::signalRun);
}

void SThreadServer::init()
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

void SThreadServer::resume()
{
    if (this->m_running)
    {
        emit this->signalRun(true);
    }

    QMutexLocker locker(&this->mutex);
    this->m_pause = false;
    this->condition.wakeOne();
}

void SThreadServer::pause()
{
    emit this->signalRun(false);

    QMutexLocker locker(&this->mutex);
    this->m_pause = true;
}

void SThreadServer::stop()
{
    emit this->signalRun(false);

    QMutexLocker locker(&this->mutex);
    this->m_pause = true;
}

void SThreadServer::abort()
{
    this->mutex.lock();
    ua_nfcRunning = false;
    this->m_abort = true;
    this->mutex.unlock();

    this->m_init = false;
    this->m_restart = false;
    this->m_pause = false;

    this->terminate();
    this->wait(100);
}

void SThreadServer::run()
{
    forever
    {
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
            if (this->server != NULL)
            {
                UA_Server_delete(this->server);
                this->server = NULL;
            }

            if (!this->setupWidget())
            {
                this->m_init = false;
                emit this->signalError();
            }
            else
            {
                this->m_init = true;
                this->setConnect();
            }
        }
        else if (ua_nfcRunning)
        {
            /* timeout is the maximum possible delay (in millisec) until the next
             * _iterate call. Otherwise, the server might miss an internal timeout
             * or cannot react to messages with the promised responsiveness.
            */
            /* If multicast discovery server is enabled, the timeout does not not consider new input data (requests) on the mDNS socket.
             * It will be handled on the next call, which may be too late for requesting clients.
             * if needed, the select with timeout on the multicast socket server->mdnsSocket (see example in mdnsd library)
             */
            UA_UInt16 timeout = UA_Server_run_iterate(this->server, this->ua_waitInternal);

            /* Now we can use the max timeout to do something else. In this case, we
             * just sleep. (select is used as a platform-independent sleep function.)
             */
            struct timeval tv;
            tv.tv_sec = 0;
            tv.tv_usec = timeout * 1000;
            select(0, NULL, NULL, NULL, &tv);
        }

        //
        // Signals
        //

        // Emit process data signal
        if (ua_nfcStart)
        {
#ifdef S_DEBUG_SYSTEM
            qDebug() << "Method call start" << ua_nfcStart << " value" << ua_nfcData;
#endif
            emit this->signalStart(ua_nfcData);
            ua_nfcStart = false;
        }

        // Emit pause signal
        if (ua_nfcPause)
        {
#ifdef S_DEBUG_SYSTEM
            qDebug() << "Method call pause" << ua_nfcPause;
#endif
            emit this->signalPause();
            ua_nfcPause = false;
        }

        // Emit resume signal
        if (ua_nfcResume)
        {
#ifdef S_DEBUG_SYSTEM
            qDebug() << "Method call pause" << ua_nfcResume;
#endif
            emit this->signalResume();
            ua_nfcResume = false;
        }

        // Emit stop signal
        if (ua_nfcStop)
        {
#ifdef S_DEBUG_SYSTEM
            qDebug() << "Method call stop" << ua_nfcStop;
#endif
            emit this->signalStop();
            ua_nfcStop = false;
        }

        // Restart / Resume
        if (this->m_restart)
        {
            this->m_restart = false;
            break;
        }
    }
}

void SThreadServer::updateProcessValue(int value)
{
    updateMonitoredItem(server, (UA_Float)value);
}

void SThreadServer::setSeverity(uint16_t value)
{
    setSeverityOfCondition(server, (UA_UInt16)value);
}
