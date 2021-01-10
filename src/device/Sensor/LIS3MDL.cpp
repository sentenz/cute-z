#include "LIS3MDL.hpp"

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
//                                 LIS3MDL                                //
/////////////////////////////////////////////////////////////////////////////

    LIS3MDL::LIS3MDL(char *host, char *port) : optHost(host), optPort(port)
    {
        pi = pigpio_start(optHost, optPort);

        if (pi < 0)
        {
            throw std::runtime_error("warning: LIS3MDL pigpio_if2 start failed!");
        }

        open();

        this->axes.resize(3, 0.0);
    }

    LIS3MDL::~LIS3MDL()
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
    void LIS3MDL::open()
    {
        handle = i2c_open(pi, 1, (unsigned)LIS_I2C::SA1_HIGH, 0);
    }

    ///
    /// @brief Close I2C device
    ///
    void LIS3MDL::close()
    {
        if (handle >= 0)
            i2c_close(pi, handle);
    }

/////////////////////////////////////////////////////////////////////////////
//                              Configuration                              //
/////////////////////////////////////////////////////////////////////////////

    void LIS3MDL::setDataRate(const LIS_DataRate dataRate)
    {
        int value = 0;

        /// READ
        this->read_i2c_byte_data(pi, handle, (unsigned)LIS_Reg::CTRL_REG1, value);

        /// SET BITS
        int mask = 0b1111 << 1;
        value = (value & (~mask)) | ((unsigned)dataRate << 1);

        /// WRITE
        this->write_i2c_byte_data(pi, handle, (unsigned)LIS_Reg::CTRL_REG1, value);

        switch (dataRate)
        {
        case LIS_DataRate::Hz_155:
        {
            this->setOperatingMode(LIS_OperatingMode::UP);
        }
            break;
        case LIS_DataRate::Hz_300:
        {
            this->setOperatingMode(LIS_OperatingMode::HP);
        }
            break;
        case LIS_DataRate::Hz_560:
        {
            this->setOperatingMode(LIS_OperatingMode::MP);
        }
            break;
        case LIS_DataRate::Hz_1000:
        {
            this->setOperatingMode(LIS_OperatingMode::LP);
        }
            break;
        default:
            break;
        }

        this->setSystemMode(LIS_SystemMode::Continuous);
    }

    void LIS3MDL::setOperatingMode(const LIS_OperatingMode operating)
    {
        /// Register CTRL_REG1: bits OM1, OM0
        int value = 0;

        /// READ
        !this->read_i2c_byte_data(pi, handle, (unsigned)LIS_Reg::CTRL_REG1, value);

        /// SET BITS
        int mask = 0b11 << 5;
        value = (value & (~mask)) | ((unsigned)operating << 5);

        /// WRITE
        this->write_i2c_byte_data(pi, handle, (unsigned)LIS_Reg::CTRL_REG1, value);


        /// Register CTRL_REG4: bits OMZ1, OMZ0
        value = 0;

        /// READ
        !this->read_i2c_byte_data(pi, handle, (unsigned)LIS_Reg::CTRL_REG4, value);

        /// SET BITS
        mask = 0b11 << 2;
        value = (value & (~mask)) | ((unsigned)operating << 2);

        /// WRITE
        this->write_i2c_byte_data(pi, handle, (unsigned)LIS_Reg::CTRL_REG4, value);
    }

    void LIS3MDL::setSystemMode(const LIS_SystemMode system)
    {
        /// Register CTRL_REG3: bits MD1, MD0
        int value = 0;

        /// READ
        !this->read_i2c_byte_data(pi, handle, (unsigned)LIS_Reg::CTRL_REG3, value);

        /// SET BITS
        int mask = 0b11 << 0;
        value = (value & (~mask)) | ((unsigned)system << 0);

        /// WRITE
        this->write_i2c_byte_data(pi, handle, (unsigned)LIS_Reg::CTRL_REG3, value);
    }

    void LIS3MDL::setFullScale(const LIS_FullScale scale)
    {
        int value = 0;

        /// READ
        !this->read_i2c_byte_data(pi, handle, (unsigned)LIS_Reg::CTRL_REG2, value);

        /// SET BITS
        int mask = 0b11 << 5;
        value = (value & (~mask)) | ((unsigned)scale << 5);

        /// WRITE
        this->write_i2c_byte_data(pi, handle, (unsigned)LIS_Reg::CTRL_REG2, value);
    }

    void LIS3MDL::setFastRead(const bool enable)
    {
        fastRead = enable;

        int value = 0;

        /// READ
        !this->read_i2c_byte_data(pi, handle, (unsigned)LIS_Reg::CTRL_REG5, value);

        /// SET BIT
        if (enable)
        {
            value |= 1 << 7;
        }
        else
        {
            value &= ~(1 << 7);
        }

        /// WRITE
        this->write_i2c_byte_data(pi, handle, (unsigned)LIS_Reg::CTRL_REG5, value);
    }

    void LIS3MDL::setBlockDataUpdate(const bool enable)
    {
        int value = 0;

        /// READ
        !this->read_i2c_byte_data(pi, handle, (unsigned)LIS_Reg::CTRL_REG5, value);

        /// SET BIT
        if (enable)
        {
            value |= 1 << 6;
        }
        else
        {
            value &= ~(1 << 6);
        }

        /// WRITE
        this->write_i2c_byte_data(pi, handle, (unsigned)LIS_Reg::CTRL_REG5, value);
    }

    void LIS3MDL::setTempSensor(const bool enable)
    {
        int value = 0;

        /// READ
        !this->read_i2c_byte_data(pi, handle, (unsigned)LIS_Reg::CTRL_REG1, value);

        /// SET BIT
        if (enable)
        {
            value |= 1 << 7;
        }
        else
        {
            value &= ~(1 << 7);
        }

        /// WRITE
        this->write_i2c_byte_data(pi, handle, (unsigned)LIS_Reg::CTRL_REG1, value);
    }

    void LIS3MDL::getRegConfig()
    {
        int value = 0;

        !this->read_i2c_byte_data(pi, handle, (unsigned)LIS_Reg::CTRL_REG1, value);
        std::cout << "LIS REG 1: " << std::bitset<8>(value) << std::endl;

        !this->read_i2c_byte_data(pi, handle, (unsigned)LIS_Reg::CTRL_REG2, value);
        std::cout << "LIS REG 2: " << std::bitset<8>(value) << std::endl;

        !this->read_i2c_byte_data(pi, handle, (unsigned)LIS_Reg::CTRL_REG3, value);
        std::cout << "LIS REG 3: " << std::bitset<8>(value) << std::endl;

        !this->read_i2c_byte_data(pi, handle, (unsigned)LIS_Reg::CTRL_REG4, value);
        std::cout << "LIS REG 4: " << std::bitset<8>(value) << std::endl;

        !this->read_i2c_byte_data(pi, handle, (unsigned)LIS_Reg::CTRL_REG5, value);
        std::cout << "LIS REG 5: " << std::bitset<8>(value) << std::endl;
    }

