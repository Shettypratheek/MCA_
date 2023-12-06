#include <lpc214x.h>
//#include "GPIO.h"


void initpll();
void delay(unsigned int count);
void initUART();
void senduart(unsigned char data);
unsigned char receiveuart();
void LCDcommand(unsigned char data);
void LCDdata(unsigned char data);
void initLCD();


void initpll()
{
	PLL0CON=0X01;
	PLL0CFG=0X24;
	PLL0FEED=0XAA;
	PLL0FEED=0X55;
	while((PLL0STAT & (0X01<<10))==0);
	PLL0CON=0X03;
	VPBDIV=0X01;
	PLL0FEED=0XAA;
	PLL0FEED=0X55;
}

void delay(unsigned int count)
{
	T0CTCR=0X00;
	T0TCR=0X02;
	T0TC=0X0;
	T0PR=59999;
	T0TCR=0X01;
	while(T0TC <count);
	T0TCR=0X00;
	T0TC=0;

}

void initUART()
{
	PINSEL0 =0X05;
	U0LCR =0X83;
	U0DLL=0X87;
	U0DLM=0X01;
	U0LCR=0X03;
}
void senduart(unsigned char data)
{
	U0THR=data;
	while((U0LCR & (0X01<<5))==0);

}
unsigned char receiveuart()
{
	unsigned char data;
	while((U0LCR &(0X01))==0);
	data=U0RBR;
	return data;
}
void LCDcommand(unsigned char mycmd)
{
	
	pinWrite(117,0); //MAKING THE RS 0 FOR SENDING THE COMMAND
	pinWrite(118,0); //MAKING RW HAS ZERO
	
	
	portWrite(13,mycmd); //SENDING THE COMMAND TO THE PORT 1 24 TO 31
	
	pinWrite(119,1);//MAKING THE ENABLE HIGH AND LOW
		delay(50);
	pinWrite(119,0);
		
}
void LCDdata(unsigned char mydata)
{
	pinWrite(117,1); //MAKING THE RS 0 FOR SENDING THE COMMAND
	pinWrite(118,0); //MAKING RW HAS ZERO
	
	
	portWrite(13,mydata); //SENDING THE COMMAND TO THE PORT 1 24 TO 31
	
	pinWrite(119,1);//MAKING THE ENABLE HIGH AND LOW
		delay(50);
	pinWrite(119,0);
		
}
void initLCD()
{
	LCDcommand(0X038);
	LCDcommand(0X0C);
	LCDcommand(0X06);
	LCDcommand(0X01);
	LCDcommand(0X80);
}