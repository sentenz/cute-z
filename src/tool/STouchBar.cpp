#include "STouchBar.h"
#include "../widget/layout/SHScrollArea.h"
#include "../widget/button/SToolButton.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QTimer>
#include <QPushButton>
#include <QToolButton>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QShowEvent>
#include <QHideEvent>
#include <QFocusEvent>
#include <QLabel>
#include <QIcon>
#include <QEvent>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QLinearGradient>
#include <QPaintEvent>
#include <QPainter>
#include <QDebug>


STouchBar::STouchBar(QWidget *parent) : QDialog(parent)
{
    this->setObjectName("STouchBar");
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->setWindowFlags(this->windowFlags() | Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_AcceptTouchEvents);
    this->setWindowState(Qt::WindowActive);
    this->activateWindow();
    this->raise();
    this->setFocus();

    this->setupLayout();
    this->setConnect();
}

STouchBar::~STouchBar()
{
    if (this->m_hideTimer != nullptr)
    {
        delete this->m_hideTimer;
        this->m_hideTimer = nullptr;
    }
}

void STouchBar::setupLayout()
{
    /// Time to hide bar when you leave desktop
    this->m_hideTimer = new QTimer;

    /// BUTTON
    SToolButton *buttonLevel0 = new SToolButton;
    buttonLevel0->setImage(":/images/ic_power_white_128dp.svg");
    buttonLevel0->setText("Power");
    buttonLevel0->setIconSize(QSize(70, 70));
    buttonLevel0->setToolButtonStyle(Qt::ToolButtonIconOnly);
//    buttonLevel0->setTheme(SToolButton::Style::Rect);

    SToolButton *buttonLevel1 = new SToolButton;
    buttonLevel1->setImage(":/images/ic_settings_white_128dp.svg");
    buttonLevel1->setText("Options");
    buttonLevel1->setIconSize(QSize(70, 70));
    buttonLevel1->setToolButtonStyle(Qt::ToolButtonIconOnly);
//    buttonLevel1->setTheme(SToolButton::Style::Rect);

    SToolButton *buttonLevel2 = new SToolButton;
    buttonLevel2->setImage(":/images/ic_widgets_white_128dp.svg");
    buttonLevel2->setText("Desktop");
    buttonLevel2->setIconSize(QSize(70, 70));
    buttonLevel2->setToolButtonStyle(Qt::ToolButtonIconOnly);
//    buttonLevel2->setTheme(SToolButton::Style::Rect);

    SToolButton *buttonLevel3 = new SToolButton;
    buttonLevel3->setImage(":/images/ic_lock_white_128dp.svg");
    buttonLevel3->setText("Lock");
    buttonLevel3->setIconSize(QSize(70, 70));
    buttonLevel3->setToolButtonStyle(Qt::ToolButtonIconOnly);
//    buttonLevel3->setTheme(SToolButton::Style::Rect);

    /// BUTTON GROUP
    int iter = 0;
    this->buttonGroup = new QButtonGroup(this);
    this->buttonGroup->addButton(buttonLevel0, iter++);
    this->buttonGroup->addButton(buttonLevel2, iter++);
    this->buttonGroup->addButton(buttonLevel1, iter++);
    this->buttonGroup->addButton(buttonLevel3, iter++);
    this->buttonGroup->setExclusive(true);

    // Layout Button
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(buttonLevel0);
    buttonLayout->addWidget(buttonLevel2);
    buttonLayout->addWidget(buttonLevel1);
    buttonLayout->addWidget(buttonLevel3);
    buttonLayout->setSpacing(0);
    buttonLayout->setMargin(0);
    buttonLayout->setContentsMargins(0, 0, 0, 0);
    // Widget
    QWidget *widget = new QWidget;
    widget->setLayout(buttonLayout);
    // Scroll Area
    SHScrollArea *scrollArea = new SHScrollArea(this);
    scrollArea->setWidget(widget);

//#include <QGraphicsScene>
//#include <QGraphicsProxyWidget>
//#include <QGraphicsView>

//QWidget *widget = new QWidget;
//widget->setLayout(buttonLayout);
//QGraphicsScene *scene = new QGraphicsScene(this);
//QGraphicsProxyWidget *proxy = scene->addWidget(widget);
//proxy->setRotation(-45);
//QGraphicsView *view = new QGraphicsView(this);
//view->setScene(scene);

//QVBoxLayout *mainLayout = new QVBoxLayout(this);
//mainLayout->addWidget(view);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(scrollArea);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    setLayout(mainLayout);
}

