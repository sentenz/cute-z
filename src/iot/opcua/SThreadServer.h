/* This work is licensed under a Creative Commons CCZero 1.0 Universal License.
 * See http://creativecommons.org/publicdomain/zero/1.0/ for more information. */

#ifndef STHREADSERVER_H
#define STHREADSERVER_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>

#ifdef UA_ENABLE_AMALGAMATION
#include "open62541.h"
#else
#include <open62541/plugin/log_stdout.h>
#include <open62541/server.h>
#include <open62541/server_config_default.h>
#endif


/// @brief Class responsibility.
class SThreadServer : public QThread
{
    Q_OBJECT

public:
    /// @brief Constructor description.
    explicit SThreadServer(QObject * parent = nullptr);

    /// @brief Destructor description.
    ~SThreadServer();

    /// @brief Function members.
    void init();
    void resume();
    void pause();
    void stop();
    void abort();

    void updateProcessValue(int value);
    void setSeverity(uint16_t value);

signals:
    void signalRun(const bool run);
    void signalError(const bool state = false);
    void signalStart(const int value);
    void signalPause();
    void signalResume();
    void signalStop();

protected:
    void run() override;

private:
    /// @brief Function members.
    bool setupWidget();
    void setConnect();

    /// @brief Data members.
    bool m_init = false;
    bool m_abort = false;
    bool m_restart = false;
    bool m_pause = false;
    bool m_running = false;

    /// @brief Qt members.
    QMutex mutex;
    QWaitCondition condition;

    /// @brief Open62541 members.
    UA_Boolean ua_waitInternal = false;
    UA_Server * server = NULL;
};

#endif // STHREADSERVER_H

