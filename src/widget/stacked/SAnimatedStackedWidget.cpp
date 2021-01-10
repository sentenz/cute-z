#include "SAnimatedStackedWidget.h"

#include <QHBoxLayout>


SAnimatedStackedWidget::SAnimatedStackedWidget(QWidget * parent)
    : QStackedWidget(parent)
{
}

void
SAnimatedStackedWidget::setVerticalMode(const bool vertical)
{
    this->m_vertical = vertical;
}

void
SAnimatedStackedWidget::setDuration(const int duration)
{
    this->m_duration = duration;
}

void
SAnimatedStackedWidget::setAnimation(const QEasingCurve::Type easing)
{
    this->m_easing = easing;
}

void
SAnimatedStackedWidget::setWrap(const bool wrap)
{
    this->m_wrap = wrap;
}

void
SAnimatedStackedWidget::slideInNext()
{
    int now = this->currentIndex();
    if (this->m_wrap || (now < count() - 1))
    {
        this->slideIn(now + 1);
    }
}

void
SAnimatedStackedWidget::slideInPrev()
{
    int now = this->currentIndex();
    if (this->m_wrap || (now > 0))
    {
        this->slideIn(now - 1);
    }
}

void
SAnimatedStackedWidget::slideIn(const int index,
                                const Direction direction)
{
    int t_index = index;
    Direction t_direction = direction;

    if (t_index > count() - 1)
    {
        t_direction = this->m_vertical ? Direction::TopToBottom : Direction::RightToLeft;
        t_index = (t_index) % count();
    }
    else if (t_index < 0)
    {
        t_direction = this->m_vertical ? Direction::BottomToTop : Direction::LeftToRight;
        t_index = (t_index + count()) % count();
    }

    this->slideIn(widget(t_index), t_direction);
}

void
SAnimatedStackedWidget::slideIn(QWidget * newWidget,
                                Direction direction)
{
    if (this->m_active)
    {
        return;
    }
    this->m_active = true;

    Direction directionHint;
    int now = this->currentIndex();
    int next = this->indexOf(newWidget);
    if (now == next)
    {
        this->m_active = false;
        return;
    }

    if (now < next)
    {
        directionHint = this->m_vertical ? Direction::TopToBottom : Direction::RightToLeft;
    }
    else
    {
        directionHint = this->m_vertical ? Direction::BottomToTop : Direction::LeftToRight;
    }

    if (direction == Direction::Automatic)
    {
        direction = directionHint;
    }

    int offsetX = this->frameRect().width();
    int offsetY = this->frameRect().height();

    this->widget(next)->setGeometry(0, 0, offsetX, offsetY);

    if (direction == Direction::BottomToTop)
    {
        offsetX = 0;
        offsetY = -offsetY;
    }
    else if (direction == Direction::TopToBottom)
    {
        offsetX = 0;
    }
    else if (direction == Direction::RightToLeft)
    {
        offsetX = -offsetX;
        offsetY = 0;
    }
    else if (direction == Direction::LeftToRight)
    {
        offsetY = 0;
    }

    QPoint pNext = widget(next)->pos();
    QPoint pNow = widget(now)->pos();
    this->m_pNow = pNow;

    this->widget(next)->move(pNext.x() - offsetX, pNext.y() - offsetY);
    this->widget(next)->show();
    this->widget(next)->raise();

    // Set group animation
    QParallelAnimationGroup * animGroup = new QParallelAnimationGroup;
    // Set move animation
    QPropertyAnimation * animNow = new QPropertyAnimation(widget(now), "pos");
    animNow->setDuration(this->m_duration);
    animNow->setEasingCurve(this->m_easing);
    animNow->setStartValue(QPoint(pNow.x(), pNow.y()));
    animNow->setEndValue(QPoint(offsetX + pNow.x(), offsetY + pNow.y()));
    QPropertyAnimation * animNext = new QPropertyAnimation(widget(next), "pos");
    animNext->setDuration(this->m_duration);
    animNext->setEasingCurve(this->m_easing);
    animNext->setStartValue(QPoint(-offsetX + pNext.x(), offsetY + pNext.y()));
    animNext->setEndValue(QPoint(pNext.x(), pNext.y()));
    // Add to group
    animGroup->addAnimation(animNow);
    animGroup->addAnimation(animNext);
    if (this->m_fade)
    {
        // Set fade animation
        QPropertyAnimation * fadeNow = new QPropertyAnimation(widget(now), "windowOpacity");
        fadeNow->setDuration(this->m_duration);
        fadeNow->setEasingCurve(QEasingCurve::InQuint);
        fadeNow->setStartValue(1);
        fadeNow->setEndValue(0);
        QPropertyAnimation * fadeNext = new QPropertyAnimation(widget(next), "windowOpacity");
        fadeNext->setDuration(this->m_duration);
        fadeNext->setEasingCurve(QEasingCurve::Linear);
        fadeNext->setStartValue(0);
        fadeNext->setEndValue(1);
        // Add to group
        animGroup->addAnimation(fadeNow);
        animGroup->addAnimation(fadeNext);
    }

    QObject::connect(animGroup, &QAbstractAnimation::finished, this, &SAnimatedStackedWidget::slotAnimationDone);

    this->m_next = next;
    this->m_now = now;
    this->m_active = true;
    animGroup->start(QPropertyAnimation::DeleteWhenStopped);
}

void
SAnimatedStackedWidget::slotAnimationDone()
{
    this->setCurrentIndex(this->m_next);
    this->widget(this->m_now)->hide();
    this->widget(this->m_now)->move(this->m_pNow);
    this->m_active = false;
    this->m_fade = false;
    emit this->signalAnimationFinished();
}

// TODO: Bring me to work.
void
SAnimatedStackedWidget::fadeIn(const int index)
{
    this->m_fade = true;
    this->slideIn(index);
}

// TODO: Bring me to work.
void
SAnimatedStackedWidget::fadeIn(QWidget * newWidget)
{
    this->m_fade = true;
    this->slideIn(newWidget);
}

void
SAnimatedStackedWidget::expandToOne()
{
    if (this->m_expanded)
    {
        return;
    }
    this->m_expanded = true;

    this->setFixedWidth(frameRect().width() * count() + ((count() - 1) * 24));

    this->m_widgets.clear();
    for (int i = 0, n = count(); i < n; ++i)
    {
        this->m_widgets.append(widget(i));
    }

    for (QWidget * widget : this->m_widgets)
    {
        this->removeWidget(widget);
    }

    QWidget * pWidget = new QWidget();
    auto layout = new QHBoxLayout(pWidget);
    layout->setSpacing(24);
    layout->setContentsMargins(0, 0, 0, 0);

    for (QWidget * w : this->m_widgets)
    {
        w->setParent(pWidget);
        w->show();
        layout->addWidget(w);
    }
    pWidget->setLayout(layout);
    this->addWidget(pWidget);
}

void
SAnimatedStackedWidget::collapse()
{
    if (!this->m_expanded)
    {
        return;
    }
    this->m_expanded = false;

    QVector<QWidget*> widgetsToDelete;
    for (int i = 0, n = count(); i < n; ++i)
    {
        widgetsToDelete.append(widget(i));
    }

    this->setFixedWidth((frameRect().width() - ((this->m_widgets.count() - 1) * 24)) / this->m_widgets.count());

    for (QWidget * w : this->m_widgets)
    {
        this->addWidget(w);
    }

    for (QWidget * w : widgetsToDelete)
    {
        this->removeWidget(w);
        w->deleteLater();
    }
}

bool
SAnimatedStackedWidget::isExpanded() const
{
    return this->m_expanded;
}
