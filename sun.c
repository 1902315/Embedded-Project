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

