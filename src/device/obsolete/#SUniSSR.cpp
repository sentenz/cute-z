#include "SUniSSR.h"

#include <QFile>
#include <QDebug>


SUniSSR::SUniSSR(const QString &dev, const QString txt) : device(dev), text(txt)
{
    file = new QFile(this->path + "/" + this->device + "/" + this->text);

    //this->reset();
}

SUniSSR::~SUniSSR()
{
    //this->reset();

    if (file != nullptr)
        delete file;
}

bool SUniSSR::latch(const SSR x)
{
    /// READ
    if (!file->open(QIODevice::ReadWrite))
    {
        return false;
    }

    /// RELAY
    char data[1];
    file->read(data, sizeof data);

    uint8_t ssr = *data;

    // DEBUG
    qDebug() << "LATCH" << QString::number(ssr, 2) << *data;

    if ((ssr & (1 << (uint8_t)x)))
    {
        ssr &= ~(1 << (uint8_t)x);

        *data = ssr;

        // DEBUG
        qDebug() << "LATCH" << *data << (char)ssr;

        /// WRITE
        file->seek(0);
        file->resize(0);
        file->write(data, sizeof data);
    }

    file->flush();
    file->close();

    return true;
}

bool SUniSSR::unlatch(const SSR x)
{
    /// READ
    if (!file->open(QIODevice::ReadWrite))
    {
        return false;
    }

    /// RELAY
    char data[1];
    file->read(data, sizeof data);

    uint8_t ssr = *data;

    // DEBUG
    qDebug() << "UNLATCH" << QString::number(ssr, 2) << *data;

    if (!(ssr & (1 << (uint8_t)x)))
    {
        ssr |= 1 << (uint8_t)x;

        *data = ssr;

        // DEBUG
        qDebug() << "UNLATCH" << *data << (char)ssr;

        /// WRITE
        file->seek(0);
        file->resize(0);
        file->write(data, sizeof data);
    }

    file->flush();
    file->close();

    return true;
}

bool SUniSSR::isLatched(const SSR x)
{
    /// READ
    if (!file->open(QIODevice::ReadOnly))
    {
        return false;
    }

    /// RELAY
    char data[1];
    file->read(data, sizeof data);

    uint8_t ssr = *data;

    if ((ssr >> (uint8_t)x) & 1U)
    {
        return true;
    }

    return false;
}

bool SUniSSR::reset()
{
    /// READ
    if (!file->open(QIODevice::WriteOnly))
    {
        return false;
    }

    char data[1];
    *data = 255;

    /// WRITE
    file->seek(0);
    file->resize(0);
    file->write(data, sizeof data);
    file->flush();
    file->close();

    return true;
}

void SUniSSR::setPath(const QString path)
{
    this->path = path;
}

void SUniSSR::setDevice(const QString device)
{
    this->device = device;
}

void SUniSSR::setFile(const QString text)
{
    this->text = text;
}
