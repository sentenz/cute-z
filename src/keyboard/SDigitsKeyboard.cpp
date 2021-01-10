#include "SDigitsKeyboard.h"
#include "../widget/button/SRaisedButton.h"

#include <QApplication>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QStringList>
#include <QChar>
#include <QTimer>
#include <QPainter>
#include <QPaintEvent>
#include <QRegularExpression>
#include <QPropertyAnimation>
#include <QRect>
#include <QFontMetrics>
#include <QStyleOption>


SDigitsKeyboard::SDigitsKeyboard(QWidget *parent) : QWidget(parent)
{
    this->setWindowState(Qt::WindowFullScreen);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->setWindowFlags(this->windowFlags() | Qt::Window | Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_AcceptTouchEvents);
    this->setAutoFillBackground(true);

    this->setupWidget();
    this->setupLayout();
    this->setConnect();
    this->restyleUI();
}

SDigitsKeyboard::~SDigitsKeyboard()
{
}

void SDigitsKeyboard::setupWidget()
{
    /// NUMBERS
    this->buttonZero = new SRaisedButton(tr("0"), this);

    this->buttonOne = new SRaisedButton(tr("1"), this);

    this->buttonTwo = new SRaisedButton(tr("2"), this);

    this->buttonThree = new SRaisedButton(tr("3"), this);

    this->buttonFour = new SRaisedButton(tr("4"), this);

    this->buttonFive = new SRaisedButton(tr("5"), this);

    this->buttonSix = new SRaisedButton(tr("6"), this);

    this->buttonSeven = new SRaisedButton(tr("7"), this);

    this->buttonEight = new SRaisedButton(tr("8"), this);

    this->buttonNine = new SRaisedButton(tr("9"), this);

    /// SYMBOLS
    this->buttonMinus = new SRaisedButton(QChar(0x00B1), this);

    this->buttonDot = new SRaisedButton(".", this);
    this->buttonDot->setDisabled(true);

    QList<SRaisedButton *> buttons = this->findChildren<SRaisedButton *>();
    for (int i = 0; i < buttons.size(); ++i)
    {
        buttons.at(i)->setRippleStyle(Material::PositionedRipple);
        buttons.at(i)->setFontSize(22);
        buttons.at(i)->setDisabledMode(true);
    }
}

void SDigitsKeyboard::setupLayout()
{
    QHBoxLayout *keyboardLayout_1 = new QHBoxLayout;
    keyboardLayout_1->addWidget(this->buttonOne);
    keyboardLayout_1->addWidget(this->buttonTwo);
    keyboardLayout_1->addWidget(this->buttonThree);
    keyboardLayout_1->setSpacing(0);
    keyboardLayout_1->setMargin(0);
    keyboardLayout_1->setContentsMargins(0, 0, 0, 0);

    QHBoxLayout *keyboardLayout_2 = new QHBoxLayout;
    keyboardLayout_2->addWidget(this->buttonFour);
    keyboardLayout_2->addWidget(this->buttonFive);
    keyboardLayout_2->addWidget(this->buttonSix);
    keyboardLayout_2->setSpacing(0);
    keyboardLayout_2->setMargin(0);
    keyboardLayout_2->setContentsMargins(0, 0, 0, 0);

    QHBoxLayout *keyboardLayout_3 = new QHBoxLayout;
    keyboardLayout_3->addWidget(this->buttonSeven);
    keyboardLayout_3->addWidget(this->buttonEight);
    keyboardLayout_3->addWidget(this->buttonNine);
    keyboardLayout_3->setSpacing(0);
    keyboardLayout_3->setMargin(0);
    keyboardLayout_3->setContentsMargins(0, 0, 0, 0);

    QHBoxLayout *keyboardLayout_4 = new QHBoxLayout;
    keyboardLayout_4->addWidget(this->buttonDot);
    keyboardLayout_4->addWidget(this->buttonZero);
    keyboardLayout_4->addWidget(this->buttonMinus);
    keyboardLayout_4->setSpacing(0);
    keyboardLayout_4->setMargin(0);
    keyboardLayout_4->setContentsMargins(0, 0, 0, 0);

    int t_horizontalSize = ::GlobalWindowSize.height() < ::GlobalWindowSize.width() ? ::GlobalWindowSize.height()*0.225 : ::GlobalWindowSize.width()*0.0417;

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(keyboardLayout_1);
    mainLayout->addLayout(keyboardLayout_2);
    mainLayout->addLayout(keyboardLayout_3);
    mainLayout->addLayout(keyboardLayout_4);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    mainLayout->setContentsMargins(t_horizontalSize, 10, t_horizontalSize, 10);

    this->setLayout(mainLayout);
}

void SDigitsKeyboard::setConnect()
{
    QList<SRaisedButton *> buttons = this->findChildren<SRaisedButton *>();
    for (int i = 0; i < buttons.size(); ++i)
    {
        connect(buttons.at(i), &SRaisedButton::pressed, this, &SDigitsKeyboard::slotButtonPressed);
    }
}

void SDigitsKeyboard::slotButtonPressed()
{
    SRaisedButton *pb = qobject_cast<SRaisedButton *>(sender());
    if (pb)
    {
        emit signalSymbolChanged(this->convertUnicodeToString(pb->text()));
    }
}

QString SDigitsKeyboard::convertUnicodeToString(QString string)
{
    if (!string.compare(QChar(0x2A2F)))
    {
        return "*"; /// Multipli
    }
    else if (!string.compare(QChar(0x00F7)))
    {
        return "/"; /// Division
    }
    else if (!string.compare(QChar(0x00B1)))
    {
        return "-"; /// Minus
    }
    else if (!string.compare(QChar(0x002B)))
    {
        return "+"; /// Plus
    }
    else
    {
        return string;
    }
}

void SDigitsKeyboard::setDatatype(const Datatype &type)
{
    switch (type)
    {
    case Datatype::Int:
        this->buttonDot->setDisabled(true);
        break;

    case Datatype::Double:
        this->buttonDot->setEnabled(true);
        break;

    default:
        break;
    }
}

void SDigitsKeyboard::setSign(const bool sign)
{
    this->buttonMinus->setEnabled(sign);
}

void
SDigitsKeyboard::paintEvent(QPaintEvent *event)
{
    QStyleOption option;
    option.init(this);
    QPainter painter(this);
    this->style()->drawPrimitive(QStyle::PE_Widget, &option, &painter, this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.fillRect(this->rect(), QBrush(this->m_colorContrast));
    painter.end();

    QWidget::paintEvent(event);
}

void SDigitsKeyboard::retranslateUI()
{
}

void
SDigitsKeyboard::restyleUI()
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
SDigitsKeyboard::changeEvent(QEvent * event)
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
