#ifndef SDIGITSKEYBOARD_H
#define SDIGITSKEYBOARD_H

#include "../build/SGlobal.h"
#include <QWidget>

class QLabel;
class QString;
class QStringList;

class SRaisedButton;


class SDigitsKeyboard : public QWidget
{
    Q_OBJECT

public:
    enum class Datatype {Int,
                         Double};

    explicit SDigitsKeyboard(QWidget *parent = nullptr);
    ~SDigitsKeyboard();

    void setDatatype(const Datatype &type = Datatype::Int);
    void setSign(const bool sign);

protected:
    void changeEvent(QEvent *event);
    void paintEvent(QPaintEvent *event);

signals:
    void signalSymbolChanged(const QString text);

private slots:
    void slotButtonPressed();

private:
    void setupWidget();
    void setupLayout();
    void setConnect();
    void retranslateUI();
    void restyleUI();
    QString convertUnicodeToString(QString string);

    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    /// NUMBERS
    SRaisedButton *buttonZero = nullptr;
    SRaisedButton *buttonOne = nullptr;
    SRaisedButton *buttonTwo = nullptr;
    SRaisedButton *buttonThree = nullptr;
    SRaisedButton *buttonFour = nullptr;
    SRaisedButton *buttonFive = nullptr;
    SRaisedButton *buttonSix = nullptr;
    SRaisedButton *buttonSeven = nullptr;
    SRaisedButton *buttonEight = nullptr;
    SRaisedButton *buttonNine = nullptr;
    /// EXTENDET
    SRaisedButton *buttonDot = nullptr;
    SRaisedButton *buttonMinus = nullptr;
};

#endif /// SDIGITSKEYBOARD_H
