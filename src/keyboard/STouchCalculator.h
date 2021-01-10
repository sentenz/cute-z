#ifndef STOUCHKEYBOARD_H
#define STOUCHKEYBOARD_H

#include "../build/SGlobal.h"
#include <QDialog>

class QString;
class QStringList;

class SLabel;
class SPushButton;


class STouchCalculator : public QDialog
{
    Q_OBJECT

public:
    enum class Datatype {
        Int,
        Double
    };

    enum class Dialog {
        Information,
        Warning,
        Critical
    };

    explicit STouchCalculator(QWidget *parent = nullptr);
    ~STouchCalculator();

    void setTitle(const QString text);
    void setDescriptionText(const QString text, const Dialog type = Dialog::Information);
    void setRange(const int min, const int max);
    void setRange(const double min, const double max);
    void setDatatype(const Datatype &type = Datatype::Int);
    void setMode(const QString mode);
    void clear();
    bool isAccepted();
    bool isEmpty();
    QString getNumber();

protected:
    void showEvent(QShowEvent *event);
    void changeEvent(QEvent *event);
    void paintEvent(QPaintEvent *event);

signals:
    void signalNumbersChanged(const QString text);

private slots:
    void slotGetButton();
    void slotClose();

private:
    void setupWidget();
    void setupGUI();
    void setConnect();
    void setStyle();
    void retranslateUI();
    void restyleUI();

    void assignButton();
    bool inRange(const QString &string);
    void convertSymbolsMath(QString &string);
    void deniedSymbolsCombination(QString &string);
    QString setElidedText(const SLabel *label, const QString &text, const Qt::TextElideMode elide = Qt::ElideRight);

    QString lastNumbers = "";
    QString currentNumbers = "";
    QString m_descriptionText = "";
    QString m_mode = "";
    QStringList range;
    bool accept = false;
    Dialog m_messageType = Dialog::Information;

    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    SLabel *labelTitle = nullptr;
    SLabel *labelNumbers = nullptr;

    /// NUMBERS
    SPushButton *buttonZero = nullptr;
    SPushButton *buttonOne = nullptr;
    SPushButton *buttonTwo = nullptr;
    SPushButton *buttonThree = nullptr;
    SPushButton *buttonFour = nullptr;
    SPushButton *buttonFive = nullptr;
    SPushButton *buttonSix = nullptr;
    SPushButton *buttonSeven = nullptr;
    SPushButton *buttonEight = nullptr;
    SPushButton *buttonNine = nullptr;
    /// SYMBOLS
    SPushButton *buttonDot = nullptr;
    SPushButton *buttonClear = nullptr;
    SPushButton *buttonEqual = nullptr;
    SPushButton *buttonDelete = nullptr;
    SPushButton *buttonMinus = nullptr;
    SPushButton *buttonPlus = nullptr;
    SPushButton *buttonDivision = nullptr;
    SPushButton *buttonMultipli = nullptr;
    SPushButton *buttonExponent = nullptr;
    /// EXTENDET
    SPushButton *buttonCancel = nullptr;
    SPushButton *buttonAccept = nullptr;
};

#endif /// STOUCHKEYBOARD_H
