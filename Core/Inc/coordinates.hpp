/**
 * @file coordinates.hpp
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
 * @brief Defines the coordinates structure used for representing 2D points.
 */

#ifndef INC_COORDINATES_HPP_
#define INC_COORDINATES_HPP_
#include <cstdint>
/**
 * @struct coordinates
 * @brief Represents a 2D coordinate with x and y values.
 * @details This struct stores two integer values (`x` and `y`) representing a 2D coordinate.
 * It also provides arithmetic operators to add and subtract coordinates, as well as a comparison operator.
 */
struct coordinates{
    std::int16_t x; ///< x coordinate
    std::int16_t y; ///< y coordinate

    /**
     * @fn coordinates operator +(coordinates) const
     * @brief Adds two coordinates together.
     * @param c The coordinate to be added.
     * @return A new `coordinates` object representing the sum of the current coordinate and the given one.
     * @details This operator overloads the `+` operator to add the `x` and `y` values of two coordinates.
     */
    coordinates operator+(coordinates c) const;

    /**
     * @fn coordinates operator -(coordinates) const
     * @brief Subtracts one coordinate from another.
     * @param c The coordinate to be subtracted.
     * @return A new `coordinates` object representing the difference between the current coordinate and the given one.
     * @details This operator overloads the `-` operator to subtract the `x` and `y` values of the given coordinate from the current one.
     */
    coordinates operator-(coordinates c) const;

    /**
     * @fn bool operator ==(coordinates) const
     * @brief Compares if two coordinates are equal.
     * @param c The coordinate to be compared with.
     * @return `true` if the `x` and `y` values of both coordinates are equal, otherwise `false`.
     * @details This operator overloads the `==` operator to compare the `x` and `y` values of two coordinates.
     */
    bool operator==(coordinates c) const;
};
#endif /* INC_COORDINATES_HPP_ */
