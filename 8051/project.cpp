#include<regx51.h>
#define PWM P1
char num,duty,num2;
char flag;


void main(void)
{
	num=0;
	num2=0;
	duty=3;//buck��duty,3�N��30%
	flag=0;
	EA=1;//�}�Ҥ��_
	ET0=1;//�Ұ�timer 0���_
    EX0=1;//�}�ҥ~�����_0
    IT0=1;//�]�w���t�tĲ�o
	TMOD=0x01;
	TR0=1;//�Ұ�timer 0
	while(1);
}
	
//timer 0���_
void timer0 (void) interrupt 1
{
	TH0=(65536-75)/256;//�e��8bit��Ӽ�
	TL0=(65536-75)%256;//�᭱8bit��l��
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