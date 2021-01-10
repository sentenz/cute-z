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

#ifndef SVTUMBLER_H
#define SVTUMBLER_H

#include "../build/SGlobal.h"

#include <QWidget>
#include <QStringList>
#include <QTimer>

class QPainter;
class QRect;
class QTimeLine;


class SVAbstractWheelWidget
        : public QWidget
{
    Q_OBJECT

public:
    SVAbstractWheelWidget(bool touch = true, QWidget *parent = nullptr);
    virtual ~SVAbstractWheelWidget();

    int currentIndex() const;
    void setCurrentIndex(int index);

    void setFontSize(const int &size = 18);

    void highlight(const bool highlight = true);

    virtual int itemHeight() const = 0;
    virtual int itemCount() const = 0;

protected:
    bool event(QEvent *event);
    void changeEvent(QEvent * event);
    void paintEvent(QPaintEvent *event);
    virtual void paintItem(QPainter* painter, int index, const QRect &rect) = 0;

    bool m_touch;
    int m_currentItem;
    int m_itemOffset; // 0-itemHeight()
    qreal m_lastY;

    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    QTimer m_timer;

public slots:
    void scrollToIndex(const int index, const int scrollTime = 1000);

signals:
    void stopped(const int index);
    void signalCurrentIndex(const int index);
    void signalCurrentContent(const QString content);
    void signalCurrentIndexContent(const int index, const QString content);

private:
    void restyleUI();
    QPainterPath lensDeform(const QPainterPath &source, const QPointF &offset);

    int m_fontSize = 18;
    bool m_highlight = true;
};

class SVTumbler : public SVAbstractWheelWidget
{
    Q_OBJECT

public:
    enum class Effect {
        None,
        GradientArc
    };

    enum class Style {
        None,
        TextUnderIcon
    };

    SVTumbler(QWidget *parent = nullptr);
    SVTumbler(bool touch = true, QWidget *parent = nullptr);

    QStringList items() const;
    void setItems(const QStringList &items);

    QStringList icons() const;
    void setIcons(const QStringList &icons);

    QString currentContent() const;
    void setCurrentContent(const QString &content);

    void scrollToContent(const QString content, const int scrollTime = 1000);

    void setEffect(const Effect &effect = Effect::None);
    void setStyle(const Style &style = Style::None);
    void setAlignment(const Qt::AlignmentFlag &alignment = Qt::AlignCenter);

    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    void enableHighlight(const bool highlight = true);

    void paintItem(QPainter* painter, int index, const QRect &rect);

    int itemHeight() const;
    void setItemHeight(const int height);

    int itemCount() const;

protected:
    void changeEvent(QEvent * event);
    void mousePressEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent * event);

private:
    void setupWidget();
    void setConnect();
    void restyleUI();

    void paintPixmap(QPainter* painter, int index, const QRect &rect);
    void paintText(QPainter* painter, int index, const QRect &rect);
    void paintEffect(QPainter* painter, int index, const QRect &rect);
    QPixmap changePixmapColor(const QString &source, const QColor &color);

    bool m_pressed = false;
    bool m_highlight = true;
    int m_itemHeight = 0;
    double m_frameFactor = 0.0;

    Effect m_effect = Effect::None;
    Style m_style = Style::None;
    QTimeLine *m_timeLine = nullptr;
    Qt::AlignmentFlag m_alignment = Qt::AlignCenter;

    QStringList m_items;
    QStringList m_icons;
    QList<QPixmap> m_listPixmap;
};

#endif // SVTUMBLER_H


//this->touchTumbler = new SVTumbler(this);
//this->touchTumbler->setBaseColor(this->m_colorBase);
//this->touchTumbler->setContrastColor(this->m_colorBase);
//this->touchTumbler->setTextColor(this->m_colorText);
//this->touchTumbler->setHighlightColor(Qt::transparent);
//this->touchTumbler->setEffect(SVTumbler::Effect::GradientArc);
//this->touchTumbler->setStyle(SVTumbler::Style::TextUnderIcon);
//this->touchTumbler->setItemHeight(t_height/3);
//this->touchTumbler->setIcons(QStringList()
//                             << ":/images/odometer.svg"
//                             << ":/images/paternoster.svg"
//                             << ":/images/panel.svg");
//this->touchTumbler->setItems(QStringList()
//                              << tr("Odometer")
//                              << tr("Paternoster")
//                              << tr("Control Panel"));

