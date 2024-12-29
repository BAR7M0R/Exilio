/*
 * vTaskVirtualDisplay.cpp
 *
 *  Created on: Dec 26, 2024
 *      Author: Bartłomiej Głodek
 */

#include <glcd.h>
#include <vTaskVirtualDisplay.hpp>
#include <xQueueJoystick.hpp>
#include <xQueueJoystick.hpp>
#include "FreeRTOS.h"
#include "task.h"
#include <cstdint>
#include <array>

#include "virtualDisplay.hpp"

void vTaskVirtualDisplay(void *pvParameters)
{
	virtualDisplay *vDisplay = reinterpret_cast<virtualDisplay *>(pvParameters);
	uint8_t xQueueJoystick_data = 0;
	while(true)
	{
		xQueueJoystick_data=xQueueJoystick_Receive();
		taskENTER_CRITICAL();
		vDisplay->fill(xQueueJoystick_data);
		taskEXIT_CRITICAL();
		//vTaskDelay(100);
	}

}
