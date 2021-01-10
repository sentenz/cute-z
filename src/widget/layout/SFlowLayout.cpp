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

#include "SFlowLayout.h"

#include <QtWidgets>
#include <QDebug>


SFlowLayout::SFlowLayout(QWidget *parent, int margin, int hSpacing, int vSpacing)
    : QLayout(parent),
      m_hSpace(hSpacing),
      m_vSpace(vSpacing)
{
    this->setContentsMargins(margin, margin, margin, margin);
}

SFlowLayout::SFlowLayout(int margin, int hSpacing, int vSpacing)
    : m_hSpace(hSpacing),
      m_vSpace(vSpacing)
{
    this->setContentsMargins(margin, margin, margin, margin);
}

SFlowLayout::~SFlowLayout()
{
    QLayoutItem *item;
    while ((item = takeAt(0)))
    {
        delete item;
    }
}

void SFlowLayout::addItem(QLayoutItem *item)
{
    this->itemList.append(item);
}

void SFlowLayout::setHorizontalSpacing(int hSpacing)
{
    this->m_hSpace = hSpacing;
}

int SFlowLayout::horizontalSpacing() const
{
    if (this->m_hSpace >= 0)
    {
        return this->m_hSpace;
    }
    else
    {
        return smartSpacing(QStyle::PM_LayoutHorizontalSpacing);
    }
}

void SFlowLayout::setVerticalSpacing(int vSpacing)
{
    this->m_vSpace = vSpacing;
}

int SFlowLayout::verticalSpacing() const
{
    if (this->m_vSpace >= 0)
    {
        return this->m_vSpace;
    }
    else
    {
        return smartSpacing(QStyle::PM_LayoutVerticalSpacing);
    }
}

void SFlowLayout::setSpacing(int vSpacing, int hSpacing)
{
    this->setVerticalSpacing(vSpacing);
    this->setHorizontalSpacing(hSpacing);
}

int SFlowLayout::count() const
{
    return this->itemList.size();
}

QLayoutItem *SFlowLayout::itemAt(int index) const
{
    return this->itemList.value(index);
}

QLayoutItem *SFlowLayout::takeAt(int index)
{
    if (index >= 0 && index < this->itemList.size())
    {
        return this->itemList.takeAt(index);
    }
    else
    {
        return 0;
    }
}

Qt::Orientations SFlowLayout::expandingDirections() const
{
    return 0;
}

bool SFlowLayout::hasHeightForWidth() const
{
    return true;
}

int SFlowLayout::heightForWidth(int width) const
{
    int height = this->doLayout(QRect(0, 0, width, 0), true);
    return height;
}

void SFlowLayout::setGeometry(const QRect &rect)
{
    QLayout::setGeometry(rect);
    this->doLayout(rect, false);
}

QSize SFlowLayout::sizeHint() const
{
    return minimumSize();
}

QSize SFlowLayout::minimumSize() const
{
    QSize size;
    QLayoutItem *item;
    foreach (item, this->itemList)
    {
        size = size.expandedTo(item->minimumSize());
    }

    size += QSize(2*margin(), 2*margin());
    return size;
}

int SFlowLayout::doLayout(const QRect &rect, bool testOnly) const
{
    int left, top, right, bottom;
    getContentsMargins(&left, &top, &right, &bottom);
    QRect effectiveRect = rect.adjusted(+left, +top, -right, -bottom);
    int x = effectiveRect.x();
    int y = effectiveRect.y();

    //qDebug() << "x" << x << "y" << y;
    //qDebug() << "left" << effectiveRect.left() << "right" << effectiveRect.right();
    //qDebug() << "top" << effectiveRect.top() << "bottom" << effectiveRect.bottom();

    int lineHeight = 0;

    foreach (QLayoutItem *item, this->itemList)
    {
        QWidget *widget = item->widget();

        // Smart Size
        {
            int width = 0;
            int height = 0;
            int count = this->itemList.count();

            if (count < 5)
            {
                width = (effectiveRect.right() - effectiveRect.right() / 20) / count;
                height = (effectiveRect.bottom() - effectiveRect.bottom() / 10) / count;
            }

//            qDebug() << "width" << width << "height" << height;

            if (width > 0 && height > 0)
            {
                widget->setFixedSize(width, height);
            }
        }

        int spaceX = this->horizontalSpacing();
        if (spaceX == -1)
        {
            spaceX = widget->style()->layoutSpacing(QSizePolicy::PushButton, QSizePolicy::PushButton, Qt::Horizontal);
        }
        int spaceY = this->verticalSpacing();
        if (spaceY == -1)
        {
            spaceY = widget->style()->layoutSpacing(QSizePolicy::PushButton, QSizePolicy::PushButton, Qt::Vertical);
        }
        int nextX = x + item->sizeHint().width() + spaceX;
        if (nextX - spaceX > effectiveRect.right() && lineHeight > 0)
        {
            x = effectiveRect.x();
            y = y + lineHeight + spaceY;
            nextX = x + item->sizeHint().width() + spaceX;
            lineHeight = 0;
        }

        //qDebug() << "nextX" << nextX << "item->sizeHint().width()" << item->sizeHint().width();
        //qDebug() << "x" << effectiveRect.x() << "y" << effectiveRect.y();

        if (!testOnly)
        {
            item->setGeometry(QRect(QPoint(x, y), item->sizeHint()));
        }

        x = nextX;
        lineHeight = qMax(lineHeight, item->sizeHint().height());

        //qDebug() << "nextX" << nextX << "item" << item->sizeHint().width();
        //qDebug() << "x" << effectiveRect.x() << "y" << effectiveRect.y();
        //qDebug() << "item->sizeHint().height()" << item->sizeHint().height();
    }

    //qDebug() << "return" << y + lineHeight - rect.y() + bottom << "\n";

    return y + lineHeight - rect.y() + bottom;
}

QSize SFlowLayout::smartSize(const QRect &rect) const
{
    Q_UNUSED(rect);

    return QSize(0, 0);
}

int SFlowLayout::smartSpacing(QStyle::PixelMetric pm) const
{
    QObject *parent = this->parent();
    if (!parent)
    {
        return -1;
    }
    else if (parent->isWidgetType())
    {
        QWidget *widget = static_cast<QWidget *>(parent);
        return widget->style()->pixelMetric(pm, 0, widget);
    }
    else
    {
        return static_cast<QLayout *>(parent)->spacing();
    }
}
