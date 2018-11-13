/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include <stdio.h>
#include "stm32f30x.h"
#include "delay.h"


int main(void)
{
	SysTick_Init();
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);

	GPIO_InitTypeDef GPIO_InitDef; //Where GPIO_InitDef is variable to work with struct

	//Apply settings just to GPIO_Pin_13:
	GPIO_InitDef.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitDef.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitDef.GPIO_OType = GPIO_OType_PP;
	GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitDef.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(GPIOA, &GPIO_InitDef);

	GPIO_SetBits(GPIOA, GPIO_Pin_5);
	GPIO_ResetBits(GPIOA, GPIO_Pin_5);
	int delay = 500;
	printf("Hello World!\r\n");
	//volatile int i;
	while (1) {
		delay_nms(delay);
		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_5)) {
			delay = 200;
//			if (delay <= 0) {
//				delay = 400;
//			}
			GPIO_ResetBits(GPIOA, GPIO_Pin_5);
		} else {
			delay = 500;
			GPIO_SetBits(GPIOA, GPIO_Pin_5);
		}
	}
}

void SysTick_Handler(void) {
	TimeTick_Decrement();
}
