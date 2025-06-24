#include "rgb.h"

#define RGB_R      (P0_5)
#define RGB_G      (P0_4)
#define RGB_B      (P0_7)

/*
R -- P0_5
G -- P0_4
B -- P0_7
*/
void RGB_Config(void)
{
  P0SEL &= ~(1<<5);
  P0DIR |= (1<<5);
  
  P0SEL &= ~(1<<4);
  P0DIR |= (1<<4);
  
  P0SEL &= ~(1<<7);
  P0DIR |= (1<<7);
}

/*
#define RGB_MODE_ON   1
#define RGB_MODE_OFF  2
#define RGB_MODE_R    3
#define RGB_MODE_G    4
#define RGB_MODE_B    5
*/
void RGB_Mode(uint8 mode)
{
  switch(mode){
    case RGB_MODE_ON:RGB_R = 0;RGB_G = 0;RGB_B = 0;break;
    case RGB_MODE_R:RGB_R = 0;RGB_G = 1;RGB_B = 1;break;
    case RGB_MODE_G:RGB_R = 1;RGB_G = 0;RGB_B = 1;break;
    case RGB_MODE_B:RGB_R = 1;RGB_G = 1;RGB_B = 0;break;
    default:RGB_R = 1;RGB_G = 1;RGB_B = 1;break;
  }
}

