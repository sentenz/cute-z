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
 * @file usbbus.c
 * @brief libusb 0.1 driver wrapper
 */

#include "usbbus.h"

#include <stdlib.h>


int usb_prepare(void)
{
    static bool usb_initialized = false;
    if (!usb_initialized)
    {
        usb_init();
        usb_initialized = true;
    }

    int res;
    // usb_find_busses will find all of the busses on the system. Returns the
    // number of changes since previous call to this function (total of new
    // busses and busses removed).
    if ((res = usb_find_busses()) < 0)
    {
        return -1;
    }

    // usb_find_devices will find all of the devices on each bus. This should be
    // called after usb_find_busses. Returns the number of changes since the
    // previous call to this function (total of new device and devices removed).
    if ((res = usb_find_devices()) < 0)
    {
        return -1;
    }

    return 0;

}

