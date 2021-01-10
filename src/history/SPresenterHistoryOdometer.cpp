#include "SPresenterHistoryOdometer.h"
#include "SModelHistoryOdometer.h"
#include "SViewHistoryOdometer.h"
#include "../util/dialog/STextDialog.h"

#include <QString>
#include <QHash>


SPresenterHistoryOdometer::SPresenterHistoryOdometer(QWidget * parent) :
    SBasePresenter(parent)
{
    this->setupWidget();
    this->setConnect();
}

SPresenterHistoryOdometer::SPresenterHistoryOdometer(const QDialog * options,
                                                     QWidget * parent) :
    SBasePresenter(parent)
{
    this->setupWidget();
    this->setConnect();
    this->setConnect(options);
}

SPresenterHistoryOdometer::SPresenterHistoryOdometer(const QObject * view,
                                                     const QObject * model,
                                                     QWidget * parent) :
    SBasePresenter(parent)
{
    this->setupWidget();
    this->setConnect();
    this->setConnect(view, model);
}

SPresenterHistoryOdometer::~SPresenterHistoryOdometer()
{
    if (this->modelHistoryOdometer != nullptr)
    {
        delete this->modelHistoryOdometer;
        this->modelHistoryOdometer = nullptr;
    }
    if (this->viewHistoryOdometer != nullptr)
    {
        delete this->viewHistoryOdometer;
        this->viewHistoryOdometer = nullptr;
    }
}

void
SPresenterHistoryOdometer::setupWidget()
{
    /* Model */
    this->modelHistoryOdometer = new SModelHistoryOdometer(this);

    /* View */
    this->viewHistoryOdometer = new SViewHistoryOdometer(this);
    this->viewHistoryOdometer->title(tr("Odometer history"));
    this->viewHistoryOdometer->closeable(true);
}

void
SPresenterHistoryOdometer::setConnect()
{
    QObject::connect(this->viewHistoryOdometer, SIGNAL(signalStream(const int)), this->modelHistoryOdometer, SIGNAL(signalStream(const int)));
    QObject::connect(this->modelHistoryOdometer, SIGNAL(signalStream(QHash<QString, QString>)), this->viewHistoryOdometer, SLOT(slotStream(QHash<QString, QString>)));
    QObject::connect(this->viewHistoryOdometer, SIGNAL(signalStatistics()), this->modelHistoryOdometer, SIGNAL(signalStatistics()));
    QObject::connect(this->modelHistoryOdometer, SIGNAL(signalStatistics(QHash<QString, QString>)), this->viewHistoryOdometer, SLOT(slotStatistics(QHash<QString, QString>)));
}

void
SPresenterHistoryOdometer::setConnect(const QDialog * options)
{
    QObject::connect(this->viewHistoryOdometer, &SViewHistoryOdometer::signalOption, options, &QDialog::show);
    QObject::connect(options, SIGNAL(signalId(const int)), this->modelHistoryOdometer, SIGNAL(signalId(const int)));
//    QObject::connect(this->modelHistoryOdometer, SIGNAL(signalId(QHash<QString,QString>)), [this](QHash<QString, QString> hash) {
//        STextDialog dialog(this);
//        dialog.setTitle(tr("Database"));
//        dialog.setAcceptButton(tr("Retry"));
//        dialog.setDescription(hash.value("info").isEmpty() ? tr("ID dosn't exist!") : hash.value("info"));
//        dialog.exec();
//        if (dialog.isAccepted())
//        {
////            this->modelHistoryOdometer->signalDeleteId(hash.value("id").toInt());
//        }
//    });
 }

void
SPresenterHistoryOdometer::setConnect(const QObject * view,
                                      const QObject * model)
{
//    QObject::connect(view, SIGNAL(signalStream(const int)), model, SIGNAL(signalStream(const int)));
//    QObject::connect(model, SIGNAL(signalStream(QHash<QString, QString>)), view, SLOT(slotStream(QHash<QString, QString>)));
}

void
SPresenterHistoryOdometer::create()
{
    this->viewHistoryOdometer->exec();
}
