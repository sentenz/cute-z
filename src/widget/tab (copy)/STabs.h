#ifndef STABS_H
#define STABS_H

#include "../build/SGlobal.h"
#include "../components/qtmaterialtabs.h"

#include <QWidget>
#include <QColor>


class STabs : public QtMaterialTabs
{
    Q_OBJECT

public:
    explicit STabs(QWidget *parent = nullptr);
    ~STabs();

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

#endif // STABS_H
