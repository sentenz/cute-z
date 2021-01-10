#include "nfcmfclassic.hpp"

#include <exception>

/////////////////////////////////////////////////////////////////////////////
//                       Constructor / Destructor                          //
/////////////////////////////////////////////////////////////////////////////

NfcMfClassic::NfcMfClassic()
{
}

NfcMfClassic::~NfcMfClassic()
{
    if (this->pnd != NULL)
    {
        nfc_close(this->pnd);
    }
    if (this->context != NULL)
    {
        nfc_exit(this->context);
    }
}

/////////////////////////////////////////////////////////////////////////////
//                            Member Functions                             //
/////////////////////////////////////////////////////////////////////////////

int NfcMfClassic::init()
{
    /// Try to open the NFC reader
    ///
    nfc_init(&this->context);
    if (this->context == NULL)
    {
        printf("error utils.nfcmfclassic nfc_init\n");
        return -1;
    }

    this->pnd = nfc_open(this->context, NULL);
    if (this->pnd == NULL)
    {
        printf("error utils.nfcmfclassic nfc_open\n");
        return -1;
    }

    if (nfc_initiator_init(this->pnd) < 0)
    {
        printf("error utils.nfcmfclassic nfc_initiator_init\n");
        return -1;
    };

    this->set_property();

    return 0;
}

void NfcMfClassic::set_property()
{
    /// Set device properties
    ///
    /*
    /// Disable ISO14443-4 switching in order to read devices that emulate Mifare Classic with ISO14443-4 compliance.
    if (nfc_device_set_property_bool(this->pnd, NP_AUTO_ISO14443_4, false) < 0)
    {
        nfc_perror(this->pnd, "nfc_device_set_property_bool");
    }
    /// Let the reader only try once to find a tag
    if (nfc_device_set_property_bool(this->pnd, NP_INFINITE_SELECT, true) < 0)
    {
        nfc_perror(this->pnd, "nfc_device_set_property_bool");
    }

    /// Configure invalid frames
    if (nfc_device_set_property_bool(this->pnd, NP_ACCEPT_INVALID_FRAMES, true) < 0)
    {
        nfc_perror(this->pnd, "nfc_device_set_property_bool");
    }

    /// Configure CRC
    if (nfc_device_set_property_bool(this->pnd, NP_HANDLE_CRC, true) < 0)
    {
        nfc_perror(this->pnd, "nfc_device_set_property_bool");
    }

    /// Guessing size
    ///
    /// 4K
    if ((this->nt.nti.nai.abtAtqa[1] & 0x02) == 0x02)
    {
        this->uiBlocks = 0xff;
    }
    /// 320b
    else if ((nt.nti.nai.btSak & 0x01) == 0x01)
    {
        this->uiBlocks = 0x13;
    }
    /// 1K/2K, checked through RATS
    else
    {
        this->uiBlocks = 0x3f;
    }

    /// Testing RATS
    int res;
    if ((res = this->get_rats()) > 0)
    {
        /// MIFARE Plus 2K
        if ((res >= 10) && (abtRx[5] == 0xc1) && (abtRx[6] == 0x05) && (abtRx[7] == 0x2f) && (abtRx[8] == 0x2f) && ((nt.nti.nai.abtAtqa[1] & 0x02) == 0x00))
        {
            this->uiBlocks = 0x7f;
        }
        /// Chinese magic emulation card, ATS=0978009102:dabc1910
        if ((res == 9)  && (abtRx[5] == 0xda) && (abtRx[6] == 0xbc) && (abtRx[7] == 0x19) && (abtRx[8] == 0x10))
        {
            this->magic2 = true;
        }
    }
    */
}

void NfcMfClassic::setKeyA(const bool key)
{
    this->bUseKeyA = key;
}

bool NfcMfClassic::is_first_block(uint32_t uiBlock)
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

bool NfcMfClassic::is_trailer_block(uint32_t uiBlock)
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

uint32_t NfcMfClassic::get_trailer_block(uint32_t uiFirstBlock)
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

