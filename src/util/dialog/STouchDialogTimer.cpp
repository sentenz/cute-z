#include "STouchDialogTimer.h"

#include <QApplication>
#include <QString>
#include <QPainter>
#include <QPaintEvent>
#include <QTimeLine>
#include <QTimer>


STouchDialogTimer::STouchDialogTimer(QWidget *parent) : QDialog(parent)
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
    this->setWindowFlags(this->windowFlags() | Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_AcceptTouchEvents);
    this->setWindowModality(Qt::WindowModal);
    this->activateWindow();
    this->raise();
    this->setWindowOpacity(this->m_opacitiy);
    //this->setModal(true);

    this->setupWidget();
    this->setConnect();
}

void STouchDialogTimer::setupWidget()
{
    /// Timer
    this->m_timeLine = new QTimeLine(1000, this);
    this->m_timeLine->setFrameRange(200, 0);
    this->m_frameFactor = 1.0/200.0;
    this->m_timeLine->start();
}

void STouchDialogTimer::setConnect()
{
    connect(this->m_timeLine, SIGNAL(frameChanged(int)), this, SLOT(update()));
    connect(this->m_timeLine, SIGNAL(finished()), this, SLOT(slotFinished()));
}

void STouchDialogTimer::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::HighQualityAntialiasing | QPainter::TextAntialiasing);
    painter.fillRect(event->rect(), this->m_colorBase);
    qreal frame = this->m_timeLine->currentFrame();
    if (this->m_counter >= 1)
    {
        painter.setOpacity(frame * this->m_frameFactor);
    }
    else if (this->m_counter < 1)
    {
        painter.setOpacity(frame / (200.0 + (1.0 - this->m_opacitiy) * 100.0));
    }
    painter.setFont(QFont(::GlobalFont, 150));
    painter.setPen(this->m_colorText);
    painter.drawText(event->rect(), Qt::AlignCenter, QString::number(this->m_counter));
    painter.end();
}

void STouchDialogTimer::slotFinished()
{

    if (--this->m_counter >= 0)
    {
        this->m_timeLine->start();
    }
    else
    {
        this->close();
    }
}

void STouchDialogTimer::setTime(const int sec)
{
    this->m_counter = sec;
}

void STouchDialogTimer::setOpacity(const double opacity)
{
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setAttribute(Qt::WA_NoSystemBackground);
    this->setAttribute(Qt::WA_OpaquePaintEvent);

    this->m_opacitiy = opacity;
    this->setWindowOpacity(opacity);
    this->update();
}


void STouchDialogTimer::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);
}

void STouchDialogTimer::retranslateUI()
{
}

void
STouchDialogTimer::restyleUI()
{
    if (this->m_colorBase != ::GlobalColorCustomBase)
    {
        this->m_colorBase = ::GlobalColorCustomBase;
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
STouchDialogTimer::changeEvent(QEvent * event)
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
