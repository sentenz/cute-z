#include "stouchsettings.h"
#include "stouchsettingssystem.h"
#include "stouchsettingscode.h"
#include "stouchsettingsregion.h"
#include "stouchsettingsdesign.h"
#include "stouchsettingsreset.h"
#include "stouchsettingsinfo.h"
#include "../analytics/stouchanalytics.h"
#include "../database/STouchHistory.h"
#include "../tool/STouchTools.h"
#include "../widget/list/SList.h"
#include "../widget/stacked/SAnimatedStackedWidget.h"
#include "../util/dialog/SAppBar.h"

#include <QApplication>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QTimerEvent>
#include <QDebug>


STouchSettings::STouchSettings(QWidget *parent) : QWidget(parent)
{
    this->setObjectName("STouchSettings");
    // Window size for developing and emulating
    if (!::GlobalWindowSize.isEmpty())
    {
        this->resize(::GlobalWindowSize);
    }
    else
    {
        this->setWindowState(Qt::WindowFullScreen);
        this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }
    this->setWindowFlags(this->windowFlags() | Qt::Window | Qt::FramelessWindowHint);
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");

    this->setupWidget();
    this->setupLayout();
    this->setConnect();
}

STouchSettings::~STouchSettings()
{
    if (this->list != nullptr)
    {
        delete this->list;
        this->list = nullptr;
    }
    if (::GlobalDefinesNfc || ::GlobalDefinesEncoder)
    {
        if (this->touchHistory != nullptr)
        {
            delete this->touchHistory;
            this->touchHistory = nullptr;
        }
    }
    if (::GlobalDefinesAnalytics)
    {
        if (this->touchAnalytics != nullptr)
        {
            delete this->touchAnalytics;
            this->touchAnalytics = nullptr;
        }
    }
    if (this->touchTools != nullptr)
    {
        delete this->touchTools;
        this->touchTools = nullptr;
    }
    if (::GlobalDefinesNfc || ::GlobalDefinesEncoder)
    {
        if (this->touchSettingsSystem != nullptr)
        {
            delete this->touchSettingsSystem;
            this->touchSettingsSystem = nullptr;
        }
    }
    if (this->touchSettingsCode != nullptr)
    {
        delete this->touchSettingsCode;
        this->touchSettingsCode = nullptr;
    }
    if (this->touchSettingsRegion != nullptr)
    {
        delete this->touchSettingsRegion;
        this->touchSettingsRegion = nullptr;
    }
    if (::GlobalDefinesSettingsDesign)
    {
        if (this->touchSettingsDesign != nullptr)
        {
            delete this->touchSettingsDesign;
            this->touchSettingsDesign = nullptr;
        }
    }
    if (this->touchSettingsReset != nullptr)
    {
        delete this->touchSettingsReset;
        this->touchSettingsReset = nullptr;
    }
    if (this->touchSettingsInfo != nullptr)
    {
        delete this->touchSettingsInfo;
        this->touchSettingsInfo = nullptr;
    }
}

