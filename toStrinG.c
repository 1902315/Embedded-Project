#include "micr.h"  
typedef char * string1;
char str[7];
 string1 toString(double num,int decimalLength)
{
	int i;	
	int j;
	int r;
	int n;
	int m;
	double num_fractions;
	double num_int;
	int count;
	
	int arrr[10];
	i = 0;
	
	if(num < 1){return "0.00";}

	num_fractions = num -(int) (num);
	num_int = (int) num;
	while ((9 - (int)(num_int))  <= 0)
	{
		if (i == 0)
		{
			num_int = num_int / pow(10, i);
			arrr[i] = (int) (num_int) % 10;
		}
		else
		{
			num_int = num_int / pow(10, 1);
			arrr[i] = (int) (num_int) % 10;
		}
		i++;
	} 
	count = i;
	for (j = 1; j < 5; j++)
	{
		num_fractions = num_fractions * pow(10, 1);
		arrr[i] = (int) (num_fractions) % 10; 
		i++;
	}

	n = 0; 
	for (r = (count - 1); r >= 0; r--) 
	{
		str[n] = (char)arrr[r] + 48; 
		n++;
	
	}
	
	if(n == 0){
		return "0.00";
	}
	
	str[n] = '.';
	n++;
	for (m = count; m < (count + decimalLength); m++) 
	{
		if(arrr[m] >= 0 && arrr[m] <= 9){
			str[n] = (char)arrr[m] + 48; 
			n++;
		}
	}

	str[n] = '\0';
	return str;
}
