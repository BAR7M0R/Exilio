/**
 * @file xQueueJoystick
 * @author Bartłomiej Głodek
 * @date 2024-12-27
 *
 * @brief
 * @details
 *
 *
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
	static xQueueJoystick& getInstance();
	void Send(std::uint8_t state);
	std::uint8_t receive();

private:
	static constexpr uint32_t maxTimeout_ = 10;
	static constexpr std::size_t queueSize_ = 1;
	QueueHandle_t xQueueJoystick_;
};

#endif /* INC_QUEUES_XQUEUEJOYSTICK_HPP_ */
