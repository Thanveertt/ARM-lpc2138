#include<lpc21xx.h>
void isr()__irq
{
	IO0PIN=~IO0PIN;
	EXTINT=1<<0;
	VICVectAddr=0;
}
void main()
{
	IO0DIR=~(1<<1);
	IO0CLR=~0;
	PINSEL0=1<<2|1<<3;
	VICIntSelect=~(1<<14);	  // ASSIGNED TO IRQ CATAGORY
	VICIntEnClr=1<<14;		  //CLEAR INTERRUPT
	VICIntEnable=1<<14;		  //ENABLE
	VICVectCntl0=1<<5|14;	  // bit no:only
	VICVectAddr0=(unsigned int)isr;//address of interrupt fun 
	EXTINT=1<<0;   //for ext0
	EXTMODE=1<<0;// edge or level
	EXTPOLAR=1<<0;//rising edge or falling
	while(1);
}
