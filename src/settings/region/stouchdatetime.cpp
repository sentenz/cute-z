#include "stouchdatetime.h"
#include "../widget/list/SList.h"
#include "../widget/label/SLabel.h"

#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFocusEvent>
#include <QTimer>
#include <QDate>
#include <QTime>
#include <QEvent>
#include <QDebug>


STouchDateTime::STouchDateTime(QWidget *parent)
    : QLCDNumber(parent)
{
    this->setWindowState(Qt::WindowFullScreen);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setFocusPolicy(Qt::StrongFocus);

    this->setupWidget();
    this->setupLayout();
    this->setConnect();
}

STouchDateTime::~STouchDateTime()
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

void STouchDateTime::setupWidget()
{
    // Timer
    this->timer = new QTimer(this);
    this->timer->setInterval(1000);

    // Header
    this->header = new SLabel;
    this->header->header(tr("Date & Time"), 0x0276E);

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

void STouchDateTime::setupLayout()
{
    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->header, 1);
    mainLayout->addWidget(this->list->list(), 10);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(mainLayout);
}

void STouchDateTime::setConnect()
{
    connect(this->header, SIGNAL(signalReleased(int)), this, SIGNAL(signalReturn(void)));
    connect(this->timer, &QTimer::timeout, this, &STouchDateTime::slotUpdateWidgeds);
}

void STouchDateTime::slotUpdateWidgeds()
{
    int t_iter = 0;
    this->list->setItem(t_iter++, QDate::currentDate().toString("dd.MM.yyyy"), SList::Item::Info);
    this->list->setItem(t_iter++, QTime::currentTime().toString("hh:mm:ss"), SList::Item::Info);
}

void STouchDateTime::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    if (!this->timer->isActive())
    {
        this->slotUpdateWidgeds();

        this->timer->start();
    }

    this->setFocus();
}

void STouchDateTime::focusOutEvent(QFocusEvent *event)
{
    Q_UNUSED(event)

    if (this->timer->isActive())
    {
        this->timer->stop();
    }
}

void STouchDateTime::retranslateUI()
{
    int t_iter = 0;

    // Header
    this->header->header(t_iter, tr("Date & Time"));

    // Swipe list
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Date"),
                     tr("Format dd.mm.yyyy."),
                     QDate::currentDate().toString("dd.MM.yyyy"),
                     "");
    // TODO: Set ->setFont(QFontDatabase::systemFont(QFontDatabase::FixedFont))
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Time"),
                     tr("Format hh:mm:ss."),
                     QTime::currentTime().toString("hh:mm:ss"),
                     "");
}

void
STouchDateTime::restyleUI()
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
STouchDateTime::changeEvent(QEvent * event)
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
