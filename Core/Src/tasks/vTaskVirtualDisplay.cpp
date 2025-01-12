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
#include "vTaskVirtualDisplay.hpp"
#include <FreeRTOS.h>
#include <task.h>
#include <cstdint>

#include "virtualDisplay.hpp"

#include "xMutexVirtualDisplay.hpp"

#include "xQueueJoystick.hpp"
#include "xQueueSW3.hpp"
#include "xQueueWaveGenerator.hpp"

#include "player.hpp"
#include "enemyBase.hpp"
#include "bulletBase.hpp"

#include "enemysManager.hpp"
#include "bulletsManager.hpp"

#include "entitiesInitData.hpp"
#include "coordinates.hpp"
#include "joystickTools.hpp"
#include "coordinatesTools.hpp"

#include "portable.h"

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
	xQueueWaveGenerator& waveGeneratorQueue = xQueueWaveGenerator::getInstance();
	bulletsManager& bManager = bulletsManager::getInstance();
	enemysManager& eManager = enemysManager::getInstance();
	while(true)
	{

		enemiGen eGen = waveGeneratorQueue.receive();
		if(!eGen.isGenerated)
		{
			eManager.add(eGen.type, eGen.position);
			eGen.isGenerated = true;
		}
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

