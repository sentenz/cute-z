#include "SFlickableTicker.h"

SFlickableTicker::SFlickableTicker(SFlickable *scroller)
{
    this->m_scroller = scroller;
}

void SFlickableTicker::start(int interval)
{
    if (!this->m_timer.isActive())
    {
        this->m_timer.start(interval, this);
    }
}

void SFlickableTicker::stop()
{
    this->m_timer.stop();
}

void SFlickableTicker::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);
    this->m_scroller->tick();
}
