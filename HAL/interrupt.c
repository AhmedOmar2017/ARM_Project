#include "interrupt.h"
#include "systemContral.h"


void Enable_NVIC(uint32_t adr, uint8_t bit)
{
    hardWare_reading(adr+R_INTERRUPT) |= (1<<bit);
}
void Disable_NVIC(uint32_t adr, uint8_t bit)
{
    hardWare_reading(adr+R_INTERRUPT) |= (1<<bit);
}
void Periorty_NVIC(uint32_t adr, uint32_t value) 
{
		hardWare_reading(adr+R_INTERRUPT) |= value;
}

volatile uint32_t Status_Interrupt(uint32_t adr)
{
	return hardWare_reading(R_GPIO_Int_StatOffset+adr);
}
	
