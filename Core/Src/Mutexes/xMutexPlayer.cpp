/*
 * xMutexPlayer.cpp
 *
 *  Created on: Jan 5, 2025
 *      Author: dev
 */

#include "xMutexPlayer.hpp"

xMutexPlayer::xMutexPlayer()
:xMutexPlayer_(nullptr){}

xMutexPlayer& xMutexPlayer::GetInstance()
{
	static xMutexPlayer instance;
	if(instance.xMutexPlayer_ == nullptr)
	{
		instance.xMutexPlayer_ = xSemaphoreCreateMutex();
	}
	return instance;
}
void xMutexPlayer::lock()
{
    if (xSemaphoreTake(xMutexPlayer_, maxTimeout_) == pdFALSE)
    {
    	while (true);
    }
}
void xMutexPlayer::unlock()
{
    if (xSemaphoreGive(xMutexPlayer_) == pdFALSE)
    {
    	while (true);
    }
}
