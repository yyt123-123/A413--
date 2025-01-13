#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Servo.h"
#include "Key.h"
#include "PWM.h"
#include "music.h"

//低音区
#define Do       Low_Do()
#define Re       Low_Re()
#define Mi       Low_Mi()
#define Fa       Low_Fa()
#define Sol      Low_Sol()
#define La       Low_La()
#define Xi       Low_Xi()

//中音区
#define Do1      Mid_Do()
#define Re1      Mid_Re()
#define Mi1      Mid_Mi()
#define Fa1      Mid_Fa()
#define Sol1     Mid_Sol()
#define La1      Mid_La()
#define Xi1      Mid_Xi()

//高音区
#define Do2      High_Do()
#define Re2      High_Re()
#define Mi2      High_Mi()
#define Fa2      High_Fa()
#define Sol2     High_Sol()
#define La2      High_La()
#define Xi2      High_Xi()
#define S        Slience()
int main(void)
{
    OLED_Init();
	Servo_Init();
	Key_Init();
	PWM_Init();
	music_Init();
	
	
	OLED_ShowString(1, 1, "Angle:");
    while(1)
    {
		Music();
    }
}

void Music(void)        //给我一首歌的时间
{
    Mi;
	Delay_ms(530);
	Sol;
	Delay_ms(530);
	Mi1;
	Delay_ms(1100);
	Mi1;
	Delay_ms(265);
	Sol;
	Delay_ms(265);
	Fa1;
	Delay_ms(265);
	Mi1;
	Delay_ms(265);
	Re1;
	Delay_ms(265);
	Fa1;
	Delay_ms(265);
	Mi1;
	Delay_ms(515);
	Re1;
	Delay_ms(315);
	Do1;
	Delay_ms(1400);
	
	Sol;
	Delay_ms(265);
	Re1;
	Delay_ms(265);
	Do1;
	Delay_ms(265);
	Mi;
	Delay_ms(265);
	Re1;
	Delay_ms(265);
	Do1;
	Delay_ms(515);
	Xi;
	Delay_ms(265);
	La;
	Delay_ms(1060);

	Xi;
	Delay_ms(265);
	La;
	Delay_ms(265);
	Sol;
	Delay_ms(515);
	Re1;
	Delay_ms(515);
	Do1;
	Delay_ms(515);
	Mi;
	Delay_ms(265);
	Fa;
	Delay_ms(1400);
	Fa;
	Delay_ms(265);
	Sol;
	Delay_ms(265);
	Sol1;
	Delay_ms(265);
	Fa1;
	Delay_ms(265);
	Mi1;
	Delay_ms(715);
	Re1;
	Delay_ms(125);
	Mi1;
	Delay_ms(125);
	Re1;
	Delay_ms(950);
	Do1;
	Delay_ms(1400);
    Delay_s(100);	
}
