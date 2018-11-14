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
#include "platform.h"
#include "radio/rfm12b.h"

void RCC_Configuration(void)
{
	SystemInit();
	SysTick_Init();

	// Enable GPIO modules
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1 | RCC_APB2Periph_SYSCFG, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA | RCC_AHBPeriph_GPIOB | RCC_AHBPeriph_GPIOC, ENABLE);
}

void GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure = {
		.GPIO_Speed = GPIO_Speed_50MHz
	};

	// SPI
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_5);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_5);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_5);

	// PB6 - RFM Chip Select
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	//  RFM - IRQn
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	RFM_CS(Bit_SET);
}

int main(void)
{
	uint8_t send_buffer[] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
	RCC_Configuration();
	GPIO_Configuration();

	printf("Hello World!\r\n");
	RFM_Init();
	while (1) {
		delay_nms(1000);
		RFM_Send(0x0012, send_buffer, sizeof(send_buffer));
	}
}

void SysTick_Handler(void) {
	TimeTick_Decrement();
}
