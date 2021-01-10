#include "STouchSystemNFC.h"
#include "STouchNFC.h"
#include "../build/SGlobal.h"
#include "../device/SEngine.h"
#include "../keyboard/STouchKeyboard.h"
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


STouchSystemNFC::STouchSystemNFC(QWidget *parent) : QDialog(parent)
{
    #ifdef S_EMBEDDED
    QApplication::setOverrideCursor(Qt::BlankCursor);
    this->setWindowState(Qt::WindowFullScreen);
    #else
    this->resize(QSize(800,480));
    #endif
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
    if (this->animation != nullptr)
    {
        delete this->animation;
        this->animation = nullptr;
    }
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
    /// Animation
    this->animation = new SAnimation;
    /// NFC
    this->touchNFC = new STouchNFC;
}

void STouchSystemNFC::setUpGUI()
{
    this->stackedWidget = new QStackedWidget(this);
    this->stackedWidget->addWidget(this->animation);
    this->stackedWidget->addWidget(this->touchNFC);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->stackedWidget);
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);

    this->setLayout(mainLayout);
}

void STouchSystemNFC::setConnect()
{
    /// animation Button
    connect(this->animation, &SAnimation::released, this, &STouchSystemNFC::slotInit);
    /// NFC
    connect(this->touchNFC, &STouchNFC::signalRun, this, &STouchSystemNFC::slotRun);
    connect(this->touchNFC, &STouchNFC::signalCorrect, this, &STouchSystemNFC::slotCorrect);
    connect(this->touchNFC, &STouchNFC::signalStop, this, &STouchSystemNFC::slotStop);
    connect(this->touchNFC, &STouchNFC::signalFinished, this, &STouchSystemNFC::slotReset);
    connect(this->touchNFC, &STouchNFC::signalCancel, this, &STouchSystemNFC::slotReset);
}

void STouchSystemNFC::slotInit()
{
    this->animation->hide();

    /// Engine
    this->engine = new SEngine(BUS::IO);

    /// Keybord
    STouchKeyboard *touchKeyboard = new STouchKeyboard;
    touchKeyboard->setTitle(tr("Input Value"));
    touchKeyboard->setDescriptionText(tr("The input value must be\n\nin the range of %1 to %2").arg(this->touchNFC->minimumValue()).arg(this->touchNFC->maximumValue()));
    touchKeyboard->setRange(this->touchNFC->minimumValue(), this->touchNFC->maximumValue());
    touchKeyboard->setMaximumDigit(QString::number(this->touchNFC->maximumValue()).length());
    touchKeyboard->setDatatyp("int");
    touchKeyboard->exec();

    if (touchKeyboard->isAccepted())
    {
        this->stackedWidget->setCurrentIndex(1);

        this->touchNFC->setTarget(touchKeyboard->getNumber().toInt());

    }

    if (touchKeyboard != nullptr)
    {
        delete touchKeyboard;
        touchKeyboard = nullptr;
    }

    this->animation->show();
}

void STouchSystemNFC::slotCorrect()
{
    /// Keybord
    STouchKeyboard *touchKeyboard = new STouchKeyboard;
    touchKeyboard->setTitle(tr("Input Value"));
    touchKeyboard->setDescriptionText(tr("The input value must be\n\nin the range of %1 to %2").arg(this->touchNFC->minimumValue()).arg(this->touchNFC->maximumValue()));
    touchKeyboard->setRange(this->touchNFC->minimumValue(), this->touchNFC->maximumValue());
    touchKeyboard->setMaximumDigit(QString::number(this->touchNFC->maximumValue()).length());
    touchKeyboard->setDatatyp("int");
    touchKeyboard->exec();

    if (touchKeyboard->isAccepted())
    {
        this->stackedWidget->setCurrentIndex(1);

        this->touchNFC->setTarget(touchKeyboard->getNumber().toInt());

    }

    if (touchKeyboard != nullptr)
    {
        delete touchKeyboard;
        touchKeyboard = nullptr;
    }
}

void STouchSystemNFC::slotRun()
{
    if (!this->touchNFC->direction().compare("Unidirectional", Qt::CaseInsensitive))
    {
        this->setEngineForward();
    }
    else if (!this->touchNFC->direction().compare("Bidirectional", Qt::CaseInsensitive))
    {
        if (true)
        {
            this->setEngineForward();
        }
        else if (false)
        {
            this->setEngineBackward();
        }
    }
}

void STouchSystemNFC::slotStop()
{
    this->setEngineNeutral();
}

void STouchSystemNFC::slotReset()
{
    /// Stacked Widget
    this->stackedWidget->setCurrentIndex(0);

    /// Delete
    if (this->engine != nullptr)
    {
        delete this->engine;
        this->engine = nullptr;
    }
}

void STouchSystemNFC::setEngineForward()
{
    this->engine->forward(Engine::EMotor);
}

void STouchSystemNFC::setEngineBackward()
{
    this->engine->backward(Engine::EMotor);
}

void STouchSystemNFC::setEngineNeutral()
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
