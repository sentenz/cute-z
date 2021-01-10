#ifndef STOUCHANALYTICSPLOTMQTT_H
#define STOUCHANALYTICSPLOTMQTT_H

#include "../build/SGlobal.h"

#include <QDialog>

class QLabel;
#ifdef S_QT
class SPlot;
#else
class SPlotQwt;
#endif
class SMqtt;


class STouchAnalyticsPlotMqtt : public QDialog
{
    Q_OBJECT

public:
    explicit STouchAnalyticsPlotMqtt(QWidget *parent = 0);
    ~STouchAnalyticsPlotMqtt();

    void setBackgroundColor(const QColor &color);
    void setContrastColor(const QColor &color);
    void setTextColor(const QColor &color);
    void setHighlightColor(const QColor &color);

protected:
    void changeEvent(QEvent* event);

signals:

private slots:
    void slotConnected(const bool connected);
    void slotDisconnected(const bool disconnected);
    void slotMessageReceived(const QString message);

private:
    void setupWidget();
    void setupLayout();
    void setConnect();
    void retranslateUI();
    QString setHtmlText(const QString upperText, const QString lowerText);

    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    QLabel *labelID = nullptr;
    QLabel *labelValue = nullptr;
    QLabel *labelTemperature = nullptr;

    #ifdef S_QT
    SPlot *plot = nullptr;
    #else
    SPlotQwt *plot = nullptr;
    #endif
    SMqtt *mqtt = nullptr;
};

#endif /// STOUCHANALYTICSPLOTMQTT_H
