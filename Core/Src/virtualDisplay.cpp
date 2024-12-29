/*
 * virtualDisplay.cpp
 *
 *  Created on: Dec 27, 2024
 *      Author: dev
 */

#include "virtualDisplay.hpp"

uint8_t * virtualDisplay::getVMap()
{
return _VMap[0].data();
}
uint8_t * virtualDisplay::getMap()
{
return *_Map;
}
void virtualDisplay::fill(uint8_t data)
{
	for (auto& row:_VMap)
	{
		row.fill(data);
	}
}
virtualDisplay::virtualDisplay()
{
	for (auto& row:_VMap)
	{
		row.fill(0x00);
	}
	int k = 0;
	for (int i = MARGIN_HEIGHT; i < MARGIN_HEIGHT + HEIGHT; ++i)
	{
		for (int j = MARGIN_WIDTH; j < MARGIN_WIDTH + WIDTH; ++j)
		{
			_Map[k++] = &_VMap[i][j];
		}
	}
}

virtualDisplay::~virtualDisplay()
{

}

