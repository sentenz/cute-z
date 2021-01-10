#ifndef SPLOT_H
#define SPLOT_H

#include <QWidget>
#include <QtCharts/QValueAxis>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChartView>

class QTimer;
class QPushButton;

QT_CHARTS_USE_NAMESPACE


class SPlot : public QWidget
{
    Q_OBJECT

public:
    explicit SPlot(QWidget *parent = 0);
    ~SPlot();

    void setPlot(const QVector<double> &y);
    void setPlot(const QVector<QPointF> &points);

    void setBackgroundColor(const QColor &color);
    void setPlotBackgroundColor(const QColor &color);

    void setVisbleAxisX(const bool &visible = true);
    void setVisbleAxisY(const bool &visible = true);

    bool isRangeAxisX() const;
    bool isRangeAxisY() const;

    void clearRangeAxisX();
    void clearRangeAxisY();

    void setRangeAxisX(const QVariant &min, const QVariant &max);
    void setRangeAxisY(const QVariant &min, const QVariant &max);

    void setCheckable(const bool &checkable = false);
    void setFreeRun(const bool &freerun = false);

    void setCycleTime(const int msec = 0);

    void clear() const;

protected:
    bool event(QEvent* event);
    void changeEvent(QEvent *event);
    void focusOutEvent(QFocusEvent *event);
    //void focusInEvent(QFocusEvent *event);
    //void paintEvent(QPaintEvent *event);

signals:
    void update();

public slots:
    void setUpdate(const double &y);

private slots:
    void slotPlayButton();

private:
    void setUpWidget();
    void setUpGUI();
    void setConnect();
    void setAutoScale(const QVector<QPointF> &points);
    void setTimerStart();
    void setTimerStop();
    void retranslateUI();

    bool m_rangeX = false;
    bool m_rangeY = false;
    bool m_checkable = false;
    bool m_freerun = false;
    int m_maxX = 0;
    int m_cycleTime = 0;

    QTimer *timer = nullptr;
    QPushButton *playButton = nullptr;

    QChart *chart = nullptr;
    QLineSeries *series = nullptr;
    QChartView *view = nullptr;
};

#endif /// SPLOT_H
