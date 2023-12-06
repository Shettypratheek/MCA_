#include <lpc214x.h>
#define bit(x) (1<<x)

void delay()
{
	int i;
	for(i=0;i<200000;i++);
	
	
}

void lcd_cmd(unsigned char a)  //Function to send COMMAND into the LCD
{
    IO1PIN&=0x00;             // Pins of Port0 set to 0    
    IO1PIN|=(a<<16);          // Shift data to Port P0.16
    IO1CLR|=bit(25);          //To send the COMMANDS into the LCD, Register Select has to be 0 ; rs=0
    IO1CLR|=bit(26);          //For writing into the LCD rw=0
    IO1SET|=bit(27);          //To latch the command/data sent into the LCD a high to low pulse is given; en=1
    delay();                  //Call a delay
    IO1CLR|=bit(27);          //en=0
}
void lcd_init()              //LCD initialization function
{
    lcd_cmd(0x30);           //8-bit mode
	  lcd_cmd(0x38);           //activate two rows of LCD crystal
    lcd_cmd(0x0c);           //Display ON Cursor OFF
		lcd_cmd(0x06);           //turn on display , turn off cusor
    lcd_cmd(0x01);           //clear the screen
    lcd_cmd(0x80);           //set the cursor to the beginning of the first line
}

void lcd_data(unsigned char b)  //Function to send DATA into the LCD
{
    IO1PIN&=0x00;              // Pins of Port0 set to 0
    IO1PIN|=(b<<16);           // Shift data to Port P0.16
    IO1SET|=bit(25);           //To send the DATA into the LCD, Register Select has to be 1 ; rs=1
    IO1CLR|=bit(26);           //For writing into the LCD rw=0
    IO1SET|=bit(27);          //To latch the command/data sent into the LCD a high to low pulse is given; en=1
    delay();                  //Call delay
    IO1CLR|=bit(27);          //en=0
}
