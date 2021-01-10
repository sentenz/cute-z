#include "STouchFlickableList.h"

#include <QApplication>
#include <QTimer>
#include <QTimeLine>
#include <QFont>
#include <QLine>
#include <QPainter>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QGraphicsOpacityEffect>
#include <QLinearGradient>
#include <QPushButton>
#include <QPalette>
#include <QDesktopWidget>
#include <QSvgRenderer>
#include <QEvent>
#include <QResizeEvent>
#include <QTouchEvent>
#include <QPaintEvent>
#include <QFocusEvent>
#include <QShowEvent>
#include <QHideEvent>
#include <QCloseEvent>
#include <QSettings>
#include <QFileSystemWatcher>
#include <QDebug>


STouchFlickableList::STouchFlickableList(QWidget *parent)
    : QWidget(parent)
{
    if (!this->m_hide)
    {
        this->setObjectName("STouchFlickableList");
    }
    this->setWindowState(Qt::WindowFullScreen);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setWindowFlags(this->windowFlags() | Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_AcceptTouchEvents);
    this->setWindowOpacity(1.0);
    this->setMouseTracking(true);
    this->setFocus();

    this->setupLayout();
    this->setConnect();
    this->slotReadSettings();
}

STouchFlickableList::~STouchFlickableList()
{
    if (this->m_hideTimer != nullptr)
    {
        delete this->m_hideTimer;
        this->m_hideTimer = nullptr;
    }
}

void
STouchFlickableList::setupLayout()
{
    // Watcher
    this->fileSystemWatcher = new QFileSystemWatcher(this);
    this->fileSystemWatcher->addPath(::GlobalConfigPathSettings);

    this->setFontSize();
    this->setFontSizeParamter();

    this->m_timeLine = new QTimeLine(300, this);
    this->m_timeLine->setFrameRange(0, 255);

    SFlickable::setAcceptMouseClick(this);
}

void
STouchFlickableList::setConnect()
{
    // Watcher
    connect(this->fileSystemWatcher, &QFileSystemWatcher::directoryChanged, this, &STouchFlickableList::slotReadSettings);
    // TimeLine
    connect(this->m_timeLine, SIGNAL(frameChanged(int)), this, SLOT(update()));
}

