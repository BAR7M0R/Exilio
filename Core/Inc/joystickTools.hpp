/**
 * @file joystickTools.hpp
 * @author Bartłomiej Głodek
 * @date 2025-01-04
 *
 * @copyright
 * Copyright (c) Bartłomiej Głodek 2025
 * Permission is granted to use, copy, modify, and distribute this software for any non-commercial purpose, free of charge.
 * For commercial use, you must notify the author and obtain permission before using this software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES, OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT, OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * @brief Provides tools for handling joystick data and converting it into coordinate-based directions.
 * @details This header defines a namespace and structures for interpreting joystick data.
 * The main functionality includes converting raw joystick data into logical coordinates.
 */

#ifndef INC_JOYSTICKTOOLS_HPP_
#define INC_JOYSTICKTOOLS_HPP_

#include <cstdint>
#include "coordinates.hpp"

/**
 * @namespace joystickTools
 * Contains utilities and constants for interpreting joystick data.
 */
namespace joystickTools
{
/**
 * @struct direction
 * Represents direction states of a joystick using bit flags.
 */
struct direction
{
    static constexpr inline std::uint8_t down   = 0b00000001; ///< Down direction flag
    static constexpr inline std::uint8_t up     = 0b00000010; ///< Up direction flag
    static constexpr inline std::uint8_t left   = 0b00000100; ///< Left direction flag
    static constexpr inline std::uint8_t right  = 0b00001000; ///< Right direction flag
    static constexpr inline std::uint8_t middle = 0b00010000; ///< Neutral (middle) position flag
};

/**
 * @fn coordinates convert(std::uint8_t joystickData)
 * @brief Converts raw joystick data into coordinates.
 *
 * @param joystickData Raw data from the joystick, represented as an 8-bit integer.
 * @return A `coordinates` object representing the logical direction or position.
 *
 * @details The function interprets the joystick's bitwise state flags and converts them into meaningful coordinates.
 */
coordinates convert(std::uint8_t joystickData);
}

#endif /* INC_JOYSTICKTOOLS_HPP_ */
