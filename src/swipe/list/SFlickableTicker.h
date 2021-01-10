#ifndef SFLICKABLETICKER_H
#define SFLICKABLETICKER_H

#include "SFlickable.h"

#include <QObject>
#include <QBasicTimer>

class SFlickableTicker : QObject
{
public:
    SFlickableTicker(SFlickable *scroller);
    ~SFlickableTicker() = default;

    void start(int interval);

    void stop();

protected:
    void timerEvent(QTimerEvent *event);

private:
    SFlickable *m_scroller;
    QBasicTimer m_timer;
};

#endif /// SFLICKABLETICKER_H
