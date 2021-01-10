#ifndef STOUCHKEYBOARD_H
#define STOUCHKEYBOARD_H

#include <QDialog>

class QLabel;
class QString;
class QPushButton;
class QFile;


class STouchKeyboard : public QDialog
{
    Q_OBJECT

public:
    explicit STouchKeyboard(QWidget *parent = 0);

    void setTitle(const QString text);
    void setPassword(const bool on);
    void setMaximumDigit(const int digits);
    void setMetric(const char *metric);
    void setButtonStyle(const QString style);
    void enableButtons(const bool on = false);
    bool isAccepted();
    QString getNumber();

protected:
    void changeEvent(QEvent *event);

signals:
    void signalNumbersChanged(const QString text);

private slots:
    void slotGetNumber();

private:
    void setUpGUI();
    void setConnect();
    void retranslateUI();

    QString convertToMetric(QString text);
    QString formStyleSheetString(const QString style = "rect");

    QString lastNumbers = "";
    QString currentNumbers = "";
    QString styleButton = "";
    bool password = false;
    bool accepted = false;
    int digits = 4;
    int maxDigits = 20;
    char metric = '\0';

    QLabel *labelTitle = nullptr;
    QLabel *labelNumbers = nullptr;
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
    QPushButton *buttonAccept = nullptr;
    QPushButton *buttonMinus = nullptr;
    QPushButton *buttonDot = nullptr;
};

#endif /// STOUCHKEYBOARD_H
