#include "stm32f10x.h"                  // Device header
#include "Delay.h"

//TCRT5000:如果传感器检测到物体反射回来的红外线强度足够大，输出端变为高电平，此时信号指示灯是熄灭的；如果反射回来的红外线强度不够大或者没有反射，输出端为低电平，信号指示灯点亮
//熄灭:没有物体反射或反射强度不足或物体颜色吸光性强||闪亮:物体反射红外线强度足够或白色物体靠近传感器

uint16_t CountSensor_Count5;

void CountSensor_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);//开启RCC时钟，开启外设GPIO_B的时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);//AFIO也是APB2的外设，可查看定义看外设对应哪个总线
	//EXTI不需要开启时钟
	//NVIC不需要开启时钟（NVIC是内核的外设，内核的外设都不需要开启时钟）
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//上拉输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource15);//将指定的 GPIO 引脚（在这里是 GPIOB 的第 14 引脚）与外部中断控制器的中断输入线路进行关联。

	
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line = EXTI_Line15;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;//选择为外部中断
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;//选择为上升沿或下降沿中断
	EXTI_Init(&EXTI_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;//数值越小，表示抢占优先级越高
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;//同样数值越小，响应优先级越高
	NVIC_Init(&NVIC_InitStructure);
	
}

uint16_t CountSensor_Get5(void)
	{
		return CountSensor_Count5;
    }


void EXTI15_10_IRQHandler(void)//第一个void表示函数的返回类型,第二个void表示这个函数在被调用时不需要接收任何外部传入的参数（它的功能是处理外部中断 15 - 10 这个范围内的中断事件，它所需要的信息（如中断标志位状态、相关引脚的电平变化等）通常是通过直接访问硬件寄存器或者内部的全局变量来获取，而不是通过参数传递的方式。这样设计使得函数的职责更加明确，它只关注与这个特定中断范围相关的处理操作，不需要额外的参数来干扰它的执行逻辑。）
{
	if (EXTI_GetITStatus(EXTI_Line15) == SET)
	{
	CountSensor_Count5 ++;
	EXTI_ClearITPendingBit(EXTI_Line15);//将中断标志位清除，避免一直申请中断，卡死在这个程序里
	}
}

