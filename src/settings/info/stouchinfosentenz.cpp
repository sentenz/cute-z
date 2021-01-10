#include "stouchinfosentenz.h"
#include "../widget/list/SList.h"
#include "../widget/label/SLabel.h"

#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QDebug>


STouchInfoSentenz::STouchInfoSentenz(QWidget *parent) : QDialog(parent)
{
    this->setWindowState(Qt::WindowFullScreen);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    this->setupWidget();
    this->setupLayout();
    this->setConnect();
}

STouchInfoSentenz::~STouchInfoSentenz()
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

void STouchInfoSentenz::setupWidget()
{
    // Header
    this->header = new SLabel;
    this->header->header(tr("Sentenz"), 0x0276E);

    // Swipe list
    this->list = new SList;
    this->list->addBox(QIcon(":/images/sentenz.svg"),
                       tr("Sentenz"),
                       tr("Automation Evolution"),
                       "",
                       "");
}

void STouchInfoSentenz::setupLayout()
{
    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->header, 1);
    mainLayout->addWidget(this->list->list(), 10);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    setLayout(mainLayout);
}

void
STouchInfoSentenz::setConnect()
{
    // Lists
    connect(this->header, SIGNAL(signalReleased(int)), this, SIGNAL(signalReturn(void)));
}

void STouchInfoSentenz::retranslateUI()
{
}

void
STouchInfoSentenz::restyleUI()
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
STouchInfoSentenz::changeEvent(QEvent * event)
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
