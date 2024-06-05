/*
 * sbus.c
 *
 *  Created on: May 23, 2024
 *      Author: tgrot
 */
#include "stm32f3xx_hal.h"
#include "sbus.h"

extern UART_HandleTypeDef huart4;
#define NRF24_UART &huart4

void formatSBUSData(uint16_t *channels, uint8_t *sbusData)
{
    sbusData[0] = 0x0F;
    sbusData[1] = (uint8_t)(channels[0] & 0x07FF);
    sbusData[2] = (uint8_t)((channels[0] & 0x07FF) >> 8 | (channels[1] & 0x07FF) << 3);
    sbusData[3] = (uint8_t)((channels[1] & 0x07FF) >> 5 | (channels[2] & 0x07FF) << 6);
    sbusData[4] = (uint8_t)((channels[2] & 0x07FF) >> 2);
    sbusData[5] = (uint8_t)((channels[2] & 0x07FF) >> 10 | (channels[3] & 0x07FF) << 1);
    sbusData[6] = (uint8_t)((channels[3] & 0x07FF) >> 7 | (channels[4] & 0x07FF) << 4);
    sbusData[7] = (uint8_t)((channels[4] & 0x07FF) >> 4 | (channels[5] & 0x07FF) << 7);
    sbusData[8] = (uint8_t)((channels[5] & 0x07FF) >> 1);
    sbusData[9] = (uint8_t)((channels[5] & 0x07FF) >> 9  | (channels[6] & 0x07FF) << 2);
    sbusData[10] = (uint8_t)((channels[6] & 0x07FF) >> 6  | (channels[7] & 0x07FF) << 5);
    sbusData[11] = (uint8_t)((channels[7] & 0x07FF) >> 3);
    sbusData[12] = (uint8_t)((channels[8] & 0x07FF));
    sbusData[13] = (uint8_t)((channels[8] & 0x07FF) >> 8 | (channels[9]  & 0x07FF) << 3);
    sbusData[14] = (uint8_t)((channels[9] & 0x07FF) >> 5 | (channels[10] & 0x07FF) << 6);
    sbusData[15] = (uint8_t)((channels[10] & 0x07FF) >> 2);
    sbusData[16] = (uint8_t)((channels[10] & 0x07FF) >> 10 | (channels[11] & 0x07FF) << 1);
    sbusData[17] = (uint8_t)((channels[11] & 0x07FF) >> 7  | (channels[12] & 0x07FF) << 4);
    sbusData[18] = (uint8_t)((channels[12] & 0x07FF) >> 4  | (channels[13] & 0x07FF) << 7);
    sbusData[19] = (uint8_t)((channels[13] & 0x07FF) >> 1);
    sbusData[20] = (uint8_t)((channels[13] & 0x07FF) >> 9  | (channels[14] & 0x07FF) << 2);
    sbusData[21] = (uint8_t)((channels[14] & 0x07FF) >> 6  | (channels[15] & 0x07FF) << 5);
    sbusData[22] = (uint8_t)((channels[15] & 0x07FF) >> 3);
    sbusData[23] = 0x00; //| (data_.ch17 * CH17_MASK_) | (data_.ch18 * CH18_MASK_) |(data_.failsafe * FAILSAFE_MASK_) | (data_.lost_frame * LOST_FRAME_MASK_);
    sbusData[24] = 0x00;
}

void sendSBUSData(uint8_t *sbusData)
{
    while(HAL_UART_Transmit_DMA(NRF24_UART, sbusData, SBUS_FRAME_SIZE) != HAL_OK);
    //while(HAL_UART_Transmit(&huart5, sbusData, SBUS_FRAME_SIZE, 0) != HAL_OK);
    //HAL_UART_Transmit(&huart5, sbusData, SBUS_FRAME_SIZE, 1000);
}

void sendSbusChannels(uint16_t *sbusChannels)
{
	uint8_t sbusData[SBUS_FRAME_SIZE];

	formatSBUSData(sbusChannels, sbusData);
	sendSBUSData(sbusData);
}


