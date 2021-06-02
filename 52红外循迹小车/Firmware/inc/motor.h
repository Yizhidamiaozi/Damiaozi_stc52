#ifndef _MOTOR_H
#define _MOTOR_H

void Motor_Init();
void Motor_Fast(uchar cmd);
void Motor_Go(uchar cmd);
void Motor_Slow(uchar cmd);
void Motor_Stop();

#endif