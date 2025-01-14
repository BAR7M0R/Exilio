/**
 * @file xMutexVirtualDisplay.hpp
 * @author Bartłomiej Głodek
 * @date 2024-12-29
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

#ifndef SRC_MUTEXES_XMUTEXVIRTUALDISPLAY_HPP_
#define SRC_MUTEXES_XMUTEXVIRTUALDISPLAY_HPP_

#include "FreeRTOS.h"
#include "semphr.h"
/**
 * @class xMutexVirtualDisplay
 * @brief mutex singledon wraper class for handling virtual display it is used inside vTaskVirtualDisplay and vTaskDisplay
 * @see virtualDisplay.hpp
 * @see vTaskVirtualDisplay.hpp
 * @see vTaskDisplay.hpp
 */
class xMutexVirtualDisplay
{
private:
	xMutexVirtualDisplay();
	xMutexVirtualDisplay(const xMutexVirtualDisplay&) = delete;
	xMutexVirtualDisplay& operator=(const xMutexVirtualDisplay&) = delete;

public:
	static xMutexVirtualDisplay& getInstance();
	/**
	 * @fn void lock()
	 * @todo opis
	 */
	void lock();
	/**
	 * @fn void unlock()
	 * @todo opis
	 */
	void unlock();

private:
	static constexpr uint32_t maxTimeout_ = 10;
	SemaphoreHandle_t xMutexVirtualDisplay_ = nullptr;
};

#endif /* SRC_MUTEXES_XMUTEXVIRTUALDISPLAY_HPP_ */
