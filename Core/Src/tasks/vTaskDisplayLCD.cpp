/*
 * displaytask.cpp
 *
 *  Created on: Dec 24, 2024
 *      Author: Bartłomiej Głodek
 */

#include <glcd.h>
#include "FreeRTOS.h"
#include "task.h"


#include <stdint.h>
#include <vTaskDisplayLCD.hpp>
#include "virtualDisplay.hpp"

void vTaskDisplayLCD(void *pvParameters)
{
	virtualDisplay *vDisplay = reinterpret_cast<virtualDisplay *>(pvParameters);

	glcd_Initialize();
	glcd_ClearScreen();

	while(true)
	{
		taskENTER_CRITICAL();
		glcd_PutFrame(vDisplay->getMap());
		taskEXIT_CRITICAL();
	}
}
