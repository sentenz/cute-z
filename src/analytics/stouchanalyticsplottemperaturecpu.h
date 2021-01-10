#ifndef STOUCHANALYTICSPLOTTEMPERATURE_H
#define STOUCHANALYTICSPLOTTEMPERATURE_H

#include "../build/SGlobal.h"
#include <QtGlobal>
#include <QDialog>

#ifdef S_QT
class SPlot;
#else
class SPlotQwt;
#endif


class STouchAnalyticsPlotTemperatureCPU : public QDialog
{
    Q_OBJECT

public:
    explicit STouchAnalyticsPlotTemperatureCPU(QWidget *parent = 0);
    ~STouchAnalyticsPlotTemperatureCPU();

protected:
    void changeEvent(QEvent* event);

signals:

private slots:
    void slotUpdateWidgeds();

private:
    void setUpWidget();
    void setupLayout();
    void setConnect();
    double getCPUTemperature();
    void retranslateUI();
    void restyleUI();

    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    #ifdef S_QT
    SPlot *plot = nullptr;
    #else
    SPlotQwt *plot = nullptr;
    #endif
};

#endif /// STOUCHANALYTICSPLOTTEMPERATURE_H
