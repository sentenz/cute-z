/*
 * Version 1.00
 *
 */

#ifndef VERTX13_HPP
#define VERTX13_HPP

#include <iostream>
#include <vector>
#include <string>
#include <stdint.h>

#include "../GPIO/GPIOif2.hpp"


namespace Sentenz
{

#define AUX_SPI         (1<<8)
#define AUX_3WIRE       (1<<9)
#define AUX_BITS(x)     ((x)<<16)
#define AUX_BYTES(x)    ((x)<<10)

/////////////////////////////////////////////////////////////////////////////
//			     Drehgeber Vert-X 13                           //
/////////////////////////////////////////////////////////////////////////////

    class VertX13 : protected GPIOif2
    {
    public:
        VertX13(char *host = NULL, char *port = const_cast<char*>("8888"));
        ~VertX13();
        const VertX13& operator=(const VertX13&) = delete;


        /// Member essential

        ///
        /// @brief Open SPI
        ///
        void open();

        ///
        /// @brief Close SPI
        ///
        void close();


        /// Member

        ///
        /// @brief Read SPI
        ///
        double read();


    private:
        char *optHost;
        char *optPort;
        int pi;
        int handle;

        /// Members
        char rxBuf[2] = {0};
        char txBuf[2] = {0};
        int bits, status;
    };

} /// SENTENZ

#endif /// VERTX13_HPP
