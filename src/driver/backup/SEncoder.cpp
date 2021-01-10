#include "SEncoder.h"

#include <math.h> // fabs()
#include <unistd.h>

#include <QDebug>

SEncoder::SEncoder()
{
}

SEncoder::~SEncoder()
{
    /// SPI destructor
    spi_close(this->fd);
}

///
/// @brief Initialize Encoder.
///
/// @return 0 if successful write operation. -1 otherwise.
///
bool SEncoder::init()
{
    /// SPI constructor
    this->fd = spi_open(port);

    if (this->fd == INVALID_SPI_PORT)
    {
        printf("Can't open /dev/spidev0.0\n");
        return false;
    }

    /// SPI config
    if (spi_set_speed(this->fd, this->speed) == INVALID_SPI_COM)
    {
        printf("Can't set speed\n");
        return false;
    }

    if (spi_set_mode(this->fd, this->mode) == INVALID_SPI_COM)
    {
        printf("Can't set mode\n");
        return false;
    }

    if (spi_set_bits(this->fd, this->bits) == INVALID_SPI_COM)
    {
        printf("Can't set bits\n");
        return false;
    }

    return true;
}

///
/// @brief Read 14 bit from Encoder.
///
/// @return 0 if successful read operation. -1 otherwise.
///
bool SEncoder::get(double &value)
{
    int res = 0;

    this->tx[0] = 0x00;
    this->tx[1] = 0x00;
    this->tx[2] = 0xFF;
    this->tx[3] = 0xFF;
    this->tx[4] = 0x00;
    this->tx[5] = 0x00;
    this->tx[6] = 0x13;
    this->tx[7] = 0xEA;

    res = spi_transfer(this->fd, this->tx, this->rx, 8, false);
    if (res < 0)
    {
        printf("can't send spi message 1\n");
        return false;
    }

    usleep(700);

    /// Issue NOP message
    this->tx[0] = 0x00;
    this->tx[1] = 0x00;
    this->tx[2] = 0xAA;
    this->tx[3] = 0xAA;
    this->tx[4] = 0x00;
    this->tx[5] = 0x00;
    this->tx[6] = 0xD0;
    this->tx[7] = 0xAB;

    res = spi_transfer(this->fd, this->tx, this->rx, 8, false);
    if (res < 0)
    {
        printf("can't send spi message 2\n");
        return false;
    }

    usleep(700);

    /// Proceed received values
    this->m_alpha = this->rx[0] | (this->rx[1] & 0x3F) << 8;
    //this->m_alpha = (this->rx[0] & this->0xF8) | (this->rx[1] & 0x3F) << 8;

    this->m_last = this->m_phase;
    this->m_phase = (double)this->m_alpha * this->m_factor;

    /// Calculation
    if (this->m_one)
    {
        this->m_diff = this->m_phase - this->m_last;

        if (fabs(this->m_diff) > 180.0)
        {
            if (this->m_last > this->m_phase)
            {
                m_diff = (this->m_phase + 360.0) - this->m_last;
            }
            else if (this->m_last < this->m_phase)
            {
                m_diff = this->m_phase - (this->m_last - 360.0);
            }
        }
        value = m_diff;
    }
    this->m_one = true;

    //Extract the error bits
    this->m_diag = this->rx[1] >> 6;
    //Extract the virtual gain byte
    this->m_gain = this->rx[4];
    //Extract the rolling counter
    this->m_counter = this->rx[6] & 0x3F;
    //Extract the CRC
    this->m_crc = this->rx[7];

    //printf("crc %d\tgain %d\tcount %2d\n", m_crc, m_gain, m_counter);
    //printf("diag %d\tphase %2.5f\tdiff %2.5f\n", m_diag, m_phase, m_diff);

    if (this->m_crc == 0)
    {
        return false;
    }
    return true;
}
