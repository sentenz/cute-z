#include "STouchFlickableList.h"
#include "../effect/SGraphicsGlowEffect.h"

#include <QApplication>
#include <QTimer>
#include <QFont>
#include <QPainter>
#include <QLine>
#include <QPaintEvent>
#include <QFocusEvent>
#include <QShowEvent>
#include <QHideEvent>
#include <QCloseEvent>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QGraphicsOpacityEffect>
#include <QLinearGradient>
#include <QPushButton>
#include <QPalette>
#include <QEvent>
#include <QGesture>
#include <QGestureEvent>
#include <QSwipeGesture>
#include <QTouchEvent>
#include <QDesktopWidget>
#include <QSignalBlocker>
#include <QDebug>


STouchFlickableList::STouchFlickableList(QWidget *parent) : QWidget(parent)
{
    #ifdef QT_EMBEDDED
    QApplication::setOverrideCursor(Qt::BlankCursor);
    this->resize(QSize(330, height()));
    #else
    this->resize(QSize(330, 480));
    #endif
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setAttribute(Qt::WA_NoSystemBackground);
    this->setAttribute(Qt::WA_OpaquePaintEvent);
    this->setAttribute(Qt::WA_AcceptTouchEvents);
    this->setWindowOpacity(1.0);
    this->setMouseTracking(true);
    this->setFocus();

    if (!this->m_hideable)
    {
        this->setObjectName("STouchFlickableList");
    }

    this->grabGesture(Qt::SwipeGesture);

    this->setupGUI();
    this->m_init_height = this->height() * 0.2;
}

STouchFlickableList::~STouchFlickableList()
{
    if (this->hideTimer != nullptr)
    {
        delete this->hideTimer;
        this->hideTimer = nullptr;
    }
}

void STouchFlickableList::setupGUI()
{
    this->setFontSize();
    this->setFontSizeParamter();

    SFlickable::setAcceptMouseClick(this);
}

