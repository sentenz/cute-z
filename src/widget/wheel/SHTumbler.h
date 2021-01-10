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

#ifndef SHTUMBLER_H
#define SHTUMBLER_H

#include <QWidget>
#include <QStringList>
#include "../build/SGlobal.h"

class QPainter;
class QRect;


class SHAbstractWheelWidget : public QWidget
{
    Q_OBJECT

public:
    SHAbstractWheelWidget(bool touch, QWidget *parent = 0);
    virtual ~SHAbstractWheelWidget();

    int currentIndex() const;
    void setCurrentIndex(int index);

    void setFontSizeParamter(const int &size = 18);
    void setBaseColor(const QColor &color);
    void setContrastColor(const QColor &color);
    void setTextColor(const QColor &color);

    virtual int itemHeight() const = 0;
    virtual int itemCount() const = 0;

protected:
    bool event(QEvent *event);
    void paintEvent(QPaintEvent *event);
    virtual void paintItem(QPainter* painter, int index, const QRect &rect) = 0;
    int m_currentItem;
    int m_itemOffset; // 0-itemHeight()
    qreal m_lastY;

public slots:
    void scrollTo(int index);

signals:
    void stopped(int index);

private:
    QPainterPath lensDeform(const QPainterPath &source, const QPointF &offset);

    int m_fontSizeParamter = 18;
    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
};

class SHTumbler : public SHAbstractWheelWidget
{
    Q_OBJECT

public:
    SHTumbler(bool touch);

    QStringList items() const;
    void setItems(const QStringList &items);

    QString currentContent() const;
    void setCurrentContent(const QString &content);

    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    void paintItem(QPainter* painter, int index, const QRect &rect);

    int itemHeight() const;
    int itemCount() const;

private:
    QStringList m_items;
};

#endif // SHTUMBLER_H
