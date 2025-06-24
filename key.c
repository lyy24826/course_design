#include "key.h"
//#include "stm32f10x.h"
uint8_t Key_Val = 0;    //当前按键值
uint8_t Key_Old = 0;    //上次按键值   
uint8_t Key_Down = 0;   //按键按下
uint8_t Key_Up = 0;     //按键弹起
void key_init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_2MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Pin=GPIO_Pin_8;
    GPIO_Init(GPIOB,&GPIO_InitStruct);
}
uint8_t key_scan(void)
{
    if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==SET)
    {
        while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==SET);
        return 1;
    }
    if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)==RESET)
    {
        while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)==RESET);
        return 2;
    }
    return 0;
}
uint8_t key_read(void)
{
    uint8_t temp=0;
    if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==SET) temp=1;
    if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)==Bit_RESET) temp=2;
    return temp;
}

void key_proc(void)
{
    Key_Val = key_read();
    Key_Down = Key_Val & (Key_Old ^ Key_Val);
    Key_Up = ~Key_Val & (Key_Old ^ Key_Val);
    Key_Old = Key_Val;
	switch(key_read())
		{
			case 1:
				break;
			case 2:
				break;
		}
}