void STouchFlickableList::paintEvent(QPaintEvent *event)
{
    // Predefination
    if (!m_widgetNames.isEmpty())
    {
        this->m_maxIndex = m_widgetNames.count();
    }
    else if (!m_widgetPixmap.isEmpty())
    {
        this->m_maxIndex = m_widgetPixmap.count();
    }

    if (!this->m_widgetPixmap.isEmpty())
    {
        if (this->m_itemHeight)
        {
            this->m_height = QFontMetrics(font()).height() + this->m_itemHeight;
        }
        else
        {
            this->m_height = QFontMetrics(font()).height() + 0.20 * this->height();
        }
    }
    else
    {
        if (this->m_itemHeight)
        {
            this->m_height = QFontMetrics(font()).height() + this->m_itemHeight;
        }
        else
        {
            this->m_height = QFontMetrics(font()).height() + 0.14 * this->height();
        }
    }

    // Define begin of loop
    if (this->m_repeat)
    {
        this->m_begin = (this->m_offset  - this->m_height) / this->m_height;
        this->m_y = this->m_begin * this->m_height - this->m_offset;

        if (this->m_begin < 0)
        {
            this->m_begin = this->m_maxIndex + this->m_begin;
        }
    }
    else
    {
        this->m_begin = this->m_offset / this->m_height;
        this->m_y = this->m_begin * this->m_height - this->m_offset;
    }

    // Define end of loop
    this->m_end = this->m_begin + this->height() / this->m_height + 1;
    if (this->m_end > this->m_maxIndex - 1)
    {
        this->m_end = this->m_maxIndex - 1;
    }

    if (this->m_repeat)
    {
        int residue = this->height() - this->m_height * this->m_end;
        if (residue > 0)
        {
            this->m_end += abs(this->m_begin) + residue / this->m_height + 2;
        }
        else
        {
            this->m_end += abs(this->m_begin) + 1;
        }

        if (this->m_end >= 4*this->m_maxIndex)
        {
            this->m_end = 3*this->m_maxIndex;
        }
    }

    //
    // Painter begin
    //
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    // set background
    painter.fillRect(event->rect(), this->m_colorBase);

    // Loop start
    for (int j = this->m_begin; j <= this->m_end; ++j, this->m_y += this->m_height)
    {
        int i;
        if (this->m_repeat && j >= this->m_maxIndex)
        {
            i = j - this->m_maxIndex;

            if (j >= 2*this->m_maxIndex)
            {
                i -= this->m_maxIndex;
            }
            if (j >= 3*this->m_maxIndex)
            {
                i -= this->m_maxIndex;
            }
        }
        else
        {
            i = j;
        }

        painter.setBrush(Qt::NoBrush);
        // set font-color
        painter.setPen(this->m_colorText);
        painter.setFont(this->m_fontText);

        // Draw Topic
        if (this->m_indexTopic.indexOf(i) != -1)
        {
            painter.fillRect(0, this->m_y, this->width(), this->m_height, this->m_colorTopic);
            painter.setPen(this->m_colorText);
            // Increase piont size of the topic
//            painter.setFont(QFont(::GlobalFont, this->m_fontText.pointSize() + 0));
            if (this->m_alignmentFlag == Qt::AlignCenter)
            {
                painter.drawText(0, this->m_y, this->width(), this->m_height, Qt::AlignCenter, this->m_widgetNames[i]);
            }
            else
            {
                painter.drawText(this->m_height * 0.5, this->m_y, this->width(), this->m_height * 0.85, Qt::AlignVCenter | Qt::AlignBottom, this->m_widgetNames[i]);
            }

            //continue;
        }

        // Draw empty item
        if (this->m_indexEmpty.indexOf(i) != -1)
        {
            painter.fillRect(0, this->m_y, this->width(), this->m_height, this->m_colorEmpty);
        }
        else if (this->m_indexTopic.indexOf(i) == -1)
        {
            this->paintShape(painter, QRect(0, this->m_y, this->width(), this->m_height), i);
        }

        // Draw Icon - Text - Parameter - Line
        if (!this->m_widgetPixmap.isEmpty() && (this->m_widgetPixmap.size() == this->m_widgetNames.size()) && (this->m_indexTopic.indexOf(i) == -1))
        {
            if (!this->m_widgetNames.isEmpty())
            {
                // Draw Text
                painter.setFont(this->m_fontText);
                painter.setPen(this->m_colorText);
                painter.drawText(this->m_height + 50, this->m_y, this->width(), this->m_height, Qt::AlignVCenter, this->m_widgetNames[i]);

                // Draw Line
                if (this->m_repeat && this->m_drawline)
                {
                    painter.setPen(QPen(this->m_colorContrast, 3));
                    painter.drawLine(QLine(this->m_height + 50, this->m_y, this->width(), this->m_y));
                }
                else if (this->m_drawline && i != 0)
                {
                    painter.setPen(QPen(this->m_colorContrast, 3));
//                    if (this->m_indexTopic.indexOf(i-1) != -1)
//                    {
//                        painter.drawLine(QLine(0, this->m_y, this->width(), this->m_y));
//                    }
//                    else
//                    {
//                        painter.drawLine(QLine(this->m_height + 50, this->m_y, this->width(), this->m_y));
//                    }
                    painter.drawLine(QLine(0, this->m_y, this->width(), this->m_y));
                }
                painter.setPen(Qt::NoPen);
            }

            /// Draw Parameter
            if (i < this->m_widgetParameter.size())
            {
                if (!this->m_widgetParameter.at(i).isEmpty())
                {
                    painter.setFont(this->m_fontParamter);
                    painter.setPen(this->m_colorText);
                    painter.drawText(0, this->m_y, this->width() - this->m_height*0.5, this->m_height, Qt::AlignRight | Qt::AlignVCenter, this->m_widgetParameter[i]);
                }
            }

            if (!this->m_widgetPixmap[i].isNull())
            {
                this->paintPixmap(painter, i);
            }
            continue;
        }

        // Draw Text
        painter.setFont(this->m_fontText);
        painter.setPen(this->m_colorText);
        if (!this->m_widgetNames.isEmpty() && (this->m_indexTopic.indexOf(i) == -1))
        {
            if (this->m_alignmentFlag == Qt::AlignCenter)
            {
                painter.drawText(0, this->m_y, this->width(), this->m_height, Qt::AlignCenter, this->m_widgetNames[i]);
            }
            else
            {
                if (this->m_widgetSubText[i] != "")
                {
                    painter.drawText(this->m_height*0.5, this->m_y, this->width(), this->m_height*0.7, Qt::AlignVCenter, this->m_widgetNames[i]);
                    painter.setFont(QFont(::GlobalFont, this->m_fontText.pointSize() - 2));
                    painter.drawText(this->m_height*0.5, this->m_y+this->m_height*0.6, this->width(), this->m_height*0.3, Qt::AlignVCenter, this->m_widgetSubText[i]);
                    painter.setFont(this->m_fontText);
                }
                else
                {
                    painter.drawText(this->m_height*0.5, this->m_y, this->width(), this->m_height, Qt::AlignVCenter, this->m_widgetNames[i]);
                }
            }
        }

        // Draw Parameter
        if (i < this->m_widgetParameter.size())
        {
            if (!this->m_widgetParameter.at(i).isEmpty())
            {
                painter.setFont(this->m_fontParamter);
                painter.setPen(this->m_colorText);
                painter.drawText(0, this->m_y, this->width() - this->m_height*0.5, this->m_height, Qt::AlignRight | Qt::AlignVCenter, this->m_widgetParameter[i]);
            }
        }

        // Draw Line
        if (this->m_repeat && this->m_drawline)
        {
            painter.setPen(QPen(this->m_colorContrast, 3));
            painter.drawLine(QLine(0, this->m_y, this->width(), this->m_y));
        }
        //else if (this->m_drawline && i != 0 && this->m_indexNoline.indexOf(i) == -1)
        else if (this->m_drawline && i != 0)
        {
            painter.setPen(QPen(this->m_colorContrast, 3));
            painter.drawLine(QLine(0, this->m_y, this->width(), this->m_y));
        }
    }

    if (this->m_repeat && this->m_gradient)
    {
        QLinearGradient gradient(0, 0, 0, event->rect().height());
        gradient.setColorAt(0.0, this->m_colorBase);
        gradient.setColorAt(0.5 - this->m_transparency, this->m_colorBase);
        gradient.setColorAt(0.5, Qt::transparent);
        gradient.setColorAt(0.5 + this->m_transparency, this->m_colorBase);
        gradient.setColorAt(1.0, this->m_colorBase);
        painter.fillRect(event->rect(), gradient);
    }

    /// painter end
    painter.end();

    if (this->m_hideTimer)
    {
        this->m_hideTimer->start(10000);
    }
}