void STouchSettings::setupWidget()
{
    /* App bar */
    this->appBar = new SAppBar(QtMaterialTheme::icon("navigation", "arrow_back"), this->m_title, this);

    /* Swipe list */
    this->list = new SList;
    this->list->addTitle(tr("Tools"));
    this->list->addSlot(QIcon(":/images/diagnosis-color.svg"),
                     tr("Dashboard"),
                     tr(""),
                     tr(""),
                     QChar(0x276F));
    this->list->addSlot(QIcon(":/images/calculator-color.svg"),
                     tr("Calculator"),
                     tr(""),
                     tr(""),
                     QChar(0x276F));
    this->list->divider();
    this->list->addTitle(tr("Function settings"));
//    this->list->addSlot(QIcon(":/images/system-color.svg"),
//                     tr("Systems"),
//                     tr(""),
//                     tr(""),
//                     QChar(0x276F));
    this->list->addSlot(QIcon(":/images/database-color.svg"),
                     tr("History"),
                     tr(""),
                     tr(""),
                     QChar(0x276F));
    this->list->divider();
    this->list->addTitle(tr("General settings"));
    this->list->addSlot(QIcon(":/images/key-color.svg"),
                     tr("Passcode"),
                     tr(""),
                     tr(""),
                     QChar(0x276F));
    this->list->addSlot(QIcon(":/images/region-color.svg"),
                     tr("Region"),
                     tr(""),
                     tr(""),
                     QChar(0x276F));
    this->list->addSlot(QIcon(":/images/design-color.svg"),
                     tr("Design"),
                     tr(""),
                     tr(""),
                     QChar(0x276F));
    this->list->addSlot(QIcon(":/images/reset-color.svg"),
                     tr("Reset"),
                     tr(""),
                     tr(""),
                     QChar(0x276F));
    this->list->addSlot(QIcon(":/images/info-color.svg"),
                     tr("Info"),
                     tr(""),
                     tr(""),
                     QChar(0x276F));

    // Widget initialisation
    // Tools
    this->touchTools = new STouchTools;
    // SETTINGS PASSCODE
    this->touchSettingsCode = new STouchSettingsCode;
    // SETTINGS REGION
    this->touchSettingsRegion = new STouchSettingsRegion;
    // SETTINGS RESET
    this->touchSettingsReset = new STouchSettingsReset;
    // SETTINGS INFO
    this->touchSettingsInfo = new STouchSettingsInfo;
    // DIAGNOSIS
    if (::GlobalDefinesAnalytics)
    {
        this->touchAnalytics = new STouchAnalytics;
    }
    // SETTINGS SENSORS
    if (::GlobalDefinesNfc || ::GlobalDefinesEncoder)
    {
        this->touchSettingsSystem = new STouchSettingsSystem;
    }
    // DATABASE
    if (::GlobalDefinesNfc || ::GlobalDefinesEncoder)
    {
        this->touchHistory = new STouchHistory;
    }
    // SETTINGS DESIGN
    if (::GlobalDefinesSettingsDesign)
    {
        this->touchSettingsDesign = new STouchSettingsDesign;
    }
}

void STouchSettings::setupLayout()
{
    QVBoxLayout * subLayout = new QVBoxLayout;
    subLayout->addWidget(this->appBar, 1);
    subLayout->addWidget(this->list->list(), 9);
    subLayout->setSpacing(0);
    subLayout->setContentsMargins(0, 0, 0, 0);

    QWidget * widget = new QWidget(this);
    widget->setLayout(subLayout);

    // Widget with all options
    this->stackedWidget = new SAnimatedStackedWidget(this);
    this->stackedWidget->addWidget(widget);
    if (::GlobalDefinesAnalytics)
    {
        this->stackedWidget->addWidget(this->touchAnalytics);
    }
    this->stackedWidget->addWidget(this->touchTools);
    if (::GlobalDefinesNfc || ::GlobalDefinesEncoder)
    {
        // FIXME: Aus irgendeinem Grund funktioniert die Einbindung ncht mehr!!!!!!!!!!!!!
//        this->stackedWidget->addWidget(this->touchSettingsSystem);
    }
    if (::GlobalDefinesNfc || ::GlobalDefinesEncoder)
    {
        this->stackedWidget->addWidget(this->touchHistory);
    }
    this->stackedWidget->addWidget(this->touchSettingsCode);
    this->stackedWidget->addWidget(this->touchSettingsRegion);
    if (::GlobalDefinesSettingsDesign)
    {
        this->stackedWidget->addWidget(this->touchSettingsDesign);
    }
    this->stackedWidget->addWidget(this->touchSettingsReset);
    this->stackedWidget->addWidget(this->touchSettingsInfo);

    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->stackedWidget);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(mainLayout);
}

