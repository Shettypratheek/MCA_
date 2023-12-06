#include <lpc214x.h>
void AnalogWrite(unsigned int my_data);
void initpll();
void delay_ms(int count);
void delay_us(int count);


int main()
{
int i;
	
	initpll();
	PINSEL1 = (0x01<<20);
	while(1){
		for(i=0;i<50;i++){
		AnalogWrite(i);
			delay_us(200);
		}
		for(i=0;i<50;i++){
		AnalogWrite(1000-(i));
			delay_us(200);
		}
		}


	return 0;
}
void AnalogWrite(unsigned int my_data)
{

PINSEL1 |= 0x15480000;
	DACR=my_data<<6;
}
void initpll()
{
		PLL0CON=0x01;
    PLL0CFG=0x24;
    PLL0FEED=0xaa;
    PLL0FEED=0x55;
    while(!(PLL0STAT&(1<<10)));
    PLL0CON=0x03;
	VPBDIV=0x01;
    PLL0FEED=0xaa;
    PLL0FEED=0x55;
    
	
}
void delay_ms(int count)
{

	
	T0CTCR=0x0;                                 //Select Timer Mode
    T0TCR=0x00;                 //Timer off
    T0PR=59999;                 //Prescaler value for 1ms
    T0TCR=0x02;                 //Timer reset
    T0TCR=0x01;                 //Timer ON
    while(T0TC<count);           
    T0TCR=0x00;                 //Timer OFF
    T0TC=0;  
}
void delay_us(int count)
{

	T0CTCR=0x0;                                 //Select Timer Mode
    T0TCR=0x00;                 //Timer off
    T0PR=59;                 //Prescaler value for 1ms
    T0TCR=0x02;                 //Timer reset
    T0TCR=0x01;                 //Timer ON
    while(T0TC<count);           
    T0TCR=0x00;                 //Timer OFF
    T0TC=0;  
}