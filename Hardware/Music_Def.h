#ifndef __MUSIC_DEF_H
#define __MUSIC_DEF_H

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

//按键
#define RA3      GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_3)
#define RA4      GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_4)
#define RA5      GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_5)
#define RA6      GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_6)
#define RA7      GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_7)
#define RA10      GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_10)
#define RA11      GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_11)
#define RA12      GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_12)
#define RA15      GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_15)

#define RB0      GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0)
#define RB1      GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1)
#define RB3      GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_3)
#define RB4      GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4)
#define RB5      GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5)
#define RB6      GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6)
#define RB7      GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7)
#define RB8      GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)
#define RB10      GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10)

#endif
