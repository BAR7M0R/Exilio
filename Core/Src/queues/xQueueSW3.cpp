/*
 * xQueueSW3.cpp
 *
 *  Created on: Jan 5, 2025
 *      Author: dev
 */

#include <xQueueSW3.hpp>

xQueueSW3::xQueueSW3()
:xQueueSW3_(nullptr){}

xQueueSW3& xQueueSW3::GetInstance()
{
	static xQueueSW3 instance;
	if(instance.xQueueSW3_ == nullptr)
	{
		instance.xQueueSW3_ = xQueueCreate(queueSize_, sizeof(bool));  // Przykładowa kolejka
        if (instance.xQueueSW3_ == nullptr) {
            while(true);
        }
	}
	return instance;

}
void xQueueSW3::Send(bool state)
{
	if (xQueueSW3_ != nullptr)
	{
		if (xQueueSend(xQueueSW3_,
				static_cast<const void*>(&state),
				pdMS_TO_TICKS(maxTimeout_)) == pdFAIL)
		{
			while(true);
		}
	}
}
bool xQueueSW3::Receive()
{
	bool receivedValue = false;
	if (xQueueSW3_ != nullptr)
	{
	    if (xQueueReceive(xQueueSW3_,
	    		&receivedValue,
				pdMS_TO_TICKS(maxTimeout_)) == pdFAIL);
	    {
	    	receivedValue = false;
	    }
	}
    return receivedValue;
}