void
STouchFlickableList::paintPixmap(QPainter &painter,
                                 const int i)
{
    int t_margin = (int)((double)this->m_height * 0.15);
    QRect t_rect = QRect(20, this->m_y, this->m_height, this->m_height).marginsRemoved(QMargins(t_margin, t_margin, t_margin, t_margin));
    painter.drawPixmap(t_rect, this->m_widgetPixmap[i].scaled(t_rect.size(), Qt::IgnoreAspectRatio, Qt::FastTransformation));
}

void
STouchFlickableList::paintShape(QPainter &painter,
                                const QRect & rect,
                                const int i)
{
    switch (this->m_shape)
    {
    case Shape::None:
        break;

    case Shape::Round:
    {
        QPainterPath path;
        path.addRoundedRect(QRectF(rect.x() + 5, rect.y() + 3, rect.width() - 10, rect.height() - 6), (rect.height() - 6) * 0.5, (rect.height() - 6) * 0.5);
        painter.setPen(Qt::NoPen);
        painter.fillPath(path, this->m_colorContrast);
        painter.drawPath(path);
        if (i == this->m_highlightIndex)
        {
            QColor t_color = this->m_colorHighlight;
            t_color.setAlpha(this->m_frames - this->m_timeLine->currentFrame());
            QPainterPath path;
            path.addRoundedRect(QRectF(rect.x() + 5, rect.y() + 3, rect.width() - 10, rect.height() - 6), (rect.height() - 6) * 0.5, (rect.height() - 6) * 0.5);
            painter.setPen(Qt::NoPen);
            painter.fillPath(path, t_color);
            painter.drawPath(path);
        }
        else if (i == this->m_selectIndex)
        {
            QColor t_color = this->m_colorHighlight;
            t_color.setAlpha(this->m_timeLine->currentFrame());
            QPainterPath path;
            path.addRoundedRect(QRectF(rect.x() + 5, rect.y() + 3, rect.width() - 10, rect.height() - 6), (rect.height() - 6) * 0.5, (rect.height() - 6) * 0.5);
            painter.setPen(Qt::NoPen);
            painter.fillPath(path, t_color);
            painter.drawPath(path);
        }
        painter.setPen(this->m_colorText);
    }
        break;

    case Shape::Rounded:
    {
        QPainterPath path;
        path.addRoundedRect(QRectF(rect.x() + 5, rect.y() + 2, rect.width() - 10, rect.height() - 4), (rect.height() - 4) * 0.2, (rect.height() - 4) * 0.2);
        painter.setPen(Qt::NoPen);
        painter.fillPath(path, this->m_colorContrast);
        painter.drawPath(path);
        if (i == this->m_highlightIndex)
        {
            QColor t_color = this->m_colorHighlight;
            t_color.setAlpha(this->m_frames - this->m_timeLine->currentFrame());
            QPainterPath path;
            path.addRoundedRect(QRectF(rect.x() + 5, rect.y() + 2, rect.width() - 10, rect.height() - 4), (rect.height() - 4) * 0.2, (rect.height() - 4) * 0.2);
            painter.setPen(Qt::NoPen);
            painter.fillPath(path, t_color);
            painter.drawPath(path);
        }
        else if (i == this->m_selectIndex)
        {
            QColor t_color = this->m_colorHighlight;
            t_color.setAlpha(this->m_timeLine->currentFrame());
            QPainterPath path;
            path.addRoundedRect(QRectF(rect.x() + 5, rect.y() + 2, rect.width() - 10, rect.height() - 4), (rect.height() - 4) * 0.2, (rect.height() - 4) * 0.2);
            painter.setPen(Qt::NoPen);
            painter.fillPath(path, t_color);
            painter.drawPath(path);
        }
        painter.setPen(this->m_colorText);
    }
        break;

    case Shape::Rect:
    {
        painter.fillRect(rect.x() + 1, rect.y() + 1, rect.width() - 2, rect.height() - 2, this->m_colorContrast);
        if (i == this->m_highlightIndex)
        {
            QColor t_color = this->m_colorHighlight;
            t_color.setAlpha(this->m_frames - this->m_timeLine->currentFrame());
            painter.fillRect(rect.x() + 1, rect.y() + 1, rect.width() - 2, rect.height() - 2, t_color);
        }
        else if (i == this->m_selectIndex)
        {
            QColor t_color = this->m_colorHighlight;
            t_color.setAlpha(this->m_timeLine->currentFrame());
            painter.fillRect(rect.x() + 1, rect.y() + 1, rect.width() - 2, rect.height() - 2, t_color);
        }
    }
        break;

    case Shape::Full:
    {
        painter.fillRect(rect, m_colorContrast);
        if (i == this->m_highlightIndex)
        {
            QColor t_color = this->m_colorHighlight;
            t_color.setAlpha(this->m_frames - this->m_timeLine->currentFrame());
            painter.fillRect(rect, t_color);
        }
        else if (i == this->m_selectIndex)
        {
            QColor t_color = this->m_colorHighlight;
            t_color.setAlpha(this->m_timeLine->currentFrame());
            painter.fillRect(rect, t_color);
        }
    }
        break;
    }
}

