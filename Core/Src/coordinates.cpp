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


/**
 * @fn coordinates operator +(coordinates)const
 * @param c
 * @return
 */
coordinates coordinates::operator+(coordinates c) const
{
	coordinates r;
	r.x = this->x + c.x;
	r.y = this->y + c.y;
	return r;
}

/**
 * @fn coordinates operator -(coordinates)const
 * @param c
 * @return
 */
coordinates coordinates::operator-(coordinates c) const
{
	coordinates r;
	r.x = this->x - c.x;
	r.y = this->y -c.y;
	return r;
}

/**
 * @fn bool operator ==(coordinates)const
 * @param c
 * @return
 */
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
