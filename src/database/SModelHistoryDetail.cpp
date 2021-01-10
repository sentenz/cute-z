#include "SModelHistoryDetail.h"


SModelHistoryDetail::SModelHistoryDetail(QObject * parent) :
    SBaseModel(parent)
{
    this->setupWidget();
    this->setConnect();
}

SModelHistoryDetail::~SModelHistoryDetail()
{
    if (this->database)
    {
        delete this->database;
        this->database = nullptr;
    }
}

void
SModelHistoryDetail::setupWidget()
{
    this->database = new SDatabase(::GlobalConfigPathDatabase, this);
}

void
SModelHistoryDetail::setConnect()
{
    QObject::connect(this, SIGNAL(signalStream(const int)), this->database, SLOT(slotStream(const int)));
    QObject::connect(this->database, SIGNAL(signalStream(QHash<QString, QString>)), this, SIGNAL(signalStream(QHash<QString, QString>)));
    QObject::connect(this, SIGNAL(signalStatistics()), this->database, SLOT(slotStatistics()));
    QObject::connect(this->database, SIGNAL(signalStatistics(QHash<QString, QString>)), this, SIGNAL(signalStatistics(QHash<QString, QString>)));
}
