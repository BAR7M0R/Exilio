/**
 * @file displayConstans.hpp
 * @author Bartłomiej Głodek
 * @date 2024-12-31
 *
 * @brief
 * @details
 *
 *
 */
#include <cstdint>
#include "field.hpp"

#ifndef INC_DISPLAYCONSTANS_HPP_
#define INC_DISPLAYCONSTANS_HPP_

namespace displayConstans
{
	static constexpr inline std::uint8_t width_lcd = 128;
	static constexpr inline std::uint8_t height_lcd = 8;
	static constexpr inline std::uint8_t number_of_pix_in_lcd_single_field = field_size;
	static constexpr inline std::uint8_t v_margin_width = 8;
	static constexpr inline std::uint8_t v_margin_height = 1;
	static constexpr inline std::uint8_t v_margin_height_in_pix = v_margin_height * number_of_pix_in_lcd_single_field;
	static constexpr inline std::uint8_t v_width = width_lcd + v_margin_width * 2;
	static constexpr inline std::uint8_t v_height = height_lcd + v_margin_height * 3;
	static constexpr inline std::uint8_t border_top = v_margin_height;
	static constexpr inline std::uint8_t border_bottom = v_margin_height+height_lcd;
	static constexpr inline std::uint8_t border_left = v_margin_width;
	static constexpr inline std::uint8_t border_right = v_margin_width+width_lcd;
	static constexpr inline std::uint8_t max_x = v_width;
	static constexpr inline std::uint8_t max_y = v_height*number_of_pix_in_lcd_single_field;
};



#endif /* INC_DISPLAYCONSTANS_HPP_ */
