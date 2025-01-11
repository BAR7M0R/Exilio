/**
 * @file coordinatesTools.cpp
 * @author Bartłomiej Głodek
 * @date 2025-01-04
 *
 * @brief
 * @details
 *
 *
 */
#include <cstdint>
#include "coordinatesTools.hpp"

#include "displayConstans.hpp"

namespace coordinatesTools {
using namespace displayConstans;


bool isInVmap(const coordinates c) {
	bool r = true;
	if ((c.x < 0) or (c.x >= v_width)) {
		r = false;
	}
	if ((c.y < 0) or (c.y >= v_height * 8)) {
		r = false;
	}
	return r;
}
bool isInMap(const coordinates c) {
	bool r = true;
	if ((c.x < v_margin_width) or (c.x >= v_margin_width + width_lcd)) {
		r = false;
	}
	if ((c.y < v_margin_height * 8)
			or (c.y >= (v_margin_height + height_lcd) * 8)) {
		r = false;
	}
	return r;
}
bool isInDownMargin(const coordinates c)
{
	bool r = false;
	if (c.y > (displayConstans::height_lcd + displayConstans::v_margin_height)*8) r = true;
	return r;
}
bool isPointInScope(const coordinates c, const coordinates scopePoint1, const coordinates scopePoint2)
{
	bool r = false;
	if ((c.x >= scopePoint1.x and c.x <= scopePoint2.x) and (c.y >= scopePoint1.y and c.y <= scopePoint2.y))
	{
		r = true;
	}
	return r;
}
bool isScopeInScope(const coordinates scope1Point1, const coordinates scope1Point2, const coordinates scope2Point1, const coordinates scope2Point2)
{
	bool r = false;
	coordinates tempPoint;
	if (isPointInScope(scope1Point1,scope2Point1,scope2Point2)) r = true;
	tempPoint = scope1Point1;
	tempPoint.x = tempPoint.x + scope1Point2.x;
	if (isPointInScope(tempPoint,scope2Point1,scope2Point2)) r = true;
	tempPoint = scope1Point1;
	tempPoint.y = tempPoint.y + scope1Point2.y;
	if (isPointInScope(tempPoint,scope2Point1,scope2Point2)) r = true;
	if (isPointInScope(scope1Point2,scope2Point1,scope2Point2)) r = true;
	{
		r = true;
	}
	return r;
}

coordinates stopPointOnBorderMap(coordinates c) {
	if (!isInMap(c)) {
		if (c.x < v_margin_width)
			c.x = v_margin_width;
		if (c.x >= v_margin_width + width_lcd)
			c.x = v_margin_width + width_lcd;
		if (c.y < v_margin_height * 8)
			c.y = v_margin_height * 8;
		if (c.y >= (v_margin_height + height_lcd) * 8)
			c.y = (v_margin_height + height_lcd) * 8;
	}
	return c;

}
coordinates stopPointOnBorderVmap(coordinates c) {
	if (!isInVmap(c)) {
		if (c.x < 0)
			c.x = 0;
		if (c.x >= v_margin_width)
			c.x = v_margin_width;
		if (c.y < 0)
			c.y = 0;
		if (c.y >= v_margin_height * 8)
			c.y = v_margin_height * 8;
	}
	return c;
}
coordinates stopRectangleOnBorderMap(coordinates c, coordinates c2)
{
	coordinates r = stopPointOnBorderMap(c);
	if (!isInMap(c2))
	{
		r = r - (c2 - stopPointOnBorderMap(c2));
	}
	return r;
}
coordinates stopRectangleOnBorderVMap(coordinates c, coordinates c2)
{
	coordinates r = stopPointOnBorderVmap(c);
	if (!isInMap(c2))
	{
		r = r - (c2 - stopPointOnBorderVmap(c2));
	}
	return r;
}
coordinates vMapSm(coordinates c) {
	c.x %= 8;
	c.y %= 8;
	return c;
}
coordinates vMapSc(coordinates c) {
	c.y /= 8;
	c.y *= 8;
	c.x /= 8;
	c.x *= 8;
	if (!isInVmap(c)) {
		while (true)
			;
	}
	return c;
}
coordinates vMapCMove(coordinates c, uint8_t x, uint8_t y) {
	coordinates m = vMapSc(c);
	m.x += x;
	m.y += y;
	if (!isInVmap(m)) {
		while (true)
			;
	}
	return m;
}
coordinates vMapSUp(coordinates c) {
	coordinates vMapS = vMapSc(c);
	vMapS.y -= 8;
	if (!isInVmap(vMapS)) {
		while (true)
			;
	}
	return vMapS;
}

coordinates vMapSDown(coordinates c) {
	coordinates vMapS = vMapSc(c);
	vMapS.y += 8;
	if (!isInVmap(vMapS)) {
		while (true)
			;
	}
	return vMapS;
}
coordinates vMapSLeft(coordinates c) {
	coordinates vMapS = vMapSc(c);
	vMapS.x -= 8;
	if (!isInVmap(vMapS)) {
		while (true)
			;
	}
	return vMapS;
}
coordinates vMapSRight(coordinates c) {
	coordinates vMapS = vMapSc(c);
	vMapS.x += 8;
	if (!isInVmap(vMapS)) {
		while (true)
			;
	}
	return vMapS;
}
coordinates vMapSUpLeft(coordinates c) {
	coordinates vMapS = vMapSc(c);
	vMapS.y -= 8;
	vMapS.x -= 8;
	if (!isInVmap(vMapS)) {
		while (true)
			;
	}
	return vMapS;
}
coordinates vMapSUpRright(coordinates c) {
	coordinates vMapS = vMapSc(c);
	vMapS.y -= 8;
	vMapS.x += 8;
	if (!isInVmap(vMapS)) {
		while (true)
			;
	}
	return vMapS;
}
coordinates vMapSDownLeft(coordinates c) {
	coordinates vMapS = vMapSc(c);
	vMapS.y += 8;
	vMapS.x -= 8;
	if (!isInVmap(vMapS)) {
		while (true)
			;
	}
	return vMapS;
}
coordinates vMapSDownRigth(coordinates c) {
	coordinates vMapS = vMapSc(c);
	vMapS.y += 8;
	vMapS.x += 8;
	if (!isInVmap(vMapS)) {
		while (true)
			;
	}
	return vMapS;
}
}

