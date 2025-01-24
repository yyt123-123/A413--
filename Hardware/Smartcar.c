#include "stm32f10x.h"                  // Device header
#include "Motor.h"

//最小值不能低于32，否则无法克服静摩擦力，轮子不转动

void Smartcar_Init(void)
{
	Motor_Init();
}
void Move_Forward(void)
{
    LeftMotor_Speed(70);
	RightMotor_Speed(70);
}
void Move_Backward(void)
{
    LeftMotor_Speed(-100);
	RightMotor_Speed(-100);
}
void Car_Stop(void)
{
    LeftMotor_Speed(0);
	RightMotor_Speed(0);
}
void Turn_Left(void)
{
    LeftMotor_Speed(33);
	RightMotor_Speed(75);
}
void Turn_Right(void)
{
    LeftMotor_Speed(75);
	RightMotor_Speed(33);
}
void Clockwise_Rotation(void)
{
    LeftMotor_Speed(70);
	RightMotor_Speed(-70);

}
void CountClockwise_Rotation(void)
{
    LeftMotor_Speed(-100);
	RightMotor_Speed(100);
}


