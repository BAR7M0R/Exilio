/*
 * SW3_Port.cpp
 *
 *  Created on: Jan 4, 2025
 *      Author: dev
 */

#include <SW3_Port.hpp>
#include "main.h"
std::uint8_t SW3_Port_read()
{
	uint8_t key_state = 0;

	if (HAL_GPIO_ReadPin(SW3_GPIO_Port, SW3_Pin) == GPIO_PIN_RESET)
		key_state |= sw_3;
	return keys_released;
}
