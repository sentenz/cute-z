#include "STouchDialogScreensaver.h"
#include "../widget/button/SIconButton.h"

#include <QApplication>
#include <QTimer>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPropertyAnimation>
#include <QFocusEvent>


STouchDialogScreensaver::STouchDialogScreensaver(QWidget *parent) : QDialog(parent)
{
    this->setObjectName("STouchDialogScreensaver");
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
    this->setStyleSheet("background-color: " + ::GlobalColorCustomBase.name() + ";");
    this->setWindowFlags(this->windowFlags() | Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint); // | Qt::X11BypassWindowManagerHint | Qt::Tool
    this->setAttribute(Qt::WA_AcceptTouchEvents);
    this->setWindowModality(Qt::ApplicationModal);
    this->setModal(true);
    this->activateWindow();
    this->raise();
    this->setFocus();

    this->setupWidget();
    this->setupGUI();
    this->setConnect();
    this->restyleUI();
}

void STouchDialogScreensaver::setupWidget()
{
    this->m_icon = new SIconButton(QIcon(":/images/sentenz.svg"), this);
    this->m_icon->setIconSize(QSize(this->size()));
    this->m_icon->setColor(::GlobalColorCustomText);
    this->m_icon->setAttribute(Qt::WA_TransparentForMouseEvents);
}

void STouchDialogScreensaver::setupGUI()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addStretch();
    mainLayout->addWidget(this->m_icon);
    mainLayout->addStretch();

    this->setLayout(mainLayout);
}

void STouchDialogScreensaver::setConnect()
{
}

void STouchDialogScreensaver::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);

    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity", this);
    animation->setDuration(::GlobalAnimationTimeIn);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->setEasingCurve(QEasingCurve::OutCubic);
    animation->start(QPropertyAnimation::DeleteWhenStopped);
}

void STouchDialogScreensaver::slotClose()
{
    QTimer::singleShot(0, this, SLOT(close()));
}

void STouchDialogScreensaver::mouseReleaseEvent(QMouseEvent* event)
{
    Q_UNUSED(event);

    this->slotClose();
}

void STouchDialogScreensaver::retranslateUI()
{
}

void
STouchDialogScreensaver::restyleUI()
{
    this->setStyleSheet("background-color: " + ::GlobalColorCustomBase.name() + ";");
}

void
STouchDialogScreensaver::changeEvent(QEvent* event)
{
    switch(event->type())
    {
    case QEvent::LanguageChange:
        retranslateUI();
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
