#include<lpc21xx.h>
void delay();
void main()
{
PINSEL1=0X00000000;
IO0DIR=0XFFFFFFFF;
IO1DIR=0X00000000;
while(1)
{
if((IO1PIN&0X80000000)==0)
{
int i;
for(i=0;i<32;i++)
{
IOSET0=1<<i;		//	 left shift
delay();
IOCLR0=1<<i;
delay();
}
}

if((IO1PIN&0X40000000)==0)
{
int i;
for(i=0;i<32;i++)
{

IOSET0=0X80000000>>i;			// right shift
delay();
IOCLR0=0X80000000>>i;
delay();
}
}
}
}
void delay()
{
int j;
for(j=0;j<50000;j++);
}
