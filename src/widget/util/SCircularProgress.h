#ifndef SCIRCULARPROGRESS_H
#define SCIRCULARPROGRESS_H

#include "../build/SGlobal.h"
#include "../components/qtmaterialcircularprogress.h"

#include <QWidget>
#include <QColor>


class SCircularProgress : public QtMaterialCircularProgress
{
    Q_OBJECT

public:
    explicit SCircularProgress(QWidget *parent = nullptr);
    ~SCircularProgress();

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

#endif // SCIRCULARPROGRESS_H
