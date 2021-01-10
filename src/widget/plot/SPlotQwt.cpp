#include "SPlotQwt.h"

#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <qwt_scale_engine.h>
#include <qwt_scale_widget.h>
#include <qwt_plot_dict.h>
#include <qwt_plot_item.h>
#include <qwt_abstract_scale_draw.h>

#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTimer>
#include <QVector>
#include <QEvent>
#include <QFocusEvent>
#include <QDebug>


SPlotQwt::SPlotQwt(QWidget *parent) : QWidget(parent)
{
    this->setObjectName("SPlotQwt");
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    this->setupWidget();
    this->setupLayout();
    this->setConnect();
    this->restyleUI();
}

SPlotQwt::~SPlotQwt()
{
}

void SPlotQwt::setupWidget()
{
    /// TIMER
    this->timer = new QTimer(this);

    /// COLOR MAP
    QPalette palette;
    palette.setColor(QPalette::WindowText, this->m_colorText.darker());   // color of ticks
    palette.setColor(QPalette::Text, this->m_colorText.darker());    // color of tick labels
    palette.setColor(QPalette::Window, this->m_colorText.darker());

    /// PLOT
    this->plot = new QwtPlot(this);
    this->plot->setCanvasBackground(Qt::transparent);
    this->plot->axisAutoScale(QwtPlot::yLeft);
    this->plot->axisScaleEngine(QwtPlot::xBottom)->setAttribute(QwtScaleEngine::Floating, true);
    this->plot->setAxisFont(QwtPlot::yLeft, QFont(::GlobalFont, 12, QFont::Bold));
    this->plot->setAxisFont(QwtPlot::xBottom, QFont(::GlobalFont, 12, QFont::Bold));
    this->plot->axisWidget(QwtPlot::xBottom)->setPalette(palette);
    this->plot->enableAxis(QwtPlot::xBottom, true);
    this->plot->axisWidget(QwtPlot::yLeft)->setPalette(palette);
    this->plot->enableAxis(QwtPlot::yLeft, true);
    this->plot->setContentsMargins(0, 0, 0, 0);
    this->plot->setAutoReplot();

    /// GRID
    //QwtPlotGrid *grid = new QwtPlotGrid;
    //grid->setPen(QPen(Qt::gray));
    //grid->attach(plot);

    /// CURVE
    this->curve = new QwtPlotCurve;
    this->curve->setPen(this->m_colorHighlight, 2);
    //this->curve->setStyle(QwtPlotCurve::Lines);
    //this->curve->setCurveAttribute(QwtPlotCurve::Fitted);
    this->curve->setRenderHint(QwtPlotItem::RenderAntialiased, true);
    this->curve->attach(this->plot);
}

void SPlotQwt::setupLayout()
{
    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->plot);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(mainLayout);}

void SPlotQwt::setConnect()
{
    connect(this->timer, &QTimer::timeout, this, &SPlotQwt::update);
}

void SPlotQwt::setPlot(const QVector<double> &y)
{
    QVector<QPointF> points;

    for (int i = 0; i < y.size(); ++i)
    {
        points.append(QPointF(i, y.at(i)));
    }

    this->setAutoScale(points);

    this->curve->setSamples(points);
    //this->plot->replot();
}

void SPlotQwt::setPlot(const QVector<QPointF> &points)
{
    this->setAutoScale(points);

    this->curve->setSamples(points);
    //this->plot->replot();
}

