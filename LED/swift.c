#include<lpc21xx.h>
void delay();
void main()
{
PINSEL1=0X00000000;
IO0DIR=0XFFFFFFFF;
while(1)
{
int i;
for(i=0;i<32;i++)
{
/*IOSET0=1<<i;			// left shift
delay();
IOCLR0=1<<i;
delay();
*/ 

 IOSET0=0X80000000>>i;			// right shift
delay();
IOCLR0=0X80000000>>i;
delay();

}
}
}
void delay()
{
int j;
for(j=0;j<50000;j++);
}
