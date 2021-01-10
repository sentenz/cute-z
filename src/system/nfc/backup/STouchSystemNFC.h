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


class STouchSystemNFC : public QDialog
{
    Q_OBJECT

public:
    explicit STouchSystemNFC(QWidget *parent = 0);
    ~STouchSystemNFC();

protected:
    void changeEvent(QEvent *event);

private slots:
    void slotRun();
    void slotStop();

private:
    /// Function members
    void setUpWidget();
    void setUpGUI();
    void setConnect();
    void setDirectionForward();
    void setDirectionBackward();
    void setDirectionNeutral();
    void retranslateUI();

    /// Data members

    /// Qt members

    /// Sentenz members
    SEngine *engine = nullptr;
    STouchNFC *touchNFC = nullptr;
};

#endif /// STOUCHSYSTEMNFC_H
