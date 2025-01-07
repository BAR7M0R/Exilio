/**
 * @file xMutexPlayer.cpp
 * @author Bartłomiej Głodek
 * @date 2025-01-05
 *
 * @brief
 * @details
 *
 *
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
