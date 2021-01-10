#ifndef STOUCHSCREENLOCK_H
#define STOUCHSCREENLOCK_H

#include <QDialog>

class QLabel;
class QString;
class QFile;
class QSettings;
class QPushButton;
class QShowEvent;
class QCloseEvent;
class QGestureEvent;
class QSwipeGesture;


class STouchScreenLock : public QDialog
{
    Q_OBJECT

public:
    explicit STouchScreenLock(QWidget *parent = 0);
    ~STouchScreenLock();

    void setUser(const QString &user);
    void setDigits(const int &digits);
    bool isAccepted();
    void enableButtons(const bool on = false);

protected:
    void showEvent(QShowEvent *event);
    void closeEvent(QCloseEvent *event);
    void changeEvent(QEvent *event);
    bool event(QEvent *event);
    bool gestureEvent(QGestureEvent *event);
    void swipeTriggered(QSwipeGesture *gesture);

signals:

private slots:
    void sloButtonEvent();
    void slotCheckCode();

private:
    void setUpWidget();
    void setUpGUI();
    void setConnect();
    void retranslateUI();

    QString formStyleSheetString(const QString &style);

    QString user = "default";
    QString password = "";
    QString code = "";
    bool acces = false;
    int digits = 4;

    QLabel *labelTitle = nullptr;
    QLabel *labelPassword = nullptr;
    QPushButton *buttonZero = nullptr;
    QPushButton *buttonOne = nullptr;
    QPushButton *buttonTwo = nullptr;
    QPushButton *buttonThree = nullptr;
    QPushButton *buttonFour = nullptr;
    QPushButton *buttonFive = nullptr;
    QPushButton *buttonSix = nullptr;
    QPushButton *buttonSeven = nullptr;
    QPushButton *buttonEight = nullptr;
    QPushButton *buttonNine = nullptr;
    QPushButton *buttonDelete = nullptr;
    QPushButton *buttonCancel = nullptr;
    QSettings *settings = nullptr;
};

#endif /// STOUCHSCREENLOCK_H
