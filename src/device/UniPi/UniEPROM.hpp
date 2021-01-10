#ifndef UNIEPROM_HPP
#define UNIEPROM_HPP

#include <iostream>
#include <stdint.h>

#include "../GPIO/GPIOif2.hpp"


namespace Sentenz
{

/// Relay register addresses
constexpr int EPROM_ID = 0xe0;	// UniPi identification
constexpr int EPROM_VS = 0xe2;	// UniPi version
constexpr int EPROM_SN = 0xf0;	// UniPi Seriennummer
constexpr int EPROM_CO = 0xf4;	// UniPi coefficient

/////////////////////////////////////////////////////////////////////////////
//				UniPi EPROM                                //
/////////////////////////////////////////////////////////////////////////////

    class UniEPROM : protected GPIOif2
    {
    public:
        UniEPROM(char *host = NULL, char *port = const_cast<char*>("8888"));
        ~UniEPROM();
        //const UniEPROM& operator=(const UniEPROM&) = delete;

        /// Member essential functions
        void open();
        void close();

        /// Member functions
        bool getIdentification(int &out);
        bool getVersion(int &out);
        bool getSerialnumber(uint32_t &out);
        bool getCoefficient(uint32_t &out);

        bool setIdentification(int in);
        bool setSerialnumber(uint32_t in);
        bool setCoefficient(uint32_t in);

    private:
        /// Members
        char *optHost;
        char *optPort;
        int pi;
        int handle = 0;
    };

} /// SENTENZ

#endif /// UNIEPROM_HPP
