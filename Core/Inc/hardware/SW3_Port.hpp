/**
 * @file SW3_Port.hpp
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
 * @brief
 * @details
 * @todo opis
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
