#ifndef SVSCROLLAREA_H
#define SVSCROLLAREA_H

#include "../build/SGlobal.h"

#include "QEvent"
#include <QScrollArea>


class SVScrollArea : public QScrollArea
{
    Q_OBJECT

public:
    explicit SVScrollArea(QWidget * parent = nullptr);

    void enableScrollBar(const bool enable);

protected:
    virtual bool eventFilter(QObject *object, QEvent *event);

private slots:
    void slotSetMinimumWidth();

private:
    QString formStyleSheet();
};

#endif // SVSCROLLAREA_H
