#ifndef _CONFIG_H
#define _CONFIG_H
/****************************************************************
 通用头文件
****************************************************************/
#include <reg52.h>
#include <intrins.h>


//#define MAIN_Fosc		11059200UL	//宏定义主时钟HZ


/****************************************************************
已有数据类型重新定义
****************************************************************/
typedef signed char int8;  //8位有符号型
typedef signed int  int16; //16位有符号型
typedef unsigned char uint8;  //8位无符号型
typedef unsigned char uchar;  //8位无符号型
typedef unsigned int  uint16; //16位无符号型
typedef unsigned int  uint; //16位无符号型
typedef unsigned long uint32; //32位无符号型

/****************************************************************
 硬件接口定义
****************************************************************/
/*5路寻迹接口 请用5P杜邦线与对应的P1口链接*/
sbit  xunji_1=P2^0;
sbit  xunji_2=P2^1;
sbit  xunji_3=P2^2;
sbit  xunji_4=P2^3;
sbit  xunji_5=P2^4;
/*舵机输出PWM IO口*/
sbit SEV_PWM = P1^0;   
/*电机输出PWM IO口*/
sbit Motor_PWM = P1^1;  

/*main.c里函数*/
void Delay(int n); 

#endif