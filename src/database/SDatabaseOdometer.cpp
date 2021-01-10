#include "SDatabaseOdometer.h"

#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDir>
#include <QNetworkInterface>
#include <QHash>
#include <QVector>
#include <QDebug>

#include <math.h>


SDatabaseOdometer::SDatabaseOdometer(QObject * parent)
    : SBaseThread(parent)
{
    this->setObjectName("SDatabaseOdometer");

    qRegisterMetaType<QHash<QString, QString> >("SDatabaseOdometer");
}

SDatabaseOdometer::SDatabaseOdometer(const QString & name,
                                     const QString &path,
                                     QObject * parent)
    : SBaseThread(parent)
{
    this->setObjectName("SDatabaseOdometer");

    this->create(name, path);

    qRegisterMetaType<QHash<QString, QString> >("SDatabaseOdometer");
}

SDatabaseOdometer::~SDatabaseOdometer()
{
    QString connection;

    if (this->db.isOpen())
    {
        this->db.close();
        connection = QSqlDatabase::database().connectionName();
    }

    QSqlDatabase::removeDatabase(connection);
}

void
SDatabaseOdometer::path(const QString & path)
{
    this->m_path = path;

    QDir dir(path);
    if (!dir.exists())
    {
        dir.mkpath(path);
    }
}

void
SDatabaseOdometer::name(const QString & name)
{
    this->m_name = name;
}

void
SDatabaseOdometer::create(const QString & name,
                          const QString &path)
{
    this->name(name);
    this->path(path);

    /* DATABASE */
    this->db = QSqlDatabase::addDatabase("QSQLITE");
    this->db.setDatabaseName(this->m_path  + "/" + this->m_name);

    if (this->db.open())
    {
        this->createTabelProcess();
        this->createTabelStatistics();
        this->createTabelAnalytics();
    }
    else
    {
        qDebug() << "Error: connection with database fail";
    }
}

void
SDatabaseOdometer::createTabelProcess()
{
    /* Query */
    QSqlQuery query(this->db);

    /* Process tabel */
    if (!query.exec("CREATE TABLE IF NOT EXISTS Process"
                    "(id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE, "
                    "length TEXT, "
                    "measured TEXT, "
                    "date TEXT, "
                    "time TEXT, "
                    "sn TEXT, "
                    "complete INTEGER, "
                    "elapsed BIGINT)"))
    {
         qDebug() << "SDatabaseOdometer create Process table error: " << query.lastError();
    }
}

void
SDatabaseOdometer::createTabelStatistics()
{
    /* Query */
    QSqlQuery query(this->db);

    /* Statistics table */
    if (!query.exec("CREATE TABLE IF NOT EXISTS Statistics "
                    "(id INTEGER PRIMARY KEY, "
                    "length DOUBLE, "
                    "counter INTEGER, "
                    "time INTEGER)"))
    {
        qDebug() << "SDatabaseOdometer create Statistics table error: " << query.lastError();
    }

    // Initialize
    if (query.exec("SELECT COUNT(*) FROM Statistics"))
    {
        if (query.next())
        {
            if (!query.value(0).toInt())
            {
                if(!query.exec("INSERT INTO Process "
                               "(length, measured, date, time, sn, complete, elapsed) "
                               "VALUES "
                               "('0.0', '0.0', ' ', ' ', ' ', 0, 0)"))
                {
                    qDebug() << "SDatabaseOdometer create Process insert error: " << query.lastError();
                }
                this->deleteAllMeasurement();

                if(!query.exec("INSERT INTO Statistics "
                               "(id, length, counter, time) "
                               "VALUES "
                               "(0, 0, 0.0, 0)"))
                {
                    qDebug() << "SDatabaseOdometer create Statistics insert error: " << query.lastError();
                }
            }
        }
    }
}

void
SDatabaseOdometer::createTabelAnalytics()
{
}

