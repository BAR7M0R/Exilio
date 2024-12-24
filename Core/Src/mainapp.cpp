/*
 * mainapp.cpp
 *
 *  Created on: Dec 22, 2024
 *      Author: dev
 */

#include "mainapp.hpp"
#include "main.h"

#include "displaytask.hpp"

void mainapp()
{
	while(true)
	{
		HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin | LED_2_Pin);
		HAL_Delay(1000);
	}
}
