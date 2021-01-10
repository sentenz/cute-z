/*
 * Version 1.02
 *
 */

#ifndef DOF9_HPP
#define DOF9_HPP

#include <iostream>
#include <vector>
#include <string>
#include <stdint.h>

#include "../GPIO/GPIOif2.hpp"


namespace Sentenz
{

/////////////////////////////////////////////////////////////////////////////
//			             DOF9                                  //
/////////////////////////////////////////////////////////////////////////////

    class DOF9 : protected GPIOif2
    {
    public:
        DOF9(char *host = NULL, char *port = const_cast<char*>("8888"));
        ~DOF9();
        const DOF9& operator=(const DOF9&) = delete;

        /// Member essential
        void open();
        void close();

        void init();
        void read();
        bool status();

        float accel[3];
        float magnet[3];
        float gyro[3];

    private:
        /// Members
        char *optHost;
        char *optPort;
        int pi;
        int handleAccel;
        int handleMagnet;
        int handleGyro;

        char data[6];
    };

} /// SENTENZ

#endif /// DOF9_HPP
