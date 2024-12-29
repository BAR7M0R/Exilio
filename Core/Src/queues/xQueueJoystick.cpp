/*
 * xQueueJoystick.cpp
 *
 *  Created on: Dec 27, 2024
 *      Author: Bartłomiej Głodek
 */

#include <cstdint>

//<to remove>
#include <main.h>
#include <xQueueJoystick.hpp>

constexpr uint32_t xQueueJoystickMaxTimeout = 100;
constexpr uint32_t xQueueJoystickSize = 16;

QueueHandle_t xQueueJoystick;

void xQueueJoystick_Init()
{
	xQueueJoystick = xQueueCreate(xQueueJoystickSize, sizeof(uint8_t));

}
void xQueueJoystick_Send(uint8_t value)
{
	if (xQueueSend(xQueueJoystick, static_cast<const void*>(&value), pdMS_TO_TICKS(xQueueJoystickMaxTimeout)) == pdFAIL)
	{
		while(true) {HAL_Delay(100); HAL_GPIO_TogglePin(LED_2_GPIO_Port, LED_2_Pin);}
	}
}
uint8_t xQueueJoystick_Receive()
{
    uint8_t receivedValue;
    if (xQueueJoystick != errQUEUE_EMPTY)
    {
        xQueueReceive(xQueueJoystick, &receivedValue, pdMS_TO_TICKS(xQueueJoystickMaxTimeout));  // Czekaj na dane
    }
    else
    {
    	while(true);
    }
    return receivedValue;
}
