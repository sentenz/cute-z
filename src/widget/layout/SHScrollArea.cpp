#include "SHScrollArea.h"

#include <QScrollBar>
#include <QScroller>
#include <QTimer>


SHScrollArea::SHScrollArea(QWidget *parent) : QScrollArea(parent)
{
    this->setWidgetResizable(true);
    this->horizontalScrollBar()->setEnabled(true);
    this->verticalScrollBar()->setEnabled(false);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setFrameShape(QFrame::NoFrame);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    this->setContentsMargins(0, 0, 0, 0);
    this->setStyleSheet(this->formStyleSheet());

    QScroller::grabGesture(viewport(), QScroller::LeftMouseButtonGesture);
}

bool SHScrollArea::eventFilter(QObject *object, QEvent *event)
{
    // This works because QScrollArea::setWidget installs an eventFilter on the widget
    if (object && object == widget() && event->type() == QEvent::Resize)
    {
        QTimer::singleShot(0, this, SLOT(slotSetMinimumHeight()));
    }

    return QScrollArea::eventFilter(object, event);
}

void
SHScrollArea::enableScrollBar(const bool enable)
{
    if (enable)
    {
        this->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    }
    else
    {
        this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    }
}

void
SHScrollArea::slotSetMinimumHeight()
{
    this->setMinimumHeight(widget()->minimumSizeHint().height());
}

QString
SHScrollArea::formStyleSheet()
{
    QString sheet = "";

    sheet = " \
            QWidget { border-image: none; background: transparent; background-color: transparent; border: none; } \
            QScrollBar:horizontal { border: none; background: " + ::GlobalColorContrast.name() + "; height: 3px; margin: 0 0 0 0; } \
            QScrollBar::handle:horizontal { background: " + ::GlobalColorHighlight.name() + "; min-width: 3px; } \
            QScrollBar::add-line:horizontal { border: none; background: none; width: 0px; subcontrol-position: none; subcontrol-origin: margin; } \
            QScrollBar::sub-line:horizontal { border: none; background: none; width: 0px; subcontrol-position: none; subcontrol-origin: margin; } \
            QScrollBar::up-arrow:horizontal, QScrollBar::down-arrow:horizontal { border: none; width: 0px; height: 0px; background: none; } \
            QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal { background: none; } \
            ";

    return sheet;
}
