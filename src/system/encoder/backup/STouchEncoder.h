#ifndef STOUCHENCODER_H
#define STOUCHENCODER_H

#include <QDialog>

#include "SThreadEncoder.h"

class QLabel;
class QString;
class QPushButton;

class STouchKeyboard;


class STouchEncoder : public QDialog
{
    Q_OBJECT

public:
    explicit STouchEncoder(QWidget *parent = 0);
    ~STouchEncoder();

    /// Function members
    void setTarget();
    void setCloseable(const bool closeable = false);
    void setCorrectButton(const bool hide = false);

    double getValue() const;
    bool up();
    bool down();
    double minimumValue() const;
    double maximumValue() const;
    QString direction() const;

protected:
    void changeEvent(QEvent *event);

signals:
    void signalRun();
    void signalStop();
    void signalFinished();
    void signalCorrect();
    void signalCancel();

private slots:
    void slotDataTransfer(const int value);
    void slotConnected(const bool connection);
    void slotProcess();
    void slotCorrect();
    void slotCancel();

private:
    /// Function members
    void setupWidget();
    void setupGUI();
    void setConnect();
    void getDirection();
    void retranslateUI();
    QString formStyleSheetString(const QString &style, const QString &icon = QString(""));

    /// Enum members
    enum class Status { Init, Run, Pause, Finish };

    /// Data members
    bool m_closeable = false;
    bool m_connection = false;
    double m_value = 0;
    uint8_t m_up = 0;
    uint8_t m_down = 0;
    uint8_t m_target = 0;
    Status m_status = Status::Init;

    /// Qt members
    QLabel *labelValue = nullptr;
    QPushButton *buttonProcess = nullptr;
    QPushButton *buttonCancel = nullptr;
    QPushButton *buttonCorrect = nullptr;

    /// Sentenz members
    SThreadEncoder *threadEncoder = nullptr;
    STouchKeyboard *touchKeyboard = nullptr;
};

#endif /// STOUCHENCODER_H
