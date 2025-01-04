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

#include "coordinatesTools.hpp"
#include "joystickTools.hpp"
#define JOY_D  0b00000001
#define JOY_U  0b00000010
#define JOY_L  0b00000100
#define JOY_R  0b00001000
#define JOY_OK 0b00010000

#include "entitiesInitData.hpp"

void vTaskVirtualDisplay(void *pvParameters)
{
	virtualDisplay *vDisplay = reinterpret_cast<virtualDisplay *>(pvParameters);
	uint8_t xQueueJoystick_data = 0;
	std::pair<coordinates,coordinates> pcords = {{135, 10},
												 {135, 10}};
	segment texture(EntitiesInitialData::player::texture_data);

	while(true)
	{
		xQueueJoystick_data=xQueueJoystick_Receive();
		pcords.second = pcords.first;
		pcords.first = JoystickTools::updateCoordinates(xQueueJoystick_data, pcords.first);
		pcords.first = coordinatesTools::stopRectangleOnBorderMap(pcords.first,pcords.first + EntitiesInitialData::player::texture_corner_2);
		xMutexVirtualDisplay_Lock();
		vDisplay->putEntity(pcords.first, pcords.second, texture);
		xMutexVirtualDisplay_Unlock();
/*		pcords.second = pcords.first;
		xMutexVirtualDisplay_Lock();
		//vDisplay->putEntity(e2coords, e2coords);
		xMutexVirtualDisplay_Unlock();
		xMutexVirtualDisplay_Lock();
		//vDisplay->putEntity(e1coords, e1coords);
		xMutexVirtualDisplay_Unlock();
		if (i % 500 == 0)
		{
			//e1coords.x += -1;
			e2coords.y += -1;
		}*/

		vTaskDelay(pdMS_TO_TICKS(10));
	}

}
