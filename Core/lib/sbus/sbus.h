/*
 * sbus.h
 *
 *  Created on: May 23, 2024
 *      Author: tgrot
 */

#ifndef LIB_SBUS_SBUS_H_
#define LIB_SBUS_SBUS_H_

void formatSBUSData(uint16_t *channels, uint8_t *sbusData);
void sendSBUSData(uint8_t *sbusData);

void sendSbusChannels(uint16_t *sbusChannels);

#define SBUS_FRAME_SIZE 25

#endif /* LIB_SBUS_SBUS_H_ */
