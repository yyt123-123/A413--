#include "stm32f10x.h"                  // Device header
#include "PWM.h"

void Motor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	//初始化电机两个角，A4，A5和A6，A7。
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	PWM_Init();
}

//A1和A4,A5搭配
void LeftMotor_Speed(int8_t Speed)
{
	if(Speed > 0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_4);//SetBits为1，表示高电平
		GPIO_ResetBits(GPIOA, GPIO_Pin_5);//ResetBits为0，表示低电平
		PWM_SetCompare2(Speed);
	}
	else if(Speed == 0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_4);//SetBits为1，表示高电平
		GPIO_SetBits(GPIOA, GPIO_Pin_5);
		PWM_SetCompare2(Speed);

	}
    else
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_4);//ResetBits为0，表示低电平
		GPIO_SetBits(GPIOA, GPIO_Pin_5);//SetBits为1，表示高电平
		PWM_SetCompare2(-Speed);//SetCompare只能传正数

	}	
}

//A0和A6,A7搭配
void RightMotor_Speed(int8_t Speed)
{
	if(Speed > 0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_6);//SetBits为1，表示高电平
		GPIO_ResetBits(GPIOA, GPIO_Pin_7);//ResetBits为0，表示低电平
		PWM_SetCompare1(Speed);
	}
	else if(Speed == 0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_6);//SetBits为1，表示高电平
		GPIO_SetBits(GPIOA, GPIO_Pin_7);
		PWM_SetCompare1(Speed);

	}
    else
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_6);//ResetBits为0，表示低电平
		GPIO_SetBits(GPIOA, GPIO_Pin_7);//SetBits为1，表示高电平
		PWM_SetCompare1(-Speed);//SetCompare只能传正数

	}	
}