/**
 * @file xMutexVirtualDisplay.cpp
 * @author Bartłomiej Głodek
 * @date 2024-12-29
 *
 * @brief
 * @details
 *
 *
 *//*
 * xMutexVirtualDisplay.cpp
 *
 *  Created on: Dec 29, 2024
 *      Author: dev
 */

#include "xMutexVirtualDisplay.hpp"

xMutexVirtualDisplay::xMutexVirtualDisplay(){}

xMutexVirtualDisplay& xMutexVirtualDisplay::GetInstance()
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

