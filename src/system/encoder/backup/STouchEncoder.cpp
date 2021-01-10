#include "STouchEncoder.h"
#include "../build/SGlobal.h"
#include "../dialog/STouchDialog.h"
#include "../dialog/STouchDialogAccept.h"
#include "../keyboard/STouchKeyboard.h"

#include <QApplication>
#include <QLabel>
#include <QTimer>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QException>
#include <QStackedWidget>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QMutex>
#include <QDebug>


STouchEncoder::STouchEncoder(QWidget *parent) : QDialog(parent)
{
    this->resize(::GlobalWindowSize);
    this->setStyleSheet("background-color: " + ::GlobalBackgroundColor + ";");
    this->setWindowFlags(this->windowFlags() | Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->setWindowModality(Qt::WindowModal);
    this->setModal(true);
    this->activateWindow();
    this->raise();
    this->setObjectName("STouchEncoder");

    this->setupWidget();
    this->setupGUI();
    this->setConnect();
}

STouchEncoder::~STouchEncoder()
{
    if (this->threadEncoder != nullptr)
    {
        delete this->threadEncoder;
        this->threadEncoder = nullptr;
    }
    if (this->touchKeyboard != nullptr)
    {
        delete this->touchKeyboard;
        this->touchKeyboard = nullptr;
    }
}

void STouchEncoder::setupWidget()
{
    /// Encoder
    this->threadEncoder = new SThreadEncoder;
    this->threadEncoder->init();

    /// Label
    this->labelValue = new QLabel(QChar(0x2015), this);
    this->labelValue->setText(QChar(0x2015));
    this->labelValue->setAlignment(Qt::AlignCenter);
    this->labelValue->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    this->labelValue->setStyleSheet("QLabel { text-align: center; font: 150pt " + ::GlobalFont + "; color: " + ::GlobalTextColor + "; background: transparent; }");

    this->buttonProcess = new QPushButton(this);
    this->buttonProcess->setDefault(true);
    this->buttonProcess->setCheckable(true);
    this->buttonProcess->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
    this->buttonProcess->setStyleSheet(formStyleSheetString("init", "play_1"));

    this->buttonCorrect = new QPushButton(tr("Correct"), this);
    this->buttonCorrect->setCheckable(true);
    this->buttonCorrect->setAutoExclusive(true);
    this->buttonCorrect->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->buttonCorrect->setStyleSheet(formStyleSheetString("correct"));

    this->buttonCancel = new QPushButton(tr("Cancel"), this);
    this->buttonCancel->setCheckable(true);
    this->buttonCancel->setAutoExclusive(true);
    this->buttonCancel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->buttonCancel->setStyleSheet(formStyleSheetString("cancel"));
}

void STouchEncoder::setupGUI()
{
    QVBoxLayout *labelLayout = new QVBoxLayout;
    labelLayout->addWidget(this->labelValue);
    labelLayout->setAlignment(Qt::AlignCenter);

    QHBoxLayout *layoutLevel_21 = new QHBoxLayout;
    layoutLevel_21->addWidget(this->buttonProcess);
    QHBoxLayout *layoutLevel_22 = new QHBoxLayout;
    layoutLevel_22->addWidget(this->buttonCancel);
    layoutLevel_22->addStretch();
    layoutLevel_22->addWidget(this->buttonCorrect);
    QVBoxLayout *layoutLevel_2 = new QVBoxLayout;
    layoutLevel_2->addLayout(layoutLevel_21);
    layoutLevel_2->addLayout(layoutLevel_22);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(labelLayout, 9);
    mainLayout->addLayout(layoutLevel_2, 5);
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);

    this->setLayout(mainLayout);
}

void STouchEncoder::setConnect()
{
    /// Encoder
    connect(this->threadEncoder, &SThreadEncoder::signalConnect, this, &STouchEncoder::slotConnected);
    connect(this->threadEncoder, &SThreadEncoder::signalDataTransferred, this, &STouchEncoder::slotDataTransfer);
    /// Buttons
    connect(this->buttonProcess, &QPushButton::toggled, this, &STouchEncoder::slotProcess);
    connect(this->buttonCorrect, &QPushButton::released, this, &STouchEncoder::slotCorrect);
    connect(this->buttonCorrect, &QPushButton::released, this, &STouchEncoder::signalCorrect);
    connect(this->buttonCancel, &QPushButton::released, this, &STouchEncoder::slotCancel);
    connect(this->buttonCancel, &QPushButton::released, this, &STouchEncoder::signalCancel);
}

