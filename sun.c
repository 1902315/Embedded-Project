#include "micr.h"
extern double DISTANCE;
extern double DISTANCE2;
void SystemInit(void) {}
double readings[4];
static volatile double startAndEnd[4];
	volatile long double x ; 
	volatile double xx =0.0 ;
int main()
{
	bool print=1;
	char y,*c,*z,*u ;
UART0_Init() ;
	UART_Initialization() ;
	gpio_initalization() ;
	SysTick_Init() ;
	SysTick_Wait1s(5) ;

	readGPSs(startAndEnd);	

	c=toString(startAndEnd[0],4) ;
	UART_OutString("-----lat of first  point : ") ;
	UART_OutString(c) ;
	UART_OutString("              ") ;

 z=toString(startAndEnd[1],4) ;	
	UART_OutString("   long of first point : ") ;
UART_OutString("           ") ;
	UART_OutString(z) ;

//		SysTick_Wait1s(1);
	while(1)
{
SysTick_Wait1s(2);
//																		y=UART_receive() ;
	//																UART_OutChar(y) ;

	readGPSs(readings) ;	
		
	SysTick_Wait1ms(2);

	/*
	c=toString(readings[0],5) ;	
	UART_OutString("   lat of current  point : ") ;
UART_OutString("           ") ;
	UART_OutString(c) ;
z=toString(readings[1],5) ;	
		UART_OutString("   long of current  point : ") ;
UART_OutString("           ") ;
	UART_OutString(z) 	;
	*/
	
	if (DISTANCE<5)
	{
xx+=DISTANCE ;
	}
x=dis( 30.06544 , 31.27718) ; 
		
		if(x>5){
			ledred();
			print=1;
		}
		else
		{
		if(print==1){
			ledyellow();
		}
SysTick_Wait1s(4) ;
			ledgreen();
SysTick_Wait1s(2) ;
			if(prnt==1){
				readGPSs(startAndEnd);
				c=tostring(startAndEnd[0],5) ;
				UART_OutString("   lat of last point : ") ;
				UART_OutString(c) ;
	UART_OutString("   long of last point : ") ;
				z=toString(startAndEnd[1],5) ;	
								UART_OutString(z) ;
	c=toString(xx,4) ;
					UART_OutString("   TOTAL DISTANCE IS  : ") ;
UART_OutString(c) ;
	UART_OutString("   ") ;
print=0;
				SysTick_Wait1s(2) ;
			}
		
		}
		
 /*
	 u=toString(x,5) ;
	UART_OutString("   linear distance is : ") ;
UART_OutString(u) ;
UART_OutString("           ") ;	
	*/

	
}
}




