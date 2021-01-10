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
#include <pigpiod_if2.h>

#include "GPIOif2.hpp"

namespace Sentenz
{

    /////////////////////////////////////////////////////////////////////////////
    //                               I2C Reads                                 //
    /////////////////////////////////////////////////////////////////////////////

    ///
    /// @brief Reads a single byte from the I2C device
    ///
    /// @return True if successful write operation. False otherwise.
    ///
    bool GPIOif2::read_i2c_byte(int pi, unsigned handle, int &out)
    {
        out = i2c_read_byte(pi, handle);

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
    bool GPIOif2::read_i2c_byte_data(int pi, unsigned handle, unsigned reg, int &out)
    {
        out = i2c_read_byte_data(pi, handle, reg);

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
    bool GPIOif2::read_i2c_word_data(int pi, unsigned handle, unsigned reg, int &out)
    {
        out = i2c_read_word_data(pi, handle, reg);

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
    bool GPIOif2::read_i2c_block_data(int pi, unsigned handle, unsigned reg, char *buf, unsigned count)
    {
        int val = i2c_read_i2c_block_data(pi, handle, reg, buf, count);

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
    bool GPIOif2::read_i2c_device(int pi, unsigned handle, char *buf, unsigned count)
    {
        int val = i2c_read_device(pi, handle, buf, count);

        usleep(1000);

        if (val == PI_BAD_HANDLE || val == PI_BAD_PARAM || val == PI_I2C_READ_FAILED)
        {
            return false;
        }

        return true;
    }

    /////////////////////////////////////////////////////////////////////////////
    //                               I2C Writes                                //
    /////////////////////////////////////////////////////////////////////////////

    ///
    /// @brief Sends a single byte to the I2C device
    ///
    /// @return True if successful write operation. False otherwise.
    ///
    bool GPIOif2::write_i2c_byte(int pi, unsigned handle, unsigned in)
    {
        int val = i2c_write_byte(pi, handle, in);

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
    bool GPIOif2::write_i2c_byte_data(int pi, unsigned handle, unsigned reg, unsigned in)
    {
        int val = i2c_write_byte_data(pi, handle, reg, in);

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
    bool GPIOif2::write_i2c_word_data(int pi, unsigned handle, unsigned reg, unsigned in)
    {
        int val = i2c_write_word_data(pi, handle, reg, in);

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
    bool GPIOif2::write_i2c_block_data(int pi, unsigned handle, unsigned reg, unsigned in, unsigned count)
    {
        char buf[count];
        sprintf(buf, "%d", in);

        int val = i2c_write_i2c_block_data(pi, handle, reg, buf, count);

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
    bool GPIOif2::write_i2c_device(int pi, unsigned handle, char *buf, unsigned count)
    {
        int val = i2c_write_device(pi, handle, buf, count);

        usleep(1000);

        if (val == PI_BAD_HANDLE || val == PI_BAD_PARAM || val == PI_I2C_WRITE_FAILED)
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
    bool GPIOif2::pwm(int pi, unsigned pin, unsigned frequency, unsigned range, unsigned dutycycle)
    {
        int val = 0;

        val = set_PWM_frequency(pi, pin, frequency);
        if (val == PI_BAD_USER_GPIO || val == PI_NOT_PERMITTED)
        {
            return false;
        }

        val = set_PWM_range(pi, pin, range);
        if (val == PI_BAD_USER_GPIO || val == PI_BAD_DUTYRANGE || val == PI_NOT_PERMITTED)
        {
            return false;
        }

        val = set_PWM_dutycycle(pi, pin, dutycycle);
        if (val == PI_BAD_USER_GPIO || val == PI_BAD_DUTYCYCLE || val == PI_NOT_PERMITTED)
        {
            return false;
        }

        return true;
    }

    /////////////////////////////////////////////////////////////////////////////
    //                           Digital Input / Output                        //
    /////////////////////////////////////////////////////////////////////////////

    ///
    /// @brief Read GPIO
    ///
    /// @return True if successful write operation. False otherwise.
    ///
    bool GPIOif2::read_input(int pi, unsigned pin)
    {
        int val = 0;

        val = set_mode(pi, pin, PI_INPUT);
        if (val == PI_BAD_GPIO || val == PI_BAD_MODE || val == PI_NOT_PERMITTED)
        {
            return false;
        }

        val = set_pull_up_down(pi, pin, PI_PUD_UP);
        if (val == PI_BAD_GPIO || val == PI_BAD_PUD || val == PI_NOT_PERMITTED)
        {
            return false;
        }

        val = gpio_read(pi, pin);
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

    ///
    /// @brief Write GPIO
    ///
    /// @return True if successful write operation. False otherwise.
    ///
    bool GPIOif2::write_output(int pi, unsigned pin, unsigned level)
    {
        int val = 0;

        val = set_mode(pi, pin, PI_OUTPUT);
        if (val == PI_BAD_GPIO || val == PI_BAD_MODE || val == PI_NOT_PERMITTED)
        {
            return false;
        }

        val = gpio_write(pi, pin, level);
        if (val == PI_BAD_GPIO || PI_BAD_LEVEL || PI_NOT_PERMITTED)
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
