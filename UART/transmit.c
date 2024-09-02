#include<lpc21xx.h>
void trans(char a);
void main()
{
PINSEL0=0X1;
IODIR0=0XF;
U0LCR=0X83;
U0DLL=98;
U0DLM=0;
U0LCR=0X03;
trans('a');
}
   void trans(char a)
   {
		U0THR=a;
		while((U0LSR&0X40)==0);
   }
