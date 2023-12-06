void pinWrite(int pin,int value);
void portWrite(int portNr,int value);


void portWrite(int portNr,int value)
{
	int i;
	
if(portNr<10)
{
if(portNr==0)
{
	for(i=0;i<8;i++)
	{
		if((value & (0x01<<i))==0)
			pinWrite(i,0);
		else
			pinWrite(i,1);
	}
}
	
else if(portNr==1)
{
	for(i=0;i<8;i++)
	{
		if((value & (0x01<<i))==0)
			pinWrite(i+8,0);
		else
			pinWrite(i+8,1);
	}
	
}
	
else if(portNr==2)
{
for(i=0;i<8;i++)
	{
		if((value & (0x01<<i))==0)
			pinWrite(i+16,0);
		else
			pinWrite(i+16,1);
	}
}
	
else if(portNr==3)
{
for(i=0;i<8;i++)
	{
		if((value & (0x01<<i))==0)
			pinWrite(i+24,0);
		else
			pinWrite(i+24,1);
	}
}
	
else{}
}
	
else
{
 if(portNr==12)
 {
 for(i=0;i<8;i++)
	{
		if((value & (0x01<<i))==0)
			pinWrite(i+116,0);
		else
			pinWrite(i+116,1);
	}
 }
 else if(portNr==13)
 {
	 for(i=0;i<8;i++)
	{
		if((value & (0x01<<i))==0)
			pinWrite(i+124,0);
		else
			pinWrite(i+124,1);
	}
 
 }
}

}
void pinWrite(int pin,int value)
{
	
 if(pin<100)
 {
	 IODIR0  |=(0X01<<pin);
		
	 if(value==0)
		 IOCLR1 |=(0X01<<pin);
	 else
		 IOSET1 |=(0X01<<pin);
 }
	 
 else if(pin >100)
 {
 pin=pin-100;
	IODIR1 |=(0X01<<pin);
	 if(value==0)
		 IOCLR1 |=(0X01<<pin);
	 else
		 IOSET1 |=(0X01<<pin);
 }
}