#ifndef UNIADC_HPP
#define UNIADC_HPP

#include <iostream>
#include <vector>
#include <stdint.h>

#include "../GPIO/GPIOif2.hpp"

namespace Sentenz
{

const std::vector<std::vector<int>> BIT_MASK {
    {0b111111111111, 0b100000000000, 4167},
    {0b11111111111111, 0b10000000000000, 16667},
    {0b1111111111111111, 0b1000000000000000, 66667},
    {0b111111111111111111, 0b100000000000000000, 266667}
};

enum class UniADCchannel
{
    C0 = 0b00,
    C1 = 0b01
};

enum class UniADCmeasurement
{
    Continuous  = 1,
    Single      = 0
};

enum class UniADCbits
{
    Bits12 = 0b00,
    Bits14 = 0b01,
    Bits16 = 0b10,
    Bits18 = 0b11
};

enum class UniADCgain
{
    x1 = 0b00,
    x2 = 0b01,
    x4 = 0b10,
    x8 = 0b11
};

/////////////////////////////////////////////////////////////////////////////
//				 UniPi ADC                                 //
/////////////////////////////////////////////////////////////////////////////

    class UniADC : protected GPIOif2
    {
    public:
        UniADC(char *host = NULL, char *port = const_cast<char*>("8888"));
        ~UniADC();
        //const UniADC& operator=(const UniADC&) = delete;

        /// Member essential functions
        void open();
        void close();

        /// Member configure functions
        bool config(const UniADCchannel channel, const UniADCbits bits, const UniADCgain gain, const UniADCmeasurement modus);

        /// Member read functions
        double& getValue();
        int getStatus();

    private:
        /// Members functions
        int waittime();

        /// Members
        char *optHost;
        char *optPort;
        int pi;
        int handle = 0;
        int mode = 0;
        int status = 0;
        int _bits = 0;
        int _gain = 0;
        double out = .0;
        double correction = 5.564920867 * 2.;
    };

} /// SENTENZ

#endif /// UNIADC_HPP
