#include "STouchSystemEncoder.h"
#include "STouchEncoder.h"
#include "../build/SGlobal.h"
#include "../device/SEngine.h"
#include "../effect/SAnimation.h"

#include <QApplication>
#include <QLabel>
#include <QTimer>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QException>
#include <QStackedWidget>
#include <QDebug>


STouchSystemEncoder::STouchSystemEncoder(QWidget *parent) : QDialog(parent)
{
    this->resize(::GlobalWindowSize);
    this->setStyleSheet("background-color: " + ::GlobalBackgroundColor + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_UnderMouse, false);
    this->setMouseTracking(true);
    this->setObjectName("STouchSystemEncoder");

    this->setUpWidget();
    this->setUpGUI();
    this->setConnect();
}

STouchSystemEncoder::~STouchSystemEncoder()
{
    if (this->animation != nullptr)
    {
        delete this->animation;
        this->animation = nullptr;
    }
    if (this->engine != nullptr)
    {
        delete this->engine;
        this->engine = nullptr;
    }
}

void STouchSystemEncoder::setUpWidget()
{
    /// Animation
    this->animation = new SAnimation;
    this->animation->setDefaultFileName(":images/halo_1.gif");
    this->animation->setPressedFileName(":images/halo_2.gif");

    stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(this->animation);
}

void STouchSystemEncoder::setUpGUI()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->stackedWidget);
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);

    this->setLayout(mainLayout);
}

void STouchSystemEncoder::setConnect()
{
    connect(this->animation, &SAnimation::released, this, &STouchSystemEncoder::slotInit);
}

void STouchSystemEncoder::setConnectNFC()
{
    connect(this->touchEncoder, &STouchEncoder::signalRun, this, &STouchSystemEncoder::slotRun);
    connect(this->touchEncoder, &STouchEncoder::signalStop, this, &STouchSystemEncoder::slotStop);
    connect(this->touchEncoder, &STouchEncoder::signalFinished, this, &STouchSystemEncoder::slotReset);
    connect(this->touchEncoder, &STouchEncoder::signalCancel, this, &STouchSystemEncoder::slotReset);
}

void STouchSystemEncoder::slotInit()
{
    this->animation->hide();

    /// Engine
    this->engine = new SEngine(BUS::GPIO);

    /// NFC
    this->touchEncoder = new STouchEncoder;
    this->touchEncoder->setAttribute(Qt::WA_DeleteOnClose);
    this->touchEncoder->setCloseable(true);
    this->touchEncoder->setTarget();

    this->setConnectNFC();

    this->stackedWidget->addWidget(this->touchEncoder);
    this->stackedWidget->setCurrentIndex(1);

    this->animation->show();
}

void STouchSystemEncoder::slotRun()
{
    if (!this->touchEncoder->direction().compare(tr("Unidirectional"), Qt::CaseInsensitive))
    {
        this->setDirectionForward();
    }
    else if (!this->touchEncoder->direction().compare(tr("Bidirectional"), Qt::CaseInsensitive))
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
}

void STouchSystemEncoder::slotStop()
{
    this->setDirectionNeutral();
}

void STouchSystemEncoder::slotReset()
{
    this->stackedWidget->setCurrentIndex(0);
    this->stackedWidget->removeWidget(this->touchEncoder);

    if (this->engine != nullptr)
    {
        delete this->engine;
        this->engine = nullptr;
    }
}

void STouchSystemEncoder::setDirectionForward()
{
    this->engine->forward(Engine::EMotor);
}

void STouchSystemEncoder::setDirectionBackward()
{
    this->engine->backward(Engine::EMotor);
}

void STouchSystemEncoder::setDirectionNeutral()
{
    this->engine->neutral(Engine::EMotor);
}

void STouchSystemEncoder::retranslateUI()
{
}

void STouchSystemEncoder::changeEvent(QEvent* event)
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
