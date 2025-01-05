/*
 * xQueueJoystick.cpp
 *
 *  Created on: Dec 27, 2024
 *      Author: Bartłomiej Głodek
 */

#include <cstdint>
#include "xQueueJoystick.hpp"

xQueueJoystick::xQueueJoystick()
:xQueueJoystick_(nullptr){}

xQueueJoystick& xQueueJoystick::GetInstance()
{
	static xQueueJoystick instance;
	if(instance.xQueueJoystick_ == nullptr)
	{
		instance.xQueueJoystick_ = xQueueCreate(queueSize_, sizeof(bool));  // Przykładowa kolejka
        if (instance.xQueueJoystick_ == nullptr) {
            while(true);
        }
	}
	return instance;

}
void xQueueJoystick::Send(std::uint8_t state)
{
	if (xQueueJoystick_ != nullptr)
	{
		if (xQueueSend(xQueueJoystick_,
				static_cast<const void*>(&state),
				pdMS_TO_TICKS(maxTimeout_)) == pdFAIL)
		{
			;
		}
	}
}
std::uint8_t xQueueJoystick::Receive()
{
	std::uint8_t receivedValue = 0;
	if (xQueueJoystick_ != nullptr)
	{
	    if (xQueueReceive(xQueueJoystick_,
	    		&receivedValue,
				pdMS_TO_TICKS(maxTimeout_)) == pdFAIL)
	    {
	    	;
	    }
	}
    return receivedValue;
}
