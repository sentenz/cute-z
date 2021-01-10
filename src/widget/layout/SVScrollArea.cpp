#include "SVScrollArea.h"

#include <QScrollBar>
#include <QScroller>
#include <QTimer>


SVScrollArea::SVScrollArea(QWidget *parent)
    : QScrollArea(parent)
{
    this->setWidgetResizable(true);
    this->horizontalScrollBar()->setEnabled(false);
    this->verticalScrollBar()->setEnabled(true);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setFrameShape(QFrame::NoFrame);
    this->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    this->setContentsMargins(0, 0, 0, 0);
    this->setStyleSheet(this->formStyleSheet());

    QScroller::grabGesture(viewport(), QScroller::LeftMouseButtonGesture);
}

// WARNING: maybe unnecessary eventFilter!
bool
SVScrollArea::eventFilter(QObject *object, QEvent *event)
{
    // This works because QScrollArea::setWidget installs an eventFilter on the widget
    if (object && object == widget() && event->type() == QEvent::Resize)
    {
        QTimer::singleShot(0, this, SLOT(slotSetMinimumWidth()));
    }

    return QScrollArea::eventFilter(object, event);
}

void
SVScrollArea::enableScrollBar(const bool enable)
{
    if (enable)
    {
        this->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    }
    else
    {
        this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    }
}

void
SVScrollArea::slotSetMinimumWidth()
{
    this->setMinimumWidth(widget()->minimumSizeHint().width());
}

QString
SVScrollArea::formStyleSheet()
{
    QString sheet = "";

    sheet = " \
            QWidget { border-image: none; background: transparent; background-color: transparent; border: none; } \
            QScrollBar:vertical { border: none; background: " + ::GlobalColorCustomContrast.name() + "; width: 3px; margin: 0 0 0 0; } \
            QScrollBar::handle:vertical { background: " + ::GlobalColorCustomHighlight.name() + "; min-height: 3px; } \
            QScrollBar::add-line:vertical { border: none; background: none; height: 0px; subcontrol-position: none; subcontrol-origin: margin; } \
            QScrollBar::sub-line:vertical { border: none; background: none; height: 0px; subcontrol-position: none; subcontrol-origin: margin; } \
            QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical { border: none; width: 0px; height: 0px; background: none; } \
            QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical { background: none; } \
            ";

    return sheet;
}
