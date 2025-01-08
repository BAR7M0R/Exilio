/**
 * @file SW3_Port.cpp
 * @author Bartłomiej Głodek
 * @date 2025-01-04
 *
 *
 */
#include <SW3_Port.hpp>
#include "main.h"
/**
 * @fn std::uint8_t SW3_Port_read()
 * @return state of SW3 button value should be 0 for low state 1 for hight state
 */
std::uint8_t SW3_Port_read()
{
	using namespace SW3PortConsts;
	uint8_t key_state = 0;

	if (HAL_GPIO_ReadPin(SW3_GPIO_Port, SW3_Pin) == GPIO_PIN_RESET)
		key_state |= sw_3;
	return key_state;
}
