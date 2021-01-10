#include "stouchinfomodule.h"
#include "../widget/list/SList.h"
#include "../widget/label/SLabel.h"

#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QNetworkInterface>


STouchInfoModule::STouchInfoModule(QWidget *parent) : QDialog(parent)
{
    this->setWindowState(Qt::WindowFullScreen);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    this->setupWidget();
    this->setupLayout();
    this->setConnect();
}

STouchInfoModule::~STouchInfoModule()
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

void STouchInfoModule::setupWidget()
{
    // Header
    this->header = new SLabel;
    this->header->header(tr("Module"), 0x0276E);

    // Swipe list
    this->list = new SList;
    this->list->addSlot(QIcon(),
                     tr("Module"),
                     tr(""),
                     ::GlobalModule,
                     "");
    this->list->addSlot(QIcon(),
                     tr("Software Version"),
                     tr(""),
                     ::GlobalVersionSW,
                     "");
    this->list->addSlot(QIcon(),
                     tr("Hardware Version"),
                     tr(""),
                     ::GlobalVersionSW,
                     "");

    foreach (QNetworkInterface networkInterface, QNetworkInterface::allInterfaces())
    {
        if (networkInterface.hardwareAddress().size() == 17)
        {
            uint64_t mac = networkInterface.hardwareAddress().remove(":").toULongLong(new bool, 16);
            if (mac)
            {
                this->list->addSlot(QIcon(),
                                 tr("Serial Number"),
                                 tr(""),
                                 networkInterface.hardwareAddress().remove(":"),
                                 "");
                     break;
            }
        }
    }
}

void STouchInfoModule::setupLayout()
{
    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->header, 1);
    mainLayout->addWidget(this->list->list(), 10);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    setLayout(mainLayout);
}

void STouchInfoModule::setConnect()
{
    // Lists
    connect(this->header, SIGNAL(signalReleased(int)), this, SIGNAL(signalReturn(void)));
}

void STouchInfoModule::retranslateUI()
{
    int t_iter = 0;

    // Header
    this->header->header(t_iter, tr("Module"));

    // Swipe list
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Module"),
                     tr(""),
                     ::GlobalModule,
                     "");
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Software Version"),
                     tr(""),
                     ::GlobalVersionSW,
                     "");
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Hardware Version"),
                     tr(""),
                     ::GlobalVersionSW,
                     "");
    this->list->setItem(t_iter++, tr("Serial Number"), SList::Item::Text);
}

void
STouchInfoModule::restyleUI()
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
STouchInfoModule::changeEvent(QEvent * event)
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
