#ifndef STOUCHSYSTEMNFC_H
#define STOUCHSYSTEMNFC_H

#include <QDialog>

class QLabel;
class QString;
class QPushButton;
class QVBoxLayout;
class QStackedWidget;

class SEngine;
class STouchNFC;
class SAnimation;


class STouchSystemNFC : public QDialog
{
    Q_OBJECT

public:
    explicit STouchSystemNFC(QWidget *parent = 0);
    ~STouchSystemNFC();

protected:
    void changeEvent(QEvent *event);

private slots:
    void slotInit();
    void slotCorrect();
    void slotRun();
    void slotStop();
    void slotReset();

private:
    /// Function members
    void setUpWidget();
    void setUpGUI();
    void setConnect();
    void setEngineForward();
    void setEngineBackward();
    void setEngineNeutral();
    void retranslateUI();

    /// Data members
    uint8_t m_target = 0;

    /// Qt members
    QStackedWidget *stackedWidget = nullptr;

    /// Sentenz members
    SEngine *engine = nullptr;
    STouchNFC *touchNFC = nullptr;
    SAnimation *animation = nullptr;
};

#endif /// STOUCHSYSTEMNFC_H
