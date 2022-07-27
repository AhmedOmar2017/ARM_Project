#include "TIMER.h"

void Disable_Timer(uint32_t adr)
{
    hardWare_reading(adr+R_TIMER_CTRLOffset) &= ~(1<<0);
}
void Enble_Timer(uint32_t adr)
{
    hardWare_reading(adr+R_TIMER_CTRLOffset) |= (1<<0);
}

void Cnfig_Timer(uint32_t adr, uint8_t val)
{
    hardWare_reading(adr+R_TIMER_CFGOffset) = val;
}

void Mod_Timer(uint32_t adr, uint8_t val)
{
    hardWare_reading(adr+R_TIMER_A_MODOffset) = val;
}

void Prsc_Timer(uint32_t adr, uint8_t val)
{
    hardWare_reading(adr+R_TIMER_A_PRSCOffset) = val-1;
}

void Prload_Timer(uint32_t adr, uint8_t val)
{
    hardWare_reading(adr+R_TIMER_A_ILOffset) = val-1;
}

void Int_Clr_Timer(uint32_t adr, uint8_t val)
{
    hardWare_reading(adr+R_TIMER_ICOffset) = (val<<0);
}
void Int_Msk_Timer(uint32_t adr, uint8_t val)
{
    hardWare_reading(adr+R_TIMER_IMOffset) = (val<<0);
}