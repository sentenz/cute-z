#ifndef STHREADNFC_H
#define STHREADNFC_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>

class NfcMfClassic;


class SThreadNFC : public QThread
{
    Q_OBJECT

public:
    /// @brief Constructor description.
    explicit SThreadNFC(QObject *parent = nullptr);

    /// @brief Destructor description.
    ~SThreadNFC();

    enum class NFC {
        Run,
        Read,
        Write
    };

    /// @brief Function members.
    void init();
    void resume();
    void pause();
    void stop();
    void abort();
    void write(const uint8_t value);

    void setMode(const NFC mode = NFC::Read);

signals:
    void signalRun(const bool run);
    void signalData(const int value);
    void signalError(const bool state = false);

protected:
    void run() override;

private:
    /// @brief Function members.
    void setupWidget();
    void setConnect();

    /// @brief Data members.
    bool m_init = false;
    bool m_abort = false;
    bool m_restart = false;
    bool m_pause = false;
    bool m_running = false;
    uint8_t m_data[16];
    NFC m_mode = NFC::Read;

    /// @brief Qt members.
    QMutex mutex;
    QWaitCondition condition;

    /// @brief Sentenz members.
    NfcMfClassic * nfc = nullptr;
};

#endif // SThreadNFC_H
