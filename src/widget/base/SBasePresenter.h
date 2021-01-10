#ifndef SBASEPRESENTER_H
#define SBASEPRESENTER_H

#include "../build/SGlobal.h"

#include <QWidget>


class SBasePresenter : public QWidget
{
    Q_OBJECT

public:
    explicit SBasePresenter(QWidget * parent = nullptr);
};

#endif /* SBASEPRESENTER_H */
