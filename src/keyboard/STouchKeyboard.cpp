#include "STouchKeyboard.h"
#include "../util/dialog/STextDialog.h"
#include "../widget/layout/SHScrollArea.h"
#include "../keyboard/SCanvas.h"
#include "../keyboard/SDigitsKeyboard.h"
#include "../widget/button/SRaisedButton.h"
#include "../widget/button/SToolButton.h"
#include "../widget/label/SLabel.h"
#include "../widget/tab/STabs.h"

#include <QApplication>
#include <QStackedWidget>
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
#include <QList>
#include <QDebug>


STouchKeyboard::STouchKeyboard(QWidget *parent)
    : QDialog(parent)
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
    this->setupLayout();
    this->setConnect();
    this->restyleUI();
}

STouchKeyboard::~STouchKeyboard()
{
    if (this->canvas != nullptr)
    {
        delete this->canvas;
        this->canvas = nullptr;
    }
    if (this->keyboard != nullptr)
    {
        delete this->keyboard;
        this->keyboard = nullptr;
    }
    /// StackedWidgets
    for (int i = this->stackedWidget->count(); i > 0; i--)
    {
        QWidget *widget = this->stackedWidget->widget(i);
        this->stackedWidget->removeWidget(widget);
        delete widget;
        widget = nullptr;
    }
}

void STouchKeyboard::setupWidget()
{
    /* Labels */
    this->labelDisplay = new SLabel(this);
    this->labelDisplay->setAlignment(Qt::AlignCenter);
    this->labelDisplay->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//    this->labelDisplay->setTheme(SLabel::Theme::FilledRoundRect);
    this->labelDisplay->setStyleSheet("QLabel { font: 21pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background: " + this->m_colorContrast.name() + "; border-radius: " + QString::number(this->labelDisplay->height()*0.9) + "px }");

    this->labelTitle = new SLabel(this);
    this->labelTitle->setAlignment(Qt::AlignCenter);
    this->labelTitle->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->labelTitle->setTheme(SLabel::Theme::Text);

    /* Buttons */
    this->buttonCancel = new SRaisedButton(QChar(0x292B), this);
    this->buttonCancel->setFontSize(24);
    this->buttonCancel->setDisabledMode(true);
    this->buttonCancel->setCornerRound();

    this->buttonAccept = new SRaisedButton(QChar(0x2713), this);
    this->buttonAccept->setFontSize(24);
    this->buttonAccept->setCornerRound();
    this->buttonAccept->setDisabled(true);
    this->buttonAccept->setDisabledMode(true);

    /* Animated stackedwidget */
    this->stackedWidget = new QStackedWidget(this);

    /* Widgets */
    this->keyboard = new SDigitsKeyboard;
    this->stackedWidget->addWidget(this->keyboard);

    this->canvas = new SCanvas;
    this->stackedWidget->addWidget(this->canvas);

    /* Tab */
    this->m_tabs = new STabs(this);
    this->m_tabs->addTab(QIcon(":/images/ic_dialpad_white_128dp.svg"), QSize(50, 50));
    this->m_tabs->addTab(QIcon(":/images/ic_touch_app_white_128dp.svg"), QSize(50, 50));
}

void STouchKeyboard::setupLayout()
{
    QHBoxLayout *layout_0 = new QHBoxLayout;
    layout_0->addWidget(this->labelDisplay);
    layout_0->setContentsMargins(10, 0, 10, 0);

    QHBoxLayout *layout_1 = new QHBoxLayout;
    layout_1->addWidget(this->buttonCancel);
    layout_1->addSpacing(10);
    layout_1->addWidget(this->buttonAccept);
    layout_1->setContentsMargins(10, 10, 10, 10);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(layout_0, 2);
    mainLayout->addWidget(this->labelTitle, 5);
    mainLayout->addLayout(layout_1, 2);
    mainLayout->addWidget(this->stackedWidget, 10);
    mainLayout->addWidget(this->m_tabs, 2, Qt::AlignBottom);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 20, 0, 0);

    this->setLayout(mainLayout);
}