void STouchFlickableList::paintEvent(QPaintEvent *event)
{
    /// Predefination
    if (!m_widgetNames.isEmpty())
    {
        this->m_maxIndex = m_widgetNames.count();
    }
    else if (!m_widgetPixmap.isEmpty())
    {
        this->m_maxIndex = m_widgetPixmap.count();
    }

    if (this->m_height == 0)
    {
        if (!this->m_widgetPixmap.isEmpty())
        {
            if (this->m_set_height)
            {
                this->m_height = QFontMetrics(font()).height() + this->m_set_height;
            }
            else
            {
                this->m_height = QFontMetrics(font()).height() + this->m_init_height;
            }
        }
        else
        {
            if (this->m_set_height)
            {
                this->m_height = QFontMetrics(font()).height() + this->m_set_height;
            }
            else
            {
                this->m_height = QFontMetrics(font()).height() + this->m_init_height * 0.6;
            }
        }
    }

    this->m_begin = this->m_offset / this->m_height;
    this->m_y = this->m_begin * this->m_height - this->m_offset;
    if (this->m_offset <= 0)
    {
        this->m_begin = 0;
        this->m_y = -this->m_offset;
    }

    this->m_end = this->m_begin + this->height() / this->m_height + 1;
    if (this->m_end > this->m_maxIndex - 1)
    {
        this->m_end = this->m_maxIndex - 1;
    }

    /// Painter begin
    ///
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    /// set background
    painter.fillRect(event->rect(), this->background_color);

    /// Loop
    ///
    for (int i = this->m_begin; i <= this->m_end; ++i, this->m_y += this->m_height)
    {
        painter.setBrush(Qt::NoBrush);
        /// set font-color
        painter.setPen(this->font_text_color);

        /// DRAW EMPTY
        ///
        if (this->m_indexEmpty.indexOf(i) != -1)
        {
            painter.fillRect(0, this->m_y, this->width(), this->m_height, this->empty_color);

            continue;
        }

        /// DRAW TOPIC
        ///
        if (this->m_indexTopic.indexOf(i) != -1)
        {
            painter.setPen(this->font_topic_color);
            painter.setFont(QFont(::GlobalFont, this->font_size.pointSize()));
            if (this->alignmentFlag == Qt::AlignCenter)
            {
                painter.drawText(this->m_height/2, this->m_y, this->width(), this->m_height, Qt::AlignCenter, this->m_widgetNames[i]);
            }
            else
            {
                painter.drawText(this->m_height/2, this->m_y, this->width(), this->m_height, Qt::AlignVCenter, this->m_widgetNames[i]);
            }
            painter.fillRect(0, this->m_y, this->width(), this->m_height, this->topic_color);

            continue;
        }

        /// HIGHLIGHT
        ///
        if (i == this->m_highlightIndex)
        {
            painter.fillRect(0, this->m_y, this->width(), this->m_height, this->highlight_color);
            painter.setPen(this->font_text_color);
        }
        if (i == this->m_selectedIndex)
        {
            painter.fillRect(0, this->m_y, this->width(), this->m_height, this->selected_color);
            painter.setPen(this->font_text_color);
        }

        /// DRAW PIXMAP
        ///
        if (!this->m_widgetPixmap.isEmpty())
        {
            if (!this->m_widgetNames.isEmpty())
            {
                painter.setFont(this->font_size);
                painter.drawText(this->m_height + 50, this->m_y, this->width(), this->m_height, Qt::AlignVCenter, this->m_widgetNames[i]);
                if (this->m_drawline && i != 0)
                {
                    painter.setPen(this->line_color);
                    painter.drawLine(QLine(this->m_height + 50, this->m_y, this->width(), this->m_y));
                }
                painter.setPen(Qt::NoPen);
            }

            /// --> much better resolution as QPaint::drawPixmap()
            int scaled_height = this->m_widgetNames.isEmpty() ? this->m_height * this->m_scale_icon : this->m_height;
            QIcon(this->m_widgetPixmap[i].scaledToHeight(this->m_height * this->m_scale_icon, Qt::SmoothTransformation)).paint(&painter, 20, this->m_y, scaled_height, this->m_height);

            continue;
        }

        /// DRAW TEXT
        ///
        painter.setFont(this->font_size);
        if (!this->m_widgetNames.isEmpty())
        {
            if (this->alignmentFlag == Qt::AlignCenter)
            {
                painter.drawText(0, this->m_y, this->width(), this->m_height, Qt::AlignCenter, this->m_widgetNames[i]);
            }
            else
            {
                painter.drawText(this->m_height/2, this->m_y, this->width(), this->m_height, Qt::AlignVCenter, this->m_widgetNames[i]);
            }
        }

        /// DRAW PARAMETER
        ///
        if (i < this->m_widgetParameter.size())
        {
            if (!this->m_widgetParameter.at(i).isEmpty())
            {
                painter.setFont(this->font_size_param);
                painter.setPen(this->font_parameter_color);
                painter.drawText(0, this->m_y, this->width() - this->m_height/2, this->m_height, Qt::AlignRight | Qt::AlignCenter, this->m_widgetParameter[i]);
            }
        }

        /// DRAW LINE
        ///
        if (this->m_drawline && i != 0 && this->m_indexNoline.indexOf(i) == -1)
        {
            painter.setPen(this->line_color);
            painter.drawLine(QLine(0, this->m_y, this->width(), this->m_y));
        }
    }

    if (this->m_loop)
    {
        QLinearGradient gradient(0, 0, 0, event->rect().height());
        gradient.setColorAt(0.0, Qt::black);
        gradient.setColorAt(0.5, Qt::transparent);
        gradient.setColorAt(1.0, Qt::black);
        painter.fillRect(event->rect(), gradient);
    }

    /// Painter end
    ///
    painter.end();

    /// Hide Timer
    ///
    if (this->hideTimer)
    {
        this->hideTimer->start(10000);
    }
}

int STouchFlickableList::index(QMouseEvent *event)
{
    int y = event->pos().y() + this->m_offset;
    return y / this->m_height;
}

void STouchFlickableList::mousePressEvent(QMouseEvent *event)
{
    SFlickable::handleMousePress(event);

    this->m_delta = event->pos();

    if (event->isAccepted())
    {
        return;
    }

    // Atuelly not works like it shall
    //
//    int i = this->index(event);

//    if (i >= 0 && i < this->m_maxIndex)
//    {
//        if (this->m_checkable)
//        {
//            if (i != this->m_highlight)
//            {
//                this->m_highlight = i;
//            }
//        }
//    }

    event->accept();
    update();
}