void STouchEncoder::slotProcess()
{
    switch (this->m_status)
    {
        case Status::Init:
        case Status::Run:
        {
            emit this->signalRun();

            /// Thread Restart
            this->threadEncoder->resume();
            /// Button Style
            this->buttonProcess->setStyleSheet(formStyleSheetString("run", "play_1"));
            /// Next Status
            this->m_status = Status::Pause;
        }
            break;

        case Status::Pause:
        {
            emit this->signalStop();

            /// Thread Stop
            this->threadEncoder->stop();
            /// Button Style
            this->buttonProcess->setStyleSheet(formStyleSheetString("pause", "pause_1"));
            /// Next Status
            this->m_status = Status::Run;
        }
            break;

        case Status::Finish:
        {
            emit this->signalFinished();

            /// Thread Stop
            //this->threadEncoder->abort();
            /// Button Style
            this->labelValue->setText(QChar(0x2015));
            this->buttonProcess->setStyleSheet(formStyleSheetString("init", "play_1"));
            /// Next Status
            this->m_status = Status::Run;
            /// Close
            if (this->m_closeable)
            {
                this->close();
                return;
            }
        }
            break;

        default:
            break;
    }
}

void STouchEncoder::slotCorrect()
{
    emit this->signalStop();

    /// Thread Stop
    this->threadEncoder->stop();

    if (this->m_status != Status::Init)
    {
        /// Button Style
        this->buttonProcess->setStyleSheet(formStyleSheetString("pause", "play_pause"));
        /// Next Status
        this->m_status = Status::Run;
    }

    /// Keybord
    this->touchKeyboard = new STouchKeyboard;
    this->touchKeyboard->setTitle(tr("Input Value"));
    this->touchKeyboard->setDescriptionText(tr("The input value must be\n\nin the range of %1 to %2").arg(this->minimumValue()).arg(this->maximumValue()));
    this->touchKeyboard->setRange(this->minimumValue(), this->maximumValue());
    this->touchKeyboard->setMaximumDigit(QString::number(this->maximumValue()).length());
    this->touchKeyboard->setDatatyp("int");
    this->touchKeyboard->exec();

    if (this->touchKeyboard != nullptr)
    {
        if (this->touchKeyboard->isAccepted())
        {
            this->m_target = this->touchKeyboard->getNumber().toInt();
        }

        delete this->touchKeyboard;
        this->touchKeyboard = nullptr;
    }
}

void STouchEncoder::slotCancel()
{
    emit this->signalStop();
    emit this->signalCancel();

    /// Thread Stop
    this->threadEncoder->stop();

    /// Button Style
    this->labelValue->setText(QChar(0x2015));
    this->buttonProcess->setStyleSheet(formStyleSheetString("init", "play_1"));
    /// Next Status
    this->m_status = Status::Init;
    /// Close
    if (this->m_closeable)
    {
        this->close();
    }
}

void STouchEncoder::slotConnected(const bool connection)
{
    /// Mutex
    QMutex mutex;
    mutex.lock();
    if (connection)
    {
        this->m_connection = true;
        return;
    }
    else
    {
        this->m_connection = false;
        this->m_status = Status::Pause;
        this->slotProcess();
    }
    mutex.unlock();

    /// Dialog
    STouchDialogAccept *touchDialogAccept = new STouchDialogAccept;
    touchDialogAccept->setAcceptText(tr("Retry"));
    touchDialogAccept->setDescriptionText(tr("Communication error"));
    touchDialogAccept->setMessageType(DialogAccept::Critical);
    touchDialogAccept->exec();

    if (!touchDialogAccept->isAccepted())
    {
        this->slotCancel();
    }

    if (touchDialogAccept != nullptr)
    {
        delete touchDialogAccept;
        touchDialogAccept = nullptr;
    }

    /// Keyboard
    if (this->touchKeyboard != nullptr)
    {
        if (this->touchKeyboard->isVisible())
        {
            this->touchKeyboard->close();
        }
    }
}

void STouchEncoder::slotDataTransfer(const int value)
{
    this->m_value = value;

    if (this->m_value != this->labelValue->text().toInt())
    {
        QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(this);
        this->labelValue->setText(tr("%1").arg(this->m_value));
        this->labelValue->setGraphicsEffect(effect);
        QPropertyAnimation *animationOpacity = new QPropertyAnimation(effect, "opacity", this);
        animationOpacity->setDuration(::GlobalAnimationTimeIn);
        animationOpacity->setStartValue(0.0);
        animationOpacity->setEndValue(1.0);
        animationOpacity->setEasingCurve(QEasingCurve::InQuart);
        animationOpacity->start(QPropertyAnimation::DeleteWhenStopped);
    }

    if (this->m_value == this->m_target)
    {
        emit this->signalStop();

        /// Thread Stop
        this->threadEncoder->stop();
        /// Button Style
        this->buttonProcess->setStyleSheet(formStyleSheetString("finish", "done"));
        /// Next Status
        this->m_status = Status::Finish;
    }
}

