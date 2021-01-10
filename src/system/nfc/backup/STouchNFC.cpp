#include "STouchNFC.h"
#include "../build/SGlobal.h"
#include "../keyboard/STouchKeyboard.h"
#include "../dialog/STouchDialog.h"
#include "../dialog/STouchDialogAccept.h"

#include <QApplication>
#include <QSettings>
#include <QFileSystemWatcher>
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


STouchNFC::STouchNFC(QWidget *parent) : QDialog(parent)
{
    this->resize(::GlobalWindowSize);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setStyleSheet("background-color: " + ::GlobalBackgroundColor + ";");
    this->setWindowFlags(this->windowFlags() | Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->setWindowModality(Qt::WindowModal);
    this->setModal(true);
    this->activateWindow();
    this->raise();
    this->setObjectName("STouchNFC");

    this->setupWidget();
    this->setupGUI();
    this->setConnect();
    this->slotReadSettings();
}

STouchNFC::~STouchNFC()
{
    if (this->settings != nullptr)
    {
        delete this->settings;
        this->settings = nullptr;
    }
    if (this->threadNFC != nullptr)
    {
        delete this->threadNFC;
        this->threadNFC = nullptr;
    }
    if (this->touchKeyboard != nullptr)
    {
        delete this->touchKeyboard;
        this->touchKeyboard = nullptr;
    }
}

void STouchNFC::setupWidget()
{
    /// Watcher
    this->fileSystemWatcher = new QFileSystemWatcher(this);
    this->fileSystemWatcher->addPath(::GlobalSettingDir + ::GlobalSettingConfig);
    this->fileSystemWatcher->addPath(::GlobalSettingDir + ::GlobalSettingConfigSettings);

    /// Labels
    this->labelTitle = new QLabel(tr("Warehouse"), this);
    this->labelTitle->setAlignment(Qt::AlignCenter);
    this->labelTitle->setStyleSheet("QLabel { font: " + ::GlobalLabelTextFont + "; color: " + ::GlobalTextColor + "; background: transparent; }");
    this->labelTitle->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    this->labelValue = new QLabel(QChar(0x2015), this);
    this->labelValue->setText(QChar(0x2015));
    this->labelValue->setAlignment(Qt::AlignCenter);
    this->labelValue->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    this->labelValue->setStyleSheet("QLabel { text-align: center; font: 150pt " + ::GlobalFont + "; color: " + ::GlobalTextColor + "; background: transparent; }");

    /// Buttons
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

void STouchNFC::setupGUI()
{
    QHBoxLayout *titleLayout = new QHBoxLayout;
    titleLayout->addWidget(this->labelTitle);

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
    mainLayout->addLayout(titleLayout);
    mainLayout->addLayout(labelLayout, 9);
    mainLayout->addLayout(layoutLevel_2, 5);
    //mainLayout->setContentsMargins(0,0,0,0);
    //mainLayout->setSpacing(0);
    //mainLayout->setMargin(0);

    this->setLayout(mainLayout);
}

void STouchNFC::setConnect()
{
    /// Watcher
    connect(this->fileSystemWatcher, &QFileSystemWatcher::directoryChanged, this, &STouchNFC::slotReadSettings);
    connect(this->fileSystemWatcher, &QFileSystemWatcher::fileChanged, this, &STouchNFC::slotReadSettings);
    /// Buttons
    connect(this->buttonProcess, &QPushButton::toggled, this, &STouchNFC::slotProcess);
    connect(this->buttonCorrect, &QPushButton::released, this, &STouchNFC::slotCorrect);
    connect(this->buttonCorrect, &QPushButton::released, this, &STouchNFC::signalCorrect);
    connect(this->buttonCancel, &QPushButton::released, this, &STouchNFC::slotReset);
}

void STouchNFC::setButtonInit()
{
    /// Button Style
    this->buttonProcess->setStyleSheet(formStyleSheetString("init", "play_1"));
    /// Next Status
    this->m_status = Status::Init;
}

void STouchNFC::setButtonPause()
{
    /// Button Style
    this->buttonProcess->setStyleSheet(formStyleSheetString("pause", "pause_1"));
    /// Next Status
    this->m_status = Status::Pause;
}

void STouchNFC::setButtonRun()
{
    /// Button Style
    this->buttonProcess->setStyleSheet(formStyleSheetString("run", "play_1"));
    /// Next Status
    this->m_status = Status::Run;
}

void STouchNFC::slotProcess()
{
    switch (this->m_status)
    {
        case Status::Init:
        {
            this->initThreadNFC();

            if (this-setTarget(this->m_setTarget))
            {
                /// Button style / process
                this->setButtonRun();
            }
        }
            break;

        case Status::Run:
        {
            this->m_error = false;

            /// Thread Restart
            this->threadNFC->resume();
            if (this->threadNFC->communicationEstablished())
            {
                emit this->signalRun();
            }

            /// Button style / process
            this->setButtonPause();
        }
            break;

        case Status::Pause:
        {
            /// Physical output stop
            emit this->signalStop();
            /// Thread stop
            this->threadNFC->stop();
            /// Button style / process
            this->setButtonRun();
        }
            break;

        case Status::Finish:
        {
        }
            break;

        default:
            break;
    }
}

void STouchNFC::slotCorrect()
{
    switch (this->m_status)
    {
        case Status::Init:
        {
            this->slotProcess();
        }
            break;

        case Status::Run:
        case Status::Pause:
        case Status::Finish:
        {
            /// Physical output stop
            emit this->signalStop();
            /// Thread stop
            this->threadNFC->stop();
            /// Button style / process
            this->setButtonRun();

            /// Keybord
            this->touchKeyboard = new STouchKeyboard;
            this->touchKeyboard->setTitle(tr("Input Value"));
            this->touchKeyboard->setDescriptionText(tr("The input value must be\n\nin the range of %1 to %2").arg(this->minimumValue()).arg(this->maximumValue()), KeyboardDialog::Warning);
            this->touchKeyboard->setRange(this->minimumValue(), this->maximumValue());
            this->touchKeyboard->setMaximumDigit(QString::number(this->maximumValue()).length());
            this->touchKeyboard->setDatatyp("int");
            this->touchKeyboard->exec();

            if (this->touchKeyboard != nullptr)
            {
                if (this->touchKeyboard->isAccepted())
                {
                    this->m_done = false;
                    this->m_target = this->touchKeyboard->getNumber().toInt();
                    this->transferTarget();
                }

                delete this->touchKeyboard;
                this->touchKeyboard = nullptr;
            }
        }
            break;

        default:
            break;
    }
}

bool STouchNFC::setTarget(const bool target)
{
    if (!target)
    {
        return true;
    }

    bool accepted = false;

    if (this->touchKeyboard != nullptr)
    {
        delete this->touchKeyboard;
        this->touchKeyboard = nullptr;
    }

    /// Keybord
    this->touchKeyboard = new STouchKeyboard;
    this->touchKeyboard->setTitle(tr("Input Value"));
    this->touchKeyboard->setDescriptionText(tr("The input value must be\n\nin the range of %1 to %2").arg(this->minimumValue()).arg(this->maximumValue()), KeyboardDialog::Warning);
    this->touchKeyboard->setRange(this->minimumValue(), this->maximumValue());
    this->touchKeyboard->setMaximumDigit(QString::number(this->maximumValue()).length());
    this->touchKeyboard->setDatatyp("int");
    this->touchKeyboard->exec();

    if (this->touchKeyboard->isAccepted())
    {
        this->m_target = this->touchKeyboard->getNumber().toInt();
        this->transferTarget();

        accepted = true;
    }
    else
    {
        this->slotReset();

        accepted = false;
    }

    delete this->touchKeyboard;
    this->touchKeyboard = nullptr;

    return accepted;
}

void STouchNFC::initThreadNFC()
{
    /// Init
    this->threadNFC = new SThreadNFC;
    this->threadNFC->init();

    /// Connect
    connect(this->threadNFC, &SThreadNFC::signalConnect, this, &STouchNFC::slotConnected);
    connect(this->threadNFC, &SThreadNFC::signalDataTransferred, this, &STouchNFC::slotDataTransfer);

    this->m_done = false;
}

void STouchNFC::resetThreadNFC()
{
    if (this->threadNFC != nullptr)
    {
        /// Thread Stop
        this->threadNFC->stop();

        /// Disconnect
        disconnect(this->threadNFC, &SThreadNFC::signalConnect, this, &STouchNFC::slotConnected);
        disconnect(this->threadNFC, &SThreadNFC::signalDataTransferred, this, &STouchNFC::slotDataTransfer);

        /// Delete
        delete this->threadNFC;
        this->threadNFC = nullptr;
    }
}

void STouchNFC::slotReset()
{
    if (this->m_status != Status::Init)
    {
        /// Physical output stop
        emit this->signalStop();
        /// NFC
        this->resetThreadNFC();
        /// Button Style
        this->labelValue->setText(QChar(0x2015));
        /// Button style / process
        this->setButtonInit();
    }

    /// Close
    if (this->m_closeable)
    {
        this->close();
    }
}

void STouchNFC::slotConnected(const bool connection)
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

    if (!this->m_error)
    {
        this->m_error = true;

        /// Dialog
        STouchDialog *touchDialog = new STouchDialog;
        touchDialog->setDescriptionText(tr("Communication error\n\nCheck the communicationcable"));
        touchDialog->setMessageType(Dialog::Critical);
        touchDialog->setAttribute(Qt::WA_DeleteOnClose);
        touchDialog->show();
    }
}

void STouchNFC::slotDataTransfer(const int value)
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
        if (!this->m_done)
        {
            this->m_done = true;

            /// Physical output stop
            emit this->signalStop();
            /// Thread Stop
            this->threadNFC->stop();

            /// Dialog
            STouchDialogAccept *touchDialogAccept = new STouchDialogAccept;
            touchDialogAccept->setDescriptionText(QString::number(this->m_value));
            touchDialogAccept->setAcceptText(tr("Done"));
            touchDialogAccept->setCancelText(tr("Next"));
            touchDialogAccept->setFontSize("100pt");
            touchDialogAccept->setOpacity(0.95);
            //touchDialogAccept->setAttribute(Qt::WA_DeleteOnClose);
            touchDialogAccept->exec();

            if (touchDialogAccept->isAccepted())
            {
                this->slotReset();
            }
            else
            {
                this->slotCorrect();
            }

            delete touchDialogAccept;
            touchDialogAccept = nullptr;
        }
    }
}

