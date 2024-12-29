/*
 * displaytask.cpp
 *
 *  Created on: Dec 24, 2024
 *      Author: Bartłomiej Głodek
 */

#include <vTaskDisplayLCD.hpp>

#include "FreeRTOS.h"
#include "task.h"
#include <glcd.h>

#include "main.h"

#include <stdint.h>

#include "virtualDisplay.hpp"

#include "xMutexVirtualDisplay.hpp"

void vTaskDisplayLCD(void *pvParameters)
{
	virtualDisplay *vDisplay = reinterpret_cast<virtualDisplay *>(pvParameters);

	glcd_Initialize();
	glcd_ClearScreen();
	//HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin);
	while(true)
	{
		xMutexVirtualDisplay_Lock();
		glcd_PutFrame(vDisplay->getMap());
		xMutexVirtualDisplay_Unlock();
		vTaskDelay(pdMS_TO_TICKS(100));
		HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin);
	}
}
