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
 * @file usb.h
 * @brief usb driver header
 */

#ifndef SENTNEZ_BUS_USB_H
#define SENTNEZ_BUS_USB_H

#ifdef __cplusplus
extern  "C" {
#endif // __cplusplus


#if defined (__linux__)
// Under POSIX system, we use libusb (>= 0.1.12)
#include <usb.h>
#define USB_TIMEDOUT ETIMEDOUT
#define _usb_strerror( X ) strerror(-X)
#else
// Under Windows we use libusb-win32 (>= 1.2.5)
#include <lusb0_usb.h>
#define USB_TIMEDOUT 116
#define _usb_strerror( X ) usb_strerror()
#endif

#include <stdbool.h>
#include <string.h>


int usb_prepare(void);


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // SENTNEZ_BUS_USB_H
