#ifndef SSWITCH_H
#define SSWITCH_H

#include "../build/SGlobal.h"
#include "../components/qtmaterialtoggle.h"

#include <QWidget>
#include <QColor>


class SSwitch : public QtMaterialToggle
{
    Q_OBJECT

public:
    explicit SSwitch(QWidget *parent = nullptr);
    ~SSwitch();

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

#endif // SSWITCH_H
