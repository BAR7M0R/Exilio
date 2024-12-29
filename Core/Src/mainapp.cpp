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
#include "queue.h"

#include "vTaskDisplayLCD.hpp"
#include "vTaskJoystick.hpp"
#include "vTaskVirtualDisplay.hpp"

#include "xQueueJoystick.hpp"

#include "virtualDisplay.hpp"


#include <cstdint>
#include <array>






virtualDisplay vDisplay;

void mainapp()
{
vTaskDisplayLCD(NULL);
	//here define tasks
	xTaskCreate(vTaskDisplayLCD, "vTaskDisplayLCD", configMINIMAL_STACK_SIZE, reinterpret_cast<void *>(&vDisplay), tskIDLE_PRIORITY + 1, NULL);
	xTaskCreate(vTaskVirtualDisplay, "vTaskVirtualDisplay", configMINIMAL_STACK_SIZE, reinterpret_cast<void *>(&vDisplay), tskIDLE_PRIORITY + 1, NULL);
	//xTaskCreate(vTaskJoystick,"vTaskJoystick",configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);
	//xTaskCreate(vTaskButton,"vTaskButton",configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY +1, NULL);
	//here define queues
	//xQueueJoystick_Init();


	vTaskStartScheduler();

	while(true)
	  {

	  }
}

