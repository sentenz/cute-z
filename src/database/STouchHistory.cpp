#include "STouchHistory.h"
#include "STouchDatabaseEncoder.h"
#include "STouchHistoryEncoder.h"
#include "../widget/list/SList.h"
#include "../widget/label/SLabel.h"
#include "../widget/stacked/SAnimatedStackedWidget.h"

#include <QApplication>
#include <QTimerEvent>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>

#include "SPresenterHistoryDetail.h"


STouchHistory::STouchHistory(QWidget *parent) : QDialog(parent)
{
    this->setWindowState(Qt::WindowFullScreen);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    this->setupWidget();
    this->setupLayout();
    this->setConnect();
}

STouchHistory::~STouchHistory()
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

void STouchHistory::setupWidget()
{
    // Header
    this->header = new SLabel;
    this->header->header(tr("History"), 0x0276E);

    // Swipe list
    this->list = new SList;
    if (::GlobalDefinesNfc)
    {
        this->list->slot("",
                         tr("Paternoster"),
                         tr(""),
                         tr(""),
                         QChar(0x276F));
    }
    if (::GlobalDefinesEncoder)
    {
        this->list->slot("",
                         tr("Odometer"),
                         tr(""),
                         tr(""),
                         QChar(0x276F));
    }
}

void STouchHistory::setupLayout()
{
    QVBoxLayout * subLayout = new QVBoxLayout(this);
    subLayout->addWidget(this->header, 1);
    subLayout->addWidget(this->list->listItems(), 10);
    subLayout->setSpacing(0);
    subLayout->setContentsMargins(0, 0, 0, 0);

    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(subLayout);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(mainLayout);
}

void STouchHistory::setConnect()
{
    /* Header */
    connect(this->header, SIGNAL(signalReleased(int)), this, SIGNAL(signalReturn(void)));
    /* Swipe list */
    connect(this->list, SIGNAL(signalReleased(QString)), this, SLOT(slotList(QString)));
}

void STouchHistory::slotList(const QString &content)
{
    this->basicTimer.start(20 * 60 * 1000, this);

    if (!content.compare(tr("Paternoster")))
    {
#ifdef S_UNUSED
        if (::GlobalDefinesNfc)
        {
        }
#endif
    }
    else if (!content.compare(tr("Odometer")))
    {
        if (::GlobalDefinesEncoder)
        {
//            STouchHistoryEncoder touchHistoryEncoder(this);
//            touchHistoryEncoder.setCloseable(true);
//            touchHistoryEncoder.exec();
            SPresenterHistoryDetail presenterHistoryDetail(this);
            presenterHistoryDetail.create();
        }
    }
}

void STouchHistory::slotReturn()
{
    this->basicTimer.stop();
}

void STouchHistory::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == this->basicTimer.timerId())
    {
        emit slotReturn();
    }
}

void STouchHistory::retranslateUI()
{
    int t_iter = 0;

    // Header
    this->header->header(t_iter, tr("History"));

    // Swipe list
    if (::GlobalDefinesNfc)
    {
        this->list->slot(t_iter++,
                         "",
                         tr("Paternoster"),
                         tr(""),
                         tr(""),
                         QChar(0x276F));
    }
    if (::GlobalDefinesEncoder)
    {
        this->list->slot(t_iter++,
                         "",
                         tr("Odometer"),
                         tr(""),
                         tr(""),
                         QChar(0x276F));
    }
}

void
STouchHistory::restyleUI()
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
STouchHistory::changeEvent(QEvent * event)
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