QPixmap
STouchFlickableList::changePixmapColor(const QString & source,
                                       const QColor & color)
{
    QImage srcImage(source);
    QImage dstImage(srcImage.size(), QImage::Format_ARGB32_Premultiplied);
    dstImage.fill(color);
    QPainter painter(&dstImage);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setCompositionMode(QPainter::CompositionMode_Source);
    painter.fillRect(srcImage.rect(), Qt::transparent);
    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter.fillRect(srcImage.rect(), color);
    painter.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    painter.drawImage(0, 0, srcImage);
    painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);
    painter.fillRect(srcImage.rect(), Qt::transparent);

    return QPixmap::fromImage(dstImage);
}

int STouchFlickableList::index(QMouseEvent * event)
{
    int y = event->pos().y() + this->m_offset;

    if (this->m_repeat && y < 0)
    {
        y /= this->m_height;
        y += this->m_maxIndex - 1;
    }
    else if (this->m_repeat && y > this->m_height * this->m_maxIndex)
    {
        y /= this->m_height;
        y -= this->m_maxIndex;
    }
    else
    {
        y /= this->m_height;
    }

    return y;
}

void
STouchFlickableList::beginTimeLine(const int duration,
                                   const int frames)
{
    if (this->m_timeLine->state() == QTimeLine::NotRunning)
    {
        this->m_frames = frames;
        this->m_timeLine->setDuration(duration);
        this->m_timeLine->setFrameRange(0, frames);
        this->m_timeLine->start();
    }
}

void
STouchFlickableList::endTimeLine()
{
    if (this->m_timeLine->state() == QTimeLine::Running)
    {
        this->m_timeLine->setPaused(true);
        int t_duration = this->m_timeLine->currentTime() > 0 ? this->m_timeLine->currentTime() : 300;
        this->m_frames = this->m_timeLine->currentFrame() > 0 ? this->m_timeLine->currentFrame() : 255;
        this->m_timeLine->setDuration(t_duration);
        this->m_timeLine->setFrameRange(0, this->m_frames);
        this->m_timeLine->stop();
        this->m_timeLine->start();
    }
    else if (this->m_timeLine->state() == QTimeLine::NotRunning)
    {
        this->m_timeLine->start();
    }
    QTimer::singleShot(this->m_timeLine->duration(), this, &STouchFlickableList::slotUnsetHighlight);
}

void STouchFlickableList::mousePressEvent(QMouseEvent *event)
{
    SFlickable::handleMousePress(event);

    int i = this->index(event);
    if (this->m_delta.isNull())
    {
        this->m_selectIndex = i;

        this->beginTimeLine(200, 255);
    }

    if (event->isAccepted())
    {
        update();
        return;
    }

    this->m_delta = event->pos();

    event->accept();
    update();
}

void STouchFlickableList::mouseReleaseEvent(QMouseEvent *event)
{
    SFlickable::handleMouseRelease(event);

    this->m_delta = QPoint(0, 0);

    if (event->isAccepted())
    {
        return;
    }

    int i = this->index(event);
    this->m_index = i;

    if (i >= 0 && i < this->m_maxIndex)
    {
        if (i != this->m_highlightIndex)
        {
            if (this->m_check)
            {
                this->m_highlightIndex = i;

                this->endTimeLine();

                if (this->m_hide)
                {
                    this->m_gesture = true;

                    QTimer::singleShot(::GlobalTouchDelay, this, &STouchFlickableList::slotClose);
                }

                // Never replace i
                // A work around for event->isAccepted()
                // Lambda don't work on Debian
                //
                //QTimer::singleShot(::GlobalTouchDelay, [this, i] () { emit signalCurrentIndex(i); } );
                QTimer::singleShot(::GlobalTouchDelay, this, &STouchFlickableList::slotEmitCurrentIndex);
            }
        }
    }

    event->accept();
    update();
}