bool
SDatabaseOdometer::process(const QString &length,
                          const QString &measured,
                          const int complete,
                          const qint64 elapsed,
                          const QString &date,
                          const QString &time)
{
    QSqlQuery query(this->db);
    query.prepare("INSERT INTO Process "
                  "(length, measured, date, time, sn, complete, elapsed)"
                  " VALUES "
                  "(:length, :measured, :date, :time, :sn, :complete, :elapsed)");
    query.bindValue(":length", length);
    query.bindValue(":measured", measured);
    query.bindValue(":date", date);
    query.bindValue(":time", time);
    query.bindValue(":sn", this->getSN());
    query.bindValue(":complete", complete);
    query.bindValue(":elapsed", elapsed);

    if (!query.exec())
    {
        qFatal("SDatabaseOdometer INSERT measurement query failed: %s", qPrintable(query.lastError().text()));
    }

    this->statistics(measured.toDouble(), elapsed);

//    QSqlQueryModel model;
//    model.setQuery(query);
//    if (model.lastError().isValid())
//    {
//        qFatal("Cannot set query on SDatabaseOdometer: %s", qPrintable(model.lastError().text()));

//        return false;
//    }

    return true;
}

QHash<QString, QString>
SDatabaseOdometer::process(const int id)
{
    QHash<QString, QString> t_hash;

    QSqlQuery query(this->db);
    query.prepare("SELECT "
                  "id, length, measured, date, time, sn, complete, elapsed "
                  "FROM Process "
                  "WHERE id = :id");
    query.bindValue(":id", id);
    if(query.exec())
    {
        if (query.next())
        {
            t_hash.insert("id", query.value(0).toString());
            t_hash.insert("length", query.value(1).toString());
            t_hash.insert("measured", query.value(2).toString());
            t_hash.insert("date", query.value(3).toString());
            t_hash.insert("time", query.value(4).toString());
            t_hash.insert("sn", query.value(5).toString());
            t_hash.insert("complete", query.value(6).toString());
            t_hash.insert("elapsed", query.value(7).toString());

//            qDebug() << QString("ID %1; Order %2 m; Measured %3 m; Date  %4 & Time %5; SN %6; Complete %7; Elapsed %8;")
//                        .arg(query.value(0).toString())
//                        .arg(query.value(1).toString())
//                        .arg(query.value(2).toString())
//                        .arg(query.value(3).toString())
//                        .arg(query.value(4).toString())
//                        .arg(query.value(5).toString())
//                        .arg(query.value(6).toString())
//                        .arg(query.value(7).toString());
        }
    }

//    QSqlQueryModel model;
//    model.setQuery(query);
//    if (model.lastError().isValid())
//    {
//        qFatal("Cannot set query process on SDatabaseOdometer: %s", qPrintable(model.lastError().text()));

//        return t_hash;
//    }

    return t_hash;
}

QVector<QHash<QString, QString> >
SDatabaseOdometer::process()
{
    QVector<QHash<QString, QString> > t_vec;

    QSqlQuery query(this->db);
//    query.setForwardOnly(true);
    if (query.exec("SELECT * FROM Process"))
    {
        while (query.next())
        {
            QHash<QString, QString> t_hash;
            t_hash.insert("id", query.value(0).toString());
            t_hash.insert("length", query.value(1).toString());
            t_hash.insert("measured", query.value(2).toString());
            t_hash.insert("date", query.value(3).toString());
            t_hash.insert("time", query.value(4).toString());
            t_hash.insert("sn", query.value(5).toString());
            t_hash.insert("complete", query.value(6).toString());
            t_hash.insert("elapsed", query.value(7).toString());

            t_vec.push_back(t_hash);

//            qDebug() << QString("ID %1; Order %2 m; Measured %3 m; Date  %4 & Time %5; SN %6; Complete %7; Elapsed %8;")
//                        .arg(query.value(0).toString())
//                        .arg(query.value(1).toString())
//                        .arg(query.value(2).toString())
//                        .arg(query.value(3).toString())
//                        .arg(query.value(4).toString())
//                        .arg(query.value(5).toString())
//                        .arg(query.value(6).toString())
//                        .arg(query.value(7).toString());
        }

    }

//    QSqlQueryModel model;
//    model.setQuery(query);
//    if (model.lastError().isValid())
//    {
//        qFatal("Cannot set query process on SDatabaseOdometer: %s", qPrintable(model.lastError().text()));

//        return t_vec;
//    }

    return t_vec;
}