void STouchNFC::setMode(const NFC mode, const bool target)
{
    this->m_mode = mode;
    this->m_setTarget = target;

    if (this->m_setTarget == false)
    {
        this->slotProcess();
    }
}

void STouchNFC::transferTarget()
{
    switch (this->m_mode)
    {
        case NFC::Write:
        {
            this->threadNFC->setMode(this->m_mode);
            this->threadNFC->write(this->m_target);
        }
            break;

        case NFC::Read:
        {
            this->threadNFC->setMode(this->m_mode);
        }
            break;

        default:
            break;
    }
}

void STouchNFC::setValue(const int value)
{
    this->m_value = value;
}

int STouchNFC::getValue() const
{
    return this->m_value;
}

void STouchNFC::setCloseable(const bool closeable)
{
    this->m_closeable = closeable;
}

void STouchNFC::setCorrectButton(const bool hide)
{
    this->buttonCorrect->setEnabled(hide);
}

bool STouchNFC::up()
{
    this->getDirection();

    if (this->m_up < this->m_down)
    {
        return true;
    }

    return false;
}

bool STouchNFC::down()
{
    this->getDirection();

    if (this->m_up > this->m_down)
    {
        return true;
    }

    return false;
}

void STouchNFC::getDirection()
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

bool STouchNFC::unidirectional() const
{
    return (this->direction() == 0);
}

