#include "STouchColorKeyboard.h"
#include "../widget/layout/SHScrollArea.h"
#include "../keyboard/SColorSquare.h"
#include "../keyboard/SColorRgb.h"
#include "../widget/button/SPushButton.h"
#include "../widget/button/SToolButton.h"

#include <QApplication>
#include <QStackedWidget>
#include <QButtonGroup>
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
#include <QList>
#include <QDebug>


STouchColorKeyboard::STouchColorKeyboard(QWidget *parent) : QDialog(parent)
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
}

STouchColorKeyboard::~STouchColorKeyboard()
{
    /// StackedWidgets
    for (int i = this->stackedWidget->count(); i > 0; i--)
    {
        QWidget *widget = this->stackedWidget->widget(i);
        this->stackedWidget->removeWidget(widget);
        delete widget;
        widget = nullptr;
    }
}

void STouchColorKeyboard::setupWidget()
{
    /// Labels
    this->labelTitle = new QLabel(this);
    this->labelTitle->setAlignment(Qt::AlignCenter);
    this->labelTitle->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->labelTitle->setStyleSheet("QLabel { font: " + ::GlobalLabelTextFont + "; color: " + this->m_colorText.name() + "; background: transparent; }");

    this->labelDisplay = new QLabel(this);
    this->labelDisplay->setAlignment(Qt::AlignCenter);
    this->labelDisplay->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    this->labelColor = new QLabel(this);
    this->labelColor->setText(tr("Color"));
    this->labelColor->setAlignment(Qt::AlignCenter);
    this->labelColor->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    this->labelColor->setStyleSheet("QLabel { font: 16pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background: transparent; }");

    this->labelSw = new QLabel(this);
    this->labelSw->setText(tr("S/W"));
    this->labelSw->setAlignment(Qt::AlignCenter);
    this->labelSw->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    this->labelSw->setStyleSheet("QLabel { font: 16pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background: transparent; }");

    this->labelRgb = new QLabel(this);
    this->labelRgb->setText(tr("RGB"));
    this->labelRgb->setAlignment(Qt::AlignCenter);
    this->labelRgb->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    this->labelRgb->setStyleSheet("QLabel { font: 16pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background: transparent; }");

    /// Buttons
    this->buttonCancel = new SPushButton(QChar(0x292B), this);
    this->buttonCancel->setStyleSheet(this->formStyleSheet("push"));

    this->buttonAccept = new SPushButton(QChar(0x2713), this);
    this->buttonAccept->setStyleSheet(this->formStyleSheet("push"));

    //
    // Widgets & Stackedwidget
    //
    this->colorSquare = new SColorSquare;

    this->colorRgb = new SColorRgb;

    this->stackedWidget = new QStackedWidget(this);
    this->stackedWidget->addWidget(this->colorRgb);
    this->stackedWidget->addWidget(this->colorSquare);
    this->stackedWidget->setCurrentIndex(0);

    //
    // Buttons & Group
    //
    SToolButton *buttonLevel0 = new SToolButton(this);
    buttonLevel0->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    buttonLevel0->shape(SToolButton::Shape::ColorHSV);
    buttonLevel0->setCheckable(true);

    SToolButton *buttonLevel1 = new SToolButton(this);
    buttonLevel1->setToolButtonStyle(Qt::ToolButtonIconOnly);
    buttonLevel1->shape(SToolButton::Shape::ColorSW);
    buttonLevel1->setCheckable(true);

    SToolButton *buttonLevel2 = new SToolButton(this);
    buttonLevel2->setToolButtonStyle(Qt::ToolButtonIconOnly);
    buttonLevel2->shape(SToolButton::Shape::ColorRGB);
    buttonLevel2->setCheckable(true);
    buttonLevel2->setChecked(true);

    int iter = 0;
    this->buttonGroup = new QButtonGroup(this);
    this->buttonGroup->setExclusive(true);
    this->buttonGroup->addButton(buttonLevel2, iter++);
    this->buttonGroup->addButton(buttonLevel0, iter++);
    this->buttonGroup->addButton(buttonLevel1, iter++);
}

