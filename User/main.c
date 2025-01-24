#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Motor.h"
#include "stdint.h"
#include "Key.h"
#include "SmartCar.h"
#include "Track.h"
#include "CountSensor.h"
#include "Serial.h"

#define D4        GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_14) //纠正向右的偏移
#define D3        GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13) //是否直行
#define D2        GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12) //纠正向左的偏移
#define Z         CountSensor_Get5()//计数

uint32_t Flag, x1, x2, x3, x4, X, Y;
uint8_t RxData;

void Rx_Solve(void)
{
	X = RxData % 16;
	Y = RxData / 16;
	x1 = X;
	x2 = x1 + 1 + Y;
	x3 = x2 + 1 + X;
	x4 = x3 + 1 + Y;
}

void Car_Amend(void)//修正函数
{
	if (D3 == 1)
	{
		Move_Forward();
	}
    else if(D4 == 1)
	{
        Turn_Right();
    }
    else if(D2 == 1)
    {
	    Turn_Left();
    }
}

int main(void)
{
	Smartcar_Init();
	Infrared_Init();
	Serial_Init();
	Motor_Init();
	OLED_Init();//初始化有机发光二极管（OLED）显示屏
	CountSensor_Init();
	Rx_Solve();

	OLED_ShowString(1,1,"C5:");
	
	while(1)//第一次转弯
    {
		OLED_ShowNum(1, 5, Z, 5);
		Move_Forward();
		    if(Z > x1)//计数遇到第一个转弯点,第一次转弯扫到线
			{
				OLED_ShowNum(1, 5, Z, 5);
				Delay_ms(200);
					while(D3 == 0)
					{						
						CountClockwise_Rotation();
					    OLED_ShowNum(1, 5, Z, 5);
						Flag = 1;
					}
					break;
		    }
			else if(Flag == 1)
				break;
	}
	Flag = 0;
	while(1)//第二次转弯
	{
		OLED_ShowNum(1, 5, Z, 5);
			if(Z > x2)//计数遇到第一个转弯点,第一次转弯扫到线
			{
				OLED_ShowNum(1, 5, Z, 5);
				Delay_ms(200);
				CountClockwise_Rotation();
					while(D3 != 1)
					{
					    OLED_ShowNum(1, 5, Z, 5);
						CountClockwise_Rotation();
						Flag = 1;
					}
					break;
		    }
			Car_Amend();
			if(Flag == 1)
				break;		
	}
	Flag = 0;
	Car_Stop();
	Delay_ms(2000);
	while(1)//第三次转弯
	{
		OLED_ShowNum(1, 5, CountSensor_Get5(), 5);
		    if(Z > x3)//计数遇到第一个转弯点,第一次转弯扫到线
			{
				OLED_ShowNum(1, 5, Z, 5);
				Delay_ms(800);
				CountClockwise_Rotation();
					while(D3 != 1)
					{
					    OLED_ShowNum(1, 5, CountSensor_Get5(), 5);
						CountClockwise_Rotation();
						Flag = 1;
					}
					break;
		    }
		    Car_Amend();	
			if(Flag == 1)
				break;		
	}
	
			Flag = 0;
	while(1)//第四次转弯
	{
		OLED_ShowNum(1, 5, Z, 5);
		    if(Z > x4)//计数遇到第一个转弯点,第一次转弯扫到线
			{
				OLED_ShowNum(1, 5, Z, 5);
				Delay_ms(800);
				CountClockwise_Rotation();
					while(D3 != 1)//检测到黑线跳出循环
					{
					    OLED_ShowNum(1, 5, Z, 5);
						CountClockwise_Rotation();
						Flag = 1;
					}
					break;
		    }
			Car_Amend();
			if(Flag == 1)
				break;		
	}
Car_Stop();
}
