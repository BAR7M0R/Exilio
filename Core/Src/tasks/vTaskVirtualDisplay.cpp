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

#include <bulletsManager.hpp>
#include <enemysManager.hpp>
#include <bulletBase.hpp>
#include "enemyBase.hpp"
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

#include "entitiesInitData.hpp"
/**
 * @fn void vTaskVirtualDisplay(void*)
 * @brief function to managing and generate virtual map.
 * @param pvParameters
 */
void vTaskVirtualDisplay(void *pvParameters)
{
	virtualDisplay& vDisplay = virtualDisplay::getInstance();
	xMutexVirtualDisplay& mutexVD = xMutexVirtualDisplay::getInstance();
	player& p = player::getInstance();
	xQueueSW3& sw3Queue = xQueueSW3::getInstance();
	xQueueJoystick& joystickQueue = xQueueJoystick::getInstance();
	//xQueueWaveGenerator& waveGeneratorQueue = xQueueWaveGenerator::getInstance();
	bulletsManager& bManager = bulletsManager::getInstance();
	enemysManager& eManager = enemysManager::getInstance();

		eManager.add(entitiesInitialData::enemys::enemy1, coordinates(60,0));
		eManager.add(entitiesInitialData::enemys::enemy2, coordinates(70,0));
		eManager.add(entitiesInitialData::enemys::enemy3, coordinates(80,0));
		eManager.add(entitiesInitialData::enemys::enemy1, coordinates(90,0));

	while(true)
	{


		p.updatePosition(joystickTools::convert(joystickQueue.receive()));
		if(sw3Queue.receive())
		{
			bManager.add(bullets::bullet1, p.getCurrentPosition()+p.getOffset());
		}
		eManager.chackCollisions();
		bManager.move();
		eManager.move();
		for(std::unique_ptr<bulletBase>& b: bManager)
		{
			if (b !=nullptr)
			{
				mutexVD.lock();
				vDisplay.putEntity(b->getCurrentCoords(), b->getPrevousCoords(), b->getTexture());
				mutexVD.unlock();
			}
		}
		for(std::unique_ptr<enemyBase>& e: eManager)
		{
			if (e != nullptr)
			{
				mutexVD.lock();
				vDisplay.putEntity(e->getCurrentCoords(), e->getPrevousCoords(), e->getTexture());
				mutexVD.unlock();
			}
		}
		mutexVD.lock();
		vDisplay.putEntity(p.getCurrentPosition(), p.getPrevousPosition(), p.getTexture());
		mutexVD.unlock();

		bManager.remove();
		eManager.remove();
		vTaskDelay(pdMS_TO_TICKS(100));
	}

 }

