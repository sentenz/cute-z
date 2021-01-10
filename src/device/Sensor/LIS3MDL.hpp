/*
 * Version 1.00
 *
 */

#ifndef LIS3MDL_HPP
#define LIS3MDL_HPP

#include <iostream>
#include <vector>
#include <string>
#include <stdint.h>

#include "../GPIO/GPIOif2.hpp"


namespace Sentenz
{

    /// I2C address
    enum class LIS_I2C
    {
        SA1_HIGH    = 0b0011110,    // 0x1E
        SA1_LOW     = 0b0011100     // 0x28
    };

    /// Register addresses
    enum class LIS_Reg
    {
        OFFSET_X_L   = 0x05,	// Offset
        OFFSET_X_H   = 0x06,	// Offset
        OFFSET_Y_L   = 0x07,	// Offset
        OFFSET_Y_H   = 0x08,	// Offset
        OFFSET_Z_L   = 0x09,	// Offset
        OFFSET_Z_H   = 0x0A,	// Offset
        WHO_AM_I     = 0x0F,	// Identification
        CTRL_REG1    = 0x20,	// Configuration
        CTRL_REG2    = 0x21,	// Configuration
        CTRL_REG3    = 0x22,	// Configuration
        CTRL_REG4    = 0x23,	// Configuration
        CTRL_REG5    = 0x24,	// Configuration
        STATUS       = 0x27,	// Status
        OUT_X_L      = 0x28,	// Data output
        OUT_X_H      = 0x29,	// Data output
        OUT_Y_L      = 0x2A,	// Data output
        OUT_Y_H      = 0x2B,	// Data output
        OUT_Z_L      = 0x2C,	// Data output
        OUT_Z_H      = 0x2D,	// Data output
        TEMP_OUT_L   = 0x2E,	// Temperatur
        TEMP_OUT_H   = 0x2F,	// Temperatur
        INT_CFG      = 0x30,	// Interrupt configuration
        INT_SRC      = 0x31,	// Interrupt source
        INT_THS_L    = 0x32,	// Interrupt threshold
        INT_THS_H    = 0x33,	// Interrupt threshold
    };

    ///
    /// @brief General configuration: Output data rate (ODR)
    ///
    /// Register CTRL_REG1; bits DO2, DO1, DO0, FAST_ODR
    ///
    enum class LIS_DataRate
    {
        mHz_625     = 0b0000,
        mHz_1250    = 0b0010,
        mHz_2500    = 0b0100,
        Hz_5        = 0b0110,
        Hz_10       = 0b1000,
        Hz_20       = 0b1010,
        Hz_40       = 0b1100,
        Hz_80       = 0b1110,
        Hz_155      = 0b0011,
        Hz_300      = 0b0101,
        Hz_560      = 0b0111,
        Hz_1000     = 0b1001
    };

    ///
    /// @brief General configuration: Operating modes
    ///
    /// Register CTRL_REG1: bits OM1, OM0
    /// Register CTRL_REG4: bits OMZ1, OMZ0
    ///
    enum class LIS_OperatingMode
    {
        LP = 0b00,
        MP = 0b01,
        HP = 0b10,
        UP = 0b11
    };

    ///
    /// @brief General configuration: Full-scale
    ///
    /// Register CTRL_REG2: bits FS1, FS0
    ///
    enum class LIS_FullScale
    {
        G4  = 0b00,
        G8  = 0b01,
        G12 = 0b10,
        G16 = 0b11
    };

    ///
    /// @brief General configuration: Measurement mode
    ///
    /// Register CTRL_REG3: bits MD1, MD0
    ///
    enum class LIS_SystemMode
    {
        Continuous  = 0b00,
        Single      = 0b01,
        PowerDown   = 0b10
    };

    ///
    /// @brief Status
    ///
    /// Register STATUS_REG; bits ZYXOR, ZOR, YOR, XOR, ZYXDA, ZDA, YDA, XDA
    ///
    enum class LIS_Status
    {
        XDA     = 1 << 0,
        YDA     = 1 << 1,
        ZDA     = 1 << 2,
        ZYXDA   = 1 << 3,
        XOR     = 1 << 4,
        YOR     = 1 << 5,
        ZOR     = 1 << 6,
        ZYXOR   = 1 << 7,
    };

    ///
    /// @brief Axis
    ///
    enum class LIS_Axes
    {
        X   = 0,
        Y   = 1,
        Z   = 2,
        ZYX = 3
    };

/////////////////////////////////////////////////////////////////////////////
//			    Magnetometer LIS3MDL                          //
/////////////////////////////////////////////////////////////////////////////

    class LIS3MDL : protected GPIOif2
    {
    public:
        LIS3MDL(char *host = NULL, char *port = const_cast<char*>("8888"));
        ~LIS3MDL();
        const LIS3MDL& operator=(const LIS3MDL&) = delete;


        /// Member essential

        ///
        /// @brief Open I2C
        ///
        void open();

        ///
        /// @brief Close I2C
        ///
        void close();


        /// Member

        ///
        /// @brief Set output data rate
        ///
        void setDataRate(const LIS_DataRate dataRate);

        ///
        /// @brief Set data rate configuration
        ///
        void setOperatingMode(const LIS_OperatingMode operating);

        ///
        /// @brief Set system operating mode selection
        ///
        void setSystemMode(const LIS_SystemMode system = LIS_SystemMode::Continuous);

        ///
        /// @brief Set Full-scale selection
        ///
        void setFullScale(const LIS_FullScale scale);

        ///
        /// @brief Allows reading the high part of DATA OUT only
        ///
        void setFastRead(const bool enable = false);

        ///
        /// @brief Output registers not updated until MSb and LSb have been read
        ///
        void setBlockDataUpdate(const bool enable = false);

        ///
        /// @brief Enable temperature sensor
        ///
        void setTempSensor(const bool enable = false);

        ///
        /// @brief Get all 5 Register configurations
        ///
        void getRegConfig();

        ///
        /// @brief Get X, Y or Z Axis
        ///
        double getAxe(const LIS_Axes axes);

        ///
        /// @brief Get all Axis
        ///
        std::vector<double> getAxes();

        ///
        /// @brief Get Axis status
        ///
        bool getStatus(const LIS_Status status);

        ///
        /// @brief Get pole change
        ///
        bool getPulse(const LIS_Axes axes, const LIS_Status status);

    private:
        /// Members
        char *optHost;
        char *optPort;
        int pi;
        int handle;

        bool fastRead = false;
        bool pulse = false;
        char data[6];
        int axe;
        std::vector<double> axes;
    };

} /// SENTENZ

#endif /// LIS3MDL_HPP
