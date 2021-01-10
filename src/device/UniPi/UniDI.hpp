#ifndef UNIDI_HPP
#define UNIDI_HPP

#include <iostream>
#include <stdint.h>

#include "../GPIO/GPIOif2.hpp"


namespace Sentenz
{

/// Digital Input
enum class UniInput
{
    I01 = 4,
    I02 = 17,
    I03 = 27,
    I04 = 23,
    I05 = 22,
    I06 = 24,
    I07 = 11,
    I08 = 7,
    I09 = 8,
    I10 = 9,
    I11 = 25,
    I12 = 10,
    I13 = 31,
    I14 = 30
};


/////////////////////////////////////////////////////////////////////////////
//				  UniPi IO                                 //
/////////////////////////////////////////////////////////////////////////////

    class UniDI : protected GPIOif2
    {
    public:
        UniDI(char *host = NULL, char *port = const_cast<char*>("8888"));
        ~UniDI();
        const UniDI& operator=(const UniDI&) = delete;

        /// Member functions
        bool isStatus(const UniInput pin);

    private:
        /// Members
        char *optHost;
        char *optPort;
        int pi;
    };

} /// SENTENZ

#endif /// UNIDI_HPP
