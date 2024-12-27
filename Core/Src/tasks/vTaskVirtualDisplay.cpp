/*
 * vTaskVirtualDisplay.cpp
 *
 *  Created on: Dec 26, 2024
 *      Author: dev
 */



#include "FreeRTOS.h"
#include "task.h"
#include "vTaskVirtualDisplay.hpp"
#include <stdint.h>
#include "glcd.h"

#include <array>

void vTaskVirtualDisplay(void *pvParameters)
{
	glcd_Initialize();
	glcd_ClearScreen();

	while(true)
	{


		vTaskDelay(100);
	}
}
