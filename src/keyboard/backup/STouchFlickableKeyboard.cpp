#include "STouchFlickableKeyboard.h"
#include "../build/SGlobal.h"
#include "../flickable/STouchFlickableList.h"
#include "../effect/SGraphicsGlowEffect.h"

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


STouchFlickableKeyboard::STouchFlickableKeyboard(QWidget *parent) : QDialog(parent)
{
    #ifdef QT_EMBEDDED
    QApplication::setOverrideCursor(Qt::BlankCursor);
    this->setWindowState(Qt::WindowFullScreen);
    #else
    this->resize(QSize(800,480));
    #endif
    this->setStyleSheet("background-color: " + ::GlobelBackgroundColor + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    this->setupGUI();
    this->setConnect();
}

STouchFlickableKeyboard::~STouchFlickableKeyboard()
{
    if (touchFirstFlickable != nullptr)
        delete touchFirstFlickable;
    if (touchSecondFlickable != nullptr)
        delete touchSecondFlickable;
}

void STouchFlickableKeyboard::setupGUI()
{
    /// Labels
    labelTitle1 = new QLabel(this);
    labelTitle1->setAlignment(Qt::AlignCenter);
    labelTitle1->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    labelTitle1->setStyleSheet("QLabel { font: bold 20pt Arial; color: " + ::GlobelTextColor + "; background: transparent; }");

    labelTitle2 = new QLabel(this);
    labelTitle2->setAlignment(Qt::AlignCenter);
    labelTitle2->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    labelTitle2->setStyleSheet("QLabel { font: bold 20pt Arial; color: " + ::GlobelTextColor + "; background: transparent; }");

    labelNumbers = new QLabel("00.00", this);
    labelNumbers->setAlignment(Qt::AlignCenter);
    labelNumbers->setStyleSheet("QLabel { font: 36pt Arial; color: lightgray; background: transparent; }");


    /// FLICKABLE
    touchFirstFlickable = new STouchFlickableList;
    touchFirstFlickable->setWindowState(Qt::WindowFullScreen);
    touchFirstFlickable->setBackgroundColor(QColor(::GlobelBackgroundColor));
    touchFirstFlickable->setFontSize(20, true);
    touchFirstFlickable->setAlignment("center");
    touchFirstFlickable->setCheckable(true);
    touchFirstFlickable->enableAnimation(false);
    touchFirstFlickable->enableDrawLine(true, QColor(255,255,255,100));
    for (int i = 0; i <= 99; ++i)
    {
        if (i < 10)
            touchFirstFlickable->setText(QString::number(i).prepend('0'));
        else
            touchFirstFlickable->setText(QString::number(i));
    }

    touchSecondFlickable = new STouchFlickableList;
    touchSecondFlickable->setWindowState(Qt::WindowFullScreen);
    touchSecondFlickable->setBackgroundColor(QColor(::GlobelBackgroundColor));
    touchSecondFlickable->setFontSize(20, true);
    touchSecondFlickable->setAlignment("center");
    touchSecondFlickable->setCheckable(true);
    touchSecondFlickable->enableAnimation(false);
    touchSecondFlickable->enableDrawLine(true, QColor(255,255,255,100));
    for (int i = 0; i <= 99; ++i)
    {
        if (i < 10)
            touchSecondFlickable->setText(QString::number(i).prepend('0'));
        else
            touchSecondFlickable->setText(QString::number(i));
    }

    /*
    QPalette palette;
    QLinearGradient gradient(touchSecondFlickable->rect().topLeft(), touchSecondFlickable->rect().bottomLeft());
    gradient.setColorAt(0, Qt::blue);
    gradient.setColorAt(0.2, Qt::green);
    gradient.setColorAt(0.4, Qt::red);
    gradient.setColorAt(0.6, Qt::yellow);
    gradient.setColorAt(1, Qt::cyan);

    palette.setBrush(QPalette::Foreground, QBrush(gradient));

    touchSecondFlickable->setPalette(palette);
    */


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


    /// Layout
    QFrame *line = new QFrame(this);
    line->setFrameShape(QFrame::HLine);
    line->setLineWidth(2);
    line->setStyleSheet("QFrame { border: 5px solid " + ::GlobelTextColor + "; }");
    SGraphicsGlowEffect *glow = new SGraphicsGlowEffect;
    glow->setBlurRadius(2);
    glow->setStrength(1);
    line->setGraphicsEffect(glow);

    QHBoxLayout *layout_0 = new QHBoxLayout;
    layout_0->addWidget(buttonCancel);
    layout_0->addWidget(labelNumbers);
    layout_0->addWidget(buttonAccept);
    layout_0->setStretchFactor(buttonCancel, 1);
    layout_0->setStretchFactor(labelNumbers, 2);
    layout_0->setStretchFactor(buttonAccept, 1);

    QVBoxLayout *layout_1 = new QVBoxLayout;
    layout_1->addLayout(layout_0);
    layout_1->addSpacing(height()/20);
    layout_1->addWidget(line);
    layout_1->addSpacing(height()/20);

    QVBoxLayout *layout_21 = new QVBoxLayout;
    layout_21->addWidget(labelTitle1);
    layout_21->addWidget(touchFirstFlickable);

    QVBoxLayout *layout_22 = new QVBoxLayout;
    layout_22->addWidget(labelTitle2);
    layout_22->addWidget(touchSecondFlickable);

    QHBoxLayout *layout_2 = new QHBoxLayout;
    layout_2->addSpacing(width()/4);
    layout_2->addLayout(layout_21);
    layout_2->addSpacing(width()/40);
    layout_2->addLayout(layout_22);
    layout_2->addSpacing(width()/4);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(layout_1);
    mainLayout->addLayout(layout_2);
    mainLayout->setStretchFactor(layout_1, 1);
    mainLayout->setStretchFactor(layout_2, 2);
    mainLayout->setContentsMargins(0,height()/10,0,height()/24);

    setLayout(mainLayout);
}

void STouchFlickableKeyboard::setConnect()
{
    connect(buttonAccept, &QPushButton::pressed, this, &STouchFlickableKeyboard::slotButtonAcceptPressed);
    connect(buttonCancel, &QPushButton::pressed, this, &STouchFlickableKeyboard::slotButtonCancelPressed);
    connect(touchFirstFlickable, &STouchFlickableList::signalCurrentIndex, this, &STouchFlickableKeyboard::slotGetFirstNumber);
    connect(touchSecondFlickable, &STouchFlickableList::signalCurrentIndex, this, &STouchFlickableKeyboard::slotGetSecondNumber);
}

void STouchFlickableKeyboard::slotGetFirstNumber(const int &index)
{
    first = touchFirstFlickable->getText(index);

    labelNumbers->setText(QString(first).append('.' + second));

    if (!accepted && !getNumber().compare("00.00"))
    {
        buttonAccept->setDisabled(true);
    }
    else
    {
        buttonAccept->setDisabled(false);
    }
}

void STouchFlickableKeyboard::slotGetSecondNumber(const int &index)
{
    second = touchSecondFlickable->getText(index);

    labelNumbers->setText(QString(first).append('.' + second));

    if (!accepted && !getNumber().compare("00.00"))
    {
        buttonAccept->setDisabled(true);
    }
    else
    {
        buttonAccept->setDisabled(false);
    }
}

void STouchFlickableKeyboard::setTitle1(const QString text)
{
    labelTitle1->setText(text);
}

void STouchFlickableKeyboard::setTitle2(const QString text)
{
    labelTitle2->setText(text);
}

void STouchFlickableKeyboard::slotButtonAcceptPressed()
{
    emit signalNumbersChanged(getNumber());
    accepted = true;
    close();
}

void STouchFlickableKeyboard::slotButtonCancelPressed()
{
    accepted = false;
    close();
}

bool STouchFlickableKeyboard::isAccepted()
{
    return accepted;
}

QString STouchFlickableKeyboard::getNumber() const
{
    return labelNumbers->text();
}

void STouchFlickableKeyboard::clear()
{
    labelNumbers->setText("00.00");

    //touchFirstFlickable->setOffset(0);
    //touchSecondFlickable->setOffset(0);

    first = "00";
    second = "00";

    accepted = false;
}

QString STouchFlickableKeyboard::formStyleSheetString(const QString &style)
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


void STouchFlickableKeyboard::retranslateUI()
{
    buttonCancel->setText(tr("Cancel"));
    buttonAccept->setText(tr("Accept"));
}

void STouchFlickableKeyboard::changeEvent(QEvent* event)
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

void STouchFlickableKeyboard::showEvent(QShowEvent *event)
{
    Q_UNUSED(event)
}

void STouchFlickableKeyboard::hideEvent(QHideEvent *event)
{
    Q_UNUSED(event)

    buttonAccept->setDisabled(true);
}