void STouchSettings::setConnect()
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

    /* Swipe list */
    connect(this->list, SIGNAL(signalReleased(int)), this, SLOT(slotList(int)));

    /* Settings */
    connect(this->touchTools, &STouchTools::signalReturn, this, &STouchSettings::slotReturn);
    connect(this->touchSettingsCode, &STouchSettingsCode::signalReturn, this, &STouchSettings::slotReturn);
    connect(this->touchSettingsRegion, &STouchSettingsRegion::signalReturn, this, &STouchSettings::slotReturn);
    connect(this->touchSettingsReset, &STouchSettingsReset::signalReturn, this, &STouchSettings::slotReturn);
    connect(this->touchSettingsInfo, &STouchSettingsInfo::signalReturn, this, &STouchSettings::slotReturn);
    if (::GlobalDefinesAnalytics)
    {
        connect(this->touchAnalytics, &STouchAnalytics::signalReturn, this, &STouchSettings::slotReturn);
    }
    if (::GlobalDefinesNfc || ::GlobalDefinesEncoder)
    {
        connect(this->touchHistory, &STouchHistory::signalReturn, this, &STouchSettings::slotReturn);
    }
    if (::GlobalDefinesNfc || ::GlobalDefinesEncoder)
    {
        connect(this->touchSettingsSystem, &STouchSettingsSystem::signalReturn, this, &STouchSettings::slotReturn);
    }
    if (::GlobalDefinesSettingsDesign)
    {
        connect(this->touchSettingsDesign, &STouchSettingsDesign::signalReturn, this, &STouchSettings::slotReturn);
    }
}

void STouchSettings::slotList(const int index)
{
    this->basicTimer.start(20 * 60 * 1000, this);

    int t_iter = 0;
    if (index == t_iter++)
    {
        if (::GlobalDefinesAnalytics)
        {
//            this->stackedWidget->slideIn(this->touchAnalytics);
//            this->stackedWidget->slideIn(this->touchAnalytics);
            this->stackedWidget->slideIn(t_iter);
        }
    }
    else if (index == t_iter++)
    {
        this->stackedWidget->slideIn(t_iter);
    }
    else if (index == t_iter++)
    {
        if (::GlobalDefinesNfc || ::GlobalDefinesEncoder)
        {
            this->stackedWidget->slideIn(t_iter);
        }
    }
    else if (index == t_iter++)
    {
        if (::GlobalDefinesNfc || ::GlobalDefinesEncoder)
        {
            this->stackedWidget->slideIn(t_iter);
        }
    }
    else if (index == t_iter++)
    {
        this->stackedWidget->slideIn(t_iter);
    }
    else if (index == t_iter++)
    {
        this->stackedWidget->slideIn(t_iter);
    }
    else if (index == t_iter++)
    {
        if (::GlobalDefinesSettingsDesign)
        {
            this->stackedWidget->slideIn(t_iter);
        }
    }
    else if (index == t_iter++)
    {
        this->stackedWidget->slideIn(t_iter);
    }
    else if (index == t_iter++)
    {
        this->stackedWidget->slideIn(t_iter);
    }
}

void STouchSettings::slotReturn()
{
    this->basicTimer.stop();
    this->stackedWidget->slideIn(0);
}

void STouchSettings::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == this->basicTimer.timerId())
    {
        emit this->slotReturn();
    }
}

void STouchSettings::retranslateUI()
{
    /* App bar */
    this->appBar->setText(this->m_title);

    /* Swipe list */
    int t_iter = 0;
    this->list->setTitle(t_iter++,
                         tr("Tools"));
    this->list->setTitle(t_iter++,
                         tr("Function settings"));
    this->list->setTitle(t_iter++,
                         tr("General settings"));

    t_iter = 0;
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Dashboard"),
                     tr(""),
                     tr(""),
                     QChar(0x276F));
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Calculator"),
                     tr(""),
                     tr(""),
                     QChar(0x276F));
//    this->list->setSlot(t_iter++,
//                        QIcon(),
//                     tr("Systems"),
//                     tr(""),
//                     tr(""),
//                     QChar(0x276F));
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("History"),
                     tr(""),
                     tr(""),
                     QChar(0x276F));
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Passcode"),
                     tr(""),
                     tr(""),
                     QChar(0x276F));
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Region"),
                     tr(""),
                     tr(""),
                     QChar(0x276F));
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Design"),
                     tr(""),
                     tr(""),
                     QChar(0x276F));
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Reset"),
                     tr(""),
                     tr(""),
                     QChar(0x276F));
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Info"),
                     tr(""),
                     tr(""),
                     QChar(0x276F));
}

void
STouchSettings::restyleUI()
{
    if (this->m_colorBase != ::GlobalColorCustomBase)
    {
        this->m_colorBase = ::GlobalColorCustomBase;
        this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    }
}

void
STouchSettings::changeEvent(QEvent * event)
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
