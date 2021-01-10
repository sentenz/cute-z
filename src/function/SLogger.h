#ifndef SLOGGER_H
#define SLOGGER_H

#include <QFile>
#include <QTextStream>

class QString;


class SLogger
{
public:
    SLogger(const QString &filename = "");
    ~SLogger();
    const SLogger& operator=(const SLogger&) = delete;

    void start();
    void close();
    void set(const double &value);
    void setFilename(const QString &filename);

private:
    void check();

    QString filename = "";
    QFile file;
    QTextStream stream;
};

#endif /// SLOGGER_H
