
#include "systemContral.h"

/*******************************************************************
 * GPIO clock gate configration
 * ****************************************************************/

void freqConfig(uint32_t sp)
{
	
    if (sp == GPIO_PA)
    {
        WriteFun(systemCtrl+R_GPIO_ClkGatingOffset, 0, HIGH);
    }
		
    else if(sp == GPIO_PB)
    {
        WriteFun(systemCtrl+R_GPIO_ClkGatingOffset, 1, HIGH);
    }
    else if(sp == GPIO_PC)
    {
        WriteFun(systemCtrl+R_GPIO_ClkGatingOffset, 2, HIGH);
    }
    else if(sp == GPIO_PD)
    {
        WriteFun(systemCtrl+R_GPIO_ClkGatingOffset, 3, HIGH);
    }
    else if(sp == GPIO_PE)
    {
        WriteFun(systemCtrl+R_GPIO_ClkGatingOffset, 4, HIGH);
    }
    else if(sp == GPIO_PF)
    {
        WriteFun(systemCtrl+R_GPIO_ClkGatingOffset, 5, HIGH);
    }
}   
/*******************************************************************
 * timer clock gate configration
 * ****************************************************************/
void timer_EnClk(uint32_t tmr)
{
    if (tmr == TIMER_0_D)
    {
        WriteFun(systemCtrl+R_TIMER_ClkGatingOffset, 0, HIGH);
    }
        
    else if(tmr == TIMER_1_D)
    {
        WriteFun(systemCtrl+R_TIMER_ClkGatingOffset, 1, HIGH);
    }
    else if(tmr == TIMER_2_D)
    {
        WriteFun(systemCtrl+R_TIMER_ClkGatingOffset, 2, HIGH);
    }
    else if(tmr == TIMER_3_D)
    {
        WriteFun(systemCtrl+R_TIMER_ClkGatingOffset, 3, HIGH);
    }
    else if(tmr == TIMER_4_D)
    {
        WriteFun(systemCtrl+R_TIMER_ClkGatingOffset, 4, HIGH);
    }
    else if(tmr == TIMER_5_D)
    {
        WriteFun(systemCtrl+R_TIMER_ClkGatingOffset, 5, HIGH);
    }

}






