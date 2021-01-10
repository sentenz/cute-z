#include "STouchScreenLock.h"

#include <Qt>
#include <QApplication>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSettings>
#include <QString>
#include <QTimer>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QShowEvent>
#include <QCloseEvent>
#include <QTouchEvent>
#include <QEvent>
#include <QGesture>
#include <QGestureEvent>
#include <QSwipeGesture>
#include <QDebug>

STouchScreenLock::STouchScreenLock(QWidget *parent) : QDialog(parent)
{
    #ifdef QT_EMBEDDED
    QApplication::setOverrideCursor(Qt::BlankCursor);
    this->setWindowState(Qt::WindowFullScreen);
    #else
    this->resize(QSize(800,480));
    #endif
    this->setStyleSheet("background-color: rgb(42,40,38);");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setWindowModality(Qt::ApplicationModal);
    this->setAttribute(Qt::WA_AcceptTouchEvents);
    this->setModal(true);
    this->setFocus();

    this->grabGesture(Qt::SwipeGesture);

    this->setUpWidget();
    this->setUpGUI();
    this->setConnect();
}

STouchScreenLock::~STouchScreenLock()
{
    if (settings != nullptr)
        delete settings;
}
void STouchScreenLock::setUpWidget()
{
    /// Buttons
    int diameter = 90;

    buttonZero = new QPushButton(tr("0"), this);
    buttonZero->setCheckable(true);
    buttonZero->setAutoExclusive(true);
    buttonZero->setFixedSize(QSize(diameter,diameter));
    buttonZero->setStyleSheet(formStyleSheetString("circle"));

    buttonOne = new QPushButton(tr("1"), this);
    buttonOne->setCheckable(true);
    buttonOne->setAutoExclusive(true);
    buttonOne->setFixedSize(QSize(diameter,diameter));
    buttonOne->setStyleSheet(formStyleSheetString("circle"));

    buttonTwo = new QPushButton(tr("2"), this);
    buttonTwo->setCheckable(true);
    buttonTwo->setAutoExclusive(true);
    buttonTwo->setFixedSize(QSize(diameter,diameter));
    buttonTwo->setStyleSheet(formStyleSheetString("circle"));

    buttonThree = new QPushButton(tr("3"), this);
    buttonThree->setCheckable(true);
    buttonThree->setAutoExclusive(true);
    buttonThree->setFixedSize(QSize(diameter,diameter));
    buttonThree->setStyleSheet(formStyleSheetString("circle"));

    buttonFour = new QPushButton(tr("4"), this);
    buttonFour->setCheckable(true);
    buttonFour->setAutoExclusive(true);
    buttonFour->setFixedSize(QSize(diameter,diameter));
    buttonFour->setStyleSheet(formStyleSheetString("circle"));

    buttonFive = new QPushButton(tr("5"), this);
    buttonFive->setCheckable(true);
    buttonFive->setAutoExclusive(true);
    buttonFive->setFixedSize(QSize(diameter,diameter));
    buttonFive->setStyleSheet(formStyleSheetString("circle"));

    buttonSix = new QPushButton(tr("6"), this);
    buttonSix->setCheckable(true);
    buttonSix->setAutoExclusive(true);
    buttonSix->setFixedSize(QSize(diameter,diameter));
    buttonSix->setStyleSheet(formStyleSheetString("circle"));

    buttonSeven = new QPushButton(tr("7"), this);
    buttonSeven->setCheckable(true);
    buttonSeven->setAutoExclusive(true);
    buttonSeven->setFixedSize(QSize(diameter,diameter));
    buttonSeven->setStyleSheet(formStyleSheetString("circle"));

    buttonEight = new QPushButton(tr("8"), this);
    buttonEight->setCheckable(true);
    buttonEight->setAutoExclusive(true);
    buttonEight->setFixedSize(QSize(diameter,diameter));
    buttonEight->setStyleSheet(formStyleSheetString("circle"));

    buttonNine = new QPushButton(tr("9"), this);
    buttonNine->setCheckable(true);
    buttonNine->setAutoExclusive(true);
    buttonNine->setFixedSize(QSize(diameter,diameter));
    buttonNine->setStyleSheet(formStyleSheetString("circle"));

    buttonCancel = new QPushButton(tr("Cancel"), this);
    buttonCancel->setCheckable(true);
    buttonCancel->setVisible(false);
    buttonCancel->setAutoExclusive(true);
    buttonCancel->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    buttonCancel->setStyleSheet(formStyleSheetString("rect"));

    buttonDelete = new QPushButton(tr("Delete"), this);
    buttonDelete->setCheckable(true);
    buttonDelete->setDisabled(true);
    buttonDelete->setVisible(false);
    buttonDelete->setAutoExclusive(true);
    buttonDelete->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    buttonDelete->setStyleSheet(formStyleSheetString("rect"));
}

