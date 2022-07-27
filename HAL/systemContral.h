/*************************************************************
 *                    Auher: Ahmed Omar
 *                     Date: 17/7/2022
 * ***********************************************************
 *              configre  the Mcu and frequancy
 * ***********************************************************/

#ifndef SYSTEMCONTRAL_H_
#define SYSTEMCONTRAL_H_


#include "HardWare_GPIO.h"
#include "HardWare_Type.h"



/********************************************************************
 *                      Function declration
 * ******************************************************************/
void freqConfig(uint32_t sp);
void timer_EnClk(uint32_t tmr);
#endif
