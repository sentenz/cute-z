#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstddef>
#include <cassert>
#include <bitset>
#include <pigpio.h>

#include "HMC5883L.hpp"

namespace Sentenz
{

/////////////////////////////////////////////////////////////////////////////
//                        HMC5883L Initialization                          //
/////////////////////////////////////////////////////////////////////////////

HMC5883L::HMC5883L()
{
    if (gpioInitialise() < 0)
    {
	throw std::runtime_error("warning: pigpio initialization failed!");
    }

    this->initHMC();
}

HMC5883L::~HMC5883L()
{
    this->resetHMC();
    gpioTerminate();
}

//
// @brief 
//
// @param[val] 
// @return True if successful write operation. False otherwise.
//
void HMC5883L::initHMC()
{
    handleHMC = i2cOpen(1, 0x1E, 0);
}

//
// @brief 
//
// @param[val] 
// @return True if successful write operation. False otherwise.
//
void HMC5883L::resetHMC()
{
    if (handleHMC)
        i2cClose(handleHMC);
}

/////////////////////////////////////////////////////////////////////////////
//                        HMC5883L Configuration                           //
/////////////////////////////////////////////////////////////////////////////

//
// @brief 
//
// @param[val] 
// @return True if successful write operation. False otherwise.
//
void HMC5883L::configHMC(int aver_, double rate_, int bais_, int gain_, int mode_)
{
    uint8_t configA = 0;

    configA |= AVERAGE.at(aver_);
    configA |= RATE.at(rate_);
    configA |= BAIS.at(bais_);
    writeByteData(handleHMC, HMC5883L_CONF_B, configA);


    uint8_t configB = 0;

    configB |= GAIN.at(gain_).first;
    writeByteData(handleHMC, HMC5883L_CONF_B, configB);

    scale = this->getGainHMC();


    uint8_t mode = 0;

    mode |= MODE.at(mode_);
    writeByteData(handleHMC, HMC5883L_MODE, mode);
}

/////////////////////////////////////////////////////////////////////////////
//                            HMC5883L Writes                              //
/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
//                             HMC5883L Reads                              //
/////////////////////////////////////////////////////////////////////////////

//
// @brief 
//
// @param[val] 
// @return True if successful write operation. False otherwise.
//
double HMC5883L::getGainHMC()
{
    int val = 0;

    readByteData(handleHMC, HMC5883L_CONF_B, val);

    return GAIN.at(val >> 5).second;
}

//
// @brief 
//
// @param[val] 
// @return True if successful write operation. False otherwise.
//
bool HMC5883L::getStatus() const
{
    return status;
}

//
// @brief 
//
// @param[val] 
// @return True if successful write operation. False otherwise.
//
bool HMC5883L::getStatusHMC()
{
    int val = 0;

    if (!readByteData(handleHMC, HMC5883L_Status, val))
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
// @brief 
//
// @param[val] 
// @return True if successful write operation. False otherwise.
//
bool HMC5883L::getDataHMC(const char *axes)
{
    assert(sizeof axes == 2 || sizeof axes > 3);

    if (!this->getStatusHMC())
    {
        status = false;
        return false;
    }
    status = true;

    if (strcmp(axes, "xyz") == 0)
    {
        int count = 6;
        char data[count];

        if (!readBlockData(handleHMC, HMC5883L_DATA, data, count))
        {
            return false;
        }

        int XRaw = (data[0] << 8) | data[1];
        int ZRaw = (data[2] << 8) | data[3];
        int YRaw = (data[4] << 8) | data[5];

        XAxis = static_cast<double>(XRaw) / 32767.0 * scale;
        ZAxis = static_cast<double>(ZRaw) / 32767.0 * scale;
        YAxis = static_cast<double>(YRaw) / 32767.0 * scale;
    }
    else
    {
        int count = 2;
        char data[count];

        if (!readBlockData(handleHMC, HMC5883L_DATA + CHANNEL.at(*axes), data, count))
        {
            return false;
        }

        int Raw = (data[0] << 8) | data[1];

        Axis = static_cast<double>(Raw) / 32767.0 * scale;
    }

    return true;
}

//
// @brief 
//
// @param[val] 
// @return True if successful write operation. False otherwise.
//
double HMC5883L::getAxis() const
{
    return Axis;
}

double HMC5883L::getX() const
{
    return XAxis;
}

double HMC5883L::getZ() const
{
    return ZAxis;
}

double HMC5883L::getY() const
{
    return YAxis;
}

} /// SENTENZ
