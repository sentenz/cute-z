#include <iostream>
#include <exception>
#include <stdexcept>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstddef>
#include <bitset>
#include <pigpiod_if2.h>

#include "UniEPROM.hpp"

namespace Sentenz
{

/////////////////////////////////////////////////////////////////////////////
//                               Initialize                                //
/////////////////////////////////////////////////////////////////////////////

    UniEPROM::UniEPROM(char *host, char *port) : optHost(host), optPort(port)
    {
        pi = pigpio_start(optHost, optPort);

        if (pi < 0)
        {
            throw std::runtime_error("warning: unipi eprom pigpio_if2 start failed!");
        }

        open();
    }

    UniEPROM::~UniEPROM()
    {
        close();

        if (pi >= 0)
            pigpio_stop(pi);
    }

/////////////////////////////////////////////////////////////////////////////
//                            EPROM Essential                              //
/////////////////////////////////////////////////////////////////////////////

    ///
    /// @brief Open I2C device
    ///
    void UniEPROM::open()
    {
        handle = i2c_open(pi, 1, 0x50, 0);
    }

    ///
    /// @brief Close I2C device
    ///
    void UniEPROM::close()
    {
        if (handle)
            i2c_close(pi, handle);
    }

/////////////////////////////////////////////////////////////////////////////
//                                 Reads                                   //
/////////////////////////////////////////////////////////////////////////////

    ///
    /// @brief
    ///
    /// @return True if successful write operation. False otherwise.
    ///
    bool UniEPROM::getIdentification(int &out)
    {
        if (!this->read_word_data(pi, handle, EPROM_ID, out))
        {
            return false;
        }

        if (out)
        {
            return true;
        }

        return false;
    }

    ///
    /// @brief
    ///
    /// @return True if successful write operation. False otherwise.
    ///
    bool UniEPROM::getVersion(int &out)
    {
        if (!this->read_word_data(pi, handle, EPROM_VS, out))
        {
            return false;
        }

        if (out)
        {
            return true;
        }

        return false;
    }

    ///
    /// @brief
    ///
    /// @return True if successful write operation. False otherwise.
    ///
    bool UniEPROM::getSerialnumber(uint32_t &out)
    {
        int count = 4;
        char data[count];

        if (!this->read_i2c_block_data(pi, handle, EPROM_SN, data, count))
        {
            return false;
        }

        out = atoi(data);

        if (out)
        {
            return true;
        }

        return false;
    }

    ///
    /// @brief
    ///
    /// @return True if successful write operation. False otherwise.
    ///
    bool UniEPROM::getCoefficient(uint32_t &out)
    {
        int count = 4;
        char data[count];

        if (!this->read_i2c_block_data(pi, handle, EPROM_CO, data, count))
        {
            return false;
        }

        out = atoi(data);

        if (out)
        {
            return true;
        }

        return false;
    }

/////////////////////////////////////////////////////////////////////////////
//                                  Writes                                 //
/////////////////////////////////////////////////////////////////////////////

    ///
    /// @brief
    ///
    /// @return True if successful write operation. False otherwise.
    ///
    bool UniEPROM::setIdentification(int in)
    {
        return this->write_word_data(pi, handle, EPROM_ID, in);
    }

    ///
    /// @brief
    ///
    /// @return True if successful write operation. False otherwise.
    ///
    bool UniEPROM::setSerialnumber(uint32_t in)
    {
        int count = 4;

        return this->write_i2c_block_data(pi, handle, EPROM_SN, in, count);
    }

    ///
    /// @brief
    ///
    /// @return True if successful write operation. False otherwise.
    ///
    bool UniEPROM::setCoefficient(uint32_t in)
    {
        int count = 4;

        return this->write_i2c_block_data(pi, handle, EPROM_CO, in, count);
    }

} /// SENTENZ
