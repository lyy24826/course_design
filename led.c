#include"led.h"

void led_init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct);

	GPIO_SetBits(GPIOC, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2);//初始化暗
}

// 单独控制每个LED
void led0_on(void)  { GPIO_ResetBits(GPIOC, GPIO_Pin_0); }
void led0_off(void) { GPIO_SetBits(GPIOC, GPIO_Pin_0); }
void led1_on(void)  { GPIO_ResetBits(GPIOC, GPIO_Pin_1); }
void led1_off(void) { GPIO_SetBits(GPIOC, GPIO_Pin_1); }
void led2_on(void)  { GPIO_ResetBits(GPIOC, GPIO_Pin_2); }
void led2_off(void) { GPIO_SetBits(GPIOC, GPIO_Pin_2); }
