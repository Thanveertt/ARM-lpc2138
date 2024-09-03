#include<lpc21xx.h>
void delay();
void cmd(char a);
void data(char b);            
void main()
{
	int i,a;
	int b[10];
	PINSEL0=0X00000000;
	PINSEL1=0X04000000;
	IO0DIR=0X0000FFFF;
	cmd(0x38);
	cmd(0x01);
	cmd(0x06);
	cmd(0x0E);
	cmd(0x80);
	while(1)
	{
		ADCR=0X01200404; 
		while((ADDR&0X80000000)==0);
		a=ADDR>>6&0X3FF;
		i=0;
		do
		{
			b[i]=(a%10)+48;
			a=a/10;
			   i++;
		}
		while(a>0);
		for(i--;i>=0;i--)
		{
			data(b[i]);
		}
		delay();									
		cmd(0x01);
	}			  
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
