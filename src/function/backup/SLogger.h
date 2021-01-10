#ifndef SLOGGER_H
#define SLOGGER_H


#include <fstream>
#include <sstream>
#include <string>

class SLogger
{
public:
    void start();
    void close();
    void set(const double &value);
    void setFilename(const std::string &filename);

private:
    void check();

    std::string name = "";
    std::string filename = "";
    std::stringstream stream;
    std::ofstream file;
};

#endif /// SLOGGER_H
