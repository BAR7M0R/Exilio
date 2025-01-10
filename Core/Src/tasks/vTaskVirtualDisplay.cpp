/**
 * @file vTaskVirtualDisplay.cpp
 * @author Bartłomiej Głodek
 * @date 2024-12-26
 *
 * @brief
 * @details
 *
 *
 */

#include <enemysManager.hpp>
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
#include "entitiesInitData.hpp"
/**
 * @fn void vTaskVirtualDisplay(void*)
 * @brief function to managing and generate virtual map.
 * @param pvParameters
 */
void vTaskVirtualDisplay(void *pvParameters)
{
	virtualDisplay& vDisplay = virtualDisplay::GetInstance();
	xMutexVirtualDisplay& mutexVD = xMutexVirtualDisplay::GetInstance();
	player& p = player::GetInstance();
	xQueueSW3& sw3Queue = xQueueSW3::GetInstance();
	xQueueJoystick& joystickQueue = xQueueJoystick::GetInstance();
	bullets& bs = bullets::GetInstance();
	enemys& es = enemys::GetInstance();


	//es.add(coordinates(40,8));
	//es.add(coordinates(50,8));
	//es.add(coordinates(60,8));
	//es.add(coordinates(70,8));
	//es.add(coordinates(80,8));
	//es.add(coordinates(90,8));

	while(true)
	{
		//es.add(coordinates(60,8));
		//es.add(coordinates(70,8));
		//es.add(coordinates(80,8));
		//es.add(coordinates(90,8));
		p.updatePosition(JoystickTools::convert(joystickQueue.Receive()));
		if(sw3Queue.Receive())
		{
			bs.add(p.getCurrentPosition() + coordinates({0,-1})+p.getOffset());
		}
		bs.move();
		es.move();

		for(bullet& b: bs)
		{
			if (b.isOnMap())
			{
				mutexVD.lock();
				vDisplay.putEntity(b.getCurrentCoords(), b.getPrevousCoords(), b.getTexture());
				mutexVD.unlock();
			}
		}
		for(enemy& e: es)
		{
			if (e.isOnMap())
			{
				mutexVD.lock();
				vDisplay.putEntity(e.getCurrentCoords(), e.getPrevousCoords(), e.getTexture());
				mutexVD.unlock();
			}
		}
		mutexVD.lock();
		vDisplay.putEntity(p.getCurrentPosition(), p.getPrevousPosition(), p.getTexture());
		mutexVD.unlock();
		bs.remove();
		es.remove();
		vTaskDelay(pdMS_TO_TICKS(100));
	}

}

