#ifndef SCHECKBOX_H
#define SRADIOBUTTON_H

#include "../build/SGlobal.h"
#include "../components/qtmaterialcheckbox.h"

#include <QWidget>
#include <QColor>


class SCheckBox : public QtMaterialCheckBox
{
    Q_OBJECT

public:
    explicit SCheckBox(QWidget *parent = nullptr);
    ~SCheckBox();

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
