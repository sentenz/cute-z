#ifndef GPIO_HPP
#define GPIO_HPP

#include <iostream>

namespace Sentenz
{

/////////////////////////////////////////////////////////////////////////////
//				    GPIO                                   //
/////////////////////////////////////////////////////////////////////////////

    class GPIO
    {
    public:
        GPIO();
        virtual ~GPIO();
        const GPIO& operator=(const GPIO&) = delete;


    protected:
        /// Member I2C reads and writes
        bool writeByte(int handle, int in);
        bool writeByteData(int handle, int reg, int in);
        bool writeWordData(int handle, int reg, int in);
        bool writeBlockData(int handle, int reg, int in, int count);
        bool writeDevice(unsigned handle, char *buf, unsigned count);

        bool readByte(int handle, int &out);
        bool readByteData(int handle, int reg, int &out);
        bool readWordData(int handle, int reg, int &out);
        bool readBlockData(int handle, int reg, char *buf, int count);
        bool readDevice(int handle, char *buf, int count);

        /// Member PWM
        bool configPWM(int pin, int frequency, int value);

        /// Member Input
        bool readInput(unsigned pin);

    private:
        //void wait(int &val);
    };

} /// SENTENZ

#endif /// GPIO_HPP
