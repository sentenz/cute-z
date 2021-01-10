#include "SMain.h"
#include "SGlobal.h"
#include "SCentral.h"
#include "../util/splashscreen/SSplashScreen.h"

#include <iostream>
#include <QApplication>
#include <QProcess>
#include <QTimer>
#include <QDebug>

SMain::SMain(QWidget *parent)
    : QWidget(parent)
{
    this->setGlobalVariables();
    this->setupWidget();
    this->setConnect();
    this->setProcess();
}

SMain::~SMain()
{
    if (this->central != nullptr)
    {
        delete this->central;
        this->central = nullptr;
    }
}

void SMain::setGlobalVariables()
{
    #ifndef __linux__
    ::GlobalAppPath = qApp->applicationDirPath();
    ::GlobalBus1Wire = qApp->applicationDirPath() + "/devices";
    #endif
}

void
SMain::setupWidget()
{
    /* Splash */
    this->splash = new SSplashScreen(this);
    this->splash->setAttribute(Qt::WA_DeleteOnClose);
    this->splash->show();

    qApp->processEvents();

    /* Central */
    this->central = new SCentral;

    /* Delay splash for a while */
    QTimer::singleShot(3000, [this] () {
        this->central->show();
        this->splash->finish(this->central);
    });
}

void
SMain::setConnect()
{
}

void
SMain::setProcess()
{
}
