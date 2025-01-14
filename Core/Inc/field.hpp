/**
 * @file field.hpp
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
 * @brief Header file defining the `field` alias and constants for the data model.
 * @details This file defines the alias `field` as `uint8_t` and the constant `field_size` with a value of 8, which are used as part of a [memory model](pdf/memory_model.pdf). Please refer to the document "[memory_model.pdf](pdf/memory_model.pdf)".
 */
#ifndef INC_FIELD_HPP_
#define INC_FIELD_HPP_

#include <cstdint>
/**
 * @brief Alias for a byte (8 bits) used in the data model.
 */
using field = uint8_t;
/**
 * @brief The size of a single `field` element (8 bits).
 */
inline static constexpr uint8_t field_size = 8;


#endif /* INC_FIELD_HPP_ */
