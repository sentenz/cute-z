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
 * Copyright (C) 2011-2013 Adam Laurie
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *  1) Redistributions of source code must retain the above copyright notice,
 *  this list of conditions and the following disclaimer.
 *  2 )Redistributions in binary form must reproduce the above copyright
 *  notice, this list of conditions and the following disclaimer in the
 *  documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Note that this license only applies on the examples, NFC library itself is under LGPL
 *
 */

/**
 * @file nfc-mfclassic.c
 * @brief MIFARE Classic manipulation example
 */

#ifndef NFC_MFCLASSIC_H
#define NFC_MFCLASSIC_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <string.h>
#include <ctype.h>
#include <time.h>

#ifdef __cplusplus
extern "C"
{
#endif /// __cplusplus

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif // HAVE_CONFIG_H

#include <nfc/nfc.h>
#include "../utils/mifare.h"

bool bUseKeyA;
bool bFormatCard;
bool magic2 = false;
int szRxBits;
uint8_t uiBlocks;
uint8_t abtData[16];
uint8_t default_key[6] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
uint8_t default_acl[4] = { 0xff, 0x07, 0x80, 0x69 };
uint8_t abtHalt[4] = { 0x50, 0x00, 0x00, 0x00 };
uint8_t abtUnlock1[1] = { 0x40 };
uint8_t abtUnlock2[1] = { 0x43 };
/// Member variables
#define MAX_FRAME_LEN 264
uint8_t abtRx[MAX_FRAME_LEN];
uint8_t keys[54] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xd3, 0xf7, 0xd3, 0xf7, 0xd3, 0xf7,
    0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5,
    0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5,
    0x4d, 0x3a, 0x99, 0xc3, 0x51, 0xdd,
    0x1a, 0x98, 0x2c, 0x7e, 0x45, 0x9a,
    0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xab, 0xcd, 0xef, 0x12, 0x34, 0x56
};
size_t num_keys = sizeof(keys) / 6;

nfc_context *context = NULL;
nfc_device *pnd = NULL;
nfc_target nt;
mifare_param mp;
mifare_classic_tag mtKeys;
const nfc_modulation nmMifare = {
    .nmt = NMT_ISO14443A,
    .nbr = NBR_106,
};

typedef enum
{
    Read,
    Write,
    Format,
} Action_t ;

/////////////////////////////////////////////////////////////////////////////
//                       Constructor / Destructor                          //
/////////////////////////////////////////////////////////////////////////////

void mf_init()
{
    bUseKeyA = true;

    /// Try to open the NFC reader
    ///
    nfc_init(&context);
    if (context == NULL)
    {
        printf("Unable to init libnfc (malloc)");
    }

    pnd = nfc_open(context, NULL);
    if (pnd == NULL)
    {
        printf("Error opening NFC reader");
    }

    if (nfc_initiator_init(pnd) < 0)
    {
        nfc_perror(pnd, "nfc_initiator_init");
    };

    /// Set device properties
    ///
    /*
    /// Disable ISO14443-4 switching in order to read devices that emulate Mifare Classic with ISO14443-4 compliance.
    if (nfc_device_set_property_bool(pnd, NP_AUTO_ISO14443_4, false) < 0)
    {
        nfc_perror(pnd, "nfc_device_set_property_bool");
        exit(EXIT_FAILURE);
    }
    /// Let the reader only try once to find a tag
    if (nfc_device_set_property_bool(pnd, NP_INFINITE_SELECT, true) < 0)
    {
        nfc_perror(pnd, "nfc_device_set_property_bool");
        exit(EXIT_FAILURE);
    }

    /// Configure invalid frames
    if (nfc_device_set_property_bool(pnd, NP_ACCEPT_INVALID_FRAMES, true) < 0)
    {
        nfc_perror(pnd, "nfc_device_set_property_bool");
        exit(EXIT_FAILURE);
    }

    /// Configure CRC
    if (nfc_device_set_property_bool(pnd, NP_HANDLE_CRC, true) < 0)
    {
        nfc_perror(pnd, "nfc_device_set_property_bool");
        exit(EXIT_FAILURE);
    }

    /// Guessing size
    ///
    /// 4K
    if ((nt.nti.nai.abtAtqa[1] & 0x02) == 0x02)
    {
        uiBlocks = 0xff;
    }
    /// 320b
    else if ((nt.nti.nai.btSak & 0x01) == 0x01)
    {
        uiBlocks = 0x13;
    }
    /// 1K/2K, checked through RATS
    else
    {
        uiBlocks = 0x3f;
    }

    /// Testing RATS
    int res;
    if ((res = get_rats()) > 0)
    {
        /// MIFARE Plus 2K
        if ((res >= 10) && (abtRx[5] == 0xc1) && (abtRx[6] == 0x05) && (abtRx[7] == 0x2f) && (abtRx[8] == 0x2f) && ((nt.nti.nai.abtAtqa[1] & 0x02) == 0x00))
        {
            uiBlocks = 0x7f;
        }
        /// Chinese magic emulation card, ATS=0978009102:dabc1910
        if ((res == 9)  && (abtRx[5] == 0xda) && (abtRx[6] == 0xbc) && (abtRx[7] == 0x19) && (abtRx[8] == 0x10))
        {
            magic2 = true;
        }
    }
    */
}

