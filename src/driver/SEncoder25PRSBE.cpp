#include "SEncoder25PRSBE.h"

#include <sys/select.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/types.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <math.h> // fabs()

#include <QDebug>

SEncoder25PRSBE::SEncoder25PRSBE()
{
}

SEncoder25PRSBE::~SEncoder25PRSBE()
{
    /// SPI destructor
    close(fd);
}

///
/// @brief Initialize Encoder.
///
/// @return 0 if successful write operation. -1 otherwise.
///
bool SEncoder25PRSBE::init()
{
    /// SPI constructor
    this->fd = open(port, O_RDWR); // | O_NOCTTY | O_NONBLOCK

    if (this->fd < 0)
    {
        printf("Can't open /dev/spidev0.0\n");
        return false;
    }

    /// SPI config
    if (ioctl(this->fd, SPI_IOC_WR_MAX_SPEED_HZ, &this->speed) < 0)
    {
        printf("Can't set speed\n");
        return false;
    }

    if (ioctl(this->fd, SPI_IOC_WR_MODE, &this->mode) < 0)
    {
        printf("Can't set mode\n");
        return false;
    }

    if (ioctl(this->fd, SPI_IOC_WR_BITS_PER_WORD, &this->bits) < 0)
    {
        printf("Can't set bits\n");
        return false;
    }

    /// Control device
    memset(&tr, 0, sizeof(tr));
    tr.tx_buf = (unsigned long)tx;
    tr.rx_buf = (unsigned long)rx;
    tr.len = sizeof(tx);
    //tr.delay_usecs = delay;
    tr.speed_hz = speed;
    tr.bits_per_word = bits;

    return true;
}

///
/// @brief Read 14 bit from Encoder.
///
/// @return 0 if successful read operation. -1 otherwise.
///
int SEncoder25PRSBE::get(double *value)
{
    int ret = 0;

    tx[0] = 0x00;
    tx[1] = 0x00;
    tx[2] = 0xFF;
    tx[3] = 0xFF;
    tx[4] = 0x00;
    tx[5] = 0x00;
    tx[6] = 0x13;
    tx[7] = 0xEA;

    ret = ioctl(fd, SPI_IOC_MESSAGE(1), &tr);
    if (ret < 0)
    {
        printf("can't send spi message 1\n");
        return -1;
    }

    usleep(700);

    /// issue NOP message
    tx[0] = 0x00;
    tx[1] = 0x00;
    tx[2] = 0xAA;
    tx[3] = 0xAA;
    tx[4] = 0x00;
    tx[5] = 0x00;
    tx[6] = 0xD0;
    tx[7] = 0xAB;

    ret = ioctl(fd, SPI_IOC_MESSAGE(1), &tr);
    if (ret < 0)
    {
        printf("can't send spi message 2\n");
        return -1;
    }

    usleep(700);

    /// Extract and convert the angle to degrees
    this->alpha = rx[0] | (rx[1] & 0x3F) << 8;
    //this->alpha = (rx[0] & 0xF8) | (rx[1] & 0x3F) << 8;
    /// Extract the error bits
    this->error = this->rx[1] >> 6;
    /// Extract the virtual gain byte
    this->gain = this->rx[4];
    /// Extract the rolling counter
    this->counter = this->rx[6] & 0x3F;
    /// Extract the CRC
    this->crc = this->rx[7];

    if (this->crc == this->computeCRC(this->rx, sizeof(this->rx)-1))
    {
        if (this->error > 1)
        {
            this->error_counter = 0;
            this->last = this->phase;
            this->phase = static_cast<double>(this->alpha) * this->factor;

            /// Calculation
            if (this->one)
            {
                this->diff = this->phase - this->last;

                if (fabs(this->diff) > 180.0)
                {
                    if (this->last > this->phase)
                    {
                        this->diff = (this->phase + 360.0) - this->last;
                    }
                    else if (this->last < this->phase)
                    {
                        this->diff = this->phase - (this->last + 360.0);
                    }
                }
            }
            this->one = true;

            //printf("crc %d\tgain %d\tcount %2d\n", crc, gain, counter);
            //printf("error %d\tphase %2.5f\tdiff %2.5f\n", error, phase, diff);

            *value = this->diff;

            return 0;
        }
        else
        {
            if (++this->error_counter > 3)
            {
                return -2;
            }
        }
    }
    else
    {
        return -2;
    }

    return 0;
}

uint8_t SEncoder25PRSBE::computeCRC(uint8_t *byte, size_t size)
{
    uint8_t  crc = 0xFF;

    for (size_t i = 0; i < size; ++i)
    {
        crc = this->crcArray[crc ^ byte[i]];
    }
    crc = ~crc;

    return crc;
}
