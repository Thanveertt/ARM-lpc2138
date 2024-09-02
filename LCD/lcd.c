#include<lpc21xx.h>
void delay();
void cmd(char a);
void data(char b);            
void main()
{
PINSEL0=0X00000000;
PINSEL1=0X00000000;
IO0DIR=0XFFFFFFFF;

	cmd(0x38);
	cmd(0x01);
	cmd(0x06);
	cmd(0x0E);
	cmd(0x80);

		data('a');
		while(1);	
	
}
void cmd(char a)
{
	IOCLR0=~0;
	IOSET0=a<<8;
	IOSET0=0X00000002;
	delay();
	IOCLR0=0X0000000F;
}
void data(char b)
{
	IOCLR0=~0;
	IOSET0=b<<8;
	IOSET0=0X00000003;
	delay();
	IOCLR0=0X00000002;
}

	void delay()
	{
	int i;
	for(i=0;i<100000;i++);
	}
