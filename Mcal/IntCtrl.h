/*******************************************************************************
*====================== Auther: Ahmed Omar  ====================================
=======================   Date:17/7/2022    ====================================
============   Here I write the function to read&wrire  ========================
*******************************************************************************/

#ifndef INTCTRL_H_
#define INTCTRL_H_

#include <stdint.h>

#ifndef HIGH
#define HIGH 		1
#endif

#ifndef LOW
#define LOW  		0
#endif

#ifndef OUTPUT
#define OUTPUT  1
#endif

#ifndef INPUT
#define INPUT   0
#endif

#ifndef Enable
#define Enable   1
#endif

#ifndef Disable
#define Disable   0
#endif



/********************************************************************************
 * =================================== macros ===================================
 * *****************************************************************************/



 #define hardWare_reading(adr) (*(volatile uint32_t*)(adr))
 

 /*******************************************************************************************
  * =========================== decleration =================================================
  * *****************************************************************************************/

static inline void WriteFun(uint32_t reg, uint8_t pin , uint8_t value);

/**********************************************************************************************
 *                                      static function
 * ********************************************************************************************/

static inline void WriteFun(uint32_t reg, uint8_t pin , uint8_t value)   
{
	if(value == HIGH)
  {
	hardWare_reading(reg) |= (1<<pin);
	}
	else if(value == LOW)
	{
		hardWare_reading(reg) &= ~(1<<pin);
	}
}

#endif