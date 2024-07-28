/*  ----------  Software simulates SPI  ----------  */
/*  ----------  Designed by CoderLiuChina from Github  ----------  */

#include "SPI_SoftwareSim.h"

/*  ----------  Using GPIO to simulates SPI Communication  ----------  */
/*  ----------  Port list:  ----------  */
/*  ----------  PA5 -> CLK  ----------  */
/*  ----------  PA6 -> MISO ----------  */
/*  ----------  PA7 -> MOSI ----------  */

/*  ----------  Parameter List:         ----------  */
/*  ----------  Baud Rate: 250 kBits/s  ----------  */
/*  ----------  Data Size: 8 Bits       ----------  */
/*  ----------  First Bit: LSB First    ----------  */
/*  ----------  CPOL: High              ----------  */
/*  ----------  CPHA: 1 Edge            ----------  */

void SPI_TransmitReceive(uint8_t *TxData, uint8_t *RxData, uint8_t size)
{
    memset(RxData, 0, sizeof(RxData));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 8;j++)
        {
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, ((uint8_t) * (TxData + i) >> j) & 0x01);
            
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
            HAL_Delay_us(4);
            *(RxData + i) += (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)) << j;
            HAL_Delay_us(4);
        }
    }

    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
}