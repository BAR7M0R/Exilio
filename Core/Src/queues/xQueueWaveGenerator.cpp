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
int xQueueWaveGenerator::activationDelayms_ = 1000;
xQueueWaveGenerator::xQueueWaveGenerator()
:xQueueWaveGenerator_(nullptr){}

xQueueWaveGenerator& xQueueWaveGenerator::getInstance()
{
	static xQueueWaveGenerator instance;
	if(!instance.xQueueWaveGenerator_)
	{
		instance.xQueueWaveGenerator_ = xQueueCreate(queueSize_, sizeof(bool));  // Przykładowa kolejka
        if (instance.xQueueWaveGenerator_ == nullptr) {
            while(true);
        }
		xTaskCreate(xQueueWaveGenerator::controlTask, "xQueueSW3ControlTask", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY +4, NULL);
	}
	return instance;

}
void xQueueWaveGenerator::send(entitiesInitialData::enemiGen eGen, std::uint16_t activationDelayms)
{
	if (xQueueWaveGenerator_)
	{
		activationDelayms_ = activationDelayms;
		xQueueSend(xQueueWaveGenerator_,static_cast<const void*>(&eGen),pdMS_TO_TICKS(maxTimeout_));
	}
}
entitiesInitialData::enemiGen xQueueWaveGenerator::receive()
{
	entitiesInitialData::enemiGen r;
	if (xQueueWaveGenerator_ and queueActivation_)
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

        vTaskDelay(pdMS_TO_TICKS(activationDelayms_));
    }
}
