/*
 * mainapp.cpp
 *
 *  Created on: Dec 22, 2024
 *      Author: Bartłomiej Głodek
 */

#include "mainapp.hpp"
#include "main.h"

#include "FreeRTOS.h"
#include "task.h"

#include "vTaskDisplayLCD.hpp"
#include "vTaskJoystick.hpp"
#include "vTaskSW3.hpp"
#include "vTaskVirtualDisplay.hpp"

void mainapp()
{
	xTaskCreate(vTaskDisplayLCD, "vTaskDisplayLCD", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 2, NULL);
	xTaskCreate(vTaskJoystick,"vTaskJoystick",configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 3, NULL);
	xTaskCreate(vTaskSW3,"vTaskSW3",configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY +4, NULL);

	xTaskCreate(vTaskVirtualDisplay, "vTaskVirtualDisplay", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);

	vTaskStartScheduler();

	while(true)
	  {
		;
	  }
}

