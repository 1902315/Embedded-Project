#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdarg.h>
#include <string.h>
#include "math.h"
#include "tm4c123gh6pm.h"
#define leds  0x0E
#define RED     0x02           
#define YELLOW    0x0A           
#define GREEN   0x08 
#define PI 3.142857
typedef char * string1;
void gpio_initalization (void) ;
void UART_Initialization(void) ;
uint8_t UART_receive() ;
void ledred(void);
void ledgreen(void);
void ledyellow(void);
void readGPSs( volatile double arr[]) ;
long double dis(volatile double latitude_2, volatile double logitude_2) ;
string1 toString(double num,int decimalLength);
void UART0_Init(void) ;
void UART_OutChar(unsigned char data) ;
void UART_OutString(char *pt);
void SysTick_Init(void) ;
void SysTick_Wait(void);
void SysTick_Wait1s(unsigned long delay1) ;
void SysTick_Wait1m(void);
void SysTick_Wait1ms(unsigned long delay1) ;


