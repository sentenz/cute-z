#include "stouchanalyticsiot.h"
#include "../widget/list/SList.h"

#include <QApplication>
#include <QVBoxLayout>
#include <QFocusEvent>
#include <QDate>
#include <QTime>
#include <QDebug>


STouchAnalyticsIot::STouchAnalyticsIot(QWidget *parent) : QDialog(parent)
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

STouchAnalyticsIot::~STouchAnalyticsIot()
{
    if (this->list != nullptr)
    {
        delete this->list;
        this->list = nullptr;
    }
}

void STouchAnalyticsIot::setupWidget()
{
    // Swipe list
    this->list = new SList;
    this->list->addSlot(QIcon(),
                     tr("Date"),
                     tr("Format dd.mm.yyyy."),
                     QDate::currentDate().toString("dd.MM.yyyy"),
                     "");
    // TODO: Set ->setFont(QFontDatabase::systemFont(QFontDatabase::FixedFont))
    this->list->addSlot(QIcon(),
                     tr("Time"),
                     tr("Format hh:mm:ss."),
                     QTime::currentTime().toString("hh:mm:ss"),
                     "");
}

void STouchAnalyticsIot::setupLayout()
{
    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->list->list());
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(mainLayout);
    this->setStyleSheet("border-width: 0px;");
}

void STouchAnalyticsIot::setConnect()
{
}

void STouchAnalyticsIot::focusInEvent(QFocusEvent *event)
{
    Q_UNUSED(event);
}

void STouchAnalyticsIot::retranslateUI()
{
}

void
STouchAnalyticsIot::restyleUI()
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
STouchAnalyticsIot::changeEvent(QEvent * event)
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
