/*
 * mainapp.cpp
 *
 *  Created on: Dec 22, 2024
 *      Author: dev
 */

#include <vTaskDisplayLCD.hpp>
#include "mainapp.hpp"
#include "main.h"
#include "FreeRTOS.h"
#include "task.h"

#include <cstdint>
#include "glcd.h"


void mainapp()
{

	glcd_Initialize();
	glcd_ClearScreen();
	uint8_t printableFrame[128][64];
	  for (int i = 0; i < 64; i++)
	  { // Iteracja po wierszach
		  for (int j = 0; j < 128; j++) { // Iteracja po kolumnach
			  printableFrame[j][i] = 0xAA;
		  }
	  }
	 glcd_PutFrame(printableFrame);

	//xTaskCreate(vTaskDisplayLCD, "displaytask", 128, NULL, 1, NULL);

	//vTaskStartScheduler();


	while(true)
	{

		HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin | LED_2_Pin);
		HAL_Delay(1000);
	}
}
