#ifndef GPIO_H_
#define GPIO_H_


#include "HardWare_GPIO.h"
#include "HardWare_Type.h"


void Port_Dir(uint32_t port , uint8_t dir);
//void Pin_Dir(uint32_t port , uint8_t dir, uint8_t pin);
void Wr_Pin(uint32_t port , uint8_t pin , uint8_t value);


/*******************************************************
 *  Interrupt configration 
 * *****************************************************/
void Sens_Pin(uint32_t port , uint8_t pin, uint8_t cond); 
void Edge_Pin(uint32_t port , uint8_t pin, uint8_t cond);
void Event_Pin(uint32_t port , uint8_t pin, uint8_t cond);
void Mask_Pin(uint32_t port , uint8_t pin, uint8_t cond);
void Clear_Pin(uint32_t port , uint8_t pin, uint8_t cond);

void Config_Port_Out(uint32_t port, uint8_t pin);
void Config_Port_In(uint32_t port, uint8_t pin);
#endif
