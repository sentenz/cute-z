#include "stouchsettingsregion.h"
#include "region/stouchlanguage.h"
#include "region/stouchdatetime.h"
#include "../widget/label/SLabel.h"
#include "../widget/list/SList.h"
#include "../widget/stacked/SAnimatedStackedWidget.h"

#include <QApplication>
#include <QTimerEvent>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QDebug>


STouchSettingsRegion::STouchSettingsRegion(QWidget *parent) : QDialog(parent)
{
    this->setWindowState(Qt::WindowFullScreen);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    this->setupWidget();
    this->setupLayout();
    this->setConnect();
}

STouchSettingsRegion::~STouchSettingsRegion()
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
    if (this->touchLanguage != nullptr)
    {
        delete this->touchLanguage;
        this->touchLanguage = nullptr;
    }
    if (this->touchDateTime != nullptr)
    {
        delete this->touchDateTime;
        this->touchDateTime = nullptr;
    }
}

void STouchSettingsRegion::setupWidget()
{
    // Header
    this->header = new SLabel;
    this->header->header(tr("Region"), 0x0276E);

    // Swipe list
    this->list = new SList;
    this->list->addSlot(QIcon(),
                     tr("Language"),
                     tr(""),
                     tr(""),
                     QChar(0x276F));
    this->list->addSlot(QIcon(),
                     tr("Date & Time"),
                     tr(""),
                     tr(""),
                     QChar(0x276F));

    // REGION LANGUAGE
    this->touchLanguage = new STouchLanguage;

    // REGION Date Time
    this->touchDateTime = new STouchDateTime;
}

void STouchSettingsRegion::setupLayout()
{
    QVBoxLayout * subLayout = new QVBoxLayout(this);
    subLayout->addWidget(this->header, 1);
    subLayout->addWidget(this->list->list(), 10);
    subLayout->setSpacing(0);
    subLayout->setMargin(0);
    subLayout->setContentsMargins(0,0,0,0);
    QWidget * widget = new QWidget(this);
    widget->setLayout(subLayout);

    this->stackedWidget = new SAnimatedStackedWidget(this);
    this->stackedWidget->addWidget(widget);
    this->stackedWidget->addWidget(this->touchLanguage);
    this->stackedWidget->addWidget(this->touchDateTime);

    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->stackedWidget);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    mainLayout->setContentsMargins(0,0,0,0);

    this->setLayout(mainLayout);
}

void STouchSettingsRegion::setConnect()
{
    // Lists
    connect(this->header, SIGNAL(signalReleased(int)), this, SIGNAL(signalReturn(void)));
    connect(this->list, SIGNAL(signalReleased(int)), this, SLOT(slotList(int)));
    // Subwidgets
    connect(this->touchLanguage, &STouchLanguage::signalReturn, this, &STouchSettingsRegion::slotReturn);
    connect(this->touchDateTime, &STouchDateTime::signalReturn, this, &STouchSettingsRegion::slotReturn);
}

void STouchSettingsRegion::slotList(const int index)
{
    this->basicTimer.start(20 * 60 * 1000, this);

    switch (index)
    {
    case 0:
        this->stackedWidget->slideIn(this->touchLanguage);
        break;

    case 1:
        this->stackedWidget->slideIn(this->touchDateTime);
        break;

    default:
        break;
    }
}

void STouchSettingsRegion::slotReturn()
{
    this->basicTimer.stop();
    this->stackedWidget->slideIn(0);
}

void STouchSettingsRegion::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == this->basicTimer.timerId())
    {
        emit this->slotReturn();
    }
}

void STouchSettingsRegion::retranslateUI()
{
    int t_iter = 0;

    // Header
    this->header->header(t_iter, tr("Region"));

    // Swipe list
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Language"),
                     tr(""),
                     tr(""),
                     QChar(0x276F));
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Date & Time"),
                     tr(""),
                     tr(""),
                     QChar(0x276F));
}

void
STouchSettingsRegion::restyleUI()
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
STouchSettingsRegion::changeEvent(QEvent * event)
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
