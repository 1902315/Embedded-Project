#include "micr.h"
#include "string.h"
volatile double DISTANCE = 0.0;
volatile double DISTANCE2 = 0.0;
static volatile double arr[4];
static volatile double arr1[2];
static volatile uint8_t k = 0;
static volatile uint8_t i = 0;
void readGPSs( volatile double arr[])
{
 char x,GPSValues[100] , interpretValue[12][20],*token,*token1,*token2, *token3,*token4,*token5,*token6 ;
 double latitude = 0.0, longitude = 0.0, sec = 0.0, result = 0.0, min = 0.0;

	int j=0,deg,latitudeint,latitudefraction ,longitudeint,longitudefraction ;
    do
    {
	x=UART_receive() ;
			switch (x)
        {
        case '$':
				i++;
            break;
        case 'G':
				i = i==1?2:0;
            break;
        case 'P':
				i = i==2?3:0;
            break;
        case 'R':
            i = i==3?4:0;
            break;
        case 'M':
				i = i==4?5:0;
            break;
        case 'C':
				i = i==5?6:0;
				break;
        case ',':
				if(i != 6) break;
				i=7;

				x=UART_receive() ;
				while (x != '*') {
	GPSValues[j] = x;
			x =  UART_receive();
					j++;
            }

						j=0;
						  token = strtok(GPSValues, ","); // strtok function in c
    				while (token != NULL) {
			strcpy(interpretValue[j], token); //copy what is in token into interpretValue
                token = strtok(NULL, ",");
                j++;

					  }

						token1 = strtok(interpretValue[2] , ".") ;
						token2 = strtok(NULL , ".") ;
						token3 = strtok(interpretValue[4] , ".") ;
						token4 = strtok(NULL , ".") ;
					token5 = strtok(token3, "0") ;
						token6 = strtok(NULL, ".") ;


		  if (strcmp(interpretValue[1], "A") == 0)
            {
					latitudeint = atoi(token1);
latitudefraction=atoi(token2);
							longitudeint = atoi(token5);
							longitudefraction = atoi(token4);
latitude=latitudeint+(double)((double)latitudefraction)/((double)100000);
							longitude=longitudeint+(double)((double)longitudefraction)/((double)100000);
							deg = latitude / 100;
               min = latitude - (double)(deg * 100);
							sec = min / 60.00;
                result = deg + sec;
               arr[k] = result;//save the latitude reading of nth point 							
	arr1[0]=arr[k]	 ;							
k++;	
                deg = longitude / 100;
                min = longitude - (double)(deg * 100);
                sec = min / 60.00;
                result = deg + sec;
							arr[k] = result;//save the longitude reading of nth point 
		arr1[1]=arr[k]	 ;	              
	k++;
			SysTick_Wait1ms(5);
			 if (k == 4)
                {
                    if((int)arr[2] > 29 && (int)arr[3] > 30){
											
										DISTANCE= ( (arr[2]-arr[0]) * (arr[2]-arr[0]) ) ; 
											DISTANCE2= ( (arr[3]-arr[1]) * (arr[3]-arr[1]) ) ;
											DISTANCE=DISTANCE+DISTANCE2 ;
								DISTANCE= sqrt(DISTANCE) ;
											DISTANCE=DISTANCE *110000 ;					
											arr[0] = arr[2];
                        arr[1] = arr[3];
                    }
                    k = 2;		
                }

            }
	else
	{
		i=0 ;
	}								
						
						
 break;
        default:
            i = 0;
            break;
				}				
	} 	while (i != 7);
}


long double dis(volatile double latitude_2, volatile double logitude_2){
		int R=6371000; //Earth radius 
    double phi1 = arr1[0]*PI/180; 
    double phi2 = latitude_2*PI/180;
    double deltaphi = phi2-phi1 ;
    double lambda = (logitude_2-arr1[1])*PI/180;
    double a = sin(deltaphi/2)*sin(deltaphi/2)+cos(phi1)*cos(phi2)*sin(lambda/2)*sin(lambda/2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
  double d = R*c;
return d ;
}


