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

#include "UniDI.hpp"

namespace Sentenz
{

/////////////////////////////////////////////////////////////////////////////
//                               Initialize                                //
/////////////////////////////////////////////////////////////////////////////

    UniDI::UniDI(char *host, char *port) : optHost(host), optPort(port)
    {
        pi = pigpio_start(optHost, optPort);

        if (pi < 0)
        {
            throw std::runtime_error("warning: unipi input pigpio_if2 start failed!");
        }
    }

    UniDI::~UniDI()
    {
        if (pi >= 0)
            pigpio_stop(pi);
    }

/////////////////////////////////////////////////////////////////////////////
//                                  Read                                   //
/////////////////////////////////////////////////////////////////////////////

    ///
    /// @brief
    ///
    /// @return True if successful read operation. False otherwise.
    ///
    bool UniDI::isStatus(const UniInput pin)
    {
        return read_input(pi, (unsigned)pin);
    }

} /// SENTENZ
