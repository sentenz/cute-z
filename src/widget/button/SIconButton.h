#ifndef SICONBUTTON_H
#define SICONBUTTON_H

#include "../build/SGlobal.h"
#include "../components/qtmaterialiconbutton.h"

#include <QWidget>
#include <QColor>


class SIconButton : public QtMaterialIconButton
{
    Q_OBJECT

public:
    explicit SIconButton(const QIcon &icon, QWidget *parent = nullptr);
    ~SIconButton();

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

#endif // SICONBUTTON_H
