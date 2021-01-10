#include <iostream>
#include <cassert>
#include <cmath>
#include <stdexcept>
#include <pigpio.h>

#include "UniPi.hpp"


namespace Sentenz
{

/////////////////////////////////////////////////////////////////////////////
//                             Initialization                              //
/////////////////////////////////////////////////////////////////////////////
/*
    UniPi::UniPi()
    {
        if (gpioInitialise() < 0)
        {
            throw std::runtime_error("warning: pigpio initialization failed!");
        }
    }

    UniPi::~UniPi()
    {
        gpioTerminate();
    }
*/
/////////////////////////////////////////////////////////////////////////////
//                                  PWM                                    //
/////////////////////////////////////////////////////////////////////////////

    ///
    /// @brief
    ///
    /// @return True if successful write operation. False otherwise.
    ///
    bool UniPi::setPWM(double value, int frequency)
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

        bool val = this->configPWM(18, frequency, (int)round(value * 100.));

        if (val == false)
        {
            return false;
        }

        return true;
    }

/////////////////////////////////////////////////////////////////////////////
//                                Digital Input                            //
/////////////////////////////////////////////////////////////////////////////

    bool UniPi::getInput(unsigned pin)
    {
        return readInput(pin);
    }

} /// SENTENZ
