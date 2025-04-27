/*
 * Frame.h
 *
 *  Created on: Apr 13, 2025
 *      Author: HP
 */

#ifndef INC_FRAME_H_
#define INC_FRAME_H_
#include "stm32f4xx.h"
#include "stdint.h"

typedef struct
{
	uint8_t start_bit;
	uint8_t command;
	uint16_t length;
	uint8_t *payload;
	uint16_t CRC_16;
	uint8_t end ;
} frame_t;

uint16_t Calculate_CRC16(uint8_t *data, uint16_t length);
void packframe(uint8_t *outbuf, frame_t  trans, uint16_t crc_16);
#endif /* INC_FRAME_H_ */
