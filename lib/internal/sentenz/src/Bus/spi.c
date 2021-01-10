/*-
 * Free/Libre Near Field Communication (NFC) library
 *
 * Libnfc historical contributors:
 * Copyright (C) 2009      Roel Verdult
 * Copyright (C) 2009-2013 Romuald Conty
 * Copyright (C) 2010-2012 Romain Tartière
 * Copyright (C) 2010-2013 Philippe Teuwen
 * Copyright (C) 2012-2013 Ludovic Rousseau
 * See AUTHORS file for a more comprehensive list of contributors.
 * Additional contributors of this file:
 * Copyright (C) 2013      Evgeny Boger
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 *
 */

/**
 * @file spi.c
 * @brief SPI driver
 */

#include "spi.h"

#include <sys/ioctl.h>
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


#if defined(__APPLE__)
const char *spi_ports_device_radix[] = { "spidev", NULL };
#elif defined (__FreeBSD__) || defined (__OpenBSD__)
const char *spi_ports_device_radix[] = { "spidev", NULL };
#elif defined (__linux__)
const char *spi_ports_device_radix[] = { "spidev", NULL };
#else
#error "Can't determine spi port string for your system"
#endif


int spi_open(const char *pcPortName)
{
    int fd;
    fd = open(pcPortName, O_RDWR | O_NOCTTY | O_NONBLOCK);

    if (fd < 0)
    {
        return INVALID_SPI_PORT;
    }

    return fd;
}

int spi_set_speed(int fd, const uint32_t uiPortSpeed)
{
    int ret = -1;
    ret = ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &uiPortSpeed);

    if (ret < 0)
    {
        printf("Error setting SPI speed.\n");
        return INVALID_SPI_COM;
    }

    return ret;
}

int spi_set_mode(int fd, const uint32_t uiPortMode)
{
    int ret = -1;
    ret = ioctl(fd, SPI_IOC_WR_MODE, &uiPortMode);

    if (ret < 0)
    {
        printf("Error setting SPI mode.\n");
        return INVALID_SPI_COM;
    }

    return ret;
}

int spi_set_bits(int fd, const uint32_t uiPortBits)
{
    int ret = -1;
    ret = ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &uiPortBits);

    if (ret < 0)
    {
        printf("Error setting SPI bits.\n");
        return INVALID_SPI_COM;
    }

    return ret;
}

uint32_t spi_get_speed(int fd)
{
    uint32_t uiPortSpeed = 0;

    int ret;
    ret = ioctl(fd, SPI_IOC_RD_MAX_SPEED_HZ, &uiPortSpeed);

    if (ret < 0)
    {
        printf("Error reading SPI speed.\n");
        return INVALID_SPI_COM;
    }

    return uiPortSpeed;
}

uint32_t spi_get_mode(int fd)
{
    uint32_t uiPortMode = 0;

    int ret;
    ret = ioctl(fd, SPI_IOC_RD_MODE, &uiPortMode);

    if (ret < 0)
    {
        printf("Error reading SPI mode.\n");
        return INVALID_SPI_COM;
    }

    return uiPortMode;
}

uint32_t spi_get_bits(int fd)
{
    uint32_t uiPortBits = 0;

    int ret;
    ret = ioctl(fd, SPI_IOC_RD_BITS_PER_WORD, &uiPortBits);

    if (ret < 0)
    {
        printf("Error reading SPI bits.\n");
        return INVALID_SPI_COM;
    }

    return uiPortBits;
}

void spi_close(int fd)
{
    close(fd);
}

/**
 * @brief Perform bit reversal on one byte \a x
 *
 * @return reversed byte
 */
static uint8_t bit_reversal(const uint8_t x)
{
    uint8_t ret = x;
    ret = (((ret & 0xaa) >> 1) | ((ret & 0x55) << 1));
    ret = (((ret & 0xcc) >> 2) | ((ret & 0x33) << 2));
    ret = (((ret & 0xf0) >> 4) | ((ret & 0x0f) << 4));
    return ret;
}

/**
 * @brief Send \a pbtTx content to SPI then receive data from SPI and copy data to \a pbtRx. CS line stays active between transfers as well as during transfers.
 *
 * @return 0 on success, otherwise a driver error is returned
 */
int spi_transfer(int fd, const uint8_t *pbtTx, uint8_t *pbtRx, const size_t sz, const uint8_t uiBits, const uint16_t uiDelay, const uint32_t uiSpeed, const bool lsb_first)
{
    uint8_t *pbtTxLSB = 0;

    if (sz)
    {
        if (lsb_first)
        {
            pbtTxLSB = (uint8_t *)malloc(sz * sizeof(uint8_t));
            if (!pbtTxLSB)
            {
                return -1;
            }

            size_t i;
            for (i = 0; i < sz; ++i)
            {
                pbtTxLSB[i] = bit_reversal(pbtTx[i]);
            }

            pbtTx = pbtTxLSB;
        }
    }

    struct spi_ioc_transfer tr;
    memset(&tr, 0, sizeof(tr));
    tr.tx_buf = (unsigned long) pbtTx;
    tr.rx_buf = (unsigned long) pbtRx;
    tr.len = sz;
    tr.delay_usecs = uiDelay;
    tr.speed_hz = uiSpeed;
    tr.bits_per_word = uiBits;

    int ret;
    ret = ioctl(fd, SPI_IOC_MESSAGE(1), &tr);

    if (sz && lsb_first)
    {
        free(pbtTxLSB);
    }

    if (ret < 0)
    {
        return INVALID_SPI_COM;
    }

    // Reverse received bytes if needed
    if (sz)
    {
        if (lsb_first)
        {
            size_t i;
            for (i = 0; i < sz; ++i)
            {
                pbtRx[i] = bit_reversal(pbtRx[i]);
            }
        }
    }

    return 0;
}