void STouchFlickableList::slotEmitCurrentIndex()
{
    if (this->m_index >= 0)
    {
        emit signalCurrentIndex(this->m_index);
    }
    if (!this->m_widgetNames.isEmpty())
    {
        emit signalCurrentContent(this->m_widgetNames[this->m_index]);
        emit signalCurrentIndexContent(this->m_index, this->m_widgetNames[this->m_index]);
    }

    if (this->m_close)
    {
        this->m_accept = true;
        this->close();
    }

    return;
}

void STouchFlickableList::mouseMoveEvent(QMouseEvent *event)
{
    SFlickable::handleMouseMove(event);

    this->m_delta = event->pos();

    this->m_selectIndex = -1;
    this->closeGesture(event);

    if (event->isAccepted())
    {
        return;
    }

    this->m_delta = QPoint(0, 0);

    event->accept();
    update();
}

void STouchFlickableList::closeGesture(QMouseEvent *event)
{
    // Work around QGestureEvent
    //
    if (this->m_hide)
    {
        if (this->m_edge == Qt::LeftEdge)
        {
            if (abs(this->m_delta.y() - event->pos().y()) < 15)
            {
                if (this->m_delta.x() - event->pos().x() > 30)
                {
                    this->m_delta = QPoint(0, 0);
                    QTimer::singleShot(0, this, &STouchFlickableList::slotClose);
                }
            }
            else
            {
                this->m_delta = QPoint(0, 0);
            }
        }
        else if (this->m_edge == Qt::RightEdge)
        {
            if (abs(this->m_delta.y() - event->pos().y()) < 15)
            {
                if (this->m_delta.x() - event->pos().x() < -20)
                {
                    this->m_delta = QPoint(0, 0);
                    QTimer::singleShot(0, this, &STouchFlickableList::slotClose);
                }
            }
            else
            {
                this->m_delta = QPoint(0, 0);
            }
        }
        else if (this->m_edge == Qt::BottomEdge)
        {
            if (abs(this->m_delta.x() - event->pos().x()) < 15)
            {
                if (this->m_delta.y() - event->pos().y() < -20)
                {
                    this->m_delta = QPoint(0, 0);
                    QTimer::singleShot(0, this, &STouchFlickableList::slotClose);
                }
            }
            else
            {
                //this->m_delta = QPoint(0, 0);
            }
        }
    }
}

void STouchFlickableList::focusOutEvent(QFocusEvent* event)
{
    if (event->type() == QEvent::FocusOut)
    {
        if (!this->m_gesture)
        {
            QTimer::singleShot(0, this, &STouchFlickableList::slotClose);
        }
        else
        {
            this->m_gesture = false;
        }
    }
}

void STouchFlickableList::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);

    if (this->m_animate)
    {
        /// Fade In & Move In
        this->showAnimation();
    }

    /// Hide after a while if not touched
    if (this->m_hide)
    {
        if (!this->m_hideTimer)
        {
            this->m_hideTimer = new QTimer;
            connect(this->m_hideTimer, &QTimer::timeout, this, &STouchFlickableList::slotClose);
        }
    }
}

