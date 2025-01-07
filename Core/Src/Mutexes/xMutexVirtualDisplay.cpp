/*
 * xMutexVirtualDisplay.cpp
 *
 *  Created on: Dec 29, 2024
 *      Author: dev
 */

#include "FreeRTOS.h"
#include "semphr.h"

#include "xMutexVirtualDisplay.hpp"
SemaphoreHandle_t xMutexVirtualDisplay = NULL;
constexpr uint32_t xMutexVirtualDisplay_max_delay = 100;

void xMutexVirtualDisplay_Init()
{
	xMutexVirtualDisplay = xSemaphoreCreateRecursiveMutex();

    if (xMutexVirtualDisplay == NULL)
    {
        while (true);
    }
}

void xMutexVirtualDisplay_Lock()
{
    if (xSemaphoreTake(xMutexVirtualDisplay, pdMS_TO_TICKS(xMutexVirtualDisplay_max_delay)) == pdFALSE)
    {
    	while (true);
    }
}

void xMutexVirtualDisplay_Unlock()
{
    if (xSemaphoreGive(xMutexVirtualDisplay) == pdFALSE)
    {
    	while (true);
    }
}
