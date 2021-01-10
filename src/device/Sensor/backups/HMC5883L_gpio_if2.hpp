/*
 * Version 1.00
 *
 */

#ifndef HMC5883L_HPP
#define HMC5883L_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

#include "../GPIO/GPIOif2.hpp"

namespace Sentenz
{

/// Register addresses
constexpr int HMC5883L_CONF_A = 0x00;	// Configuration A
constexpr int HMC5883L_CONF_B = 0x01;	// Configuration B
constexpr int HMC5883L_MODE   = 0x02;	// Mode
constexpr int HMC5883L_DATA   = 0x03;	// Data Output 03h-08h
constexpr int HMC5883L_STATUS = 0x09;	// Status

/// For single axes mode add channels register DATA
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

    class HMC5883L : protected GPIOif2
    {
    public:
        HMC5883L(char *host = NULL, char *port = "8888");
        ~HMC5883L();

        // Member essential
        void open();
        void close();

        // Member functions
        void config(int m_aver, double m_rate, int m_bais, int m_gain, int m_mode);
        bool getDatas(const std::string &str, std::vector<double> &out);
        bool getPulse(const std::string &str);
        bool isStatus();

    private:
        // Member functions
        double getGain();

        // Members
        char *optHost;
        char *optPort;
        int pi;
        int handle;
        double scale = 0.0;
        bool pulse = false;
        std::vector<double> value;
    };

} /// SENTENZ

#endif /// HMC5883L_HPP