/**
 * @brief Send \a pbtTx content to SPI then receive data from SPI and copy data to \a pbtRx. CS line stays active	 between transfers as well as during transfers.
 *
 * @return 0 on success, otherwise a driver error is returned
 */
int spi_send_receive(int fd, const uint8_t *pbtTx, const size_t szTx, uint8_t *pbtRx, const size_t szRx, bool lsb_first)
{
    size_t transfers = 0;
    struct spi_ioc_transfer tr[2];

    uint8_t *pbtTxLSB = 0;

    if (szTx)
    {
        if (lsb_first)
        {
            pbtTxLSB = (uint8_t *)malloc(szTx * sizeof(uint8_t));
            if (!pbtTxLSB)
            {
                return -1;
            }

            size_t i;
            for (i = 0; i < szTx; ++i)
            {
                pbtTxLSB[i] = bit_reversal(pbtTx[i]);
            }

            pbtTx = pbtTxLSB;
        }

        struct spi_ioc_transfer tr_send;
        memset(&tr, 0, sizeof(tr_send));
        tr_send.tx_buf = (unsigned long) pbtTx;
        tr_send.rx_buf = 0;
        tr_send.len = szTx;
        tr_send.delay_usecs = 0;
        tr_send.speed_hz = 0;
        tr_send.bits_per_word = 0;
        tr[transfers] = tr_send;
        ++transfers;
    }

    if (szRx)
    {
        struct spi_ioc_transfer tr_receive;
        memset(&tr, 0, sizeof(tr_receive));
        tr_receive.tx_buf = 0;
        tr_receive.rx_buf = (unsigned long) pbtRx;
        tr_receive.len = szRx;
        tr_receive.delay_usecs = 0;
        tr_receive.speed_hz = 0;
        tr_receive.bits_per_word = 0;
        tr[transfers] = tr_receive;
        ++transfers;
    }

    if (transfers)
    {
        int ret;
        ret = ioctl(fd, SPI_IOC_MESSAGE(transfers), tr);

        if (szTx && lsb_first)
        {
            free(pbtTxLSB);
        }

        if (ret < 0)
        {
            return INVALID_SPI_COM;
        }

        // Reverse received bytes if needed
        if (szRx)
        {
            if (lsb_first)
            {
                size_t i;
                for (i = 0; i < szRx; ++i)
                {
                    pbtRx[i] = bit_reversal(pbtRx[i]);
                }
            }
        }
    }

    return 0;
}

/**
 * @brief Receive data from SPI and copy data to \a pbtRx
 *
 * @return 0 on success, otherwise driver error code
 */
int spi_receive(int fd, uint8_t *pbtRx, const size_t szRx, bool lsb_first)
{
    return spi_send_receive(fd, 0, 0, pbtRx, szRx, lsb_first);
}

/**
 * @brief Send \a pbtTx content to SPI
 *
 * @return 0 on success, otherwise a driver error is returned
 */
int spi_send(int fd, const uint8_t *pbtTx, const size_t szTx, bool lsb_first)
{
    return spi_send_receive(fd, pbtTx, szTx, 0, 0, lsb_first);
}

char **spi_list_ports(void)
{
    char **res = (char **)malloc(sizeof(char *));
    size_t szRes = 1;
    res[0] = NULL;

    DIR *pdDir = opendir("/dev");
    struct dirent *pdDirEnt;
    struct dirent entry;
    struct dirent *result;

    while ((readdir_r(pdDir, &entry, &result) == 0) && (result != NULL))
    {
        pdDirEnt = &entry;
        #if !defined(__APPLE__)
        if (!isdigit(pdDirEnt->d_name[strlen(pdDirEnt->d_name) - 1]))
        {
            continue;
        }
        #endif
        const char **p = spi_ports_device_radix;
        while (*p)
        {
            if (!strncmp(pdDirEnt->d_name, *p, strlen(*p)))
            {
                char **res2 = (char **)realloc(res, (szRes + 1) * sizeof(char *));
                if (!res2)
                {
                    goto oom;
                }

                res = res2;
                if (!(res[szRes - 1] = (char *)malloc(6 + strlen(pdDirEnt->d_name))))
                {
                    goto oom;
                }

                sprintf(res[szRes - 1], "/dev/%s", pdDirEnt->d_name);

                szRes++;
                res[szRes - 1] = NULL;
            }
            p++;
        }
    }

    oom:
    closedir(pdDir);

    return res;
}
