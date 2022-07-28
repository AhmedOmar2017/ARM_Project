/*******************************************************************************
*====================== Auther: Ahmed Omar  ====================================
=======================   Date:21/7/2022    ====================================
* 			This program used to contral the blinked LED
* Sw1,sw2 in launch bad (tiva c)used  to set on and off delay in the running time
* The blue LED which is used to blink.
* Green and red LED to use inform the user are in set mode 
* Sw1 is used to enter the set mode and taggle between off and on delay and 
* exit for set mode and reset the on and off time 
* Sw2 to set values of on and off      
*******************************************************************************/

/*==========================================================================
 *      					   Include files
 *==========================================================================*/
#include"app.h"

/*==========================================================================
 *      					   Global Variables
 *==========================================================================*/	


uint8_t set 	= 0;
uint8_t On 		= 0;
uint8_t Off 	= 0;
uint32_t Ref	= 0;

int main (void)

{
/*==========================================================================
 *         intializing  pin 1, 2, and 3 in port F as output GPIO
 *==========================================================================*/	
	initPin(GPIO_PF, 1,OUTPUT);
	initPin(GPIO_PF, 2,OUTPUT);
	initPin(GPIO_PF, 3,OUTPUT);

/*==========================================================================
 *       intializing  pin 0 and 4 in port F as Input GPIO
 *==========================================================================*/	
	
	initPin(GPIO_PF, 0,INPUT);
	initPin(GPIO_PF, 4,INPUT);


/*==========================================================================
 *             intializing  pin 0  in port F as Interrupt
 *==========================================================================*/		
	Sens_Pin(GPIO_PF, 0,Disable);
	Edge_Pin(GPIO_PF, 0,Disable);
	Event_Pin(GPIO_PF, 0,Disable);
	Clear_Pin(GPIO_PF, 0,Enable);
	Mask_Pin(GPIO_PF, 0,Enable);

/*==========================================================================
 *             intializing  pin 4  in port F as Interrupt
 *==========================================================================*/	
	Sens_Pin(GPIO_PF, 4,Disable);
	Edge_Pin(GPIO_PF, 4,Disable);
	Event_Pin(GPIO_PF, 4,Disable);
	Clear_Pin(GPIO_PF, 4,Enable);
	Mask_Pin(GPIO_PF, 4,Enable);
	
	
		
/*==========================================================================
 *        Intializing  priorty for GPIO prot F and enable interrupt 
 *		  					priorty of port F is 1
 *==========================================================================*/			
	Periorty_NVIC(Interrupt_28_31_Periorty_Offset, 0x00200000);		
	Enable_NVIC(Interrupt_31_Set_Offset,30);
		
		
/*==========================================================================
 *        		Intializing  the timer 1 and enable interrupt 
 *==========================================================================*/			
	InitTimer(TIMER_1_D, T16, Periodic, 250, 200, Enable, Enable); 
	Enable_NVIC(Interrupt_31_Set_Offset, 21);
	

	
    while(1)
    {    
    }
}


/*==========================================================================
 *      					  Timer handler interrupt
 *==========================================================================*/

void TIMER1A_Handler(void)
{
	Ref = Set_value_Blinking(GPIO_PF,On, Off, Ref);
	Int_Clr_Timer(TIMER_1_D, Enable);
}





/*==========================================================================
 *      					  GPIO port F handler interrupt
 *==========================================================================*/
void GPIOF_Handler(void)
{
	
	if(Status_Interrupt( GPIO_PF) & 0x01 && set == 0)
	{
		On = 0;
		Off= 0;
		Clear_Pin(GPIO_PF, 0,Enable);
		Wr_Pin(GPIO_PF,1,HIGH);
		Wr_Pin(GPIO_PF,3,LOW);
		set++;
		
	}
	if(Status_Interrupt( GPIO_PF) & 0x01 && set <= 2 && set > 0)
	{
		Clear_Pin(GPIO_PF, 0,Enable);
		Wr_Pin(GPIO_PF,1,HIGH);
		Wr_Pin(GPIO_PF,3,LOW);
		set++;
	}
	else if(Status_Interrupt( GPIO_PF) & 0x01 && set == 3)
	{
		Clear_Pin(GPIO_PF, 0,Enable);
		set = 0;
		Wr_Pin(GPIO_PF,1,LOW);
	
	}
	
	if(Status_Interrupt( GPIO_PF) & 0x10 && set == 1)
	{
		Clear_Pin(GPIO_PF, 4,Enable);
		Wr_Pin(GPIO_PF,3,HIGH);
		On++;
		
	}
	else if(Status_Interrupt( GPIO_PF) & 0x10 && set == 2)
	{
		Clear_Pin(GPIO_PF, 4,Enable);
		Wr_Pin(GPIO_PF,3,HIGH);
		Off++;
		
	}
			
}
		
