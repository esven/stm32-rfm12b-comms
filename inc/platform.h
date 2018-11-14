/*
 * platform.h
 *
 *  Created on: 14.11.2018
 *      Author: esven
 */

#ifndef PLATFORM_H_
#define PLATFORM_H_

//#define LED_ON Bit_RESET
//#define LED_OFF Bit_SET

//#define LED_GREEN_PIN      GPIO_Pin_5
//#define LED_GREEN_GPIO     GPIOA

#define RFM_CS_PIN         GPIO_Pin_6
#define RFM_CS_GPIO        GPIOB

#define RFM_IRQ_PIN        GPIO_Pin_7
#define RFM_IRQ_GPIO       GPIOC

//#define RFM_RST_PIN        GPIO_Pin_9
//#define RFM_RST_GPIO       GPIOA
//
//#define RFM_INT_PIN        GPIO_Pin_3
//#define RFM_INT_GPIO       GPIOA

//#define LED_RED(x)         GPIO_WriteBit(LED_RED_GPIO, LED_RED_PIN, x)
//#define LED_GREEN(x)       GPIO_WriteBit(LED_GREEN_GPIO, LED_GREEN_PIN, x)
//#define LED_YELLOW(x)      GPIO_WriteBit(LED_YELLOW_GPIO, LED_YELLOW_PIN, x)

#define RFM_CS(x)          GPIO_WriteBit(RFM_CS_GPIO, RFM_CS_PIN, x)
//#define RFM_RST(x)         GPIO_WriteBit(RFM_RST_GPIO, RFM_RST_PIN, x)
#define RFM_IRQ_READ()     GPIO_ReadInputDataBit(RFM_IRQ_GPIO, RFM_IRQ_PIN)

#endif /* PLATFORM_H_ */
