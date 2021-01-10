#ifndef SDATABASEODOMETER_H
#define SDATABASEODOMETER_H

#include "../widget/base/SBaseThread.h"

#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QDateTime>
#include <QString>
#include <QHash>


//class SDatabaseOdometer : public QSqlQueryModel, SBaseThread
class SDatabaseOdometer : public SBaseThread
{
    Q_OBJECT

public:
    SDatabaseOdometer(QObject * parent = nullptr);
    SDatabaseOdometer(const QString & name, const QString & path, QObject * parent = nullptr);
    ~SDatabaseOdometer();

    void create(const QString & name, const QString & path);

    /**
     * @brief stream Stream an amount of quantity from the database. If the quantity if reached the stream will pause until its called again.
     * @param quantity The quantity will be load at one stream.
     */
    void stream(const int quantity = 0);

    /**
     * @brief process Stores the values on the process table.
     * @param length
     * @param measured
     * @param complete
     * @param elapsed
     * @param date
     * @param time
     * @return Returns true if the storage was successfule, otherwise false.
     */
    bool process(const QString &length, const QString &measured, const int complete, const qint64 elapsed, const QString &date = QDate::currentDate().toString("dd/MM/yyyy"), const QString &time = QTime::currentTime().toString("hh:mm"));

    /**
     * @brief process
     * @param id
     * @return Returns the process table by id.
     */
    QHash<QString, QString> process(const int id);

    /**
     * @brief process
     * @return Returns all stored value from the process table.
     */
    QVector<QHash<QString, QString> > process();

    /**
     * @brief statistics
     * @param measured Total measurements (datatype double).
     * @param elapsed Total duration time of all orders (datatype long long).
     * @param counter Tolal order counter (datatype int).
     * @return Returns true if the storage was successfule, otherwise false.
     */
    bool statistics(const double measured, const qint64 elapsed, const uint counter = 1);

    /**
     * @brief statistics
     * @return Returns all stored value from the statistics table.
     */
    QHash<QString, QString> statistics();

    int getSize();

    bool deleteMeasurement(const int id);
    bool deleteAllMeasurement();
    bool removeTotal(const double measured, const qint64 elapsed);

    bool setAutoIncrement(const int value);

    double getLength(const int id);

    int getID();
    int getID(const int index);
    int getNextID();

    QString getSN();

    int quantity() const;

signals:
    void signalStream(QHash<QString, QString> hash);
    void signalId(QHash<QString, QString> hash);
    void signalStatistics(QHash<QString, QString> hash);

public slots:
    void slotStream(const int quantity);
    void slotId(const int id);
    void slotStatistics();

protected:
    void run() override;

private:
    /* Function members */
    void createTabelProcess();
    void createTabelStatistics();
    void createTabelAnalytics();

    void app();
    void path(const QString & path);
    void name(const QString & name);

    /* Members */
    int m_quantity = 0;
    QString m_path = "";
    QString m_name = "";

    /* Data members */
    QSqlDatabase db;
};

#endif /* SDATABASEODOMETER_H */