void STouchFlickableList::mouseReleaseEvent(QMouseEvent *event)
{
    SFlickable::handleMouseRelease(event);

    this->m_delta = QPoint(0, 0);

    if (event->isAccepted())
    {
        return;
    }

    int i = this->index(event);
    this->m_index = i;

    if (i >= 0 && i < this->m_maxIndex)
    {
        if (i != this->m_highlightIndex)
        {
            if (this->m_selectable)
            {
                this->m_selectedIndex = i;
            }

            if (this->m_checkable)
            {
                this->m_highlightIndex = i;

                if (this->m_hideable)
                {
                    this->m_gesture = true;

                    QTimer::singleShot(200, this, SLOT(slotClose()));
                }
                else
                {
                    QTimer::singleShot(300, this, SLOT(slotUnsetHighlight()));
                }

                // Never replace i
                // A work around for event->isAccepted()
                // Lambda don't work on Debian
                //
                //QTimer::singleShot(200, [this, i] () { emit signalCurrentIndex(i); } );
                QTimer::singleShot(200, this, SLOT(slotEmitCurrentIndex()));
            }
        }
    }

    event->accept();
    update();
}

void STouchFlickableList::slotEmitCurrentIndex()
{
    emit signalCurrentIndex(this->m_index);

    return;
}

void STouchFlickableList::mouseMoveEvent(QMouseEvent *event)
{
    SFlickable::handleMouseMove(event);

    this->closeGesture(event);

    if (event->isAccepted())
    {
        return;
    }

    // Atuelly not works like it shall
    //
//    if (abs(this->m_delta.y() - event->pos().y()) > 3)
//    {
//        this->m_highlight = -1;
//    }

    event->accept();
    update();
}

void STouchFlickableList::closeGesture(QMouseEvent *event)
{
    // Work around QGestureEvent
    //
    if (this->m_hideable)
    {
        if (this->edge == Qt::LeftEdge)
        {
            if (abs(this->m_delta.y() - event->pos().y()) < 15)
            {
                if (this->m_delta.x() - event->pos().x() > 30)
                {
                    this->m_delta = QPoint(0, 0);
                    QTimer::singleShot(0, this, SLOT(slotClose()));
                }
            }
            else
            {
                this->m_delta = QPoint(0, 0);
            }
        }
        else if (this->edge == Qt::RightEdge)
        {
            if (abs(this->m_delta.y() - event->pos().y()) < 15)
            {
                if (this->m_delta.x() - event->pos().x() < -20)
                {
                    this->m_delta = QPoint(0, 0);
                    QTimer::singleShot(0, this, SLOT(slotClose()));
                }
            }
            else
            {
                this->m_delta = QPoint(0, 0);
            }
        }
        else if (this->edge == Qt::BottomEdge)
        {
            if (abs(this->m_delta.x() - event->pos().x()) < 15)
            {
                if (this->m_delta.y() - event->pos().y() < -20)
                {
                    this->m_delta = QPoint(0, 0);
                    QTimer::singleShot(0, this, SLOT(slotClose()));
                }
            }
            else
            {
                //this->m_delta = QPoint(0, 0);
            }
        }
    }
}

void STouchFlickableList::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Down)
    {
        this->m_offset += 1;
        event->accept();
        update();
        return;
    }

    if (event->key() == Qt::Key_Up)
    {
        this->m_offset -= 1;
        event->accept();
        update();
        return;
    }
}

bool STouchFlickableList::event(QEvent *event)
{
    if (event->type() == QEvent::Gesture)
    {
        return gestureEvent(static_cast<QGestureEvent*>(event));
    }

    return QWidget::event(event);
}

bool STouchFlickableList::gestureEvent(QGestureEvent *event)
{
    if (QGesture *swipe = event->gesture(Qt::SwipeGesture))
    {
        swipeTriggered(static_cast<QSwipeGesture *>(swipe));
    }
    return true;
}

void STouchFlickableList::swipeTriggered(QSwipeGesture *gesture)
{
    if (gesture->state() == Qt::GestureFinished)
    {
        if (gesture->horizontalDirection() == QSwipeGesture::Left)
        {
            this->slotClose();
        }
        update();
    }
}

