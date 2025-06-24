#include "delay.h"

void Set_Clock_32M(void)
{
  //��ʱ��Դѡ���ⲿ����32MHz
  CLKCONCMD &=~ 0x40;
  //�ȴ������ȶ�
  while(CLKCONSTA & 0x40);
  //ϵͳʱ�ӵ��ٶ�����Ϊ��32MHz
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
