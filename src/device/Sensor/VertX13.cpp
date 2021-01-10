#include "VertX13.hpp"

#include <iostream>
#include <exception>
#include <stdexcept>
#include <utility>
#include <cstring>
#include <string.h>
#include <cmath>
#include <pigpiod_if2.h>

#include <bitset>


namespace Sentenz
{

/////////////////////////////////////////////////////////////////////////////
//                                  VertX13                                //
/////////////////////////////////////////////////////////////////////////////

    VertX13::VertX13(char *host, char *port) : optHost(host), optPort(port)
    {
        this->pi = pigpio_start(this->optHost, this->optPort);

        if (this->pi < 0)
        {
            throw std::runtime_error("warning: VertX13 pigpio_if2 start failed!");
        }

        this->open();
    }

    VertX13::~VertX13()
    {
        this->close();

        if (this->pi >= 0)
        {
            pigpio_stop(this->pi);
        }
    }

/////////////////////////////////////////////////////////////////////////////
//                                Essential                                //
/////////////////////////////////////////////////////////////////////////////

    ///
    /// @brief Open SPI device
    ///
    void VertX13::open()
    {
        //this->handle = spi_open(this->pi, 0, 1000000, AUX_3WIRE | AUX_BYTES(3));
        this->handle = spi_open(this->pi, 0, 1000000, AUX_BITS(14));
    }

    ///
    /// @brief Close SPI device
    ///
    void VertX13::close()
    {
        if (this->handle >= 0)
        {
            spi_close(this->pi, this->handle);
        }
    }

/////////////////////////////////////////////////////////////////////////////
//                                   Read                                  //
/////////////////////////////////////////////////////////////////////////////

    ///
    /// @brief Read SPI device
    ///
    double VertX13::read()
    {
        //status = spi_read(this->pi, this->handle, (char*)&this->rxBuf, sizeof(this->rxBuf));
        status = spi_xfer(this->pi, this->handle, (char*)&this->txBuf, (char*)&this->rxBuf, sizeof(this->rxBuf));

        std::cout << "Status " << status << std::endl;
        std::cout << "Write " << txBuf[0] << " " << txBuf[1] << std::endl;
        std::cout << "Read " << rxBuf[0] << " " << rxBuf[1] << std::endl;

        return static_cast<double>((this->rxBuf[1] << 8) | this->rxBuf[0]) / 16383.0;
    }

} /// SENTENZ
