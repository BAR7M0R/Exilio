/**
 * @file xQueueJoystick.hpp
 * @author Bartłomiej Głodek
 * @date 2024-12-27
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
#ifndef INC_QUEUES_XQUEUEJOYSTICK_HPP_
#define INC_QUEUES_XQUEUEJOYSTICK_HPP_

#include <cstdint>
#include "FreeRTOS.h"
#include "queue.h"
/**
 * @class xQueueJoystick
 * @todo opis
 */
class xQueueJoystick
{
private:
	xQueueJoystick();
	xQueueJoystick(const xQueueJoystick&) = delete;
	xQueueJoystick& operator=(const xQueueJoystick&) = delete;

public:
	static xQueueJoystick& getInstance();
	/**
	 * @fn void Send(std::uint8_t)
	 * @param state
	 * @todo opis
	 */
	void Send(std::uint8_t state);
	/**
	 * @fn std::uint8_t receive()
	 * @return
	 * @todo opis
	 */
	std::uint8_t receive();

private:
	static constexpr uint32_t maxTimeout_ = 10;
	static constexpr std::size_t queueSize_ = 1;
	QueueHandle_t xQueueJoystick_;
};

#endif /* INC_QUEUES_XQUEUEJOYSTICK_HPP_ */
