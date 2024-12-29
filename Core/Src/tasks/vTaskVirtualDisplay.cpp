/*
 * vTaskVirtualDisplay.cpp
 *
 *  Created on: Dec 26, 2024
 *      Author: Bartłomiej Głodek
 */

#include <glcd.h>
#include "vTaskVirtualDisplay.hpp"
#include "xQueueJoystick.hpp"
#include "xMutexVirtualDisplay.hpp"
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
		xMutexVirtualDisplay_Lock();
		vDisplay->fill(xQueueJoystick_data);
		xMutexVirtualDisplay_Unlock();
		vTaskDelay(pdMS_TO_TICKS(10));
	}

}
