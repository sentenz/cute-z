#include "stouchdatetime.h"
#include "../build/SGlobal.h"
#include "../../flickable/list/STouchFlickableList.h"
#include "../button/SReturnButton.h"

#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFocusEvent>
#include <QTimer>
#include <QDate>
#include <QTime>
#include <QEvent>
#include <QDebug>


STouchDateTime::STouchDateTime(QWidget *parent) : QLCDNumber(parent)
{
    this->setWindowState(Qt::WindowFullScreen);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setStyleSheet("background-color: " + ::GlobalBackgroundColor + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setFocusPolicy(Qt::StrongFocus);

    this->setupWidget();
    this->setupGUI();
    this->setConnect();

    setSegmentStyle(Filled);
}

STouchDateTime::~STouchDateTime()
{
    if (touchFlickable != nullptr)
    {
        delete touchFlickable;
        touchFlickable = nullptr;
    }
}

void STouchDateTime::setupWidget()
{
    /// TIMER
    this->timer = new QTimer(this);
    this->timer->setInterval(1000);

    /// Label
    this->labelTitle = new QLabel(tr("Date & Time"), this);
    this->labelTitle->setAlignment(Qt::AlignCenter);
    this->labelTitle->setStyleSheet("QLabel { font: " + ::GlobalLabelTextFont + "; color: " + ::GlobalBrightTextColor + "; background: transparent; }"); // font-variant: small-caps;
    this->labelTitle->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    /// BUTTON
    this->backButton = new SReturnButton(this);

    int t_height = ::GlobalWindowSize.height() < ::GlobalWindowSize.width() ? ::GlobalWindowSize.height() : ::GlobalWindowSize.width();
    /// Flickable
    this->touchFlickable = new STouchFlickableList;
    this->touchFlickable->setRowHeight(t_height/8);
    this->touchFlickable->setBackgroundColor(QColor(::GlobalBackgroundColor));
    this->touchFlickable->setText(tr("Date"));
    this->touchFlickable->setParameter(QDate::currentDate().toString("dd.MM.yyyy"));
    this->touchFlickable->setText(tr("Time"));
    this->touchFlickable->setParameter(QTime::currentTime().toString("hh:mm:ss"));
}

void STouchDateTime::setupGUI()
{
    QHBoxLayout *titleLayout = new QHBoxLayout;
    titleLayout->addWidget(this->backButton, 0, Qt::AlignLeft);
    titleLayout->addWidget(this->labelTitle);
    titleLayout->setContentsMargins(0,0,this->backButton->width(),0);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(this->touchFlickable);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(titleLayout);
    mainLayout->addLayout(layout);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    mainLayout->setContentsMargins(0,0,0,0);

    setLayout(mainLayout);
}

void STouchDateTime::setConnect()
{
    connect(this->timer, &QTimer::timeout, this, &STouchDateTime::slotUpdateWidgeds);
}

void STouchDateTime::slotUpdateWidgeds()
{
    this->touchFlickable->setParameter(QDate::currentDate().toString("dd.MM.yyyy"), 0);
    this->touchFlickable->setParameter(QTime::currentTime().toString("hh:mm:ss"), 1);
}

void STouchDateTime::retranslateUI()
{
    this->labelTitle->setText(tr("Date & Time"));
    this->touchFlickable->setText(tr("Date"), 0);
    this->touchFlickable->setText(tr("Time"), 1);
}

void STouchDateTime::changeEvent(QEvent* event)
{
    switch(event->type())
    {
    case QEvent::LanguageChange:
        retranslateUI();
        break;
    case QEvent::LocaleChange:
        break;
    default:
        break;
    }

    //this->setFocus();

    QWidget::changeEvent(event);
}

/*
void STouchDateTime::focusInEvent(QFocusEvent *event)
{
    Q_UNUSED(event)

    static bool activate = false;

    if (!activate)
    {
        activate = true;
    }
    else
    {
        if (!this->timer->isActive())
        {
            this->timer->start();
        }
    }

    this->setFocus();

    qDebug() << "DateTime focus IN";
}
*/

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
