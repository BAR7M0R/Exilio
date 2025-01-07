/*
 * coordinates.cpp
 *
 *  Created on: Jan 5, 2025
 *      Author: dev
 */
#include "coordinates.hpp"



coordinates coordinates::operator+(coordinates c) const
{
	coordinates r;
	r.x = this->x + c.x;
	r.y = this->y + c.y;
	return r;
}
coordinates coordinates::operator-(coordinates c) const
{
	coordinates r;
	r.x = this->x - c.x;
	r.y = this->y -c.y;
	return r;
}
