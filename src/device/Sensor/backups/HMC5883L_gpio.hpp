/*
 * Version 1.00
 *
 */

#ifndef HMC5883L_HPP
#define HMC5883L_HPP

#include <iostream>
#include <vector>
#include <map>
#include <utility>

#include "../GPIO.hpp"

namespace Sentenz
{

/// Register addresses
constexpr int HMC5883L_CONF_A = 0x00;	// Configuration A
constexpr int HMC5883L_CONF_B = 0x01;	// Configuration B
constexpr int HMC5883L_MODE   = 0x02;	// Mode
constexpr int HMC5883L_DATA   = 0x03;	// Data Output 03h-08h
constexpr int HMC5883L_Status = 0x09;	// Status

/// Channels for additional register
const std::map<char, uint8_t> CHANNEL = {
    {'x', 0},
    {'z', 2},
    {'y', 4}
};

/// Measurement Mode (normel measurement = 0 (default); pos bais = 1; neg bais = 2;)
const std::map<int, uint8_t> BAIS = {
    {0, 0},
    {1, 1},
    {2, 2}
};

/// Data Output Rate / Hz (0.75 to 75.0)
const std::map<double, uint8_t> RATE = {
    {0.75, 0 << 2},
    {1.50, 1 << 2},
    {3.00, 2 << 2},
    {7.50, 3 << 2},
    {15.0, 4 << 2},
    {30.0, 5 << 2},
    {75.0, 6 << 2}
};

/// Averaged Measurement Output (1 to 8)
const std::map<int, uint8_t> AVERAGE = {
    {1, 0 << 5},
    {2, 1 << 5},
    {4, 2 << 5},
    {8, 3 << 5}
};

// Gain Configuration (0 to 7)
const std::vector<std::pair<int, double>> GAIN = {
    {0 << 5, 0.73},
    {1 << 5, 0.92},
    {2 << 5, 1.22},
    {3 << 5, 1.52},
    {4 << 5, 2.27},
    {5 << 5, 2.56},
    {6 << 5, 3.03},
    {7 << 5, 4.35}
};

// Operating Mode (continuous = 0; single = 1 (default);)
const std::map<int, uint8_t> MODE = {
    {0, 0},
    {1, 1}
};

/////////////////////////////////////////////////////////////////////////////
//			    Magnetometer HMC5883L                          //
/////////////////////////////////////////////////////////////////////////////

class HMC5883L : protected GPIO
{
public:
    HMC5883L();
    ~HMC5883L();

    // Member functions
    void initHMC();
    void resetHMC();

    void configHMC(int aver_, double rate_, int bais_, int gain_, int mode_);

    bool getDataHMC(const char *axes);
    double getAxis() const;
    double getX() const;
    double getZ() const;
    double getY() const;

    bool getStatus() const;

private:
    // Member functions
    double getGainHMC();
    bool getStatusHMC();

    // Members
    int handleHMC = 0;
    double scale = 0.0;
    double Axis = 0.0;
    double XAxis = 0.0;
    double ZAxis = 0.0;
    double YAxis = 0.0;
    bool status = false;
};

} /// SENTENZ

#endif /// HMC5883L_HPP