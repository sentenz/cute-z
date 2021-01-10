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

#include "SCanvas.h"
#include "../build/SGlobal.h"
#include "../neuron/mnist/sneuronmnist.h"

#include <QtWidgets>
#include <QImage>
#include <math.h>


SCanvas::SCanvas(QWidget *parent)
    : QWidget(parent)
    , m_alphaChannelValuator(TangentialPressureValuator)
    , m_colorSaturationValuator(NoValuator)
    , m_lineWidthValuator(PressureValuator)
    , m_color(Qt::white)
    , m_brush(m_color)
    , m_pen(m_brush, 14.0, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin)
    , m_deviceDown(false)
{
    this->setWindowFlags(this->windowFlags() | Qt::Window | Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_AcceptTouchEvents);
    this->setAutoFillBackground(true);
    this->setMouseTracking(true);

    this->initPixmap();
}

void SCanvas::initPixmap()
{
    QPixmap newPixmap = QPixmap(this->width(), this->height());
    newPixmap.fill(Qt::black);
    QPainter painter(&newPixmap);
    if (!this->m_pixmap.isNull())
    {
        painter.drawPixmap(0, 0, this->m_pixmap);
        painter.fillRect(this->rect(), Qt::black);
    }
    painter.end();
    this->m_pixmap = newPixmap;
    update();
}

bool SCanvas::save(const QString &file)
{
    //QString fileName = QFileDialog::getSaveFileName(this, tr("Save Picture"), path);

    bool saved = this->saveImage(file);
    if (!saved)
    {
        printf("SCanvas: Error Saving Picture, could not save the image\n");
    }

    return saved;
}

bool SCanvas::saveImage(const QString &file)
{
    bool saved = false;

    QImage image = this->zoom(this->m_pixmap);
    if (!image.isNull())
    {
        saved = this->padding(image, image.height() * 0.4, Qt::black).save(file);
    }

    return saved;
}

bool SCanvas::load(const QString &file)
{
    //QString fileName = QFileDialog::getOpenFileName(this, tr("Open Picture"), QDir::currentPath());

    bool loaded = this->loadImage(file);
    if (!loaded)
    {
        printf("SCanvas: Error Opening Picture, could not open picture\n");
    }

    return loaded;
}

bool SCanvas::loadImage(const QString &file)
{
    bool loaded = false;

    if (!file.isEmpty())
    {
        this->m_pixmap.load(file);
    }

    if (loaded)
    {
        update();
    }

    return loaded;
}

QImage SCanvas::zoom(QPixmap &pixmap)
{
    QImage image = pixmap.toImage();

    QColor color;
    int y = 0,  x = 0;
    int y1 = -1, y2 = -1;
    int x1 = image.width()-1, x2 = -1;

    for (int i = 0; i < image.height(); i++)
    {
        for (int j = 0; j < image.width(); j++)
        {
            color = image.pixel(j, i);

            if (y1 < 0 && color.value() != 0)
            {
                y1 = y;
            }

            if (x1 > x && color.value() != 0)
            {
                x1 = x+1;
            }

            if (y2 < y && color.value() != 0)
            {
                y2 = y;
            }

            if (x2 < x && color.value() != 0)
            {
                x2 = x;
            }

            if (x++ == image.width()-1)
            {
                j = 0;
                ++y;
                x = 0;
            }
        }
    }

    return image.copy(x1, y1, x2-x1, y2-y1);
}

template <typename T>
QImage SCanvas::padding(const QImage &image, int pad, T value)
{
    QImage padded{image.width() + 2*pad, image.height() + 2*pad, image.format()};
    padded.fill(value);

    QPainter p{&padded};
    p.drawImage(QPoint(pad, pad), image);

    return padded;
}

void SCanvas::mousePressEvent(QMouseEvent *event)
{
    this->blankTimer.stop();

    if (!this->m_deviceDown)
    {
        this->m_deviceDown = true;
        lastPoint.pos = event->pos();
    }

    event->accept();
    update();
}

