#include "SLogger.h"

#include <sys/stat.h>
#include <QDir>


void SLogger::start()
{
    this->check();

    this->file.open(this->filename, std::ios::app);

    if (!this->file.is_open())
    {
        return;
    }
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
    struct stat buffer;

    while (stat(this->filename.c_str(), &buffer) == 0)
    {
        this->filename = "datalogger/" + this->name + std::to_string(++number);
    }
}

void SLogger::set(const double &value)
{
    this->stream << value;
    this->file << this->stream.str() << " ";
}

void SLogger::setFilename(const std::string &filename)
{
    this->filename = "datalogger/" + filename;
    this->name = filename;
}
