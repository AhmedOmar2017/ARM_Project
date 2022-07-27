/*******************************************************************************
*====================== Auther: Ahmed Omar  ====================================
=======================   Date:17/7/2022    ====================================
============   Here I define the addresses and offsets  ========================
*******************************************************************************/

#ifndef HW_MCU_H_
#define  HW_MCU_H_
#include <stdint.h>

/*==========================================================================
 *                 defination for addrasses for contral
 *==========================================================================*/
#define systemCtrl  0x400FE000
#define Hw_Mask     0x3FC

/*==========================================================================
 *                 defination for interrupt addrasse 
 *==========================================================================*/
#define R_INTERRUPT             0xE000E000
/*******************************************************
 * ***************  APB GPIO ***************************
 *  datasheet tiva c page   658:659
 *******************************************************/



#define GPIO_PA 0x40004000
#define GPIO_PB 0x40005000
#define GPIO_PC 0x40006000
#define GPIO_PD 0x40007000
#define GPIO_PE 0x40024000
#define GPIO_PF 0x40025000





/******************************************************
 * ***** define the offsets GPIO
 ******************************************************/

#define R_GPIO_DataOffset       0x000     // page 662
#define R_GPIO_DIROffset        0x400     // page 663
#define R_GPIO_AFSOffset        0x420     // page 671
#define R_GPIO_2mAOffset        0x500     // page 673
#define R_GPIO_4mAOffset        0x504     // page 674
#define R_GPIO_8mAOffset        0x508     // page 675
#define R_GPIO_OpenDrainOffset  0x50C     // page 676
#define R_GPIO_PuUpOffset       0x510     // page 677
#define R_GPIO_PuDownOffset     0x514     // page 678
#define R_GPIO_DEnOffset        0x51c     // page 682
#define R_GPIO_DMAOffset        0x534     // page 691
#define R_GPIO_LockOffset       0x520     // page 684
#define R_GPIO_ComOffset        0x524     // page 685
#define R_GPIO_ClkGatingOffset  0x608     // page 340

/******************************************************
 * ***** define the offsets Interrupt
 ******************************************************/


#define R_GPIO_Int_SensOffset   0x404     // page 664
#define R_GPIO_Int_EdgeOffset   0x408     // page 665
#define R_GPIO_Int_EventOffset  0x40C     // page 666
#define R_GPIO_Int_MaskOffset   0x410     // page 667
#define R_GPIO_Int_ClrOffset    0x41C     // page 670
#define R_GPIO_Int_StatOffset   0x418     // page 669

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


/******************************************************
 * *******      TIMERS
 * ****************************************************/

//  16/32-bit Timer 0: 0x4003.0000
#define TIMER_0_D  0x40030000
//  16/32-bit Timer 1: 0x4003.1000
#define TIMER_1_D  0x40031000
//  16/32-bit Timer 2: 0x4003.2000
#define TIMER_2_D  0x40032000
//  16/32-bit Timer 3: 0x4003.3000
#define TIMER_3_D  0x40033000
//  16/32-bit Timer 4: 0x4003.4000
#define TIMER_4_D  0x40034000
//  16/32-bit Timer 5: 0x4003.5000
#define TIMER_5_D  0x40035000

/*****************************************************
 * *** TIMER CONFIGRATION OFFSETS
 * ***************************************************/
#define R_TIMER_CFGOffset               0x000     // page 727
#define R_TIMER_A_MODOffset             0x004     // page 729
#define R_TIMER_B_MODOffset             0x008     // page 729
#define R_TIMER_CTRLOffset              0x00C     // page 737
#define R_TIMER_IMOffset                0x018     // page 745
#define R_TIMER_ICOffset                0x024     // page 753
#define R_TIMER_A_ILOffset              0x028     // page 756
#define R_TIMER_B_ILOffset              0x02C     // page 757
#define R_TIMER_A_MTCHOffset            0x030     // page 758
#define R_TIMER_B_MTCHOffset            0x034     // page 759
#define R_TIMER_A_PRSCOffset            0x038     // page 760
#define R_TIMER_B_PRSCOffset            0x03C     // page 761
#define R_TIMER_A_PSMOffset             0x040     // page 762
#define R_TIMER_B_PSMOffset             0x044     // page 762
#define R_TIMER_ClkGatingOffset         0x604     // page 338


#endif