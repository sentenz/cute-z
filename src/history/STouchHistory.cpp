#include "STouchHistory.h"
#include "SViewHistoryOptions.h"
#include "SPresenterHistoryOdometer.h"
#include "../widget/list/SList.h"
#include "../util/dialog/SAppBar.h"

#include <QApplication>
#include <QTimerEvent>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>


STouchHistory::STouchHistory(QWidget * parent)
    : QWidget(parent)
{
    this->setWindowState(Qt::WindowFullScreen);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");

    this->setupWidget();
    this->setupLayout();
    this->setConnect();
}

STouchHistory::~STouchHistory()
{
    if (this->list != nullptr)
    {
        delete this->list;
        this->list = nullptr;
    }
}

void STouchHistory::setupWidget()
{
    /* App bar */
    this->appBar = new SAppBar(QtMaterialTheme::icon("navigation", "arrow_back"), this->m_title, this);

    /* Swipe list */
    this->list = new SList;
    if (::GlobalDefinesNfc)
    {
        this->list->addSlot(QIcon(),
                         tr("Paternoster"),
                         tr(""),
                         tr(""),
                         QChar(0x276F));
    }
    if (::GlobalDefinesEncoder)
    {
        this->list->addSlot(QIcon(),
                         tr("Odometer"),
                         tr(""),
                         tr(""),
                         QChar(0x276F));
    }
}

void STouchHistory::setupLayout()
{
    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->appBar, 1);
    mainLayout->addWidget(this->list->list(), 9);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(mainLayout);
}

void STouchHistory::setConnect()
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
    connect(this->list, SIGNAL(signalReleased(QString)), this, SLOT(slotList(QString)));
}

void STouchHistory::slotList(const QString &content)
{
    this->basicTimer.start(20 * 60 * 1000, this);

    if (!content.compare(tr("Paternoster")))
    {
        if (::GlobalDefinesNfc)
        {
        }
    }
    else if (!content.compare(tr("Odometer")))
    {
        if (::GlobalDefinesEncoder)
        {
            SViewHistoryOptions viewHistoryOptions(this);
            viewHistoryOptions.closeable(true);
            SPresenterHistoryOdometer presenterHistoryOdometer(&viewHistoryOptions, this);
            presenterHistoryOdometer.create();
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
    /* App bar */
    this->appBar->setText(this->m_title);

    /* Swipe list */
    int t_iter = 0;
    if (::GlobalDefinesNfc)
    {
        this->list->setSlot(t_iter++,
                         QIcon(),
                         tr("Paternoster"),
                         tr(""),
                         tr(""),
                         QChar(0x276F));
    }
    if (::GlobalDefinesEncoder)
    {
        this->list->setSlot(t_iter++,
                         QIcon(),
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
