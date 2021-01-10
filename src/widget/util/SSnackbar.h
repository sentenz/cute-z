#ifndef SSNACKBAR_H
#define SSNACKBAR_H

#include "../build/SGlobal.h"
#include "../components/qtmaterialsnackbar.h"

#include <QWidget>
#include <QColor>


class SSnackbar : public QtMaterialSnackbar
{
    Q_OBJECT

public:
    explicit SSnackbar(QWidget *parent = nullptr);
    ~SSnackbar();

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

#endif // SSNACKBAR_H
