#include "STouchColorKeyboard.h"
#include "../build/SGlobal.h"
#include "../flickable/STouchFlickableList.h"
#include "../effect/SGraphicsGlowEffect.h"
#include "../effect/SColorGradientSquare.h"

#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFrame>
#include <QString>
#include <QChar>
#include <QPalette>
#include <QLinearGradient>
#include <QDebug>


STouchColorKeyboard::STouchColorKeyboard(QWidget *parent) : QDialog(parent)
{
    #ifdef QT_EMBEDDED
    QApplication::setOverrideCursor(Qt::BlankCursor);
    this->setWindowState(Qt::WindowFullScreen);
    #else
    this->resize(QSize(800,480));
    #endif
    this->setStyleSheet("background-color: " + ::GlobelBackgroundColor + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    this->setupWidget();
    this->setupGUI();
    this->setConnect();
}

STouchColorKeyboard::~STouchColorKeyboard()
{
    if (colorGradientSquare != nullptr)
    {
        delete colorGradientSquare;
        colorGradientSquare = nullptr;
    }
    if (touchFirstFlickable != nullptr)
    {
        delete touchFirstFlickable;
        touchFirstFlickable = nullptr;
    }
    if (touchSecondFlickable != nullptr)
    {
        delete touchSecondFlickable;
        touchSecondFlickable = nullptr;
    }
}

void STouchColorKeyboard::setupWidget()
{
    /// BUTTONS
    buttonCancel = new QPushButton(tr("Cancel"), this);
    buttonCancel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    buttonCancel->setStyleSheet(formStyleSheetString("button"));
    buttonCancel->setMinimumHeight(height()/8);
    buttonCancel->setCheckable(true);

    buttonAccept = new QPushButton(tr("Accept"), this);
    buttonAccept->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    buttonAccept->setStyleSheet(formStyleSheetString("button"));
    buttonAccept->setMinimumHeight(height()/8);
    buttonAccept->setCheckable(true);
    buttonAccept->setDisabled(true);

    /// FLICKABLES
    touchFirstFlickable = new STouchFlickableList;
    touchFirstFlickable->setWindowState(Qt::WindowFullScreen);
    touchFirstFlickable->setBackgroundColor(QColor(::GlobelBackgroundColor));
    touchFirstFlickable->setFontSize(20, true);
    touchFirstFlickable->setAlignment("center");
    touchFirstFlickable->setCheckable(true);
    touchFirstFlickable->enableAnimation(false);
    touchFirstFlickable->enableDrawLine(true, QColor(255,255,255,100));

    touchSecondFlickable = new STouchFlickableList;
    touchSecondFlickable->setWindowState(Qt::WindowFullScreen);
    touchSecondFlickable->setBackgroundColor(QColor(::GlobelBackgroundColor));
    touchSecondFlickable->setFontSize(20, true);
    touchSecondFlickable->setAlignment("center");
    touchSecondFlickable->setCheckable(true);
    touchSecondFlickable->enableAnimation(false);
    touchSecondFlickable->enableDrawLine(true, QColor(255,255,255,100));

    colorGradientSquare = new SColorGradientSquare;
    glow = new SGraphicsGlowEffect;
    glow->setBlurRadius(50);
    glow->setStrength(5);
    colorGradientSquare->setGraphicsEffect(glow);
}

void STouchColorKeyboard::setupGUI()
{
    QHBoxLayout *layout_0 = new QHBoxLayout;
    layout_0->addWidget(buttonCancel);
    layout_0->addWidget(buttonAccept);
    layout_0->setStretchFactor(buttonCancel, 1);
    layout_0->setStretchFactor(buttonAccept, 1);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(layout_0);
    mainLayout->addWidget(colorGradientSquare);
    mainLayout->setStretchFactor(layout_0, 1);
    mainLayout->setStretchFactor(colorGradientSquare, 2);
    mainLayout->setContentsMargins(0,height()/10,0,height()/24);

    setLayout(mainLayout);
}

void STouchColorKeyboard::setConnect()
{
    connect(buttonAccept, &QPushButton::pressed, this, &STouchColorKeyboard::slotButtonAcceptPressed);
    connect(buttonCancel, &QPushButton::pressed, this, &STouchColorKeyboard::slotButtonCancelPressed);
    //connect(colorGradientSquare, &SColorGradientSquare::colorSelected , colorGradientSquare, &SColorGradientSquare::selectedColorChanged);
    //connect(touchFirstFlickable, &STouchFlickableList::signalCurrentIndex, this, &STouchColorKeyboard::slotGetFirstNumber);
    //connect(touchSecondFlickable, &STouchFlickableList::signalCurrentIndex, this, &STouchColorKeyboard::slotGetSecondNumber);
}

void STouchColorKeyboard::slotGetSecondNumber(const int &index)
{

}

void STouchColorKeyboard::slotButtonAcceptPressed()
{
    emit signalNumbersChanged(getRGB());
    accepted = true;
    close();
}

void STouchColorKeyboard::slotButtonCancelPressed()
{
    accepted = false;
    close();
}

bool STouchColorKeyboard::isAccepted()
{
    return accepted;
}

QString STouchColorKeyboard::getRGB() const
{
    return "";
}

QString STouchColorKeyboard::formStyleSheetString(const QString &style)
{
    QString styleButton;

    if (!style.compare("button"))
    {
        styleButton =
        " \
            QPushButton:!pressed { font: 18pt Arial; color: " + ::GlobelTextColor + "; background-color: transparent; border: none; } \
            QPushButton:pressed  { font: 18pt Arial; color: " + ::GlobelTextColor + "; background-color: transparent; border: none; } \
            QPushButton:disabled { font: 18pt Arial; color: gray; background-color: transparent; border: none; } \
        ";
    }

    return styleButton;
}

void STouchColorKeyboard::retranslateUI()
{
    buttonCancel->setText(tr("Cancel"));
    buttonAccept->setText(tr("Accept"));
}

void STouchColorKeyboard::changeEvent(QEvent* event)
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

void STouchColorKeyboard::showEvent(QShowEvent *event)
{
    Q_UNUSED(event)
}

void STouchColorKeyboard::hideEvent(QHideEvent *event)
{
    Q_UNUSED(event)

    buttonAccept->setDisabled(true);
}
