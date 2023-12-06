#include <LPC214x.h>
#include "GPIO.h"
#include "header.h"

int main(void)
{

	initpll();
	
	while(1)
	{
	digitalWrite(116,1);
		delay_ms(100);
	digitalWrite(116,0);
		delay_ms(100);
		
}


	return 0;
}