#include<config.h>
#include<motor.h>

uchar V=90;	//VԽ���ٶ�Խ��
uchar Enum=0;

void Motor_Init(){
	TMOD |= 0x11;
	TH1   = 0xff; //��װʱ�䳣�� 0.1ms
	TL1   = 0Xa4;

	EA    = 1;
	ET1   = 1;
	TR1   = 1;
}
void Motor_Fast(uchar cmd){
	V=0;
	V=V+cmd;
	if(V>100) V=100;
}
void Motor_Go(uchar cmd){
	V=70;
	V=V+cmd;
	if(V>150) V=150;
}
void Motor_Slow(uchar cmd){
	V=130;
	V=V+cmd;
	if(V>160) V=160;
}
void Motor_Stop(){
 	V=200;
}
void Time1_Init() interrupt 3{
	TR1	  = 0;
 	TH1   = 0Xff;
	TL1   = 0Xa4;
	if(Enum <= V){
		Motor_PWM = 1; 
	}
	else{
		Motor_PWM = 0;	
	}
	Enum++;
	if(Enum >= 200){//T = 20ms���� 
		Enum = 0; 
	}
	TR1	  = 1;
}