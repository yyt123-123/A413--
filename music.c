#include "stm32f10x.h"                  // Device header
#include "PWM.h"

//低八度
void music_Init()
{
	PWM_Init();
}

void Low_Do(void)
{
	PWM_Beep(3817);
	PWM_SetCompare2(1908);
}

void Low_Re(void)
{
	PWM_Beep(3401);
	PWM_SetCompare2(1700);
}

void Low_Mi(void)
{
	PWM_Beep(3030);
	PWM_SetCompare2(1515);
}

void Low_Fa(void)
{
	PWM_Beep(2865);
	PWM_SetCompare2(1600);
}

void Low_Sol(void)
{
	PWM_Beep(2551);
	PWM_SetCompare2(1400);
}

void Low_La(void)
{
	PWM_Beep(2273);
	PWM_SetCompare2(1136);
}

void Low_Xi(void)
{
	PWM_Beep(2024);
	PWM_SetCompare2(850);
}

//中八度
void Mid_Do(void)
{
	PWM_Beep(1912);
	PWM_SetCompare2(956);
}

void Mid_Re(void)
{
	PWM_Beep(1703);
	PWM_SetCompare2(852);
}

void Mid_Mi(void)
{
	PWM_Beep(1517);
	PWM_SetCompare2(759);
}

void Mid_Fa(void)
{
	PWM_Beep(1433);
	PWM_SetCompare2(716);
}

void Mid_Sol(void)
{
	PWM_Beep(1275);
	PWM_SetCompare2(638);
}

void Mid_La(void)
{
	PWM_Beep(1136);
	PWM_SetCompare2(568);
}

void Mid_Xi(void)
{
	PWM_Beep(1012);
	PWM_SetCompare2(506);
}

//高八度
void High_Do(void)
{
	PWM_Beep(956);
	PWM_SetCompare2(478);
}

void High_Re(void)
{
	PWM_Beep(851);
	PWM_SetCompare2(425);
}

void High_Mi(void)
{
	PWM_Beep(759);
	PWM_SetCompare2(379);
}

void High_Fa(void)
{
	PWM_Beep(716);
	PWM_SetCompare2(358);
}

void High_Sol(void)
{
	PWM_Beep(638);
	PWM_SetCompare2(319);
}

void High_La(void)
{
	PWM_Beep(568);
	PWM_SetCompare2(284);
}

void High_Xi(void)
{
	PWM_Beep(506);
	PWM_SetCompare2(253);
}

//无声
void Slience(void)
{
	PWM_Beep(1);
	PWM_SetCompare2(0);
}