void mf_close()
{
    if (pnd != NULL)
    {
        nfc_close(pnd);
    }
    if (context != NULL)
    {
        nfc_exit(context);
    }
}

/////////////////////////////////////////////////////////////////////////////
//                            Member Functions                             //
/////////////////////////////////////////////////////////////////////////////

bool transmit_bits(const uint8_t *pbtTx, const size_t szTxBits)
{
    // Transmit the bit frame command, we don't use the arbitrary parity feature
    if ((szRxBits = nfc_initiator_transceive_bits(pnd, pbtTx, szTxBits, NULL, abtRx, sizeof(abtRx), NULL)) < 0)
    {
        return false;
    }

    return true;
}

bool transmit_bytes(const uint8_t *pbtTx, const size_t szTx)
{
    int res;
    if ((res = nfc_initiator_transceive_bytes(pnd, pbtTx, szTx, abtRx, sizeof(abtRx), 0)) < 0)
    {
        return false;
    }

    return true;
}

bool is_first_block(uint32_t uiBlock)
{
    /// Test if we are in the small or big sectors
    if (uiBlock < 128)
    {
        return ((uiBlock) % 4 == 0);
    }
    else
    {
        return ((uiBlock) % 16 == 0);
    }
}

bool is_trailer_block(uint32_t uiBlock)
{
    /// Test if we are in the small or big sectors
    if (uiBlock < 128)
    {
        return ((uiBlock + 1) % 4 == 0);
    }
    else
    {
        return ((uiBlock + 1) % 16 == 0);
    }
}

uint32_t get_trailer_block(uint32_t uiFirstBlock)
{
    /// Test if we are in the small or big sectors
    uint32_t trailer_block = 0;
    if (uiFirstBlock < 128)
    {
      trailer_block = uiFirstBlock + (3 - (uiFirstBlock % 4));
    }
    else
    {
      trailer_block = uiFirstBlock + (15 - (uiFirstBlock % 16));
    }
    return trailer_block;
}

bool authenticate(uint32_t uiBlock)
{
    mifare_cmd mc;

    /// Set the authentication information (uid)
    memcpy(mp.mpa.abtAuthUid, nt.nti.nai.abtUid + nt.nti.nai.szUidLen - 4, 4);

    /// Should we use key A or B?
    mc = (bUseKeyA) ? MC_AUTH_A : MC_AUTH_B;

    /// If formatting or try to guess the right key
    for (size_t key_index = 0; key_index < num_keys; key_index++)
    {
        memcpy(mp.mpa.abtKey, keys + (key_index * 6), 6);
        if (nfc_initiator_mifare_cmd(pnd, mc, uiBlock, &mp))
        {
            if (bUseKeyA)
            {
                memcpy(mtKeys.amb[uiBlock].mbt.abtKeyA, &mp.mpa.abtKey, 6);
            }
            else
            {
                memcpy(mtKeys.amb[uiBlock].mbt.abtKeyB, &mp.mpa.abtKey, 6);
            }
            return true;
        }
    }

    return false;
}

