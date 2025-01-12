/**
 * @file vTaskSW3.cpp
 * @author Bartłomiej Głodek
 * @date 2024-12-31
 *
 * @brief
 * @details
 *
 *
 */

#include "vTaskSW3.hpp"
#include "SW3_Port.hpp"
#include "xQueueSW3.hpp"

using namespace SW3PortConsts;

void vTaskSW3(void *pvParameters)
{
	xQueueSW3& sw3Queue = xQueueSW3::getInstance();
	uint8_t state = 0x00;
	uint8_t state_prev = 0x00;
	uint8_t state_pressed = 0x00;
	uint8_t state_pressed_prev = 0x00;
	while(true)
	{
		//HAL_GPIO_TogglePin(LED_2_GPIO_Port, LED_2_Pin);
		state = SW3_Port_read();
		state_pressed = (~(state ^ state_prev)) & state; // pressed keys

		if (state_pressed == keys_released) // all keys released
		{

		}
		else
		{
			if ((~state_pressed_prev & state_pressed) != keys_released) // new key pressed
			{
				// key_state_pressed
				//HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin);
				sw3Queue.send(true);

			}
			else // can be used for auto-repeat
			{
				//sw3Queue.Send(true);
			}
		}

		state_pressed_prev = state_pressed;
		state_prev = state;
		vTaskDelay(50);
	}
}
