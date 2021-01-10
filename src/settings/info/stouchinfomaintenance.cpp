#include "stouchinfomaintenance.h"
#include "../widget/list/SList.h"
#include "../widget/label/SLabel.h"

#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QDebug>


STouchInfoMaintenance::STouchInfoMaintenance(QWidget *parent) : QDialog(parent)
{
    this->setWindowState(Qt::WindowFullScreen);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    this->setupWidget();
    this->setupLayout();
    this->setConnect();
}

STouchInfoMaintenance::~STouchInfoMaintenance()
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
}

void STouchInfoMaintenance::setupWidget()
{
    // Header
    this->header = new SLabel;
    this->header->header(tr("Maintenance"), 0x0276E);

    // Swipe list
    this->list = new SList;
    this->list->addBanner(QIcon(":/images/sentenz.svg"),
                       tr("Maintenance"),
                       tr("Recursive search is disabled by passing FALSE as the third argument."));
}

void STouchInfoMaintenance::setupLayout()
{
    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->header, 1);
    mainLayout->addWidget(this->list->list(), 10);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(mainLayout);
}

void STouchInfoMaintenance::setConnect()
{
    // Header
    connect(this->header, SIGNAL(signalReleased(int)), this, SIGNAL(signalReturn(void)));
}

void STouchInfoMaintenance::retranslateUI()
{
    int t_iter = 0;

    // Header
    this->header->header(t_iter, tr("Maintenance"));

    // Swipe list
    this->list->setBanner(t_iter++,
                          QIcon(),
                       tr("Maintenance"),
                       tr("Recursive search is disabled by passing FALSE as the third argument."));
}

void
STouchInfoMaintenance::restyleUI()
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
STouchInfoMaintenance::changeEvent(QEvent * event)
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
