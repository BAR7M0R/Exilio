/*
 * virtualDisplay.hpp
 *
 *  Created on: Dec 27, 2024
 *      Author: Bartłomiej Głodek
 */

#ifndef SRC_VIRTUALDISPLAY_HPP_
#define SRC_VIRTUALDISPLAY_HPP_
#include <array>
#include <cstdint>

#include "segment.hpp"
#include "coordinates.hpp"
#include "displayConstans.hpp"


using namespace displayConstans;
class virtualDisplay
{
private:

	std::array<std::array<uint8_t, V_WIDTH>, V_HEIGHT> _VMap;
	uint8_t * _Map[HEIGHT_LCD*WIDTH_LCD];
	uint8_t checkNumberOfCells(coordinates& cords);
	segment takeSnap(coordinates coords);
	void putSegment(segment& s, coordinates coords);

public:
	static constexpr uint16_t MAX_X = V_WIDTH;
	static constexpr uint16_t MAX_Y = V_HEIGHT*NUMBER_OF_PIX_IN_LCD_SINGLE_FIELD;
	uint8_t *getVMap();
	uint8_t ** getMap();
	void fill(uint8_t data);
	void putEntity(coordinates coords, coordinates cordspreve/*, demage indicator*/);
	virtualDisplay();
	~virtualDisplay();
	virtualDisplay(const virtualDisplay&) = delete;
	virtualDisplay& operator=(const virtualDisplay&) = delete;

};
#endif /* SRC_VIRTUALDISPLAY_HPP_ */
