/*
 * joystickTools.hpp
 *
 *  Created on: Jan 4, 2025
 *      Author: dev
 */

#ifndef SRC_TASKS_JOYSTICKTOOLS_HPP_
#define SRC_TASKS_JOYSTICKTOOLS_HPP_

#include <cstdint>
#include "coordinates.hpp"

namespace JoystickTools
{
struct direction
{
static constexpr inline std::uint8_t down = 0b00000001;
static constexpr inline std::uint8_t up =  0b00000010;
static constexpr inline std::uint8_t left =  0b00000100;
static constexpr inline std::uint8_t right = 0b00001000;
static constexpr inline std::uint8_t middle = 0b00010000;
};
coordinates updateCoordinates(std::uint8_t joystickData, coordinates currentPosition)
{

	if ((joystickData & direction::down) == direction::down) {++currentPosition.y;}
	if ((joystickData & direction::up) == direction::up) {--currentPosition.y;}
	if ((joystickData & direction::left) == direction::left) {--currentPosition.x;}
	if ((joystickData & direction::right) == direction::right) {++currentPosition.x;}
	return currentPosition;
}

}


#endif /* SRC_TASKS_JOYSTICKTOOLS_HPP_ */
