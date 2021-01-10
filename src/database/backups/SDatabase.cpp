#include "SDatabase.h"

#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDir>
#include <QDebug>


SDatabase::SDatabase(const QString &path)
{
    QDir dir(path);

    if (!dir.exists())
    {
        dir.mkpath(path);
    }

    /// DATABASE
    this->db = QSqlDatabase::addDatabase("QSQLITE");
    this->db.setDatabaseName(path + "/database.db");

    if (this->db.open())
    {
        /// QUERY
        QSqlQuery query(this->db);

        /// Customer
        if(!query.exec("CREATE TABLE IF NOT EXISTS Customer (id INTEGER PRIMARY KEY AUTOINCREMENT, ordering double, measured double, date TEXT)"))
        {
             qDebug() << "SDatabase create Customer error: " << query.lastError();
        }

        /// Odometer
        if(!query.exec("CREATE TABLE IF NOT EXISTS Odometer (id INTEGER PRIMARY KEY, meter double)"))
        {
            qDebug() << "SDatabase create Odometer error: " << query.lastError();
        }

        /// Initialize Odometer
        if (query.exec("SELECT COUNT(*) FROM Odometer"))
        {
            if (query.next())
            {
                if (!query.value(0).toInt())
                {
                    if(!query.exec("INSERT INTO Odometer (id, meter) VALUES (0, 0.0)"))
                    {
                        qDebug() << "SDatabase create Odometer insert error: " << query.lastError();
                    }
                }
            }
        }
    }
    else
    {
        qDebug() << "Error: connection with database fail";
    }
}

SDatabase::~SDatabase()
{
    this->db.close();
    if (!this->db.isOpen())
    {
        this->db.removeDatabase(this->db.connectionName());
    }
}

bool SDatabase::saveMeasurement(const double &ordering, const double &measured, const QString &date)
{
    QSqlQuery query(this->db);

    query.prepare("INSERT INTO Customer (id, ordering, measured, date) VALUES (:id, :ordering, :measured, :date)");
    query.bindValue(":ordering", ordering);
    query.bindValue(":measured", measured);
    query.bindValue(":date", date);

    if (query.exec())
    {
        return true;
    }
    else
    {
         qDebug() << "SDatabase INSERT measurement error: " << query.lastError();
    }

    return false;
}

QString SDatabase::getMeasurement(const int &id)
{
    QSqlQuery query(this->db);

    //query.prepare("SELECT Customer.id, Customer.ordering, Customer.measured, Customer.date FROM Customer WHERE id = :id");
    query.prepare("SELECT id, ordering, measured, date FROM Customer WHERE id = :id");
    query.bindValue(":id", id);

    if(!query.exec())
    {
         qDebug() << "SDatabase SELECT measurement error: " << query.lastError();
    }
    else
    {
        if (query.next())
        {
            QSqlRecord rec = query.record();
            int cols = rec.count();

            QString temp;

            for (int i = 0; i < cols; ++i)
            {
                temp += query.value(i).toString() + ((i < cols - 1) ? "\t" : "");
            }

            return temp;
        }
    }

    return "";
}

void SDatabase::getAllMeasurement()
{
    QSqlQuery query("SELECT * FROM Customer");

    if(!query.exec())
    {
         qDebug() << "SDatabase getAllMeasurement() error: " << query.lastError();
    }
    else
    {
        while (query.next())
        {
            qDebug() << QString("ID %1; Order %2 m; Measured %3 m; Date & Time %4").arg(query.value(0).toString()).arg(query.value(1).toString()).arg(query.value(2).toString()).arg(query.value(3).toString());
        }
    }
}

bool SDatabase::deleteMeasurement(const int &id)
{
    QSqlQuery query;

    this->deleteFromAbsolutLength(this->getLength(id));

    query.prepare("DELETE FROM Customer WHERE id = (:id)");
    query.bindValue(":id", id);

    if(!query.exec())
    {
         qDebug() << "SDatabase deleteMeasurement() error: " << query.lastError();
    }
    else
    {
        return true;
    }

    return false;
}

