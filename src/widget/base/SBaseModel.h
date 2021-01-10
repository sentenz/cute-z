#ifndef SBASEMODEL_H
#define SBASEMODEL_H

#include "../build/SGlobal.h"

#include <QObject>


class SBaseModel : public QObject
{
    Q_OBJECT

public:
    explicit SBaseModel(QObject * parent = nullptr);
};

#endif /* SBASEMODEL_H */