void STouchScreenLock::setUpGUI()
{
    /// Labels
    labelTitle = new QLabel(tr("Enter  your  Code"), this);
    labelTitle->setAlignment(Qt::AlignCenter);
    labelTitle->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    labelTitle->setStyleSheet("QLabel { font: bold 20pt Arial; color: gainsboro; background: transparent; }");

    labelPassword = new QLabel(QString(digits, QChar(0x26AA)), this);
    labelPassword->setAlignment(Qt::AlignCenter);
    labelPassword->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    labelPassword->setFont(QFont("Dejavu Sans"));
    labelPassword->setStyleSheet("QLabel { font: bold 30pt; color: lightgray; background: transparent; }");

    /// Layout
    double space = 10.0;
    double f = 3.0;

    QHBoxLayout *keyboardLayout_1 = new QHBoxLayout;
    keyboardLayout_1->addStretch();
    keyboardLayout_1->addWidget(buttonOne);
    keyboardLayout_1->addSpacing(f*space);
    keyboardLayout_1->addWidget(buttonTwo);
    keyboardLayout_1->addSpacing(f*space);
    keyboardLayout_1->addWidget(buttonThree);
    keyboardLayout_1->addSpacing(f*space);
    keyboardLayout_1->addWidget(buttonFour);
    keyboardLayout_1->addStretch();

    QHBoxLayout *keyboardLayout_2 = new QHBoxLayout;
    keyboardLayout_2->addStretch();
    keyboardLayout_2->addWidget(buttonFive);
    keyboardLayout_2->addSpacing(f*space);
    keyboardLayout_2->addWidget(buttonSix);
    keyboardLayout_2->addSpacing(f*space);
    keyboardLayout_2->addWidget(buttonSeven);
    keyboardLayout_2->addSpacing(f*space);
    keyboardLayout_2->addWidget(buttonEight);
    keyboardLayout_2->addStretch();

    QHBoxLayout *keyboardLayout_3 = new QHBoxLayout;
    keyboardLayout_3->addWidget(buttonCancel);
    keyboardLayout_3->addStretch();
    keyboardLayout_3->addWidget(buttonZero);
    keyboardLayout_3->addSpacing(f*space);
    keyboardLayout_3->addWidget(buttonNine);
    keyboardLayout_3->addStretch();
    keyboardLayout_3->addWidget(buttonDelete);

    QVBoxLayout *keyboardLayout = new QVBoxLayout;
    keyboardLayout->addLayout(keyboardLayout_1);
    keyboardLayout->addSpacing(space);
    keyboardLayout->addLayout(keyboardLayout_2);
    keyboardLayout->addSpacing(space);
    keyboardLayout->addLayout(keyboardLayout_3);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(labelTitle);
    mainLayout->addWidget(labelPassword);
    mainLayout->addLayout(keyboardLayout);
    mainLayout->setStretch(0,0);
    mainLayout->setStretch(0,0);
    mainLayout->setStretch(1,5);
    mainLayout->setContentsMargins(width()/20,height()/24,width()/20,height()/24);

    setLayout(mainLayout);
}

void STouchScreenLock::setConnect()
{
    QList<QPushButton *> buttons = this->findChildren<QPushButton *>();
    for (int i = 0; i < buttons.size(); ++i)
    {
        connect(buttons.at(i), &QPushButton::pressed, this, &STouchScreenLock::sloButtonEvent);
    }
}

void STouchScreenLock::sloButtonEvent()
{
    ///
    /// \brief pb: casting which butten is pressed
    ///
    QPushButton *pb = qobject_cast<QPushButton *>(sender());
    if(pb)
    {
        /// cancel characters
        if (!pb->text().compare(tr("Cancel")))
        {
            this->close();
        }
        /// delete characters
        else if (!pb->text().compare(tr("Delete")))
        {
             password.remove(password.length()-1, 1);
        }
        /// add characters
        else
        {
            password.push_back(pb->text());
        }

        if(password.isEmpty())
        {
            buttonDelete->setDisabled(true);
        }
        else
        {
            buttonDelete->setDisabled(false);
        }
    }

    ///
    /// \brief labelPassword: fill up dots
    ///
    labelPassword->setText(QString(password.length(), QChar(0x26AB)).append(QString(digits - password.length(), QChar(0x26AA))));

    ///
    /// \brief check code acception
    ///
    if (password.length() == digits)
    {
        buttonDelete->setDisabled(true);

        QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(this);
        labelPassword->setGraphicsEffect(effect);
        QPropertyAnimation *animation = new QPropertyAnimation(effect, "opacity");
        animation->setDuration(500);
        animation->setStartValue(1);
        animation->setEndValue(0);
        animation->setEasingCurve(QEasingCurve::OutBack);
        animation->start(QPropertyAnimation::DeleteWhenStopped);

        connect(animation, &QPropertyAnimation::finished, this, &STouchScreenLock::slotCheckCode);
    }
    else if(password.length() > digits)
    {
        labelPassword->setText(QString(digits, QChar(0x26AA)));
        password.clear();
    }
}

