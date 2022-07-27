#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "HardWare_GPIO.h"
#include "HardWare_Type.h"

#define R_INTERRUPT             0xE000E000



#define Interrupt_31_Set_Offset  	  0x100
#define Interrupt_63_Set_Offset  	  0x104
#define Interrupt_95_Set_Offset   	  0x108
#define Interrupt_127_Set_Offset   	  0x10C


#define Interrupt_31_Clear_Offset  	  0x180
#define Interrupt_63_Clear_Offset     0x184
#define Interrupt_95_Clear_Offset     0x188
#define Interrupt_127_Clear_Offset    0x18C

#define Interrupt_28_31_Periorty_Offset  0x41C      // PortF
#define Interrupt_20_23_Periorty_Offset  0x414      // timerA



void Periorty_NVIC(uint32_t adr, uint32_t value);
void Enable_NVIC(uint32_t adr, uint8_t bit);
void Disable_NVIC(uint32_t adr, uint8_t bit);
volatile uint32_t Status_Interrupt(uint32_t adr);
#endif