void SPlotQwt::setUpdate(const double &y)
{
    QVector<QPointF> oldPoints; // = static_cast<QVector<QPointF>>(this->curve->data());
    QVector<QPointF> points;

    for (size_t i = 0; i < this->curve->dataSize(); ++i)
    {
        oldPoints.append(this->curve->sample(i));
    }

    if (oldPoints.count() < this->m_maxX)
    {
        for (size_t i = 0; i < this->curve->dataSize(); ++i)
        {
            points.append(this->curve->sample(i));
        }
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

    this->curve->setSamples(points);
}

void SPlotQwt::setVisbleAxisX(const bool &visible)
{
    this->plot->enableAxis(QwtPlot::xBottom, visible);
}

void SPlotQwt::setVisbleAxisY(const bool &visible)
{
    this->plot->enableAxis(QwtPlot::yLeft, visible);
}

bool SPlotQwt::isRangeAxisX() const
{
    if (this->m_rangeX)
    {
        return true;
    }

    return false;
}

bool SPlotQwt::isRangeAxisY() const
{
    if (this->m_rangeY)
    {
        return true;
    }

    return false;
}

void SPlotQwt::clearRangeAxisX()
{
    this->m_rangeX = false;
}

void SPlotQwt::clearRangeAxisY()
{
    this->m_rangeY = false;
}

void SPlotQwt::setRangeAxisX(const QVariant &min, const QVariant &max)
{
    this->plot->setAxisScale(QwtPlot::xBottom, min.toDouble(), max.toDouble());
    this->m_maxX = max.toInt();
    this->m_rangeX = true;
}

void SPlotQwt::setRangeAxisY(const QVariant &min, const QVariant &max)
{
    this->plot->setAxisScale(QwtPlot::yLeft, min.toDouble(), max.toDouble());
    this->m_rangeY = true;
}


void SPlotQwt::setFreeRun(const bool &freerun)
{
    this->m_freerun = freerun;

    if (this->m_freerun)
    {
        this->setTimerStart();
    }
}

void SPlotQwt::setAutoScale(const QVector<QPointF> &points)
{
    QPolygonF poly(points);
    QRectF brect = poly.boundingRect();

    if (!this->m_rangeX)
    {
        this->plot->setAxisScale(QwtPlot::xBottom, 0.0, brect.right());
    }

    if (!this->m_rangeY)
    {
        qreal top = brect.top() >= 0 ? -brect.top() : brect.top();
        qreal bottom = brect.bottom() >= 0 ? brect.bottom() : -brect.bottom();

        this->plot->setAxisScale(QwtPlot::yLeft, brect.top() + top/10, brect.bottom() + bottom/10);
    }
}

void SPlotQwt::setCycleTime(const int time)
{
    this->m_cycleTime = time;

    if (this->timer->isActive())
    {
        this->timer->start(this->m_cycleTime);
    }
}

void SPlotQwt::clear() const
{
    this->plot->detachItems(QwtPlotItem::Rtti_PlotCurve);
    //this->plot->detachItems(QwtPlotItem::Rtti_PlotMarker);
}

void SPlotQwt::setTimerStart()
{
    if (!this->timer->isActive())
    {
        this->timer->start(this->m_cycleTime);
    }
}

void SPlotQwt::setTimerStop()
{
    if (this->timer->isActive())
    {
        this->timer->stop();
    }
}

void SPlotQwt::retranslateUI()
{
}

void
SPlotQwt::restyleUI()
{
    if (this->m_colorBase != ::GlobalColorCustomBase)
    {
        this->m_colorBase = ::GlobalColorCustomBase;
        this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    }
    if (this->m_colorContrast != ::GlobalColorCustomContrast)
    {
        this->m_colorContrast = ::GlobalColorCustomContrast;
    }
    if (this->m_colorText != ::GlobalColorCustomText)
    {
        this->m_colorText = ::GlobalColorCustomText;
        if (this->plot != nullptr)
        {
            this->plot->detachItems(QwtPlotItem::Rtti_PlotTextLabel);
//            this->plot->detachItems(QwtPlotItem::Rtti_PlotItem);
//            this->plot->detachItems(QwtPlotItem::Rtti_PlotScale);
            QPalette palette;
            palette.setColor(QPalette::WindowText, this->m_colorText);   // color of ticks
            palette.setColor(QPalette::Text, this->m_colorText);    // color of tick labels
            palette.setColor(QPalette::Window, this->m_colorText);
//            QwtScaleDiv div(150,150);
//            QwtAbstractScaleDraw *sd = this->plot->axisWidget(QwtPlot::yLeft)->scaleDraw();
//            sd->setScaleDiv(div);
//            sd->invalidateCache();
//            this->plot->axisWidget(QwtPlot::yLeft)->scaleDraw()->invalidateCache();
            this->plot->axisWidget(QwtPlot::xBottom)->setPalette(palette);
            this->plot->axisWidget(QwtPlot::yLeft)->setPalette(palette);
            this->plot->axisWidget(QwtPlot::xBottom)->repaint();
            this->plot->axisWidget(QwtPlot::yLeft)->repaint();
            this->plot->axisWidget(QwtPlot::xBottom)->update();
            this->plot->axisWidget(QwtPlot::yLeft)->update();
            this->plot->replot();
        }
    }
    if (this->m_colorHighlight != ::GlobalColorCustomHighlight)
    {
        this->m_colorHighlight = ::GlobalColorCustomHighlight;
        if (this->curve != nullptr)
        {
            this->curve->setPen(this->m_colorHighlight, 2);
        }
    }
    this->update();
}

void SPlotQwt::changeEvent(QEvent* event)
{
    switch (event->type())
    {
    case QEvent::LanguageChange:
        this->retranslateUI();
        break;

    case QEvent::StyleChange:
        this->restyleUI();
        break;

    case QEvent::LocaleChange:
        break;

    default:
        break;
    }

    QWidget::changeEvent(event);
}
