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
    {
        delete settings;
        settings = nullptr;
    }
    if (butterworth != nullptr)
    {
        delete butterworth;
        butterworth = nullptr;
    }
    if (hilbert != nullptr)
    {
        delete hilbert;
        hilbert = nullptr;
    }
    #ifdef S_UNUSED
    if (magnet != nullptr)
    {
        delete magnet;
        magnet = nullptr;
    }
    #endif   
}

void SOdometer::setupWidget()
{
    /// WATCHER
    fileSystemWatcher = new QFileSystemWatcher(this);
    fileSystemWatcher->addPath(::GlobalSettingDir + ::GlobalSettingConfig);

    /// SENSOR
    #ifdef S_UNUSED
    magnet = new VertX13;
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
    return true;
}

double SOdometer::getRawValue()
{
    #ifdef S_UNUSED
    return this->magnet->read();
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
    #ifdef S_DEBUG_T
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

        #ifdef S_DEBUG_T
        clock_gettime(CLOCK_MONOTONIC, &finish);
        qDebug() << "Filt" << dataFilt.back() <<  "Elapsed" << (finish.tv_nsec - start.tv_nsec); //  / 1.e6
        #endif

        return true;
    }

    return false;
}

bool SOdometer::getPulseValue(double &pulse)
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
    /*
    this->settings = new QSettings(::GlobalSettingDir + ::GlobalSettingSettings, QSettings::IniFormat);

    if (!QStringList(this->settings->allKeys().filter("custom/system/odometer", Qt::CaseInsensitive)).isEmpty())
    {
        this->settings->beginGroup("custom/system/odometer");
    }
    else if (!QStringList(this->settings->allKeys().filter("default/system/odometer", Qt::CaseInsensitive)).isEmpty())
    {
        this->settings->beginGroup("default/system/odometer");
    }

    /// resolution
    this->resolution = this->settings->value("resolution",  QString::number(50.0, 'f', 2)).toDouble();
    /// diameter
    this->diameter = this->settings->value("diameter",  QString::number(0.10, 'f', 4)).toDouble();
    /// threshold
    this->threshold = this->settings->value("threshold",  0.0).toDouble();
    /// samplerate
    this->samplerate = this->settings->value("samplerate",  1000).toDouble();
    if (this->samplerate == 300)
    {
        #ifdef S_UNUSED
        //magnet->setDataRate(LIS_DataRate::Hz_300);
        #endif
    }
    else if (this->samplerate == 560)
    {
        #ifdef S_UNUSED
        //magnet->setDataRate(LIS_DataRate::Hz_560);
        #endif
    }
    else if (this->samplerate == 1000)
    {
        #ifdef S_UNUSED
        //magnet->setDataRate(LIS_DataRate::Hz_1000);
        #endif
    }
    /// filter order
    this->filterOrder = this->settings->value("filterOrder",  5).toInt();
    this->butterworth->setOrder(this->filterOrder);
    if (!this->data.empty() && (this->data.size() > this->butterworth->getOrder()))
    {
        this->data.erase(this->data.begin(), this->data.begin() + this->butterworth->getOrder());
    }
    /// filter coefficient fc
    this->filterCutFreqC = this->settings->value("filterCutFreqC",  QString::number(0.5, 'f', 5)).toDouble();
    this->butterworth->setCutFreqC(this->filterCutFreqC);
    /// filter coefficient f1
    this->filterCutFreq1 = this->settings->value("filterCutFreq1",  QString::number(0.5, 'f', 5)).toDouble();
    this->butterworth->setCutFreq1(this->filterCutFreq1);
    /// filter coefficient f2
    this->filterCutFreq2 = this->settings->value("filterCutFreq2",  QString::number(0.5, 'f', 5)).toDouble();
    this->butterworth->setCutFreq2(this->filterCutFreq2);
    /// filter function
    this->filterType = this->settings->value("filterType", "pass").toString();
    this->butterworth->setType(filterType.toStdString());
    /// procedure
    this->procedure = this->settings->value("procedure", "pulse").toString();

    this->settings->sync();
    this->settings->endGroup();

    if (this->settings != nullptr)
    {
        delete this->settings;
        this->settings = nullptr;
    }
    */
}

bool SOdometer::readFile()
{
    /*
    QFile file(::GlobalSettingDir + ::GlobalSettingEWave);

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
    */

    return true;
}

bool SOdometer::writeFile()
{
    /*
    QFile file(::GlobalSettingDir + ::GlobalSettingEWave);

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
    */

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
            touchDialogAccept->setAcceptText(tr("Okay"));
            touchDialogAccept->setDescriptionText(tr("Odometer intialization.\n\nKeep caution throughout the process!"));
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

#ifdef S_LOGGER
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
