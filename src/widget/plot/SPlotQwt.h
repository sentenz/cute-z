#ifndef SPLOTQWT_H
#define SPLOTQWT_H

#include "../build/SGlobal.h"
#include <QWidget>

class QTimer;
class QPushButton;

class QwtPlot;
class QwtPlotCurve;


class SPlotQwt : public QWidget
{
    Q_OBJECT

public:
    explicit SPlotQwt(QWidget *parent = 0);
    ~SPlotQwt();

    void setPlot(const QVector<double> &y);
    void setPlot(const QVector<QPointF> &points);

    void setVisbleAxisX(const bool &visible = true);
    void setVisbleAxisY(const bool &visible = true);

    bool isRangeAxisX() const;
    bool isRangeAxisY() const;

    void clearRangeAxisX();
    void clearRangeAxisY();

    void setRangeAxisX(const QVariant &min, const QVariant &max);
    void setRangeAxisY(const QVariant &min, const QVariant &max);

    void setFreeRun(const bool &freerun = false);

    void setCycleTime(const int time = 0);

    void clear() const;

protected:
    void changeEvent(QEvent *event);

signals:
    void update();

public slots:
    void setUpdate(const double &y);

private slots:

private:
    void setupWidget();
    void setupLayout();
    void setConnect();
    void setAutoScale(const QVector<QPointF> &points);
    void setTimerStart();
    void setTimerStop();
    void retranslateUI();
    void restyleUI();

    bool m_rangeX = false;
    bool m_rangeY = false;
    bool m_freerun = false;
    int m_maxX = 0;
    int m_cycleTime = 0;

    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    QTimer *timer = nullptr;
    QPushButton *playButton = nullptr;

    QwtPlot *plot = nullptr;
    QwtPlotCurve *curve = nullptr;
};

#endif /// SPLOTQWT_H
