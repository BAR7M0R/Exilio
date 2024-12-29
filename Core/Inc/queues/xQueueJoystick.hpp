/*
 * xQueueJoystick.hpp
 *
 *  Created on: Dec 27, 2024
 *      Author: dev
 */

#ifndef INC_QUEUES_XQUEUEJOYSTICK_HPP_
#define INC_QUEUES_XQUEUEJOYSTICK_HPP_

#ifndef __cplusplus
extern "C" {
#endif

#include "FreeRTOS.h"
#include "queue.h"

extern void xQueueJoystick_Init();
extern void xQueueJoystick_Send(uint8_t value);
extern uint8_t xQueueJoystick_Receive();

#ifndef __cplusplus
}
#endif

#endif /* INC_QUEUES_XQUEUEJOYSTICK_HPP_ */
