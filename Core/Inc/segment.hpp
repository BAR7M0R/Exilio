/**
 * @file segment.hpp
 * @author Bartłomiej Głodek
 * @date 2024-12-30
 *
 * @copyright
 * Copyright (c) Bartłomiej Głodek 2025
 * Permission is granted to use, copy, modify, and distribute this software for any non-commercial purpose, free of charge.
 * For commercial use, you must notify the author and obtain permission before using this software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES, OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT, OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * @brief This file contains the declaration of the segment class, which is the basic type of screan manipulation data.
 */
#ifndef INC_SEGMENT_HPP_
#define INC_SEGMENT_HPP_
#include <field.hpp>
#include <array>
#include <cstdint>

static constexpr inline std::uint8_t segment_size = 8;

/**
 * @class segment
 * @brief This is wrapper around std::array<@link field.hpp field @endlink, 8> class based on the [memory model](pdf/memory_model.pdf).
 * @brief class provide basic bitwise operations such as not, and, or and xor.
 */
class segment
{
public:

	/**
	 * @fn segment()
	 * @brief Default constructor to create a segment with a zero-initialized array.
	 * @details Initializes the segment's internal array to zero.
	 */
	segment();

	/**
	 * @fn segment(std::initializer_list<@link field.hpp field @endlink> init)
	 * @param init - An initializer list of `@link field.hpp field @endlink` elements to initialize the segment.
	 * @brief Constructor that initializes a segment from an initializer list of `@link field.hpp field @endlink`.
	 */
	segment(std::initializer_list<field> init);

	/**
	 * @fn segment(std::array<@link field.hpp field @endlink, segment_size> data)
	 * @param data - A fixed-size array of `@link field.hpp field @endlink` elements to initialize the segment.
	 * @brief Constructor that initializes the segment with a given array of `@link field.hpp field @endlink`.
	 */
	segment(std::array<field, segment_size> data);

	/**
	 * @fn @link field.hpp field @endlink& operator[](uint32_t index)
	 * @param index - The index of the <@link field.hpp field @endlink' element to access.
	 * @return A reference to the `@link field.hpp field @endlink` element at the specified index.
	 * @brief Accesses the `@link field.hpp field @endlink` element at the specified index.
	 */
	field& operator[](uint32_t index);

	/**
	 * @fn operator std::array<@link field.hpp field @endlink, segment_size>() const
	 * @return A `std::array<@link field.hpp field @endlink, segment_size>` representation of the segment.
	 * @brief Converts the segment to a `std::array<@link field.hpp field @endlink, segment_size>`.
	 */
	operator std::array<field, segment_size>() const;

	/**
	 * @fn segment& operator=(std::initializer_list<@link field.hpp field @endlink> init)
	 * @param init - An initializer list of `@link field.hpp field @endlink` to assign to the segment.
	 * @return A reference to this segment after assignment.
	 * @brief Assigns values from an initializer list of `@link field.hpp field @endlink` to the segment.
	 */
	segment& operator=(std::initializer_list<field> init);

	/**
	 * @fn segment& operator=(const segment& other)
	 * @param other - Another segment to assign from.
	 * @return A reference to this segment after assignment.
	 * @brief Assigns values from another `segment` to this one.
	 */
	segment& operator=(const segment& other);

	/**
	 * @fn segment& operator=(const std::array<@link field.hpp field @endlink, segment_size>& arr)
	 * @param arr - A `std::array<@link field.hpp field @endlink, segment_size>` to assign to the segment.
	 * @return A reference to this segment after assignment.
	 * @brief Assigns values from a `std::array<@link field.hpp field @endlink, segment_size>` to the segment.
	 */
	segment& operator=(const std::array<field, segment_size>& arr);

	/**
	 * @fn segment& operator|=(const segment& second)
	 * @param second - Another segment to perform bitwise OR with.
	 * @return A reference to this segment after performing the operation.
	 * @brief Performs a bitwise OR operation with another segment and updates this segment.
	 */
	segment& operator|=(const segment& second);

