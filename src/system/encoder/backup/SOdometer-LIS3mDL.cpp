#include "SOdometer.h"
#include "../dialog/STouchDialogAccept.h"

#include <QApplication>
#include <QFileSystemWatcher>
#include <QFile>
#include <QTextStream>
#include <QSettings>
#include <algorithm>
#include <cmath>

#include <QDebug>
#include <ctime>

SOdometer::SOdometer(QWidget *parent) : QDialog(parent)
{
    this->setObjectName("SOdometer");

    this->setupWidget();
    this->setConnect();
    this->readFile();
    this->slotReadSettings();
}

SOdometer::~SOdometer()
{
    if (settings != nullptr)
        delete settings;
    if (butterworth != nullptr)
        delete butterworth;
    if (hilbert != nullptr)
        delete hilbert;
    #ifdef QT_SENTENZ
    if (magnet != nullptr)
        delete magnet;
    #endif
}

void SOdometer::setupWidget()
{
    /// WATCHER
    fileSystemWatcher = new QFileSystemWatcher(this);
    #ifdef __linux__
    fileSystemWatcher->addPath(QString("/home/pi/.config/sentenz").append("/.config/settings.ini"));
    #else
    fileSystemWatcher->addPath(qApp->applicationDirPath().append("/config/settings.ini"));
    #endif

    /// SENSOR
    #ifdef QT_SENTENZ
    magnet = new LIS3MDL;
    magnet->setFullScale(LIS_FullScale::G16);
    magnet->setDataRate(LIS_DataRate::Hz_1000);
    magnet->setTempSensor(true);
    magnet->setFastRead(false);
    magnet->setBlockDataUpdate(false);
    #endif

    #ifdef S_DEBUG
    magnet->getRegConfig();
    #endif

    /// FILTER
    butterworth = new Butterworth;

    /// HILBERT
    hilbert = new Hilbert;
}

void SOdometer::setConnect()
{
    /// WATCHER
    connect(fileSystemWatcher, &QFileSystemWatcher::fileChanged, this, &SOdometer::slotReadSettings);
}

bool SOdometer::isStatus()
{
    #ifdef QT_SENTENZ
    return this->magnet->getStatus(LIS_Status::ZDA);
    #else
    return true;
    #endif
}

double SOdometer::getRawValue()
{
    #ifdef QT_SENTENZ
    return this->magnet->getAxe(LIS_Axes::Z);
    #else
    static int count = 0;
    return .5 + .05 * sin(2*M_PI*500*count++/10000) + .05 * (double)qrand()/RAND_MAX;
    #endif
}

double SOdometer::getFilterValue()
{
    this->data.push_back(this->getRawValue());

    if (this->data.size() > this->butterworth->getOrder())
    {
        this->butterworth->filter(this->data, this->dataFilt);

        this->data.erase(this->data.begin());

        return this->dataFilt.back();
    }

    return 0.0;
}

bool SOdometer::getHilbertValue(double &dist)
{
    if (this->isStatus())
    {
        #ifdef S_DEBUG_02
        struct timespec start, finish;
        clock_gettime(CLOCK_MONOTONIC, &start);
        #endif

        /// FILTER
        this->value = this->getFilterValue();

        if (fabs(this->value) > threshold)
        {
            this->dataHilb.erase(this->dataHilb.begin());
            this->dataHilb.push_back(this->value);

            /// PHASE
            this->vphase = this->hilbert->phase(this->dataHilb);

            if (this->prev)
            {
                this->angle = this->hilbert->angle(this->vphase[this->vphase.size()/2] - this->prev);
                dist = angle * (this->diameter / this->resolution);
            }

            this->prev = this->vphase[this->vphase.size()/2];

            #ifdef S_DEBUG_02
            clock_gettime(CLOCK_MONOTONIC, &finish);
            qDebug() << "Filt" << dataFilt.back() <<  "Elapsed" << (finish.tv_nsec - start.tv_nsec); //  / 1.e6
            #endif

            return true;
        }
    }

    return false;
}

bool SOdometer::getPulseValue(double &pulse)
{
    if (this->isStatus())
    {
        this->value = this->getFilterValue();

        if (fabs(this->value) > threshold)
        {
            if (!std::signbit(this->value) & this->pos)
            {
                if (!(this->pos & this->neg))
                {
                    pulse = (M_PI * this->diameter) / this->resolution;
                }

                this->pos = false;
                this->neg = true;

                return true;
            }
            else if (std::signbit(this->value) & this->neg)
            {
                if (!(this->pos & this->neg))
                {
                    pulse = (M_PI * this->diameter) / this->resolution;
                }

                this->pos = true;
                this->neg = false;

                return true;
            }
        }
    }

    return false;
}

bool SOdometer::getValue(double &value)
{
    if (!this->procedure.compare("pulse"))
    {
        return this->getPulseValue(value);
    }
    else if (!this->procedure.compare("phase"))
    {
        return this->getHilbertValue(value);
    }

    return false;
}

