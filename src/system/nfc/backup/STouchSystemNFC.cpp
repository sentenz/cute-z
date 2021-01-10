#include "STouchSystemNFC.h"
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
#include <QDebug>


STouchSystemNFC::STouchSystemNFC(QWidget *parent) : QDialog(parent)
{
    this->resize(::GlobalWindowSize);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setStyleSheet("background-color: " + ::GlobalBackgroundColor + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_UnderMouse, false);
    this->setMouseTracking(true);
    this->setObjectName("STouchSystemNFC");

    this->setUpWidget();
    this->setUpGUI();
    this->setConnect();
}

STouchSystemNFC::~STouchSystemNFC()
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

void STouchSystemNFC::setUpWidget()
{
    /// NFC
    this->touchNFC = new STouchNFC;

    /// Engine
    this->engine = new SEngine(BUS::GPIO);
}

void STouchSystemNFC::setUpGUI()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->touchNFC);
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);

    this->setLayout(mainLayout);
}

void STouchSystemNFC::setConnect()
{
    connect(this->touchNFC, &STouchNFC::signalRun, this, &STouchSystemNFC::slotRun);
    connect(this->touchNFC, &STouchNFC::signalStop, this, &STouchSystemNFC::slotStop);
}

void STouchSystemNFC::slotRun()
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

void STouchSystemNFC::slotStop()
{
    this->setDirectionNeutral();
}

void STouchSystemNFC::setDirectionForward()
{
    this->engine->forward(Engine::EMotor);
}

void STouchSystemNFC::setDirectionBackward()
{
    this->engine->backward(Engine::EMotor);
}

void STouchSystemNFC::setDirectionNeutral()
{
    this->engine->neutral(Engine::EMotor);
}

void STouchSystemNFC::retranslateUI()
{
}

void STouchSystemNFC::changeEvent(QEvent* event)
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

    QWidget::changeEvent(event);
}
