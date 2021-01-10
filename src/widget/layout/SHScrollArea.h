#ifndef SHSCROLLAREA_H
#define SHSCROLLAREA_H

#include "../build/SGlobal.h"

#include <QEvent>
#include <QScrollArea>


class SHScrollArea : public QScrollArea
{
    Q_OBJECT

public:
    explicit SHScrollArea(QWidget * parent = nullptr);

    void enableScrollBar(const bool enable);

protected:
    virtual bool eventFilter(QObject *object, QEvent *event);

private slots:
    void slotSetMinimumHeight();
    QString formStyleSheet();
};

#endif // SHSCROLLAREA_H
