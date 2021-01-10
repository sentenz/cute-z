/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "SVTumbler.h"

#include <QtWidgets>
#include <QIcon>
#include <QPixmap>
#include <QPainterPath>
#include <QConicalGradient>
#include <QPen>
#include <QBrush>
#include <QTimeLine>
#include <QTimer>
#include <QMouseEvent>
#include <QDebug>

#define WHEEL_SCROLL_OFFSET 50000.0


SVAbstractWheelWidget::SVAbstractWheelWidget(bool touch, QWidget *parent)
    : QWidget(parent)
    , m_currentItem(0)
    , m_itemOffset(0)
    , m_touch(touch)
{
//    QScroller::grabGesture(this, touch ? QScroller::TouchGesture : QScroller::LeftMouseButtonGesture);
    if (touch)
    {
        QScroller::grabGesture(this, QScroller::LeftMouseButtonGesture);
    }
    this->restyleUI();
}

SVAbstractWheelWidget::~SVAbstractWheelWidget()
{ }

int
SVAbstractWheelWidget::currentIndex() const
{
    return this->m_currentItem;
}

void
SVAbstractWheelWidget::setCurrentIndex(int index)
{
    if (index >= 0 && index < itemCount())
    {
        this->m_currentItem = index;
        this->m_itemOffset = 0;
        this->update();
    }
}

void
SVAbstractWheelWidget::setFontSize(const int &size)
{
    this->m_fontSize = size;
    this->update();
}

bool
SVAbstractWheelWidget::event(QEvent *event)
{
    switch (event->type())
    {
    case QEvent::ScrollPrepare:
    {
//        setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        // We set the snap positions as late as possible so that we are sure
        // we get the correct itemHeight
       QScroller *scroller = QScroller::scroller(this);
       scroller->setSnapPositionsY(WHEEL_SCROLL_OFFSET, this->itemHeight());

       QScrollerProperties properties = scroller->scrollerProperties();
       properties.setScrollMetric(QScrollerProperties::AxisLockThreshold, 0.66);
       properties.setScrollMetric(QScrollerProperties::ScrollingCurve, QEasingCurve(QEasingCurve::Linear));
       properties.setScrollMetric(QScrollerProperties::DecelerationFactor, 0.30);
       properties.setScrollMetric(QScrollerProperties::DragVelocitySmoothingFactor, 0.70);
       properties.setScrollMetric(QScrollerProperties::MaximumVelocity, 0.150);
       properties.setScrollMetric(QScrollerProperties::OvershootDragResistanceFactor, 0.33);
       properties.setScrollMetric(QScrollerProperties::OvershootScrollDistanceFactor, 0.33);
       properties.setScrollMetric(QScrollerProperties::SnapPositionRatio, 0.33);
       properties.setScrollMetric(QScrollerProperties::DragStartDistance, 0.001);
       scroller->setScrollerProperties(properties);

       QScrollPrepareEvent *se = static_cast<QScrollPrepareEvent *>(event);
       se->setViewportSize(QSizeF(size()));
       // we claim a huge scrolling area and a huge content position and
       // hope that the user doesn't notice that the scroll area is restricted
       se->setContentPosRange(QRectF(0.0, 0.0, 0.0, WHEEL_SCROLL_OFFSET * 2));
       if (this->m_touch)
       {
           se->setContentPos(QPointF(0.0, WHEEL_SCROLL_OFFSET + this->itemCount()*this->itemHeight() + this->m_currentItem*this->itemHeight() + this->m_itemOffset));
       }
       else
       {
           se->setContentPos(QPointF(0.0, WHEEL_SCROLL_OFFSET + this->m_currentItem * itemHeight() + this->m_itemOffset));
       }
       se->accept();
       return true;
    }

    case QEvent::Scroll:
    {
        QScrollEvent *se = static_cast<QScrollEvent *>(event);

        qreal y = se->contentPos().y();
        int iy = y - (WHEEL_SCROLL_OFFSET + this->itemCount()*this->itemHeight());
        int ih = this->itemHeight();
        // -- calculate the current item position and offset and redraw the widget
        int ic = this->itemCount();

        if (ic > 0)
        {
            this->m_currentItem = iy / ih % ic;
            this->m_itemOffset = iy % ih;

            // take care when scrolling backwards. Modulo returns negative numbers
            if (m_itemOffset < 0)
            {
                this->m_itemOffset += ih;
                this->m_currentItem--;
            }

            if (this->m_currentItem < 0)
            {
                this->m_currentItem += ic;
            }

            emit stopped(this->m_currentItem);
        }
        // -- repaint
        update();

        se->accept();
        return true;
    }

    default:
        return QWidget::event(event);
    }

    return true;
}

