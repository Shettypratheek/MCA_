#include <lpc214x.h>
#include "header.h"
#include "LCD.h"
int main()
{
	//pinSelect(0,1);
	//pinSelect(1,1);
	//pinSelect(25,2);
	//pinSelect(8,1);
	//pinSelect(116,2);
	unsigned char data[]="shetty";
	int i;
	initLCD();
	IODIR1 |=(0xFFFF0000);
	for(i=0;i<8;i++){
		LCDdata(data[i]);
	}
	
	while(1)
	{
		IOSET1 |=0x01<<19;
	delay();
		IOCLR1 |=0x01<<19;
		delay();
}
	return 0;
}