#include "stouchanalyticsplottemperaturecpu.h"

#ifdef S_QT
#include "../widget/plot/SPlot.h"
#else
#include "../widget/plot/SPlotQwt.h"
#endif

#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTimer>
#include <QVector>
#include <QEvent>
#include <QFocusEvent>
#include <QFileInfo>
#include <QDebug>

#include <fcntl.h>


STouchAnalyticsPlotTemperatureCPU::STouchAnalyticsPlotTemperatureCPU(QWidget *parent) : QDialog(parent)
{
    this->setObjectName("STouchAnalyticsPlotTemperatureCPU");
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setFocusPolicy(Qt::StrongFocus);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->setUpWidget();
    this->setupLayout();
    this->setConnect();
}

STouchAnalyticsPlotTemperatureCPU::~STouchAnalyticsPlotTemperatureCPU()
{
    if (this->plot != nullptr)
    {
        delete this->plot;
        this->plot = nullptr;
    }
}

void STouchAnalyticsPlotTemperatureCPU::setUpWidget()
{
    /// Plot
    ///
    #ifdef S_QT
    this->plot = new SPlot;
    #else
    this->plot = new SPlotQwt;
    #endif
    this->plot->setVisbleAxisX(false);
    this->plot->setRangeAxisX(0, 750);
    //this->plot->setCheckable(true);
    this->plot->setFreeRun(true);
    this->plot->setCycleTime(400);
}

void STouchAnalyticsPlotTemperatureCPU::setupLayout()
{
    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->plot);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(mainLayout);
    this->setStyleSheet("border-width: 0px;");
}

void STouchAnalyticsPlotTemperatureCPU::setConnect()
{
    #ifdef S_QT
    connect(this->plot, &SPlot::update, this, &STouchAnalyticsPlotTemperatureCPU::slotUpdateWidgeds);
    #else
    connect(this->plot, &SPlotQwt::update, this, &STouchAnalyticsPlotTemperatureCPU::slotUpdateWidgeds);
    #endif
}

void STouchAnalyticsPlotTemperatureCPU::slotUpdateWidgeds()
{
    /// Set data.
    this->plot->setUpdate(this->getCPUTemperature());
}

double STouchAnalyticsPlotTemperatureCPU::getCPUTemperature()
{
    std::string path = "/sys/class/thermal/thermal_zone0/temp";

    if (::GlobalDefinesEmbedded)
    {
        if (QFileInfo::exists(QString::fromStdString(path)))
        {
            FILE *infile;
            infile = fopen(path.c_str(), "r");

            double temp = 0.0;
            fscanf(infile, "%lf",&temp);
            fclose(infile);

            return temp/1000.0;
        }
        else
        {
            return static_cast<double>(rand());
        }
    }
    else
    {
        return static_cast<double>(rand());
    }
}

void STouchAnalyticsPlotTemperatureCPU::retranslateUI()
{
}

void
STouchAnalyticsPlotTemperatureCPU::restyleUI()
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
    }
    if (this->m_colorHighlight != ::GlobalColorCustomHighlight)
    {
        this->m_colorHighlight = ::GlobalColorCustomHighlight;
    }
}

void
STouchAnalyticsPlotTemperatureCPU::changeEvent(QEvent * event)
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