QPainterPath
SVAbstractWheelWidget::lensDeform(const QPainterPath &source,
                                  const QPointF &offset)
{
    QPainterPath path;
//    path.addPath(source);

//    qreal flip = m_intensity / qreal(100);

//    for (int i=0; i<path.elementCount(); ++i) {
//        const QPainterPath::Element &e = path.elementAt(i);

//        qreal x = e.x + offset.x();
//        qreal y = e.y + offset.y();

//        qreal dx = x - m_pos.x();
//        qreal dy = y - m_pos.y();
//        qreal len = m_radius - qSqrt(dx * dx + dy * dy);

//        if (len > 0) {
//            path.setElementPositionAt(i,
//                                      x + flip * dx * len / m_radius,
//                                      y + flip * dy * len / m_radius);
//        } else {
//            path.setElementPositionAt(i, x, y);
//        }

//    }

    return path;
}

void
SVAbstractWheelWidget::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    int w = this->width();
    int h = this->height();
    int iH = this->itemHeight();
    int iC = this->itemCount();

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    // set background
    painter.fillRect(event->rect(), this->m_colorContrast);
    // draw a transparent bar over the center
    if (this->m_highlight)
    {
        painter.fillRect(QRect( 0, h/2 - iH/2, w, iH ), QBrush(m_colorHighlight));
    }
    else
    {
        painter.fillRect(QRect( 0, h/2 - iH/2, w, iH ), QBrush(m_colorContrast));
    }

    // paint the items
    painter.setFont(QFont(::GlobalFont, this->m_fontSize));
    painter.setPen(this->m_colorText);
    painter.setClipRect(QRect(0, 0, w, h));

    if (iC > 0)
    {
        this->m_itemOffset = this->m_itemOffset % iH;

        for (int i = -h/2/iH; i <= h/2/iH+1; i++)
        {
            int itemNum = this->m_currentItem + i;
            while (itemNum < 0)
            {
                itemNum += iC;
            }
            while (itemNum >= iC)
            {
                itemNum -= iC;
            }

            this->paintItem(&painter, itemNum, QRect(0, h/2 +i*iH - this->m_itemOffset - iH/2, w, iH));
        }
    }

    // linear gradient brush
    QLinearGradient grad(0.5, 0, 0.5, 1.0);
    grad.setColorAt(0.0, this->m_colorContrast);
    grad.setColorAt(0.4, Qt::transparent);
    grad.setColorAt(0.6, Qt::transparent);
    grad.setColorAt(1.0, this->m_colorContrast);
    grad.setCoordinateMode(QGradient::ObjectBoundingMode);
    painter.fillRect(event->rect(), grad);

    // paint end
    painter.end();
}

/*!
    Rotates the wheel widget to a given index.
    You can also give an index greater than itemCount or less than zero in which
    case the wheel widget will scroll in the given direction and end up with
    (index % itemCount)
*/
void
SVAbstractWheelWidget::scrollToIndex(const int index, const int scrollTime)
{
    if (index != this->currentIndex())
    {
        if (!this->m_timer.isActive())
        {
            this->m_timer.setSingleShot(true);
            this->m_timer.start(scrollTime);
            QScroller * scroller = QScroller::scroller(this);
            scroller->scrollTo(QPointF(0, WHEEL_SCROLL_OFFSET + index * itemHeight()), scrollTime);
        }
    }
}

void
SVAbstractWheelWidget::restyleUI()
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
    this->update();
}

void
SVAbstractWheelWidget::highlight(const bool highlight)
{
    this->m_highlight = highlight;
}