bool STouchNFC::bidirectional() const
{
    return (this->direction() == 1);
}

int STouchNFC::minimumValue() const
{
    return this->m_minValue;
}

int STouchNFC::maximumValue() const
{
    return this->m_maxValue;
}

int STouchNFC::direction() const
{
    return this->m_direction;
}

void STouchNFC::slotReadSettings()
{
    this->settings = new QSettings(::GlobalSettingDir + ::GlobalSettingConfigSettings, QSettings::IniFormat);

    if (!QStringList(this->settings->allKeys().filter("custom/system/nfc", Qt::CaseInsensitive)).isEmpty())
    {
        this->settings->beginGroup("custom/system/nfc");
    }
    else if (!QStringList(this->settings->allKeys().filter("default/system/nfc", Qt::CaseInsensitive)).isEmpty())
    {
        this->settings->beginGroup("default/system/nfc");
    }

    this->m_minValue = this->settings->value("minValue", 1).toInt();
    this->m_maxValue = this->settings->value("maxValue", 32).toInt();
    this->m_direction = this->settings->value("direction", 0).toInt();

    this->settings->sync();
    this->settings->endGroup();

    if (this->settings != nullptr)
    {
        delete this->settings;
        this->settings = nullptr;
    }
}

QString STouchNFC::formStyleSheetString(const QString &style, const QString &icon)
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

void STouchNFC::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);
}

void STouchNFC::retranslateUI()
{
    this->labelTitle->setText(tr("Warehouse"));
    this->buttonCorrect->setText(tr("Correct"));
    this->buttonCancel->setText(tr("Cancel"));
}

void STouchNFC::changeEvent(QEvent* event)
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
