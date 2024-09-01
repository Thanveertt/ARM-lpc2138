#include<lpc214x.h>
void delay();
void delay1();
void main()
{
PINSEL1=0X00000000;
IO0DIR=0XFFFFFFFF;
PINSEL2=0X00000000;
IO1DIR=0XFFFFFFFF;
while(1)
{
IOSET0=0XFFFFFFFF; 
delay();
IOCLR0=0XFFFFFFFF;
delay();
IOSET1=0XFFFFFFFF;
delay1();
IOCLR1=0XFFFFFFFF;
delay1();
}
}
void delay()
{
int i;
for(i=0;i<100;i++);
}
void delay1()
{
int i;
for(i=0;i<200;i++);
}
