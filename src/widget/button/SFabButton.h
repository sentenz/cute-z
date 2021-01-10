#ifndef SFABBUTTON_H
#define SFABBUTTON_H

#include "../build/SGlobal.h"
#include "../components/qtmaterialfab.h"

#include <QWidget>
#include <QColor>


class SFabButton : public QtMaterialFloatingActionButton
{
    Q_OBJECT

public:
    explicit SFabButton(const QIcon &icon, QWidget *parent = nullptr);
    ~SFabButton();

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

#endif // SFABBUTTON_H
