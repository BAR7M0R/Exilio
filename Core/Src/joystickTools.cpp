/**
 * @file joystickTools.cpp
 * @author Bartłomiej Głodek
 * @date 2025-01-05
 *
 * @brief
 * @details
 *
 *
 */
#include "joystickTools.hpp"

namespace joystickTools
{

coordinates convert(std::uint8_t joystickData)
{

	coordinates r{0,0};
	if ((joystickData & direction::down) == direction::down) {++r.y;}
	if ((joystickData & direction::up) == direction::up) {--r.y;}
	if ((joystickData & direction::left) == direction::left) {--r.x;}
	if ((joystickData & direction::right) == direction::right) {++r.x;}
	return r;
}
}
