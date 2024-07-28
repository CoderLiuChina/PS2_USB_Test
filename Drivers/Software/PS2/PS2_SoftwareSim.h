/*  ----------  PS2 Controller Functions  ----------  */
/*  ----------  Written by plumyT from PanGu_Sys  -----------  */
/*  ----------  Attention: Using software SPI  -----------  */
/*  ----------  Remember to include "SPI_SoftwareSim.h"  ----------  */
/*  ----------  While using, include .h file*/

#ifndef _PS2_SOFTWARESIM_H_
#define _PS2_SOFTWARESIM_H_

#include "SPI_SoftwareSim.h"
#include "delay.h"

#define InitCode 0x01
#define RequireCode 0x42
#define IdleCode 0x00
#define RedModeCode 0x73
#define GreenModeCOde 0x41
#define HeaderCode 0x5a

typedef struct
{
    uint8_t SELECT, L3, R3, START, UP, RIGHT, DOWN, LEFT;
    uint8_t L2, R2, L1, R1, Y, B, A, X;
    uint8_t PSS_RX, PSS_RY, PSS_LX, PSS_LY;
} PS2_Controller;

void PS2_GetData(PS2_Controller *PS2);

#endif // !_PS2_SOFTWARESIM_H_
