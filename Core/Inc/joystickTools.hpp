/**
 * @file joystickTools.hpp
 * @author Bartłomiej Głodek
 * @date 2025-01-04
 *
 * @brief
 * @details
 *
 *
 */
#ifndef INC_JOYSTICKTOOLS_HPP_
#define INC_JOYSTICKTOOLS_HPP_

#include <cstdint>
#include "coordinates.hpp"

namespace joystickTools
{
struct direction
{
static constexpr inline std::uint8_t down   = 0b00000001;
static constexpr inline std::uint8_t up     = 0b00000010;
static constexpr inline std::uint8_t left   = 0b00000100;
static constexpr inline std::uint8_t right  = 0b00001000;
static constexpr inline std::uint8_t middle = 0b00010000;
};
coordinates convert(std::uint8_t joystickData);
}


#endif /* INC_JOYSTICKTOOLS_HPP_ */