bool
SDatabaseOdometer::statistics(const double measured,
                             const qint64 elapsed,
                             const uint counter)
{
    QSqlQuery query(this->db);

    query.prepare("UPDATE Statistics SET length = length + :measured, counter = counter + :counter, time = time + :elapsed WHERE id = :id");
    query.bindValue(":measured", measured);
    query.bindValue(":counter", counter);
    query.bindValue(":elapsed", elapsed);
    query.bindValue(":id", 0);

    if (query.exec())
    {
        return true;
    }
    else
    {
         qDebug() << "SDatabaseOdometer saveToAbolutLength() error: " << query.lastError();
    }

    return false;
}

QHash<QString, QString>
SDatabaseOdometer::statistics()
{
    QHash<QString, QString> t_hash;

    QSqlQuery query(this->db);

    query.prepare("SELECT * FROM Statistics");

    if (query.exec())
    {
        if (query.next())
        {
            t_hash.insert("id", query.value(0).toString());
            t_hash.insert("length", query.value(1).toString());
            t_hash.insert("counter", query.value(2).toString());
            t_hash.insert("time", query.value(3).toString());

            emit this->signalStatistics(t_hash);
        }
    }
    else
    {
        qDebug() << "SDatabaseOdometer getTotalOrders() error: " << query.lastError();
    }

    return t_hash;
}

bool
SDatabaseOdometer::deleteMeasurement(const int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Process WHERE id = :id");
    query.bindValue(":id", id);

    if (!query.exec())
    {
        qFatal("SDatabaseOdometer DELETE query deleteMeasurement failed: %s", qPrintable(query.lastError().text()));
    }

//    QSqlQueryModel model;
//    model.setQuery(query);
//    if (model.lastError().isValid())
//    {
//        qFatal("Cannot set query deleteMeasurement on SDatabaseOdometer: %s", qPrintable(model.lastError().text()));

//        return false;
//    }

    return true;
}

bool SDatabaseOdometer::deleteAllMeasurement()
{
    QSqlQuery query;

    query.prepare("DELETE FROM Process");

    // Delete database
    if(!query.exec())
    {
         qDebug() << "SDatabaseOdometer deleteAllMeasurement() Process error: " << query.lastError();

         return false;
    }

    // Re-init id incremental
    this->setAutoIncrement(this->getID());

    // Re-init total meter
//    query.prepare("UPDATE Statistics SET length = :measured,  counter = :counter, time = :elapsed WHERE id = :id");
//    query.bindValue(":measured", 0.0);
//    query.bindValue(":counter", 0);
//    query.bindValue(":elapsed", 0);
//    query.bindValue(":id", 0);

    if(!query.exec())
    {
         qDebug() << "SDatabaseOdometer deleteAllMeasurement() Statistics error: " << query.lastError();
    }
    else
    {
        return true;
    }

    return false;
}

double SDatabaseOdometer::getLength(const int id)
{
    QSqlQuery query(this->db);

    query.prepare("SELECT measured FROM Process WHERE id = :id");
    query.bindValue(":id", id);

    if(query.exec())
    {
        if (query.next())
        {
            return query.value(0).toDouble();
        }
    }
    else
    {
        qDebug() << "SDatabaseOdometer getLength() error: " << query.lastError();
    }

    return -1.0;
}

bool
SDatabaseOdometer::removeTotal(const double measured,
                       const qint64 elapsed)
{
    QSqlQuery query(this->db);

    query.prepare("UPDATE Statistics SET length = length - :measured, counter = counter - :counter, time = time - :elapsed WHERE id = :id");
    query.bindValue(":measured", measured);
    query.bindValue(":counter", -1);
    query.bindValue(":elapsed", elapsed);
    query.bindValue(":id", 0);

    if(query.exec())
    {
        return true;
    }
    else
    {
         qDebug() << "SDatabaseOdometer removeTotal() error: " << query.lastError();
    }

    return false;
}

int
SDatabaseOdometer::getSize()
{
    QSqlQuery query(this->db);

    query.prepare("SELECT COUNT(*) FROM Process");

    if (query.exec())
    {
        if (query.next())
        {
            return query.value(0).toInt();
        }
    }
    else
    {
        qDebug() << "SDatabaseOdometer getSize() error: " << query.lastError();
    }

    return -1;
}

