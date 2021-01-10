#include "STouchCalculator.h"
#include "../function/Calculator.h"
#include "../widget/button/SPushButton.h"
#include "../widget/label/SLabel.h"

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
#include <QDebug>


STouchCalculator::STouchCalculator(QWidget *parent) : QDialog(parent)
{
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
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->setWindowFlags(this->windowFlags() | Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_AcceptTouchEvents);
    this->setWindowModality(Qt::WindowModal);
    this->setModal(true);
    this->activateWindow();
    this->raise();

    this->setupWidget();
    this->setupGUI();
    this->setConnect();
}

STouchCalculator::~STouchCalculator()
{
}

void STouchCalculator::setupWidget()
{
    /// LABELS
    this->labelNumbers = new SLabel(this);
    this->labelNumbers->setAlignment(Qt::AlignCenter);
    this->labelNumbers->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->labelNumbers->setTheme(SLabel::Theme::Text);
    this->labelNumbers->fontSize(22);

    this->labelTitle = new SLabel(this);
    this->labelTitle->setAlignment(Qt::AlignCenter);
    this->labelTitle->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->labelTitle->setTheme(SLabel::Theme::Text);

    /// NUMBERS
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

    /// SYMBOLS
    this->buttonDot = new SPushButton(".", this);
    this->buttonDot->setDisabled(true);

    this->buttonDelete = new SPushButton(QChar(0x2770), this);

    this->buttonClear = new SPushButton(QChar(0x0043), this);
    this->buttonClear->setObjectName("math");
    this->buttonClear->setVisible(false);

    this->buttonEqual = new SPushButton(QChar(0x003D), this);
    this->buttonEqual->setObjectName("equal");
    this->buttonEqual->setVisible(false);

    this->buttonMinus = new SPushButton(QChar(0x2212), this);
    this->buttonMinus->setObjectName("math");
    this->buttonMinus->setVisible(false);

    this->buttonPlus = new SPushButton(QChar(0x002B), this);
    this->buttonPlus->setObjectName("math");
    this->buttonPlus->setVisible(false);

    this->buttonDivision = new SPushButton(QChar(0x00F7), this);
    this->buttonDivision->setObjectName("math");
    this->buttonDivision->setVisible(false);

    this->buttonMultipli = new SPushButton(QChar(0x2A2F), this);
    this->buttonMultipli->setObjectName("math");
    this->buttonMultipli->setVisible(false);

    this->buttonExponent = new SPushButton("^", this);
    this->buttonExponent->setObjectName("math");
    this->buttonExponent->setVisible(false);

    /// EXTENDET
    this->buttonCancel = new SPushButton(QChar(0x292B), this);
    this->buttonCancel->setObjectName("cancel");

    QIcon icon;
    icon.addPixmap(QPixmap(":/images/ok_1.svg"), QIcon::Active, QIcon::On);
    icon.addPixmap(QPixmap(":/images/ok_2.svg"), QIcon::Disabled, QIcon::Off);
    this->buttonAccept = new SPushButton(this);
    this->buttonAccept->setIcon(icon);
    this->buttonAccept->setIconSize(QSize(65,65));
    this->buttonAccept->setDisabled(true);
    this->buttonAccept->setObjectName("accept");

    this->setStyle();
}

void STouchCalculator::setStyle()
{
}

