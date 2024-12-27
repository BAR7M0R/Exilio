/*
 * virtualDisplay.hpp
 *
 *  Created on: Dec 27, 2024
 *      Author: dev
 */

#ifndef SRC_VIRTUALDISPLAY_HPP_
#define SRC_VIRTUALDISPLAY_HPP_
#include <array>
#include <cstdint>
class virtualDisplay
{
private:
	static constexpr uint8_t WIDTH = 128;
	static constexpr uint8_t HEIGHT = 64;
	static constexpr uint8_t MARGIN_WIDTH = 8;
	static constexpr uint8_t MARGIN_HEIGHT = 1;
	static constexpr uint8_t V_WIDTH = WIDTH + MARGIN_WIDTH * 2;
	static constexpr uint8_t V_HEIGHT = WIDTH + MARGIN_HEIGHT * 2;

	std::array<std::array<uint8_t, V_HEIGHT>, V_WIDTH> _VMap;
	uint8_t * _Map[HEIGHT*WIDTH];

public:
	uint8_t *getVMap();
	uint8_t * getMap();
	virtualDisplay();
	~virtualDisplay();
	virtualDisplay(const virtualDisplay&) = delete;
	virtualDisplay& operator=(const virtualDisplay&) = delete;

};
#endif /* SRC_VIRTUALDISPLAY_HPP_ */
