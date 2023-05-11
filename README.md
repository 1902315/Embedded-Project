##GPS Tracking System

We stored and showed the coordinates of the start point , And After reaching the destination point, we stored the coordinates 
of the end point and calculated the total distance that was taken by the user and there is no big difference/deviation (error margin 
should be <= 5%) between the calculated distance and the one shown by google maps , we also used displacment function to find the linear distance between the point that the gps sensor reads and the destination point to translate the output as :
Stage 1: The built-in LED will be turned on(green) when the target  destination is reached.
 Stage 2: The built-in LED will be turned on(yellow) when the target 
destination is about to be reached < 5 meters.
{if the diplacment is less the 5 meters the led turns yellow then delay then turns green and keep the green led only if the distance didn't change to be more than 5 meters }
 Stage 3: The built-in LED will be turned on(red) when the target destination is far away by distance > 5 meters.
 CONTRIBUTIONS :

              gps.c : Emad medhat 2000324 and Peter ibrahim 2000270
              delay.c: Youssef Samir 1901012  and Abdullah sadek 2101719
              uart.c: Saleh Ehab 18W3168
              Uhart.c: mostafa akram 2001111
              toStrinG.c: philopater Zakaria 2001320
              leds.c: Ahmed Kamel 2001692
              sun.c (main): Ahmed Mohamed 1902315 and Seif El dein Ashraf 1901249
