void LCDcommand(unsigned char cmd);
void LCDdata(unsigned char data);
void initLCD();


void LCDcommand(unsigned char cmd)
{
	IODIR1 |=(0xFFFF0000);
	//IO1PIN&=0x00;
		

	IOCLR1 |=(0X01<<16);
	IOCLR1 |=(0X01<<17);
	IO1PIN |=(cmd<<24);
	IOSET1 |=(0X01<<18);
	delay();
	IOCLR1 |=(0X01<<18);
	delay();

}
void LCDdata(unsigned char data)
{
	//IO1PIN&=0x00;
	IODIR1 |=(0xFFFF0000);
	
	IOSET1 |=(0X01<<16);
	IOCLR1 |=(0X01<<17);
	IO1PIN |=(data<<24);
	IOSET1 |=(0X01<<18);
	delay();
	IOCLR1 |=(0X01<<18);
	delay();
}
void initLCD()
{
	LCDcommand(0x038);
	LCDcommand(0x0C);
	LCDcommand(0x06);
	LCDcommand(0x01);
	LCDcommand(0x080);

}


