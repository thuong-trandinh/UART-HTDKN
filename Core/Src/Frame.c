/*
 * Frame.c
 *
 *  Created on: Apr 13, 2025
 *      Author: HP
 */


#include "Frame.h"


uint16_t Calculate_CRC16(uint8_t *data, uint16_t length) {
    uint16_t crc = 0xFFFF;
    for (uint16_t i = 0; i < length; i++) {
        crc ^= (uint16_t)(data[i] << 8);  // Sử dụng data[i] cho rõ ràng
        for (uint8_t j = 0; j < 8; j++) {
            if (crc & 0x8000)
                crc = (crc << 1) ^ 0x1021;
            else
                crc = crc << 1;
        }
    }
    return crc;
}

void packframe(uint8_t *outbuf, frame_t  *trans, uint8_t command){
	outbuf[0] = trans->start_bit;
	trans->command = command;
	outbuf[1] = trans->command;
	outbuf[2] = (uint8_t)(trans->length >> 8)&0xFF;
	outbuf[3] = (uint8_t)(trans->length & 0xFF);
	// Copy payload vào frame (nếu có)
	if (trans->payload != NULL && trans->length > 0) {
	    memcpy(&outbuf[4], trans->payload, trans->length);
	}
	trans->CRC_16 = Calculate_CRC16(&outbuf[1],trans->length + 3); // temp ktr xiu nua xoa
	outbuf[trans->length + 4] = ((trans->CRC_16)>>8)&0xFF;
	outbuf[trans->length + 5] = trans->CRC_16&0xFF;
	outbuf[6 + trans->length] = trans->end;
}

