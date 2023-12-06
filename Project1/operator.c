#include "header.h"

void initpll(void)
{
	PLL0CON=0X01; //Enable the pll
	PLL0CFG=0X24; //giving the M value has 4 and p value has 2;
	PLL0FEED=0XAA;
	PLL0FEED=0X55; //applying the feed sequence
	while((PLL0STAT && (0X01<<10))==0);
	PLL0CON=0X03; //connect the pll to processor
	VPBDIV =0X01; //giving the pll same clock has processor clock
	PLL0FEED=0XAA;
	PLL0FEED=0X55; //applying the feed sequence
}
void delay(int value)
{
	T0CTCR=0X00; //selecting the timer mode
	T0TCR=0X02; // RESET THE TIMER
	T0PR =59999; //PRESCALR VALUE FOR 1MS DELAY
	T0TCR=0X01;
	while(T0TC<value);
	T0TCR=0X00; //DISABLE THE TIMER
}