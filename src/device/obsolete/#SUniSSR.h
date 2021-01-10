#ifndef SUNISSR_H
#define SUNISSR_H

#include <QString>
#include <QApplication>

class QFile;

/// SSR
enum class SSR
{
    R1 = 0,
    R2 = 1,
    R3 = 2,
    R4 = 3,
    R5 = 4,
    R6 = 5,
    R7 = 6,
    R8 = 7
};


class SUniSSR
{
public:
    explicit SUniSSR(const QString &dev, const QString txt);
    ~SUniSSR();

    /// Member functions
    bool latch(const SSR x);
    bool unlatch(const SSR x);
    bool isLatched(const SSR x);
    bool reset();

    void setPath(const QString path);
    void setDevice(const QString device);
    void setFile(const QString text);

private:
    #ifdef QT_SENTENZ
    QString path = "/sys/bus/w1/devices";
    #else
    QString path = qApp->applicationDirPath().append("/devices");
    #endif
    QFile *file = nullptr;
    QString device;
    QString text;
};

#endif /// SUNISSR_H
