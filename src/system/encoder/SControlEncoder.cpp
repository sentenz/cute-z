#include "SControlEncoder.h"
#include "STouchEncoder.h"
#include <../device/SEngine.h>

#include <QApplication>
#include <QLabel>
#include <QTimer>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QException>
#include <QStackedWidget>
#ifdef S_DEBUG_SYSTEM
#include <QDebug>
#endif


SControlEncoder::SControlEncoder(QWidget *parent) : QDialog(parent)
{
    this->setObjectName("SControlEncoder");
    this->setWindowState(Qt::WindowFullScreen);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_UnderMouse, false);
    this->setMouseTracking(true);

    this->setupWidget();
    this->setupLayout();
    this->setConnect();
}

SControlEncoder::~SControlEncoder()
{
    if (this->touchEncoder != nullptr)
    {
        delete this->touchEncoder;
        this->touchEncoder = nullptr;
    }
    if (this->engine != nullptr)
    {
        delete this->engine;
        this->engine = nullptr;
    }
}

void SControlEncoder::setupWidget()
{
    /// Encoder
    this->touchEncoder = new STouchEncoder;

    /// Engine
    this->engine = new SEngine(BUS::GPIO);
}

void SControlEncoder::setupLayout()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->touchEncoder);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);

    this->setLayout(mainLayout);
}

void SControlEncoder::setConnect()
{
    connect(this->touchEncoder, &STouchEncoder::signalRun, this, &SControlEncoder::slotRun);
    connect(this->touchEncoder, &STouchEncoder::signalReturn, this, &SControlEncoder::signalReturn);
    connect(this, &SControlEncoder::signalRun, this->touchEncoder, &STouchEncoder::slotRun);
}

void SControlEncoder::stop()
{
    this->touchEncoder->stop();
}

void SControlEncoder::pause()
{
    if (this->isRunning())
    {
        this->touchEncoder->pause();
    }
}

bool SControlEncoder::isRunning() const
{
    return this->m_running;
}

void SControlEncoder::slotRun(const bool run)
{
#ifdef S_DEBUG_SYSTEM
    qDebug() << "SControlEncoder::slotRun";
#endif
    if (run)
    {
        if (this->touchEncoder->up())
        {
            this->setDirectionForward();
        }
        else if (this->touchEncoder->down())
        {
            this->setDirectionBackward();
        }
    }
    else
    {
        this->setDirectionNeutral();
    }
}

void SControlEncoder::setDirectionForward()
{
#ifdef S_DEBUG_SYSTEM
    qDebug() << "SControlEncoder::setDirectionForward";
#endif
    emit this->signalRun(true);

    this->m_running = true;
    this->engine->forward(Engine::EMotor);
}

void SControlEncoder::setDirectionBackward()
{
#ifdef S_DEBUG_SYSTEM
    qDebug() << "SControlEncoder::setDirectionBackward";
#endif
    emit this->signalRun(true);

    this->m_running = true;
    this->engine->backward(Engine::EMotor);
}

void SControlEncoder::setDirectionNeutral()
{
#ifdef S_DEBUG_SYSTEM
    qDebug() << "SControlEncoder::setDirectionNeutral";
#endif
    emit this->signalRun(false);

    this->m_running = false;
    this->engine->neutral(Engine::EMotor);
}

void SControlEncoder::retranslateUI()
{
}

void SControlEncoder::changeEvent(QEvent* event)
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
