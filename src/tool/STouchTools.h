#ifndef STOUCHTOOLS_H
#define STOUCHTOOLS_H

#include "../build/SGlobal.h"

#include <QDialog>

class QButtonGroup;

class SLabel;
class SAnimatedStackedWidget;
class STouchCalculator;


class STouchTools : public QDialog
{
    Q_OBJECT

public:
    explicit STouchTools(QWidget *parent = 0);
    ~STouchTools();

protected:
    void changeEvent(QEvent *event);

signals:
    void signalReturn();

private:
    void setupWidget();
    void setupLayout();
    void setConnect();
    void retranslateUI();
    void restyleUI();

    QString formStyleSheetString(const QString &style);

    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    QButtonGroup *buttonGroup = nullptr;

    SLabel * header = nullptr;
    SAnimatedStackedWidget * stackedWidget = nullptr;
    STouchCalculator * touchCalculator = nullptr;
};

#endif // STOUCHTOOLS_H
