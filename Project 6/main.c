#include <lpc214x.h>
#include <string.h>
#include "header.h"

int main(void)
{
 int i;
	unsigned char data[6]="Shetty";
	while(data[i++]!='\0')
		lcd_data(data[i]);
	return 0;

}