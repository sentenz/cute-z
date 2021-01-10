#ifndef ZX_SENSOR_HPP
#define ZX_SENSOR_HPP

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstddef>

#include "../GPIO/GPIO.hpp"

namespace Sentenz
{

// Debug
#define DEBUG               0

// Acceptable ZX Sensor version
#define ZX_MODEL_VER        0x01

// Acceptable ZX Sensor register map
#define ZX_REG_MAP_VER      0x01

// ZX Sensor register addresses
#define ZX_STATUS           0x00
#define ZX_DRE              0x01
#define ZX_DRCFG            0x02
#define ZX_GESTURE          0x04
#define ZX_GSPEED           0x05
#define ZX_DCM              0x06
#define ZX_XPOS             0x08
#define ZX_ZPOS             0x0A
#define ZX_LRNG             0x0C
#define ZX_RRNG             0x0E
#define ZX_REGVER           0xFE
#define ZX_MODEL            0xFF

// ZX Sensor bit names
#define DRE_RNG             0
#define DRE_CRD             1
#define DRE_SWP             2
#define DRE_HOVER           3
#define DRE_HVG             4
#define DRE_EDGE            5
#define DRCFG_POLARITY      0
#define DRCFG_EDGE          1
#define DRCFG_FORCE         6
#define DRCFG_EN            7

// ZX Sensor UART message headers
#define ZX_UART_END         0xFF
#define ZX_UART_RANGES      0xFE
#define ZX_UART_X           0xFA
#define ZX_UART_Z           0xFB
#define ZX_UART_GESTURE     0xFC
#define ZX_UART_ID          0xF1

// Constants
#define ZX_ERROR            0xFF
#define MAX_RNG		    240
#define SET_ALL_DRE         0b00111111

//Enumeration for possible gestures
enum class Gesture
{
    RIGHT_SWIPE		    = 0x01,
    LEFT_SWIPE		    = 0x02,
    UP_SWIPE		    = 0x03,
    NO_GESTURE		    = 0xFF
};

// Enumeration for possible interrupt enables
enum class Interrupt
{
    NO_INTERRUPTS	    = 0x00,
    POSITION_INTERRUPTS	    = 0x01,
    GESTURE_INTERRUPTS	    = 0x02,
    ALL_INTERRUPTS	    = 0x03
};

/// ZX Sensor Status
#define GESTURE		    0b00001100
#define POSITION	    0b00000001


class ZX_Sensor : protected GPIO
{
public:
    ZX_Sensor();
    ~ZX_Sensor();

    // Initialise
    void initZX();
    void resetZX();

    bool configZX(Interrupt interrupts = Interrupt::NO_INTERRUPTS, bool active_high = true);
    int getModelVersion();
    int getRegMapVersion();
    
    // Interrupt configuration
    bool setInterruptTrigger(Interrupt interrupts);
    bool configureInterrupts(bool active_high, bool pin_pulse = false);
    bool enableInterrupts();
    bool disableInterrupts();
    bool clearInterrupt();
    
    // Data available
    bool statusAvailable(int &val);
    
    // Sensor data read
    bool readX(int &val);
    bool readZ(int &val);
    bool readGesture(Gesture &gesture);
    bool readGestureSpeed(int &val);
   
private:
    // Bit manipulation
    bool setRegisterBit(int reg, int bit);
    bool clearRegisterBit(int reg, int bit);
 
    // Members
    int handleZX = 0;
    int status = 0;
};

} /// SENTENZ

#endif /// ZX_SENSOR_HPP