#include "STouchScreenlock.h"
#include "../util/dialog/STouchDialogTimer.h"
#include "../widget/button/SPushButton.h"
#include "../widget/label/SLabel.h"

#include <Qt>
#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSettings>
#include <QString>
#include <QTimer>
#include <QPropertyAnimation>
#include <QShowEvent>
#include <QCloseEvent>
#include <QTouchEvent>
#include <QLine>
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>


STouchScreenlock::STouchScreenlock(QWidget *parent) : QDialog(parent)
{
    // Window size for developing and emulating
    if (!::GlobalWindowSize.isEmpty())
    {
        this->resize(::GlobalWindowSize);
    }
    else
    {
        this->setWindowState(Qt::WindowFullScreen);
        this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->setWindowFlags(this->windowFlags() | Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_AcceptTouchEvents);
    this->setWindowModality(Qt::ApplicationModal);
    this->setModal(true);
    this->activateWindow();
    this->raise();
    this->setFocus();

    this->setupWidget();
    this->setupLayout();
    this->setConnect();
    this->restyleUI();
}

STouchScreenlock::~STouchScreenlock()
{
    if (this->settings != nullptr)
    {
        delete this->settings;
        this->settings = nullptr;
    }
}

void STouchScreenlock::setupWidget()
{
    // Labels
    this->labelTitle = new SLabel(tr("Enter your User Code"), this);
    this->labelTitle->setAlignment(Qt::AlignCenter);
    this->labelTitle->setTheme(SLabel::Theme::Text);

    this->labelPassword = new SLabel(QString(this->m_digits, QChar(0x25FB)).split("", QString::SkipEmptyParts).join(QChar(0x2001)), this);
    this->labelPassword->setAlignment(Qt::AlignCenter);
    this->labelPassword->setTheme(SLabel::Theme::Text);
    this->labelPassword->fontSize(20);

    // BUTTON
    this->buttonZero = new SPushButton(tr("0"), this);
    this->buttonOne = new SPushButton(tr("1"), this);
    this->buttonTwo = new SPushButton(tr("2"), this);
    this->buttonThree = new SPushButton(tr("3"), this);
    this->buttonFour = new SPushButton(tr("4"), this);
    this->buttonFive = new SPushButton(tr("5"), this);
    this->buttonSix = new SPushButton(tr("6"), this);
    this->buttonSeven = new SPushButton(tr("7"), this);
    this->buttonEight = new SPushButton(tr("8"), this);
    this->buttonNine = new SPushButton(tr("9"), this);

    this->buttonCancel = new SPushButton(QChar(0x292B), this);
    this->buttonCancel->setVisible(false);
    this->buttonCancel->setObjectName("cancel");
    this->buttonDelete = new SPushButton(QChar(0x2770), this);
    this->buttonDelete->setDisabled(true);
    this->buttonDelete->setVisible(false);
    this->buttonDelete->setObjectName("delete");

    QList<SPushButton *> buttons = this->findChildren<SPushButton *>();
    for (int i = 0; i < buttons.size(); ++i)
    {
        buttons.at(i)->setRippleStyle(Material::CenteredRipple);
        buttons.at(i)->setFontSize(28);
        buttons.at(i)->setUseThemeColors(false);
        buttons.at(i)->setForegroundColor(this->m_colorText);
    }
}

void STouchScreenlock::setupLayout()
{
    QHBoxLayout *keyboardLayout_1 = new QHBoxLayout;
    keyboardLayout_1->addWidget(this->buttonOne);
    keyboardLayout_1->addWidget(this->buttonTwo);
    keyboardLayout_1->addWidget(this->buttonThree);

    QHBoxLayout *keyboardLayout_2 = new QHBoxLayout;
    keyboardLayout_2->addWidget(this->buttonFour);
    keyboardLayout_2->addWidget(this->buttonFive);
    keyboardLayout_2->addWidget(this->buttonSix);

    QHBoxLayout *keyboardLayout_3 = new QHBoxLayout;
    keyboardLayout_3->addWidget(this->buttonSeven);
    keyboardLayout_3->addWidget(this->buttonEight);
    keyboardLayout_3->addWidget(this->buttonNine);

    QHBoxLayout *keyboardLayout_4 = new QHBoxLayout;
    keyboardLayout_4->addWidget(this->buttonCancel);
    keyboardLayout_4->addWidget(this->buttonZero);
    keyboardLayout_4->addWidget(this->buttonDelete);

    int t_horizontalSize = ::GlobalWindowSize.height() < ::GlobalWindowSize.width() ? ::GlobalWindowSize.height()*0.225 : ::GlobalWindowSize.width()*0.0417;

    QVBoxLayout *keyboardLayout = new QVBoxLayout;
    keyboardLayout->addLayout(keyboardLayout_1);
    keyboardLayout->addLayout(keyboardLayout_2);
    keyboardLayout->addLayout(keyboardLayout_3);
    keyboardLayout->addLayout(keyboardLayout_4);
    keyboardLayout->setContentsMargins(t_horizontalSize, 0, t_horizontalSize, 0);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->labelPassword, 2);
    mainLayout->addWidget(this->labelTitle, 2);
    mainLayout->addLayout(keyboardLayout, 5);
    mainLayout->setContentsMargins(0, 0, 0, 10);

    this->setLayout(mainLayout);
}

