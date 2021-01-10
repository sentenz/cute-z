#include "nfc-mfclassic.h"

int main ()
{
    uint8_t data[16];
    uint32_t block = 2;
    Action_t action = Read;

    mf_init();

    while (1)
    {
        if (transmitBlock(action, block, data))
        {
            printf("%i\n\n", data[0]);
        }
    }

    mf_close();

    return 0;
}
