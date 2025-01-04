/*
 * coordinates.hpp
 *
 *  Created on: Dec 31, 2024
 *      Author: Bartłomiej Głodek
 */

#ifndef INC_COORDINATES_HPP_
#define INC_COORDINATES_HPP_
#include <cstdint>
struct coordinates {
	std::int16_t x;
    std::int16_t y;
    coordinates operator+(coordinates c) const
    {
    	coordinates r;
    	r.x = this->x + c.x;
    	r.y = this->y + c.y;
    	return r;
    }
    coordinates operator-(coordinates c) const
    {
    	coordinates r;
    	r.x = this->x - c.x;
    	r.y = this->y -c.y;
    	return r;
    }
};

#endif /* INC_COORDINATES_HPP_ */
