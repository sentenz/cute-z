#ifndef STHREADENCODER_H
#define STHREADENCODER_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>

class SEncoder25PRSBE;


class SThreadEncoder : public QThread
{
    Q_OBJECT

public:
    explicit SThreadEncoder(QObject *parent = 0);
    ~SThreadEncoder();

    // Function members
    void resume();
    void pause();
    void stop();
    void abort();

signals:
    void signalRun(const bool run);
    void signalData(const double value);
    void signalError(const bool state = false);

protected:
    void run() override;

private:
    // Function members
    void setupWidget();
    void setConnect();
    void init();

    // Data members
    bool m_init = false;
    bool m_abort = false;
    bool m_restart = false;
    bool m_pause = false;
    bool m_running = false;
    double m_data = 0.0;

    // Qt members
    QMutex mutex;
    QWaitCondition condition;

    // Sentenz members
    SEncoder25PRSBE *encoder = nullptr;
};

#endif // STHREADENCODER_H
