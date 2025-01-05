/*
 * virtualDisplay.cpp
 *
 *  Created on: Dec 27, 2024
 *      Author: Bartłomiej Głodek
 */

#include "virtualDisplay.hpp"
#include "claster.hpp"
#include "entitiesInitData.hpp"
#include "coordinatesTools.hpp"
using namespace displayConstans;

uint8_t * virtualDisplay::getVMap()
{
return &_VMap[0][0];
}
uint8_t ** virtualDisplay::getMap()
{
return _Map;
}
void virtualDisplay::fill(uint8_t data)
{
	for (auto& row:_VMap)
	{
		row.fill(data);
	}
}
uint8_t virtualDisplay::checkNumberOfCells(coordinates& coords)
{
	uint8_t numberOfCells=0;
	if (coords.y%NUMBER_OF_PIX_IN_LCD_SINGLE_FIELD == 0)
	{
		numberOfCells = 1;
	}
	else
	{
		numberOfCells = 2;
	}
	return numberOfCells;
}
segment virtualDisplay::takeSnap(coordinates coords)
{
	segment snap;
	uint8_t numberOfCells = checkNumberOfCells(coords);
	for(uint8_t xIdx = 0; xIdx < snap.size(); ++xIdx)
	{
		for(uint8_t yIdx = 0; yIdx < numberOfCells; ++yIdx)
		{
			if (yIdx == 0)
			{
				snap.at(xIdx) |= (_VMap.at(coords.y/NUMBER_OF_PIX_IN_LCD_SINGLE_FIELD+yIdx).at(coords.x+xIdx)
						>> coords.y%NUMBER_OF_PIX_IN_LCD_SINGLE_FIELD);
			}
			else
			{
				snap.at(xIdx) |= (_VMap.at(coords.y/NUMBER_OF_PIX_IN_LCD_SINGLE_FIELD+yIdx).at(coords.x+xIdx)
						<< (NUMBER_OF_PIX_IN_LCD_SINGLE_FIELD - coords.y%NUMBER_OF_PIX_IN_LCD_SINGLE_FIELD));
			}
		}
	}
	return snap;
}
void virtualDisplay::putEntity(coordinates& coords, coordinates& cordspreve, const segment& texture)
{
	using namespace coordinatesTools;

	//segment texture(EntitiesInitialData::enemy3::texture_data);//{0x07, 0x07, 0x07, 0x00,0x00,0x00,0x00,0x00};
	//do zrefaktoryzowania
	segment core1 = takeSnap(vMapCMove(cordspreve, 0, 0));
	segment core2 = takeSnap(vMapCMove(cordspreve, 8, 0));
	segment core3 = takeSnap(vMapCMove(cordspreve, 0, 8));
	segment core4 = takeSnap(vMapCMove(cordspreve, 8, 8));

	claster cla1(core1, core2, core3, core4);
	cla1.putBlackmaskSegmentOnClaster(vMapSm(cordspreve), ~texture);

	putSegment(core1, vMapCMove(cordspreve, 0, 0));
	putSegment(core2, vMapCMove(cordspreve, 8, 0));
	putSegment(core3, vMapCMove(cordspreve, 0, 8));
	putSegment(core4, vMapCMove(cordspreve, 8, 8));

	segment core11 = takeSnap(vMapCMove(coords, 0, 0));
	segment core22 = takeSnap(vMapCMove(coords, 8, 0));
	segment core33 = takeSnap(vMapCMove(coords, 0, 8));
	segment core44 = takeSnap(vMapCMove(coords, 8, 8));
	claster cla2(core11, core22, core33, core44);
	cla2.putSegmentOnClaster(vMapSm(coords), texture);

	putSegment(core11, vMapCMove(coords, 0, 0));
	putSegment(core22, vMapCMove(coords, 8, 0));
	putSegment(core33, vMapCMove(coords, 0, 8));
	putSegment(core44, vMapCMove(coords, 8, 8));
}
void virtualDisplay::putSegment(segment& s, coordinates coords)
{
	for(uint8_t currentFieldIndex = 0; currentFieldIndex < s.size(); ++currentFieldIndex)
	{
		_VMap.at(coords.y / NUMBER_OF_PIX_IN_LCD_SINGLE_FIELD).at(coords.x+currentFieldIndex) = s[currentFieldIndex];
	}
}
virtualDisplay::virtualDisplay()
{
	for (auto& row:_VMap)
	{
		for (int i = 0; i< 30; ++i)
		{
			row.at(i) = (0x00);
		}

	}
	uint16_t k = 0;
	for (uint8_t i = 0; i < HEIGHT_LCD; ++i)
	{
		for (uint8_t j = 0; j < WIDTH_LCD; ++j)
		{
			_Map[k++] = &_VMap[V_MARGIN_HEIGHT+i][V_MARGIN_WIDTH+j];
		}
	}
}

virtualDisplay::~virtualDisplay()
{

}