bool NfcMfClassic::unlock_card(void)
{
    if (this->magic2)
    {
        printf("Don't use R/W with this card, this is not required!\n");
        return false;
    }

    /// Configure the CRC
    if (nfc_device_set_property_bool(this->pnd, NP_HANDLE_CRC, false) < 0)
    {
        nfc_perror(this->pnd, "nfc_configure");
        return false;
    }

    /// Use raw send/receive methods
    if (nfc_device_set_property_bool(this->pnd, NP_EASY_FRAMING, false) < 0)
    {
        nfc_perror(this->pnd, "nfc_configure");
        return false;
    }

    iso14443a_crc_append(this->abtHalt, 2);
    transmit_bytes(this->abtHalt, 4);

    /// now send unlock
    if (!transmit_bits(this->abtUnlock1, 7))
    {
        printf("unlock failure!\n");
        return false;
    }

    if (!transmit_bytes(this->abtUnlock2, 1))
    {
        printf("unlock failure!\n");
        return false;
    }

    /// Configure the CRC
    if (nfc_device_set_property_bool(this->pnd, NP_HANDLE_CRC, true) < 0)
    {
        nfc_perror(this->pnd, "nfc_device_set_property_bool");
        return false;
    }

    /// Switch off raw send/receive methods
    if (nfc_device_set_property_bool(this->pnd, NP_EASY_FRAMING, true) < 0)
    {
        nfc_perror(this->pnd, "nfc_device_set_property_bool");
        return false;
    }

    return true;
}

int NfcMfClassic::get_rats(void)
{
    int res;
    uint8_t abtRats[2] = { 0xe0, 0x50};

    /// Use raw send/receive methods
    if (nfc_device_set_property_bool(this->pnd, NP_EASY_FRAMING, false) < 0)
    {
        nfc_perror(this->pnd, "nfc_configure");
        return -1;
    }

    res = nfc_initiator_transceive_bytes(this->pnd, abtRats, sizeof(abtRats), this->abtRx, sizeof(this->abtRx), 0);
    if (res > 0)
    {
        /// ISO14443-4 card, turn RF field off/on to access ISO14443-3 again
        if (nfc_device_set_property_bool(this->pnd, NP_ACTIVATE_FIELD, false) < 0)
        {
            nfc_perror(this->pnd, "nfc_configure");
            return -1;
        }

        if (nfc_device_set_property_bool(this->pnd, NP_ACTIVATE_FIELD, true) < 0)
        {
            nfc_perror(this->pnd, "nfc_configure");
            return -1;
        }
    }

    return res;
}

bool NfcMfClassic::transmit_bits(const uint8_t *pbtTx, const size_t szTxBits)
{
    // Transmit the bit frame command, we don't use the arbitrary parity feature
    if ((this->szRxBits = nfc_initiator_transceive_bits(this->pnd, pbtTx, szTxBits, NULL, this->abtRx, sizeof(this->abtRx), NULL)) < 0)
    {
        return false;
    }

    return true;
}

bool NfcMfClassic::transmit_bytes(const uint8_t *pbtTx, const size_t szTx)
{
    int res;
    if ((res = nfc_initiator_transceive_bytes(this->pnd, pbtTx, szTx, this->abtRx, sizeof(this->abtRx), 0)) < 0)
    {
        return false;
    }

    return true;
}

bool NfcMfClassic::authenticate(uint32_t uiBlock)
{
    mifare_cmd mc;

    /// Set the authentication information (uid)
    memcpy(this->mp.mpa.abtAuthUid, this->nt.nti.nai.abtUid + this->nt.nti.nai.szUidLen - 4, 4);

    /// Should we use key A or B?
    mc = (this->bUseKeyA) ? MC_AUTH_A : MC_AUTH_B;

    /// If formatting or try to guess the right key
    for (size_t key_index = 0; key_index < this->num_keys; key_index++)
    {
        memcpy(this->mp.mpa.abtKey, this->keys + (key_index * 6), 6);
        if (nfc_initiator_mifare_cmd(this->pnd, mc, uiBlock, &this->mp))
        {
            if (this->bUseKeyA)
            {
                memcpy(this->mtKeys.amb[uiBlock].mbt.abtKeyA, &this->mp.mpa.abtKey, 6);
            }
            else
            {
                memcpy(this->mtKeys.amb[uiBlock].mbt.abtKeyB, &this->mp.mpa.abtKey, 6);
            }
            return true;
        }
    }

    return false;
}

bool NfcMfClassic::read_block(const uint32_t block, uint8_t abtData[])
{
    /// Try to authenticate for the current sector
    if (!this->authenticate(this->get_trailer_block(block)))
    {
        printf("Error: authentication failed for block 0x%02x\n", this->get_trailer_block(block));
        return false;
    }

    /// Try to read out the data block
    if (nfc_initiator_mifare_cmd(this->pnd, MC_READ, block, &this->mp))
    {
        memset(abtData, 0x00, 16);
        memcpy(abtData, this->mp.mpd.abtData, 16);
    }
    else
    {
        printf("Error: unable to read block 0x%02x\n", block);
        return false;
    }

    return true;
}

// ToDo
bool NfcMfClassic::read_card()
{
    return false;
}