void STouchFlickableList::focusOutEvent(QFocusEvent* event)
{
    if (event->type() == QEvent::FocusOut)
    {
        if (!this->m_gesture)
        {
            QTimer::singleShot(0, this, SLOT(slotClose()));
        }
        else
        {
            this->m_gesture = false;
        }
    }
}

void STouchFlickableList::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);

    if (this->m_animate)
    {
        /// Fade In & Move In
        ///
        this->showAnimation();
    }

    /// Hide after a while if not touched
    ///
    if (this->m_hideable)
    {
        if (!this->hideTimer)
        {
            this->hideTimer = new QTimer;
            connect(this->hideTimer, &QTimer::timeout, this, &STouchFlickableList::slotClose);
        }
    }
}

void STouchFlickableList::hideEvent(QHideEvent *event)
{
    /// Unset highlight & index
    ///
    this->slotUnsetHighlight();

    /// Disconnect hide timer
    ///
    if (this->m_hideable)
    {
        if (this->hideTimer)
        {
            this->hideTimer->stop();
            disconnect(this->hideTimer, &QTimer::timeout, this, &STouchFlickableList::slotClose);

            delete this->hideTimer;
            this->hideTimer = nullptr;
        }

        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void STouchFlickableList::slotClose()
{

    //const QSignalBlocker blocker(timer);

    int duration = 0;

    if (this->m_animate)
    {
        /// Fade Out & Move Out
        ///
        duration = this->closeAnimation();
    }

    if (this->m_hideable)
    {
        QTimer::singleShot(duration, this, SLOT(hide()));
    }
}

int STouchFlickableList::showAnimation()
{
    QPropertyAnimation *animationPos = new QPropertyAnimation(this, "pos", this);
    animationPos->setEasingCurve(QEasingCurve::OutCirc);
    if (this->edge == Qt::LeftEdge)
    {
        animationPos->setDuration(400);
        animationPos->setStartValue(QPoint(-this->width(), 0));
        animationPos->setEndValue(QPoint(0, 0));
    }
    else if (this->edge == Qt::RightEdge)
    {
        animationPos->setDuration(200);
        animationPos->setStartValue(QPoint(qApp->desktop()->width() + this->width(), 0));
        animationPos->setEndValue(QPoint(qApp->desktop()->width() - this->width(), 0));
    }
    else if (this->edge == Qt::BottomEdge)
    {
        animationPos->setDuration(200);
        animationPos->setStartValue(QPoint(0, qApp->desktop()->height() + this->height()));
        animationPos->setEndValue(QPoint(0, qApp->desktop()->height() - this->height()));
    }

    QPropertyAnimation *animationOpa = new QPropertyAnimation(this, "windowOpacity", this);
    animationOpa->setEasingCurve(QEasingCurve::Linear);
    if (this->edge == Qt::LeftEdge)
    {
        animationOpa->setDuration(450);
        animationOpa->setStartValue(0.0);
        animationOpa->setEndValue(this->m_opacity);
    }
    else if (this->edge == Qt::RightEdge)
    {
        animationOpa->setDuration(300);
        animationOpa->setStartValue(0.0);
        animationOpa->setEndValue(this->m_opacity);
    }
    else if (this->edge == Qt::BottomEdge)
    {
        animationOpa->setDuration(300);
        animationOpa->setStartValue(0.0);
        animationOpa->setEndValue(this->m_opacity);
    }

    QParallelAnimationGroup *group = new QParallelAnimationGroup(this);
    group->addAnimation(animationPos);
    group->addAnimation(animationOpa);
    group->start(QPropertyAnimation::DeleteWhenStopped);

    return group->duration();
}

int STouchFlickableList::closeAnimation()
{
    QPropertyAnimation *animationOpa = new QPropertyAnimation(this, "windowOpacity", this);
    animationOpa->setEasingCurve(QEasingCurve::Linear);
    if (this->edge == Qt::LeftEdge)
    {
        animationOpa->setDuration(300);
        animationOpa->setStartValue(this->m_opacity);
        animationOpa->setEndValue(0.0);
    }
    else if (this->edge == Qt::RightEdge)
    {
        animationOpa->setDuration(200);
        animationOpa->setStartValue(this->m_opacity);
        animationOpa->setEndValue(0.0);
    }
    else if (this->edge == Qt::BottomEdge)
    {
        animationOpa->setDuration(200);
        animationOpa->setStartValue(this->m_opacity);
        animationOpa->setEndValue(0.0);
    }

    QPropertyAnimation *animationPos = new QPropertyAnimation(this, "pos", this);
    animationPos->setEasingCurve(QEasingCurve::InCirc);
    if (this->edge == Qt::LeftEdge)
    {
        animationPos->setDuration(350);
        animationPos->setStartValue(QPoint(0, 0));
        animationPos->setEndValue(QPoint(-this->width(), 0));
    }
    else if (this->edge == Qt::RightEdge)
    {
        animationPos->setDuration(250);
        animationPos->setStartValue(QPoint(qApp->desktop()->width() - this->width(), 0));
        animationPos->setEndValue(QPoint(qApp->desktop()->width() + this->width(), 0));
    }
    else if (this->edge == Qt::BottomEdge)
    {
        animationPos->setDuration(250);
        animationPos->setStartValue(QPoint(0, qApp->desktop()->height() - this->height()));
        animationPos->setEndValue(QPoint(0, qApp->desktop()->height() + this->height()));
    }

    QParallelAnimationGroup *group = new QParallelAnimationGroup(this);
    group->addAnimation(animationPos);
    group->addAnimation(animationOpa);
    group->start(QPropertyAnimation::DeleteWhenStopped);

    return group->duration();
}

void STouchFlickableList::slotUnsetHighlight()
{
    this->m_highlight = -1;
    this->m_highlightIndex = -1;
    update();
}

void STouchFlickableList::setScrollOffset(const QPoint &offset)
{
    int y = offset.y();

    if (y != this->m_offset)
    {
        this->m_offset = qBound(0, y, this->m_height * this->m_maxIndex - height());
        //this->m_offset = qBound(-1*(this->m_height * this->m_maxIndex -1), y, this->m_height * this->m_maxIndex - height());

        // DEBUG
        //qDebug() << "offset" << this->m_offset;

        update();
    }
}

QPoint STouchFlickableList::scrollOffset() const
{
    return QPoint(0, this->m_offset);
}

void STouchFlickableList::setOffset(const int &offset)
{
    this->setScrollOffset(QPoint(0, offset));
    update();
}

void STouchFlickableList::setCheckable(const bool &checkable)
{
    this->m_checkable = checkable;
}

void STouchFlickableList::setSelectable(const bool &selectable)
{
    this->m_selectable = selectable;
}

void STouchFlickableList::setEmpty()
{
    this->setText("");
    this->setParameter("");
    this->m_indexEmpty.push_back(this->m_widgetNames.size()-1);
    this->m_indexNoline.push_back(this->m_widgetNames.size()-1);
    this->m_indexNoline.push_back(this->m_widgetNames.size());
}

void STouchFlickableList::setTopic(const QString &topic)
{
    this->setText(topic);
    this->setParameter("");
    this->m_indexTopic.push_back(this->m_widgetNames.size()-1);
    this->m_indexNoline.push_back(this->m_widgetNames.size()-1);
}

void STouchFlickableList::setTopic(const QString &topic, const int &index)
{
    this->setText(topic, index);
}

void STouchFlickableList::setText(const QString &text)
{
    this->m_widgetNames.push_back(text);
}

void STouchFlickableList::setText(const QString &text, const int &index)
{
    this->m_widgetNames[index] = text;
    update();
}

QString STouchFlickableList::getText(const int &index) const
{
    return this->m_widgetNames[index];
}

void STouchFlickableList::setParameter(const int &param)
{
    this->m_widgetParameter.push_back(QString::number(param));
}

void STouchFlickableList::setParameter(const uint64_t &param)
{
    this->m_widgetParameter.push_back(QString::number(param));
}
void STouchFlickableList::setParameter(const double &param)
{
    this->m_widgetParameter.push_back(QString::number(param));
}

void STouchFlickableList::setParameter(const QString &param)
{
    this->m_widgetParameter.push_back(param);
}

void STouchFlickableList::setParameter(const int &param, const int &index)
{
    this->m_widgetParameter[index] = QString::number(param);
    update();
}

void STouchFlickableList::setParameter(const uint64_t &param, const int &index)
{
    this->m_widgetParameter[index] = QString::number(param);
    update();
}

void STouchFlickableList::setParameter(const double &param, const int &index)
{
    this->m_widgetParameter[index] = QString::number(param);
    update();
}

void STouchFlickableList::setParameter(const QString &param, const int &index)
{
    this->m_widgetParameter[index] = param;
    update();
}


QString STouchFlickableList::getParameter(const int &index) const
{
    return this->m_widgetParameter[index];
}

void STouchFlickableList::setIndexOf(const int &index)
{
    this->m_selectedIndex = index;
    update();
}

void STouchFlickableList::setIndexOf(const QString &text)
{
    int index = 0;

    foreach (QString str, this->m_widgetNames)
    {
        if (str.contains(text))
        {
            this->m_selectedIndex = index;
        }

        ++index;
    }

    update();
}

int STouchFlickableList::getIndex() const
{
    return this->m_selectedIndex;
}

void STouchFlickableList::setPixmap(const QPixmap &pix)
{
    this->m_widgetPixmap.push_back(pix);
}

void STouchFlickableList::setRowHeight(const int height)
{
    this->m_set_height = height;
    update();
}

void STouchFlickableList::setScaleIcon(const double scale)
{
    this->m_scale_icon = scale;
    update();
}

void STouchFlickableList::setBackgroundColor(const QColor &color)
{
    this->background_color = color;
    update();
}

QColor STouchFlickableList::getBackgroundColor() const
{
    return this->background_color;
}

void STouchFlickableList::setEmptyColor(const QColor &color)
{
    this->empty_color = color;
    update();
}

void STouchFlickableList::setTopicColor(const QColor &color)
{
    this->topic_color = color;
    update();
}

void STouchFlickableList::setHighlightColor(const QColor &color)
{
    this->highlight_color = color;
    update();
}

void STouchFlickableList::setSelectColor(const QColor &color)
{
    this->selected_color = color;
    update();
}

void STouchFlickableList::setFontTopicColor(const QColor &color)
{
    this->font_topic_color = color;
    update();
}

void STouchFlickableList::setFontTextColor(const QColor &color)
{
    this->font_text_color = color;
    update();
}

void STouchFlickableList::setFontParameterColor(const QColor &color)
{
    this->font_parameter_color = color;
    update();
}

void STouchFlickableList::setParameterColor(const QColor &color)
{
    this->font_parameter_color = color;
    update();
}

void STouchFlickableList::setFontSize(const int &size, const bool bold)
{
    this->font_size.setPointSize(size);
    this->font_size.setBold(bold);
    update();
}

void STouchFlickableList::setFontSizeParamter(const int &size, const bool bold)
{
    this->font_size_param.setPointSize(size);
    this->font_size_param.setBold(bold);
    update();
}

void STouchFlickableList::setTextAlignment(const Qt::AlignmentFlag &alignmentFlag)
{
    this->alignmentFlag = alignmentFlag;
}

void STouchFlickableList::setOpacity(const double opacity)
{
    this->setWindowOpacity(opacity);
    this->m_opacity = opacity;
    update();
}

double STouchFlickableList::getOpacity() const
{
    return this->m_opacity;
}

void STouchFlickableList::setWindowWidth(const int width)
{
    this->setFixedWidth(width);
    update();
}

void STouchFlickableList::setWindowHeight(const int height)
{
    this->setFixedHeight(height);
    update();
}

int STouchFlickableList::size() const
{
    int size = 0;

    if (!this->m_widgetNames.isEmpty())
    {
        size = this->m_widgetNames.size();
    }
    else if (!this->m_widgetPixmap.isEmpty())
    {
         size = this->m_widgetPixmap.size();
    }

    return size;
}

void STouchFlickableList::setHideable(const bool &hideable)
{
    if (hideable)
    {
        this->setObjectName("");
    }

    this->m_hideable = hideable;
    update();
}

void STouchFlickableList::enableAnimation(const bool animate, const Qt::Edge &edge)
{
    this->m_animate = animate;
    this->edge = edge;
    update();
}

void STouchFlickableList::enableDrawLine(const bool drawline, const QColor &color)
{
    this->m_drawline = drawline;
    this->line_color = color;
    update();
}

void STouchFlickableList::changeEvent(QEvent* event)
{
    switch(event->type())
    {
    case QEvent::LanguageChange:
        //this->repaint();
        break;
    case QEvent::LocaleChange:
        break;
    default:
        break;
    }

    QWidget::changeEvent(event);
}
