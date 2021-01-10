/*
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

/*
 * @file nfc-mfclassic.c
 * @brief MIFARE Classic manipulation example
 */

#ifndef SNFCCONTROLLER_HPP
#define SNFCCONTROLLER_HPP

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif /// HAVE_CONFIG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include <nfc/nfc.h>
#include "../utils/mifare.h"

#include <time.h>


enum class Action
{
    Read,
    Write,
    Format,
};

class SNFCController
{
public:
    SNFCController();
    ~SNFCController();
    const SNFCController& operator=(const SNFCController&) = delete;

    /// Member functions
    int init();
    void setKeyA(const bool key = true);
    bool transmitBlock(const Action action, const uint32_t block, uint8_t data[16]);
    bool transmitCard(const Action action);

private:
    /// Member functions
    void set_property();
    bool read_block(const uint32_t block, uint8_t abtData[16]);
    bool read_card();
    bool write_block(const uint32_t block, uint8_t abtData[16]);
    bool write_card();
    bool transmit_bits(const uint8_t *pbtTx, const size_t szTxBits);
    bool transmit_bytes(const uint8_t *pbtTx, const size_t szTx);
    bool is_first_block(uint32_t uiBlock);
    bool is_trailer_block(uint32_t uiBlock);
    bool authenticate(uint32_t uiBlock);
    bool unlock_card(void);
    int get_rats(void);
    uint32_t get_trailer_block(uint32_t uiFirstBlock);

    /// Member variables
    #define MAX_FRAME_LEN 264

    bool bUseKeyA = true;
    bool bFormatCard = false;
    bool magic2 = false;
    int szRxBits;
    uint8_t uiBlocks;
    uint8_t abtData[16];
    uint8_t default_key[6] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
    uint8_t default_acl[4] = { 0xff, 0x07, 0x80, 0x69 };
    uint8_t abtHalt[4] = { 0x50, 0x00, 0x00, 0x00 };
    uint8_t abtUnlock1[1] = { 0x40 };
    uint8_t abtUnlock2[1] = { 0x43 };
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

    nfc_context *context;
    nfc_device *pnd;
    nfc_target nt;
    mifare_param mp;
    mifare_classic_tag mtKeys;
    const nfc_modulation nmMifare = {
        .nmt = NMT_ISO14443A,
        .nbr = NBR_106,
    };
};

#endif /// SNFCCONTROLLER_HPP