int SDatabaseOdometer::getNextID()
{
    QSqlQuery query(this->db);

    query.prepare("SELECT SEQ FROM SQLITE_SEQUENCE WHERE NAME = 'Process'");

    int id = -1;

    if (query.exec())
    {
         if (query.next())
         {
             id = query.value(0).toInt() + 1;
         }
    }
    else
    {
        qDebug() << "SDatabaseOdometer getNextID() error: " << query.lastError();
    }

    return id;
}

bool
SDatabaseOdometer::setAutoIncrement(const int value)
{
    QSqlQuery query(this->db);

    query.prepare("UPDATE SQLITE_SEQUENCE SET SEQ = :value WHERE NAME = 'Process'");
    query.bindValue(":value", value);

    if (!query.exec())
    {
        qDebug() << "SDatabaseOdometer setAutoIncrement() error: " << query.lastError();

        return false;
    }

    return true;
}

int
SDatabaseOdometer::getID()
{
    int mac = 0;

    foreach (QNetworkInterface interface, QNetworkInterface::allInterfaces())
    {
        if (interface.hardwareAddress().size() == 17)
        {
            mac = interface.hardwareAddress().section(':', 3, 5).remove(':').toInt(new bool, 16);
            if (mac)
            {
                break;
            }
        }
    }

    return mac;
}

int
SDatabaseOdometer::getID(const int index)
{
    QString text;

    foreach (QNetworkInterface interface, QNetworkInterface::allInterfaces())
    {
        text += interface.hardwareAddress() + "|";
    }

    return text.split('|').at(index).section(':', 3, 5).remove(':').toInt(new bool, 16);
}

QString
SDatabaseOdometer::getSN()
{
    QString text = "";

    foreach (QNetworkInterface networkInterface, QNetworkInterface::allInterfaces())
    {
        if (networkInterface.hardwareAddress().size() == 17)
        {
            uint64_t mac = networkInterface.hardwareAddress().remove(":").toULongLong(new bool, 16);
            if (mac)
            {
                text = networkInterface.hardwareAddress().remove(":");
                break;
            }
        }
    }

    return text;
}

void
SDatabaseOdometer::slotStream(const int quantity)
{
    this->stream(quantity);
}

void
SDatabaseOdometer::slotId(const int id)
{
    emit this->signalId(this->process(id));
}

void
SDatabaseOdometer::slotStatistics()
{
    this->statistics();
}

int
SDatabaseOdometer::quantity() const
{
    return this->m_quantity;
}

void SDatabaseOdometer::stream(const int quantity)
{
    this->m_quantity = quantity;

    /* Activate the thread function run() */
    if (!this->isRunning())
    {
        this->proceed();
    }
    else if (this->isPause())
    {
        this->resume();
    }
}


void SDatabaseOdometer::run()
{
    forever
    {
        this->asserts();
        this->app();
    }
}

void SDatabaseOdometer::app()
{
    QSqlQuery query(this->db);
    if (query.exec("SELECT * FROM Process"))
    {
        int t_count = 0;
        while (query.next())
        {
            QHash<QString, QString> t_hash;
            t_hash.insert("id", query.value(0).toString());
            t_hash.insert("length", query.value(1).toString());
            t_hash.insert("measured", query.value(2).toString());
            t_hash.insert("date", query.value(3).toString());
            t_hash.insert("time", query.value(4).toString());
            t_hash.insert("sn", query.value(5).toString());
            t_hash.insert("complete", query.value(6).toString());
            t_hash.insert("elapsed", query.value(7).toString());

            emit this->signalStream(t_hash);
            msleep(100);

            if ((this->m_quantity <= ++t_count) && (this->m_quantity != 0))
            {
                t_count = 0;
                this->pause();
            }
        }
    }
    this->pause();

//    QSqlQueryModel model;
//    model.setQuery(query);
//    if (model.lastError().isValid())
//    {
//        emit this->signalError();
//        qFatal("Cannot set query app() on SDatabaseOdometer: %s", qPrintable(model.lastError().text()));
//    }
}
