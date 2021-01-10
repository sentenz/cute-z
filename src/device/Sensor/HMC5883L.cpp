#include "HMC5883L.hpp"

#include <iostream>
#include <exception>
#include <stdexcept>
#include <utility>
#include <cstring>
#include <string.h>
#include <cmath>
#include <vector>
#include <cassert>
#include <pigpiod_if2.h>

#include <bitset>

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
            throw std::runtime_error("warning: HMC5883L pigpio_if2 start failed!");
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

    ///
    /// @brief Open I2C device
    ///
    void HMC5883L::open()
    {
        handle = i2c_open(pi, 1, 0x1E, 0);
    }

    ///
    /// @brief Close I2C device
    ///
    void HMC5883L::close()
    {
        if (handle >= 0)
            i2c_close(pi, handle);
    }

/////////////////////////////////////////////////////////////////////////////
//                              Configuration                              //
/////////////////////////////////////////////////////////////////////////////

    void HMC5883L::setSampleAverage(HMC_AVERAGE average)
    {
        int config = 0;

        this->read_byte_data(pi, handle, HMC5883L_REG_CONFIG_A, config);

        config = (config & ~(average << 5)) | (config & (average << 5));

        this->write_byte_data(pi, handle, HMC5883L_REG_CONFIG_A, config);
    }

    int HMC5883L::getSampleAverage()
    {
        int config = 0;

        this->read_byte_data(pi, handle, HMC5883L_REG_CONFIG_A, config);

        return config;
    }

    void HMC5883L::setDataRate(HMC_RATE rate)
    {
        int config = 0;

        this->read_byte_data(pi, handle, HMC5883L_REG_CONFIG_A, config);

        config |= rate << 2;

        this->write_byte_data(pi, handle, HMC5883L_REG_CONFIG_A, config);
    }

    double HMC5883L::getDataRate()
    {
        return 0.0;
    }

    void HMC5883L::setBais(HMC_BAIS bais)
    {
        int config = 0;

        this->read_byte_data(pi, handle, HMC5883L_REG_CONFIG_A, config);

        config = (config & ~bais) | (config & bais);

        this->write_byte_data(pi, handle, HMC5883L_REG_CONFIG_A, config);
    }

    int HMC5883L::getBais()
    {
        int config = 0;

        if (!this->read_byte_data(pi, handle, HMC5883L_REG_CONFIG_A, config))
        {
            return -1;
        }

        std::cout << "Reg A " << std::bitset<8>(config) << std::endl;

        return config;
    }

    void HMC5883L::setGain(HMC_GAIN gain)
    {
        int config = 0;

        this->read_byte_data(pi, handle, HMC5883L_REG_CONFIG_B, config);

        config = gain << 5;

        this->write_byte_data(pi, handle, HMC5883L_REG_CONFIG_B, config);
    }

    double HMC5883L::getGain()
    {
        int config = 0;

        if (!this->read_byte_data(pi, handle, HMC5883L_REG_CONFIG_B, config))
        {
            return -1;
        }

        std::cout << "Reg B " << std::bitset<8>(config) << std::endl;

        return config;
    }

    void HMC5883L::setMode(HMC_MODE mode)
    {
        int config = 0;

        this->read_byte_data(pi, handle, HMC5883L_REG_MODE, config);

        config = mode;

        this->write_byte_data(pi, handle, HMC5883L_REG_MODE, config);
    }

    int HMC5883L::getMode()
    {
        int config = 0;

        if (!this->read_byte_data(pi, handle, HMC5883L_REG_MODE, config))
        {
            return -1;
        }

        std::cout << "Reg MODED " << std::bitset<8>(config) << std::endl;

        return config;
    }

/////////////////////////////////////////////////////////////////////////////
//                          HMC5883L Data Reads                            //
/////////////////////////////////////////////////////////////////////////////

    ///
    /// @brief Reads all datas from registers DATA
    ///
    /// @return True if successful reads. False otherwise.
    ///
    bool HMC5883L::getDatas(const std::string &str, std::vector<double> &out)
    {
        assert(str.size() == 3);

        if (!isStatus())
        {
            return false;
        }

        if (out.empty() || out.size() != str.size())
        {
            out.clear();
            out.resize(str.size());
        }

        if (!this->read_i2c_block_data(pi, handle, HMC5883L_REG_DATA, data, 6))
        {
            return false;
        }

        if (str.find("x") < 3)
            out.at(str.find("x")) = static_cast<double>((data[0] << 8) | data[1]) / 65535.0 * scale;
        if (str.find("z") < 3)
            out.at(str.find("z")) = static_cast<double>((data[2] << 8) | data[3]) / 65535.0 * scale;
        if (str.find("y") < 3)
            out.at(str.find("y")) = static_cast<double>((data[4] << 8) | data[5]) / 65535.0 * scale;
        
        return true;
    }

    ///
    /// @brief Reads X axes
    ///
    double HMC5883L::getX()
    {
        if (!this->read_i2c_block_data(pi, handle, HMC5883L_REG_DATA, data, 6))
        {
            return 0.0;
        }

        return static_cast<double>((data[0] << 8) | data[1]) / 65535.0 * scale;
    }

    ///
    /// @brief Reads Y axes
    ///
    double HMC5883L::getY()
    {
        if (!this->read_i2c_block_data(pi, handle, HMC5883L_REG_DATA, data, 6))
        {
            return 0.0;
        }

        return static_cast<double>((data[4] << 8) | data[5]) / 65535.0 * scale;
   }

    ///
    /// @brief Reads Z axes
    ///
    double HMC5883L::getZ()
    {
        if (!this->read_i2c_block_data(pi, handle, HMC5883L_REG_DATA, data, 6))
        {
            return 0.0;
        }

        return static_cast<double>((data[2] << 8) | data[3]) / 65535.0 * scale;
    }

    //
    // @brief Reads datas from registers DATA
    //
    // @return True if successful reads. False otherwise.
    //
    bool HMC5883L::getPulse()
    {
        if (isStatus())
        {
            bool tmp = static_cast<bool>(round(getZ()));

            if (tmp != pulse)
            {
                pulse = tmp;
                return true;
            }
        }

        return false;
    }

/////////////////////////////////////////////////////////////////////////////
//                                                                         //
/////////////////////////////////////////////////////////////////////////////

    //
    // @brief Reads status from register STATUS
    //
    // @return Status if the device has a value.
    //
    bool HMC5883L::isStatus()
    {
        int status = 0;

        if (!this->read_byte_data(pi, handle, HMC5883L_REG_STATUS, status))
        {
            return false;
        }

        if (status & 0x01)
        {
            return true;
        }

        return false;
    }

} /// SENTENZ
