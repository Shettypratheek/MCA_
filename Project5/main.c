#include <LPC214x.h>

int main(void)
{
	int i;
	
	IODIR0 |=(0X01<<10)|(0X01<<9);
	IODIR0 &=~(0X01<<5);
	while(1)
	{
		if(IO0PIN & (0X01<<5))
		{
		IO0SET =(0X01<<10);
		for(i=0;i<400000;i++);
		IO0SET =(0X01<<9);
		for(i=0;i<200000;i++);
		IO0CLR =(0X01<<9);
		for(i=0;i<200000;i++);
		IO0CLR =(0X01<<10);
		for(i=0;i<400000;i++);
		}
	}
	
	return 0;
}