void STouchEncoder::setTarget()
{
    /// Keybord
    this->touchKeyboard = new STouchKeyboard;
    this->touchKeyboard->setTitle(tr("Input Value"));
    this->touchKeyboard->setDescriptionText(tr("The input value must be\n\nin the range of %1 to %2").arg(this->minimumValue()).arg(this->maximumValue()));
    this->touchKeyboard->setRange(this->minimumValue(), this->maximumValue());
    this->touchKeyboard->setMaximumDigit(QString::number(this->maximumValue()).length());
    this->touchKeyboard->setDatatyp("int");
    this->touchKeyboard->exec();

    if (this->touchKeyboard != nullptr)
    {
        if (this->touchKeyboard->isAccepted())
        {
            this->m_target = this->touchKeyboard->getNumber().toInt();
        }
        else
        {
            this->slotCancel();
        }

        delete this->touchKeyboard;
        this->touchKeyboard = nullptr;
    }
}

double STouchEncoder::getValue() const
{
    return this->m_value;
}

void STouchEncoder::setCloseable(const bool closeable)
{
    this->m_closeable = closeable;
}

void STouchEncoder::setCorrectButton(const bool hide)
{
    this->buttonCorrect->setEnabled(hide);
}

bool STouchEncoder::up()
{
    this->getDirection();

    if (this->m_up < this->m_down)
    {
        return true;
    }

    return false;
}

bool STouchEncoder::down()
{
    this->getDirection();

    if (this->m_up > this->m_down)
    {
        return true;
    }

    return false;
}

void STouchEncoder::getDirection()
{
    if (this->m_value < this->m_target)
    {
        this->m_up = this->m_target - this->m_value;
        this->m_down = this->m_value - this->minimumValue() + this->maximumValue() - this->m_target;
    }
    else if (this->m_value > this->m_target)
    {
        this->m_up = this->m_target - this->minimumValue() + this->maximumValue() - this->m_value;
        this->m_down = this->m_value - this->m_target;
    }
}

double STouchEncoder::minimumValue() const
{
    return this->threadEncoder->minimumValue();
}

double STouchEncoder::maximumValue() const
{
    return this->threadEncoder->maximumValue();
}


QString STouchEncoder::direction() const
{
    return this->threadEncoder->direction();
}

QString STouchEncoder::formStyleSheetString(const QString &style, const QString &icon)
{
    QString styleButton;

    if (!style.compare("init"))
    {
        styleButton =
        "\
            QPushButton { qproperty-icon: url(:/images/"+ icon +".svg); icon-size: 80px 80px; background-color: " + ::GlobalGrayColor + "; border: none; } \
        ";
    }
    else if (!style.compare("run"))
    {
        styleButton =
        "\
            QPushButton { qproperty-icon: url(:/images/"+ icon +".svg); icon-size: 80px 80px; background-color: rgb(0,130,255); border: none; } \
        ";
    }
    else if (!style.compare("pause"))
    {
        styleButton =
        "\
            QPushButton { qproperty-icon: url(:/images/"+ icon +".svg); icon-size: 80px 80px; background-color: rgb(255,130,130); border: none; } \
        ";
    }
    else if (!style.compare("finish"))
    {
        styleButton =
        "\
            QPushButton { qproperty-icon: url(:/images/"+ icon +".svg); icon-size: 80px 80px; background-color: rgb(130,255,130); border: none; }\
        ";
    }
    else if (!style.compare("cancel") || !style.compare("correct"))
    {
        styleButton =
        "\
            QPushButton          { font: 18pt " + ::GlobalFont + "; color: " + ::GlobalTextColor + "; background: transparent; border: none; } \
            QPushButton:pressed  { font: 18pt " + ::GlobalFont + "; color: " + ::GlobalBlueColor + "; background: transparent; border: none; } \
            QPushButton:disabled { font: 18pt " + ::GlobalFont + "; color: #151518; background: transparent; border: none; } \
        ";
    }
    else if (!style.compare("blue"))
    {
        styleButton =
        "\
            QPushButton         { font: 22pt; color: " + ::GlobalTextColor + "; background-color: " + ::GlobalBackgroundColor + "; border: none; border-radius: 100px; } \
            QPushButton:pressed { font: 22pt; color: " + ::GlobalTextColor + "; background-color: " + ::GlobalBlueColor + "; border: none; border-radius: 100px; } \
        ";
    }

    return styleButton;
}

void STouchEncoder::retranslateUI()
{
    this->buttonCorrect->setText(tr("Correct"));
    this->buttonCancel->setText(tr("Cancel"));
}

void STouchEncoder::changeEvent(QEvent* event)
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
