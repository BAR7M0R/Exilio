/*
 * coordinatesTools.hpp
 *
 *  Created on: Dec 31, 2024
 *      Author: dev
 */

#ifndef INC_COORDINATESTOOLS_HPP_
#define INC_COORDINATESTOOLS_HPP_


namespace coordinatesTools
{
	coordinates vMapSm(coordinates c)
	{
		c.x %= 8;
		c.y %= 8;
		return c;
	}
	coordinates vMapSc(coordinates c)
	{
		c.y /= 8;
		c.y *= 8;
		c.x /= 8;
		c.x *= 8;
		if(0 >= c.y and V_HEIGHT <= c.y)
		{
			while(true);
		}
		if(0 >= c.x and V_WIDTH <= c.x)
		{
			while(true);
		}
		return c;
	}
	coordinates vMapCMove(coordinates c, uint8_t x, uint8_t y)
	{
		coordinates m = vMapSc(c);
		m.x += x;
		m.y += y;
		if(0 >= c.y and V_HEIGHT <= c.y)
		{
			while(true);
		}
		if(0 >= c.x and V_WIDTH <= c.x)
		{
			while(true);
		}
		return m;
	}
	coordinates vMapSUp(coordinates c)
	{
		coordinates vMapS = vMapSc(c);
		vMapS.y -= 8;
		if(0 > vMapS.y)
		{
			while(true);
		}
		return vMapS;
	}

	coordinates vMapSDown(coordinates c)
	{
		coordinates vMapS = vMapSc(c);
		vMapS.y += 8;
		if(V_HEIGHT < vMapS.y)
		{
			while(true);
		}
		return vMapS;
	}
	coordinates vMapSLeft(coordinates c)
	{
		coordinates vMapS = vMapSc(c);
		vMapS.x -= 8;
		if(0 > vMapS.x)
		{
			while(true);
		}
		return vMapS;
	}
	coordinates vMapSRight(coordinates c)
	{
		coordinates vMapS = vMapSc(c);
		vMapS.x += 8;

		if(V_WIDTH < vMapS.x)
		{
			while(true);
		}
		return vMapS;
	}
	coordinates vMapSUpLeft(coordinates c)
	{
		coordinates vMapS = vMapSc(c);
		vMapS.y -= 8;
		vMapS.x -= 8;
		if(0 > vMapS.y)
		{
			while(true);
		}
		if(0 > vMapS.x)
		{
			while(true);
		}
		return vMapS;
	}
	coordinates vMapSUpRright(coordinates c)
	{
		coordinates vMapS = vMapSc(c);
		vMapS.y -= 8;
		vMapS.x += 8;
		if(0 > vMapS.y)
		{
			while(true);
		}
		if(V_WIDTH < vMapS.x)
		{
			while(true);
		}
		return vMapS;
	}
	coordinates vMapSDownLeft(coordinates c)
	{
		coordinates vMapS = vMapSc(c);
		vMapS.y += 8;
		vMapS.x -= 8;
		if(V_HEIGHT < vMapS.y)
		{
			while(true);
		}
		if(0 > vMapS.x)
		{
			while(true);
		}
		return vMapS;
	}
	coordinates vMapSDownRigth(coordinates c)
	{
		coordinates vMapS = vMapSc(c);
		vMapS.y += 8;
		vMapS.x += 8;
		if(V_HEIGHT < vMapS.y)
		{
			while(true);
		}
		if(V_WIDTH < vMapS.x)
		{
			while(true);
		}
		return vMapS;
	}
};


#endif /* INC_COORDINATESTOOLS_HPP_ */
