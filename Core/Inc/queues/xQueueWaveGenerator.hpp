/**
 * @file xQueueWaveGenerator.hpp
 * @author Bartłomiej Głodek
 * @date 2025-01-11
 *
 * @brief
 * @details
 *
 *
 */
#ifndef INC_QUEUES_XQUEUEWAVEGENERATOR_HPP_
#define INC_QUEUES_XQUEUEWAVEGENERATOR_HPP_

#include <cstdint>
#include "FreeRTOS.h"
#include "queue.h"
#include "entitiesInitData.hpp"
#include "coordinates.hpp"



class xQueueWaveGenerator
{
private:
	xQueueWaveGenerator();
	xQueueWaveGenerator(const xQueueWaveGenerator&) = delete;
	xQueueWaveGenerator& operator=(const xQueueWaveGenerator&) = delete;
public:
	static xQueueWaveGenerator& getInstance();
	void send(entitiesInitialData::enemiGen eGen, std::uint16_t activationDelay);
	entitiesInitialData::enemiGen receive();
	static void controlTask(void *pvParameters);

private:
	static constexpr uint32_t maxTimeout_ = 100;
	static constexpr std::size_t queueSize_ = 1;
	static std::uint32_t activationDelayms_;
	bool queueActivation_;
	QueueHandle_t xQueueWaveGenerator_;
};


#endif /* INC_QUEUES_XQUEUEWAVEGENERATOR_HPP_ */
