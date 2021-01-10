#ifndef STOUCHFLICKABLEKEYBOARD_H
#define STOUCHFLICKABLEKEYBOARD_H

#include <QDialog>

class QLabel;
class QString;
class QPushButton;

class STouchFlickableList;


class STouchFlickableKeyboard : public QDialog
{
    Q_OBJECT

public:
    explicit STouchFlickableKeyboard(QWidget *parent = 0);
    ~STouchFlickableKeyboard();

    void setTitle1(const QString text);
    void setTitle2(const QString text);
    bool isAccepted();
    QString getNumber() const;
    void clear();

protected:
    void changeEvent(QEvent *event);
    void showEvent(QShowEvent *event);
    void hideEvent(QHideEvent *event);

signals:
    void signalNumbersChanged(const QString text);

private slots:
    void slotButtonCancelPressed();
    void slotButtonAcceptPressed();
    void slotGetFirstNumber(const int &index);
    void slotGetSecondNumber(const int &index);

private:
    void setupWidget();
    void setupGUI();
    void setConnect();
    void retranslateUI();

    QString formStyleSheetString(const QString &style);

    bool accepted = false;
    QString first = "00";
    QString second = "00";

    QLabel *labelTitle1 = nullptr;
    QLabel *labelTitle2 = nullptr;
    QLabel *labelNumbers = nullptr;
    QPushButton *buttonCancel = nullptr;
    QPushButton *buttonAccept = nullptr;

    STouchFlickableList *touchFirstFlickable = nullptr;
    STouchFlickableList *touchSecondFlickable = nullptr;
};

#endif /// STOUCHFLICKABLEKEYBOARD_H
