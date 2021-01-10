#include "stouchsettingsinfo.h"
#include "info/stouchinfosentenz.h"
#include "info/stouchinfomodule.h"
#include "info/stouchinfomaintenance.h"
#include "../widget/list/SList.h"
#include "../widget/label/SLabel.h"
#include "../widget/stacked/SAnimatedStackedWidget.h"

#include <QApplication>
#include <QTimerEvent>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QDebug>


STouchSettingsInfo::STouchSettingsInfo(QWidget *parent) : QDialog(parent)
{
    this->setWindowState(Qt::WindowFullScreen);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    this->setupWidget();
    this->setupLayout();
    this->setConnect();
}

STouchSettingsInfo::~STouchSettingsInfo()
{
    if (this->header != nullptr)
    {
        delete this->header;
        this->header = nullptr;
    }
    if (this->list != nullptr)
    {
        delete this->list;
        this->list = nullptr;
    }
    if (this->touchInfoSentenz != nullptr)
    {
        delete this->touchInfoSentenz;
        this->touchInfoSentenz = nullptr;
    }
    if (this->touchInfoModule != nullptr)
    {
        delete this->touchInfoModule;
        this->touchInfoModule = nullptr;
    }
    if (this->touchInfoMaintenance != nullptr)
    {
        delete this->touchInfoMaintenance;
        this->touchInfoMaintenance = nullptr;
    }
}

void STouchSettingsInfo::setupWidget()
{
    // Header
    this->header = new SLabel;
    this->header->header(tr("Info"), 0x0276E);

    // Swipe list
    this->list = new SList;
    this->list->addSlot(QIcon(),
                     tr("Sentenz"),
                     tr("About Sentenz."),
                     "",
                     QChar(0x276F));
    this->list->addSlot(QIcon(),
                     tr("Module"),
                     tr("Module specification."),
                     "",
                     QChar(0x276F));
    this->list->addSlot(QIcon(),
                     tr("Maintenance"),
                     tr(""),
                     "",
                     QChar(0x276F));

    // About Sentenz
    this->touchInfoSentenz = new STouchInfoSentenz;

    // About Module
    this->touchInfoModule = new STouchInfoModule;

    // About Maintenance
    this->touchInfoMaintenance = new STouchInfoMaintenance;
}

void STouchSettingsInfo::setupLayout()
{
    QVBoxLayout * subLayout = new QVBoxLayout(this);
    subLayout->addWidget(this->header, 1);
    subLayout->addWidget(this->list->list(), 10);
    subLayout->setSpacing(0);
    subLayout->setMargin(0);
    subLayout->setContentsMargins(0, 0, 0, 0);
    QWidget * widget = new QWidget(this);
    widget->setLayout(subLayout);

    this->stackedWidget = new SAnimatedStackedWidget(this);
    this->stackedWidget->addWidget(widget);
    this->stackedWidget->addWidget(this->touchInfoSentenz);
    this->stackedWidget->addWidget(this->touchInfoModule);
    this->stackedWidget->addWidget(this->touchInfoMaintenance);

    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->stackedWidget);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    setLayout(mainLayout);
}

void STouchSettingsInfo::setConnect()
{
    // Lists
    connect(this->header, SIGNAL(signalReleased(int)), this, SIGNAL(signalReturn(void)));
    connect(this->list, SIGNAL(signalReleased(int)), this, SLOT(slotList(int)));
    // Subwidgets
    connect(this->touchInfoSentenz, &STouchInfoSentenz::signalReturn, this, &STouchSettingsInfo::slotReturn);
    connect(this->touchInfoModule, &STouchInfoModule::signalReturn, this, &STouchSettingsInfo::slotReturn);
    connect(this->touchInfoMaintenance, &STouchInfoMaintenance::signalReturn, this, &STouchSettingsInfo::slotReturn);
}

void
STouchSettingsInfo::slotList(const int index)
{
    basicTimer.start(20 * 60 * 1000, this);

    switch (index)
    {
    case 0:
        this->stackedWidget->slideIn(this->touchInfoSentenz);
        break;

    case 1:
        this->stackedWidget->slideIn(this->touchInfoModule);
        break;

    case 2:
        this->stackedWidget->slideIn(this->touchInfoMaintenance);
        break;

    default:
        break;
    }
}

void STouchSettingsInfo::slotReturn()
{
    this->basicTimer.stop();
    this->stackedWidget->slideIn(0);
}

void STouchSettingsInfo::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == this->basicTimer.timerId())
    {
        emit this->slotReturn();
    }
}

void STouchSettingsInfo::retranslateUI()
{
    int t_iter = 0;

    // Header
    this->header->header(t_iter, tr("Info"));

    // Swipe list
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Sentenz"),
                     tr("About Sentenz."),
                     "",
                     QChar(0x276F));
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Module"),
                     tr("Module specification."),
                     "",
                     QChar(0x276F));
    this->list->setSlot(t_iter++,
                        QIcon(),
                        tr("Maintenance"),
                     tr(""),
                     "",
                     QChar(0x276F));
}

void
STouchSettingsInfo::restyleUI()
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
STouchSettingsInfo::changeEvent(QEvent * event)
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
