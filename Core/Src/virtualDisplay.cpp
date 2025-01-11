/**
 * @file virtulaDisplay.cpp
 * @author Bartłomiej Głodek
 * @date 2024-12-27
 *
 * @brief
 * @details
 *
 *
 */

#include <Claster.hpp>
#include "virtualDisplay.hpp"
#include "entitiesInitData.hpp"
#include "coordinatesTools.hpp"
#include "displayConstans.hpp"
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
	if (coords.y%number_of_pix_in_lcd_single_field == 0)
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
				snap.at(xIdx) |= (_VMap.at(coords.y/number_of_pix_in_lcd_single_field+yIdx).at(coords.x+xIdx)
						>> coords.y%number_of_pix_in_lcd_single_field);
			}
			else
			{
				snap.at(xIdx) |= (_VMap.at(coords.y/number_of_pix_in_lcd_single_field+yIdx).at(coords.x+xIdx)
						<< (number_of_pix_in_lcd_single_field - coords.y%number_of_pix_in_lcd_single_field));
			}
		}
	}
	return snap;
}
void virtualDisplay::putEntity(coordinates& coords, coordinates& cordspreve, const segment& texture)
{
	using namespace coordinatesTools;

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
		_VMap.at(coords.y / number_of_pix_in_lcd_single_field).at(coords.x+currentFieldIndex) = s[currentFieldIndex];
	}
}
virtualDisplay& virtualDisplay::getInstance()
{
	static virtualDisplay instance;
	return instance;
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
	for (uint8_t i = 0; i < height_lcd; ++i)
	{
		for (uint8_t j = 0; j < width_lcd; ++j)
		{
			_Map[k++] = &_VMap[v_margin_height+i][v_margin_width+j];
		}
	}
}

