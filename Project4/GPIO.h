void digitalWrite(int portNum,int pinValue)
{
	if(portNum< 100)
	{
	IODIR0 |=(0x01 << portNum); // setting the particular pin has output
	if(pinValue==1)
		IOSET0 |=(0x01 << portNum); //setting the pin
	else if(pinValue==0)
		IOCLR0 |=(0x01 << portNum); //clearing the pin
	else 
		pinValue=0;
	}
	else{
		portNum=portNum-100;
		IODIR1 |=(0x01 << portNum); // setting the particular pin has output
	if(pinValue==1)
		IOSET1 |=(0x01 << portNum); //setting the pin
	else if(pinValue==0)
		IOCLR1 |=(0x01 << portNum); //clearing the pin
	else 
		pinValue=0;

	}

}
void portWrite(int portNr,int portValue)
{
	if(portNr<10)
	{
	if(portNr==0)
	else if(portNr==1)
	else if(portNr==2)
	}
	else if(portNr>=10)
	{}
}