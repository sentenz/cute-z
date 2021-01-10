#include "STouchDialogChoise.h"
#include "../widget/label/SLabel.h"
#include "../widget/button/SPushButton.h"
#include "../widget/list/SList.h"

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


STouchDialogChoise::STouchDialogChoise(QWidget *parent) : QDialog(parent)
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

STouchDialogChoise::~STouchDialogChoise()
{
}

void
STouchDialogChoise::setupWidget()
{
    // Header
    this->labelTitle = new SLabel(this);
    this->labelTitle->fontSize(20);
    this->labelTitle->setTheme(SLabel::Theme::Contrast);

    // Swipe list
    this->list = new SList;
    this->list->enableScrollBar(true);

    // Option buttons
    this->buttonReject = new SPushButton(tr("Cancel"), this);
    this->buttonReject->setFontSize(19);

    this->buttonAccept = new SPushButton(tr("Done"), this);
    this->buttonAccept->setFontSize(19);
}

void
STouchDialogChoise::setupLayout()
{
    int t_verticalSize = ::GlobalWindowSize.height() > ::GlobalWindowSize.width() ? ::GlobalWindowSize.height() * 0.225 : ::GlobalWindowSize.width() * 0.0417;
    int t_horizontalSize = ::GlobalWindowSize.height() < ::GlobalWindowSize.width() ? ::GlobalWindowSize.height() * 0.225 : ::GlobalWindowSize.width() * 0.0417;

    QHBoxLayout * buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(3);
    buttonLayout->addWidget(this->buttonReject, 5);
    buttonLayout->addWidget(this->buttonAccept, 5);

    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->labelTitle, 5);
    mainLayout->addWidget(this->list->listItems(), 15);
    mainLayout->addLayout(buttonLayout, 5);
    mainLayout->setMargin(t_horizontalSize * 1.5);

    this->setLayout(mainLayout);
    this->setContentsMargins(t_horizontalSize, t_verticalSize, t_horizontalSize, t_verticalSize);
}

void
STouchDialogChoise::setConnect()
{
    // Option buttons
    connect(this->buttonAccept, &QPushButton::released, this, &STouchDialogChoise::slotAccept);
    connect(this->buttonReject, &QPushButton::released, this, &STouchDialogChoise::slotReject);
}

void
STouchDialogChoise::setOpacity(const double opacity)
{
    this->m_opacity = opacity;
    update();
}

QStringList
STouchDialogChoise::items() const
{
    return this->m_items;
}

void
STouchDialogChoise::items(const QStringList &items)
{
    this->m_items = items;
    this->list->listItemsSingleChoice(this->m_items);
}

void
STouchDialogChoise::setFontSize(const int size)
{
    this->labelTitle->fontSize(size);
}

void
STouchDialogChoise::setFontSizeParamter(const int size)
{
}

void
STouchDialogChoise::index(const int index)
{
    this->list->index(index);
}

int
STouchDialogChoise::index() const
{
    return this->list->index();
}

QString
STouchDialogChoise::content() const
{
}

void
STouchDialogChoise::content(const QString &content)
{
}

void
STouchDialogChoise::slotIndex(int index)
{
    this->m_index = index;
}

void
STouchDialogChoise::slotAccept()
{
    this->m_accepted = true;
    this->slotClose();
}

void
STouchDialogChoise::slotReject()
{
    this->m_accepted = false;
    this->slotClose();
}

void
STouchDialogChoise::title(const QString &text)
{
    this->labelTitle->setText(text);
    this->update();
}

void
STouchDialogChoise::setAcceptText(const QString &text)
{
    this->buttonAccept->setText(text);
    this->update();
}

void
STouchDialogChoise::setRejectText(const QString &text)
{
    this->buttonReject->setText(text);
    this->update();
}

void
STouchDialogChoise::setAcceptVisible(const bool visible)
{
    this->buttonAccept->setVisible(visible);
    this->update();
}

void
STouchDialogChoise::setRejectVisible(const bool visible)
{
    this->buttonReject->setVisible(visible);
    this->update();
}

bool
STouchDialogChoise::isAccepted()
{
    return m_accepted;
}

bool
STouchDialogChoise::isRejected()
{
    return !m_accepted;
}

void
STouchDialogChoise::paintEvent(QPaintEvent * event)
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
STouchDialogChoise::showEvent(QShowEvent *event)
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
STouchDialogChoise::slotClose()
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
STouchDialogChoise::retranslateUI()
{
    this->buttonReject->setText(tr("Cancel"));
    this->buttonAccept->setText(tr("Done"));
}

void
STouchDialogChoise::restyleUI()
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
STouchDialogChoise::changeEvent(QEvent * event)
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
