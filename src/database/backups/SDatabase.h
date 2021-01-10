#ifndef SDATABASE_H
#define SDATABASE_H

#include <QSqlDatabase>
#include <QDateTime>
#include <QString>


class SDatabase
{
public:
    SDatabase(const QString &path);
    ~SDatabase();

    bool saveMeasurement(const double &ordering, const double &measured, const QString &date = QDateTime::currentDateTime().toString("dd MMM. yyyy hh:mm:ss"));
    QString getMeasurement(const int &id);

    bool initAutoIncrement();
    void getAllMeasurement();
    bool deleteMeasurement(const int &id);
    bool deleteAllMeasurement();
    bool saveToAbolutLength(const double &measured);
    bool deleteFromAbsolutLength(const double &measured);
    double getAbsolutLength();
    double getLength(const int &id);
    int getNextID();
    int getCount();

private:
    QSqlDatabase db;
};

#endif /// SDATABASE_H
