/**
 * @file mainapp.cpp
 * @author Bartłomiej Głodek
 * @date 2024-12-22
 *
 * @brief
 * @details
 *
 *
 */


#include "mainapp.hpp"
#include "main.h"

#include "FreeRTOS.h"
#include "task.h"

#include "vTaskDisplayLCD.hpp"
#include "vTaskJoystick.hpp"
#include "vTaskSW3.hpp"
#include "vTaskVirtualDisplay.hpp"
#include "vTaskWaveGenerator.hpp"

#include "xQueueWaveGenerator.hpp"
#include "xQueueSW3.hpp"
void mainapp(void)
{
	xTaskCreate(vTaskDisplayLCD, "vTDisplayLCD", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 2, NULL);
	xTaskCreate(vTaskJoystick,"vTJoystick",configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 3, NULL);
	xTaskCreate(vTaskSW3,"vTSW3",configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY +4, NULL);
	xTaskCreate(vTaskVirtualDisplay, "vTVirtualDisplay", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);
	xTaskCreate(vTaskWaveGenerator,"vTWGen", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 2, NULL);
	xTaskCreate(xQueueWaveGenerator::controlTask, "xQWaveGenCT", 32, NULL, tskIDLE_PRIORITY +5, NULL);
	xTaskCreate(xQueueSW3::controlTask, "xQSW3CT", 32, NULL, tskIDLE_PRIORITY +5, NULL);
	vTaskStartScheduler();

	while(true);

}

