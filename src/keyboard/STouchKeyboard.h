#ifndef STOUCHKEYBOARD_H
#define STOUCHKEYBOARD_H

#include "../build/SGlobal.h"

#include <QDialog>

class QString;
class QStringList;
class QStackedWidget;

class SCanvas;
class SDigitsKeyboard;
class SRaisedButton;
class SLabel;
class STabs;


class STouchKeyboard : public QDialog
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

    explicit STouchKeyboard(QWidget *parent = nullptr);
    ~STouchKeyboard();

    void setTitle(const QString text);
    void setDescriptionText(const QString text, const Dialog type = Dialog::Information);
    void setRange(const int min, const int max);
    void setRange(const double min, const double max);
    void setMaximumDigit(const int digits);
    void setSecurityMode(const bool on = false, const int digits = 4);
    void setDatatype(const Datatype &type = Datatype::Int);
    void clear();
    bool isAccepted();
    bool isEmpty();
    QString getNumber();

protected:
    void showEvent(QShowEvent *event);
    void changeEvent(QEvent *event);

signals:
    void signalSymbolChanged(const QString symbol);

private slots:
    void slotSymbolChanged(const QString symbol);
    void slotReleasedButton();
    void slotClose();

private:
    void setupWidget();
    void setupLayout();
    void setConnect();
    void retranslateUI();
    void restyleUI();
    void assignButton();
    bool inRange(const QString &string);
    void checkSymbolsCombination(QString &string);
    void checkLabelWidth(const SLabel *label, QString &string);
    QString setElidedText(const SLabel *label, const QString &text, const Qt::TextElideMode elide = Qt::ElideRight);

    QString lastNumbers = "";
    QString currentNumbers = "";
    QString m_descriptionText = "";
    QString m_mode = "";
    QStringList range;
    bool m_password = false;
    bool accept = false;
    int m_digits = 0;
    Dialog m_messageType = Dialog::Information;

    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    QStackedWidget * stackedWidget = nullptr;

    SLabel *labelTitle = nullptr;
    SLabel *labelDisplay = nullptr;
    SRaisedButton *buttonCancel = nullptr;
    SRaisedButton *buttonAccept = nullptr;
    SCanvas *canvas = nullptr;
    SDigitsKeyboard *keyboard = nullptr;

    STabs * m_tabs = nullptr;
};

#endif /* STOUCHKEYBOARD_H */
