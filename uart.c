#include "micr.h"  
void UART_Initialization()
{
double clc_div = (16000000.0    )  / (16 * 9600) ;	
 
  SYSCTL_RCGCUART_R |= 0x00000002; /* activate UART1 */
        SYSCTL_RCGCGPIO_R |= 0x00000004; /* activate PORTC */ 
    UART1_CTL_R &= ~0x00000001;      /* Disable UART1 enable */
        /* Adjust baudrate */
  UART1_IBRD_R =  (int) clc_div ;
  UART1_FBRD_R =  (int) ((clc_div - UART1_IBRD_R) * 64 + 0.5 );
        /* Adjust BIT_Data number (number of bits to be sent or received)*/
      	    UART1_LCRH_R |= (UART1_LCRH_R & UART_LCRH_WLEN_M )| UART_LCRH_WLEN_8;

        /* Enable the FIFO */
        UART1_LCRH_R |= UART_LCRH_FEN;

        /* Enable RXE, TXE, UARTEN */
        UART1_CTL_R |= UART_CTL_UARTEN | UART_CTL_TXE | UART_CTL_RXE;


        GPIO_PORTC_PCTL_R = (GPIO_PORTC_PCTL_R&0xFF00FFFF)+0x00220000;/* put 2 on pin 4, 5 to work as UART1 */
        GPIO_PORTC_AFSEL_R |= 0x0030 ;                        /* Enable the alternate functions on pin 4, 5 */
        GPIO_PORTC_DEN_R |= 0x0030 ;                          /* Enable Digital on pins 4, 5 */
        GPIO_PORTC_AMSEL_R &= ~ 0x0030;                  /* Disable Analog on pins 4, 5 */  
	
} 

uint8_t UART_receive()
 {
while((UART1_FR_R&UART_FR_RXFE) != 0) {} 	 
	 return((char)(UART1_DR_R&0x000000FF));
  
}
