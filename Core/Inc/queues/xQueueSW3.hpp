/*
 * xQueueSW3.hpp
 *
 *  Created on: Jan 5, 2025
 *      Author: Bartłomiej Głodek
 */

#ifndef INC_QUEUES_XQUEUESW3_HPP_
#define INC_QUEUES_XQUEUESW3_HPP_

#include <cstdint>
#include "FreeRTOS.h"
#include "queue.h"

class xQueueSW3
{
private:
	xQueueSW3();
	xQueueSW3(const xQueueSW3&) = delete;
	xQueueSW3& operator=(const xQueueSW3&) = delete;

public:
	static xQueueSW3& GetInstance();
	void Send(bool state);
	bool Receive();

private:
	static constexpr uint32_t maxTimeout_ = 100;
	static constexpr std::size_t queueSize_ = 100;
	QueueHandle_t xQueueSW3_;
};
#endif /* INC_QUEUES_XQUEUESW3_HPP_ */
