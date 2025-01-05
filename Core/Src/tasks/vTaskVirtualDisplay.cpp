/*
 * vTaskVirtualDisplay.cpp
 *
 *  Created on: Dec 26, 2024
 *      Author: Bartłomiej Głodek
 */

#include <glcd.h>
#include "vTaskVirtualDisplay.hpp"
#include "xQueueJoystick.hpp"
#include "xQueueSW3.hpp"
#include "xMutexVirtualDisplay.hpp"
#include "FreeRTOS.h"
#include "task.h"
#include <cstdint>
#include <array>

#include "virtualDisplay.hpp"

#include "coordinatesTools.hpp"
#include "joystickTools.hpp"

#include "player.hpp"
#include "xMutexPlayer.hpp"

#define JOY_D  0b00000001
#define JOY_U  0b00000010
#define JOY_L  0b00000100
#define JOY_R  0b00001000
#define JOY_OK 0b00010000

#include "entitiesInitData.hpp"

void vTaskVirtualDisplay(void *pvParameters)
{
	player& p = player::GetInstance();
	xQueueSW3& sw3Queue = xQueueSW3::GetInstance();
	xQueueJoystick& joystickQueue = xQueueJoystick::GetInstance();

	virtualDisplay *vDisplay = reinterpret_cast<virtualDisplay *>(pvParameters);

	segment texture(EntitiesInitialData::player1::texture_data);
	std::pair<coordinates,coordinates> pcords = {{135, 10},{135, 10}};

	while(true)
	{
		//pcords.second = pcords.first;
		//pcords.first = pcords.first + JoystickTools::convert(joystickQueue.Receive());
		//pcords.first = coordinatesTools::stopRectangleOnBorderMap(pcords.first,pcords.first + EntitiesInitialData::player1::texture_corner_2);

		p.updatePosition(JoystickTools::convert(joystickQueue.Receive()));
		xMutexVirtualDisplay_Lock();
		//vDisplay->putEntity(pcords.first, pcords.second, texture);
		vDisplay->putEntity(p.getCurrentPosition(), p.getPrevousPosition(), p.getTexture());
		xMutexVirtualDisplay_Unlock();
		//if(sw3Queue.Receive())
		//{

		//}
		vTaskDelay(pdMS_TO_TICKS(10));
	}

}

