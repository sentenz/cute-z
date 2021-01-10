#ifndef STHREADENCODER_H
#define STHREADENCODER_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>

class QSettings;
class QFileSystemWatcher;

class STouchDialogAccept;

class SThreadEncoder : public QThread
{
    Q_OBJECT

public:
    explicit SThreadEncoder(QObject *parent = 0);
    ~SThreadEncoder();

    /// Function members
    void init();
    void resume();
    void stop();
    void abort();

    /// Data members
    double minimumValue() const;
    double maximumValue() const;
    QString direction() const;

signals:
    void signalDataTransferred(const int value);
    void signalConnect(const bool connection);

protected:
    void run() override;

private slots:
    void slotReadSettings();

private:
    /// Function members
    void setupWidget();
    void setConnect();

    /// Data members
    bool m_init = false;
    bool m_abort = false;
    bool m_restart = false;
    bool m_pause = false;
    uint8_t m_data[16];
    double m_minValue = 0;
    double m_maxValue = 0;
    QString m_direction = "Unidirectional";

    /// Qt members
    QMutex mutex;
    QWaitCondition condition;
    QSettings *settings = nullptr;
    QFileSystemWatcher *fileSystemWatcher = nullptr;

    /// Sentenz members
    //NfcMfClassic *nfc = nullptr;
};

#endif /// STHREADENCODER_H
