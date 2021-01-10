#ifndef UNIRELAY_HPP
#define UNIRELAY_HPP

#include "../GPIO/GPIOif2.hpp"

#include <iostream>
#include <stdint.h>


namespace Sentenz
{

    /// Debug
    #ifndef DEBUG
    constexpr int DEBUG  = 0;
    #endif

    /// Relay register addresses
    constexpr int MCP23008_IODIR = 0x00;    // direction 1=in, 0=out
    constexpr int MCP23008_IPOL	= 0x01;     // reversed input polarity
    constexpr int MCP23008_GPPU	= 0x06;     // pullup
    constexpr int MCP23008_GPIO	= 0x09;     // input/output
    constexpr int MCP23008_OLAT	= 0x0A;     // latch output status

    /// Relay
    enum class Relay
    {
        R8 = 0,
        R7 = 1,
        R6 = 2,
        R5 = 3,
        R4 = 4,
        R3 = 5,
        R2 = 6,
        R1 = 7
    };

/////////////////////////////////////////////////////////////////////////////
//				UniPi Relay                                //
/////////////////////////////////////////////////////////////////////////////

    class UniRelay : protected GPIOif2
    {
    public:
        UniRelay(int bus = 0x20, char *host = NULL, char *port = const_cast<char*>("8888"));
        ~UniRelay();
        //const UniRelay& operator=(const UniRelay&) = delete;

        /// Member essential functions
        void open();
        void close();

        /// Member functions
        bool latch(const Relay x);
        bool unlatch(const Relay x);
        bool isLatched(const Relay x);
        int getSatus();

    private:
        /// Members
        char *optHost;
        char *optPort;
        int pi;
        int handle = 0;
        int i2cBus;
    };

} /// SENTENZ

#endif /// UNIRELAY_HPP
