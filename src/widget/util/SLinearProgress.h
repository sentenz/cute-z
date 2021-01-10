#ifndef SLINEARPROGRESS_H
#define SLINEARPROGRESS_H

#include "../build/SGlobal.h"
#include "../components/qtmaterialprogress.h"
#include "../components/lib/qtmaterialtheme.h"

#include <QWidget>
#include <QColor>


class SLinearProgress : public QtMaterialProgress
{
    Q_OBJECT

public:
    explicit SLinearProgress(QWidget *parent = nullptr);
    ~SLinearProgress();

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

#endif // SLINEARPROGRESS_H
