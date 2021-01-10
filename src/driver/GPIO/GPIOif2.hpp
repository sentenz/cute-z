#ifndef GPIOIF2_HPP
#define GPIOIF2_HPP

#include <iostream>

namespace Sentenz
{

    /////////////////////////////////////////////////////////////////////////////
    //                                  GPIOif2                                //
    /////////////////////////////////////////////////////////////////////////////

    class GPIOif2
    {
    public:
        GPIOif2() = default;
        ~GPIOif2() = default;
        const GPIOif2& operator=(const GPIOif2&) = delete;


    protected:
        /// Member I2C write / read
        bool read_i2c_byte(int pi, unsigned handle, int &out);
        bool read_i2c_byte_data(int pi, unsigned handle, unsigned reg, int &out);
        bool read_i2c_word_data(int pi, unsigned handle, unsigned reg, int &out);
        bool read_i2c_block_data(int pi, unsigned handle, unsigned reg, char *buf, unsigned count);
        bool read_i2c_device(int pi, unsigned handle, char *buf, unsigned count);

        bool write_i2c_byte(int pi, unsigned handle, unsigned in);
        bool write_i2c_byte_data(int pi, unsigned handle, unsigned reg, unsigned in);
        bool write_i2c_word_data(int pi, unsigned handle, unsigned reg, unsigned in);
        bool write_i2c_block_data(int pi, unsigned handle, unsigned reg, unsigned in, unsigned count);
        bool write_i2c_device(int pi, unsigned handle, char *buf, unsigned count);

        /// Member PWM
        bool pwm(int pi, unsigned pin, unsigned frequency, unsigned range, unsigned dutycycle);

        /// Member DI / DO
        bool read_input(int pi, unsigned pin);
        bool write_output(int pi, unsigned pin, unsigned level);
    };

} /// SENTENZ

#endif /// GPIOIF2_HPP
