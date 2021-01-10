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
 * @file spi.h
 * @brief SPI driver header
 */

#ifndef SENTNEZ_BUS_SPI_H
#define SENTNEZ_BUS_SPI_H

#include <sys/time.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <linux/spi/spidev.h>


#ifdef __cplusplus
extern  "C" {
#endif // __cplusplus


// Define shortcut to types to make code more readable
#define INVALID_SPI_PORT -1
#define INVALID_SPI_COM -2

int spi_open(const char *pcPortName);
void spi_close(int fd);

int spi_set_speed(int fd, const uint32_t uiPortSpeed);
int spi_set_mode(int fd, const uint32_t uiPortMode);
int spi_set_bits(int fd, const uint32_t uiPortBits);
uint32_t spi_get_speed(const int fd);
uint32_t spi_get_mode(const int fd);
uint32_t spi_get_bits(const int fd);

int spi_receive(int fd, uint8_t *pbtRx, const size_t szRx, bool lsb_first);
int spi_send(int fd, const uint8_t *pbtTx, const size_t szTx, bool lsb_first);
int spi_send_receive(int fd, const uint8_t *pbtTx, const size_t szTx, uint8_t *pbtRx, const size_t szRx, bool lsb_first);
int spi_transfer(int fd, const uint8_t *pbtTx, uint8_t *pbtRx, const size_t sz, const uint8_t uiBits, const uint16_t uiDelay, const uint32_t uiSpeed, const bool lsb_first);

char **spi_list_ports(void);


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // SENTNEZ_BUS_SPI_H