void STouchScreenlock::setConnect()
{
    QList<SPushButton *> buttons = this->findChildren<SPushButton *>();
    for (int i = 0; i < buttons.size(); ++i)
    {
        connect(buttons.at(i), &SPushButton::released, this, &STouchScreenlock::slotButtonEvent);
    }
}

void STouchScreenlock::slotButtonEvent()
{
    ///
    /// \brief pb: casting which butten is pressed
    ///
    SPushButton *pb = qobject_cast<SPushButton *>(sender());
    if (pb)
    {
        /// cancel characters
        if (!pb->text().compare(QChar(0x292B)))
        {
            this->slotClose(true);
        }
        /// delete characters
        else if (!pb->text().compare(QChar(0x2770)))
        {
             this->m_password.remove(this->m_password.length() - 1, 1);

             if (this->m_password.isEmpty())
             {
                 this->buttonDelete->setDisabled(true);
             }
        }
        /// add characters
        else
        {
            if (this->m_password.length() < this->m_digits)
            {
                this->m_password.push_back(pb->text());

                ///
                /// \brief check code acception
                ///
                if (this->m_password.length() == this->m_digits)
                {
                    this->buttonDelete->setDisabled(true);
                    this->slotCheckCode();
                }
                else
                {
                    if (!this->m_password.isEmpty())
                    {
                        this->buttonDelete->setDisabled(false);
                    }
                }
            }
        }
    }

    ///
    /// \brief labelPassword: fill up the circles with dots
    ///
    this->labelPassword->setText(QString(this->m_password.length(), QChar(0x25FC)).append(QString(this->m_digits - this->m_password.length(), QChar(0x25FB))).split("", QString::SkipEmptyParts).join(QChar(0x2001)));
}

void STouchScreenlock::slotCheckCode()
{
    bool verification = false;

    switch (this->m_role)
    {
    case Role::User:
        verification = !this->m_password.compare(this->m_userCode) ? true : false;
        break;

    case Role::Operator:
        verification = !this->m_password.compare(this->m_operatorCode) ? true : false;
        break;

    case Role::Admin:
        verification = !this->m_password.compare(this->m_adminCode) ? true : false;
        break;

    default:
        break;
    }

    if (verification)
    {
        this->m_access = true;
        this->m_userCode.clear();
        this->m_operatorCode.clear();
        this->m_adminCode.clear();
        this->m_attempt = 0;
        QTimer::singleShot(250, this, SLOT(slotClose()));
    }
    else
    {
        this->m_access = false;

        if (++this->m_attempt == 3)
        {
            QTimer::singleShot(250, this, [this] {
                this->m_attempt = 0;
            });

            STouchDialogTimer *touchDialogTimer = new STouchDialogTimer(this);
            touchDialogTimer->setAttribute(Qt::WA_DeleteOnClose);
            touchDialogTimer->setTime(30);
            QTimer::singleShot(250, touchDialogTimer, &STouchDialogTimer::show);
        }
    }

    this->labelAnimation();
}

void STouchScreenlock::labelAnimation()
{
    if (!this->m_access)
    {
        QPropertyAnimation *animation = new QPropertyAnimation(this->labelPassword, "pos", this);
        animation->setDuration(50);
        animation->setStartValue(QPointF(-40, 0));
        animation->setEndValue(QPointF(40, 0));
        animation->setLoopCount(5);
        animation->setEasingCurve(QEasingCurve::CosineCurve);
        animation->start(QPropertyAnimation::DeleteWhenStopped);
    }

    QTimer::singleShot(250, this, [this] {
        this->m_password.clear();
        this->labelPassword->setText(QString(this->m_digits, QChar(0x25FB)).split("", QString::SkipEmptyParts).join(QChar(0x2001)));
    });
}

void STouchScreenlock::setRole(const Role &role)
{
    this->m_role = role;

    switch (this->m_role)
    {
    case Role::User:
        this->m_digits = 4;
        this->labelTitle->setText(tr("Enter your User Code"));
        break;

    case Role::Operator:
        this->m_digits = 6;
        this->labelTitle->setText(tr("Enter your Operator Code"));
        break;

    case Role::Admin:
        this->m_digits = 8;
        this->labelTitle->setText(tr("Enter your Admin Code"));
        break;

    default:
        break;
    }

    this->labelPassword->setText(QString(this->m_digits, QChar(0x25FB)).split("", QString::SkipEmptyParts).join(QChar(0x2001)));
    update();
}

void STouchScreenlock::setDigits(const int &digits)
{
    this->m_digits = digits;
    update();
}

bool STouchScreenlock::isAccepted() const
{
    return this->m_access;
}

