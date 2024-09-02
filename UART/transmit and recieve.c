#include<lpc21xx.h>
void trans(char a);
char rec();
void main()
{
char c;
PINSEL0=0X5;
IODIR0=0X1 ;
U0LCR=0X83;
U0DLL=98;
U0DLM=0;
U0LCR=0X03;
while(1)
{
c=rec();
trans(c);
}
}
char rec()
   {
		while((U0LSR&0X01)==0);
		return(U0RBR);
   }
void trans(char a)
   { 
  	while((U0LSR&0X20)==0);
   	U0THR=a;
   }
