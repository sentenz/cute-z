#include "SControlNFC.h"
#include "STouchNFC.h"
#include "../build/SGlobal.h"
//#include "../device/SEngine.h"
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


SControlNFC::SControlNFC(QWidget *parent) : QDialog(parent)
{
    this->setObjectName("SControlNFC");
    this->setWindowState(Qt::WindowFullScreen);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_UnderMouse, false);
    this->setMouseTracking(true);

    this->setupWidget();
    this->setupLayout();
    this->setConnect();
}

SControlNFC::~SControlNFC()
{
    if (this->touchNFC != nullptr)
    {
        delete this->touchNFC;
        this->touchNFC = nullptr;
    }
    if (this->engine != nullptr)
    {
        delete this->engine;
        this->engine = nullptr;
    }
}

void SControlNFC::setupWidget()
{
    /// NFC
    this->touchNFC = new STouchNFC;
    this->touchNFC->setMode(SThreadNFC::NFC::Run);

    /// Engine
    this->engine = new SEngine(BUS::GPIO);
}

void SControlNFC::setupLayout()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->touchNFC);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);

    this->setLayout(mainLayout);
}

void SControlNFC::setConnect()
{
    connect(this->touchNFC, &STouchNFC::signalRun, this, &SControlNFC::slotRun);
    connect(this->touchNFC, &STouchNFC::signalReturn, this, &SControlNFC::signalReturn);
    connect(this->touchNFC, &STouchNFC::signalOptions, this, &SControlNFC::signalOptions);
    connect(this, &SControlNFC::signalRun, this->touchNFC, &STouchNFC::slotRun);
}

void SControlNFC::stop()
{
    this->touchNFC->stop();
}

void SControlNFC::pause()
{
    if (this->isRunning())
    {
        this->touchNFC->pause();
    }
}

bool SControlNFC::isRunning() const
{
    return this->m_running;
}

void SControlNFC::slotRun(const bool run)
{
#ifdef S_DEBUG_SYSTEM
    qDebug() << "SControlNFC::slotRun";
#endif
    if (run)
    {
        if (this->touchNFC->unidirectional())
        {
            this->setDirectionForward();
        }
        else if (this->touchNFC->bidirectional())
        {
            if (this->touchNFC->up())
            {
                this->setDirectionForward();
            }
            else if (this->touchNFC->down())
            {
                this->setDirectionBackward();
            }
        }
    }
    else
    {
        this->setDirectionNeutral();
    }

}

void SControlNFC::setDirectionForward()
{
#ifdef S_DEBUG_SYSTEM
    qDebug() << "SControlNFC::setDirectionForward";
#endif
    emit this->signalRun(true);

    this->m_running = true;
    this->engine->forward(Engine::EMotor);
}

void SControlNFC::setDirectionBackward()
{
#ifdef S_DEBUG_SYSTEM
    qDebug() << "SControlNFC::setDirectionBackward";
#endif
    emit this->signalRun(true);

    this->m_running = true;
    this->engine->backward(Engine::EMotor);
}

void SControlNFC::setDirectionNeutral()
{
#ifdef S_DEBUG_SYSTEM
    qDebug() << "SControlNFC::setDirectionNeutral";
#endif
    emit this->signalRun(false);

    this->m_running = false;
    this->engine->neutral(Engine::EMotor);
}

void SControlNFC::retranslateUI()
{
}

void SControlNFC::changeEvent(QEvent* event)
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
