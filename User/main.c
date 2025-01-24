#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Servo.h"
#include "Key.h"
#include "PWM.h"
#include "music.h"
#include "Music_Def.h"


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
		if(RB7 == 1){Do;}
		if(RB6 == 1){Re;}
		if(RB5 == 1){Mi;}
		if(RB4 == 1){Fa;}
		if(RB3 == 1){Sol;}
		if(RA15 == 1){La;}
		if(RA12 == 1){Xi;}
		if(RA11 == 1){Do1;}
		if(RA10 == 1){Re1;}
		if(RB10 == 1){Mi1;}
		if(RB1 == 1){Fa1;}
		if(RB0 == 1){Sol1;}
		if(RA7 == 1){La1;}
		if(RA6 == 1){Xi1;}
		if(RA5 == 1){Do2;}
		if(RA4 == 1){Re2;}
		if(RA3 == 1){Mi2;}
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