bool SDatabase::deleteAllMeasurement()
{
    QSqlQuery query;

    /// DELETE ALL
    if(!query.exec("DELETE FROM Customer"))
    {
         qDebug() << "SDatabase deleteAllMeasurement() Customer error: " << query.lastError();

         return false;
    }

    this->initAutoIncrement();

    /// REINIT ABSOLUT LENGTH
    query.prepare("UPDATE Odometer SET meter = :measured WHERE id = :id");
    query.bindValue(":measured", 0.0);
    query.bindValue(":id", 0);

    if(!query.exec())
    {
         qDebug() << "SDatabase deleteAllMeasurement() Odometer error: " << query.lastError();
    }
    else
    {
        return true;
    }

    return false;
}

int SDatabase::getCount()
{
    QSqlQuery query(this->db);

    query.prepare("SELECT COUNT(*) FROM Customer");

    if (!query.exec())
    {
         qDebug() << "SDatabase getCount() error: " << query.lastError();
    }
    else
    {
        if (query.next())
        {
            return query.value(0).toInt();
        }
    }

    return -1;
}

double SDatabase::getLength(const int &id)
{
    QSqlQuery query(this->db);

    query.prepare("SELECT measured FROM Customer WHERE id = :id");
    query.bindValue(":id", id);

    if(!query.exec())
    {
         qDebug() << "SDatabase getLength() error: " << query.lastError();
    }
    else
    {
        if (query.next())
        {
            return query.value(0).toDouble();
        }
    }

    return -1.0;
}


bool SDatabase::saveToAbolutLength(const double &measured)
{
    QSqlQuery query(this->db);

    query.prepare("UPDATE Odometer SET meter = meter + :measured WHERE id = :id");
    query.bindValue(":measured", measured);
    query.bindValue(":id", 0);

    if(query.exec())
    {
        return true;
    }
    else
    {
         qDebug() << "SDatabase saveToAbolutLength() error: " << query.lastError();
    }

    return false;
}

bool SDatabase::deleteFromAbsolutLength(const double &measured)
{
    QSqlQuery query(this->db);

    query.prepare("UPDATE Odometer SET meter = meter - :measured WHERE id = :id");
    query.bindValue(":measured", measured);
    query.bindValue(":id", 0);

    if(query.exec())
    {
        return true;
    }
    else
    {
         qDebug() << "SDatabase deleteFromAbsolutLength() error: " << query.lastError();
    }

    return false;
}

double SDatabase::getAbsolutLength()
{
    QSqlQuery query(this->db);

    query.prepare("SELECT meter FROM Odometer WHERE id = 0");

    if(!query.exec())
    {
         qDebug() << "SDatabase getAbsolutLength() error: " << query.lastError();
    }
    else
    {
        if (query.next())
        {
            return query.value(0).toDouble();
        }
    }

    return -1.0;
}

int SDatabase::getNextID()
{
    QSqlQuery query(this->db);

    query.prepare("SELECT SEQ FROM SQLITE_SEQUENCE WHERE NAME = 'Customer'");

    int id = -1;

    if (query.exec())
    {
         if (query.next())
         {
             id = query.value(0).toInt();

             if (id < 0)
             {
                 this->initAutoIncrement();
                 this->getNextID();
             }

             return id;
         }
    }
    else
    {
        qDebug() << "SDatabase getNextID() error: " << query.lastError();
    }

    return id;
}

bool SDatabase::initAutoIncrement()
{
    QSqlQuery query(this->db);

    if(!query.exec("UPDATE SQLITE_SEQUENCE SET SEQ = 0 WHERE NAME = 'Customer'"))
    {
        qDebug() << "SDatabase initAutoIncrement() error: " << query.lastError();

        return false;
    }

    return true;
}
