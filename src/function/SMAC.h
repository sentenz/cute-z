#ifndef SMAC_H
#define SMAC_H

#include <QString>
#include <QStringList>


QStringList network();
QStringList mac();
QString mac(const int &index);

/*
class SMAC
{
public:
    SMAC();

    QStringList getMAC();
    QString getMAC(const int &index);
    QString getMAC(const QString mode);

private:
    void network();

    QStringList hardwareAddress;
};
*/
#endif /// SMAC_H