void STouchBar::setConnect()
{
    /// Buttongroup
    connect(this->buttonGroup, SIGNAL(buttonPressed(int)), this, SLOT(slotButtonPressed(int)));
    connect(this->buttonGroup, SIGNAL(buttonReleased(int)), this, SLOT(slotButtonReleased(int)));
    connect(this->buttonGroup, SIGNAL(buttonClicked(int)), this, SIGNAL(signalClicked(int)));
    /// Timer
    connect(this->m_hideTimer, &QTimer::timeout, this, &STouchBar::slotClose);
}

void STouchBar::slotButtonPressed(const int index)
{
    this->buttonGroup->button(index)->setChecked(true);
}

void STouchBar::slotButtonReleased(const int index)
{
    this->buttonGroup->setExclusive(false);
    this->buttonGroup->button(index)->setChecked(false);
    this->buttonGroup->setExclusive(true);

    /// At a gestuere close event emit no signals
    if (this->m_gesture)
    {
        return;
    }

    /// Signal emiter for index, content and combination of two
    if (index >= 0)
    {
        emit signalCurrentIndex(index);
    }

    if (!this->buttonGroup->button(index)->text().isEmpty())
    {
        emit signalCurrentContent(this->buttonGroup->button(index)->text());
        emit signalCurrentIndexContent(index, this->buttonGroup->button(index)->text());
    }
}

void STouchBar::mousePressEvent(QMouseEvent *event)
{
    this->m_delta = event->pos();

    if (event->isAccepted())
    {
        return;
    }

    event->accept();
    update();
}

void STouchBar::mouseReleaseEvent(QMouseEvent *event)
{
    this->m_delta = QPoint(0, 0);

    if (event->isAccepted())
    {
        return;
    }

    event->accept();
    update();
}

void STouchBar::mouseMoveEvent(QMouseEvent *event)
{
    this->gesture(event);

    if (event->isAccepted())
    {
        return;
    }

    event->accept();
    update();
}