void STouchScreenlock::enableSymbols(const bool visible, const bool enable)
{
    this->buttonCancel->setVisible(visible);
    this->buttonCancel->setEnabled(enable);
    this->buttonDelete->setVisible(visible);
}

void STouchScreenlock::init()
{
    this->m_access = false;
    this->m_attempt = 0;
    this->m_password.clear();
    this->labelPassword->setText(QString(this->m_digits, QChar(0x25FB)).split("", QString::SkipEmptyParts).join(QChar(0x2001)));
}

void STouchScreenlock::showEvent(QShowEvent * event)
{
    Q_UNUSED(event);

    /// Window size for developing and emulating
    if (::GlobalWindowSize.isEmpty())
    {
        this->setWindowState(Qt::WindowFullScreen);
        this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }

    this->init();

    /// QSettings
    ///
    this->settings = new QSettings(::GlobalConfigFileSettings, QSettings::IniFormat);
    if (!QStringList(this->settings->allKeys().filter("custom/code", Qt::CaseInsensitive)).isEmpty())
    {
        this->settings->beginGroup("custom/code");
    }
    else if (!QStringList(this->settings->allKeys().filter("default/code", Qt::CaseInsensitive)).isEmpty())
    {
        this->settings->beginGroup("default/code");
    }
    this->m_userCode = this->settings->value("usercode").toString();
    this->m_operatorCode = this->settings->value("operatorcode").toString();
    this->settings->endGroup();
    this->settings->beginGroup("admin/code");
    this->m_adminCode = this->settings->value("admincode").toString();
    this->settings->endGroup();
    if (this->settings != nullptr)
    {
        delete this->settings;
        this->settings = nullptr;
    }

    /// Close
    switch (this->m_role)
    {
    case Role::User:
        if (this->m_userCode.isEmpty())
        {
            this->m_access = true;
            this->slotClose(false);
            return;
        }
        break;

    case Role::Operator:
        if (this->m_operatorCode.isEmpty())
        {
            this->m_access = true;
            this->slotClose(false);
            return;
        }
        break;

    case Role::Admin:
        if (this->m_adminCode.isEmpty())
        {
            this->m_access = true;
            this->slotClose(false);
            return;
        }
        break;

    case Role::Appropriate:
        if (!this->m_operatorCode.isEmpty())
        {
            this->setRole(Role::Operator);
        }
        else if (!this->m_userCode.isEmpty())
        {
            this->setRole(Role::User);
        }

        if (this->m_userCode.isEmpty() && this->m_operatorCode.isEmpty())
        {
            this->m_access = true;
            this->slotClose(false);
            return;
        }
        break;

    default:
        break;
    }

    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity", this);
    animation->setDuration(::GlobalAnimationFastTimeOut);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->setEasingCurve(QEasingCurve::OutExpo);
    animation->start(QPropertyAnimation::DeleteWhenStopped);

    emit this->finished(0);
}

void STouchScreenlock::slotClose(const bool animate)
{
    if (animate)
    {
        QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity", this);
        animation->setDuration(::GlobalAnimationFastTimeOut);
        animation->setStartValue(1);
        animation->setEndValue(0);
        animation->setEasingCurve(QEasingCurve::InCubic);
        animation->start(QPropertyAnimation::DeleteWhenStopped);

        QTimer::singleShot(::GlobalAnimationFastTimeOut, this, SLOT(close()));
    }
    else
    {
        QTimer::singleShot(0, this, SLOT(close()));
    }
}

void STouchScreenlock::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);

    if (this->m_access)
    {
        emit this->accepted();
    }
}

void
STouchScreenlock::retranslateUI()
{
    switch (this->m_role)
    {
    case Role::User:
        this->labelTitle->setText(tr("Enter your User Code"));
        break;

    case Role::Operator:
        this->labelTitle->setText(tr("Enter your Operator Code"));
        break;

    case Role::Admin:
        this->labelTitle->setText(tr("Enter your Admin Code"));
        break;

    default:
        break;
    }
}

void
STouchScreenlock::restyleUI()
{
    if (this->m_colorBase != ::GlobalColorCustomBase)
    {
        this->m_colorBase = ::GlobalColorCustomBase;
        this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    }
    if (this->m_colorContrast != ::GlobalColorCustomContrast)
    {
        this->m_colorContrast = ::GlobalColorCustomContrast;
    }
    if (this->m_colorHighlight != ::GlobalColorCustomHighlight)
    {
        this->m_colorHighlight = ::GlobalColorCustomHighlight;
    }
    if (this->m_colorText != ::GlobalColorCustomText)
    {
        this->m_colorText = ::GlobalColorCustomText;
    }
}

void
STouchScreenlock::changeEvent(QEvent * event)
{
    switch (event->type())
    {
    case QEvent::LanguageChange:
        this->retranslateUI();
        break;

    case QEvent::StyleChange:
        this->restyleUI();
        break;

    case QEvent::LocaleChange:
        break;

    default:
        break;
    }

    QWidget::changeEvent(event);
}
