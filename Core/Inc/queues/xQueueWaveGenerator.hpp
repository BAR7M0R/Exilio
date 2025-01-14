/**
 * @file xQueueWaveGenerator.hpp
 * @author Bartłomiej Głodek
 * @date 2025-01-11
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
#ifndef INC_QUEUES_XQUEUEWAVEGENERATOR_HPP_
#define INC_QUEUES_XQUEUEWAVEGENERATOR_HPP_

#include <cstdint>
#include "FreeRTOS.h"
#include "queue.h"
#include "entitiesInitData.hpp"
#include "coordinates.hpp"


/**
 * @class xQueueWaveGenerator
 * @todo opis
 */
class xQueueWaveGenerator
{
private:
	xQueueWaveGenerator();
	xQueueWaveGenerator(const xQueueWaveGenerator&) = delete;
	xQueueWaveGenerator& operator=(const xQueueWaveGenerator&) = delete;
public:
	static xQueueWaveGenerator& getInstance();
	/**
	 * @fn void send(entitiesInitialData::enemiGen, std::uint16_t)
	 * @param eGen
	 * @param activationDelay
	 * @todo opis
	 */
	void send(entitiesInitialData::enemiGen eGen, std::uint16_t activationDelay);
	/**
	 * @fn entitiesInitialData::enemiGen receive()
	 * @return
	 * @todo opis
	 */
	entitiesInitialData::enemiGen receive();
	/**
	 * @fn void controlTask(void*)
	 * @param pvParameters
	 * @todo opis
	 */
	static void controlTask(void *pvParameters);

private:
	static constexpr uint32_t maxTimeout_ = 100;
	static constexpr std::size_t queueSize_ = 1;
	static std::uint32_t activationDelayms_;
	bool queueActivation_;
	QueueHandle_t xQueueWaveGenerator_;
};


#endif /* INC_QUEUES_XQUEUEWAVEGENERATOR_HPP_ */
