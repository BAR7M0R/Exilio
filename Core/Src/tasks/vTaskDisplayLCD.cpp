/**
 * @file displaytask.cpp
 * @author Bartłomiej Głodek
 * @date 2024-12-24
 *
 * @brief Implementation of FreeRTOS task for updating the GLCD screen with a virtual display map.
 * @details
 * - Initializes the GLCD screan at startup
 * - Uses a mutex for synchronized access to the virtual display.
 * - Toggles an LED to signal task execution.
 * - operates in a FreeRTOS enviroment with periodic delays.
 *
 * @todo remove HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin); line before publish
 * @todo remove #include "main.h" -||-
 *
 * This file uses the following libraries:
 * - FreeRTOS.h and task.h: For FreeRTOS task management.
 * - cstdint: for basic data types.
 * - glcd.h: To interact with the GLCD hardware.
 * - virtualDisplay.hpp: To access the virtual display object.
 * - xMutexVirtualDisplay.hpp: For synchronized access to virtual display object.
 *
 */
#include "vTaskDisplayLCD.hpp"
#include "FreeRTOS.h"
#include "task.h"
#include <cstdint>
#include <glcd.h>
#include "virtualDisplay.hpp"
#include "xMutexVirtualDisplay.hpp"

#ifdef DEBUG
#include "main.h"
#endif

/**
 * @brief task function to set virtual map on GLCD screan.
 * @fn void vTaskDisplayLCD(void*)
 * @param[in] pvParameters Unused. Pass 'NULL' when creating the task.
 * @see mainapp.cpp
 */
void vTaskDisplayLCD(void *pvParameters)
{
	virtualDisplay& vDisplay = virtualDisplay::getInstance();
	xMutexVirtualDisplay& mutexVD = xMutexVirtualDisplay::getInstance();

	glcd_Initialize();
	glcd_ClearScreen();

	while(true)
	{
		mutexVD.lock();
		glcd_PutFrame(vDisplay.getMap());
		mutexVD.unlock();
		#ifdef DEBUG
		HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin); //to remove
		#endif
		vTaskDelay(pdMS_TO_TICKS(40));
	}
}
