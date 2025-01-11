/**
 * @file xMutexVirtualDisplay.cpp
 * @author Bartłomiej Głodek
 * @date 2024-12-29
 *
 * @brief
 * @details
 *
 *
 */

#include "xMutexVirtualDisplay.hpp"

xMutexVirtualDisplay::xMutexVirtualDisplay(){}

xMutexVirtualDisplay& xMutexVirtualDisplay::getInstance()
{
	static xMutexVirtualDisplay instance;
	if(instance.xMutexVirtualDisplay_ == nullptr)
	{
		instance.xMutexVirtualDisplay_ = xSemaphoreCreateMutex();
	}
	return instance;
}
void xMutexVirtualDisplay::lock()
{
    if (xSemaphoreTake(xMutexVirtualDisplay_, maxTimeout_) == pdFALSE)
    {
    	while (true);
    }
}
void xMutexVirtualDisplay::unlock()
{
    if (xSemaphoreGive(xMutexVirtualDisplay_) == pdFALSE)
    {
    	while (true);
    }
}

