#include "DOF9.hpp"

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

namespace Sentenz
{

/////////////////////////////////////////////////////////////////////////////
//                                   DOF9                                  //
/////////////////////////////////////////////////////////////////////////////

    DOF9::DOF9(char *host, char *port) : optHost(host), optPort(port)
    {
        pi = pigpio_start(optHost, optPort);

        if (pi < 0)
        {
            throw std::runtime_error("warning: DOF9 pigpio_if2 start failed!");
        }

        open();
        init();
    }

    DOF9::~DOF9()
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
    void DOF9::open()
    {
        handleAccel = i2c_open(pi, 1, 0x53, 0);
        handleMagnet = i2c_open(pi, 1, 0x1E, 0);
        handleGyro = i2c_open(pi, 1, 0x68, 0);
    }

    ///
    /// @brief Close I2C device
    ///
    void DOF9::close()
    {
        if (handleAccel >= 0)
            i2c_close(pi, handleAccel);
        if (handleMagnet >= 0)
            i2c_close(pi, handleMagnet);
        if (handleGyro >= 0)
            i2c_close(pi, handleGyro);
    }

/////////////////////////////////////////////////////////////////////////////
//                              Configuration                              //
/////////////////////////////////////////////////////////////////////////////

    ///
    /// @brief Initialize accelerometer, magnetometer and gyroscope
    ///
    void DOF9::init()
    {
        /// Power register
        this->write_byte_data(pi, handleAccel, 0x2D, 0x08); // Measurement mode
        /// Data format register
        this->write_byte_data(pi, handleAccel, 0x31, 0x08); // Set to full resolution
        /// Rate
        this->write_byte_data(pi, handleAccel, 0x2C, 0x0A); // Set to 100Hz

        /// Mode register
        this->write_byte_data(pi, handleMagnet, 0x02, 0x00); // Set continuous mode
        /// Configuration A register
        this->write_byte_data(pi, handleMagnet, 0x00, 0x18); // Set to 75Hz

        /// Power Management
        this->write_byte_data(pi, handleGyro, 0x3E, 0x80); // Reset defaults
        /// Full-Scale range / Set LP filter bandwidth to 48Hz
        this->write_byte_data(pi, handleGyro, 0x16, 0x1B); // FS_SEL = 3, DLPF_CFG = 2
        /// Set sample rato to 50Hz
        this->write_byte_data(pi, handleGyro, 0x15, 0x0C); // SMPLRT_DIV = 12 (77Hz)
        /// Power Management
        this->write_byte_data(pi, handleGyro, 0x3E, 0x00);
    }

    ///
    /// @brief Initialize accelerometer, magnetometer and gyroscope
    ///
    void DOF9::read()
    {
        this->read_i2c_block_data(pi, handleAccel, 0x32, data, 6);

        accel[0] = static_cast<float>((data[3] << 8) | data[2]) / 65535.0f;  // X axis (internal sensor y axis)
        accel[1] = static_cast<float>((data[1] << 8) | data[0]) / 65535.0f;  // Y axis (internal sensor x axis)
        accel[2] = static_cast<float>((data[5] << 8) | data[4]) / 65535.0f;  // Z axis (internal sensor z axis)

        this->read_i2c_block_data(pi, handleMagnet, 0x03, data, 6);

        magnet[0] = -1.0 * static_cast<float>((data[0] << 8) | data[1]) / 65535.0f;  // X axis (internal sensor -x axis)
        magnet[1] = -1.0 * static_cast<float>((data[4] << 8) | data[5]) / 65535.0f;  // Y axis (internal sensor -y axis)
        magnet[2] = -1.0 * static_cast<float>((data[2] << 8) | data[3]) / 65535.0f;  // Z axis (internal sensor -z axis)

        this->read_i2c_block_data(pi, handleGyro, 0x1D, data, 6);

        gyro[0] = -1.0 * static_cast<float>((data[2] << 8) | data[3]) / 65535.0f;    // X axis (internal sensor -y axis)
        gyro[1] = -1.0 * static_cast<float>((data[0] << 8) | data[1]) / 65535.0f;    // Y axis (internal sensor -x axis)
        gyro[2] = -1.0 * static_cast<float>((data[4] << 8) | data[5]) / 65535.0f;    // Z axis (internal sensor -z axis)
    }

    ///
    /// @brief Reads status from register STATUS
    ///
    bool DOF9::status()
    {
        int statAcc = 0;
        int statMag = 0;
        int statGyr = 0;

        this->read_byte_data(pi, handleAccel, 0x39, statAcc);
        this->read_byte_data(pi, handleMagnet, 0x09, statMag);
        this->read_byte_data(pi, handleGyro, 0x1A, statGyr);

        if ((statMag & 0x01) && (statGyr & 0x01))
        {
            read();
            return true;
        }

        return false;
    }

} /// SENTENZ
