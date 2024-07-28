/*  ----------  Delay functions with TIM  ----------  */
/*  ----------  Designed by CoderLiuChina from Github  ----------  */
/*  ----------  Attention: Here is the header file  ----------  */
/*  ----------  While using, include .h file  ----------  */

#ifndef _CLKDELAY_H_
#define _CLKDELAY_H_

#include "stm32f1xx_hal.h"
#include "tim.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
void delay_us(uint8_t time);

#endif // !_CLKDELAY_H_
