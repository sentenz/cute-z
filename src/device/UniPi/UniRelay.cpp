#include "UniRelay.hpp"
#include <pigpiod_if2.h>

#include <iostream>
#include <exception>
#include <stdexcept>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstddef>
#include <bitset>


namespace Sentenz
{

/////////////////////////////////////////////////////////////////////////////
//                               Initialize                                //
/////////////////////////////////////////////////////////////////////////////

    UniRelay::UniRelay(int bus, char *host, char *port) : i2cBus(bus), optHost(host), optPort(port)
    {
        pi = pigpio_start(optHost, optPort);

        if (pi < 0)
        {
            throw std::runtime_error("warning: unipi relay pigpio_if2 start failed!");
        }

        open();
    }

    UniRelay::~UniRelay()
    {
        close();

        if (pi >= 0)
            pigpio_stop(pi);
    }

/////////////////////////////////////////////////////////////////////////////
//                                Essential                                //
/////////////////////////////////////////////////////////////////////////////

    ///
    /// @brief Open I2C device
    ///
    void UniRelay::open()
    {
        handle = i2c_open(pi, 1, i2cBus, 0);

        //this->write_i2c_byte_data(pi, handle, MCP23008_GPPU, 0x00);   /// no pullup, not required on output
        this->write_i2c_byte_data(pi, handle, MCP23008_IODIR, 0x00);    /// all output
    }

    ///
    /// @brief Close I2C device
    ///
    void UniRelay::close()
    {
        this->write_i2c_byte_data(pi, handle, MCP23008_OLAT, 0x00);

        if (handle)
            i2c_close(pi, handle);
    }

/////////////////////////////////////////////////////////////////////////////
//                             Relay Control                               //
/////////////////////////////////////////////////////////////////////////////

    ///
    /// @brief
    ///
    /// @return True if successful write operation. False otherwise.
    ///
    bool UniRelay::latch(const Relay x)
    {
        int olat;

        /// Read
        ///
        if (!this->read_i2c_byte_data(pi, handle, MCP23008_OLAT, olat))
        {
            return false;
        }

        /// Write
        ///
        if (!(olat & (1 << (unsigned)x)))
        {
            olat |= 1 << (unsigned)x;

            return this->write_i2c_byte_data(pi, handle, MCP23008_OLAT, olat);
        }

        return true;
    }

    ///
    /// @brief
    ///
    /// @return True if successful write operation. False otherwise.
    ///
    bool UniRelay::unlatch(const Relay x)
    {
        int olat;

        /// Read
        ///
        if (!this->read_i2c_byte_data(pi, handle, MCP23008_OLAT, olat))
        {
            return false;
        }

        /// Write
        ///
        if ((olat & (1 << (unsigned)x)))
        {
            olat &= ~(1 << (unsigned)x);

            return this->write_i2c_byte_data(pi, handle, MCP23008_OLAT, olat);
        }

        return true;
    }

    ///
    /// @brief
    ///
    /// @return True if successful read operation. False otherwise.
    ///
    bool UniRelay::isLatched(const Relay x)
    {
        int olat;

        /// Read
        ///
        if (!this->read_i2c_byte_data(pi, handle, MCP23008_OLAT, olat))
        {
            return false;
        }

        if ((olat >> (unsigned)x) & 1U)
        {
            return true;
        }

        return false;
    }

    ///
    /// @brief
    ///
    /// @return True if successful read operation. False otherwise.
    ///
    int UniRelay::getSatus()
    {
        int olat;

        /// Read
        ///
        if (!this->read_i2c_byte_data(pi, handle, MCP23008_OLAT, olat))
        {
            return false;
        }

        return olat;
    }

} /// SENTENZ
