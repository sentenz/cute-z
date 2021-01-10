#include "stouchanalyticsdatabase.h"
#include "../database/SDatabaseEncoder.h"
#include "../widget/list/SList.h"

#include <QApplication>
#include <QVBoxLayout>
#include <QFocusEvent>
#include <QDebug>


STouchAnalyticsDatabase::STouchAnalyticsDatabase(QWidget *parent) : QDialog(parent)
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

STouchAnalyticsDatabase::~STouchAnalyticsDatabase()
{
    if (this->list != nullptr)
    {
        delete this->list;
        this->list = nullptr;
    }
}

void STouchAnalyticsDatabase::setupWidget()
{
    // Swipe list
    if (::GlobalDefinesEncoder)
    {
        this->list = new SList;
        this->list->topic(tr("Odometer"));
        this->list->slot("",
                         QChar(0x03A3) + tr(" Measurements"),
                         tr(""),
                         QString::number(this->m_measurement).append(" m"),
                         "");
        this->list->slot("",
                         QChar(0x03A3) + tr(" Orders"),
                         tr(""),
                         QString::number(this->m_order),
                         "");
    }
}

void STouchAnalyticsDatabase::setupLayout()
{
    if (this->list == nullptr)
    {
        return;
    }

    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->list->listItems(), 10);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(mainLayout);
    this->setStyleSheet("border-width: 0px;");
}

void STouchAnalyticsDatabase::setConnect()
{
}

void STouchAnalyticsDatabase::setDatabase()
{
    if (::GlobalDefinesEncoder)
    {
        SDatabaseEncoder * database = new SDatabaseEncoder(::GlobalConfigPathDatabase);
//        this->m_measurement = database->getTotalLength();
//        this->m_order = database->getTotalOrders();
        database->deleteLater();
        database = nullptr;

        this->retranslateUI();
    }
}

void STouchAnalyticsDatabase::focusInEvent(QFocusEvent *event)
{
    Q_UNUSED(event);

    this->setDatabase();
}

void STouchAnalyticsDatabase::retranslateUI()
{
    int t_iter = 0;

    if (::GlobalDefinesEncoder)
    {
        this->list->topic(t_iter, tr("Odometer"));
        this->list->slot(t_iter++,
                         "",
                         QChar(0x03A3) + tr(" Measurements"),
                         tr(""),
                         QString::number(this->m_measurement).append(" m"),
                         "");
        this->list->slot(t_iter++,
                         "",
                         QChar(0x03A3) + tr(" Orders"),
                         tr(""),
                         QString::number(this->m_order),
                         "");
    }
}


void
STouchAnalyticsDatabase::restyleUI()
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
STouchAnalyticsDatabase::changeEvent(QEvent * event)
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
