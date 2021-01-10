#include "STouchRegistration.h"
#include "../build/SGlobal.h"
#include "../effect/SAnimation.h"
#include "../function/SMAC.h"
#include "../keyboard/STouchKeyboard.h"
#include "../util/dialog/STextDialog.h"

#include <QApplication>
#include <QSettings>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QTimer>
#include <QShowEvent>
#include <QNetworkInterface>
#include <QFile>
#include <QMovie>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>


STouchRegistration::STouchRegistration(QWidget *parent) : QDialog(parent)
{
    this->setObjectName("STouchRegistration");
    /// Window size for developing and emulating
    if (!::GlobalWindowSize.isEmpty())
    {
        this->resize(::GlobalWindowSize);
    }
    else
    {
        this->setWindowState(Qt::WindowFullScreen);
        this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }
    this->setStyleSheet("background-color: " + ::GlobalColorBase.name() + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

    this->setupWidget();
    this->setupLayout();
    this->setConnect();
}

STouchRegistration::~STouchRegistration()
{
    if (this->animation != nullptr)
    {
        delete this->animation;
        this->animation = nullptr;
    }
}

void STouchRegistration::setupWidget()
{
    this->animation = new SAnimation;
    this->animation->setDefaultFileName(":images/halo_1.gif");
    this->animation->setPressedFileName(":images/halo_2.gif");
}

void STouchRegistration::setupLayout()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->animation, 0, Qt::AlignCenter);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(mainLayout);
}

void STouchRegistration::setConnect()
{
    connect(this->animation, &SAnimation::released, this, &STouchRegistration::slotCheckSerialnumber);
}

void STouchRegistration::slotCheckSerialnumber()
{
    this->animation->hide();

    #ifdef S_DEBUG
    this->verification = true;
    emit this->done(0);
    return;
    #endif

    /// Read Settings
    this->readSettings();

    /// Keyboard
    if (!this->verification)
    {
        tryAgain:
        {
            STouchKeyboard touchKeyboard(this);
            touchKeyboard.setTitle(tr("Certification Number"));
            touchKeyboard.exec();
            if (touchKeyboard.isAccepted())
            {
                uint64_t id = touchKeyboard.getNumber().toLongLong();
                uint64_t mac = this->getMAC();

                /// Verification
                if (id == mac)
                {
                    this->sn = mac;
                    this->verification = true;
                }
                else
                {
                    this->verification = false;
                }

                if (!this->verification)
                {
//                    STextDialog dalog(this);
//                    touchDialog.setTitelText(tr("Registration"));
//                    touchDialog.setAcceptText(tr("Retry"));
//                    touchDialog.setDescriptionText(tr("Invalid certification"));
//                    touchDialog.exec();
//                    if (touchDialog.isAccepted())
//                    {
//                        goto tryAgain;
//                    }
                }
            }
            else
            {
                this->verification = false;
            }
        }
    }

    /// Write Settings
    if (this->verification)
    {
        this->writeSettings();
        emit this->done(0);

        return;
    }

    this->animation->show();
}

uint64_t STouchRegistration::getMAC()
{
    uint64_t mac;

    foreach (QNetworkInterface interface, QNetworkInterface::allInterfaces())
    {
        if (interface.hardwareAddress().size() == 17)
        {
            mac = interface.hardwareAddress().remove(":").toULongLong(new bool, 16);
            if (mac)
            {
                return mac;
            }
        }
    }

    return 0;
}

void STouchRegistration::writeSettings()
{
    QSettings settings(::GlobalConfigFileSettings, QSettings::IniFormat);
    settings.beginGroup("custom/register");
    settings.setValue("sn", QString::number(this->sn));
    settings.sync();
    settings.endGroup();
}

void STouchRegistration::readSettings()
{
    QSettings settings(::GlobalConfigFileSettings, QSettings::IniFormat);

    if (!QStringList(settings.allKeys().filter("custom/register", Qt::CaseInsensitive)).isEmpty())
    {
        settings.beginGroup("custom/register");
    }
    else if (!QStringList(settings.allKeys().filter("default/register", Qt::CaseInsensitive)).isEmpty())
    {
        settings.beginGroup("default/register");
    }
    this->sn = settings.value("sn").toLongLong();
    uint64_t mac = this->getMAC();

    if (this->sn == mac)
    {
        this->verification = true;
    }
    else if (this->sn != mac)
    {
        this->sn = 0;
        this->verification = false;
    }
    settings.endGroup();
}

bool STouchRegistration::isVerified()
{
    return this->verification;
}

void STouchRegistration::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);

    QPropertyAnimation *animationOpacity = new QPropertyAnimation(this, "windowOpacity", this);
    animationOpacity->setDuration(::GlobalAnimationTimeIn);
    animationOpacity->setStartValue(0);
    animationOpacity->setEndValue(1);
    animationOpacity->setEasingCurve(QEasingCurve::OutCubic);
    animationOpacity->start(QPropertyAnimation::DeleteWhenStopped);

    QTimer::singleShot(animationOpacity->duration(), this, &STouchRegistration::signalShowed);
}

void STouchRegistration::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);

//    QPropertyAnimation *animationOpacity = new QPropertyAnimation(this, "windowOpacity", this);
//    animationOpacity->setDuration(::GlobalAnimationSlowTimeOut);
//    animationOpacity->setStartValue(1);
//    animationOpacity->setEndValue(0);
//    animationOpacity->setEasingCurve(QEasingCurve::OutCurve);
//    animationOpacity->start(QPropertyAnimation::DeleteWhenStopped);

    emit this->signalClosed();
}

void STouchRegistration::retranslateUI()
{
}

void STouchRegistration::changeEvent(QEvent *event)
{
    switch (event->type())
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
