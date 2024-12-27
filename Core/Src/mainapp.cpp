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
#include "queue.h"

#include <cstdint>

#include "virtualDisplay.hpp"

#include "vTaskDisplayLCD.hpp"
#include "vTaskVirtualDisplay.hpp"
#include <array>

#include "glcd.h"

#define STACK_SIZE 8192
constexpr std::size_t virtualMapHight = GLCD_HEIGHT + 2;
constexpr std::size_t virtualMapWidth = GLCD_WIDTH + 16;

virtualDisplay vMap;

void mainapp()
{

	joyQueue = xQueueCreate(1, sizeof(uint8_t));

	xTaskCreate(vTaskDisplayLCD, "vTaskDisplayLCD", configMINIMAL_STACK_SIZE, reinterpret_cast<void *>(&vMap), tskIDLE_PRIORITY + 1, NULL);
	//xTaskCreate(vTaskVirtualDisplay, "vTaskVirtualDisplay", configMinimal_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);
	//xTaskCreate(vTaskJoy,"vTaskJoy",configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY +1, NULL);
	//xTaskCreate(vTaskButton,"vTaskButton",configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY +1, NULL);

	vTaskStartScheduler();
	while(true)
	{

		HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin | LED_2_Pin);
		HAL_Delay(1000);
	}
}

//singledon class provided basic functionality on virtual map

