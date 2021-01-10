#include "STouchDialogTumbler.h"
#include "../widget/wheel/SVTumbler.h"
#include "../widget/label/SLabel.h"
#include "../widget/button/SPushButton.h"

#include <QApplication>
#include <QPixmap>
#include <QLabel>
#include <QVBoxLayout>
#include <QTimer>
#include <QString>
#include <QPainter>
#include <QPaintEvent>
#include <QPushButton>
#include <QPropertyAnimation>


STouchDialogTumbler::STouchDialogTumbler(QWidget *parent) : QDialog(parent)
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
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setAttribute(Qt::WA_NoSystemBackground);
    this->setAttribute(Qt::WA_OpaquePaintEvent);
    this->setAttribute(Qt::WA_AcceptTouchEvents);
    this->setWindowModality(Qt::WindowModal);
    this->setModal(true);
    this->activateWindow();
    this->raise();

    this->setupWidget();
    this->setupLayout();
    this->setConnect();
}

STouchDialogTumbler::~STouchDialogTumbler()
{
}

void
STouchDialogTumbler::setupWidget()
{
    // Labels
    this->labelTitle = new SLabel(this);
    this->labelTitle->fontSize(20);
    this->labelTitle->setTheme(SLabel::Theme::Contrast);

    this->labelDescription = new SLabel(this);
//    this->labelDescription->setVisible(false);
    this->labelDescription->setTheme(SLabel::Theme::Contrast);

    // Wheel
    this->tumblerText = new SVTumbler(this);
    this->tumblerText->enableHighlight(false);

    // Option buttons
    this->buttonReject = new SPushButton(tr("Cancel"), this);
    this->buttonReject->setFontSize(19);

    this->buttonAccept = new SPushButton(tr("Done"), this);
    this->buttonAccept->setFontSize(19);
}

void
STouchDialogTumbler::setupLayout()
{
    int t_verticalSize = ::GlobalWindowSize.height() > ::GlobalWindowSize.width() ? ::GlobalWindowSize.height()*0.225 : ::GlobalWindowSize.width()*0.0417;
    int t_horizontalSize = ::GlobalWindowSize.height() < ::GlobalWindowSize.width() ? ::GlobalWindowSize.height()*0.225 : ::GlobalWindowSize.width()*0.0417;

    QHBoxLayout * buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(3);
    buttonLayout->addWidget(this->buttonReject, 5);
    buttonLayout->addWidget(this->buttonAccept, 5);

    QHBoxLayout * listLayout = new QHBoxLayout;
    listLayout->addWidget(this->tumblerText, 5, Qt::AlignRight);
    listLayout->addWidget(this->labelDescription, 3, Qt::AlignLeft);

    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->labelTitle, 5);
    mainLayout->addLayout(listLayout, 15);
    mainLayout->addLayout(buttonLayout, 5);
    mainLayout->setMargin(t_horizontalSize * 1.5);

    this->setLayout(mainLayout);
    this->setContentsMargins(t_horizontalSize, t_verticalSize, t_horizontalSize, t_verticalSize);
}

void
STouchDialogTumbler::setConnect()
{
    // Buttons
    connect(this->buttonAccept, &QPushButton::released, this, &STouchDialogTumbler::slotAccept);
    connect(this->buttonReject, &QPushButton::released, this, &STouchDialogTumbler::slotReject);
    // Wheel
    connect(this->tumblerText, &SVTumbler::stopped, this, &STouchDialogTumbler::slotIndex);
}

QStringList
STouchDialogTumbler::items() const
{
    return this->m_items;
}

void
STouchDialogTumbler::setItems(const QStringList &items)
{
    this->m_items = items;
    this->tumblerText->setItems(this->m_items);
}

void
STouchDialogTumbler::setDescription(const QString &description)
{
    this->labelDescription->setText(description);
//    this->labelDescription->setVisible(true);
}

void
STouchDialogTumbler::setFontSize(const int size)
{
    this->labelTitle->fontSize(size);
}

void
STouchDialogTumbler::setFontSizeParamter(const int size)
{
    this->tumblerText->setFontSize(size);
    this->labelDescription->fontSize(size);
}

void
STouchDialogTumbler::setOpacity(const double opacity)
{
    this->m_opacity = opacity;
    update();
}

void
STouchDialogTumbler::enableHighlight(const bool enable)
{
    this->tumblerText->enableHighlight(enable);
}

void
STouchDialogTumbler::setAlignment(const Qt::AlignmentFlag &alignment)
{
    this->tumblerText->setAlignment(alignment);
}

int
STouchDialogTumbler::currentIndex() const
{
    return this->tumblerText->currentIndex();
}

void
STouchDialogTumbler::setCurrentIndex(const int index)
{
    this->tumblerText->setCurrentIndex(index);
}

QString
STouchDialogTumbler::currentContent() const
{
    return this->tumblerText->currentContent();
}

void
STouchDialogTumbler::setCurrentContent(const QString &content)
{
    this->tumblerText->setCurrentContent(content);
}

void
STouchDialogTumbler::scrollToIndex(const int index)
{
    this->tumblerText->scrollToIndex(index);
}

void
STouchDialogTumbler::slotIndex(int index)
{
    this->m_index = index;
}

void
STouchDialogTumbler::slotAccept()
{
    this->m_accepted = true;
    this->slotClose();
}

void
STouchDialogTumbler::slotReject()
{
    this->m_accepted = false;
    this->slotClose();
}

void
STouchDialogTumbler::setTitleText(const QString &text)
{
    this->labelTitle->setText(text);
}

void
STouchDialogTumbler::setAcceptText(const QString &text)
{
    this->buttonAccept->setText(text);
}

void
STouchDialogTumbler::setRejectText(const QString &text)
{
    this->buttonReject->setText(text);
}

void
STouchDialogTumbler::setAcceptVisible(const bool visible)
{
    this->buttonAccept->setVisible(visible);
}

void
STouchDialogTumbler::setRejectVisible(const bool visible)
{
    this->buttonReject->setVisible(visible);
}

bool
STouchDialogTumbler::isAccepted()
{
    return m_accepted;
}

bool
STouchDialogTumbler::isRejected()
{
    return !m_accepted;
}

void
STouchDialogTumbler::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    QColor t_color = this->m_colorText;
    t_color.setAlphaF(this->m_opacity);
    painter.fillRect(event->rect(), QBrush(t_color));
    painter.fillRect(this->contentsRect(), QBrush(this->m_colorContrast));
    painter.end();
}

void
STouchDialogTumbler::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);

    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity", this);
    animation->setDuration(::GlobalAnimationTimeIn);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->setEasingCurve(QEasingCurve::OutCubic);
    animation->start(QPropertyAnimation::DeleteWhenStopped);
}

void
STouchDialogTumbler::slotClose()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity", this);
    animation->setDuration(::GlobalAnimationTimeOut);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->setEasingCurve(QEasingCurve::OutCubic);
    animation->start(QPropertyAnimation::DeleteWhenStopped);

    QTimer::singleShot(::GlobalAnimationTimeOut, this, SLOT(close()));
}

void
STouchDialogTumbler::retranslateUI()
{
    this->buttonReject->setText(tr("Cancel"));
    this->buttonAccept->setText(tr("Done"));
}

void
STouchDialogTumbler::restyleUI()
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
STouchDialogTumbler::changeEvent(QEvent * event)
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
