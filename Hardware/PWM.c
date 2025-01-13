#include "stm32f10x.h"                  // Device header

void PWM_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;//设置成复用推挽输出，将控制权由输出寄存器转给定时器，片上外设
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;  //GPIO_Pin_15
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
		
	TIM_InternalClockConfig(TIM2);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;//变量命名
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;//允许对定时器的时钟信号进行进一步的分频操作，以满足不同的应用需求
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 1;//ARR（周期）:在10K频率下计10000个数就是1s，ARR：当定时器的计数值从 0 开始计数，达到这个设定的自动重装载值（10000 - 1 = 9999）后，定时器会产生一个更新事件
	TIM_TimeBaseInitStructure.TIM_Prescaler = 72 - 1;//PSC:对72M进行7200的分频得到10K的计数频率，PSC：计数器每秒钟会被时钟信号驱动计数 10000 次。
	
	//溢出频率 = CK_PSC/(PSC+ 1)/(ARR+1)
	//TIM_Prescaler：预分频器,主要作用是降低输入时钟信号的频率,能够以一个合适的频率进行工作。
	
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;//允许用户定义一个重复计数的值，在定时器完成指定次数的计数周期后，才会产生一次更新事件或者触发某些特定的操作
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);//初始化
	
	TIM_OCInitTypeDef TIM_OCInitStructure ;
	TIM_OCStructInit(&TIM_OCInitStructure);//用于给所有StructInit赋初始值，再更改自己需要的值，避免不确定性
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;//设置输出比较的极性
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;//Pusle就是CCR（处于高电平的那一部分）的值，TIM_Pulse的值决定脉冲的宽度。
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);
	
	TIM_Cmd(TIM2,ENABLE);

}

void PWM_SetCompare2(uint16_t Compare)
{
	TIM_SetCompare2(TIM2, Compare);
}

void PWM_Beep(uint16_t f)
{
	if(f == 0)
	{
		TIM_SetAutoreload(TIM2, 1);
		TIM_SetCompare2(TIM2, 0);
	}
	TIM_SetAutoreload(TIM2, f);
	TIM_SetCompare2(TIM2, f/2);
}

