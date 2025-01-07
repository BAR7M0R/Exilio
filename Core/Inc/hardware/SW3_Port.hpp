/**
 * @file SW3_Port.hpp
 * @author Bartłomiej Głodek
 * @date 2025-01-04
 *
 *
 */
#ifndef INC_HARDWARE_SW3PORT_HPP_
#define INC_HARDWARE_SW3PORT_HPP_

#include <cstdint>
/**
 * @namespace SW3PortDefines provides constants for SW3 Port
 */
namespace SW3PortConsts
{
	static constexpr inline std::uint8_t sw_3 = 0b00000001;
	static constexpr inline std::uint8_t keys_pressed = 1;
	static constexpr inline std::uint8_t key_pressed = 1;
	static constexpr inline std::uint8_t keys_released = 0;
}
/**
 * @fn std::uint8_t SW3_Port_read()
 * @return should be 0 or 1
 */
std::uint8_t SW3_Port_read();

#endif /* INC_HARDWARE_SW3PORT_HPP_ */
