#include <iostream>
#include <exception>
#include <stdexcept>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstddef>
#include <bitset>
#include <pigpio.h>

#include "ZX_Sensor.hpp"

namespace Sentenz
{

/////////////////////////////////////////////////////////////////////////////
//                            Initialization                               //
/////////////////////////////////////////////////////////////////////////////

ZX_Sensor::ZX_Sensor()
{
    if (gpioInitialise() < 0)
    {
	throw std::runtime_error("warning: pigpio initialization failed!");
    }

    this->initZX();
}

ZX_Sensor::~ZX_Sensor()
{
    this->resetZX();
    gpioTerminate();
}

//
// @brief 
//
// @param[val] 
// @return True if successful write operation. False otherwise.
//
void ZX_Sensor::initZX()
{
    handleZX = i2cOpen(1, 0x10, 0);
}

//
// @brief 
//
// @param[val] 
// @return True if successful write operation. False otherwise.
//
void ZX_Sensor::resetZX()
{
    if (handleZX)
        i2cClose(handleZX);
}

/////////////////////////////////////////////////////////////////////////////
//                       Interrupt Configutation                           //
/////////////////////////////////////////////////////////////////////////////

//
// @brief Configures I2C communications and checks ZX sensor model number.
//
// @param enable_interrupts enables DR pin to assert on events
// @return True if initialized successfully. False otherwise.
//
bool ZX_Sensor::configZX(Interrupt interrupts /* = NO_INTERRUPTS */, bool active_high /* = true */)
{
    // Enable DR interrupts based on desired interrupts
    setInterruptTrigger(interrupts);
    configureInterrupts(active_high, false);
    if (interrupts == Interrupt::NO_INTERRUPTS)
    {
        disableInterrupts();
    }
    else
    {
        enableInterrupts();
    }

    return true;
}

//
// @brief Reads the sensor model version
//
// @return sensor model version number
//
int ZX_Sensor::getModelVersion()
{
    int vs = 0;

    if (!readByteData(handleZX, ZX_MODEL, vs))
    {
        return ZX_ERROR;
    }

    return vs;
}

//
// @brief Reads the register map version
//
// @return register map version number
//
int ZX_Sensor::getRegMapVersion()
{
    int vs = 0;

    if ( !readByteData(handleZX, ZX_REGVER, vs))
    {
        return ZX_ERROR;
    }

    return vs;
}

/////////////////////////////////////////////////////////////////////////////
//                        Interrupt Configuration                          //
/////////////////////////////////////////////////////////////////////////////

//
// @brief Sets the triggers that cause the DR pin to change
//
// @param[in] interrupts which types of interrupts to enable
// @return True if operation successful. False otherwise.
//
bool ZX_Sensor::setInterruptTrigger(Interrupt interrupts)
{

#if DEBUG
    std::cout << "Setting interrupts: " << static_cast<Interrupt>(interrupts) << std::endl;
#endif

    switch (interrupts)
    {
        case Interrupt::POSITION_INTERRUPTS:
            if (!setRegisterBit(ZX_DRE, DRE_CRD))
	    {
                return false;
            }
            break;
        case Interrupt::GESTURE_INTERRUPTS:
            if (!setRegisterBit(ZX_DRE, DRE_SWP))
	    {
                return false;
            }
            if (!setRegisterBit(ZX_DRE, DRE_HOVER))
	    {
                return false;
            }
            if (!setRegisterBit(ZX_DRE, DRE_HVG))
	    {
                return false;
            }
            break;
        case Interrupt::ALL_INTERRUPTS:
            if (!writeByteData(handleZX, ZX_DRE, SET_ALL_DRE))
	    {
                return false;
            }
            break;
        default:
            if (!writeByteData(handleZX, ZX_DRE, 0x00))
	    {
                return false;
            }
            break;
    }

#if DEBUG
    int val;
    readByteData(handleZX, ZX_DRE, val);
    std::cout << "ZX_DRE: " << std::bitset<8>(val) << std::endl;
#endif

    return true;
}

//
// @brief Configured the behavior of the DR pin on an interrupt
//
// @param[in] active_high true for DR active-high. False for active-low.
// @param[in] pin_pulse true: DR pulse. False: DR pin asserts until STATUS read
// @return True if operation successful. False otherwise.
//
bool ZX_Sensor::configureInterrupts(bool active_high, bool pin_pulse /* = false */)
{
    // Set or clear polarity bit to make DR active-high or active-low
    if (active_high)
    {
        if (!setRegisterBit(ZX_DRCFG, DRCFG_POLARITY))
	{
            return false;
        }
    }
    else
    {
        if (!clearRegisterBit(ZX_DRCFG, DRCFG_POLARITY))
	{
            return false;
        }
    }

    // Set or clear edge bit to make DR pulse or remain set until STATUS read
    if (pin_pulse)
    {
        if (!setRegisterBit(ZX_DRCFG, DRCFG_EDGE))
	{
            return false;
        }
    }
    else
    {
        if (!clearRegisterBit(ZX_DRCFG, DRCFG_EDGE))
	{
            return false;
        }
    }

#if DEBUG
    int val;
    readByteData(handleZX, ZX_DRCFG, val);
    std::cout << "ZX_DRCFG: " << std::bitset<8>(val) << std::endl;
#endif

    return true;
}

//
// @brief Turns on interrupts so that DR asserts on desired events.
//
// @return True if operation successful. False otherwise.
//
bool ZX_Sensor::enableInterrupts()
{
    if (!setRegisterBit(ZX_DRCFG, DRCFG_EN))
    {
        return false;
    }

    return true;
}

//
// @brief Turns off interrupts so that DR will never assert.
//
// @return True if operation successful. False otherwise.
//
bool ZX_Sensor::disableInterrupts()
{
    if (!clearRegisterBit(ZX_DRCFG, DRCFG_EN))
    {
        return false;
    }

    return true;
}

//
// @brief Reads the STATUS register to clear an interrupt (de-assert DR)
//
// @return True if operation successful. False otherwise.
//
bool ZX_Sensor::clearInterrupt()
{
    int val = 0;

    if (!readByteData(handleZX, ZX_STATUS, val))
    {
        return false;
    }

    return true;
}

/////////////////////////////////////////////////////////////////////////////
//                           Bit Manipulation                              //
/////////////////////////////////////////////////////////////////////////////

//
// @brief sets a bit in a register over I2C
//
// @param[in] bit the number of the bit (0-7) to set
// @return True if successful write operation. False otherwise.
//
bool ZX_Sensor::setRegisterBit(int reg, int bit)
{
    int val = 0;

    // Read value from register
    if (!readByteData(handleZX, reg, val))
    {
        return false;
    }

    // Set bits in register and write back to the register
    val |= (1 << bit);
    if (!writeByteData(handleZX, reg, val))
    {
        return false;
    }

    return true;
}

//
// @brief clears a bit in a register over I2C
//
// @param[in] bit the number of the bit (0-7) to clear
// @return True if successful write operation. False otherwise.
//
bool ZX_Sensor::clearRegisterBit(int reg, int bit)
{
    int val = 0;

    // Read value from register
    if (!readByteData(handleZX, reg, val))
    {
        return false;
    }

    // Clear bit in register and write back to the register
    val &= ~(1 << bit);
    if (!writeByteData(handleZX, reg, val))
    {
        return false;
    }

    return true;
}

/////////////////////////////////////////////////////////////////////////////
//                             Data available                              //
/////////////////////////////////////////////////////////////////////////////

//
// @brief Indicates that new position (X or Z) data is available
//
// @return True if data is ready to be read. False otherwise.
//
bool ZX_Sensor::statusAvailable(int &val)
{
    // Read STATUS register and extract DAV bit
    if (!readByteData(handleZX, ZX_STATUS, status))
    {
        return false;
    }

    status &= 0b00011101;
    if (status)
    {
        val = status;
        return true;
    }

    return false;
}

/////////////////////////////////////////////////////////////////////////////
//                            Sensor data read                             //
/////////////////////////////////////////////////////////////////////////////

//
// @brief Reads the X position data from the sensor
// @return 0-240 for X position. 0xFF on read error.
//
bool ZX_Sensor::readX(int &val)
{
    // Read X Position register and return it
    if (!readByteData(handleZX, ZX_XPOS, val))
    {
        return false;
    }
    if (val > MAX_RNG)
    {
        return false;
    }

    return true;
}

//
// @brief Reads the Z position data from the sensor
//
// @return 0-240 for Z position. 0xFF on read error.
//
bool ZX_Sensor::readZ(int &val)
{
    // Read X Position register and return it
    if (!readByteData(handleZX, ZX_ZPOS, val))
    {
        return false;
    }
    if (val > MAX_RNG)
    {
        return false;
    }

    return true;
}

//
// @brief Reads the last detected gesture from the sensor
//
// 0x01 Right Swipe
// 0x02 Left Swipe
// 0x03 Up Swipe
//
// @return a number corresponding to  a gesture. 0xFF on error.
//
bool ZX_Sensor::readGesture(Gesture &gesture)
{
    int val = 0;

    // Read GESTURE register and return the value
    if (!readByteData(handleZX, ZX_GESTURE, val))
    {
	gesture = Gesture::NO_GESTURE;
        return false;
    }

#if DEBUG
    std::cout << "Gesture read: 0b" << std::bitset<8>(val) << std::endl;
#endif

    switch (static_cast<Gesture>(val))
    {
        case Gesture::RIGHT_SWIPE:
            gesture = Gesture::RIGHT_SWIPE;
	    break;
        case Gesture::LEFT_SWIPE:
            gesture = Gesture::LEFT_SWIPE;
	    break;
        case Gesture::UP_SWIPE:
            gesture = Gesture::UP_SWIPE;
	    break;
        default:
            gesture = Gesture::NO_GESTURE;
    }

    return true;
}

//
// @brief Reads the speed of the last gesture from the sensor
//
// @return a number corresponding to the speed of the gesture. 0xFF on error.
//
bool ZX_Sensor::readGestureSpeed(int &val)
{
    // Read GESTURE register and return the value
    if (!readByteData(handleZX, ZX_GSPEED, val))
    {
        return false;
    }

    return true;
}

} /// SENTENZ