void SCanvas::mouseMoveEvent(QMouseEvent *event)
{
    if (this->m_deviceDown)
    {
        this->updateBrush(event);
        QPainter painter(&this->m_pixmap);
        this->paintPixmap(painter, event);
        this->lastPoint.pos = event->pos();
    }

    event->accept();
    update();
}

void SCanvas::mouseReleaseEvent(QMouseEvent *event)
{
    this->blankTimer.start(700, this);

    if (this->m_deviceDown && event->buttons() == Qt::NoButton)
    {
        this->m_deviceDown = false;
    }

    event->accept();
    update();
}

void SCanvas::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, this->m_pixmap);
    painter.end();
}

void SCanvas::paintPixmap(QPainter &painter, QMouseEvent *event)
{
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    this->m_brush.setStyle(Qt::SolidPattern);
    painter.setPen(QPen(Qt::white, 14.0, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.setBrush(this->m_brush);
    QPolygonF poly;
    poly << this->lastPoint.pos;
    poly << event->pos();
    painter.drawConvexPolygon(poly);
    painter.end();

    //    switch (event) {
    //    case QTabletEvent::Airbrush:
    //    {
    //        painter.setPen(Qt::NoPen);
    //        QRadialGradient grad(lastPoint.pos, this->m_pen.widthF() * 10.0);
    //        QColor color = this->m_brush.color();
    //        color.setAlphaF(color.alphaF() * 0.25);
    //        grad.setColorAt(0, this->m_brush.color());
    //        grad.setColorAt(0.5, Qt::transparent);
    //        painter.setBrush(grad);
    //        qreal radius = grad.radius();
    //        painter.drawEllipse(event->pos(), radius, radius);
    //    }
    //        break;
    //    case QTabletEvent::RotationStylus:
    //    {
    //        this->m_brush.setStyle(Qt::SolidPattern);
    //        painter.setPen(Qt::NoPen);
    //        painter.setBrush(this->m_brush);
    //        QPolygonF poly;
    //        qreal halfWidth = this->m_pen.widthF();
    ////        QPointF brushAdjust(qSin(qDegreesToRadians(lastPoint.rotation)) * halfWidth,
    ////                            qCos(qDegreesToRadians(lastPoint.rotation)) * halfWidth);
    //        poly << lastPoint.pos + brushAdjust;
    //        poly << lastPoint.pos - brushAdjust;
    //        brushAdjust = QPointF(qSin(qDegreesToRadians(event->rotation())) * halfWidth,
    //                              qCos(qDegreesToRadians(event->rotation())) * halfWidth);
    //        poly << event->posF() - brushAdjust;
    //        poly << event->posF() + brushAdjust;
    //        painter.drawConvexPolygon(poly);
    //    }
    //        break;
    //    case QTabletEvent::Puck:
    //    case QTabletEvent::FourDMouse:
    //    {
    //        const QString error(tr("This input device is not supported by the example."));
    //#ifndef QT_NO_STATUSTIP
    //        QStatusTipEvent status(error);
    //        QApplication::sendEvent(this, &status);
    //#else
    //        qWarning() << error;
    //#endif
    //    }
    //        break;
    //    default:
    //    {
    //        const QString error(tr("Unknown tablet device - treating as stylus"));
    //#ifndef QT_NO_STATUSTIP
    //        QStatusTipEvent status(error);
    //        QApplication::sendEvent(this, &status);
    //#else
    //        qWarning() << error;
    //#endif
    //    }
    //        // FALL-THROUGH
    //    case QTabletEvent::Stylus:
    //        painter.setPen(this->m_pen);
    //        painter.drawLine(lastPoint.pos, event->pos());
    //        break;
    //    }
}

void SCanvas::updateBrush(const QMouseEvent *event)
{
    Q_UNUSED(event);

    int hue, saturation, value, alpha;
    this->m_color.getHsv(&hue, &saturation, &value, &alpha);
    this->m_pen.setWidthF(14.0);

    //    switch (this->m_alphaChannelValuator) {
    //    case PressureValuator:
    //        this->m_color.setAlphaF(event->pressure());
    //        break;
    //    case TangentialPressureValuator:
    //        if (event->device() == QTabletEvent::Airbrush)
    //            this->m_color.setAlphaF(qMax(0.01, (event->tangentialPressure() + 1.0) / 2.0));
    //        else
    //            this->m_color.setAlpha(255);
    //        break;
    //    case TiltValuator:
    //        this->m_color.setAlpha(maximum(abs(vValue - 127), abs(hValue - 127)));
    //        break;
    //    default:
    //        this->m_color.setAlpha(255);
    //    }

    //    switch (this->m_colorSaturationValuator) {
    //    case VTiltValuator:
    //        this->m_color.setHsv(hue, vValue, value, alpha);
    //        break;
    //    case HTiltValuator:
    //        this->m_color.setHsv(hue, hValue, value, alpha);
    //        break;
    //    case PressureValuator:
    //        this->m_color.setHsv(hue, int(event->pressure() * 255.0), value, alpha);
    //        break;
    //    default:
    //        break;
    //    }

    //    switch (this->m_lineWidthValuator) {
    //    case PressureValuator:
    //        this->m_pen.setWidthF(event->pressure() * 10 + 1);
    //        break;
    //    case TiltValuator:
    //        this->m_pen.setWidthF(maximum(abs(vValue - 127), abs(hValue - 127)) / 12);
    //        break;
    //    default:
    //        this->m_pen.setWidthF(1);
    //    }

    //    if (event->pointerType() == QTabletEvent::Eraser) {
    //        this->m_brush.setColor(Qt::white);
    //        this->m_pen.setColor(Qt::white);
    //        this->m_pen.setWidthF(event->pressure() * 10 + 1);
    //    } else {
    //        this->m_brush.setColor(this->m_color);
    //        this->m_pen.setColor(this->m_color);
    //    }
}

//void SCanvas::updateCursor(const QTabletEvent *event)
//{
//    QCursor cursor;
//    if (event->type() != QEvent::TabletLeaveProximity) {
//        if (event->pointerType() == QTabletEvent::Eraser) {
//            cursor = QCursor(QPixmap(":/images/cursor-eraser.png"), 3, 28);
//        } else {
//            switch (event->device()) {
//            case QTabletEvent::Stylus:
//                cursor = QCursor(QPixmap(":/images/cursor-pencil.png"), 0, 0);
//                break;
//            case QTabletEvent::Airbrush:
//                cursor = QCursor(QPixmap(":/images/cursor-airbrush.png"), 3, 4);
//                break;
//            case QTabletEvent::RotationStylus: {
//                QImage origImg(QLatin1String(":/images/cursor-felt-marker.png"));
//                QImage img(32, 32, QImage::Format_ARGB32);
//                QColor solid = this->m_color;
//                solid.setAlpha(255);
//                img.fill(solid);
//                QPainter painter(&img);
//                QTransform transform = painter.transform();
//                transform.translate(16, 16);
//                transform.rotate(-event->rotation());
//                painter.setTransform(transform);
//                painter.setCompositionMode(QPainter::CompositionMode_DestinationIn);
//                painter.drawImage(-24, -24, origImg);
//                painter.setCompositionMode(QPainter::CompositionMode_HardLight);
//                painter.drawImage(-24, -24, origImg);
//                painter.end();
//                cursor = QCursor(QPixmap::fromImage(img), 16, 16);
//            }
//                break;
//            default:
//                break;
//            }
//        }
//    }
//    setCursor(cursor);
//}

void SCanvas::resizeEvent(QResizeEvent *)
{
    this->initPixmap();
}

void SCanvas::timerEvent(QTimerEvent *event)
{
    /// Blank canvas
    if (event->timerId() == this->blankTimer.timerId())
    {
        this->blankTimer.stop();

        if (this->save("/etc/sentenz/config/neuron/mnist/number.bmp"))
        {
            this->predictImage();
        }
        this->initPixmap();
    }
}

void SCanvas::predictImage()
{
    int number = neuron_mnist::recognize("/etc/sentenz/config/neuron/mnist/LeNet-model", "/etc/sentenz/config/neuron/mnist/number.bmp");

    emit this->signalSymbolChanged(QString::number(number));
}