void STouchFlickableList::hideEvent(QHideEvent *event)
{
    // Unset highlight & index
//    this->slotUnsetHighlight();

    // Disconnect hide timer
    if (this->m_hide)
    {
        if (this->m_hideTimer)
        {
            this->m_hideTimer->stop();
            disconnect(this->m_hideTimer, &QTimer::timeout, this, &STouchFlickableList::slotClose);

            delete this->m_hideTimer;
            this->m_hideTimer = nullptr;
        }

        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void STouchFlickableList::slotClose()
{
    int duration = 0;

    if (this->m_animate)
    {
        /// Fade Out & Move Out
        duration = this->closeAnimation();
    }

    if (this->m_hide)
    {
        QTimer::singleShot(duration, this, &STouchFlickableList::hide);
    }
}

int STouchFlickableList::showAnimation()
{    
    QPropertyAnimation *animationPos = new QPropertyAnimation(this, "pos", this);
    animationPos->setEasingCurve(QEasingCurve::Linear);
    if (this->m_edge == Qt::LeftEdge)
    {
        animationPos->setDuration(400);
        animationPos->setStartValue(QPoint(-this->width(), 0));
        animationPos->setEndValue(QPoint(0, 0));
    }
    else if (this->m_edge == Qt::RightEdge)
    {
        animationPos->setDuration(300);
        animationPos->setStartValue(QPoint(qApp->desktop()->width() + this->width(), 0));
        animationPos->setEndValue(QPoint(qApp->desktop()->width() - this->width(), 0));
    }
    else if (this->m_edge == Qt::BottomEdge)
    {
        animationPos->setDuration(200);
        animationPos->setStartValue(QPoint(0, qApp->desktop()->height() + this->height()));
        animationPos->setEndValue(QPoint(0, qApp->desktop()->height() - this->height()));
    }

    QPropertyAnimation *animationOpa = new QPropertyAnimation(this, "windowOpacity", this);
    animationOpa->setEasingCurve(QEasingCurve::InQuint);
    if (this->m_edge == Qt::LeftEdge)
    {
        animationOpa->setDuration(400);
        animationOpa->setStartValue(0.0);
        animationOpa->setEndValue(this->m_opacity);
    }
    else if (this->m_edge == Qt::RightEdge)
    {
        animationOpa->setDuration(300);
        animationOpa->setStartValue(0.0);
        animationOpa->setEndValue(this->m_opacity);
    }
    else if (this->m_edge == Qt::BottomEdge)
    {
        animationOpa->setDuration(300);
        animationOpa->setStartValue(0.0);
        animationOpa->setEndValue(this->m_opacity);
    }

    QParallelAnimationGroup *group = new QParallelAnimationGroup(this);
    group->addAnimation(animationPos);
    group->addAnimation(animationOpa);
    group->start(QPropertyAnimation::DeleteWhenStopped);

    return group->duration();
}

int STouchFlickableList::closeAnimation()
{
    QPropertyAnimation *animationPos = new QPropertyAnimation(this, "pos", this);
    animationPos->setEasingCurve(QEasingCurve::Linear);
    if (this->m_edge == Qt::LeftEdge)
    {
        animationPos->setDuration(400);
        animationPos->setStartValue(QPoint(0, 0));
        animationPos->setEndValue(QPoint(-this->width(), 0));
    }
    else if (this->m_edge == Qt::RightEdge)
    {
        animationPos->setDuration(300);
        animationPos->setStartValue(QPoint(qApp->desktop()->width() - this->width(), 0));
        animationPos->setEndValue(QPoint(qApp->desktop()->width() + this->width(), 0));
    }
    else if (this->m_edge == Qt::BottomEdge)
    {
        animationPos->setDuration(250);
        animationPos->setStartValue(QPoint(0, qApp->desktop()->height() - this->height()));
        animationPos->setEndValue(QPoint(0, qApp->desktop()->height() + this->height()));
    }

    QPropertyAnimation *animationOpa = new QPropertyAnimation(this, "windowOpacity", this);
    animationOpa->setEasingCurve(QEasingCurve::OutQuint);
    if (this->m_edge == Qt::LeftEdge)
    {
        animationOpa->setDuration(400);
        animationOpa->setStartValue(this->m_opacity);
        animationOpa->setEndValue(0.0);
    }
    else if (this->m_edge == Qt::RightEdge)
    {
        animationOpa->setDuration(300);
        animationOpa->setStartValue(this->m_opacity);
        animationOpa->setEndValue(0.0);
    }
    else if (this->m_edge == Qt::BottomEdge)
    {
        animationOpa->setDuration(200);
        animationOpa->setStartValue(this->m_opacity);
        animationOpa->setEndValue(0.0);
    }

    QParallelAnimationGroup *group = new QParallelAnimationGroup(this);
    group->addAnimation(animationPos);
    group->addAnimation(animationOpa);
    group->start(QPropertyAnimation::DeleteWhenStopped);

    return group->duration();
}

void STouchFlickableList::slotUnsetHighlight()
{
    this->m_highlightIndex = -1;
    this->m_selectIndex = -1;
    update();
}

void STouchFlickableList::setScrollOffset(const QPoint &offset)
{
    int y = offset.y();

    if (y != this->m_offset)
    {
        if (this->m_repeat)
        {
            this->m_offset = qBound(-1*(this->m_height * this->m_maxIndex), y, this->m_height * this->m_maxIndex);

            if (this->m_offset == -1*(this->m_height * this->m_maxIndex))
            {
                this->m_offset = 0;
            }
            else if (this->m_offset == this->m_height * this->m_maxIndex)
            {
                this->m_offset = 0;
            }
        }
        else
        {
            this->m_offset = qBound(0, y, this->m_height * this->m_maxIndex - height());
        }
        update();
    }
}

QPoint STouchFlickableList::scrollOffset() const
{
    return QPoint(0, this->m_offset);
}

void STouchFlickableList::setOffset(const int &offset)
{
    this->setScrollOffset(QPoint(0, offset));
}

void STouchFlickableList::setCheckable(const bool &checkable)
{
    this->m_check = checkable;
}

void STouchFlickableList::setRepeatable(const bool &repeatable, const bool &gradient, const double transparency)
{
    this->m_repeat = repeatable;
    this->m_gradient = gradient;
    /// The value should be in the range of 0.0 to 0.5, where 0.5 is fully transparent and 0.0 is fully linear opaque. By default, the opacity is 0.1.
    this->m_transparency = qBound(0.01, transparency, 0.49);
}

void STouchFlickableList::setEmpty()
{
    if (!this->m_widgetNames.isEmpty())
    {
        this->setText("");
    }
    if (!this->m_widgetParameter.isEmpty())
    {
        this->setParameter("");
    }
    if (!this->m_widgetPixmap.isEmpty())
    {
        this->setPixmap("");
    }
    this->m_indexEmpty.push_back(this->m_widgetNames.size()-1);
    this->m_indexNoline.push_back(this->m_widgetNames.size()-1);
    this->m_indexNoline.push_back(this->m_widgetNames.size());
}

void STouchFlickableList::setTopic(const QString &topic)
{
    this->setText(topic.toUpper());
    this->setParameter("");
    this->setPixmap("");
    this->m_indexTopic.push_back(this->m_widgetNames.size()-1);
}

void STouchFlickableList::setTopic(const QString &topic, const int &index)
{
//    this->setText(topic.toUpper(), index);
    this->setText(topic, index);
}

void STouchFlickableList::setText(const QString &text, const QString &sub)
{
    this->m_widgetNames.push_back(text);
    this->m_widgetSubText.push_back(sub);
    update();
}

void STouchFlickableList::setText(const QString &text, const int &index)
{
    if (index > this->m_widgetNames.size())
    {
        return;
    }

    this->m_widgetNames[index] = text;
    update();
}

void STouchFlickableList::setText(const QString &text, const QString &sub, const int &index)
{
    if (index > this->m_widgetNames.size())
    {
        return;
    }

    this->m_widgetNames[index] = text;
    this->m_widgetSubText[index] = sub;
    update();
}

QString STouchFlickableList::getText(const int &index) const
{
    if (index > this->m_widgetNames.size())
    {
        return "";
    }

    return this->m_widgetNames[index];
}

void STouchFlickableList::setParameter(const int &param)
{
    this->m_widgetParameter.push_back(QString::number(param));
}

void STouchFlickableList::setParameter(const uint64_t &param)
{
    this->m_widgetParameter.push_back(QString::number(param));
}
void STouchFlickableList::setParameter(const double &param)
{
    this->m_widgetParameter.push_back(QString::number(param));
}

void STouchFlickableList::setParameter(const QString &param)
{
    this->m_widgetParameter.push_back(param);
}

void STouchFlickableList::setParameter(const int &param, const int &index)
{
    if (index > this->m_widgetParameter.size())
    {
        return;
    }

    this->m_widgetParameter[index] = QString::number(param);
    update();
}

void STouchFlickableList::setParameter(const uint64_t &param, const int &index)
{
    if (index > this->m_widgetParameter.size())
    {
        return;
    }

    this->m_widgetParameter[index] = QString::number(param);
    update();
}

void STouchFlickableList::setParameter(const double &param, const int &index)
{
    if (index > this->m_widgetParameter.size())
    {
        return;
    }

    this->m_widgetParameter[index] = QString::number(param);
    update();
}

void STouchFlickableList::setParameter(const QString &param, const int &index)
{
    if (index > this->m_widgetParameter.size())
    {
        return;
    }

    this->m_widgetParameter[index] = param;
    update();
}

QString STouchFlickableList::getParameter(const int &index) const
{
    if (index > this->m_widgetParameter.size())
    {
        return "";
    }

    return this->m_widgetParameter[index];
}

int STouchFlickableList::getIndex() const
{
    return this->m_index;
}

void STouchFlickableList::setContent(const QString &text)
{
    int index = 0;
    foreach (QString str, this->m_widgetNames)
    {
        if (str.contains(text))
        {
            this->m_widgetNames[index] = text;
        }
        ++index;
    }
    update();
}

QString STouchFlickableList::getContent() const
{
    return this->m_widgetNames[this->m_index];
}

void STouchFlickableList::removeIndex(const int &index)
{
    this->m_widgetNames.removeAt(index);
    this->m_widgetSubText.removeAt(index);
    this->m_widgetParameter.removeAt(index);
    update();
}

void STouchFlickableList::setPixmap(const QString &pixmap)
{
    this->m_sourcePixmap.push_back(pixmap);
    this->m_widgetPixmap.push_back(this->changePixmapColor(pixmap, this->m_colorText));
}

void STouchFlickableList::setItemHeight(const int height)
{
    this->m_itemHeight = height;
    update();
}

void STouchFlickableList::setBaseColor(const QColor &color)
{
    this->m_colorBase = color;
    update();
}

QColor STouchFlickableList::getBackgroundColor() const
{
    return this->m_colorBase;
}

void STouchFlickableList::setEmptySlotColor(const QColor &color)
{
    this->m_colorEmpty = color;
    update();
}

void STouchFlickableList::setTopicBackgroundColor(const QColor &color)
{
    this->m_colorTopic = color;
    update();
}

void STouchFlickableList::setHighlightColor(const QColor &color)
{
    this->m_colorHighlight = color;
    update();
}

void STouchFlickableList::setContrastColor(const QColor &color)
{
    this->m_colorContrast = color;
    update();
}

void STouchFlickableList::setFontTextColor(const QColor &color)
{
    this->m_colorText = color;
    update();
}

void STouchFlickableList::setFontSize(const int &size, const bool bold)
{
    this->m_fontText.setPointSize(size);
    this->m_fontText.setBold(bold);
    update();
}

void STouchFlickableList::setFontSizeParamter(const int &size, const bool bold)
{
    this->m_fontParamter.setPointSize(size);
    this->m_fontParamter.setBold(bold);
    update();
}

void STouchFlickableList::resetFontWidth()
{
    this->m_fontWidth = 0;
}

void STouchFlickableList::setTextAlignment(const Qt::AlignmentFlag &flag)
{
    this->m_alignmentFlag = flag;
}

void STouchFlickableList::setOpacity(const double opacity)
{
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setAttribute(Qt::WA_NoSystemBackground);
    this->setAttribute(Qt::WA_OpaquePaintEvent);

    this->m_opacity = qBound(0.0, opacity, 1.0);
    this->setWindowOpacity(this->m_opacity);
    update();
}

double STouchFlickableList::getOpacity() const
{
    return this->m_opacity;
}

int STouchFlickableList::size() const
{
    int size = 0;
    if (!this->m_widgetNames.isEmpty())
    {
        size = this->m_widgetNames.size();
    }
    else if (!this->m_widgetPixmap.isEmpty())
    {
        size = this->m_widgetPixmap.size();
    }

    return size;
}

void STouchFlickableList::setHideable(const bool &hideable)
{
    if (hideable)
    {
        this->setObjectName("");
    }

    this->m_hide = hideable;
}

void STouchFlickableList::setCloseable(const bool &closeable)
{
    if (closeable)
    {
        this->setObjectName("");
    }

    this->m_close = closeable;
}

void STouchFlickableList::enableAnimation(const bool animate, const Qt::Edge &edge)
{
    this->m_animate = animate;
    this->m_edge = edge;
    update();
}

void STouchFlickableList::enableDrawLine(const bool draw)
{
    this->m_drawline = draw;
    update();
}

void
STouchFlickableList::setShape(const Shape &shape, const bool enable)
{
    this->m_shape = shape;
    this->m_shapeEnabled = enable;
    this->m_shapeDefault = this->m_shape;
    this->slotReadSettings();
    update();
}

bool STouchFlickableList::isAccepted()
{
    return this->m_accept;
}

void STouchFlickableList::resizeEvent(QResizeEvent *event)
{
    this->setScrollOffset(QPoint(0, 0));
    update();

    QWidget::resizeEvent(event);
}

void
STouchFlickableList::slotReadSettings()
{
    QSettings settings(::GlobalConfigFileSettings, QSettings::IniFormat);
    if (!QStringList(settings.allKeys().filter("custom/design", Qt::CaseInsensitive)).isEmpty())
    {
        settings.beginGroup("custom/design");
    }
    else if (!QStringList(settings.allKeys().filter("default/design", Qt::CaseInsensitive)).isEmpty())
    {
        settings.beginGroup("default/design");
    }

    this->m_colorBase = settings.value("color_base").toString();
    this->m_colorContrast = settings.value("color_contrast").toString();
    this->m_colorHighlight = settings.value("color_highlight").toString();

    QColor t_color = QColor(settings.value("color_text").toString());
    if (t_color != this->m_colorText)
    {
        this->m_colorText = settings.value("color_text").toString();
        // Update Widgets with the loaded settings
        this->updateWidget();
    }

    // TODO: Fix offset leackage after height change.
    this->m_itemHeight = settings.value("item_height").toInt();
//    this->setOffset(0);

    if (this->m_shapeEnabled)
    {
        int t_shape = settings.value("item_shape", 0).toInt();
        if (t_shape == 0)
        {
            this->m_shape = this->m_shapeDefault;
        }
        else
        {
            this->m_shape = static_cast<Shape>(t_shape);
        }
    }

    settings.sync();
    settings.endGroup();

    this->update();
}

void
STouchFlickableList::updateWidget()
{
    this->m_widgetPixmap.clear();
    foreach (QString src, this->m_sourcePixmap)
    {
        this->m_widgetPixmap.push_back(this->changePixmapColor(src, this->m_colorText));
    }
}

void STouchFlickableList::changeEvent(QEvent* event)
{
    switch (event->type())
    {
    case QEvent::LanguageChange:
        break;

    case QEvent::LocaleChange:
        break;

    default:
        break;
    }

    QWidget::changeEvent(event);
}
