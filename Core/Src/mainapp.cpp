/*
 * mainapp.cpp
 *
 *  Created on: Dec 22, 2024
 *      Author: dev
 */


#include "mainapp.hpp"
#include "main.h"
#include "FreeRTOS.h"
#include "task.h"

#include <cstdint>
#include "vTaskDisplayLCD.hpp"

#define STACK_SIZE 8192

void mainapp()
{
	xTaskCreate(vTaskDisplayLCD, "vTaskDisplayLCD", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);

	vTaskStartScheduler();
	while(true)
	{

		HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin | LED_2_Pin);
		HAL_Delay(1000);
	}
}
