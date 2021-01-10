/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
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

#include "SColorPicker.h"

#include <QPainter>
#include <QResizeEvent>
#include <QTouchEvent>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QRadialGradient>
#include <QConicalGradient>


SColorPicker::SColorPicker(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowFlags(this->windowFlags() | Qt::Window | Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_AcceptTouchEvents);
    this->setAutoFillBackground(true);
    this->setMouseTracking(true);
}

void SColorPicker::mousePressEvent(QMouseEvent *event)
{

    event->accept();
    update();
}

void SColorPicker::mouseMoveEvent(QMouseEvent *event)
{

    event->accept();
    update();
}

void SColorPicker::mouseReleaseEvent(QMouseEvent *event)
{

    event->accept();
    update();
}

QPixmap SColorPicker::drawHuePixmap()
{
    //    int m_value;
    //    QPoint m_pt;
    //    QColor m_color;
    //    int hue(const QPoint &pt) const;
    QPixmap pixmap;
    QConicalGradient conical;
    conical.setCenter(this->rect().center());
    QImage huecircle(this->size(), QImage::Format_ARGB32);
    huecircle.fill(::GlobalDarkGrayColor);
    QPainter phcircle(&huecircle);
    phcircle.setRenderHint(QPainter::Antialiasing);
    phcircle.setBrush(QBrush(conical));
    phcircle.setPen(this->palette().color(QPalette::Shadow));
    phcircle.drawEllipse(this->rect().center(), this->rect().center().ry()-2, this->rect().center().ry()-2);
    pixmap = QPixmap::fromImage(huecircle);

    // alpha gradient
    QRadialGradient rg(this->rect().center(), this->rect().center().ry()-2);
    for (float i = 0.0; i < 1.0; i += 0.1)
    {
        rg.setColorAt(i, QColor::fromHsv((int)(256*i), 255, 255));
    }
    rg.setColorAt(1, Qt::white);

    // alpha channel
    QImage ac(this->size(), QImage::Format_RGB32);
    ac.fill(Qt::transparent);
    QPainter acpainter(&ac);
    acpainter.setRenderHint(QPainter::Antialiasing);
    acpainter.setPen(Qt::NoPen);
    acpainter.setBrush(QBrush(rg));
    acpainter.drawEllipse(this->rect().center(), this->rect().center().ry()-2, this->rect().center().ry()-2);
    pixmap = QPixmap::fromImage(ac);

    // destination image
    QImage dst(this->size(), QImage::Format_ARGB32);
    dst.fill(Qt::transparent);
    QPainter dstp(&dst);
    dstp.setRenderHint(QPainter::Antialiasing);
    dstp.setBrush(QColor::fromHsv(100, 255, 255)); //m_value
    dstp.drawEllipse(this->rect().center(), this->rect().center().ry()-2, this->rect().center().ry()-2);
    dstp.setCompositionMode(QPainter::CompositionMode_SourceOver);
    dstp.drawPixmap(this->rect(), pixmap);
//    dstp.setCompositionMode(QPainter::CompositionMode_Source);
//    dstp.setBrush(Qt::NoBrush);
//    dstp.setPen(Qt::NoPen);
//    dstp.drawEllipse(rect());
    pixmap = QPixmap::fromImage(dst);

    return pixmap;
}

void SColorPicker::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, this->drawHuePixmap());
    painter.end();
}

void SColorPicker::resizeEvent(QResizeEvent *)
{
}

void SColorPicker::timerEvent(QTimerEvent *event)
{
    /// Blank canvas
    if (event->timerId() == this->blankTimer.timerId())
    {
        this->blankTimer.stop();
    }
}
