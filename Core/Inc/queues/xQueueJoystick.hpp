/*
 * xQueueJoystick.hpp
 *
 *  Created on: Dec 27, 2024
 *      Author: dev
 */

#ifndef INC_QUEUES_XQUEUEJOYSTICK_HPP_
#define INC_QUEUES_XQUEUEJOYSTICK_HPP_

#include <cstdint>
#include "FreeRTOS.h"
#include "queue.h"

class xQueueJoystick
{
private:
	xQueueJoystick();
	xQueueJoystick(const xQueueJoystick&) = delete;
	xQueueJoystick& operator=(const xQueueJoystick&) = delete;

public:
	static xQueueJoystick& GetInstance();
	void Send(std::uint8_t state);
	std::uint8_t Receive();

private:
	static constexpr uint32_t maxTimeout_ = 100;
	static constexpr std::size_t queueSize_ = 2;
	QueueHandle_t xQueueJoystick_;
};

#endif /* INC_QUEUES_XQUEUEJOYSTICK_HPP_ */
