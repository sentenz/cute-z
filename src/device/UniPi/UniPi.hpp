#ifndef UNIPI_HPP
#define UNIPI_HPP

#include <iostream>

#include "UniRelay.hpp"
#include "UniEPROM.hpp"
#include "UniADC.hpp"
#include "../GPIO/GPIO.hpp"


namespace Sentenz
{

/////////////////////////////////////////////////////////////////////////////
//				   UniPi                                   //
/////////////////////////////////////////////////////////////////////////////

    class UniPi : protected GPIO
    {
    public:
        UniPi() = default;
        ~UniPi() = default;
        const UniPi& operator=(const UniPi&) = delete;

        bool setPWM(double value, int frequency);

        bool getInput(unsigned pin);

        UniADC adc;
        UniRelay relay;
        UniEPROM eprom;
    };

} /// SENTENZ

#endif /// UNIPI_HPP
