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

        axes.resize(3, 0.0);
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
        handle = i2c_open(pi, 1, (unsigned)LISi2c::SA1_HIGH, 0);
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

    void LIS3MDL::setScale(const LISscale scale)
    {
        int value = 0;

        !this->read_byte_data(pi, handle, (unsigned)LISreg::CTRL_2, value);

        int mask = 0b11 << 5;
        value = (value & (~mask)) | ((unsigned)scale << 5);

        this->write_byte_data(pi, handle, (unsigned)LISreg::CTRL_2, value);
    }

    void LIS3MDL::setDataRate(const LISdataRate dataRate)
    {
        int value = 0;

        !this->read_byte_data(pi, handle, (unsigned)LISreg::CTRL_1, value);

        int mask = 0b1111 << 1;
        value = (value & (~mask)) | ((unsigned)dataRate << 1);

        this->write_byte_data(pi, handle, (unsigned)LISreg::CTRL_1, value);

        switch (dataRate)
        {
        case LISdataRate::Hz155:
            setPerformance(LISperformance::UP);
            break;
        case LISdataRate::Hz300:
            setPerformance(LISperformance::HP);
            break;
        case LISdataRate::Hz560:
            setPerformance(LISperformance::MP);
            break;
        case LISdataRate::Hz1000:
            setPerformance(LISperformance::LP);
            break;
        default:
            break;
        }

        setMeasurement(LISmeasurement::Continuous);
    }

    void LIS3MDL::setPerformance(const LISperformance performance)
    {
        // Register CTRL_REG1: bits OM1, OM0
        int value = 0;

        !this->read_byte_data(pi, handle, (unsigned)LISreg::CTRL_1, value);

        int mask = 0b11 << 5;
        value = (value & (~mask)) | ((unsigned)performance << 5);

        this->write_byte_data(pi, handle, (unsigned)LISreg::CTRL_1, value);


        // Register CTRL_REG4: bits OMZ1, OMZ0
        value = 0;

        !this->read_byte_data(pi, handle, (unsigned)LISreg::CTRL_4, value);

        mask = 0b11 << 2;
        value = (value & (~mask)) | ((unsigned)performance << 2);

        this->write_byte_data(pi, handle, (unsigned)LISreg::CTRL_4, value);
    }

    void LIS3MDL::setMeasurement(const LISmeasurement measurement)
    {
        // Register CTRL_REG3: bits MD1, MD0
        int value = 0;

        !this->read_byte_data(pi, handle, (unsigned)LISreg::CTRL_3, value);

        int mask = 0b11 << 0;
        value = (value & (~mask)) | ((unsigned)measurement << 0);

        this->write_byte_data(pi, handle, (unsigned)LISreg::CTRL_3, value);
    }

    void LIS3MDL::setFastRead(const bool enable)
    {
        fastRead = enable;

        int value = 0;

        !this->read_byte_data(pi, handle, (unsigned)LISreg::CTRL_5, value);

        if (enable)
        {
            value |= 1 << 7;
        }
        else
        {
            value &= ~(1 << 7);
        }

        this->write_byte_data(pi, handle, (unsigned)LISreg::CTRL_5, value);
    }

    void LIS3MDL::setTempSensor(const bool enable)
    {
        int value = 0;

        !this->read_byte_data(pi, handle, (unsigned)LISreg::CTRL_1, value);

        if (enable)
        {
            value |= 1 << 7;
        }
        else
        {
            value &= ~(1 << 7);
        }

        this->write_byte_data(pi, handle, (unsigned)LISreg::CTRL_1, value);
    }

    void LIS3MDL::getConfig()
    {
        int value = 0;

        !this->read_byte_data(pi, handle, (unsigned)LISreg::CTRL_1, value);
        std::cout << "LIS REG 1: " << std::bitset<8>(value) << std::endl;

        !this->read_byte_data(pi, handle, (unsigned)LISreg::CTRL_2, value);
        std::cout << "LIS REG 2: " << std::bitset<8>(value) << std::endl;

        !this->read_byte_data(pi, handle, (unsigned)LISreg::CTRL_3, value);
        std::cout << "LIS REG 3: " << std::bitset<8>(value) << std::endl;

        !this->read_byte_data(pi, handle, (unsigned)LISreg::CTRL_4, value);
        std::cout << "LIS REG 4: " << std::bitset<8>(value) << std::endl;

        !this->read_byte_data(pi, handle, (unsigned)LISreg::CTRL_5, value);
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
        if (!this->read_i2c_block_data(pi, handle, (unsigned)LISreg::OUT_X_L, data, 6))
        {
            //return false;
        }

        axes[0] = static_cast<double>((data[1] << 8) | data[0]) / 65535.0;
        axes[1] = static_cast<double>((data[3] << 8) | data[2]) / 65535.0;
        axes[2] = static_cast<double>((data[5] << 8) | data[4]) / 65535.0;
        
        return axes;
    }

    ///
    /// @brief Reads axe
    ///
    double LIS3MDL::getAxe(const LISaxes axes)
    {
        switch (axes)
        {
        case LISaxes::X:
        {
            if (fastRead)
            {
                if (!this->read_byte_data(pi, handle, (unsigned)LISreg::OUT_X_H, axe))
                {
                    return 0.0;
                }
                return static_cast<double>(axe) / 255.0;
            }
            else
            {
                if (!this->read_word_data(pi, handle, (unsigned)LISreg::OUT_X_L, axe))
                {
                    return 0.0;
                }
                return static_cast<double>(axe) / 65535.0;
            }
        }
            break;
        case LISaxes::Y:
        {
            if (fastRead)
            {
                if (!this->read_byte_data(pi, handle, (unsigned)LISreg::OUT_Y_H, axe))
                {
                    return 0.0;
                }
                return static_cast<double>(axe) / 255.0;
            }
            else
            {
                if (!this->read_word_data(pi, handle, (unsigned)LISreg::OUT_Y_L, axe))
                {
                    return 0.0;
                }
                return static_cast<double>(axe) / 65535.0;
            }
        }
            break;
        case LISaxes::Z:
        {
            if (fastRead)
            {
                if (!this->read_byte_data(pi, handle, (unsigned)LISreg::OUT_Z_H, axe))
                {
                    return 0.0;
                }
                return static_cast<double>(axe) / 255.0;

            }
            else
            {
                if (!this->read_word_data(pi, handle, (unsigned)LISreg::OUT_Z_L, axe))
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
    bool LIS3MDL::getStatus(const LISstatus status)
    {
        int value = 0;

        if (!this->read_byte_data(pi, handle, (unsigned)LISreg::STATUS, value))
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
    bool LIS3MDL::getPulse(const LISaxes axes, const LISstatus status)
    {
        if (getStatus(status))
        {
            switch (axes)
            {
            case LISaxes::X:
            case LISaxes::Y:
            case LISaxes::Z:
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
            case LISaxes::ZYX:
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
