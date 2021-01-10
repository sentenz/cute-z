#include <iostream>
#include <utility>
#include <cstring>
#include <string.h>
#include <cmath>
#include <vector>
#include <unistd.h>
#include <pigpiod_if2.h>


#include "HMC5883L.hpp"

namespace Sentenz
{

/////////////////////////////////////////////////////////////////////////////
//                                 HMC5883L                                //
/////////////////////////////////////////////////////////////////////////////

    HMC5883L::HMC5883L(char *host, char *port) : optHost(host), optPort(port)
    {
        pi = pigpio_start(optHost, optPort);

        if (pi < 0)
        {
	    throw std::runtime_error("warning: pigpio start failed!");
        }

        open();
    }

    HMC5883L::~HMC5883L()
    {
        close();

        if (pi >= 0)
            pigpio_stop(pi);
    }

/////////////////////////////////////////////////////////////////////////////
//                                Essential                                //
/////////////////////////////////////////////////////////////////////////////

    //
    // @brief Open I2C device
    //
    void HMC5883L::open()
    {
        handle = i2c_open(pi, 1, 0x1E, 0);
    }

    //
    // @brief Close I2C device
    //
    void HMC5883L::close()
    {
        if (handle >= 0)
            i2c_close(pi, handle);
    }

/////////////////////////////////////////////////////////////////////////////
//                              Configuration                              //
/////////////////////////////////////////////////////////////////////////////

    //
    // @brief Configer register A, B and MODE
    //
    void HMC5883L::config(int m_aver, double m_rate, int m_bais, int m_gain, int m_mode)
    {
        /// REGISTER A
        uint8_t configA = 0;

        configA |= AVERAGE.at(m_aver);
        configA |= RATE.at(m_rate);
        configA |= BAIS.at(m_bais);

        this->write_byte_data(pi, handle, HMC5883L_CONF_B, configA);


        /// REGISTER B
        uint8_t configB = 0;

        configB |= GAIN.at(m_gain).first;

        this->write_byte_data(pi, handle, HMC5883L_CONF_B, configB);

        scale = getGain();


        /// REGISTER MODE
        uint8_t mode = 0;

        mode |= MODE.at(m_mode);

        this->write_byte_data(pi, handle, HMC5883L_MODE, mode);
    }


/////////////////////////////////////////////////////////////////////////////
//                             HMC5883L Reads                              //
/////////////////////////////////////////////////////////////////////////////

    //
    // @brief Reads datas from registers DATA
    //
    // @return True if successful reads. False otherwise.
    //
    bool HMC5883L::getDatas(const std::string &str, std::vector<double> &out)
    {
        if (!isStatus())
        {
            return false;
        }

        int count = 0;
        if (str.find("x") < 3)
        {
            count += 1;
        }
        if (str.find("z") < 3)
        {
            count += 1;
        }
        if (str.find("y") < 3)
        {
            count += 1;
        }

        if ((out.empty() && count) || out.size() != (size_t)count)
        {
            out.clear();
            out.resize(count);
        }

        if (out.size() > 1)
        {
            unsigned size = 6;
            char data[size];

            if (!this->read_i2c_block_data(pi, handle, HMC5883L_DATA, data, size))
            {
                return false;
            }

            if (str.find("x") < 3)
                out.at(str.find("x")) = static_cast<double>((data[0] << 8) | data[1]) / 65535.0 * scale;
            if (str.find("z") < 3)
                out.at(str.find("z")) = static_cast<double>((data[2] << 8) | data[3]) / 65535.0 * scale;
            if (str.find("y") < 3)
                out.at(str.find("y")) = static_cast<double>((data[4] << 8) | data[5]) / 65535.0 * scale;
        }
        else if (out.size() == 1)
        {
            unsigned size = 2;
            char data[size];

            if (!this->read_i2c_block_data(pi, handle, HMC5883L_DATA + CHANNEL.at(*str.c_str()), data, size))
            {
                return false;
            }

            out.front() = static_cast<double>((data[0] << 8) | data[1]) / 65535.0 * scale;
        }

        return true;
    }


    //
    // @brief Reads datas from registers DATA
    //
    // @return True if successful reads. False otherwise.
    //
    bool HMC5883L::getPulse(const std::string &str)
    {
        if (getDatas(str, value))
        {
            bool tmp = static_cast<bool>(round(value[0]));

            if (tmp != pulse)
            {
                pulse = tmp;
                return true;
            }
        }

        return false;
    }

    //
    // @brief Reads status from register STATUS
    //
    // @return Status if the device has a value.
    //
    bool HMC5883L::isStatus()
    {
        int val = 0;

        if (!this->read_byte_data(pi, handle, HMC5883L_STATUS, val))
        {
            return false;
        }

        if (val & 0x01)
        {
            return true;
        }

        return false;
    }

    //
    // @brief Reads gain from register B
    //
    // @return Gain value of the device.
    //
    double HMC5883L::getGain()
    {
        int val = 0;

        this->read_byte_data(pi, handle, HMC5883L_CONF_B, val);

        return GAIN.at(val >> 5).second;
    }

} /// SENTENZ
