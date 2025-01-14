/**
 * @file xQueueSW3.hpp
 * @author Bartłomiej Głodek
 * @date 2025-01-05
 *
 * @copyright
 * Copyright (c) Bartłomiej Głodek 2025
 * Permission is granted to use, copy, modify, and distribute this software for any non-commercial purpose, free of charge.
 * For commercial use, you must notify the author and obtain permission before using this software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES, OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT, OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * @brief
 * @details
 * @todo opis
 *
 */
#ifndef INC_QUEUES_XQUEUESW3_HPP_
#define INC_QUEUES_XQUEUESW3_HPP_

#include <cstdint>
#include "FreeRTOS.h"
#include "queue.h"
/**
 * @class xQueueSW3
 * @todo opis
 */
class xQueueSW3
{
private:
	xQueueSW3();
	xQueueSW3(const xQueueSW3&) = delete;
	xQueueSW3& operator=(const xQueueSW3&) = delete;
public:
	static xQueueSW3& getInstance();
	/**
	 * @fn void send(bool)
	 * @param state
	 * @todo opis
	 */
	void send(bool state);
	/**
	 * @fn bool receive()
	 * @return
	 * @todo opis
	 */
	bool receive();
	/**
	 * @fn void controlTask(void*)
	 * @param pvParameters
	 */
	static void controlTask(void *pvParameters);


private:
	static constexpr uint32_t maxTimeout_ = 1;
	static constexpr std::size_t queueSize_ = 1;
	static constexpr std::uint32_t activationDelayms_ = 666;
	bool queueActivation_;
	QueueHandle_t xQueueSW3_;
};
#endif /* INC_QUEUES_XQUEUESW3_HPP_ */
