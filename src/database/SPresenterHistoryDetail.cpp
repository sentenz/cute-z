#include "SPresenterHistoryDetail.h"
#include "SModelHistoryDetail.h"
#include "SViewHistoryDetail.h"

#include <QString>
#include <QHash>


SPresenterHistoryDetail::SPresenterHistoryDetail(QWidget * parent) :
    SBasePresenter(parent)
{
    this->setupWidget();
    this->setConnect();
}

SPresenterHistoryDetail::SPresenterHistoryDetail(const QObject * view,
                                                 const QObject * model,
                                                 QWidget * parent) :
    SBasePresenter(parent)
{
    this->setupWidget();
    this->setConnect(view, model);
}

SPresenterHistoryDetail::~SPresenterHistoryDetail()
{
    if (this->modelHistoryDetail != nullptr)
    {
        delete this->modelHistoryDetail;
        this->modelHistoryDetail = nullptr;
    }
    if (this->viewHistoryDetail != nullptr)
    {
        delete this->viewHistoryDetail;
        this->viewHistoryDetail = nullptr;
    }
}

void
SPresenterHistoryDetail::setupWidget()
{
    /* Model */
    this->modelHistoryDetail = new SModelHistoryDetail(this);

    /* View */
    this->viewHistoryDetail = new SViewHistoryDetail(this);
    this->viewHistoryDetail->title(tr("Odometer history"));
    this->viewHistoryDetail->closeable(true);
}

void
SPresenterHistoryDetail::setConnect()
{
    QObject::connect(this->viewHistoryDetail, SIGNAL(signalStream(const int)), this->modelHistoryDetail, SIGNAL(signalStream(const int)));
    QObject::connect(this->modelHistoryDetail, SIGNAL(signalStream(QHash<QString, QString>)), this->viewHistoryDetail, SLOT(slotStream(QHash<QString, QString>)));
    QObject::connect(this->viewHistoryDetail, SIGNAL(signalStatistics()), this->modelHistoryDetail, SIGNAL(signalStatistics()));
    QObject::connect(this->modelHistoryDetail, SIGNAL(signalStatistics(QHash<QString, QString>)), this->viewHistoryDetail, SLOT(slotStatistics(QHash<QString, QString>)));
}

void
SPresenterHistoryDetail::setConnect(const QObject * view,
                                    const QObject * model)
{
//    QObject::connect(view, SIGNAL(signalStream(const int)), model, SIGNAL(signalStream(const int)));
//    QObject::connect(model, SIGNAL(signalStream(QHash<QString, QString>)), view, SLOT(slotStream(QHash<QString, QString>)));
}

void
SPresenterHistoryDetail::create()
{
    this->viewHistoryDetail->exec();
}
