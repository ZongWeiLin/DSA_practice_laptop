#include<regx51.h>
#define PWM P1
char num,duty,num2;
char flag;


void main(void)
{
	num=0;
	num2=0;
	duty=3;//buck的duty,3代表30%
	flag=0;
	EA=1;//開啟中斷
	ET0=1;//啟動timer 0中斷
    EX0=1;//開啟外部中斷0
    IT0=1;//設定為負緣觸發
	TMOD=0x01;
	TR0=1;//啟動timer 0
	while(1);
}
	
//timer 0中斷
void timer0 (void) interrupt 1
{
	TH0=(65536-75)/256;//前面8bit放商數
	TL0=(65536-75)%256;//後面8bit方餘數
	num++;
	if(num>duty){
	num2++;
	if(num2>(10-duty)){num=0;num2=0;}
	if(num2!=0)PWM=0xff;
	}
	else
	PWM=0x7f;
}
void ext0 (void) interrupt 0
{   if(duty>=10)duty=1;
    else duty++;
}