#include "SLogger.h"

#include <QDir>


SLogger::SLogger(const QString &filename)
{
    this->filename = "datalogger/" + filename;
}

SLogger::~SLogger()
{
}

void SLogger::start()
{
    this->check();

    if (!this->file.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        return;
    }

    this->stream.setDevice(&this->file);
}

void SLogger::close()
{
    this->file.flush();
    this->file.close();
}

void SLogger::check()
{
    if (!QDir("datalogger").exists())
    {
        QDir().mkdir("datalogger");
    }

    int number = 0;

    this->file.setFileName(this->filename);

    while (this->file.exists())
    {
        this->file.setFileName(this->filename + QString::number(++number));
    }
}

void SLogger::set(const double &value)
{
    this->stream << value << " ";
}

void SLogger::setFilename(const QString &filename)
{
    this->filename = "datalogger/" + filename;
}
