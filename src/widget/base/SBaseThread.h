#ifndef SBASETHREAD_H
#define SBASETHREAD_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>


class SBaseThread : public QThread
{
    Q_OBJECT

public:
    explicit SBaseThread(QObject * parent = nullptr);
    ~SBaseThread();

    // Function members
    void proceed();
    void resume();
    void pause();
    void stop();
    void abort();

    bool isInit() const;
    bool isRunning() const;
    bool isPause() const;

signals:
    void signalRun(const bool run);
    void signalError(const bool state = false);

protected:
    void asserts();
//    void run() override;

private:
    // Function members
    void setConnect();

    // Data members
    bool m_init = false;
    bool m_abort = false;
    bool m_pause = false;
    bool m_running = false;

    // Qt members
    QMutex mutex;
    QWaitCondition condition;
};

#endif // SBASETHREAD_H
