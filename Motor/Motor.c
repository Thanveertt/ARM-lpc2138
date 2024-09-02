#include<lpc21xx.h>
void delay();
void main()
{
PINSEL0=0X00000000;
PINSEL1=0X00000000;
IO0DIR=0XFFFFFFFF;
IO1DIR=0X00000000;
while(1)
{
if((IO1PIN&0X80000000)==0)
{
IOSET0=0X0000001D;		//	 forward
delay();
IOCLR0=~0;
delay();
}
if((IO1PIN&0X40000000)==0)
{
IOSET0=0X0000002E;			// reverse
delay();
IOCLR0=~0;
delay();
} 
}
}
void delay()
{
int j;
for(j=0;j<10000000;j++);
}