void STouchColorKeyboard::setupLayout()
{
    QHBoxLayout *layout_0 = new QHBoxLayout;
    layout_0->addWidget(this->buttonCancel, 1);
    layout_0->addWidget(this->labelTitle, 5);
    layout_0->addWidget(this->buttonAccept, 1);
    layout_0->setSpacing(0);
    layout_0->setMargin(0);
    layout_0->setContentsMargins(0, 0, 0, 0);

    QVBoxLayout *layout_1 = new QVBoxLayout;
    layout_1->addStretch(2);
    layout_1->addWidget(this->labelDisplay, 2);
    layout_1->addStretch(2);

    QVBoxLayout *layout_2 = new QVBoxLayout;
    layout_2->addWidget(this->stackedWidget);
    layout_2->setSpacing(0);
    layout_2->setMargin(0);
    layout_2->setContentsMargins(0, 0, 0, 0);

    /* Layout Button */
    int iter = 0;
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(this->buttonGroup->button(iter++));
    buttonLayout->addWidget(this->buttonGroup->button(iter++));
    buttonLayout->addWidget(this->buttonGroup->button(iter++));

    QHBoxLayout *labelLayout = new QHBoxLayout;
    labelLayout->addWidget(this->labelRgb);
    labelLayout->addWidget(this->labelColor);
    labelLayout->addWidget(this->labelSw);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(layout_0, 2);
    mainLayout->addLayout(buttonLayout, 2);
    mainLayout->addLayout(labelLayout, 0);
    mainLayout->addLayout(layout_1, 1);
//    mainLayout->addStretch(1);
    mainLayout->addLayout(layout_2, 12);
//    mainLayout->setSpacing(0);
//    mainLayout->setMargin(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(mainLayout);
}

void STouchColorKeyboard::setConnect()
{
    // Button
    connect(this->buttonAccept, &SPushButton::released, this, &STouchColorKeyboard::slotReleasedButton);
    connect(this->buttonCancel, &SPushButton::released, this, &STouchColorKeyboard::slotReleasedButton);
    // Widgets
    connect(this->colorSquare, &SColorSquare::colorSelected, this, &STouchColorKeyboard::slotColorChanged);
    connect(this->colorRgb, &SColorRgb::signalColorChanged, this, &STouchColorKeyboard::slotColorChanged);
    connect(this->colorSquare, &SColorSquare::colorSelected, this->colorRgb, &SColorRgb::slotColorChanged);
    // Button Group
    connect(this->buttonGroup, SIGNAL(buttonClicked(int)), this->colorSquare, SLOT(setMode(int)));
    connect(this->buttonGroup, static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked), [=](int id) {
        if ((id == 1) || (id == 2))
        {
            // SColorSquare
            this->stackedWidget->setCurrentIndex(1);
        }
        else
        {
            // SColorRgb
            this->stackedWidget->setCurrentIndex(0);
        }
    });
}

void STouchColorKeyboard::slotColorChanged(const QColor &color)
{
    this->m_color = color;
    this->labelDisplay->setStyleSheet("QLabel { background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 transparent, stop: 0.3 " + color.name() + ", stop: 0.7 " + color.name() + ", stop:1 transparent); border-top: 1px solid qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 transparent, stop: 0.3 " + this->m_colorText.name() + ", stop: 0.7 " + this->m_colorText.name() + ", stop:1 transparent); border-bottom: 1px solid qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 transparent, stop: 0.3 " + this->m_colorText.name() + ", stop: 0.7 " + this->m_colorText.name() + ", stop:1 transparent); }");
}

void STouchColorKeyboard::slotReleasedButton()
{
    ///
    /// \brief pb: casting which button is pressed
    ///
    SPushButton *pb = qobject_cast<SPushButton *>(sender());

    if (pb)
    {
        /// CANCEL characters
        if (!pb->text().compare(QChar(0x292B)))
        {
            this->m_accepted = false;
            this->slotClose();
        }
        /// ACCEPT characters
        else if (!pb->text().compare(QChar(0x2713)))
        {
            emit signalColorChanged(this->m_color);
            this->m_accepted = true;
            this->slotClose();
        }
    }
}

