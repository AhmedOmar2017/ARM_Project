#ifndef TIMER_H_
#define TIMER_H_

#include "HardWare_GPIO.h"
#include "HardWare_Type.h"


#ifndef Enable
#define Enable 1
#endif

#ifndef Disable
#define Disable 0
#endif

#ifndef T16
#define T16 0x4
#endif

#ifndef T32
#define T32 0x0
#endif

#ifndef Periodic
#define Periodic 0x2
#endif
#ifndef OShot
#define OShot 0x1
#endif


void Enble_Timer(uint32_t adr);
void Disable_Timer(uint32_t adr);
void Cnfig_Timer(uint32_t adr, uint8_t val);
void Mod_Timer(uint32_t adr, uint8_t val);
void Prsc_Timer(uint32_t adr, uint8_t val);
void Prload_Timer(uint32_t adr, uint8_t val);
void Int_Clr_Timer(uint32_t adr, uint8_t val);
void Int_Msk_Timer(uint32_t adr, uint8_t val);

#endif