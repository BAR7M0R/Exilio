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

#include "bullets.hpp"
#include "enemys.hpp"
#include "entitiesInitData.hpp"

void vTaskVirtualDisplay(void *pvParameters)
{
	player& p = player::GetInstance();
	xQueueSW3& sw3Queue = xQueueSW3::GetInstance();
	xQueueJoystick& joystickQueue = xQueueJoystick::GetInstance();

	virtualDisplay *vDisplay = reinterpret_cast<virtualDisplay *>(pvParameters);
	bullets& bs = bullets::GetInstance();
	enemys& es = enemys::GetInstance();
	es.add(coordinates(40,8));
	es.add(coordinates(50,8));
	es.add(coordinates(60,8));
	es.add(coordinates(70,8));
	es.add(coordinates(80,8));
	es.add(coordinates(90,8));

	while(true)
	{
		//pcords.second = pcords.first;
		//pcords.first = pcords.first + JoystickTools::convert(joystickQueue.Receive());
		//pcords.first = coordinatesTools::stopRectangleOnBorderMap(pcords.first,pcords.first + EntitiesInitialData::player1::texture_corner_2);
		es.add(coordinates(60,8));
		es.add(coordinates(70,8));
		es.add(coordinates(80,8));
		es.add(coordinates(90,8));
		p.updatePosition(JoystickTools::convert(joystickQueue.Receive()));
		if(sw3Queue.Receive())
		{
			bs.add(p.getCurrentPosition() + coordinates({0,-1})+p.getOffset());
		}
		bs.move();
		es.move();

		//xMutexVirtualDisplay_Lock();
		for(bullet& b: bs)
		{
			if (b.isOnMap())
			{
				vDisplay->putEntity(b.getCurrentCoords(), b.getPrevousCoords(), b.getTexture());
			}
		}
		for(enemy& e: es)
		{
			if (e.isOnMap())
			{
				vDisplay->putEntity(e.getCurrentCoords(), e.getPrevousCoords(), e.getTexture());
			}
		}
		vDisplay->putEntity(p.getCurrentPosition(), p.getPrevousPosition(), p.getTexture());
		//xMutexVirtualDisplay_Unlock();
		bs.remove();
		es.remove();
		vTaskDelay(pdMS_TO_TICKS(100));
	}

}