void
STouchColorKeyboard::setTitle(const QString text)
{
    this->labelTitle->setText(text);
}

bool
STouchColorKeyboard::isAccepted()
{
    return this->m_accepted;
}

void
STouchColorKeyboard::setColor(const QColor color)
{
    this->colorRgb->setColor(color);
}

QColor
STouchColorKeyboard::getColor() const
{
    return this->m_color;
}

void
STouchColorKeyboard::setBaseColor(const QColor &color)
{
    this->m_colorBase = color;
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->buttonCancel->setStyleSheet(this->formStyleSheet("push"));
    this->buttonAccept->setStyleSheet(this->formStyleSheet("push"));
    this->update();
}

void
STouchColorKeyboard::setContrastColor(const QColor &color)
{
    this->m_colorContrast = color;
    this->buttonCancel->setStyleSheet(this->formStyleSheet("push"));
    this->buttonAccept->setStyleSheet(this->formStyleSheet("push"));
    this->update();
}

void
STouchColorKeyboard::setTextColor(const QColor &color)
{
    this->m_colorText = color;
    this->labelTitle->setStyleSheet("QLabel { font: " + ::GlobalLabelTextFont + "; color: " + this->m_colorText.name() + "; background: transparent; }");
    this->labelColor->setStyleSheet("QLabel { font: 16pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background: transparent; }");
    this->labelSw->setStyleSheet("QLabel { font: 16pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background: transparent; }");
    this->labelRgb->setStyleSheet("QLabel { font: 16pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background: transparent; }");
    this->buttonCancel->setStyleSheet(this->formStyleSheet("push"));
    this->buttonAccept->setStyleSheet(this->formStyleSheet("push"));
    this->update();
}

void
STouchColorKeyboard::setHighlightColor(const QColor &color)
{
    this->m_colorHighlight = color;
    this->buttonCancel->setStyleSheet(this->formStyleSheet("push"));
    this->buttonAccept->setStyleSheet(this->formStyleSheet("push"));
    this->update();
}

void STouchColorKeyboard::showEvent(QShowEvent *event)
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

void STouchColorKeyboard::slotClose()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity", this);
    animation->setDuration(::GlobalAnimationFastTimeOut);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->setEasingCurve(QEasingCurve::InCubic);
    animation->start(QPropertyAnimation::DeleteWhenStopped);

    QTimer::singleShot(::GlobalAnimationFastTimeOut, this, SLOT(close()));
}

void STouchColorKeyboard::retranslateUI()
{
    this->labelColor->setText(tr("Color"));
    this->labelSw->setText(tr("S/W"));
    this->labelRgb->setText(tr("RGB"));
}

void STouchColorKeyboard::changeEvent(QEvent* event)
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

QString STouchColorKeyboard::formStyleSheet(const QString &style)
{
     QString sheet = "";

    if (!style.compare("push"))
    {
        sheet = "\
                SPushButton          { text-align: center; font: 30pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background-color: transparent; border: none; } \
                SPushButton:pressed  { text-align: center; font: 30pt " + ::GlobalFont + "; color: " + this->m_colorHighlight.name() + "; background-color: transparent; border: none; } \
                SPushButton:disabled { text-align: center; font: 30pt " + ::GlobalFont + "; color: " + this->m_colorContrast.darker().name() + "; background-color: transparent; none; } \
                ";
    }
    else if (!style.compare("tool"))
    {
        sheet = "\
                QToolButton         { padding-top: 0px; padding-bottom: 0px; background-color: " + this->m_colorContrast.darker().name() + "; border: none; } \
                QToolButton:pressed { padding-top: 0px; padding-bottom: 0px; background-color: " + this->m_colorContrast.darker().name() + "; border: none; } \
                QToolButton:checked { padding-top: 0px; padding-bottom: 0px; background-color: " + this->m_colorContrast.darker().name() + "; border: none; } \
                ";
    }

    return sheet;
}
