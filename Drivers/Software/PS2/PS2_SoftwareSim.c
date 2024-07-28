/*  ----------  PS2 Controller Functions  ----------  */
/*  ----------  Written by plumyT from PanGu_Sys  -----------  */

#include "PS2_SoftwareSim.h"

void PS2_GetData(PS2_Controller *PS2)
{
    uint8_t CommandPack[3] = {InitCode, RequireCode, IdleCode};
    uint8_t DataPack[9];

    HAL_GPIO_WritePin(PS2_CS_GPIO_Port, PS2_CS_Pin, GPIO_PIN_RESET);

    SPI_TransmitReceive(&CommandPack[0], &DataPack[0], 1);
    HAL_Delay_us(5);
    SPI_TransmitReceive(&CommandPack[1], &DataPack[1], 1);
    HAL_Delay_us(5);
    SPI_TransmitReceive(&CommandPack[2], &DataPack[2], 1);
    HAL_Delay_us(5);

    for (int i = 3; i < 9;i++)
    {
        SPI_TransmitReceive(&CommandPack[2], &DataPack[i], 1);
        HAL_Delay_us(1);
    }

    HAL_GPIO_WritePin(PS2_CS_GPIO_Port, PS2_CS_Pin, GPIO_PIN_SET);

    for (int i = 3; i < 5;i++)
    {
        for (int j = 0; j < 8;j++)
        {
            *((uint8_t*)PS2 + j + 8 * (i - 3)) = (uint8_t)~(DataPack[i] >> j) & 0x01;
        }
    }
    PS2->PSS_RX = DataPack[5];
    PS2->PSS_RY = DataPack[6];
    PS2->PSS_LX = DataPack[7];
    PS2->PSS_LY = DataPack[8];
}