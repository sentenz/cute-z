#ifndef SANIMATEDSTACKEDWIDGET_H
#define SANIMATEDSTACKEDWIDGET_H

#include <QDebug>
#include <QEasingCurve>
#include <QStackedWidget>
#include <QWidget>
#include <QtGui>

/**
 * @brief SAnimatedStackedWidget is a class that is derived from QtStackedWidget
 *        and allows smooth side shifting of widgets, in addition
 *        to the original hard switching from one to another as offered by
 *        QStackedWidget itself.
 * Thanks to http://www.developer.nokia.com/Community/Wiki/Extending_QStackedWidget_for_sliding_page_animations_in_Qt
 */
class SAnimatedStackedWidget : public QStackedWidget
{
    Q_OBJECT

public:
    enum class Direction
    {
        LeftToRight,
        RightToLeft,
        TopToBottom,
        BottomToTop,
        Automatic,
        FadeOutIn
    };

    explicit SAnimatedStackedWidget(QWidget * parent = nullptr);
    ~SAnimatedStackedWidget() override = default;

    bool isExpanded() const;

public slots:
    void setDuration(const int duration);
    void setAnimation(const QEasingCurve::Type easing);
    void setVerticalMode(const bool vertical = true);
    void setWrap(const bool wrap);
    void slideInNext();
    void slideInPrev();
    void slideIn(const int index, const Direction direction = Direction::Automatic);
    void slideIn(QWidget * widget, Direction direction = Direction::Automatic);
    void fadeIn(const int index);
    void fadeIn(QWidget * widget);
    void expandToOne();
    void collapse();

signals:
    void signalAnimationFinished();

protected slots:
    void slotAnimationDone();

protected:

    bool m_fade = false;
    bool m_wrap = false;
    bool m_vertical = false;
    bool m_active = false;
    bool m_expanded = false;
    int m_now = 0;
    int m_next = 0;
    int m_duration = 500;
    QPoint m_pNow = QPoint(0, 0);
    QEasingCurve::Type m_easing = QEasingCurve::OutBack;

    QVector<QWidget*> m_widgets;
};

#endif // SANIMATEDSTACKEDWIDGET_H
