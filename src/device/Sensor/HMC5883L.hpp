/*
 * Version 1.02
 *
 */

#ifndef HMC5883L_HPP
#define HMC5883L_HPP

#include <iostream>
#include <vector>
#include <string>
#include <stdint.h>

#include "../GPIO/GPIOif2.hpp"


namespace Sentenz
{

/// Register addresses
constexpr unsigned HMC5883L_REG_CONFIG_A    = 0x00;	// Configuration
constexpr unsigned HMC5883L_REG_CONFIG_B    = 0x01;	// Configuration
constexpr unsigned HMC5883L_REG_MODE        = 0x02;	// Mode
constexpr unsigned HMC5883L_REG_DATA        = 0x03;	// Data 03h-08h
constexpr unsigned HMC5883L_REG_DATA_X      = 0x03;	// Data 03h-04h
constexpr unsigned HMC5883L_REG_DATA_Z      = 0x05;	// Data 05h-06h
constexpr unsigned HMC5883L_REG_DATA_Y      = 0x07;	// Data 07h-08h
constexpr unsigned HMC5883L_REG_STATUS      = 0x09;	// Status
constexpr unsigned HMC5883L_REG_IDENT_A     = 0x0A;	// Identification
constexpr unsigned HMC5883L_REG_IDENT_B     = 0x0B;	// Identification
constexpr unsigned HMC5883L_REG_IDENT_C     = 0x0C;	// Identification


///
/// Measurement Mode
///
/// normel = 0 (default), pos bais = 1, neg bais = 2
///
enum HMC_BAIS {
    Normal    = 0b00,
    Positive  = 0b01,
    Negative  = 0b10
};

///
/// Data Rate
///
enum HMC_RATE {
    Hz0_75  = 0b000,
    Hz1_5   = 0b001,
    Hz3     = 0b010,
    Hz7_5   = 0b011,
    Hz15    = 0b100,
    Hz30    = 0b101,
    Hz75    = 0b110
};

///
/// Averaged Measurement
///
enum HMC_AVERAGE {
    One    = 0b00,
    Two    = 0b01,
    Four   = 0b10,
    Eight  = 0b11
};

///
/// Gain
///
enum HMC_GAIN {
    G1370  = 0b000,
    G1090  = 0b001,
    G820   = 0b010,
    G660   = 0b011,
    G440   = 0b100,
    G390   = 0b101,
    G330   = 0b110,
    G220   = 0b111
};

///
/// Operating Mode 
///
/// continuous = 0, single = 1 (default)
///
enum HMC_MODE {
    Continuous  = 0b00,
    Single      = 0b01,
    IDLE        = 0b10
};


/////////////////////////////////////////////////////////////////////////////
//			    Magnetometer HMC5883L                          //
/////////////////////////////////////////////////////////////////////////////

    class HMC5883L : protected GPIOif2
    {
    public:
        HMC5883L(char *host = NULL, char *port = const_cast<char*>("8888"));
        ~HMC5883L();
        //const HMC5883L& operator=(const HMC5883L&) = delete;

        /// Member essential
        void open();
        void close();

        /// Member REG_CONFIG_A functions
        void setSampleAverage(HMC_AVERAGE average);
        int getSampleAverage();

        void setDataRate(HMC_RATE rate);
        double getDataRate();

        void setBais(HMC_BAIS bais);
        int getBais();

        /// Member REG_CONFIG_B functions
        void setGain(HMC_GAIN gain);
        double getGain();

        /// Member REG_MODE functions
        void setMode(HMC_MODE mode);
        int getMode();

        /// Member REG_DATA functions
        bool getDatas(const std::string &str, std::vector<double> &out);

        double getX();
        double getY();
        double getZ();

        bool getPulse();

        bool isStatus();

    private:
        /// Members
        char *optHost;
        char *optPort;
        char data[6];
        int pi;
        int handle;
        double scale = 0.92;
        bool pulse;
        std::vector<double> value;
    };

} /// SENTENZ

#endif /// HMC5883L_HPP
