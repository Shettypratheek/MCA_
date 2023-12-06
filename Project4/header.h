void pinSelect(int pinNr,int spFunction)
{
	int bit0,bit1;
	
	//SETTING THE BIT FOR SPECIAL FUNCTION
	// spFunction CAN BE 0,1,2,3
	if(spFunction==0)
	{bit1=0;bit0=0;}
	else if(spFunction==1)
	{bit1=0;bit0=1;}
	else if(spFunction==2)
	{bit1=1;bit0=0;}
	else if(spFunction==3)
	{bit1=1;bit0=1;}
	//CHOOSING THE PINSEL
	if( pinNr>=0 & pinNr<=15 )
	{
			//SETTING THE SPECIAL FI=UNCTION FOR PINSELECT 0
		if(bit0==0)
			PINSEL0 &=~(0x01<<pinNr*2); //CHOOSING THE EVEN BITS
		else
			PINSEL0 |=(0x01<<pinNr*2);
		if(bit1==0)
			PINSEL0 &=~(0x01<<(pinNr*2+1)); //CHOOSING THE ODD BITS
		else
			PINSEL0 |=(0x01<<(pinNr*2+1));
	}
	else if(pinNr>=16 & pinNr<=31)
	{		
			pinNr=pinNr-16;
			//SETTING THE SPECIAL FI=UNCTION FOR PINSELECT 1
		if(bit0==0)
			PINSEL1 &=~(0x01<<pinNr*2);
		else
			PINSEL1 |=(0x01<<pinNr*2);
		if(bit1==0)
			PINSEL1 &=~(0x01<<(pinNr*2+1));
		else
			PINSEL1 |=(0x01<<(pinNr*2+1));
	}
	else if(pinNr>=116 & pinNr<=131)
	{	
		pinNr=pinNr-100-16;
			//SETTING THE SPECIAL FUNCTION FOR PINSELECT 2
		if(bit0==0)
			PINSEL2 &=~(0x01<<pinNr*2);
		else
			PINSEL2 |=(0x01<<pinNr*2);
		if(bit1==0)
			PINSEL2 &=~(0x01<<(pinNr*2+1));
		else
			PINSEL2 |=(0x01<<(pinNr*2+1));
	}
}
void delay()
{
 int i;
	for(i=0;i<3000000;i++);
	
	
}