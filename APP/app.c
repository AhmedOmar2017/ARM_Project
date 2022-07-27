/*******************************************************************************
*====================== Auther: Ahmed Omar  ====================================
=======================   Date:23/7/2022    ====================================
*******************************************************************************/

#include "app.h"

/*==========================================================================
 *                           Initializtion the GPIO 
 *==========================================================================*/

void initPin(uint32_t Port,uint8_t Pin, uint8_t dir)
{
  freqConfig(Port);

  if(dir == INPUT)
  {
    Config_Port_In(Port, Pin);
  }
  else if(dir == OUTPUT)
  {
      Config_Port_Out(Port, Pin);
  }
   
}



/*==========================================================================
 *                            Initializtion the Timer
 *==========================================================================*/
void InitTimer(uint32_t adr, uint8_t sel, uint8_t mod, uint8_t prscal, uint8_t prload, uint8_t cli, uint8_t msk)
{
  timer_EnClk(adr);
  Disable_Timer(adr);
  Cnfig_Timer( adr, sel);
  Mod_Timer(adr, mod);
  Prsc_Timer(adr, prscal);
  Prload_Timer(adr, prload);
  Int_Clr_Timer(adr, cli);
  Int_Msk_Timer(adr, msk);
  Enble_Timer(adr);
}