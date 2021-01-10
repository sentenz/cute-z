#ifndef UNIPWM_HPP
#define UNIPWM_HPP

#include <iostream>
#include <stdint.h>

#include "../GPIO/GPIOif2.hpp"


namespace Sentenz
{

/////////////////////////////////////////////////////////////////////////////
//				   UniPWM                                  //
/////////////////////////////////////////////////////////////////////////////

    class UniPWM : protected GPIOif2
    {
    public:
        UniPWM(char *host = NULL, char *port = const_cast<char*>("8888"));
        ~UniPWM();
        //const UniPWM& operator=(const UniPWM&) = delete;

        /// Member functions
        bool setValue(double value, int frequency, int pin = 18);
        int getFrequency();
        int getDutycycle();
        int getRange();

    private:
        /// Members
        char *optHost;
        char *optPort;
        int pi;
    };

} /// SENTENZ

#endif /// UNIPWM_HPP
