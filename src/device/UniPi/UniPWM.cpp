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

#include "UniPWM.hpp"

namespace Sentenz
{

/////////////////////////////////////////////////////////////////////////////
//                               Initialize                                //
/////////////////////////////////////////////////////////////////////////////

    UniPWM::UniPWM(char *host, char *port) : optHost(host), optPort(port)
    {
        pi = pigpio_start(optHost, optPort);

        if (pi < 0)
        {
            throw std::runtime_error("warning: unipi pwm pigpio_if2 start failed!");
        }
    }

    UniPWM::~UniPWM()
    {
        if (pi >= 0)
            pigpio_stop(pi);
    }

/////////////////////////////////////////////////////////////////////////////
//                                  PWM                                    //
/////////////////////////////////////////////////////////////////////////////

    ///
    /// @brief
    ///
    /// @return True if successful write operation. False otherwise.
    ///
    bool UniPWM::setValue(double value, int frequency, int pin)
    {
        assert(frequency >= 0 && frequency <= 400);

        if (value > 10.0)
        {
            value = 10.0;
        }
        else if (value < 0.0)
        {
            value = 0.0;
        }

        bool val = this->config_PWM(pi, pin, frequency, 1000, (int)round(value * 100.));

        if (val == false)
        {
            return false;
        }

        return true;
    }

    int UniPWM::getFrequency()
    {
        return get_PWM_frequency(pi, 18);
    }

    int UniPWM::getDutycycle()
    {
        return get_PWM_dutycycle(pi, 18);
    }

    int UniPWM::getRange()
    {
        return get_PWM_range(pi, 18);
    }

} /// SENTENZ
