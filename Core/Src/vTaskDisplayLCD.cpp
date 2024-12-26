/*
 * displaytask.cpp
 *
 *  Created on: Dec 24, 2024
 *      Author: dev
 */

#include "FreeRTOS.h"
#include "task.h"
#include "vTaskDisplayLCD.hpp"
#include <stdint.h>
#include "glcd.h"

#include <array>

std::array<std::array<uint8_t, 64>, 128> printableFrame = {{0}};

void vTaskDisplayLCD(void *pvParameters)
{
	glcd_Initialize();
	glcd_ClearScreen();

	std::array<uint8_t, 16> testSymbols{0x00, 0x11, 0x02, 0x33,0x04,0x55,0x06,0x77,0x08,0x99,0x0A,0xBB,0x0C,0xDD,0x0E,0xFF};

 	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_2_Pin, GPIO_PIN_RESET);
	std::size_t i = 0;
	while(true)
	{

		for (auto& row : printableFrame)
		{
			row.fill(testSymbols.at(i));
		}

		++i;
		if (i >= testSymbols.size()) { i = 0;}
		glcd_PutFrame(reinterpret_cast<uint8_t(*)[64]>(printableFrame.data()));
		HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin | LED_2_Pin);
		//glcd_PutFrame(printableFrame);
		vTaskDelay(1000);
	}
}
