#include "stouchanalytics.h"
#include "../analytics/stouchanalyticsplottemperaturecpu.h"
#include "../analytics/stouchanalyticsinputs.h"
#include "../analytics/stouchanalyticsiot.h"
#include "../widget/layout/SHScrollArea.h"
#include "../widget/button/SToolButton.h"
#include "../widget/stacked/SAnimatedStackedWidget.h"
#include "../widget/tab/STabs.h"
#include "../util/dialog/SAppBar.h"

#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>


STouchAnalytics::STouchAnalytics(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowState(Qt::WindowFullScreen);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    this->setupWidget();
    this->setupLayout();
    this->setConnect();
}

STouchAnalytics::~STouchAnalytics()
{
    // StackedWidgets
    for (int i = this->stackedWidget->count(); i > 0; i--)
    {
        QWidget * widget = this->stackedWidget->widget(i);
        this->stackedWidget->removeWidget(widget);
        delete widget;
        widget = nullptr;
    }
}

void STouchAnalytics::setupWidget()
{
    /* App bar */
    this->appBar = new SAppBar(QtMaterialTheme::icon("navigation", "arrow_back"), this->m_title, this);

    /* Tab */
    this->m_tabs = new STabs(this);
    this->m_tabs->addTab(tr("Media"), QtMaterialTheme::icon("toggle", "star"));
    this->m_tabs->addTab(tr("Playback"), QtMaterialTheme::icon("toggle", "star"));
    this->m_tabs->addTab(tr("Audio"), QtMaterialTheme::icon("toggle", "star"));

    /* Animated stackedwidget */
    this->stackedWidget = new SAnimatedStackedWidget(this);
    this->stackedWidget->setDuration(300);
    this->stackedWidget->setAnimation(QEasingCurve::InQuad);

    /*  Widgets placet in stackedwidget */
    STouchAnalyticsPlotTemperatureCPU * touchAnalyticsPlotTemperatureCPU = new STouchAnalyticsPlotTemperatureCPU;
    this->stackedWidget->addWidget(touchAnalyticsPlotTemperatureCPU);

    STouchAnalyticsInputs * touchAnalyticsInputs = new STouchAnalyticsInputs;
    this->stackedWidget->addWidget(touchAnalyticsInputs);

    STouchAnalyticsIot * touchAnalyticsIot = new STouchAnalyticsIot;
    this->stackedWidget->addWidget(touchAnalyticsIot);
}

void STouchAnalytics::setupLayout()
{
    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->appBar, 1);
    mainLayout->addWidget(this->m_tabs, 1, Qt::AlignTop);
    mainLayout->addWidget(this->stackedWidget, 8);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(mainLayout);
}

void STouchAnalytics::setConnect()
{
    /* App bar */
    connect(this->appBar, &SAppBar::signalClicked, [this](int n) {
        switch (n) {
        case 0:
            emit this->signalReturn();
            break;

        default:
            break;
        }
    });

    /* Tabs */
    connect(this->m_tabs, SIGNAL(currentChanged(int)), this->stackedWidget, SLOT(slideIn(int)));

    /* Stacked widget */
    connect(this->stackedWidget, &SAnimatedStackedWidget::currentChanged, [=](int arg) { this->stackedWidget->widget(arg)->setFocus(); });
}

void
STouchAnalytics::retranslateUI()
{
    /* App bar */
    this->appBar->setText(this->m_title);

    /* Tabs */
    int t_iter = 0;
    this->m_tabs->setTabText(t_iter++, tr("Media"));
    this->m_tabs->setTabText(t_iter++, tr("Playback"));
    this->m_tabs->setTabText(t_iter++, tr("Audio"));
}

void
STouchAnalytics::restyleUI()
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
STouchAnalytics::changeEvent(QEvent * event)
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
