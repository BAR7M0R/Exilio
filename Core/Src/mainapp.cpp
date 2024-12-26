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

void mainapp()
{
	xTaskCreate(vTaskDisplayLCD, "displaytask", 128, NULL, 1, NULL);

	vTaskStartScheduler();


	while(true)
	{

		HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin | LED_2_Pin);
		HAL_Delay(1000);
	}
}
