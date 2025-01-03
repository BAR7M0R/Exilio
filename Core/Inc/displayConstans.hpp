/*
 * displayConstans.hpp
 *
 *  Created on: Dec 31, 2024
 *      Author: dev
 */

#ifndef INC_DISPLAYCONSTANS_HPP_
#define INC_DISPLAYCONSTANS_HPP_
#include <cstdint>
#include "field.hpp"
namespace displayConstans
{
	static constexpr uint8_t WIDTH_LCD = 128;
	static constexpr uint8_t HEIGHT_LCD = 8;
	static constexpr uint8_t NUMBER_OF_PIX_IN_LCD_SINGLE_FIELD = FIELD_SIZE;
	static constexpr uint8_t V_MARGIN_WIDTH = 8;
	static constexpr uint8_t V_MARGIN_HEIGHT = 1;
	static constexpr uint8_t V_WIDTH = WIDTH_LCD + V_MARGIN_WIDTH * 2;
	static constexpr uint8_t V_HEIGHT = HEIGHT_LCD + V_MARGIN_HEIGHT * 2;
	static constexpr uint8_t BORDER_TOP = V_MARGIN_HEIGHT;
	static constexpr uint8_t BORDER_BOTTOM = V_MARGIN_HEIGHT+HEIGHT_LCD;
	static constexpr uint8_t BORDER_LEFT = V_MARGIN_WIDTH;
	static constexpr uint8_t BORDER_RIGHT = V_MARGIN_WIDTH+WIDTH_LCD;

};



#endif /* INC_DISPLAYCONSTANS_HPP_ */