bool NfcMfClassic::write_block(const uint32_t block, uint8_t abtData[])
{
    /// Try to authenticate for the current sector
    if (!this->authenticate(this->get_trailer_block(block)))
    {
        printf("!\nError: authentication failed for block 0x%02x\n", this->get_trailer_block(block));
        return false;
    }

    /// Try to write the data block
    memcpy(this->mp.mpd.abtData, abtData, 16);
    if (!nfc_initiator_mifare_cmd(this->pnd, MC_WRITE, block, &this->mp))
    {
        printf("!\nError: unable to write block 0x%02x\n", block);
        return false;
    }

    return true;
}

// ToDo
bool NfcMfClassic::write_card()
{
    return false;
}

double time_diff(clock_t t1, clock_t t2, bool verbose)
{
      double elapsed = 0;
      elapsed = (double)(t2 - t1) / (double)CLOCKS_PER_SEC;

      if (verbose)
      {
        printf("Time: %f sec\n\n", elapsed);
      }

      return elapsed;
}

bool NfcMfClassic::transmitBlock(const Action action, const uint32_t block, uint8_t data[])
{
    // Time
    //clock_t t1, t2;
    //t1 = clock();
    //

    switch (action)
    {
    case Action::Read:
    {
        /// Slow Data Transmission
        //if (nfc_initiator_poll_target(this->pnd, &this->nmMifare, 1, 0xFF, 0x01, &this->nt) > 0)
        /// Fast Data Transmission
        if (nfc_initiator_select_passive_target(this->pnd, nmMifare, NULL, 0, &nt) > 0)
        {
            return this->read_block(block, data);

            /*
            nfc_device_set_property_bool(this->pnd, NP_ACCEPT_INVALID_FRAMES, true);
            uint8_t getTag[2] = { 0x30, 0x02};
            if (!transmit_bytes(getTag, 2))
              printf("%s\n", "trasmit failed!");
            */

            //nfc_initiator_deselect_target(this->pnd);
        }
    }
        break;

    case Action::Write:
    {
        /// Slow Data Transmission
        //if (nfc_initiator_poll_target(this->pnd, &this->nmMifare, 1, 0xFF, 0x01, &this->nt) > 0)
        /// Fast Data Transmission
        if (nfc_initiator_select_passive_target(this->pnd, nmMifare, NULL, 0, &nt) > 0)
        {
            return this->write_block(block, data);
        }
    }
        break;

    default:
        break;
    }

    // Time
    //t2 = clock();
    //time_diff(t1, t2, true);
    //

    return false;
}

bool NfcMfClassic::transmitCard(const Action action)
{
    switch (action)
    {
    case Action::Read:
    {
        //if (nfc_initiator_poll_target(this->pnd, &this->nmMifare, 1, 0xFF, 0x01, &this->nt) > 0)
        if (nfc_initiator_select_passive_target(this->pnd, nmMifare, NULL, 0, &nt) > 0)
        {
        }
    }
        break;

    case Action::Write:
    {
        //if (nfc_initiator_poll_target(this->pnd, &this->nmMifare, 1, 0xFF, 0x01, &this->nt) > 0)
        if (nfc_initiator_select_passive_target(this->pnd, nmMifare, NULL, 0, &nt) > 0)
        {
        }
    }
        break;

    default:
        break;
    }

    return false;
}

/*
  if (strcmp(command, "r") == 0 || strcmp(command, "R") == 0) {
    atAction = ACTION_READ;
    if (strcmp(command, "R") == 0)
      unlock = 1;
    //bUseKeyA = tolower((int)((unsigned char) * (argv[2]))) == 'a';
    bTolerateFailures = tolower((int)((unsigned char) * (argv[2]))) != (int)((unsigned char) * (argv[2]));
    bUseKeyFile = (argc > 4);
    bForceKeyFile = ((argc > 5) && (strcmp((char *)argv[5], "f") == 0));
  } else if (strcmp(command, "w") == 0 || strcmp(command, "W") == 0 || strcmp(command, "f") == 0) {
    atAction = ACTION_WRITE;
    if (strcmp(command, "W") == 0)
      unlock = 1;
    bFormatCard = (strcmp(command, "f") == 0);
    //bUseKeyA = tolower((int)((unsigned char) * (argv[2]))) == 'a';
    bTolerateFailures = tolower((int)((unsigned char) * (argv[2]))) != (int)((unsigned char) * (argv[2]));
    bUseKeyFile = (argc > 4);
    bForceKeyFile = ((argc > 5) && (strcmp((char *)argv[5], "f") == 0));
  }

  if (atAction == ACTION_READ)
  {
  }
  else if (atAction == ACTION_WRITE)
  {

    // Test if we are dealing with a MIFARE compatible tag
    if ((nt.nti.nai.btSak & 0x08) == 0) {
      printf("Warning: tag is probably not a MFC!\n");
    }

    write_card(unlock);
  }
*/


