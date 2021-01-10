#include "SMAC.h"

#include <QNetworkInterface>


QStringList mac()
{
    return network();
}

QString mac(const int &index)
{
    QStringList list = network();

    if (list.size() > index)
    {
        return list.at(index);
    }

    return "";
}

QStringList network()
{
    QStringList list;

    foreach (QNetworkInterface interface, QNetworkInterface::allInterfaces())
    {
        if (interface.hardwareAddress().size() == 17)
        {
            list.push_back(interface.hardwareAddress());
        }
    }

    return list;
}

/*
SMAC::SMAC()
{
    this->network();
}

QStringList SMAC::getMAC()
{
    return hardwareAddress;
}

QString SMAC::getMAC(const int &index)
{
    if (hardwareAddress.size() > index)
    {
        return hardwareAddress.at(index);
    }

    return "";
}

QString SMAC::getMAC(const QString mode)
{
    foreach (QString text, hardwareAddress)
    {
        if (text.split(':').size())
        {
            return text;
        }
    }

    return "";
}

void SMAC::network()
{
    foreach (QNetworkInterface interface, QNetworkInterface::allInterfaces())
    {
        if (interface.hardwareAddress().size() == 17)
        {
            hardwareAddress.push_back(interface.hardwareAddress());
        }
    }
}
*/
