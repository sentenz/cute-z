#include <iostream>
#include <exception>
#include <stdexcept>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cstddef>
#include <unistd.h>
#include <bitset>
#include <pigpio.h>

#include "GPIO.hpp"

namespace Sentenz
{

    /////////////////////////////////////////////////////////////////////////////
    //                               Initialize                                //
    /////////////////////////////////////////////////////////////////////////////

    GPIO::GPIO()
    {
        if (gpioInitialise() < 0)
        {
            throw std::runtime_error("warning: pigpio initialization failed!");
        }
    }

    GPIO::~GPIO()
    {
        gpioTerminate();
    }


    /////////////////////////////////////////////////////////////////////////////
    //                               I2C Writes                                //
    /////////////////////////////////////////////////////////////////////////////

    ///
    /// @brief Sends a single byte to the I2C device
    ///
    /// @return True if successful write operation. False otherwise.
    ///
    bool GPIO::writeByte(int handle, int in)
    {
        int val = i2cWriteByte(handle, in);

        if (val == PI_BAD_HANDLE || val == PI_BAD_PARAM || val == PI_I2C_WRITE_FAILED)
        {
            return false;
        }

        return true;
    }

    ///
    /// @brief Sends a single byte to the I2C device
    ///
    /// @return True if successful write operation. False otherwise.
    ///
    bool GPIO::writeByteData(int handle, int reg, int in)
    {
        int val = i2cWriteByteData(handle, reg, in);

        if (val == PI_BAD_HANDLE || val == PI_BAD_PARAM || val == PI_I2C_WRITE_FAILED)
        {
            return false;
        }

        return true;
    }

    ///
    /// @brief Sends 16 bit word to the I2C device.
    ///
    /// @return True if successful write operation. False otherwise.
    ///
    bool GPIO::writeWordData(int handle, int reg, int in)
    {
        int val = i2cWriteWordData(handle, reg, in);

        usleep(600);

        if (val == PI_BAD_HANDLE || val == PI_BAD_PARAM || val == PI_I2C_WRITE_FAILED)
        {
            return false;
        }

        return true;
    }

    ///
    /// @brief Sends a block of up to 32 bytes to the I2C device.
    ///
    /// @return True if successful write operation. False otherwise.
    ///
    bool GPIO::writeBlockData(int handle, int reg, int in, int count)
    {
        char buf[count];
        sprintf(buf, "%d", in);

        int val = i2cWriteI2CBlockData(handle, reg, buf, count);

        usleep(1000);

        if (val == PI_BAD_HANDLE || val == PI_BAD_PARAM || val == PI_I2C_WRITE_FAILED)
        {
            return false;
        }

        return true;
    }

    ///
    /// @brief Sends count bytes to the I2C device
    ///
    /// @return True if successful write operation. False otherwise.
    ///
    bool GPIO::writeDevice(unsigned handle, char *buf, unsigned count)
    {
        int val = i2cWriteDevice(handle, buf, count);

        usleep(1000);

        if (val == PI_BAD_HANDLE || val == PI_BAD_PARAM || val == PI_I2C_WRITE_FAILED)
        {
            return false;
        }

        return true;
    }

    /////////////////////////////////////////////////////////////////////////////
    //                               I2C Reads                                 //
    /////////////////////////////////////////////////////////////////////////////

    ///
    /// @brief Reads a single byte from the I2C device
    ///
    /// @return True if successful write operation. False otherwise.
    ///
    bool GPIO::readByte(int handle, int &out)
    {
        out = i2cReadByte(handle);

        if (out == PI_BAD_HANDLE || out == PI_I2C_READ_FAILED)
        {
            return false;
        }

        return true;
    }

    ///
    /// @brief Reads a single byte from the I2C device
    ///
    /// @return True if successful write operation. False otherwise.
    ///
    bool GPIO::readByteData(int handle, int reg, int &out)
    {
        out = i2cReadByteData(handle, reg);

        if (out == PI_BAD_HANDLE || out == PI_BAD_PARAM || out == PI_I2C_READ_FAILED)
        {
            return false;
        }

        return true;
    }

    ///
    /// @brief Reads a single 16 bit word from the I2C device
    ///
    /// @return True if successful write operation. False otherwise.
    ///
    bool GPIO::readWordData(int handle, int reg, int &out)
    {
        out = i2cReadWordData(handle, reg);

        if (out == PI_BAD_HANDLE || out == PI_BAD_PARAM || out == PI_I2C_READ_FAILED)
        {
            return false;
        }

        return true;
    }

    ///
    /// @brief Reads a block of up to 32 bytes from the I2C device
    ///
    /// @return True if successful write operation. False otherwise.
    ///
    /// @usage uint16_t = (buf[0] << 8) | buf[1];
    ///
    bool GPIO::readBlockData(int handle, int reg, char *buf, int count)
    {
        int val = i2cReadI2CBlockData(handle, reg, buf, count);

        usleep(1000);

        if (val == PI_BAD_HANDLE || val == PI_BAD_PARAM || val == PI_I2C_READ_FAILED)
        {
            return false;
        }

        return true;
    }

    ///
    /// @brief Reads count bytes from the I2C device
    ///
    /// @return True if successful write operation. False otherwise.
    ///
    bool GPIO::readDevice(int handle, char *buf, int count)
    {
        int val = i2cReadDevice(handle, buf, count);

        usleep(1000);

        if (val == PI_BAD_HANDLE || val == PI_BAD_PARAM || val == PI_I2C_READ_FAILED)
        {
            return false;
        }

        return true;
    }

    /////////////////////////////////////////////////////////////////////////////
    //                                   PWM                                   //
    /////////////////////////////////////////////////////////////////////////////

    ///
    /// @brief Configurat the frequency, range and dutycycle of the PWM on the GPIO
    ///
    /// @return True if successful write operation. False otherwise.
    ///
    bool GPIO::configPWM(int pin, int frequency, int value)
    {
        int val = 0;

        val = gpioSetPWMfrequency(pin, frequency);
        if (val == PI_BAD_USER_GPIO)
        {
            return false;
        }

        val = gpioSetPWMrange(pin, 1000);
        if (val == PI_BAD_USER_GPIO || val == PI_BAD_DUTYRANGE)
        {
            return false;
        }

        val = gpioPWM(pin, value);
        if (val == PI_BAD_USER_GPIO || val == PI_BAD_DUTYCYCLE)
        {
            return false;
        }

        return true;
    }

    /////////////////////////////////////////////////////////////////////////////
    //                                Digital Input                            //
    /////////////////////////////////////////////////////////////////////////////

    ///
    /// @brief Read GPIO
    ///
    /// @return True if successful write operation. False otherwise.
    ///
    bool GPIO::readInput(unsigned pin)
    {
        int val = 0;

        val = gpioSetMode(pin, PI_INPUT);
        if (val == PI_BAD_GPIO || val == PI_BAD_MODE)
        {
            return false;
        }

        val = gpioSetPullUpDown(pin, PI_PUD_UP);
        if (val == PI_BAD_GPIO || val == PI_BAD_PUD)
        {
            return false;
        }

        val = gpioRead(pin);
        if (val == PI_BAD_GPIO)
        {
            return false;
        }
        else if (val == 0)
        {
            return true;
        }

        return false;
    }

} /// SENTENZ
