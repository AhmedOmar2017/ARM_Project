#include "GPIO.h"


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
/*
void Configration_Pin(uint32_t port , uint8_t dir, uint8_t pin)
{
    if(dir == INPUT)
    {
      hardWare_reading(port+R_GPIO_DIROffset) 		= pin;
    }
    else if(dir == OUTPUT)
    {
       hardWare_reading(port+R_GPIO_DIROffset) 		= pin;
    }
}
*/
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


void Config_Port_Out(uint32_t port, uint8_t pin)
{
  hardWare_reading(port+R_GPIO_DIROffset) 	  	|=(1<<pin);
	hardWare_reading(port+R_GPIO_2mAOffset) 	    |=(1<<pin);  //= 0xFF;
  hardWare_reading(port+R_GPIO_ComOffset) 	    |=(1<<pin); 	//= 0xFF;
	hardWare_reading(port+R_GPIO_LockOffset) 	     = 0x4C4F434B;
  hardWare_reading(port+R_GPIO_DEnOffset) 		  |=(1<<pin);  //= 0xFF;
  //hardWare_reading(port+R_GPIO_PuDownOffset)      |=(1<<pin);  //= 0xFF;
}


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
 * * sense
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
 * * edge
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
 * * event
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
 * * mask
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
 * * clear
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
