#ifndef STOUCHSYSTEMENCODER_H
#define STOUCHSYSTEMENCODER_H

#include <QDialog>

class QLabel;
class QString;
class QPushButton;
class QVBoxLayout;
class QStackedWidget;

class SEngine;
class STouchEncoder;
class SAnimation;


class STouchSystemEncoder : public QDialog
{
    Q_OBJECT

public:
    explicit STouchSystemEncoder(QWidget *parent = 0);
    ~STouchSystemEncoder();

protected:
    void changeEvent(QEvent *event);

private slots:
    void slotInit();
    void slotRun();
    void slotStop();
    void slotReset();

private:
    /// Function members
    void setUpWidget();
    void setUpGUI();
    void setConnect();
    void setConnectNFC();
    void setDirectionForward();
    void setDirectionBackward();
    void setDirectionNeutral();
    void retranslateUI();

    /// Data members

    /// Qt members
    QStackedWidget *stackedWidget = nullptr;

    /// Sentenz members
    SEngine *engine = nullptr;
    STouchEncoder *touchEncoder = nullptr;
    SAnimation *animation = nullptr;
};

#endif /// STOUCHSYSTEMENCODER_H