/////////////////////////////////////////////////////////////////////////////
//                          LIS3MDL Data Reads                            //
/////////////////////////////////////////////////////////////////////////////

    ///
    /// @brief Reads all datas from registers
    ///
    /// @return True if successful reads. False otherwise.
    ///
    std::vector<double> LIS3MDL::getAxes()
    {
        if (!this->read_i2c_block_data(pi, handle, (unsigned)LIS_Reg::OUT_X_L, data, 6))
        {
            //return false;
        }

        this->axes[0] = static_cast<double>((data[1] << 8) | data[0]) / 65535.0;
        this->axes[1] = static_cast<double>((data[3] << 8) | data[2]) / 65535.0;
        this->axes[2] = static_cast<double>((data[5] << 8) | data[4]) / 65535.0;
        
        return axes;
    }

    ///
    /// @brief Reads axe
    ///
    double LIS3MDL::getAxe(const LIS_Axes axes)
    {
        switch (axes)
        {
        case LIS_Axes::X:
        {
            if (fastRead)
            {
                if (!this->read_i2c_byte_data(pi, handle, (unsigned)LIS_Reg::OUT_X_H, axe))
                {
                    return 0.0;
                }
                return static_cast<double>(axe) / 255.0;
            }
            else
            {
                if (!this->read_i2c_word_data(pi, handle, (unsigned)LIS_Reg::OUT_X_L, axe))
                {
                    return 0.0;
                }
                return static_cast<double>(axe) / 65535.0;
            }
        }
            break;
        case LIS_Axes::Y:
        {
            if (fastRead)
            {
                if (!this->read_i2c_byte_data(pi, handle, (unsigned)LIS_Reg::OUT_Y_H, axe))
                {
                    return 0.0;
                }
                return static_cast<double>(axe) / 255.0;
            }
            else
            {
                if (!this->read_i2c_word_data(pi, handle, (unsigned)LIS_Reg::OUT_Y_L, axe))
                {
                    return 0.0;
                }
                return static_cast<double>(axe) / 65535.0;
            }
        }
            break;
        case LIS_Axes::Z:
        {
            if (fastRead)
            {
                if (!this->read_i2c_byte_data(pi, handle, (unsigned)LIS_Reg::OUT_Z_H, axe))
                {
                    return 0.0;
                }
                return static_cast<double>(axe) / 255.0;

            }
            else
            {
                if (!this->read_i2c_word_data(pi, handle, (unsigned)LIS_Reg::OUT_Z_L, axe))
                {
                    return 0.0;
                }

                //std::cout << "LIS Z-Axe: " << axe << std::endl;

                return static_cast<double>(axe) / 65535.0;
            }
        }
            break;
        default:
            break;
        }

        return 0.0;
    }


/////////////////////////////////////////////////////////////////////////////
//                                                                         //
/////////////////////////////////////////////////////////////////////////////

    ///
    /// @brief Reads status from register STATUS
    ///
    /// @return Status if the device has a value.
    ///
    bool LIS3MDL::getStatus(const LIS_Status status)
    {
        int value = 0;

        if (!this->read_i2c_byte_data(pi, handle, (unsigned)LIS_Reg::STATUS, value))
        {
            return false;
        }

        //std::cout << "LIS Status: " << std::bitset<8>(value) << std::endl;

        if ((value & (int)status))
        {
            return true;
        }

        return false;
    }

    ///
    /// @brief Reads datas from registers DATA
    ///
    /// @return True if successful reads. False otherwise.
    ///
    bool LIS3MDL::getPulse(const LIS_Axes axes, const LIS_Status status)
    {
        if (getStatus(status))
        {
            switch (axes)
            {
            case LIS_Axes::X:
            case LIS_Axes::Y:
            case LIS_Axes::Z:
            {
                bool tmp = static_cast<bool>(round(getAxe(axes)));

                if (tmp != pulse)
                {
                    pulse = tmp;
                    return true;
                }
                return false;
            }
                break;
            case LIS_Axes::ZYX:
            {
                return false;
            }
                break;
            default:
                break;
            }
        }

        return false;
    }

} /// SENTENZ