void STouchKeyboard::setConnect()
{
    /* Buttons */
    connect(this->buttonAccept, &SRaisedButton::released, this, &STouchKeyboard::slotReleasedButton);
    connect(this->buttonCancel, &SRaisedButton::released, this, &STouchKeyboard::slotReleasedButton);
    /* Widgets */
    connect(this->canvas, &SCanvas::signalSymbolChanged, this, &STouchKeyboard::slotSymbolChanged);
    connect(this->keyboard, &SDigitsKeyboard::signalSymbolChanged, this, &STouchKeyboard::slotSymbolChanged);
    /* Tabs */
    connect(this->m_tabs, SIGNAL(currentChanged(int)), this->stackedWidget, SLOT(setCurrentIndex(int)));
}

void STouchKeyboard::slotSymbolChanged(const QString symbol)
{
    if (this->m_password && this->currentNumbers.length() >= this->m_digits)
    {
        return;
    }

    if (!symbol.compare("-"))
    {
        this->currentNumbers.prepend(symbol);
    }
    else
    {
        this->currentNumbers.push_back(symbol);
        // Remove last Character if it's dosn't fit in line
        this->checkLabelWidth(this->labelDisplay, this->currentNumbers);
    }
    this->checkSymbolsCombination(this->currentNumbers);

    ///
    /// \brief labelDisplay: visual Numbers
    ///
    if (this->m_password)
    {
        this->labelDisplay->setText(QString(this->currentNumbers.length(), QChar(0x25FC)).append(QString(this->m_digits - this->currentNumbers.length(), QChar(0x25FB))).split("", QString::SkipEmptyParts).join(QChar(0x2000)));
    }
    else
    {
        this->labelDisplay->setText(this->setElidedText(this->labelDisplay, this->currentNumbers));
    }

    if (this->currentNumbers.isEmpty())
    {
        this->buttonCancel->setText(QChar(0x292B));
        this->buttonAccept->setDisabled(true);
    }
    else
    {
        this->buttonCancel->setText(QChar(0x276C)); //0x276C
        this->buttonAccept->setEnabled(true);
    }
}

void STouchKeyboard::slotReleasedButton()
{
    ///
    /// \brief pb: casting which button is pressed
    ///
    this->assignButton();

    ///
    /// \brief labelDisplay: visual Numbers
    ///
    if (this->m_password)
    {
        this->labelDisplay->setText(QString(this->currentNumbers.length(), QChar(0x25FC)).append(QString(this->m_digits - this->currentNumbers.length(), QChar(0x25FB))).split("", QString::SkipEmptyParts).join(QChar(0x2000)));
    }
    else
    {
        this->labelDisplay->setText(this->setElidedText(this->labelDisplay, this->currentNumbers));
    }

    if (this->currentNumbers.isEmpty())
    {
        this->buttonCancel->setText(QChar(0x292B));
        this->buttonAccept->setDisabled(true);
    }
    else
    {
        this->buttonCancel->setText(QChar(0x276C));
        this->buttonAccept->setEnabled(true);
    }
}

void STouchKeyboard::assignButton()
{
    SRaisedButton *pb = qobject_cast<SRaisedButton *>(sender());

    if (pb)
    {
        /// CANCEL characters
        if (!pb->text().compare(QChar(0x292B)))
        {
            this->accept = false;
            this->slotClose();
            this->clear();
        }
        /// ACCEPT characters
        else if (!pb->text().compare(QChar(0x2713)))
        {
            if (!this->currentNumbers.isEmpty())
            {
                if (!this->range.isEmpty())
                {
                    if (!this->inRange(this->currentNumbers))
                    {
                        STextDialog *dialog = new STextDialog(this);
                        dialog->setTitle(tr("Keyboard"));
                        dialog->setDescription(this->m_descriptionText);
                        dialog->setAcceptButton(tr("Accept"));
                        dialog->setAttribute(Qt::WA_DeleteOnClose);
                        dialog->show();

                        if (this->m_messageType != Dialog::Information)
                        {
                            return;
                        }
                    }
                }

                emit signalSymbolChanged(this->currentNumbers);

                this->lastNumbers = this->currentNumbers;
                this->currentNumbers.clear();
                this->accept = true;
                this->slotClose();
            }
        }
        /// DELETE character
        else if (!pb->text().compare(QChar(0x276C)))
        {
            this->currentNumbers.remove(this->currentNumbers.length()-1, 1);
        }
    }
}

