/**
 * @file displayConstans.hpp
 * @author Bartłomiej Głodek
 * @date 2024-12-31
 *
 * @copyright
 * Copyright (c) Bartłomiej Głodek 2025
 * Permission is granted to use, copy, modify, and distribute this software for any non-commercial purpose, free of charge.
 * For commercial use, you must notify the author and obtain permission before using this software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES, OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT, OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * @brief This file contains constants used for defining the display parameters.
 * @details
 * It includes:
 * - LCD display width and height
 * - Vertical margins and padding
 * - Display borders
 * - Pixel counts for display calculations
 *
 * The constants are designed to ensure correct positioning and scaling of the virtual display components.
 */
#include <cstdint>
#include "field.hpp"

#ifndef INC_DISPLAYCONSTANS_HPP_
#define INC_DISPLAYCONSTANS_HPP_
/**
 * @namespace displayConstans
 * @brief This namespace contains constants used for defining the display parameters.
 * @details
 * It includes:
 * - LCD display width and height
 * - Vertical margins and padding
 * - Display borders
 * - Pixel counts for display calculations
 */
namespace displayConstans
{
    /**
     * @var width_lcd
     * @brief The width of the LCD display in pixels.
     */
    static constexpr inline std::uint8_t width_lcd = 128;

    /**
     * @var height_lcd
     * @brief The height of the LCD display in fields.
     */
    static constexpr inline std::uint8_t height_lcd = 8;

    /**
     * @var number_of_pix_in_lcd_single_field
     * @brief The number of pixels in a single field of the LCD display.
     * This value is based on the `field_size` constant from the `field.hpp` file.
     */
    static constexpr inline std::uint8_t number_of_pix_in_lcd_single_field = field_size;

    /**
     * @var v_margin_width
     * @brief The width of the vertical margin around the display in pixel.
     */
    static constexpr inline std::uint8_t v_margin_width = 8;

    /**
     * @var v_margin_height
     * @brief The height of the vertical margin around the display in fields.
     */
    static constexpr inline std::uint8_t v_margin_height = 1;

    /**
     * @var v_margin_height_in_pix
     * @brief The total vertical margin height in pixels.
     */
    static constexpr inline std::uint8_t v_margin_height_in_pix = v_margin_height * number_of_pix_in_lcd_single_field;

    /**
     * @var v_width
     * @brief The total width of the virtual display, including the margins. in pixels
     */
    static constexpr inline std::uint8_t v_width = width_lcd + v_margin_width * 2;

    /**
     * @var v_height
     * @brief The total height of the virtual display, including the margins. in fields
     */
    static constexpr inline std::uint8_t v_height = height_lcd + v_margin_height * 3;

    /**
     * @var border_top
     * @brief The top border of the virtual display. in fields
     */
    static constexpr inline std::uint8_t border_top = v_margin_height;

    /**
     * @var border_bottom
     * @brief The bottom border of the virtual display. in fields
     */
    static constexpr inline std::uint8_t border_bottom = v_margin_height + height_lcd;

    /**
     * @var border_left
     * @brief The left border of the virtual display. in pixels
     */
    static constexpr inline std::uint8_t border_left = v_margin_width;

    /**
     * @var border_right
     * @brief The right border of the virtual display. in pixels
     */
    static constexpr inline std::uint8_t border_right = v_margin_width + width_lcd;

    /**
     * @var max_x
     * @brief The maximum X coordinate of the virtual display. in pixels
     */
    static constexpr inline std::uint8_t max_x = v_width;

    /**
     * @var max_y
     * @brief The maximum Y coordinate of the virtual display. in pixels
     */
    static constexpr inline std::uint8_t max_y = v_height * number_of_pix_in_lcd_single_field;
};



#endif /* INC_DISPLAYCONSTANS_HPP_ */
