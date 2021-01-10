#ifndef SRADIOBUTTON_H
#define SRADIOBUTTON_H

#include "../build/SGlobal.h"
#include "../components/qtmaterialradiobutton.h"

#include <QWidget>
#include <QColor>


class SRadioButton : public QtMaterialRadioButton
{
    Q_OBJECT

public:
    explicit SRadioButton(QWidget *parent = nullptr);
    ~SRadioButton();

protected:
    void changeEvent(QEvent *event);

private:
    void setupProperty();
    void setupWidget();
    void restyleUI();

    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;
};

#endif // SRADIOBUTTON_H
