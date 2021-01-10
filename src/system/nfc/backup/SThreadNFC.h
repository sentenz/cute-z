#ifndef STHREADNFC_H
#define STHREADNFC_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>

class NfcMfClassic;


enum class NFC
{
    Read,
    Write
};

class SThreadNFC : public QThread
{
    Q_OBJECT

public:
    explicit SThreadNFC(QObject *parent = 0);
    ~SThreadNFC();

    /// Function members
    void init();
    void resume();
    void stop();
    void abort();
    void write(const uint8_t value);

    /// Data members
    void setMode(const NFC mode = NFC::Read);
    bool communicationEstablished() const;

signals:
    void signalDataTransferred(const int value);
    void signalConnect(const bool connection);

protected:
    void run() override;

private:
    /// Function members
    void setupWidget();
    void setConnect();

    /// Data members
    bool m_init = false;
    bool m_abort = false;
    bool m_restart = false;
    bool m_pause = false;
    bool m_established = false;
    uint8_t m_data[16];
    NFC m_mode = NFC::Read;

    /// Qt members
    QMutex mutex;
    QWaitCondition condition;

    /// Sentenz members
    NfcMfClassic *nfc = nullptr;
};

#endif /// SThreadNFC_H
