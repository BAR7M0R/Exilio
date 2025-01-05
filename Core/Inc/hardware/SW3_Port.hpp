/*
 * SW3_Port.hpp
 *
 *  Created on: Jan 4, 2025
 *      Author: dev
 */

#ifndef INC_HARDWARE_SW3PORT_HPP_
#define INC_HARDWARE_SW3PORT_HPP_
#include <cstdint>

static constexpr inline std::uint8_t sw_3 = 0b00000001;

static constexpr inline std::uint8_t keys_pressed = 1;
static constexpr inline std::uint8_t key_pressed = 1;
static constexpr inline std::uint8_t keys_released = 0;

std::uint8_t SW3_Port_read();

#endif /* INC_HARDWARE_SW3PORT_HPP_ */
