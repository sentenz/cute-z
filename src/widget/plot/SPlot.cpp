#include "SPlot.h"
#include "../build/SGlobal.h"

#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QVector>
#include <QEvent>
#include <QFocusEvent>
#include <QTimer>
#include <QDateTimeAxis>
#include <QDebug>

QT_CHARTS_USE_NAMESPACE

SPlot::SPlot(QWidget *parent) : QWidget(parent)
{
    this->setObjectName("SPlot");
    this->setStyleSheet("background-color: " + ::GlobalBackgroundColor.name() + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    this->setUpWidget();
    this->setUpGUI();
    this->setConnect();
}

SPlot::~SPlot()
{
}

void SPlot::setUpWidget()
{
    /// TIMER
    ///
    this->timer = new QTimer(this);

    /// X-Axis
    ///
    QValueAxis *axisX = new QValueAxis;
    axisX->setLabelFormat("%g");
    /// Y-Axis
    ///
    QValueAxis *axisY = new QValueAxis;

    /// CURVE
    ///
    this->series = new QLineSeries;
    this->series->setUseOpenGL(true);
    this->series->setPen(QPen(QBrush(::GlobalBlueColor), 2));

    /// PLOT
    ///
    this->chart = new QChart;
    this->chart->addSeries(this->series);
    this->chart->setAxisX(axisX, this->series);
    this->chart->setAxisY(axisY, this->series);
    this->chart->legend()->hide();
    this->chart->createDefaultAxes();
    this->chart->setPlotAreaBackgroundVisible(false);
    this->chart->setBackgroundVisible(false);
    this->chart->setBackgroundRoundness(0);
    this->chart->setMargins(QMargins(0, 0, 0, 0));
    this->chart->setContentsMargins(0, 0, 0, 0);
    this->chart->setAnimationOptions(QChart::AllAnimations);
    this->chart->axisX()->setGridLineVisible(false);
    this->chart->axisY()->setGridLineVisible(false);
    this->chart->axisX()->setLabelsFont(QFont(::GlobalFont, 12, QFont::Normal));
    this->chart->axisY()->setLabelsFont(QFont(::GlobalFont, 12, QFont::Normal));
    this->chart->axisX()->setLinePen(QPen(::GlobalBrightTextColor, 2));
    this->chart->axisY()->setLinePen(QPen(::GlobalBrightTextColor, 2));
    this->chart->axisX()->setLabelsBrush(QBrush(::GlobalBrightTextColor));
    this->chart->axisY()->setLabelsBrush(QBrush(::GlobalBrightTextColor));

    this->view = new QChartView(this->chart);
    this->view->setRenderHint(QPainter::Antialiasing);
}

void SPlot::setUpGUI()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->view);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    mainLayout->setContentsMargins(0,0,0,0);

    setStyleSheet("border-width: 0px;");
    setLayout(mainLayout);

    /// BUTTON
    this->playButton = new QPushButton(this);
    this->playButton->setIcon(QIcon(QPixmap(":/images/play_2.svg")));
    this->playButton->setIconSize(QSize(150,150));
    this->playButton->setVisible(false);
    this->playButton->setCheckable(true);
    this->playButton->setFixedSize(QSize(this->width()/4, this->width()/4));
    this->playButton->setStyleSheet("QPushButton { color: transparent; background: transparent; border:none; }");
    //this->playButton->layout()->setAlignment(Qt::AlignCenter);
    this->playButton->move(this->width()/2, this->height()/2 - this->playButton->height());
}

void SPlot::setConnect()
{
    connect(this->playButton, &QPushButton::toggled, this, &SPlot::slotPlayButton);
    connect(this->timer, &QTimer::timeout, this, &SPlot::update);
}

void SPlot::slotPlayButton()
{
    if (this->m_checkable)
    {
        if (this->playButton->isVisible())
        {
            this->playButton->setVisible(false);
        }

        this->setTimerStart();
        this->setFocus();
    }
}

void SPlot::setPlot(const QVector<double> &y)
{
    QVector<QPointF> points;

    for (int i = 0; i < y.size(); ++i)
    {
        points.append(QPointF(i, y.at(i)));
    }

    this->setAutoScale(points);

    this->series->replace(points);
}

void SPlot::setPlot(const QVector<QPointF> &points)
{
    this->setAutoScale(points);

    this->series->replace(points);

    /*
    foreach (QPointF p, points)
    {
        qDebug() << p;
    }
    */
}

void SPlot::setUpdate(const double &y)
{
    QVector<QPointF> oldPoints = this->series->pointsVector();
    QVector<QPointF> points;

    if (oldPoints.count() < this->m_maxX)
    {
        points = this->series->pointsVector();
    }
    else
    {
        for (int i = 1; i < oldPoints.count(); ++i)
        {
            points.append(QPointF(i - 1, oldPoints.at(i).y()));
        }
    }

    qint64 size = points.count();
    for (int k = 0; k < 1; ++k)
    {
        points.append(QPointF(k + size, y));
    }

    this->setAutoScale(points);

    this->chart->setAnimationOptions(QChart::NoAnimation);

    this->series->replace(points);
}

