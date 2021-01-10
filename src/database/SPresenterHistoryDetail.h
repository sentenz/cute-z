#ifndef SPRESENTERHISTORYDETAIL_H
#define SPRESENTERHISTORYDETAIL_H

#include "../widget/base/SBasePresenter.h"

#include <QObject>
#include <QWidget>

class SModelHistoryDetail;
class SViewHistoryDetail;


class SPresenterHistoryDetail : public SBasePresenter
{
    Q_OBJECT

public:
    explicit SPresenterHistoryDetail(QWidget * parent = nullptr);
    explicit SPresenterHistoryDetail(const QObject * view = nullptr, const QObject * model = nullptr, QWidget * parent = nullptr);
    ~SPresenterHistoryDetail();

    /**
     * @brief create Call funtions on create.
     */
    void create();

private:
    /* Funtion members */
    void setupWidget();
    void setConnect();
    void setConnect(const QObject * view, const QObject * model);

    /* MVP members */
    SModelHistoryDetail * modelHistoryDetail = nullptr;
    SViewHistoryDetail * viewHistoryDetail = nullptr;
};

#endif /* SPRESENTERHISTORYDETAIL_H */
