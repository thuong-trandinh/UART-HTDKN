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
        crc ^= (uint16_t)(*(data + i) << 8);
        for (uint8_t j = 0; j < 8; j++) {
            if (crc & 0x8000)
                crc = (crc << 1) ^ 0x1021;
            else
                crc <<= 1;
        }
    }
    return crc;
}

void packframe(uint8_t *outbuf, frame_t  trans, uint16_t crc_16){
	outbuf[trans.length + 4] = crc_16>>8;
	outbuf[trans.length + 5] = crc_16&0xFF;
	outbuf[6 + trans.length] = trans.end;
}
void choose_channel(frame_t trans,uint8_t command,float value){
	trans.command = command;
	trans.
}

