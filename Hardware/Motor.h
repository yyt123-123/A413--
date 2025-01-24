#ifndef __MOTOR_H
#define __MOTOR_H
#include "stdint.h"

void Motor_Init(void);
void Motor_SetSpeed(int8_t Speed);
void LeftMotor_Speed(int8_t Speed);
void RightMotor_Speed(int8_t Speed);


#endif
