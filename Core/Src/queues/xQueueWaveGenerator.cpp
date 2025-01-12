/**
 * @file xQueueWaveGenerator.cpp
 * @author Bartłomiej Głodek
 * @date 2025-01-11
 *
 * @brief
 * @details
 *
 *
 */

#include <xQueueWaveGenerator.hpp>
#include "task.h"

uint32_t xQueueWaveGenerator::activationDelayms_ = 1000;

xQueueWaveGenerator::xQueueWaveGenerator()
:xQueueWaveGenerator_(nullptr){
}

xQueueWaveGenerator& xQueueWaveGenerator::getInstance()
{
	static xQueueWaveGenerator instance;
	if(!instance.xQueueWaveGenerator_)
	{
		instance.xQueueWaveGenerator_ = xQueueCreate(queueSize_, sizeof(entitiesInitialData::enemiGen));  // Przykładowa kolejka
        if (instance.xQueueWaveGenerator_ == nullptr) {
            while(true);
        }

	}
	return instance;

}
void xQueueWaveGenerator::send(entitiesInitialData::enemiGen eGen, std::uint16_t activationDelayms)
{
	if (uxQueueMessagesWaiting(xQueueWaveGenerator_) == 0)
	{
		if (xQueueSend(xQueueWaveGenerator_,static_cast<const void*>(&eGen),pdMS_TO_TICKS(maxTimeout_)) != pdPASS) {
			while(true);
		}
	}
}
entitiesInitialData::enemiGen xQueueWaveGenerator::receive()
{
	entitiesInitialData::enemiGen r;
	if (xQueueWaveGenerator_ !=nullptr and queueActivation_)
	{
		xQueueReceive(xQueueWaveGenerator_, &r, pdMS_TO_TICKS(maxTimeout_));
		queueActivation_ = false;
	}
    return r;
}
extern "C" void xQueueWaveGenerator::controlTask(void *pvParameters)
{
	xQueueWaveGenerator& instance = xQueueWaveGenerator::getInstance();
    while (true)
    {

        instance.queueActivation_ = true;

        vTaskDelay(pdMS_TO_TICKS(instance.activationDelayms_));
    }
}
