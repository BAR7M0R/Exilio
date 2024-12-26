/*
 * displaytask.cpp
 *
 *  Created on: Dec 24, 2024
 *      Author: dev
 */

#include "FreeRTOS.h"
#include "task.h"
#include "vTaskDisplayLCD.hpp"
#include "glcd.h"

void vTaskDisplayLCD(void *pvParameters)
{
	/*glcd_ClearScreen();
	uint8_t printableFrame[128][64];
	uint8_t testSymbols[16] = {0x00, 0x01, 0x02, 0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F};
	  for (int i = 0; i < 64; i++)
	  { // Iteracja po wierszach
		  for (int j = 0; j < 128; j++) { // Iteracja po kolumnach
			  printableFrame[j][i] = 0x09;
		  }
	  }
*/
	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_2_Pin, GPIO_PIN_RESET);
	while(true)
	{

		HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin | LED_2_Pin);
		//glcd_PutFrame(printableFrame);
		vTaskDelay(1000);
	}
}
