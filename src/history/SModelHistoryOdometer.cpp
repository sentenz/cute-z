#include "SModelHistoryOdometer.h"
#include <QTime>
//#include <QDate>


SModelHistoryOdometer::SModelHistoryOdometer(QObject * parent) :
    SBaseModel(parent)
{
    this->setupWidget();
    this->setConnect();
}

SModelHistoryOdometer::~SModelHistoryOdometer()
{
    if (this->database)
    {
        delete this->database;
        this->database = nullptr;
    }
}

void
SModelHistoryOdometer::setupWidget()
{
    this->database = new SDatabaseOdometer("database_encoder.db", ::GlobalConfigPathDatabase, this);
}

void
SModelHistoryOdometer::setConnect()
{
    /* Forward to database */
    QObject::connect(this, SIGNAL(signalStream(const int)), this->database, SLOT(slotStream(const int)));
    QObject::connect(this, SIGNAL(signalId(const int)), this->database, SLOT(slotId(const int)));
    QObject::connect(this, SIGNAL(signalStatistics()), this->database, SLOT(slotStatistics()));
    /* From database to internal modification */
    QObject::connect(this->database, SIGNAL(signalStream(QHash<QString, QString>)), this, SLOT(slotStream(QHash<QString, QString>)));
    QObject::connect(this->database, SIGNAL(signalId(QHash<QString, QString>)), this, SLOT(slotId(QHash<QString, QString>)));
    QObject::connect(this->database, SIGNAL(signalStatistics(QHash<QString, QString>)), this, SLOT(slotStatistics(QHash<QString, QString>)));
}

void
SModelHistoryOdometer::slotStream(QHash<QString, QString> hash)
{
    QHash<QString, QString> t_hash;

    t_hash.insert("icon", hash.value("complete").toInt() ? ":/images/ic_check_circle_blue_128dp.svg" : ":/images/ic_warning_red_128dp.svg");
    t_hash.insert("text", tr("%1 %2").arg(hash.value("date")).arg(hash.value("time")));
    t_hash.insert("subtext", tr("<p style=\"font-size: 14pt\">Ordered %1 <sup>%3</sup><br>Measuered %2 <sup>%3</sup></p>").arg(hash.value("length")).arg(hash.value("measured")).arg("m"));
    t_hash.insert("info", tr("<p style=\"font-size: 14pt\">ID %1</p>").arg(hash.value("id")));

    emit this->signalStream(t_hash);
}

void
SModelHistoryOdometer::slotId(QHash<QString, QString> hash)
{
    QHash<QString, QString> t_hash;

    t_hash.insert("icon", hash.value("complete").toInt() ? ":/images/ic_check_circle_blue_128dp.svg" : ":/images/ic_warning_red_128dp.svg");
    t_hash.insert("text", tr("%1 %2").arg(hash.value("date")).arg(hash.value("time")));
    t_hash.insert("subtext", tr("<p style=\"font-size: 14pt\">Ordered %1 <sup>%3</sup><br>Measuered %2 <sup>%3</sup></p>").arg(hash.value("length")).arg(hash.value("measured")).arg("m"));
    t_hash.insert("info", tr("<p style=\"font-size: 14pt\">ID %1</p>").arg(hash.value("id")));

    emit this->signalId(t_hash);
}

void
SModelHistoryOdometer::slotStatistics(QHash<QString, QString> hash)
{
    QHash<QString, QString> t_hash;

    t_hash.insert("time", this->html(QTime::fromMSecsSinceStartOfDay(hash.value("time").toLongLong()).toString("hh:mm"), tr("Total time"), "h"));
    t_hash.insert("length", this->html(QString::number(hash.value("length").toDouble(), 'f', 0), tr("Total length"), "m"));
    t_hash.insert("counter", this->html(hash.value("counter"), tr("Total orders")));


    emit this->signalStatistics(t_hash);
}

QString
SModelHistoryOdometer::html(const QString topText,
                          const QString bottom,
                          const QString unit)
{
    QString text = tr("<p style=\"line-height: 140%\"><span style=\"font-size: 22pt\">%1</span> <sup><span style=\"font-size: 20pt\">%3</span></sup><br><span style=\"font-size: 16pt\">%2</span></p>").arg(topText, bottom, unit);
//    QString text = tr("<p style=\"line-height: 140%; font-size: 20pt\"><font size='+2'>%1</font> <font size='+0'><sup>%3</sup></font><br><font size='-2'>%2</font></p>").arg(topText, bottomText, unit);
    return text;
}
