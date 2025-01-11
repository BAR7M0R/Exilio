/**
 * @file virtulaDisplay.hpp
 * @author Bartłomiej Głodek
 * @date 2024-12-27
 *
 * @brief
 * @details
 *
 *
 */

#ifndef INC_VIRTUALDISPLAY_HPP_
#define INC_VIRTUALDISPLAY_HPP_
#include <array>
#include <cstdint>

#include "segment.hpp"
#include "coordinates.hpp"
#include "displayConstans.hpp"


using namespace displayConstans;

class virtualDisplay
{
private:
	virtualDisplay();
	virtualDisplay(const virtualDisplay&) = delete;
	virtualDisplay& operator=(const virtualDisplay&) = delete;
public:
	static virtualDisplay& getInstance();
	std::uint8_t *getVMap();
	std::uint8_t ** getMap();
	void fill(uint8_t data);
	void putEntity(coordinates& coords, coordinates& cordspreve, const segment& texture/*, demage indicator*/);

private:
	std::uint8_t checkNumberOfCells(coordinates& cords);
	segment takeSnap(coordinates coords);
	void putSegment(segment& s, coordinates coords);
	std::array<std::array<std::uint8_t, v_width>, v_height> _VMap;
	std::uint8_t * _Map[height_lcd*width_lcd];


};
#endif /* INC_VIRTUALDISPLAY_HPP_ */