void STouchBar::gesture(QMouseEvent *event)
{
    // Work around QGestureEvent
    //
    if (this->m_hide)
    {
        if (this->m_edge == Qt::BottomEdge)
        {
            if (abs(this->m_delta.x() - event->pos().x()) < 15)
            {
                if (this->m_delta.y() - event->pos().y() < -15)
                {
                    this->m_delta = QPoint(0, 0);

                    this->m_gesture = true;
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

int STouchBar::showAnimation()
{
    QPropertyAnimation *animationPos = new QPropertyAnimation(this, "pos", this);
    animationPos->setEasingCurve(QEasingCurve::Linear);
    if (this->m_edge == Qt::BottomEdge)
    {
        animationPos->setDuration(300);
        animationPos->setStartValue(QPoint(0, qApp->desktop()->height() + this->height()));
        animationPos->setEndValue(QPoint(0, qApp->desktop()->height() - this->height()));
    }

    QPropertyAnimation *animationOpa = new QPropertyAnimation(this, "windowOpacity", this);
    animationOpa->setEasingCurve(QEasingCurve::InCubic);
    if (this->m_edge == Qt::BottomEdge)
    {
        animationOpa->setDuration(300);
        animationOpa->setStartValue(0);
        animationOpa->setEndValue(1);
    }

    QParallelAnimationGroup *group = new QParallelAnimationGroup(this);
    group->addAnimation(animationPos);
    group->addAnimation(animationOpa);
    group->start(QPropertyAnimation::DeleteWhenStopped);

    return group->duration();
}

int STouchBar::closeAnimation()
{
    QPropertyAnimation *animationPos = new QPropertyAnimation(this, "pos", this);
    animationPos->setEasingCurve(QEasingCurve::Linear);
    if (this->m_edge == Qt::BottomEdge)
    {
        animationPos->setDuration(500);
        animationPos->setStartValue(QPoint(0, qApp->desktop()->height() - this->height()));
        animationPos->setEndValue(QPoint(0, qApp->desktop()->height() + this->height()));
    }

    QPropertyAnimation *animationOpa = new QPropertyAnimation(this, "windowOpacity", this);
    animationOpa->setEasingCurve(QEasingCurve::OutCubic);
    if (this->m_edge == Qt::BottomEdge)
    {
        animationOpa->setDuration(500);
        animationOpa->setStartValue(1);
        animationOpa->setEndValue(0);
    }

    QParallelAnimationGroup *group = new QParallelAnimationGroup(this);
    group->addAnimation(animationPos);
    group->addAnimation(animationOpa);
    group->start(QPropertyAnimation::DeleteWhenStopped);

    return group->duration();
}

void STouchBar::fadeOut()
{
    this->m_hiding = true;

    QTimer::singleShot(this->closeAnimation(), this, SLOT(hide()));
}

void STouchBar::slotClose()
{
    if (this->m_hiding || !this->m_hide)
    {
        return;
    }
    this->m_hiding = true;

    QTimer::singleShot(this->closeAnimation(), this, SLOT(hide()));
}

void STouchBar::focusOutEvent(QFocusEvent* event)
{
    if (event->type() == QEvent::FocusOut)
    {
        QTimer::singleShot(400, this, SLOT(slotClose()));
    }
}

void STouchBar::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);

    if (!this->m_hide)
    {
        return;
    }

    /// Fade In & Move In
    this->showAnimation();

    /// Hide after a while if not touched
    if (this->m_hide)
    {
        this->m_hideTimer->start(5000);
        this->setFocus();
    }

    this->m_hiding = false;
    this->m_gesture = false;

    emit this->finished(0);
}

void STouchBar::hideEvent(QHideEvent *event)
{
    Q_UNUSED(event);

    this->m_hideTimer->stop();
}

void STouchBar::setDock(const Qt::Edge &edge)
{
    this->m_edge = edge;
    update();
}

void STouchBar::setHideable(const bool &hide)
{
    this->m_hide = hide;

    /// Hide after a while if not touched
    if (this->m_hide)
    {
        this->m_hideTimer->start(5000);
    }
    else
    {
        this->m_hideTimer->stop();
    }
    update();
}

void STouchBar::setOpacity(const double opacity)
{
    this->m_opacity = qBound(0.0, opacity, 1.0);
    this->setWindowOpacity(this->m_opacity);
    update();
}

double STouchBar::getOpacity() const
{
    return this->m_opacity;
}

int STouchBar::setDisabledButton(const int &index, const bool &disable)
{
    if (index < this->buttonGroup->buttons().size())
    {
        this->buttonGroup->button(index)->setVisible(disable);
        return 0;
    }
    return -1;
}

void STouchBar::retranslateUI()
{
}

void
STouchBar::restyleUI()
{
    if (this->m_colorBase != ::GlobalColorCustomBase)
    {
        this->m_colorBase = ::GlobalColorCustomBase;
        this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    }
    if (this->m_colorContrast != ::GlobalColorCustomContrast)
    {
        this->m_colorContrast = ::GlobalColorCustomContrast;
    }
    if (this->m_colorText != ::GlobalColorCustomText)
    {
        this->m_colorText = ::GlobalColorCustomText;
    }
    if (this->m_colorHighlight != ::GlobalColorCustomHighlight)
    {
        this->m_colorHighlight = ::GlobalColorCustomHighlight;
    }
}

void
STouchBar::changeEvent(QEvent * event)
{
    switch (event->type())
    {
    case QEvent::LanguageChange:
        this->retranslateUI();
        break;

    case QEvent::StyleChange:
        this->restyleUI();
        break;

    case QEvent::LocaleChange:
        break;

    default:
        break;
    }

    QWidget::changeEvent(event);
}
