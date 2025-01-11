/**
 * @file coordinates.cpp
 * @author Bartłomiej Głodek
 * @date 2025-01-05
 *
 * @brief
 * @details
 *
 *
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
bool coordinates::operator==(coordinates c) const
{
	bool r = true;
	if(c.x != this->x)
	{
		r = false;
	}
	if(c.y != this->y)
	{
		r = false;
	}
	return r;
}
