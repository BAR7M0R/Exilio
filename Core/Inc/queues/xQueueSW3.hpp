/**
 * @file xQueueJoystick
 * @author Bartłomiej Głodek
 * @date 2025-01-05
 *
 * @brief
 * @details
 *
 *
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
	static xQueueSW3& getInstance();
	void send(bool state);
	bool receive();
	static void controlTask(void *pvParameters);


private:
	static constexpr uint32_t maxTimeout_ = 1;
	static constexpr std::size_t queueSize_ = 1;
	static constexpr std::uint32_t activationDelayms_ = 666;
	bool queueActivation_;
	QueueHandle_t xQueueSW3_;
};
#endif /* INC_QUEUES_XQUEUESW3_HPP_ */