void
SVAbstractWheelWidget::changeEvent(QEvent * event)
{
    switch (event->type())
    {
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

/*!
    \class SVTumbler
    \brief The SVTumbler class is an implementation of the SVAbstractWheelWidget class that draws QStrings as items.
    \sa SVAbstractWheelWidget
*/

SVTumbler::SVTumbler(QWidget *parent)
    : SVAbstractWheelWidget(true, parent)
{
    this->setWindowState(Qt::WindowFullScreen);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->setupWidget();
    this->setConnect();
    this->restyleUI();
}

SVTumbler::SVTumbler(bool touch, QWidget *parent)
    : SVAbstractWheelWidget(touch, parent)
{
    this->setWindowState(Qt::WindowFullScreen);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->setupWidget();
    this->setConnect();
}

void
SVTumbler::setupWidget()
{
    this->m_timeLine = new QTimeLine(500, this);
    this->m_timeLine->setLoopCount(2);
    this->m_timeLine->setFrameRange(0, 200);
    this->m_frameFactor = 1.0/200.0;
}

void
SVTumbler::setConnect()
{
    connect(this->m_timeLine, SIGNAL(frameChanged(int)), this, SLOT(update()));
    connect(this->m_timeLine, &QTimeLine::finished, [=] {
        this->m_pressed = false;
        emit signalCurrentIndex(this->m_currentItem);
        if (!this->m_items.isEmpty() & !(this->m_currentItem >= this->m_items.count()))
        {
            emit signalCurrentContent(this->m_items.at(this->m_currentItem));
            emit signalCurrentIndexContent(this->m_currentItem, this->m_items.at(this->m_currentItem));
        }
    });
}

QStringList
SVTumbler::items() const
{
    return this->m_items;
}

void
SVTumbler::setItems(const QStringList &items)
{
    this->m_items = items;
    if (this->m_currentItem >= items.count())
    {
        this->m_currentItem = items.count() - 1;
    }
    update();
}

QStringList
SVTumbler::icons() const
{
    return this->m_icons;
}

void
SVTumbler::setIcons(const QStringList &icons)
{
    this->m_icons = icons;
    this->m_listPixmap.clear();
    foreach (QString src, this->m_icons)
    {
        this->m_listPixmap.push_back(this->changePixmapColor(src, this->m_colorText));
    }

    if (this->m_currentItem >= icons.count())
    {
        this->m_currentItem = icons.count() - 1;
    }
    update();
}

QString
SVTumbler::currentContent() const
{
    return this->m_items.at(this->m_currentItem);
}

void
SVTumbler::setCurrentContent(const QString &content)
{
    int index = 0;
    foreach (const QString& var, this->m_items)
    {
        if (var == content)
        {
            this->setCurrentIndex(index);
            return;
        }
        ++index;
    }
}

void
SVTumbler::scrollToContent(const QString content, const int scrollTime)
{
    if (!this->m_timer.isActive() && content.compare(this->currentContent()))
    {
        if (this->m_items.isEmpty())
        {
            return;
        }

        // Scroll down
        if (content.toDouble() < this->currentContent().toDouble())
        {
            this->setItems(QStringList() << this->currentContent() << content);
            this->setCurrentIndex(0);
            this->scrollToIndex(1, scrollTime);
        }
        else // Scroll up
        {
            this->setItems(QStringList() << content << this->currentContent());
            this->setCurrentIndex(1);
            this->scrollToIndex(0, scrollTime);
        }
    }
}

void
SVTumbler::setEffect(const Effect &effect)
{
    this->m_effect = effect;
    update();
}

void
SVTumbler::setStyle(const Style &style)
{
    this->m_style = style;
    update();
}

void
SVTumbler::setAlignment(const Qt::AlignmentFlag &alignment)
{
    this->m_alignment = alignment;
}

QSize
SVTumbler::sizeHint() const
{
    // determine font size
    QFontMetrics fm(font());

    return QSize(fm.width("m") * 10 + 6, fm.height() * 4 + 6);
}

QSize
SVTumbler::minimumSizeHint() const
{
    QFontMetrics fm(font());

    return QSize(fm.width("m") * 5 + 6, fm.height() * 3 + 6);
}


int
SVTumbler::itemHeight() const
{
    QFontMetrics fm(font());
    if (this->m_itemHeight == 0)
    {
        return fm.height() * 4;
    }
    else
    {
        return fm.height() + this->m_itemHeight;
    }
}

void
SVTumbler::setItemHeight(const int height)
{
    this->m_itemHeight = height;
}

int
SVTumbler::itemCount() const
{
    int t_count = 0;
    t_count = t_count < this->m_icons.count() ? this->m_icons.count() : t_count;
    t_count = t_count < this->m_items.count() ? this->m_items.count() : t_count;

    return t_count;
}

void
SVTumbler::enableHighlight(const bool highlight)
{
    this->highlight(highlight);
    this->m_highlight = highlight;
}

void
SVTumbler::mousePressEvent(QMouseEvent *event)
{
    if (event->isAccepted())
    {
        return;
    }

    event->accept();
    update();
}
void
SVTumbler::mouseReleaseEvent(QMouseEvent *event)
{
    int w = this->width();
    int h = this->height();
    int iH = this->itemHeight();
    if (QRect( 0, h/2 - iH/2, w, iH ).contains(event->pos()))
    {
        this->m_pressed = true;
        this->m_timeLine->start();
    }

    if (event->isAccepted())
    {
        return;
    }

    event->accept();
    update();
}

void
SVTumbler::paintItem(QPainter* painter,
                     int index,
                     const QRect &rect)
{
    this->paintEffect(painter, index ,rect);
    this->paintPixmap(painter, index, rect);
    this->paintText(painter, index, rect);
}

void
SVTumbler::paintPixmap(QPainter* painter,
                          int index,
                          const QRect &rect)
{
    /// Draw Pixmap
    /// Note: Resolution of QIcon().paint() is much better than QPaint::drawPixmap()
    if (!this->m_icons.isEmpty())
    {
        if (index >= this->m_icons.count())
        {
            return;
        }

        if (!this->m_icons.at(index).isEmpty())
        {
            switch (this->m_style)
            {
            case Style::None:
            {
                painter->drawPixmap(rect, this->m_listPixmap[index].scaled(QSize(rect.height(), rect.height()), Qt::IgnoreAspectRatio, Qt::FastTransformation));

                break;
            }

            case Style::TextUnderIcon:
            {
                QRectF t_rect = rect.adjusted(0, -rect.height() * 0.1, 0, -rect.height() * 0.1);
                painter->drawPixmap(t_rect.center().rx()-t_rect.height()*0.5, t_rect.y(), t_rect.height(), t_rect.height(), this->m_listPixmap[index].scaled(QSize(t_rect.height(), t_rect.height()), Qt::IgnoreAspectRatio, Qt::FastTransformation));
                break;
            }

            default:
                break;
            }
        }
    }
}

void
SVTumbler::paintText(QPainter* painter,
                     int index,
                     const QRect &rect)
{
    if (!this->m_items.isEmpty())
    {
        if (index >= this->m_items.count())
        {
            return;
        }

        if (!this->m_items.at(index).isEmpty())
        {
            switch (this->m_style)
            {
            case Style::None:
                painter->setPen(this->m_colorText);
                painter->drawText(rect, this->m_alignment, this->m_items.at(index));
                break;

            case Style::TextUnderIcon:
                painter->setPen(this->m_colorText);
                painter->drawText(rect.adjusted(0, rect.height() * 0.15, 0, rect.height() * 0.15), this->m_alignment, this->m_items.at(index));
                break;

            default:
                break;
            }
        }
    }
}

void
SVTumbler::paintEffect(QPainter* painter,
                       int index,
                       const QRect &rect)
{
    switch (this->m_effect)
    {
    case Effect::None:
        break;

    case Effect::GradientArc:
        QRect t_rect = rect.adjusted(20, 20, -20, -20);

        QConicalGradient gradient;
        gradient.setCenter(rect.center());
        gradient.setColorAt(0, this->m_colorText);
        gradient.setColorAt(1, this->m_colorText);

        int t_width = 3;
        int arcLengthApproximation = t_width + t_width / 3;
        int loadingAngle = 360;

        // Load animation on pressed event.
        if (this->m_pressed & (index == this->m_currentItem))
        {
            qreal frame = this->m_timeLine->currentFrame();
            gradient.setAngle(loadingAngle * frame * this->m_frameFactor);
            gradient.setColorAt(0, this->m_colorText);
            gradient.setColorAt(0.5, this->m_colorHighlight);
            gradient.setColorAt(1, this->m_colorText);
        }

        QPen pen(QBrush(gradient), t_width);
        pen.setCapStyle(Qt::RoundCap);
        painter->setPen(pen);
        painter->drawArc(t_rect.center().rx()-t_rect.height()*0.5, t_rect.y(), t_rect.height(), t_rect.height(), 90 * 16 - arcLengthApproximation, -loadingAngle * 16);
        break;
    }
}

QPixmap
SVTumbler::changePixmapColor(const QString &source, const QColor &color)
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

void
SVTumbler::restyleUI()
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
        this->m_listPixmap.clear();
        foreach (QString src, this->m_icons)
        {
            this->m_listPixmap.push_back(this->changePixmapColor(src, this->m_colorText));
        }
    }
    if (this->m_colorHighlight != ::GlobalColorCustomHighlight)
    {
        this->m_colorHighlight = ::GlobalColorCustomHighlight;
    }
    this->update();
}

void
SVTumbler::changeEvent(QEvent * event)
{
    switch (event->type())
    {
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
