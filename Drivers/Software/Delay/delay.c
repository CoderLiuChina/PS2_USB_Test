#include "delay.h"

void HAL_Delay_us(uint32_t nus)
{
    HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq() / 1000000);
    HAL_Delay(nus - 1);
    HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq() / 1000);

    if (nus == 0)
        return;
}