void SPlot::setBackgroundColor(const QColor &color)
{
    this->chart->setBackgroundBrush(QBrush(color));
    this->chart->setBackgroundVisible(true);
}

void SPlot::setPlotBackgroundColor(const QColor &color)
{
    this->chart->setPlotAreaBackgroundBrush(QBrush(color));
    this->chart->setPlotAreaBackgroundVisible(true);
}

void SPlot::setVisbleAxisX(const bool &visible)
{
    this->chart->axisX()->setVisible(visible);
}

void SPlot::setVisbleAxisY(const bool &visible)
{
    this->chart->axisY()->setVisible(visible);
}

bool SPlot::isRangeAxisX() const
{
    if (this->m_rangeX)
    {
        return true;
    }

    return false;
}

bool SPlot::isRangeAxisY() const
{
    if (this->m_rangeY)
    {
        return true;
    }

    return false;
}

void SPlot::clearRangeAxisX()
{
    this->m_rangeX = false;
}

void SPlot::clearRangeAxisY()
{
    this->m_rangeY = false;
}

void SPlot::setRangeAxisX(const QVariant &min, const QVariant &max)
{
    this->chart->axisX()->setRange(min, max);
    this->m_maxX = max.toInt();
    this->m_rangeX = true;
}

void SPlot::setRangeAxisY(const QVariant &min, const QVariant &max)
{
    this->chart->axisY()->setRange(min, max);
    this->m_rangeY = true;
}

void SPlot::setCheckable(const bool &checkable)
{
    this->m_checkable = checkable;
    this->playButton->setVisible(this->m_checkable);

    if (this->m_checkable)
    {
        this->setTimerStop();
    }
}

void SPlot::setFreeRun(const bool &freerun)
{
    this->m_freerun = freerun;

    if (this->m_freerun && !this->m_checkable)
    {
        this->setTimerStart();
    }
}

void SPlot::setAutoScale(const QVector<QPointF> &points)
{
    QPolygonF poly(points);
    QRectF brect = poly.boundingRect();

    if (!this->m_rangeX)
    {
        this->chart->axisX()->setRange(0, brect.right());
    }

    if (!this->m_rangeY)
    {
        qreal top = brect.top() >= 0 ? -brect.top() : brect.top();
        qreal bottom = brect.bottom() >= 0 ? brect.bottom() : -brect.bottom();

        this->chart->axisY()->setRange(brect.top() + top/10, brect.bottom() + bottom/10);
    }
}

void SPlot::setCycleTime(const int msec)
{
    this->m_cycleTime = msec;

    if (this->timer->isActive())
    {
        this->timer->start(this->m_cycleTime);
    }
}

void SPlot::clear() const
{
    this->series->clear();
}

void SPlot::setTimerStart()
{
    if (!this->timer->isActive())
    {
        this->timer->start(this->m_cycleTime);
    }
}

void SPlot::setTimerStop()
{
    if (this->timer->isActive())
    {
        this->timer->stop();
    }
}

/*
void SPlot::focusInEvent(QFocusEvent *event)
{
    Q_UNUSED(event)

    static bool activate = false;

    if (!activate)
    {
        activate = true;
    }
    else
    {
        if (!timer->isActive())
        {
            timer->start(10);
        }

        qDebug() << "FOCUS IN PLOT";
    }

    this->setFocus(Qt::ActiveWindowFocusReason);
}
*/

/*
void SPlot::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    if (!timer->isActive())
    {
        this->slotUpdateWidgeds();

        timer->start(10);
    }

    this->setFocus();
}
*/

bool SPlot::event(QEvent* event)
{
    switch(event->type())
    {
        case QEvent::TouchBegin:
        case QEvent::TouchUpdate:
        case QEvent::TouchEnd:
        case QEvent::MouseMove:
        case QEvent::MouseButtonPress:
        case QEvent::MouseButtonRelease:
        {
            if (this->m_checkable)
            {
                if (!this->playButton->isVisible())
                {
                    this->clearFocus();
                }
            }
        }
            break;
        default:
            break;
    }

    return QWidget::event(event);
}

void SPlot::focusOutEvent(QFocusEvent *event)
{
    Q_UNUSED(event);

    if (this->m_checkable)
    {
        this->setTimerStop();

        if (!this->playButton->isVisible())
        {
            this->playButton->setVisible(true);
        }
    }
}

void SPlot::retranslateUI()
{
}

void SPlot::changeEvent(QEvent* event)
{
    switch(event->type())
    {
        case QEvent::LanguageChange:
            this->retranslateUI();
            break;
        case QEvent::LocaleChange:
            break;
        default:
            break;
    }

    if (this->m_checkable)
    {
        this->setFocus();
    }

    QWidget::changeEvent(event);
}
