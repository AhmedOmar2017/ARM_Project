/*******************************************************************************
*====================== Auther: Ahmed Omar  ====================================
=======================   Date:23/7/2022    ====================================
*******************************************************************************/


#ifndef APP_H_
#define APP_H_


#include "systemContral.h"
#include "GPIO.h"
#include "TIMER.h"
#include "interrupt.h"

/*==========================================================================
 *                           Initializtion the GPIO 
 *==========================================================================*/
void initPin(uint32_t Port,uint8_t Pin, uint8_t dir);

/*==========================================================================
 *                            Initializtion the Timer
 *==========================================================================*/
void InitTimer(uint32_t adr, uint8_t sel, uint8_t mod, uint8_t prscal, uint8_t prload, uint8_t cli, uint8_t msk);
#endif