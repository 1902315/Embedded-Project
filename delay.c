
void SysTick_Wait1m(void){   /// wait 1 milli sec for one time
 NVIC_ST_RELOAD_R = 16000-1; // number of counts to wait
 NVIC_ST_CURRENT_R = 0; // any value written to CURRENT clears
 while((NVIC_ST_CTRL_R&0x00010000)==0){ // wait for count flag
 }
}


void SysTick_Wait1ms(unsigned long delay1)  // wait (delay1) milli 
{
 unsigned long i;
 for(i=0; i<delay1; i++)
{
SysTick_Wait1m() ; // wait 1ms (assumes 16 MHz clock)
 }
}
