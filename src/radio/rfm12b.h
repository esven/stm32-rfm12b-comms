/*
 * rfm12b.h
 *
 *  Created on: 12.11.2018
 *  Mainly copied from: https://github.com/robots/STM32/blob/master/GPSTracker/modem/rfm12.h
 */

#ifndef RADIO_RFM12B_H_
#define RADIO_RFM12B_H_

enum {
	RFM_STATE_SLEEP,
	RFM_STATE_IDLE,
	RFM_STATE_SCAN,
	RFM_STATE_SNIFF,
	RFM_STATE_RX,
	RFM_STATE_TX,
};

#define RFM_BAND_433MHZ  1
#define RFM_BAND_868MHZ  2
#define RFM_BAND_915MHZ  3

#define RFM_STATUS_FFIT_RGIT  0x8000
#define RFM_STATUS_POR        0x4000
#define RFM_STATUS_FFOV_RGUR  0x2000
#define RFM_STATUS_WKUP       0x1000
#define RFM_STATUS_EXT        0x0800
#define RFM_STATUS_LBD        0x0400
#define RFM_STATUS_FFEM       0x0200
#define RFM_STATUS_ATS_RSSI   0x0100
#define RFM_STATUS_DQD        0x0080
#define RFM_STATUS_CRL        0x0040
#define RFM_STATUS_ATGL       0x0020
#define RFM_STATUS_OFFS_SIGN  0x0010
#define RFM_STATUS_OFFS_MASK  0x000F

#define RFM_RECV_MODE    0x82D9
#define RFM_XMIT_MODE    0x8239
#define RFM_IDLE_MODE    0x8209
#define RFM_SLEEP_MODE   0x8201
#define RFM_WAKEUP_MODE  0x8203

#define RFM_TX_REG       0xB800
#define RFM_RX_REG       0xB000
#define RFM_WAKEUP_REG   0xE000


void RFM_Init(void);
void RFM_SetDataRate(uint8_t r);
void RFM_SetTXDeviation(uint8_t d);
void RFM_SetRXWidth(uint8_t w);
void RFM_SetGroup(uint8_t g);
void RFM_SetBand(uint8_t b);
void RFM_SetFreq(uint16_t f);
void RFM_SetFIFO(uint8_t g);

void RFM_IdleMode();
void RFM_SniffMode(uint8_t a);
void RFM_ScanMode();
void RFM_RecvMode();

uint8_t RFM_Send(uint16_t id, uint8_t *data, uint8_t len);
uint8_t RFM_ReadFifo();
uint8_t RFM_IsIdle();

#endif /* RADIO_RFM12B_H_ */
