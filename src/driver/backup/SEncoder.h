#ifndef SENCODER_H
#define SENCODER_H

#include <iostream>

#include <Bus>


class SEncoder
{
public:
    SEncoder();
    ~SEncoder();
    const SEncoder& operator=(const SEncoder&) = delete;

    /// Member functions
    bool init();
    bool get(double &value);

private:
    /// Variable members
    bool m_one = false;
    uint8_t m_diag = 0;
    uint8_t m_gain = 0;
    uint8_t m_counter = 0;
    uint8_t m_crc = 0;
    double m_dist = 0.0;
    double m_last = 0.0;
    double m_diff = 0.0;
    double m_phase = 0.0;
    unsigned int m_alpha = 0;
    const double m_factor = 360.0 / 16383.0;

    /// SPI members
    int fd;
    char *port = "/dev/spidev0.0";
    uint8_t tx[8];
    uint8_t rx[8];
    uint32_t mode = SPI_CPHA;
    uint32_t bits = 8;
    uint32_t speed = 500000;

};

#endif /// SENCODER_H
