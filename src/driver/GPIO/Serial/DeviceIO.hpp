#ifndef DEVICEIO_HPP
#define DEVICEIO_HPP

#include <iostream>
#include <stdint.h>

#include "../GPIOif2.hpp"


namespace Sentenz
{

    /// Digital I/O
    enum class IO
    {
        IO17 = 17,
        IO18 = 18,
        IO27 = 27,
        IO22 = 22,
        IO23 = 23,
        IO24 = 24,
        IO25 = 25,
        IO05 = 5,
        IO06 = 6,
        IO12 = 12,
        IO13 = 13,
        IO19 = 19,
        IO16 = 16,
        IO26 = 26,
        IO20 = 20,
        IO21 = 21,
    };


    /// PWM Output
    enum class PWM
    {
    };

    /////////////////////////////////////////////////////////////////////////////
    //				      UniPi IO                                 //
    /////////////////////////////////////////////////////////////////////////////

    class DeviceIO : protected GPIOif2
    {
    public:
        DeviceIO(char *host = NULL, char *port = const_cast<char*>("8888"));
        ~DeviceIO();
        const DeviceIO& operator=(const DeviceIO&) = delete;

        /// Member functions
        bool read(const IO pin);
        bool write(const IO pin, const bool level = false);

        bool write(const PWM pin, unsigned frequency, unsigned range, unsigned dutycycle);

    private:
        /// Members
        char *optHost;
        char *optPort;
        int pi;
    };

} /// SENTENZ

#endif /// DEVICEIO_HPP
