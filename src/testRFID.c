#include <stdio.h>
#include <stdlib.h>
#include "SPIRpi.h"
#include <stdint.h>
#include "rfid-rc522.h"
#include <unistd.h>
uint8_t CardID[5];
uint8_t buffer[5];
uint8_t type;
uint8_t status = 0;
int ret;

int main(int argc, char**argv)
{
    int i;
    SPI_t hspi;
    SPI_Init(&hspi,0, POL0_PHA0, SPI_FREQ_1MHZ, SPI_WORD_LEN_8, 17);
    RFID_RC522_Init(&hspi);
    while(1)
    {
        ret = TM_MFRC522_Check(&hspi, buffer, &type);
        if(ret == MI_OK)
        {
            printf("Card detected: \nID: ");
            for(i = 0; i < 5; i++)
            {
                CardID[i] = buffer[i];
                buffer[i] = 0;
                printf("%d : ", CardID[i]);
            }
            printf("\n");
        }
        else if(ret == MI_TIMEOUT)
        {
            //printf(".");
        }
        else if(ret == MI_ERR)
        {

        }
        else
        {
            //do nothing
        }
        usleep(40);
    }
    return SUCCESS;
}