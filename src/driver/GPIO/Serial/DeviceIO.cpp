#include <iostream>
#include <exception>
#include <stdexcept>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstddef>
#include <bitset>
#include <cassert>
#include <pigpiod_if2.h>

#include "DeviceIO.hpp"

namespace Sentenz
{

    /////////////////////////////////////////////////////////////////////////////
    //                               Initialize                                //
    /////////////////////////////////////////////////////////////////////////////

    DeviceIO::DeviceIO(char *host, char *port) : optHost(host), optPort(port)
    {
        pi = pigpio_start(optHost, optPort);

        if (pi < 0)
        {
            throw std::runtime_error("warning: devive io pigpio_if2 start failed!");
        }
    }

    DeviceIO::~DeviceIO()
    {
        if (pi >= 0)
        {
            pigpio_stop(pi);
        }
    }

    /////////////////////////////////////////////////////////////////////////////
    //                             Read / Write                                //
    /////////////////////////////////////////////////////////////////////////////

    ///
    /// @brief Read input.
    ///
    /// @return True if successful read operation. False otherwise.
    ///
    bool DeviceIO::read(const IO pin)
    {
        return this->read_input(pi, (unsigned)pin);
    }

    ///
    /// @brief Write output.
    ///
    /// @return True if successful read operation. False otherwise.
    ///
    bool DeviceIO::write(const IO pin, const bool level)
    {
        return this->write_output(pi, (unsigned)pin, (unsigned)level);
    }

    /////////////////////////////////////////////////////////////////////////////
    //                                   PWM                                   //
    /////////////////////////////////////////////////////////////////////////////

    ///
    /// @brief Write PWM output
    ///
    /// @return True if successful read operation. False otherwise.
    ///
    bool DeviceIO::write(const PWM pin, unsigned frequency, unsigned range, unsigned dutycycle)
    {
        return this->pwm(pi, (unsigned)pin, frequency, range, dutycycle);
    }

} /// SENTENZ
