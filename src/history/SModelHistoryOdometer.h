#ifndef SMODELHISTORYODOMETER_H
#define SMODELHISTORYODOMETER_H

#include "../widget/base/SBaseModel.h"
#include "../database/SDatabaseOdometer.h"


class SModelHistoryOdometer : public SBaseModel
{
    Q_OBJECT

public:
    explicit SModelHistoryOdometer(QObject * parent = nullptr);
    ~SModelHistoryOdometer();

signals:
    void signalStream(const int quantity);
    void signalStream(QHash<QString, QString> hash);
    void signalId(const int id);
    void signalId(QHash<QString, QString> hash);
    void signalStatistics();
    void signalStatistics(QHash<QString, QString> hash);

private slots:
    void slotStream(QHash<QString, QString> hash);
    void slotId(QHash<QString, QString> hash);
    void slotStatistics(QHash<QString, QString> hash);

private:
    /* Funtion members */
    void setupWidget();
    void setConnect();

    QString html(const QString top, const QString bottom, const QString unit = "");

    /* Members */
    SDatabaseOdometer * database = nullptr;
};

#endif /* SMODELHISTORYODOMETER_H */
