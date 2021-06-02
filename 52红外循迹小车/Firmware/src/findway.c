#include<config.h>
#include<findway.h>
#include<STEENG.h>
#include<motor.h>

int8 motor=0;
int8 STE=0;

void Findway_Init(){
	P2=0xff;	   //P2����Ϊ����ģʽ
}
void Findway_PID(){
	uchar flatN=0;
	uint8 Q;
	if(Q!=P2) flatN++;
	Q = P2;
	if(Timer()<30&&flatN>3){ //10*20ms��	ѭ������3�α仯
		STE--;
		if(STE<-2)STE=-3;
		motor=motor+20;
		if(motor>80) motor=80;	
	}
	if(Timer()<30&&flatN<=3){ //10*20ms��	ѭ������3�α仯
		STE++;
		if(STE>3)STE=3;
		motor=motor-20;
		if(motor<0) motor=-30;	
	}
}
void Findway_Deal(){
	if(xunji_1==1&&xunji_2==1&&xunji_3==1&&xunji_4==1&&xunji_5==1){
	 	Go();
		Delay(230);
	 	Motor_Stop();
	}
	if(xunji_1==0&&xunji_2==0&&xunji_3==1&&xunji_4==0&&xunji_5==0){
	 	Go();
		Delay(230);
	 	Motor_Fast(30+motor);//cmdԽ���ٶ�Խ��
	}
	if(xunji_1==0&&xunji_2==1&&xunji_3==1&&xunji_4==0&&xunji_5==0){	//��ת�����ֱ����ƫ���
	 	right(2); //SEVԽ��ת��Խ��
		Delay(230);
	 	Motor_Go(30);//cmdԽ���ٶ�Խ��
	}
	if(xunji_1==0&&xunji_2==1&&xunji_3==0&&xunji_4==0&&xunji_5==0){	//��ת�����ֱ����ƫ���
	 	right(2+STE); //SEVԽ��ת��Խ��
		Delay(230);
	 	Motor_Fast(30+motor);//cmdԽ���ٶ�Խ��
	}		
	if(xunji_1==0&&xunji_2==0&&xunji_3==1&&xunji_4==1&&xunji_5==0){	//������ת�����ֱ����ƫ
	 	lift(2); //SEVԽ��ת��Խ��
		Delay(230);
	 	Motor_Go(30);//cmdԽ���ٶ�Խ��
	}
	if(xunji_1==0&&xunji_2==0&&xunji_3==0&&xunji_4==1&&xunji_5==0){	//������ת�����ֱ����ƫ
	 	lift(2+STE); //SEVԽ��ת��Խ��
		Delay(230);
	 	Motor_Fast(30+motor);//cmdԽ���ٶ�Խ��
	}
	if(xunji_1==1&&xunji_2==1&&xunji_3==0&&xunji_4==0&&xunji_5==0){	
	 	right(3); //SEVԽ��ת��Խ��
		Delay(230);
	 	Motor_Slow(10);//cmdԽ���ٶ�Խ��
	}
	if(xunji_1==1&&xunji_2==0&&xunji_3==0&&xunji_4==0&&xunji_5==0){	
	 	right(3); //SEVԽ��ת��Խ��
		Delay(230);
	 	Motor_Slow(10+motor);//cmdԽ���ٶ�Խ��
	}
	if(xunji_1==0&&xunji_2==0&&xunji_3==0&&xunji_4==1&&xunji_5==1){	
	 	lift(3); //SEVԽ��ת��Խ��
		Delay(230);
	 	Motor_Slow(10);//cmdԽ���ٶ�Խ��
	}
	if(xunji_1==0&&xunji_2==0&&xunji_3==0&&xunji_4==0&&xunji_5==1){	
	 	lift(3); //SEVԽ��ת��Խ��
		Delay(230);
	 	Motor_Slow(10+motor);//cmdԽ���ٶ�Խ��
	}

				 	
}

