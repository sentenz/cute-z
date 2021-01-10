#ifndef STOUCHNFC_H
#define STOUCHNFC_H

#include <QDialog>

#include "SThreadNFC.h"

class QLabel;
class QString;
class QPushButton;
class QSettings;
class QFileSystemWatcher;

class STouchKeyboard;


class STouchNFC : public QDialog
{
    Q_OBJECT

public:
    explicit STouchNFC(QWidget *parent = 0);
    ~STouchNFC();

    /// Function members
    void setCloseable(const bool closeable = false);
    void setCorrectButton(const bool hide = false);
    void setMode(const NFC mode = NFC::Read, const bool target = true);

    void setValue(const int value);
    int getValue() const;
    bool up();
    bool down();
    int minimumValue() const;
    int maximumValue() const;
    bool unidirectional() const;
    bool bidirectional() const;
    int direction() const;

protected:
    void showEvent(QShowEvent *event);
    void changeEvent(QEvent *event);

signals:
    void signalRun();
    void signalStop();
    void signalCorrect();

private slots:
    void slotDataTransfer(const int value);
    void slotConnected(const bool connection);
    void slotProcess();
    void slotCorrect();
    void slotReset();
    void slotReadSettings();

private:
    /// Function members
    void setupWidget();
    void setupGUI();
    void setConnect();
    void setButtonInit();
    void setButtonPause();
    void setButtonRun();
    void getDirection();
    bool setTarget(const bool target = true);
    void transferTarget();
    void initThreadNFC();
    void resetThreadNFC();
    void retranslateUI();
    QString formStyleSheetString(const QString &style, const QString &icon = QString(""));

    /// Enum members
    enum class Status { Init, Run, Pause, Finish };

    /// Data members
    bool m_error = false;
    bool m_done = false;
    bool m_closeable = false;
    bool m_connection = false;
    bool m_setTarget = true;
    int m_minValue = 0;
    int m_maxValue = 0;
    int m_direction = 0;
    uint8_t m_up = 0;
    uint8_t m_down = 0;
    uint8_t m_value = 0;
    uint8_t m_target = 0;
    Status m_status = Status::Init;
    NFC m_mode = NFC::Read;

    /// Qt members
    QLabel *labelTitle = nullptr;
    QLabel *labelValue = nullptr;
    QPushButton *buttonProcess = nullptr;
    QPushButton *buttonCancel = nullptr;
    QPushButton *buttonCorrect = nullptr;
    QSettings *settings = nullptr;
    QFileSystemWatcher *fileSystemWatcher = nullptr;

    /// Sentenz members
    SThreadNFC *threadNFC = nullptr;
    STouchKeyboard *touchKeyboard = nullptr;
};

#endif /// STOUCHNFC_H
