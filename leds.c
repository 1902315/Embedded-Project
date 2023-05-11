#include "micr.h"
void gpio_initalization (void)
{
SYSCTL_RCGCGPIO_R |= 0x00000020; // activate Port F 
while((SYSCTL_PRGPIO_R&0x00000020) == 0){};
GPIO_PORTF_LOCK_R = 0x4C4F434B;
GPIO_PORTF_CR_R = 0x1F;
GPIO_PORTF_AMSEL_R = 0x00;  
	 GPIO_PORTF_AFSEL_R = 0x00;
	GPIO_PORTF_CR_R = leds; // allow changes to PF3-1 
GPIO_PORTF_DIR_R = leds; //  PF3-1 out 
GPIO_PORTF_DEN_R = leds; // digital I/O 
	
}
void ledred(void) 
{
GPIO_PORTF_DATA_R	=RED ;
}
void ledyellow(void) 
{
GPIO_PORTF_DATA_R=YELLOW	;
}
void ledgreen(void) 
{
GPIO_PORTF_DATA_R	=GREEN ;
}

