#include <iostream>
#include <exception>
#include <stdexcept>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstddef>
#include <unistd.h>
#include <bitset>
#include <cassert>
#include <pigpiod_if2.h>

#include "UniADC.hpp"

namespace Sentenz
{

/////////////////////////////////////////////////////////////////////////////
//                             Initialization                              //
/////////////////////////////////////////////////////////////////////////////

    UniADC::UniADC(char *host, char *port) : optHost(host), optPort(port)
    {
        pi = pigpio_start(optHost, optPort);

        if (pi < 0)
        {
            throw std::runtime_error("warning: unipi adc pigpio_if2 start failed!");
        }

        open();
    }

    UniADC::~UniADC()
    {
        close();

        if (pi >= 0)
            pigpio_stop(pi);
    }

/////////////////////////////////////////////////////////////////////////////
//                             ADC Essential                               //
/////////////////////////////////////////////////////////////////////////////

    ///
    /// @brief Open I2C device
    ///
    void UniADC::open()
    {
        handle = i2c_open(pi, 1, 0x68, 0);
    }

    ///
    /// @brief Close I2C device
    ///
    void UniADC::close()
    {
        if (handle)
            i2c_close(pi, handle);
    }

/////////////////////////////////////////////////////////////////////////////
//                          ADC Configuration                              //
/////////////////////////////////////////////////////////////////////////////

    ///
    /// @brief
    ///
    /// @return True if successful write operation. False otherwise.
    ///
    int UniADC::waittime()
    {
        return BIT_MASK[(_bits-12) >> 1][2];
    }

    ///
    /// @brief
    ///
    /// @return True if successful write operation. False otherwise.
    ///
    bool UniADC::config(const UniADCchannel channel, const UniADCbits bits, const UniADCgain gain, const UniADCmeasurement modus)
    {
        mode |= (unsigned)channel << 5;
        mode |= (unsigned)modus == 1 ? 1 << 4 : 1 << 4 | 1 << 7;
        mode |= (unsigned)bits << 2;
        mode |= (unsigned)gain;

        if (bits == UniADCbits::Bits12)
            _bits = 12;
        else if (bits == UniADCbits::Bits14)
            _bits = 14;
        else if (bits == UniADCbits::Bits16)
            _bits = 16;
        else if (bits == UniADCbits::Bits18)
            _bits = 18;

        if (gain == UniADCgain::x1)
            _gain = 1;
        else if (gain == UniADCgain::x2)
            _gain = 2;
        else if (gain == UniADCgain::x4)
            _gain = 4;
        else if (gain == UniADCgain::x8)
            _gain = 8;

        return this->write_byte(pi, handle, mode);
    }

/////////////////////////////////////////////////////////////////////////////
//                              Read / Write                               //
/////////////////////////////////////////////////////////////////////////////

    ///
    /// @brief
    ///
    /// @return True if successful write operation. False otherwise.
    ///
    int UniADC::getStatus()
    {
        return status;
    }

    ///
    /// @brief
    ///
    /// @return True if successful write operation. False otherwise.
    ///
    double& UniADC::getValue()
    {
        int count = _bits == 18 ? 4 : 3;
        char data[count];

        this->read_device(pi, handle, data, count);

        usleep(waittime());

        status = data[count-1];

        // DEBUG
        //std::cout << "Status " << std::bitset<8>(status) << std::endl;

        if (status & 0x80)
        {
            std::cerr << "Status\t" << std::bitset<8>(status) << std::endl;
        }
        if ((mode & 0x7F) != (status & 0x7F))
        {
            std::cerr << "Status\t" << std::bitset<8>(status) << std::endl;
        }

        int value = 0;
        for (int i = 0; i < count-1; ++i)
        {
            value = (value << 8) | data[i];
        }

        int bit = (status & 0x0C) >> 2;
        int sign = BIT_MASK[bit][1] & value;
        value &= BIT_MASK[bit][0];

        if (sign)
        {
            value = -value;
        }

        out = 2.048 / static_cast<double>(BIT_MASK[bit][0]) * static_cast<double>(value);
        out *= correction / static_cast<double>(_gain);

        return out;
    }

} /// SENTENZ