void STouchCalculator::setupGUI()
{
    QHBoxLayout *displayLayout_0 = new QHBoxLayout;
    displayLayout_0->addWidget(this->buttonCancel, 1);
    displayLayout_0->addWidget(this->labelNumbers, 3);
    displayLayout_0->addWidget(this->buttonAccept, 1);
    displayLayout_0->setSpacing(0);
    displayLayout_0->setMargin(0);
    displayLayout_0->setContentsMargins(0, 0, 0, 0);

    QHBoxLayout *mathLayout_1 = new QHBoxLayout;
    mathLayout_1->addWidget(this->buttonExponent, 20);
    mathLayout_1->addWidget(this->buttonClear, 20);
    mathLayout_1->addWidget(this->buttonEqual, 41);

    QHBoxLayout *mathLayout_2 = new QHBoxLayout;
    mathLayout_2->addWidget(this->buttonDivision);
    mathLayout_2->addWidget(this->buttonMultipli);
    mathLayout_2->addWidget(this->buttonPlus);
    mathLayout_2->addWidget(this->buttonMinus);

    QHBoxLayout *keyboardLayout_1 = new QHBoxLayout;
    keyboardLayout_1->addWidget(this->buttonOne);
    keyboardLayout_1->addWidget(this->buttonTwo);
    keyboardLayout_1->addWidget(this->buttonThree);
    keyboardLayout_1->addWidget(this->buttonFour);

    QHBoxLayout *keyboardLayout_2 = new QHBoxLayout;
    keyboardLayout_2->addWidget(this->buttonFive);
    keyboardLayout_2->addWidget(this->buttonSix);
    keyboardLayout_2->addWidget(this->buttonSeven);
    keyboardLayout_2->addWidget(this->buttonEight);

    QHBoxLayout *keyboardLayout_3 = new QHBoxLayout;
    keyboardLayout_3->addWidget(this->buttonDot);
    keyboardLayout_3->addWidget(this->buttonZero);
    keyboardLayout_3->addWidget(this->buttonNine);
    keyboardLayout_3->addWidget(this->buttonDelete);

    QVBoxLayout *keyboardLayout = new QVBoxLayout;
    keyboardLayout->addLayout(mathLayout_1);
    keyboardLayout->addLayout(mathLayout_2);
    keyboardLayout->addLayout(keyboardLayout_1);
    keyboardLayout->addLayout(keyboardLayout_2);
    keyboardLayout->addLayout(keyboardLayout_3);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(displayLayout_0, 2);
    mainLayout->addWidget(this->labelTitle, 2);
    mainLayout->addLayout(keyboardLayout, 5);
    //mainLayout->setSpacing(0);
    //mainLayout->setMargin(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(mainLayout);
}

void STouchCalculator::setConnect()
{
    QList<SPushButton *> buttons = this->findChildren<SPushButton *>();
    for (int i = 0; i < buttons.size(); ++i)
    {
        if (!buttons.at(i)->objectName().compare("accept") || !buttons.at(i)->objectName().compare("cancel"))
        {
            connect(buttons.at(i), &SPushButton::released, this, &STouchCalculator::slotGetButton);
        }
        else
        {
            connect(buttons.at(i), &SPushButton::pressed, this, &STouchCalculator::slotGetButton);
        }
    }
}

void STouchCalculator::assignButton()
{
    SPushButton *pb = qobject_cast<SPushButton *>(sender());

    if (pb)
    {
        /// CANCEL
        if (!pb->objectName().compare("cancel"))
        {
            this->accept = false;
            this->slotClose();
            this->clear();
        }
        /// ACCEPT characters
        else if (!pb->objectName().compare("accept") || !pb->objectName().compare("equal"))
        {
            /// Replace ASCII code with string
            this->convertSymbolsMath(this->currentNumbers);
            /// CALCULATOR
            this->currentNumbers = QString::number(Sentenz::calculator(this->currentNumbers.toStdString()));
        }
        /// DELETE character
        else if (!pb->text().compare(QChar(0x2770)))
        {
            this->currentNumbers.remove(this->currentNumbers.length()-1, 1);
        }
        /// CLEAR characters
        else if (!pb->text().compare(QChar(0x0043)))
        {
            this->clear();
        }
        /// ADD CHARACTER TO STRING
        else
        {
            this->currentNumbers.push_back(pb->text());
            this->deniedSymbolsCombination(this->currentNumbers);

            /// Remove last Character if it's dosn't fit in line
            QFontMetrics metrics(this->labelNumbers->font());
            QRect rect = metrics.boundingRect(this->currentNumbers);

            if (rect.width() + 5 > this->labelNumbers->width())
            {
                this->currentNumbers.chop(1);
            }
        }
    }
}

void STouchCalculator::slotGetButton()
{
    ///
    /// \brief pb: casting which button is pressed
    ///
    this->assignButton();

    ///
    /// \brief labelNumbers: visual Numbers
    ///
    this->labelNumbers->setText(this->setElidedText(this->labelNumbers, this->currentNumbers));

    if (this->currentNumbers.isEmpty())
    {
        this->buttonAccept->setDisabled(true);
    }
    else
    {
        this->buttonAccept->setEnabled(true);
    }
}

