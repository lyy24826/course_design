#include "delay.h"

void Set_Clock_32M(void)
{
  //主时钟源选择：外部晶振32MHz
  CLKCONCMD &=~ 0x40;
  //等待晶振稳定
  while(CLKCONSTA & 0x40);
  //系统时钟的速度设置为：32MHz
  CLKCONCMD &=~ 0x07;
}


void Delay_xus(unsigned int value)
{
  while(value--)
  {
    asm("NOP");
    asm("NOP");
    asm("NOP");
  }
}


void Delay_xms(unsigned int value)
{
  for(int i=0; i<value; i++)
  Delay_xus(1000);
}
