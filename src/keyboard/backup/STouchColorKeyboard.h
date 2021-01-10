#ifndef STOUCHCOLORKEYBOARD_H
#define STOUCHCOLORKEYBOARD_H

#include <QDialog>

class QLabel;
class QString;
class QPushButton;

class STouchFlickableList;
class SColorGradientSquare;
class SGraphicsGlowEffect;

class STouchColorKeyboard : public QDialog
{
    Q_OBJECT

public:
    STouchColorKeyboard(QWidget *parent = 0);
    ~STouchColorKeyboard();

    bool isAccepted();
    QString getRGB() const;

protected:
    void changeEvent(QEvent *event);
    void showEvent(QShowEvent *event);
    void hideEvent(QHideEvent *event);

signals:
    void signalNumbersChanged(const QString text);

private slots:
    void slotButtonCancelPressed();
    void slotButtonAcceptPressed();
    void slotGetSecondNumber(const int &index);

private:
    void setupWidget();
    void setupGUI();
    void setConnect();
    void retranslateUI();
    QString formStyleSheetString(const QString &style);

    bool accepted = false;

    QPushButton *buttonCancel = nullptr;
    QPushButton *buttonAccept = nullptr;

    SGraphicsGlowEffect *glow = nullptr;
    SColorGradientSquare *colorGradientSquare = nullptr;
    STouchFlickableList *touchFirstFlickable = nullptr;
    STouchFlickableList *touchSecondFlickable = nullptr;
};

#endif /// STOUCHCOLORKEYBOARD_H
