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
#include "vTaskSW3.hpp"
#include "vTaskUpdatePlayer.hpp"

#include "xMutexVirtualDisplay.hpp"

#include "virtualDisplay.hpp"


#include <cstdint>
#include <array>






virtualDisplay vDisplay;

void mainapp()
{

	//here define tasks
	xTaskCreate(vTaskDisplayLCD, "vTaskDisplayLCD", configMINIMAL_STACK_SIZE, reinterpret_cast<void *>(&vDisplay), tskIDLE_PRIORITY + 2, NULL);
	xTaskCreate(vTaskVirtualDisplay, "vTaskVirtualDisplay", configMINIMAL_STACK_SIZE, reinterpret_cast<void *>(&vDisplay), tskIDLE_PRIORITY + 1, NULL);
	xTaskCreate(vTaskJoystick,"vTaskJoystick",configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 3, NULL);
	xTaskCreate(vTaskSW3,"vTaskSW3",configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY +3, NULL);
	//xTaskCreate(vTaskUpdatePlayer, "vTaskUpdatePlayer", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY +2, NULL);
	//here define queues
	//xQueueJoystick_Init();
	xMutexVirtualDisplay_Init();

	vTaskStartScheduler();

	while(true)
	  {
		;
	  }
}

