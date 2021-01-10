#ifndef SSLIDER_H
#define SSLIDER_H

#include "../build/SGlobal.h"
#include "../components/qtmaterialslider.h"

#include <QWidget>
#include <QColor>


class SSlider : public QtMaterialSlider
{
    Q_OBJECT

public:
    explicit SSlider(QWidget *parent = nullptr);
    ~SSlider();

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

#endif // SSLIDER_H
