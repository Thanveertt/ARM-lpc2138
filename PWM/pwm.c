#include<lpc21xx.h>
void main()
{
	PINSEL0=1<<3;
	IO0DIR=~0;
	PWMMR0=300;	 //COMPARED TO TIMER / C VALUE	  - PERIOD	300 * 1mS
	PWMMR3=100;
	PWMTCR=2;
	PWMTCR=1|1<<3;
	PWMMCR=1<<1;
	PWMPR=14999; 	   //1 mS
	PWMTC=0;	   
	PWMPC=0;
	PWMPCR=1<<11;
	while(1);
} 
