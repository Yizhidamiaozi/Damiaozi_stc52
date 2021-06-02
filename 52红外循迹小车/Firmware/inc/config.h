#ifndef _CONFIG_H
#define _CONFIG_H
/****************************************************************
 ͨ��ͷ�ļ�
****************************************************************/
#include <reg52.h>
#include <intrins.h>


//#define MAIN_Fosc		11059200UL	//�궨����ʱ��HZ


/****************************************************************
���������������¶���
****************************************************************/
typedef signed char int8;  //8λ�з�����
typedef signed int  int16; //16λ�з�����
typedef unsigned char uint8;  //8λ�޷�����
typedef unsigned char uchar;  //8λ�޷�����
typedef unsigned int  uint16; //16λ�޷�����
typedef unsigned int  uint; //16λ�޷�����
typedef unsigned long uint32; //32λ�޷�����

/****************************************************************
 Ӳ���ӿڶ���
****************************************************************/
/*5·Ѱ���ӿ� ����5P�Ű������Ӧ��P1������*/
sbit  xunji_1=P2^0;
sbit  xunji_2=P2^1;
sbit  xunji_3=P2^2;
sbit  xunji_4=P2^3;
sbit  xunji_5=P2^4;
/*������PWM IO��*/
sbit SEV_PWM = P1^0;   
/*������PWM IO��*/
sbit Motor_PWM = P1^1;  

/*main.c�ﺯ��*/
void Delay(int n); 

#endif