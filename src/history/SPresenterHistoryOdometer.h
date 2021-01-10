#ifndef SPRESENTERHISTORYODOMETER_H
#define SPRESENTERHISTORYODOMETER_H

#include "../widget/base/SBasePresenter.h"

#include <QObject>
#include <QWidget>
#include <QDialog>

class SModelHistoryOdometer;
class SViewHistoryOdometer;


class SPresenterHistoryOdometer : public SBasePresenter
{
    Q_OBJECT

public:
    explicit SPresenterHistoryOdometer(QWidget * parent = nullptr);
    explicit SPresenterHistoryOdometer(const QDialog * options, QWidget * parent = nullptr);
    explicit SPresenterHistoryOdometer(const QObject * view, const QObject * model, QWidget * parent = nullptr);
    ~SPresenterHistoryOdometer();

public slots:
    /**
     * @brief create Call funtions on create.
     */
    void create();

private:
    /* Funtion members */
    void setupWidget();
    void setConnect();
    void setConnect(const QDialog * view);
    void setConnect(const QObject * view, const QObject * model);

    /* MVP members */
    SModelHistoryOdometer * modelHistoryOdometer = nullptr;
    SViewHistoryOdometer * viewHistoryOdometer = nullptr;
};

#endif /* SPRESENTERHISTORYODOMETER_H */
