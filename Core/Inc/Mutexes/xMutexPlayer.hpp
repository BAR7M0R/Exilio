/*
 * xMutexPlayer.hpp
 *
 *  Created on: Jan 5, 2025
 *      Author: Bartłomiej Głdoek
 */

#ifndef INC_XMUTEXPLAYER_HPP_
#define INC_XMUTEXPLAYER_HPP_

#include "FreeRTOS.h"
#include "semphr.h"

class xMutexPlayer
{
private:
	xMutexPlayer();
	xMutexPlayer(const xMutexPlayer&) = delete;
	xMutexPlayer& operator=(const xMutexPlayer&) = delete;

public:
	static xMutexPlayer& GetInstance();
	void lock();
	void unlock();

private:
	static constexpr uint32_t maxTimeout_ = 10;
	SemaphoreHandle_t xMutexPlayer_;
};
#endif /* INC_XMUTEXPLAYER_HPP_ */
