/*
 * vTaskUpdatePlayer.cpp
 *
 *  Created on: Jan 5, 2025
 *      Author: Bartłomiej Głodek
 */

#include "vTaskUpdatePlayer.hpp"
#include "coordinates.hpp"
#include "segment.hpp"
#include "entitiesInitData.hpp"
#include "xQueueJoystick.hpp"
#include "xQueueSW3.hpp"
#include "xMutexPlayer.hpp"
#include "player.hpp"
#include "joystickTools.hpp"

#include "bullets.hpp"
void vTaskUpdatePlayer(void *pvParameters)
{
	player& p = player::GetInstance();
	xMutexPlayer& pMutex =  xMutexPlayer::GetInstance();
	xQueueSW3& sw3Queue = xQueueSW3::GetInstance();
	xQueueJoystick& joystickQueue = xQueueJoystick::GetInstance();
	bullets& bs = bullets::GetInstance();
	while(true)
	{
		pMutex.lock();
		p.updatePosition(JoystickTools::convert(joystickQueue.Receive()));
		pMutex.unlock();
		if (sw3Queue.Receive())
		{
			bs.add(p.getCurrentPosition()+coordinates({0,1}));
		}
		bs.move();
		bs.remove();
	}
}
