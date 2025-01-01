/*
 * vTaskVirtualDisplay.cpp
 *
 *  Created on: Dec 26, 2024
 *      Author: Bartłomiej Głodek
 */

#include <glcd.h>
#include "vTaskVirtualDisplay.hpp"
#include "xQueueJoystick.hpp"
#include "xMutexVirtualDisplay.hpp"
#include "FreeRTOS.h"
#include "task.h"
#include <cstdint>
#include <array>

#include "virtualDisplay.hpp"

#define JOY_D  0b00000001
#define JOY_U  0b00000010
#define JOY_L  0b00000100
#define JOY_R  0b00001000
#define JOY_OK 0b00010000

void vTaskVirtualDisplay(void *pvParameters)
{
	virtualDisplay *vDisplay = reinterpret_cast<virtualDisplay *>(pvParameters);
	uint8_t xQueueJoystick_data = 0;
	std::pair<coordinates,coordinates> pcords = {{10, 10},
												 {10, 10}};
	coordinates e1coords = {virtualDisplay::MAX_X/2+10,virtualDisplay::MAX_Y/2+10};
	coordinates e2coords = {virtualDisplay::MAX_X/2+16,virtualDisplay::MAX_Y/2+1};
/*	for(int i = 0; i <45; ++i)
	{
		pcords.second = pcords.first;
		pcords.first.x +=1;
		pcords.first.y +=1;
		xMutexVirtualDisplay_Lock();
		vDisplay->putEntity(pcords.first, pcords.second);
		xMutexVirtualDisplay_Unlock();
		vTaskDelay(pdMS_TO_TICKS(10));
	}*/

	while(true)
	{
		xQueueJoystick_data=xQueueJoystick_Receive();
		pcords.second = pcords.first;
		if ((xQueueJoystick_data & JOY_D) == JOY_D) {++pcords.first.y;}
		if ((xQueueJoystick_data & JOY_U) == JOY_U) {--pcords.first.y;}
		if ((xQueueJoystick_data & JOY_L) == JOY_L) {--pcords.first.x;}
		if ((xQueueJoystick_data & JOY_R) == JOY_R) {++pcords.first.x;}
		xMutexVirtualDisplay_Lock();
		vDisplay->putEntity(pcords.first, pcords.second);
		xMutexVirtualDisplay_Unlock();
		xMutexVirtualDisplay_Lock();
		vDisplay->putEntity(e1coords, e1coords);
		xMutexVirtualDisplay_Unlock();
		xMutexVirtualDisplay_Lock();
		vDisplay->putEntity(e2coords, e2coords);
		xMutexVirtualDisplay_Unlock();

		vTaskDelay(pdMS_TO_TICKS(10));
	}

}
