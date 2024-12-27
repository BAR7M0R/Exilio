/*
 * vTaskJoystick.cpp
 *
 *  Created on: Dec 27, 2024
 *      Author: dev
 */

#include "FreeRTOS.h"
#include "task.h"

#include "joystick_port.h"

#include <stdint.h>
#include <vTaskJoystick.hpp>


void vTaskJoy(void *pvParameters)
{
	uint8_t keys_state = 0x00;
	uint8_t keys_state_prev = 0x00;
	uint8_t keys_state_pressed = 0x00;
	uint8_t keys_state_pressed_prev = 0x00;

	while(true)
	{
		keys_state = joystick_port_read();
		keys_state_pressed = (~(keys_state ^ keys_state_prev)) & keys_state; // pressed keys

		if (keys_state_pressed == KEYS_RELEASED) // all keys released
		{

		}
		else
		{
			if ((~keys_state_pressed_prev & keys_state_pressed) != KEYS_RELEASED) // new key pressed
			{
				// key_state_pressed
				//xQueueSend(xQueueKeys, &keys_state_pressed, portMAX_DELAY);
			}
			else // can be used for auto-repeat
			{
				// key_state_pressed
			}
		}

		keys_state_pressed_prev = keys_state_pressed;
		keys_state_prev = keys_state;
	}
}