void STouchKeyboard::setTitle(const QString text)
{
    this->labelTitle->setText(text);
}

void STouchKeyboard::setDescriptionText(const QString text, const Dialog type)
{
    this->m_descriptionText = text;
    this->m_messageType = type;
}

void STouchKeyboard::setRange(const int min, const int max)
{
    this->range.append(QString::number(min));
    this->range.append(QString::number(max));
}

void STouchKeyboard::setRange(const double min, const double max)
{
    this->range.append(QString::number(min));
    this->range.append(QString::number(max));
}

bool STouchKeyboard::inRange(const QString &string)
{
    if (string.toDouble() < this->range.at(0).toDouble() || string.toDouble() > this->range.at(1).toDouble())
    {
        return false;
    }

    return true;
}

void STouchKeyboard::setMaximumDigit(const int digits)
{
    this->m_digits = digits;
    update();
}

void STouchKeyboard::setSecurityMode(const bool on, const int digits)
{
    this->m_password = on;
    this->m_digits = digits;

    this->keyboard->setSign(false);

    this->labelDisplay->setText(QString(digits, QChar(0x25FB)).split("", QString::SkipEmptyParts).join(QChar(0x2000)));
    this->labelDisplay->setStyleSheet("QLabel { font: 20pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background: transparent; }");

    update();
}

void STouchKeyboard::setDatatype(const Datatype &type)
{
    this->keyboard->setDatatype(static_cast<SDigitsKeyboard::Datatype>(type));
}

void STouchKeyboard::clear()
{
    this->lastNumbers.clear();
    this->currentNumbers.clear();
}

bool STouchKeyboard::isAccepted()
{
    return this->accept;
}

bool STouchKeyboard::isEmpty()
{
    return this->lastNumbers.isEmpty();
}

QString STouchKeyboard::getNumber()
{
    return this->lastNumbers;
}

void STouchKeyboard::checkSymbolsCombination(QString &string)
{
    string.replace("..", ".");
    string.remove(QRegularExpression("(^-\\D|\\.\\d+\\.|\\.\\D|\\D{2,})"));
}

void STouchKeyboard::checkLabelWidth(const SLabel *label,
                                     QString &string)
{
    QFontMetrics metrics(label->font());
    QRect rect = metrics.boundingRect(string);
    if (rect.width() * 1.1 > label->width())
    {
        string.chop(1);
    }
}

QString STouchKeyboard::setElidedText(const SLabel *label,
                                      const QString &text,
                                      const Qt::TextElideMode elide)
{
    QFontMetrics t_metrics(label->font());
    return t_metrics.elidedText(text, elide, label->width() - 2);
}

void STouchKeyboard::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);

    // Window size for developing and emulating
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

void STouchKeyboard::slotClose()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity", this);
    animation->setDuration(::GlobalAnimationFastTimeOut);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->setEasingCurve(QEasingCurve::InCubic);
    animation->start(QPropertyAnimation::DeleteWhenStopped);

    QTimer::singleShot(::GlobalAnimationFastTimeOut, this, SLOT(close()));
}

void
STouchKeyboard::retranslateUI()
{
}

void
STouchKeyboard::restyleUI()
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
STouchKeyboard::changeEvent(QEvent * event)
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
