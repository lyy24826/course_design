#ifndef _ADC_KEY_H_
#define _ADC_KEY_H_

#include "iocc2530.h"
#include "OnBoard.h"

typedef enum{
  KEY_UP = 1,
  KEY_DOWN,
  KEY_LEFT,
  KEY_RIGHT,
}ADC_KEY_Def;

uint8 Adc_KeyGetValue(void);
#endif