bool unlock_card(void)
{
    if (magic2)
    {
        printf("Don't use R/W with this card, this is not required!\n");
        return false;
    }

    /// Configure the CRC
    if (nfc_device_set_property_bool(pnd, NP_HANDLE_CRC, false) < 0)
    {
        nfc_perror(pnd, "nfc_configure");
        return false;
    }

    /// Use raw send/receive methods
    if (nfc_device_set_property_bool(pnd, NP_EASY_FRAMING, false) < 0)
    {
        nfc_perror(pnd, "nfc_configure");
        return false;
    }

    iso14443a_crc_append(abtHalt, 2);
    transmit_bytes(abtHalt, 4);

    /// now send unlock
    if (!transmit_bits(abtUnlock1, 7))
    {
        printf("unlock failure!\n");
        return false;
    }

    if (!transmit_bytes(abtUnlock2, 1))
    {
        printf("unlock failure!\n");
        return false;
    }

    /// Configure the CRC
    if (nfc_device_set_property_bool(pnd, NP_HANDLE_CRC, true) < 0)
    {
        nfc_perror(pnd, "nfc_device_set_property_bool");
        return false;
    }

    /// Switch off raw send/receive methods
    if (nfc_device_set_property_bool(pnd, NP_EASY_FRAMING, true) < 0)
    {
        nfc_perror(pnd, "nfc_device_set_property_bool");
        return false;
    }

    return true;
}

int get_rats(void)
{
    int res;
    uint8_t abtRats[2] = { 0xe0, 0x50};

    /// Use raw send/receive methods
    if (nfc_device_set_property_bool(pnd, NP_EASY_FRAMING, false) < 0)
    {
        nfc_perror(pnd, "nfc_configure");
        return -1;
    }

    res = nfc_initiator_transceive_bytes(pnd, abtRats, sizeof(abtRats), abtRx, sizeof(abtRx), 0);
    if (res > 0)
    {
        /// ISO14443-4 card, turn RF field off/on to access ISO14443-3 again
        if (nfc_device_set_property_bool(pnd, NP_ACTIVATE_FIELD, false) < 0)
        {
            nfc_perror(pnd, "nfc_configure");
            return -1;
        }

        if (nfc_device_set_property_bool(pnd, NP_ACTIVATE_FIELD, true) < 0)
        {
            nfc_perror(pnd, "nfc_configure");
            return -1;
        }
    }

    return res;
}

bool read_block(const uint32_t block, uint8_t abtData[])
{
    /// Try to authenticate for the current sector
    if (!authenticate(get_trailer_block(block)))
    {
        printf("!\nError: authentication failed for block 0x%02x\n", get_trailer_block(block));
        return false;
    }

    /// Try to read out the data block
    if (nfc_initiator_mifare_cmd(pnd, MC_READ, block, &mp))
    {
        memset(abtData, 0x00, 16);
        memcpy(abtData, mp.mpd.abtData, 16);
    }
    else
    {
        printf("!\nError: unable to read block 0x%02x\n", block);
        return false;
    }

    return true;
}

// ToDo
bool read_card()
{
    return false;
}

bool write_block(const uint32_t block, uint8_t abtData[])
{
    /// Try to authenticate for the current sector
    if (!authenticate(get_trailer_block(block)))
    {
        printf("!\nError: authentication failed for block 0x%02x\n", get_trailer_block(block));
        return false;
    }

    /// Try to write the data block
    memcpy(mp.mpd.abtData, abtData, 16);
    if (!nfc_initiator_mifare_cmd(pnd, MC_WRITE, block, &mp))
    {
        printf("!\nError: unable to write block 0x%02x\n", block);
        return false;
    }

    return true;
}

// ToDo
bool write_card()
{
    return false;
}

