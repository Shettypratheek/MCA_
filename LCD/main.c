#include <lpc214x.h>
#include <string.h>
#include "GPIO.h"
#include "header.h"


int main()
{
	unsigned char data1[]="Hello Everyone";
	unsigned char data2[]="Hello Everyone";
	int i=0,j=0;
	//initUART();
	initLCD();
	
	
	while(data1[i]!='\0')
		{
		LCDdata(data1[i]);
		
		i++;
	}
	LCDcommand(0xC0);
	while(data2[j]!='\0'){
		
		LCDdata(data2[j]);
		j++;
	}
	
return 0;
}