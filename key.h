#ifndef __KEY_H
#define __KEY_H

#include "stm32f10x.h"
void key_init(void);
uint8_t key_scan(void);
uint8_t key_read(void);
void key_proc(void);
#endif
