#include<lpc21xx.h>
void delay();
void main()
{
PINSEL1=0X00000000;			   //32 pin, Enable all
IO0DIR=0XFFFFFFFF;			   //to set pin Input or Output
while(1)
{
IOSET0=0XFFFFFFFF;			   //set
delay();
IOCLR0=0XFFFFFFFF;			   //clear
delay();
}
}
void delay()
{
int i;
for(i=0;i<100;i++);
}