	/**
	 * @fn segment& operator&=(const segment& second)
	 * @param second - Another segment to perform bitwise AND with.
	 * @return A reference to this segment after performing the operation.
	 * @brief Performs a bitwise AND operation with another segment and updates this segment.
	 */
	segment& operator&=(const segment& second);

	/**
	 * @fn segment& operator^=(const segment& second)
	 * @param second - Another segment to perform bitwise XOR with.
	 * @return A reference to this segment after performing the operation.
	 * @brief Performs a bitwise XOR operation with another segment and updates this segment.
	 */
	segment& operator^=(const segment& second);

	/**
	 * @fn segment operator|(const segment& second) const
	 * @param second - Another segment to perform bitwise OR with.
	 * @return A new segment that is the result of performing a bitwise OR operation.
	 * @brief Returns a new segment that is the result of a bitwise OR operation with another segment.
	 */
	segment operator|(const segment& second) const;

	/**
	 * @fn segment operator&(const segment& second) const
	 * @param second - Another segment to perform bitwise AND with.
	 * @return A new segment that is the result of performing a bitwise AND operation.
	 * @brief Returns a new segment that is the result of a bitwise AND operation with another segment.
	 */
	segment operator&(const segment& second) const;

	/**
	 * @fn segment operator^(const segment& second) const
	 * @param second - Another segment to perform bitwise XOR with.
	 * @return A new segment that is the result of performing a bitwise XOR operation.
	 * @brief Returns a new segment that is the result of a bitwise XOR operation with another segment.
	 */
	segment operator^(const segment& second) const;

	/**
	 * @fn segment operator~() const
	 * @return A new segment that is the result of performing a bitwise NOT operation.
	 * @brief Returns a new segment that is the result of a bitwise NOT operation.
	 */
	segment operator~() const;

	/**
	 * @fn @link field.hpp field @endlink& at(uint32_t index)
	 * @param index - The index of the @link field.hpp field @endlink element to access.
	 * @return A reference to the `@link field.hpp field @endlink` element at the specified index.
	 * @brief Accesses the `@link field.hpp field @endlink` element at the specified index, with bounds checking.
	 */
	field& at(uint32_t index);

	/**
	 * @fn const @link field.hpp field @endlink& at(uint32_t index) const
	 * @param index - The index of the `@link field.hpp field @endlink` element to access.
	 * @return A constant reference to the `@link field.hpp field @endlink` element at the specified index.
	 * @brief Accesses the `@link field.hpp field @endlink` element at the specified index, with bounds checking.
	 */
	const field& at(uint32_t index) const;

	/**
	 * @fn const @link field.hpp field @endlink size() const
	 * @return The size of the segment in bytes.
	 * @brief Returns the size of the segment.
	 */
	const field size() const;

	/**
	 * @fn std::array<@link field.hpp field @endlink, segment_size>::pointer begin()
	 * @return A pointer to the beginning of the segment array.
	 * @brief Returns a pointer to the beginning of the segment array for iteration.
	 */
	std::array<field, segment_size>::pointer begin();

	/**
	 * @fn std::array<@link field.hpp field @endlink, segment_size>::pointer end()
	 * @return A pointer to the end of the segment array.
	 * @brief Returns a pointer to the end of the segment array for iteration.
	 */
	std::array<field, segment_size>::pointer end();

	/**
	 * @fn std::array<@link field.hpp field @endlink, segment_size>::const_pointer begin() const
	 * @return A constant pointer to the beginning of the segment array.
	 * @brief Returns a constant pointer to the beginning of the segment array for iteration.
	 */
	std::array<field, segment_size>::const_pointer begin() const;

	/**
	 * @fn std::array<@link field.hpp field @endlink, segment_size>::const_pointer end() const
	 * @return A constant pointer to the end of the segment array.
	 * @brief Returns a constant pointer to the end of the segment array for iteration.
	 */
	std::array<field, segment_size>::const_pointer end() const;
private:
	std::array<field, segment_size> segment_;
};

#endif /* INC_SEGMENT_HPP_ */
