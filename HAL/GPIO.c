/*******************************************************************************
*====================== Auther: Ahmed Omar  ====================================
=======================   Date:17/7/2022    ====================================
============   function responsible for configration    ========================
=================  general perpose input output ================================
*******************************************************************************/                 
#include "GPIO.h"


/*==========================================================================
 *                         diraction of all port 
 *==========================================================================*/

void Port_Dir(uint32_t port , uint8_t dir)
{
    if(dir == INPUT)
    {
      hardWare_reading(port+R_GPIO_DIROffset) 		= 0x00;
    }
    else if(dir == OUTPUT)
    {
       hardWare_reading(port+R_GPIO_DIROffset) 		= 0xFF;
    }
}

/*==========================================================================
 *                            Write on pin
 *==========================================================================*/
void Wr_Pin(uint32_t port , uint8_t pin , uint8_t value)
{
    if(value == HIGH)
    {
         WriteFun(port+R_GPIO_DataOffset+Hw_Mask,pin,value);
    }
    else if(value == LOW)
    {
         WriteFun(port+R_GPIO_DataOffset+Hw_Mask,pin,value);
    }
}

/*==========================================================================
 *              all configration in one function of output gpio pin 
 *==========================================================================*/
void Config_Port_Out(uint32_t port, uint8_t pin)
{
  hardWare_reading(port+R_GPIO_DIROffset) 	  	|=(1<<pin);
	hardWare_reading(port+R_GPIO_2mAOffset) 	    |=(1<<pin);  //= 0xFF;
  hardWare_reading(port+R_GPIO_ComOffset) 	    |=(1<<pin); 	//= 0xFF;
	hardWare_reading(port+R_GPIO_LockOffset) 	     = 0x4C4F434B;
  hardWare_reading(port+R_GPIO_DEnOffset) 		  |=(1<<pin);  //= 0xFF;
  //hardWare_reading(port+R_GPIO_PuDownOffset)      |=(1<<pin);  //= 0xFF;
}

/*==========================================================================
 *              all configration in one function of input gpio pin 
 *==========================================================================*/
void Config_Port_In(uint32_t port, uint8_t pin)
{
  hardWare_reading(port+R_GPIO_DIROffset) 		&=~(1<<pin);
	hardWare_reading(port+R_GPIO_PuUpOffset)    |=(1<<pin);  //= 0xFF;
  hardWare_reading(port+R_GPIO_ComOffset) 	  |=(1<<pin); 	//= 0xFF;
	hardWare_reading(port+R_GPIO_LockOffset) 	   = 0x4C4F434B;
  hardWare_reading(port+R_GPIO_DEnOffset) 	  |=(1<<pin);  //= 0xFF;
  //hardWare_reading(port+R_GPIO_2mAOffset) 	      |=(1<<pin);  //= 0xFF;
}

/*******************************************************
 * * sense for input switch
 * *****************************************************/
void Sens_Pin(uint32_t port , uint8_t pin, uint8_t cond)
{
  if(cond == Enable)
  {
      hardWare_reading(port+R_GPIO_Int_SensOffset) 	  	|=(1<<pin);
  }
  else if(cond == Disable)
  {
      hardWare_reading(port+R_GPIO_Int_SensOffset) 	  	&= ~(1<<pin);
  }
}

/*******************************************************
 * * edge for input switch
 * *****************************************************/
void Edge_Pin(uint32_t port , uint8_t pin, uint8_t cond)
{
  if(cond == Enable)
  {
      hardWare_reading(port+R_GPIO_Int_EdgeOffset) 	  	|=(1<<pin);
  }
  else if(cond == Disable)
  {
      hardWare_reading(port+R_GPIO_Int_EdgeOffset) 	  	&= ~(1<<pin);
  }
}

/*******************************************************
 * * event for input switch
 * *****************************************************/
void Event_Pin(uint32_t port , uint8_t pin, uint8_t cond)
{
  if(cond == Enable)
  {
      hardWare_reading(port+R_GPIO_Int_EventOffset) 	  	|=(1<<pin);
  }
  else if(cond == Disable)
  {
      hardWare_reading(port+R_GPIO_Int_EventOffset) 	  	&= ~(1<<pin);
  }
}

/*******************************************************
 * * mask for input switch
 * *****************************************************/
void Mask_Pin(uint32_t port , uint8_t pin, uint8_t cond)
{
  if(cond == Enable)
  {
      hardWare_reading(port+R_GPIO_Int_MaskOffset) 	  	|=(1<<pin);
  }
  else if(cond == Disable)
  {
      hardWare_reading(port+R_GPIO_Int_MaskOffset) 	  	&= ~(1<<pin);
  }
}
/*******************************************************
 * * clear for input switch
 * *****************************************************/
void Clear_Pin(uint32_t port , uint8_t pin, uint8_t cond)
{
  if(cond == Enable)
  {
      hardWare_reading(port+R_GPIO_Int_ClrOffset) 	  	|=(1<<pin);
  }
  else if(cond == Disable)
  {
      hardWare_reading(port+R_GPIO_Int_ClrOffset) 	  	&= ~(1<<pin);
  }
}
