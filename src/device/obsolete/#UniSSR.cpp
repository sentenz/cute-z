#include "UniSSR.hpp"

namespace Sentenz
{

UniSSR::UniSSR(const std::string &dev, const std::string txt) : device(dev), text(txt)
{
    infile = new std::fstream;
    this->setFilename();

    this->reset();
}

UniSSR::~UniSSR()
{
    this->reset();

    if (infile != nullptr)
        delete infile;
}

bool UniSSR::latch(const SSR &x)
{
    /// READ
    char data[1];
    this->readByte(data);

    /// RELAY
    uint8_t ssr = *data;

    if (this->setBit(ssr, x))
    {
        /// WRITE
        *data = ssr;

        this->writeByte(data);
    }

    infile->flush();
    infile->close();

    return true;
}

bool UniSSR::latch(const std::vector<SSR> &x)
{
    /// READ
    char data[1];
    this->readByte(data);

    /// RELAY
    uint8_t ssr = *data;
    bool ok = false;

    for (auto it : x)
    {
        if (this->setBit(ssr, it))
        {
            ok = true;
        }
    }

    /// WRITE
    if (ok)
    {
        *data = ssr;

        this->writeByte(data);
    }

    infile->flush();
    infile->close();

    return true;
}

bool UniSSR::unlatch(const SSR &x)
{
    /// READ
    char data[1];
    this->readByte(data);

    /// RELAY
    uint8_t ssr = *data;

    if (this->unsetBit(ssr, x))
    {
        /// WRITE
        *data = ssr;

        this->writeByte(data);
    }

    infile->flush();
    infile->close();

    return true;
}

bool UniSSR::unlatch(const std::vector<SSR> &x)
{
    /// READ
    char data[1];
    this->readByte(data);

    /// RELAY
    uint8_t ssr = *data;
    bool ok = false;

    for (auto it : x)
    {
        if (this->unsetBit(ssr, it))
        {
            ok = true;
        }
    }

    /// WRITE
    if (ok)
    {
        *data = ssr;

        this->writeByte(data);
    }

    infile->flush();
    infile->close();

    return true;
}

bool UniSSR::isLatched(const SSR &x)
{
    /// READ
    char data[1];
    this->readByte(data);

    uint8_t ssr = *data;

    if (this->isBit(ssr, x))
    {
        return true;
    }

    infile->flush();
    infile->close();

    return false;
}

bool UniSSR::reset()
{
    /// READ
    infile->open(filename, std::fstream::out);

    if (!infile->is_open())
    {
        return false;
    }

    char data[1];
    *data = 255;

    /// WRITE
    infile->seekp(0);
    infile->clear();
    infile->write(data, sizeof data);
    infile->flush();
    infile->close();

    return true;
}

void UniSSR::setPath(const std::string &path)
{
    this->path = path;
    this->setFilename();
}

void UniSSR::setDevice(const std::string &device)
{
    this->device = device;
    this->setFilename();
}

void UniSSR::setFile(const std::string &text)
{
    this->text = text;
    this->setFilename();
}

void UniSSR::setFilename()
{
    this->filename = this->path + "/" + this->device + "/" + this->text;
}

bool UniSSR::readByte(char *data)
{
    infile->open(filename, std::fstream::in | std::fstream::out);

    if (!infile->is_open())
    {
        return false;
    }

    infile->read(data, sizeof data);

    return true;
}

void UniSSR::writeByte(char *data)
{
    infile->seekp(0);
    infile->clear();
    infile->write(data, sizeof data);
}

bool UniSSR::setBit(uint8_t &value, const SSR &x)
{
    if ((value & (1 << (uint8_t)x)))
    {
        value &= ~(1 << (uint8_t)x);

        return true;
    }

    return false;
}

bool UniSSR::unsetBit(uint8_t &value, const SSR &x)
{
    if (!(value & (1 << (uint8_t)x)))
    {
        value |= 1 << (uint8_t)x;

        return true;
    }

    return false;
}

bool UniSSR::isBit(uint8_t &value, const SSR &x)
{
    if ((value >> (uint8_t)x) & 1U)
    {
        return true;
    }

    return false;
}

} /// SENETNZ

