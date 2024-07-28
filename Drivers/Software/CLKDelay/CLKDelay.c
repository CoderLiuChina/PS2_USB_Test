/*  ----------  Delay functions with TIM  ----------  */
/*  ----------  Designed by CoderLiuChina from Github  ----------  */

#include "CLKDelay.h"

uint8_t delayus = 0;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    delayus++;
}

void delay_us(uint8_t time)
{
    delayus = 0;
    HAL_TIM_Base_Start_IT(&htim2);
    while (delayus < time)
    {
        
    }
    HAL_TIM_Base_Stop_IT(&htim2);
}