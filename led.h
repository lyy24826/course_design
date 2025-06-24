#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"
void led_init(void);

// 单独控制每个LED的亮灭
void led0_on(void);
void led0_off(void);
void led1_on(void);
void led1_off(void);
void led2_on(void);
void led2_off(void);
//led翻转
#define LED1_TURN GPIOC->ODR^=1<<0
#define LED2_TURN GPIOC->ODR^=1<<1
#define LED3_TURN GPIOC->ODR^=1<<2

#endif
