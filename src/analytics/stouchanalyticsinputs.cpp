#include "stouchanalyticsinputs.h"
#include "../widget/list/SList.h"

#include <QApplication>
#include <QVBoxLayout>
#include <QFocusEvent>
#include <QTimer>
#include <QDate>
#include <QTime>
#include <QDebug>


STouchAnalyticsInputs::STouchAnalyticsInputs(QWidget *parent) : QDialog(parent)
{
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //this->setAttribute(Qt::WA_OpaquePaintEvent, true);
    //setAttribute(Qt::WA_PaintOnScreen, true);
    //this->activateWindow();
    //this->setWindowState(Qt::WindowActive);
    //this->raise();
    //this->showNormal();

    this->setupWidget();
    this->setupLayout();
    this->setConnect();
}

STouchAnalyticsInputs::~STouchAnalyticsInputs()
{
    if (this->list != nullptr)
    {
        delete this->list;
        this->list = nullptr;
    }
}

void STouchAnalyticsInputs::setupWidget()
{
    // Timer
    timer = new QTimer(this);

    // Swipe list
    this->list = new SList;
    // TODO: Set ->setFont(QFontDatabase::systemFont(QFontDatabase::FixedFont))
    this->list->addSlot(QIcon(),
                     tr("Operating time"),
                     tr(""),
                     QTime::currentTime().toString("hh:mm:ss"),
                     "");
    this->list->addSlot(QIcon(),
                     tr("Preventive maintenance"),
                     tr("Next Date."),
                     QDate::currentDate().toString("dd.MM.yyyy"),
                     "");
}

void STouchAnalyticsInputs::setupLayout()
{    
    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->list->list());
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(mainLayout);
    this->setStyleSheet("border-width: 0px;");
}

void STouchAnalyticsInputs::setConnect()
{
    connect(timer, &QTimer::timeout, this, &STouchAnalyticsInputs::slotUpdateWidgeds);
}

void STouchAnalyticsInputs::slotUpdateWidgeds()
{
    int t_iter = 0;

    // Swipe list
    this->list->setItem(t_iter++, QTime::currentTime().toString("hh:mm:ss"), SList::Item::Info);
    this->list->setItem(t_iter++, QDate::currentDate().toString("dd.MM.yyyy"), SList::Item::Info);
}

void STouchAnalyticsInputs::focusInEvent(QFocusEvent *event)
{
    Q_UNUSED(event);

    static bool activate = false;

    if (!activate)
    {
        activate = true;
    }
    else
    {
        if (!timer->isActive())
        {
            this->slotUpdateWidgeds();

            timer->start(200);
        }
    }
}

void STouchAnalyticsInputs::focusOutEvent(QFocusEvent *event)
{
    Q_UNUSED(event);

    if (timer->isActive())
    {
        timer->stop();
    }
}


void STouchAnalyticsInputs::retranslateUI()
{
    int t_iter = 0;

    // Swipe list
    this->list->setSlot(t_iter++,
                     QIcon(),
                     tr("Operating time"),
                     tr(""),
                     QTime::currentTime().toString("hh:mm:ss"),
                     "");
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Preventive maintenance"),
                     tr("Next Date."),
                     QDate::currentDate().toString("dd.MM.yyyy"),
                     "");
}

void
STouchAnalyticsInputs::restyleUI()
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
STouchAnalyticsInputs::changeEvent(QEvent * event)
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
