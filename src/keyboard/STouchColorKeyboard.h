#ifndef STOUCHCOLORKEYBOARD_H
#define STOUCHCOLORKEYBOARD_H

#include "../build/SGlobal.h"
#include <QDialog>

class QLabel;
class QString;
class QStringList;
class QButtonGroup;
class QStackedWidget;

class SColorSquare;
class SColorRgb;
class SPushButton;


class STouchColorKeyboard : public QDialog
{
    Q_OBJECT

public:
    explicit STouchColorKeyboard(QWidget *parent = nullptr);
    ~STouchColorKeyboard();

    void setTitle(const QString text);
    bool isAccepted();

    void setColor(const QColor color);
    QColor getColor() const;

    void setBaseColor(const QColor &color);
    void setContrastColor(const QColor &color);
    void setTextColor(const QColor &color);
    void setHighlightColor(const QColor &color);

protected:
    void showEvent(QShowEvent *event);
    void changeEvent(QEvent *event);

signals:
    void signalColorChanged(const QColor &color);

private slots:
    void slotColorChanged(const QColor &color);
    void slotReleasedButton();
    void slotClose();

private:
    void setupWidget();
    void setupLayout();
    void setConnect();
    void retranslateUI();
    QString formStyleSheet(const QString &style = "");

    bool m_accepted = false;
    QColor m_color;
    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    QLabel *labelTitle = nullptr;
    QLabel *labelDisplay = nullptr;
    QLabel *labelColor = nullptr;
    QLabel *labelSw = nullptr;
    QLabel *labelRgb = nullptr;
    QButtonGroup *buttonGroup = nullptr;
    QStackedWidget *stackedWidget = nullptr;

    SPushButton *buttonCancel = nullptr;
    SPushButton *buttonAccept = nullptr;
    SColorSquare *colorSquare = nullptr;
    SColorRgb *colorRgb = nullptr;
};

#endif /// STOUCHCOLORKEYBOARD_H
