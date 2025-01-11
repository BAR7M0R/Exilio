/**
 * @file coordinates.hpp
 * @author Bartłomiej Głodek
 * @date 2024-12-31
 *
 * @brief
 * @details
 *
 *
 */

#ifndef INC_COORDINATES_HPP_
#define INC_COORDINATES_HPP_
#include <cstdint>
/**
 * @struct coordinates
 *
 */
struct coordinates {
	std::int16_t x;
    std::int16_t y;
    coordinates operator+(coordinates c) const;
    coordinates operator-(coordinates c) const;
    bool operator==(coordinates c) const;
};

#endif /* INC_COORDINATES_HPP_ */
