#ifndef SMODELHISTORYDETAIL_H
#define SMODELHISTORYDETAIL_H

#include "../widget/base/SBaseModel.h"
#include "../database/SDatabase.h"


class SModelHistoryDetail : public SBaseModel
{
    Q_OBJECT

public:
    explicit SModelHistoryDetail(QObject * parent = nullptr);
    ~SModelHistoryDetail();

signals:
    void signalStream(const int quantity);
    void signalStream(QHash<QString, QString> hash);
    void signalStatistics();
    void signalStatistics(QHash<QString, QString> hash);

private:
    /* Funtion members */
    void setupWidget();
    void setConnect();

    /* Members */
    SDatabase * database = nullptr;
};

#endif /* SMODELHISTORYDETAIL_H */