void STouchScreenLock::slotCheckCode()
{    
    if (!password.compare(code))
    {
        acces = true;

        code.clear();

        this->close();
    }
    else
    {
        acces = false;
    }

    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(this);
    labelPassword->setGraphicsEffect(effect);
    QPropertyAnimation *animation = new QPropertyAnimation(effect, "opacity");
    animation->setDuration(200);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->setEasingCurve(QEasingCurve::InBack);
    animation->start(QPropertyAnimation::DeleteWhenStopped);

    labelPassword->setText(QString(digits, QChar(0x26AA)));
    password.clear();
}

void STouchScreenLock::setUser(const QString &user)
{
    this->user = user;

    if (!user.compare("master"))
    {
        this->setDigits(8);
        labelTitle->setText(tr("Enter  your  Master  Code"));
        labelPassword->setText(QString(digits, QChar(0x26AA)));
    }

    update();
}

void STouchScreenLock::setDigits(const int &digits)
{
    this->digits = digits;
    update();
}
bool STouchScreenLock::isAccepted()
{
    return acces;
}

void STouchScreenLock::enableButtons(const bool on)
{
    buttonCancel->setVisible(on);
    buttonDelete->setVisible(on);
}

void STouchScreenLock::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
}

void STouchScreenLock::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);

    #ifdef __linux__
    settings = new QSettings(QString("/media/pi/sentenz").append("/.config/sunipisettings.ini"), QSettings::IniFormat);
    #else
    settings = new QSettings(qApp->applicationDirPath().append("/config/sunipisettings.ini"), QSettings::IniFormat);
    #endif

    if (!user.compare("default"))
    {
        if (settings->contains("custom/passcode/code"))
        {
            settings->beginGroup("custom/passcode");
        }
        else
        {
            settings->beginGroup("default/passcode");
        }

        if (settings->value("code").toString().isEmpty())
        {
            acces = true;
            this->hide();
        }
    }
    else if (!user.compare("master"))
    {
        settings->beginGroup("master/passcode");
    }
    code = settings->value("code").toString();
    settings->endGroup();

    delete settings;
    settings = nullptr;
}

QString STouchScreenLock::formStyleSheetString(const QString &style)
{
    QString styleButton;

    if (!style.compare("circle"))
    {
        styleButton =
        "\
            QPushButton:!pressed { font: 25pt Arial; color: gainsboro; background: transparent; border: 2px solid gainsboro; border-radius: 45px; } \
            QPushButton:pressed  { font: 25pt Arial; color: gainsboro; background-color: gray; border: none; border-radius: 45px; } \
        ";
    }
    else if (!style.compare("rect"))
    {
        styleButton =
        "\
            QPushButton:!pressed { font: 18pt Arial; color: gainsboro; background: transparent; border: none; } \
            QPushButton:pressed  { font: 18pt Arial; color: gainsboro; background: transparent; border: none; } \
            QPushButton:disabled { font: 18pt Arial; color: #454545; background: transparent; border: none; } \
        ";
    }

    return styleButton;
}

void STouchScreenLock::retranslateUI()
{
    if (!user.compare("default"))
    {
        labelTitle->setText(tr("Enter  your  Code"));
    }
    else if (!user.compare("master"))
    {
        labelTitle->setText(tr("Enter  your  Master  Code"));
    }

    buttonCancel->setText(tr("Cancel"));
    buttonDelete->setText(tr("Delete"));
}

void STouchScreenLock::changeEvent(QEvent* event)
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

bool STouchScreenLock::event(QEvent *event)
{
    QTouchEvent *touchEvent = static_cast<QTouchEvent *>(event);
    Q_UNUSED(touchEvent);

    if (event->type() == QEvent::Gesture)
    {
        return gestureEvent(static_cast<QGestureEvent*>(event));
    }

    return QWidget::event(event);
}

bool STouchScreenLock::gestureEvent(QGestureEvent *event)
{
    if (QGesture *swipe = event->gesture(Qt::SwipeGesture))
    {
        swipeTriggered(static_cast<QSwipeGesture *>(swipe));
    }
    return true;
}

void STouchScreenLock::swipeTriggered(QSwipeGesture *gesture)
{
    if (gesture->state() == Qt::GestureFinished)
    {
        if (gesture->horizontalDirection() == QSwipeGesture::Left)
        {
            qDebug() << "WHAAAAAAAAAAAAAAAAAAAAAAAAT";
        }
        update();
    }
}
