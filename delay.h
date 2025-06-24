#ifndef __DELAY_H
#define __DELAY_H

#include "iocc2530.h"

void Set_Clock_32M(void);
void Delay_xus(unsigned int value);
void Delay_xms(unsigned int value);

#endif