void STouchCalculator::setTitle(const QString text)
{
    this->labelTitle->setText(text);
}

void STouchCalculator::setDescriptionText(const QString text, const Dialog type)
{
    this->m_descriptionText = text;
    this->m_messageType = type;
}

void STouchCalculator::setRange(const int min, const int max)
{
    this->range.append(QString::number(min));
    this->range.append(QString::number(max));
}

void STouchCalculator::setRange(const double min, const double max)
{
    this->range.append(QString::number(min));
    this->range.append(QString::number(max));
}

bool STouchCalculator::inRange(const QString &string)
{
    if (string.toDouble() < this->range.at(0).toDouble() || string.toDouble() > this->range.at(1).toDouble())
    {
        return false;
    }

    return true;
}

void STouchCalculator::setDatatype(const Datatype &type)
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

void STouchCalculator::clear()
{
    this->lastNumbers.clear();
    this->currentNumbers.clear();
}

bool STouchCalculator::isAccepted()
{
    return this->accept;
}

bool STouchCalculator::isEmpty()
{
    return this->lastNumbers.isEmpty();
}

QString STouchCalculator::getNumber()
{
    return this->lastNumbers;
}

void STouchCalculator::convertSymbolsMath(QString &string)
{
    /// Multipli
    string.replace(QChar(0x2A2F), "*");
    /// Division
    string.replace(QChar(0x00F7), "/");
    /// Minus
    string.replace(QChar(0x2212), "-");
    /// Plus
    string.replace(QChar(0x002B), "+");
}

void STouchCalculator::setMode(const QString mode)
{
    this->m_mode = mode;

    if (!this->m_mode.compare("math"))
    {
        /// Disable this buttons, because its in permanent window
        this->buttonCancel->setVisible(false);
        this->buttonAccept->setVisible(false);
        this->labelTitle->setVisible(false);

        /// For float numbers
        this->buttonDot->setEnabled(true);

        /// Enable math operators
        this->buttonMinus->setVisible(true);
        this->buttonPlus->setVisible(true);
        this->buttonClear->setVisible(true);
        this->buttonDivision->setVisible(true);
        this->buttonMultipli->setVisible(true);
        this->buttonExponent->setVisible(true);
        this->buttonEqual->setVisible(true);
    }

    this->update();
}

void STouchCalculator::deniedSymbolsCombination(QString &string)
{
    string.replace("..", ".");
    string.remove(QRegularExpression("(^\\D|\\.\\d+\\.|\\.\\D|\\D{2,})"));
}

QString STouchCalculator::setElidedText(const SLabel *label, const QString &text, const Qt::TextElideMode elide)
{
    QFontMetrics t_metrics(label->font());
    return t_metrics.elidedText(text, elide, label->width() - 2);
}

void STouchCalculator::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

//    QPainter painter(this);
//    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
//    painter.fillRect(0, 0, this->width(), this->height()/4, ::GlobalColorContrast);
//    painter.end();
}

void STouchCalculator::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);

    /// Window size for developing and emulating
    if (::GlobalWindowSize.isEmpty())
    {
        this->setWindowState(Qt::WindowFullScreen);
        this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }

    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity", this);
    animation->setDuration(::GlobalAnimationTimeIn);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->setEasingCurve(QEasingCurve::OutCubic);
    animation->start(QPropertyAnimation::DeleteWhenStopped);
}

void STouchCalculator::slotClose()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity", this);
    animation->setDuration(::GlobalAnimationFastTimeOut);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->setEasingCurve(QEasingCurve::InCubic);
    animation->start(QPropertyAnimation::DeleteWhenStopped);

    QTimer::singleShot(animation->duration(), this, SLOT(close()));
}

void STouchCalculator::retranslateUI()
{
}

void
STouchCalculator::restyleUI()
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
    if (this->m_colorText != ::GlobalColorCustomText)
    {
        this->m_colorText = ::GlobalColorCustomText;
    }
    if (this->m_colorHighlight != ::GlobalColorCustomHighlight)
    {
        this->m_colorHighlight = ::GlobalColorCustomHighlight;
    }
}

void
STouchCalculator::changeEvent(QEvent * event)
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
