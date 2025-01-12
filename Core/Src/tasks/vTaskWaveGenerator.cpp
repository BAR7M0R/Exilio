/**
 * @file vTaskWaveGenerator.cpp
 * @author Bartłomiej Głodek
 * @date 2025-01-12
 *
 * @brief
 * @details
 *
 *
 */

#include "vTaskWaveGenerator.hpp"

#include "xQueueWaveGenerator.hpp"

#include "adc.h"
#include "entitiesInitData.hpp"

std::uint32_t Read_ADC(void) {
    HAL_ADC_Start(&hadc1); // Rozpocznij konwersję
    HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY); // Poczekaj na zakończenie
    std::uint32_t value = HAL_ADC_GetValue(&hadc1); // Pobierz wartość
    HAL_ADC_Stop(&hadc1); // Zatrzymaj konwersję
    return value;
}

void vTaskWaveGenerator(void *pvParameters)
{
	while (true)
	{

		xQueueWaveGenerator& waveGeneratorQueue = xQueueWaveGenerator::getInstance();
		int16_t spawnPosition = 8 + static_cast<int16_t>(Read_ADC() & 0x00FF);
		spawnPosition = spawnPosition > 128 ? 128: spawnPosition;
		uint8_t enemyTypeRandGen = static_cast<uint8_t>(Read_ADC() & 0x0003);
		uint8_t enemyNumberRandGen = static_cast<uint8_t>(Read_ADC() & 0x0003);
		entitiesInitialData::enemiGen dataToSent;
		dataToSent.position = coordinates({spawnPosition,0});
		dataToSent.number = enemyNumberRandGen;
		dataToSent.isGenerated = false;
		switch(enemyTypeRandGen)
		{
		case 1:
			{
				dataToSent.type = entitiesInitialData::enemys::enemy1;
			}break;
		case 2:
			{
				dataToSent.type = entitiesInitialData::enemys::enemy2;
			}break;

		case 3:
				{
					dataToSent.type = entitiesInitialData::enemys::enemy3;
				}break;
		default:
		{
			dataToSent.type = entitiesInitialData::enemys::enemy1;
		}break;
		}
		int16_t activationDelay = static_cast<int16_t>(Read_ADC() & 0x00EF);
		activationDelay = activationDelay < 4096 ? 4096 : activationDelay;
		waveGeneratorQueue.send(dataToSent, activationDelay);
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}