void SOdometer::slotReadSettings()
{
    ///
    /// INIT AREA
    ///
    #ifdef __linux__
    settings = new QSettings(QString("/home/pi/.config/sentenz").append("/.config/settings.ini"), QSettings::IniFormat);
    #else
    settings = new QSettings(qApp->applicationDirPath().append("/config/settings.ini"), QSettings::IniFormat);
    #endif

    if (settings->contains("custom/systems/diameter") || settings->contains("custom/systems/filterOrder") || settings->contains("custom/systems/filterType"))
    {
        settings->beginGroup("custom/systems");
    }
    else if (settings->childGroups().contains("default"))
    {
        settings->beginGroup("default/systems");
    }

    ///
    /// VALUE AREA
    ///

    /// resolution
    this->resolution = settings->value("resolution",  QString::number(50.0, 'f', 2)).toDouble();
    /// diameter
    this->diameter = settings->value("diameter",  QString::number(0.10, 'f', 4)).toDouble();
    /// threshold
    this->threshold  = settings->value("threshold",  0.0).toDouble();
    /// samplerate
    this->samplerate  = settings->value("samplerate",  1000).toDouble();
    if (samplerate == 300)
    {
        #ifdef QT_SENTENZ
        magnet->setDataRate(LIS_DataRate::Hz_300);
        #endif
    }
    else if (samplerate == 560)
    {
        #ifdef QT_SENTENZ
        magnet->setDataRate(LIS_DataRate::Hz_560);
        #endif
    }
    else if (samplerate == 1000)
    {
        #ifdef QT_SENTENZ
        magnet->setDataRate(LIS_DataRate::Hz_1000);
        #endif
    }

    /// filter order
    this->filterOrder = settings->value("filterOrder",  5).toInt();
    this->butterworth->setOrder(this->filterOrder);
    if (!this->data.empty() && (this->data.size() > this->butterworth->getOrder()))
    {
        this->data.erase(this->data.begin(), this->data.begin() + this->butterworth->getOrder());
    }

    /// filter coefficient
    this->filterCutFreqC = settings->value("filterCutFreqC",  QString::number(0.5, 'f', 5)).toDouble();
    this->butterworth->setCutFreqC(this->filterCutFreqC);

    this->filterCutFreq1 = settings->value("filterCutFreq1",  QString::number(0.5, 'f', 5)).toDouble();
    this->butterworth->setCutFreq1(this->filterCutFreq1);

    this->filterCutFreq2 = settings->value("filterCutFreq2",  QString::number(0.5, 'f', 5)).toDouble();
    this->butterworth->setCutFreq2(this->filterCutFreq2);

    /// filter function
    this->filterType = settings->value("filterType", "pass").toString();
    this->butterworth->setType(filterType.toStdString());

    /// procedure
    this->procedure = settings->value("procedure", "pulse").toString();

    ///
    /// CLOSE AREA
    ///
    settings->sync();
    settings->endGroup();

    delete settings;
    settings = nullptr;
}

bool SOdometer::readFile()
{
    #ifdef __linux__
    QFile file(QString("/home/pi/.config/sentenz").append("/.config/ewave"));
    #else
    QFile file(qApp->applicationDirPath().append("/config/ewave"));
    #endif

    if (!file.open(QIODevice::ReadOnly))
    {
        return false;
    }

    QTextStream in(&file);
    while (!in.atEnd())
    {
        this->initParameter(in.readLine().toDouble());
    }

    file.flush();
    file.close();

    return true;
}

bool SOdometer::writeFile()
{
    #ifdef __linux__
    QFile file(QString("/home/pi/.config/sentenz").append("/.config/ewave"));
    #else
    QFile file(qApp->applicationDirPath().append("/config/ewave"));
    #endif

    if (!file.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text))
    {
        return false;
    }

    double tmp = 0.0;
    QTextStream out(&file);

    for (int i = 0; i < 64;)
    {
        if (this->isStatus())
        {
            tmp = this->getFilterValue();

            if (tmp != 0.0)
            {
                out << tmp << "\n";
                this->initParameter(tmp);
                ++i;
            }
        }
    }

    file.flush();
    file.close();

    emit stop();

    return true;
}

bool SOdometer::initOdometer()
{
    bool init = true;

    if (this->dataHilb.empty())
    {
        init = this->readFile();

        if (this->dataHilb.empty())
        {
            touchDialogAccept = new STouchDialogAccept;
            touchDialogAccept->setText(tr("Ok"));
            touchDialogAccept->setDescription(tr("Odometer intialization.\nKeep caution throughout the process!"));
            touchDialogAccept->exec();

            if (touchDialogAccept->isAccepted())
            {
                emit start();

                init = this->writeFile();
            }

            delete touchDialogAccept;
            touchDialogAccept = nullptr;
        }

        return init;
    }

    return init;
}

void SOdometer::initParameter(const double &value)
{
    /// fill data for hilbert transformation
    this->dataHilb.push_back(value);

    /// fill vector for filtering
    if (this->data.size() < this->butterworth->getOrder())
    {
        this->data.push_back(value);
    }

    /// hilbert transformation
    if (this->dataHilb.size() == 64) // && !this->procedure.compare("phase")
    {
        this->vphase = this->hilbert->phase(this->dataHilb);
        this->prev = this->vphase[this->vphase.size()/2];
    }
}

void SOdometer::reset()
{
    this->pos = true;
    this->neg = true;
}

#ifdef QT_LOGGER
double &SOdometer::getWave()
{
    return this->dataHilb[this->dataHilb.size()/2];
}

double &SOdometer::getPhase()
{
    return this->vphase[this->vphase.size()/2];
}

double &SOdometer::getUnwrap()
{
    this->unwrap += this->angle;

    return this->unwrap;
}

void SOdometer::setUnwrap(const double &value)
{
    this->unwrap = value;
}
#endif
