/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the demonstration applications of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL21$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** As a special exception, The Qt Company gives you certain additional
** rights. These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "SFlickable.h"
#include "SFlickableTicker.h"

#include <QtCore>
#include <QtWidgets>
#include <QApplication>
#include <QDebug>


class SFlickablePrivate
{
public:
    typedef enum
    {
        Steady,
        Pressed,
        ManualScroll,
        AutoScroll,
        Stop
    } State;

    State state;
    int threshold;
    QPoint pressPos;
    QPoint offset;
    QPoint delta;
    QPoint speed;
    SFlickableTicker *ticker;
    QTime timeStamp;
    QWidget *target;
    QList<QEvent*> ignoreList;
};

SFlickable::SFlickable()
{
    flick = new SFlickablePrivate;
    flick->state = SFlickablePrivate::Steady;
    flick->threshold = 3;
    flick->ticker = new SFlickableTicker(this);
    flick->timeStamp = QTime::currentTime();
    flick->target = 0;
}

SFlickable::~SFlickable()
{
    if (flick)
    {
        delete flick;
        flick = nullptr;
    }
}

void SFlickable::setThreshold(int threshold)
{
    if (threshold >= 0)
    {
        flick->threshold = threshold;
    }
}

int SFlickable::threshold() const
{
    return flick->threshold;
}

void SFlickable::setAcceptMouseClick(QWidget *target)
{
    flick->target = target;
}

void SFlickable::handleMousePress(QMouseEvent *event)
{
    event->ignore();

    if (flick->state == SFlickablePrivate::AutoScroll)
    {
        flick->state = SFlickablePrivate::Steady;
        flick->ticker->stop();
    }

    if (flick->ignoreList.removeAll(event))
    {
        return;
    }

    switch (flick->state)
    {
        case SFlickablePrivate::Steady:
            event->accept();
            flick->state = SFlickablePrivate::Pressed;
            flick->pressPos = event->pos();
            break;

        case SFlickablePrivate::AutoScroll:
            event->accept();
            flick->state = SFlickablePrivate::Stop;
            flick->speed = QPoint(0, 0);
            flick->pressPos = event->pos();
            flick->offset = scrollOffset();
            flick->ticker->stop();
            break;

        default:
            break;
    }
}

void SFlickable::handleMouseRelease(QMouseEvent *event)
{
    event->ignore();

    if (flick->ignoreList.removeAll(event))
    {
        return;
    }

    QPoint delta;

    switch (flick->state)
    {
        case SFlickablePrivate::Pressed:
            event->accept();
            flick->state = SFlickablePrivate::Steady;
            if (flick->target)
            {
                QMouseEvent *event1 = new QMouseEvent(QEvent::MouseButtonPress, flick->pressPos, Qt::LeftButton, Qt::LeftButton, Qt::NoModifier);
                QMouseEvent *event2 = new QMouseEvent(*event);
                flick->ignoreList << event1;
                flick->ignoreList << event2;
                QApplication::postEvent(flick->target, event1);
                QApplication::postEvent(flick->target, event2);
            }
            break;

    case SFlickablePrivate::ManualScroll:
            event->accept();
            delta = event->pos() - flick->pressPos;
            if (flick->timeStamp.elapsed() > 100)
            {
                flick->timeStamp = QTime::currentTime();
                flick->speed = delta - flick->delta;
                flick->delta = delta;
            }
            flick->offset = scrollOffset();
            flick->pressPos = event->pos();
            if (flick->speed == QPoint(0, 0))
            {
                flick->state = SFlickablePrivate::Steady;
            }
            else
            {
                flick->speed /= 4;
                flick->state = SFlickablePrivate::AutoScroll;
                flick->ticker->start(20);
            }
            break;

    case SFlickablePrivate::Stop:
            event->accept();
            flick->state = SFlickablePrivate::Steady;
            flick->offset = scrollOffset();
            break;

    default:
            break;
    }
}

void SFlickable::handleMouseMove(QMouseEvent *event)
{
    event->ignore();

    if (flick->ignoreList.removeAll(event))
    {
        return;
    }

    QPoint delta;

    switch (flick->state)
    {
        case SFlickablePrivate::Pressed:
        case SFlickablePrivate::Stop:
            delta = event->pos() - flick->pressPos;
            if (delta.x() > flick->threshold || delta.x() < -flick->threshold || delta.y() > flick->threshold || delta.y() < -flick->threshold)
            {
                flick->timeStamp = QTime::currentTime();
                flick->state = SFlickablePrivate::ManualScroll;
                flick->delta = QPoint(0, 0);
                flick->pressPos = event->pos();
                event->accept();
            }
            break;

        case SFlickablePrivate::ManualScroll:
            event->accept();
            delta = event->pos() - flick->pressPos;
            setScrollOffset(flick->offset - delta);
            if (flick->timeStamp.elapsed() > 100)
            {
                flick->timeStamp = QTime::currentTime();
                flick->speed = delta - flick->delta;
                flick->delta = delta;
            }
            break;

        default:
            break;
    }
}

static QPoint deaccelerate(const QPoint &speed, int a = 1, int max = 64)
{
    int x = qBound(-max, speed.x(), max);
    int y = qBound(-max, speed.y(), max);
    x = (x == 0) ? x : (x > 0) ? qMax(0, x - a) : qMin(0, x + a);
    y = (y == 0) ? y : (y > 0) ? qMax(0, y - a) : qMin(0, y + a);

    return QPoint(x, y);
}

void SFlickable::tick()
{
    if (flick->state == SFlickablePrivate::AutoScroll)
    {
        flick->speed = deaccelerate(flick->speed);
        setScrollOffset(flick->offset - flick->speed);
        flick->offset = scrollOffset();
        if (flick->speed == QPoint(0, 0))
        {
            flick->state = SFlickablePrivate::Steady;
            flick->ticker->stop();
        }
    }
    else
    {
        flick->ticker->stop();
    }
}
