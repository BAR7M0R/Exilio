/**
 * @file vTaskJoystick
 * @author Bartłomiej Głodek
 * @date 2024-12-27
 *
 * @brief
 * @details
 *
 *
 */
#include "joystick_port.h"
#include "vTaskJoystick.hpp"
#include "xQueueJoystick.hpp"
#include "FreeRTOS.h"
#include "task.h"



#include <cstdint>


void vTaskJoystick(void *pvParameters)
{
	xQueueJoystick& joystickQueue = xQueueJoystick::GetInstance();
	joystick_port_init();
	uint8_t keys_state = 0x00;
	uint8_t keys_state_prev = 0x00;
	uint8_t keys_state_pressed = 0x00;
	uint8_t keys_state_pressed_prev = 0x00;

	while(true)
	{
		//HAL_GPIO_TogglePin(LED_2_GPIO_Port, LED_2_Pin);
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
				//HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin);
				//xQueueJoystick_Send(keys_state_pressed);
				joystickQueue.Send(keys_state_pressed);


			}
			else // can be used for auto-repeat
			{
				joystickQueue.Send(keys_state_pressed);
			}
		}

		keys_state_pressed_prev = keys_state_pressed;
		keys_state_prev = keys_state;
		vTaskDelay(50);
	}
}
