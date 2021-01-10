#include "SAnimation.h"
#include "../build/SGlobal.h"

#include <QApplication>
#include <QLabel>
#include <QString>
#include <QFile>
#include <QMovie>
#include <QTimer>
#include <QStackedLayout>
#include <QVBoxLayout>
#include <QPropertyAnimation>
#include <QShowEvent>
#include <QCloseEvent>
#include <QDebug>


SAnimation::SAnimation(QWidget *parent) : QWidget(parent)
{
    this->setWindowState(Qt::WindowFullScreen);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setStyleSheet("background-color: " + ::GlobalColorBase.name() + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setObjectName("Generic");

    this->setupWidget();
    this->setupLayout();
    this->setConnect();
}

SAnimation::~SAnimation()
{
}

void SAnimation::setupWidget()
{
    this->movie = new QMovie;
    this->processLabel = new QLabel(this);
    this->processLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->processLabel->setMovie(this->movie);

    this->slotDefaultEvent();
}

void SAnimation::setupLayout()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->processLabel, 0, Qt::AlignCenter);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(mainLayout);
}

void SAnimation::setConnect()
{
}

void SAnimation::slotDefaultEvent()
{
    if (!this->m_defaultFileName.isEmpty())
    {
        this->movie->stop();
        this->movie->setFileName(this->m_defaultFileName);
        this->movie->start();
    }

    this->m_accepted = false;
}

void SAnimation::mousePressEvent(QMouseEvent *event)
{
    int x1 = this->size().width()/8;
    int x2 = this->size().width()/1.2;
    int y1 = this->size().height()/4.8;
    int y2 = this->size().height()/1.1;

    if ((event->pos().x() < x1) || (event->pos().x() > x2) || (event->pos().y() < y1) || (event->pos().y() > y2))
    {
        this->m_event = false;
        return;
    }
    else
    {
        this->m_event = true;
    }

    if (this->m_accepted)
    {
        return;
    }

    if (!this->m_pressedFileName.isEmpty())
    {
        this->movie->stop();
        this->movie->setFileName(this->m_pressedFileName);
        this->movie->start();
    }

    emit this->pressed();
}

void SAnimation::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);

    if (!this->m_event)
    {
        return;
    }

    if (this->m_accepted)
    {
        return;
    }

    this->m_accepted = true;

    if (!this->m_releasedFileName.isEmpty())
    {
        this->movie->stop();
        this->movie->setFileName(this->m_releasedFileName);
        this->movie->start();
    }

    QTimer::singleShot(0, this, SIGNAL(released()));
    QTimer::singleShot(300, this, SLOT(slotDefaultEvent()));

}

void SAnimation::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);

    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity", this);
    animation->setDuration(::GlobalAnimationTimeIn);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->setEasingCurve(QEasingCurve::OutCubic);
    animation->start(QPropertyAnimation::DeleteWhenStopped);
}

void SAnimation::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);

    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity", this);
    animation->setDuration(::GlobalAnimationTimeOut);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->setEasingCurve(QEasingCurve::InCubic);
    animation->start(QPropertyAnimation::DeleteWhenStopped);
}

void SAnimation::setDefaultFileName(const QString fileName)
{
    this->m_defaultFileName = fileName;

    this->slotDefaultEvent();
}

void SAnimation::setPressedFileName(const QString fileName)
{
    this->m_pressedFileName = fileName;
}

void SAnimation::setReleasedFileName(const QString fileName)
{
    this->m_releasedFileName = fileName;
}

void SAnimation::retranslateUI()
{
}

void SAnimation::changeEvent(QEvent *event)
{
    switch(event->type())
    {
    case QEvent::LanguageChange:
        this->retranslateUI();
        break;

    case QEvent::LocaleChange:
        break;

    default:
        break;
    }

    QWidget::changeEvent(event);
}
