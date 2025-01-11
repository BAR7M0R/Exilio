/**
 * @file xMutexVirtualDisplay.hpp
 * @author Bartłomiej Głodek
 * @date 2024-12-29
 *
 * @brief
 * @details
 *
 *
 */

#ifndef SRC_MUTEXES_XMUTEXVIRTUALDISPLAY_HPP_
#define SRC_MUTEXES_XMUTEXVIRTUALDISPLAY_HPP_

#include "FreeRTOS.h"
#include "semphr.h"

class xMutexVirtualDisplay
{
private:
	xMutexVirtualDisplay();
	xMutexVirtualDisplay(const xMutexVirtualDisplay&) = delete;
	xMutexVirtualDisplay& operator=(const xMutexVirtualDisplay&) = delete;

public:
	static xMutexVirtualDisplay& getInstance();
	void lock();
	void unlock();

private:
	static constexpr uint32_t maxTimeout_ = 10;
	SemaphoreHandle_t xMutexVirtualDisplay_ = nullptr;
};

#endif /* SRC_MUTEXES_XMUTEXVIRTUALDISPLAY_HPP_ */