double time_diff(clock_t t1, clock_t t2, bool verbose)
{
      double elapsed = 0;
      elapsed = (double)(t2 - t1) / (double)CLOCKS_PER_SEC;

      if (verbose) {
        printf("Time: %f sec\n\n", elapsed);
      }

      return elapsed;
}

bool transmitBlock(const Action_t action, const uint32_t block, uint8_t data[])
{
    // Time
    clock_t t1, t2;
    t1 = clock();
    //

    bool result = false;

    switch (action)
    {
        case Read:
        {
            if (nfc_initiator_poll_target(pnd, &nmMifare, 1, 0xFF, 0x01, &nt) > 0)
            //if (nfc_initiator_select_passive_target(pnd, nmMifare, NULL, 0, &nt) > 0)
            {
                result = read_block(block, data);

                /*
                nfc_device_set_property_bool(pnd, NP_ACCEPT_INVALID_FRAMES, true);
                uint8_t getTag[2] = { 0x30, 0x02};
                if (!transmit_bytes(getTag, 2))
                  printf("%s\n", "trasmit failed!");
                */

                //nfc_initiator_deselect_target(pnd);
            }
        }
            break;
        case Write:
        {
            if (nfc_initiator_poll_target(pnd, &nmMifare, 1, 0xFF, 0x01, &nt) > 0)
            //if (nfc_initiator_select_passive_target(pnd, nmMifare, NULL, 0, &nt) > 0)
            {
                result = write_block(block, data);
            }
        }
            break;
        default:
            break;
    }

    // Time
    t2 = clock();
    time_diff(t1, t2, true);
    //

    return result;
}

bool transmitCard(const Action_t action)
{
    bool result = false;

    switch (action)
    {
        case Read:
        {
            //if (nfc_initiator_poll_target(pnd, &nmMifare, 1, 0xFF, 0x01, &nt) > 0)
            if (nfc_initiator_select_passive_target(pnd, nmMifare, NULL, 0, &nt) > 0)
            {
            }
        }
            break;
        case Write:
        {
            if (nfc_initiator_poll_target(pnd, &nmMifare, 1, 0xFF, 0x01, &nt) > 0)
            if (nfc_initiator_select_passive_target(pnd, nmMifare, NULL, 0, &nt) > 0)
            {
            }
        }
            break;
        default:
            break;
    }

    return result;
}

#ifdef __cplusplus
}  /// extern "C"
#endif /// __cplusplus

#endif /// NFC_MFCLASSIC_H


/*
  if (strcmp(command, "r") == 0 || strcmp(command, "R") == 0) {
    atAction_t = ACTION_READ;
    if (strcmp(command, "R") == 0)
      unlock = 1;
    //bUseKeyA = tolower((int)((unsigned char) * (argv[2]))) == 'a';
    bTolerateFailures = tolower((int)((unsigned char) * (argv[2]))) != (int)((unsigned char) * (argv[2]));
    bUseKeyFile = (argc > 4);
    bForceKeyFile = ((argc > 5) && (strcmp((char *)argv[5], "f") == 0));
  } else if (strcmp(command, "w") == 0 || strcmp(command, "W") == 0 || strcmp(command, "f") == 0) {
    atAction_t = ACTION_WRITE;
    if (strcmp(command, "W") == 0)
      unlock = 1;
    bFormatCard = (strcmp(command, "f") == 0);
    //bUseKeyA = tolower((int)((unsigned char) * (argv[2]))) == 'a';
    bTolerateFailures = tolower((int)((unsigned char) * (argv[2]))) != (int)((unsigned char) * (argv[2]));
    bUseKeyFile = (argc > 4);
    bForceKeyFile = ((argc > 5) && (strcmp((char *)argv[5], "f") == 0));
  }

  if (atAction_t == ACTION_READ)
  {
  }
  else if (atAction_t == ACTION_WRITE)
  {

    // Test if we are dealing with a MIFARE compatible tag
    if ((nt.nti.nai.btSak & 0x08) == 0) {
      printf("Warning: tag is probably not a MFC!\n");
    }

    write_card(unlock);
  }
*/


