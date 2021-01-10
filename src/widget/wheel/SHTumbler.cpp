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

#include "SHTumbler.h"

#include <QtWidgets>
#include <QPainterPath>

#define WHEEL_SCROLL_OFFSET 50000.0


SHAbstractWheelWidget::SHAbstractWheelWidget(bool touch, QWidget *parent)
    : QWidget(parent)
    , m_currentItem(0)
    , m_itemOffset(0)
{
    QScroller::grabGesture(this, touch ? QScroller::TouchGesture : QScroller::LeftMouseButtonGesture);
}

SHAbstractWheelWidget::~SHAbstractWheelWidget()
{ }

int
SHAbstractWheelWidget::currentIndex() const
{
    return this->m_currentItem;
}

void
SHAbstractWheelWidget::setCurrentIndex(int index)
{
    if (index >= 0 && index < itemCount())
    {
        this->m_currentItem = index;
        this->m_itemOffset = 0;
        this->update();
    }
}

void
SHAbstractWheelWidget::setFontSizeParamter(const int &size)
{
    this->m_fontSizeParamter = size;
    this->update();
}

void
SHAbstractWheelWidget::setBaseColor(const QColor &color)
{
    this->m_colorBase = color;
    this->update();
}

void
SHAbstractWheelWidget::setContrastColor(const QColor &color)
{
    this->m_colorContrast = color;
    this->update();
}

void
SHAbstractWheelWidget::setTextColor(const QColor &color)
{
    this->m_colorText = color;
    this->update();
}

bool
SHAbstractWheelWidget::event(QEvent *event)
{
    switch (event->type())
    {
    case QEvent::ScrollPrepare:
    {
        // We set the snap positions as late as possible so that we are sure
        // we get the correct itemHeight
       QScroller *scroller = QScroller::scroller(this);
       scroller->setSnapPositionsX(WHEEL_SCROLL_OFFSET, itemHeight());

       QScrollerProperties properties = scroller->scrollerProperties();
       properties.setScrollMetric(QScrollerProperties::AxisLockThreshold, 0.66);
       properties.setScrollMetric(QScrollerProperties::ScrollingCurve, QEasingCurve(QEasingCurve::OutExpo));
       properties.setScrollMetric(QScrollerProperties::DecelerationFactor, 0.05);
       properties.setScrollMetric(QScrollerProperties::MaximumVelocity, 0.635);
       properties.setScrollMetric(QScrollerProperties::OvershootDragResistanceFactor, 0.33);
       properties.setScrollMetric(QScrollerProperties::OvershootScrollDistanceFactor, 0.33);
       properties.setScrollMetric(QScrollerProperties::SnapPositionRatio, 0.93);
       properties.setScrollMetric(QScrollerProperties::DragStartDistance, 0.001);
       scroller->setScrollerProperties(properties);

       QScrollPrepareEvent *se = static_cast<QScrollPrepareEvent *>(event);
       se->setViewportSize(QSizeF(this->size()));
       // we claim a huge scrolling area and a huge content position and
       // hope that the user doesn't notice that the scroll area is restricted
       se->setContentPosRange(QRectF(0.0, 0.0, WHEEL_SCROLL_OFFSET * 2, 0.0));
       //se->setContentPos(QPointF(0.0, WHEEL_SCROLL_OFFSET + this->m_currentItem * itemHeight() + this->m_itemOffset));
       se->setContentPos(QPointF(WHEEL_SCROLL_OFFSET + itemCount()*itemHeight() + this->m_currentItem*itemHeight() + this->m_itemOffset, 0.0));
       se->accept();
       return true;
    }

    case QEvent::Scroll:
    {
        QScrollEvent *se = static_cast<QScrollEvent *>(event);

        qreal x = se->contentPos().x();
        int iy = x - (WHEEL_SCROLL_OFFSET + itemCount()*itemHeight());
        int ih = itemHeight();
        // -- calculate the current item position and offset and redraw the widget
        int ic = itemCount();

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
SHAbstractWheelWidget::lensDeform(const QPainterPath &source,
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
SHAbstractWheelWidget::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    int w = width();
    int h = height();
    int iH = itemHeight();
    int iC = itemCount();

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    /// set background
    painter.fillRect(event->rect(), this->m_colorContrast);
    /// draw a transparent bar over the center
    painter.fillRect( QRect( 0, h/2 - iH/2, w, iH ), ::GlobalColorHighlight.toRgb());

    /// paint the items
    painter.setFont(QFont(::GlobalFont, this->m_fontSizeParamter));
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

            paintItem(&painter, itemNum, QRect(0, h/2 +i*iH - this->m_itemOffset - iH/2, w, iH));
        }
    }

    /// linear gradient brush
    QLinearGradient grad(0.5, 0, 0.5, 1.0);
    grad.setColorAt(0.0, this->m_colorContrast);
    grad.setColorAt(0.4, Qt::transparent);
    grad.setColorAt(0.6, Qt::transparent);
    grad.setColorAt(1.0, this->m_colorContrast);
    grad.setCoordinateMode(QGradient::ObjectBoundingMode);
    painter.fillRect(event->rect(), grad);

    /// paint end
    painter.end();
}

/*!
    Rotates the wheel widget to a given index.
    You can also give an index greater than itemCount or less than zero in which
    case the wheel widget will scroll in the given direction and end up with
    (index % itemCount)
*/
void
SHAbstractWheelWidget::scrollTo(int index)
{
    QScroller *scroller = QScroller::scroller(this);

    scroller->scrollTo(QPointF(0, WHEEL_SCROLL_OFFSET + index * itemHeight()), 5000);
}

/*!
    \class SHTumbler
    \brief The SHTumbler class is an implementation of the SHAbstractWheelWidget class that draws QStrings as items.
    \sa SHAbstractWheelWidget
*/

SHTumbler::SHTumbler(bool touch)
    : SHAbstractWheelWidget(touch)
{
    this->setWindowState(Qt::WindowFullScreen);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

QStringList SHTumbler::items() const
{
    return this->m_items;
}

void SHTumbler::setItems(const QStringList &items)
{
    this->m_items = items;
    if (this->m_currentItem >= items.count())
    {
        this->m_currentItem = items.count() - 1;
    }
    update();
}

QString SHTumbler::currentContent() const
{
    return this->m_items.at(this->m_currentItem);
}

void SHTumbler::setCurrentContent(const QString &content)
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

QSize SHTumbler::sizeHint() const
{
    // determine font size
    QFontMetrics fm(font());

    return QSize(fm.width("m") * 10 + 6, fm.height() * 4 + 6);
}

QSize SHTumbler::minimumSizeHint() const
{
    QFontMetrics fm(font());

    return QSize(fm.width("m") * 5 + 6, fm.height() * 3 + 6);
}

void SHTumbler::paintItem(QPainter* painter, int index, const QRect &rect)
{
    painter->drawText(rect, Qt::AlignCenter, this->m_items.at(index));
}

int SHTumbler::itemHeight() const
{
    QFontMetrics fm(font());
    return fm.height() * 4;
}

int SHTumbler::itemCount() const
{
    return this->m_items.count();
}
