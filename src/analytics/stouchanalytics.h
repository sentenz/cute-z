#ifndef STOUCHANALYTICS_H
#define STOUCHANALYTICS_H

#include "../build/SGlobal.h"

#include <QWidget>

class SAppBar;
class STabs;
class SAnimatedStackedWidget;
class STouchAnalyticsPlotTemperatureCPU;
class STouchAnalyticsInputs;
class STouchAnalyticsIot;


class STouchAnalytics : public QWidget
{
    Q_OBJECT

public:
    explicit STouchAnalytics(QWidget * parent = nullptr);
    ~STouchAnalytics();

protected:
    void changeEvent(QEvent *event);

signals:
    void signalReturn();

private slots:

private:
    void setupWidget();
    void setupLayout();
    void setConnect();
    void retranslateUI();
    void restyleUI();

    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    /* Qt members */
    QString m_title = tr("Dashboard");

    /* UI menbers */
    SAppBar * appBar = nullptr;
    STabs * m_tabs = nullptr;
    SAnimatedStackedWidget * stackedWidget = nullptr;
};

#endif /* STOUCHANALYTICS_H */
