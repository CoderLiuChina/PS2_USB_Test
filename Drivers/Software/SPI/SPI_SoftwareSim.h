/*  ----------  Software simulates SPI  ----------  */
/*  ----------  Designed by CoderLiuChina from Github  ----------  */
/*  ----------  Attention: Here is the header file  ----------  */
/*  ----------  While using, include .h file  ----------  */

#ifndef _SPI_SOFTWARESIM_H_
#define _SPI_SOFTWARESIM_H_

#include "stm32f1xx_hal.h"
#include "gpio.h"
#include "delay.h"

#include <string.h>

void SPI_TransmitReceive(uint8_t *TxData, uint8_t *RxData, uint8_t size);

#endif // !_SPI_SOFTWARESIM_H_