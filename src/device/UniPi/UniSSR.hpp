#ifndef UNISSR_HPP
#define UNISSR_HPP

#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <vector>
#include <string>

namespace Sentenz
{

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


    class UniSSR
    {
    public:
        explicit UniSSR(const std::string &dev, const std::string txt);
        ~UniSSR();

        /// Member functions
        bool latch(const SSR &x);
        bool latch(const std::vector<SSR> &x);
        bool unlatch(const SSR &x);
        bool unlatch(const std::vector<SSR> &x);
        bool isLatched(const SSR &x);
        bool reset();

        void setPath(const std::string &path);
        void setDevice(const std::string &device);
        void setFile(const std::string &text);
        void setFilename();

    private:
        bool setBit(uint8_t &value, const SSR &x);
        bool unsetBit(uint8_t &value, const SSR &x);
        bool isBit(uint8_t &value, const SSR &x);

        std::fstream *infile = nullptr;
        std::string filename;
        std::string path = "/sys/bus/w1/devices";
        std::string device;
        std::string text;
    };

} /// SENETNZ

#endif /// UniSSR_HPP
