/**
 * @file xQueueSW3.cpp
 * @author Bartłomiej Głodek
 * @date 2025-01-05
 *
 * @brief
 * @details
 *
 *
 */

#include <xQueueSW3.hpp>
#include "task.h"
xQueueSW3::xQueueSW3()
:xQueueSW3_(nullptr){}

xQueueSW3& xQueueSW3::getInstance()
{
	static xQueueSW3 instance;
	if(!instance.xQueueSW3_)
	{
		instance.xQueueSW3_ = xQueueCreate(queueSize_, sizeof(bool));  // Przykładowa kolejka
        if (instance.xQueueSW3_ == nullptr) {
            while(true);
        }

	}
	return instance;

}
void xQueueSW3::send(bool state)
{
	if (xQueueSW3_)
	{
		xQueueSend(xQueueSW3_,static_cast<const void*>(&state),pdMS_TO_TICKS(maxTimeout_));
	}
}
bool xQueueSW3::receive()
{
	bool receivedValue = false;
	if (xQueueSW3_ and queueActivation_)
	{
		xQueueReceive(xQueueSW3_, &receivedValue, pdMS_TO_TICKS(maxTimeout_));
		queueActivation_ = false;
	}
    return receivedValue;
}
extern "C" void xQueueSW3::controlTask(void *pvParameters)
{
	xQueueSW3& instance = xQueueSW3::getInstance();
    while (true)
    {

        instance.queueActivation_ = true;

        vTaskDelay(pdMS_TO_TICKS(activationDelayms_));
    }
}
