/*
 * delay.h
 *
 *  Created on: 13.11.2018
 *  Example used from: https://patrickleyman.be/blog/stm32f407-delay-with-systick/
 */

#ifndef DELAY_H_
#define DELAY_H_

#include "stm32f30x.h"

void SysTick_Init(void);
void TimeTick_Decrement(void);
void delay_nus(u32 n);
void delay_1ms(void);
void delay_nms(u32 n);

#endif /* DELAY_H_ */
