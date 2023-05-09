
#include "micr.h"
void SysTick_Init(void){
NVIC_ST_CTRL_R &= ~(0x00000001); // disable SysTick during setup
 NVIC_ST_RELOAD_R = 0x00FFFFFF; // maximum reload value
 NVIC_ST_CURRENT_R = 0; // any write to current clears it
 NVIC_ST_CTRL_R = 0x00000005; // enable SysTick with core clock
}

 
void SysTick_Wait(void){    /// wait 1 sec  for one time
 NVIC_ST_RELOAD_R = 16000000-1; // number of counts to wait
 NVIC_ST_CURRENT_R = 0; // any value written to CURRENT clears
 while((NVIC_ST_CTRL_R&0x00010000)==0){ // wait for count flag
 }
}

void SysTick_Wait1s(unsigned long delay1) /// wait (delay1) sec 
{
 unsigned long i;
 for(i=0; i<delay1; i++)
{
 SysTick_Wait(); // wait 1s (assumes 16 MHz clock)
 }
}
