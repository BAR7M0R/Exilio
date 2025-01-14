/**
 * @file coordinatesTools.cpp
 * @author Bartłomiej Głodek
 * @date 2025-01-04
 *
 * @copyright
 * Copyright (c) Bartłomiej Głodek 2025
 * Permission is granted to use, copy, modify, and distribute this software for any non-commercial purpose, free of charge.
 * For commercial use, you must notify the author and obtain permission before using this software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES, OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT, OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * @brief Implementation of tools for managing coordinates in the virtual map.
 * @details This file contains various utility functions for working with coordinates
 * on a virtual display, such as checking if a coordinate is within the bounds
 * of the virtual map or screen, stopping coordinates on the border,
 * and handling movement on the map.
 */

#include <cstdint>
#include "coordinatesTools.hpp"
#include "displayConstans.hpp"

namespace coordinatesTools {
using namespace displayConstans;

/**
 * @fn bool isInVmap(const coordinates c)
 * @brief Checks if the given coordinate is within the bounds of the virtual map.
 * @param c The coordinate to check.
 * @return true if the coordinate is inside the virtual map, false otherwise.
 */
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

/**
 * @fn bool isInMap(const coordinates c)
 * @brief Checks if the given coordinate is within the bounds of the actual map.
 * @param c The coordinate to check.
 * @return true if the coordinate is inside the map, false otherwise.
 */
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

/**
 * @fn bool isInDownMargin(const coordinates c)
 * @brief Checks if the given coordinate is within the lower margin of the display.
 * @param c The coordinate to check.
 * @return true if the coordinate is outside the bottom margin, false otherwise.
 */
bool isInDownMargin(const coordinates c) {
	bool r = false;
	if (c.y > (displayConstans::height_lcd + displayConstans::v_margin_height)*8) r = true;
	return r;
}

/**
 * @fn bool isPointInScope(const coordinates c, const coordinates scopePoint1, const coordinates scopePoint2)
 * @brief Checks if a point is within a rectangular scope.
 * @param c The coordinate to check.
 * @param scopePoint1 The first corner of the scope.
 * @param scopePoint2 The opposite corner of the scope.
 * @return true if the point is within the scope, false otherwise.
 */
bool isPointInScope(const coordinates c, const coordinates scopePoint1, const coordinates scopePoint2) {
	bool r = false;
	if ((c.x >= scopePoint1.x and c.x <= scopePoint2.x) and (c.y >= scopePoint1.y and c.y <= scopePoint2.y))
	{
		r = true;
	}
	return r;
}

/**
 * @fn bool isScopeInScope(const coordinates scope1Point1, const coordinates scope1Point2, const coordinates scope2Point1, const coordinates scope2Point2)
 * @brief Checks if one rectangular scope is fully within another scope.
 * @param scope1Point1 The first corner of the first scope.
 * @param scope1Point2 The opposite corner of the first scope.
 * @param scope2Point1 The first corner of the second scope.
 * @param scope2Point2 The opposite corner of the second scope.
 * @return true if the first scope is fully within the second, false otherwise.
 */
bool isScopeInScope(const coordinates scope1Point1, const coordinates scope1Point2, const coordinates scope2Point1, const coordinates scope2Point2) {
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

/**
 * @fn coordinates stopPointOnBorderMap(coordinates c)
 * @brief Adjusts a coordinate to be within the bounds of the map.
 * @param c The coordinate to adjust.
 * @return The adjusted coordinate.
 */
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

/**
 * @fn coordinates stopPointOnBorderVmap(coordinates c)
 * @brief Adjusts a coordinate to be within the bounds of the virtual map.
 * @param c The coordinate to adjust.
 * @return The adjusted coordinate.
 */
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

/**
 * @fn coordinates stopRectangleOnBorderMap(coordinates c, coordinates c2)
 * @brief Adjusts two coordinates to be within the bounds of the map.
 * @param c The first coordinate to adjust.
 * @param c2 The second coordinate to adjust.
 * @return The adjusted coordinates.
 */
coordinates stopRectangleOnBorderMap(coordinates c, coordinates c2)
{
	coordinates r = stopPointOnBorderMap(c);
	if (!isInMap(c2))
	{
		r = r - (c2 - stopPointOnBorderMap(c2));
	}
	return r;
}

/**
 * @fn coordinates stopRectangleOnBorderVMap(coordinates c, coordinates c2)
 * @brief Adjusts two coordinates to be within the bounds of the virtual map.
 * @param c The first coordinate to adjust.
 * @param c2 The second coordinate to adjust.
 * @return The adjusted coordinates.
 */
coordinates stopRectangleOnBorderVMap(coordinates c, coordinates c2)
{
	coordinates r = stopPointOnBorderVmap(c);
	if (!isInMap(c2))
	{
		r = r - (c2 - stopPointOnBorderVmap(c2));
	}
	return r;
}

/**
 * @fn coordinates vMapSm(coordinates c)
 * @brief Adjusts the coordinates to be within a 8x8 grid in the virtual map.
 * @param c The coordinate to adjust.
 * @return The adjusted coordinate.
 */
coordinates vMapSm(coordinates c) {
	c.x %= 8;
	c.y %= 8;
	return c;
}

/**
 * @fn coordinates vMapSc(coordinates c)
 * @brief Converts the coordinate to the start of the 8x8 grid in the virtual map.
 * @param c The coordinate to convert.
 * @return The adjusted coordinate.
 */
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

/**
 * @fn coordinates vMapCMove(coordinates c, uint8_t x, uint8_t y)
 * @brief Moves the coordinate within the 8x8 grid in the virtual map.
 * @param c The coordinate to move.
 * @param x The number of units to move in the x direction.
 * @param y The number of units to move in the y direction.
 * @return The adjusted coordinate.
 */
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

/**
 * @fn coordinates vMapSUp(coordinates c)
 * @brief Moves the coordinate up within the virtual map.
 * @param c The coordinate to move.
 * @return The adjusted coordinate.
 */
coordinates vMapSUp(coordinates c) {
	coordinates vMapS = vMapSc(c);
	vMapS.y -= 8;
	if (!isInVmap(vMapS)) {
		while (true)
			;
	}
	return vMapS;
}

/**
 * @fn coordinates vMapSDown(coordinates c)
 * @brief Moves the coordinate down within the virtual map.
 * @param c The coordinate to move.
 * @return The adjusted coordinate.
 */
coordinates vMapSDown(coordinates c) {
	coordinates vMapS = vMapSc(c);
	vMapS.y += 8;
	if (!isInVmap(vMapS)) {
		while (true)
			;
	}
	return vMapS;
}

/**
 * @fn coordinates vMapSLeft(coordinates c)
 * @brief Moves the coordinate left within the virtual map.
 * @param c The coordinate to move.
 * @return The adjusted coordinate.
 */
coordinates vMapSLeft(coordinates c) {
	coordinates vMapS = vMapSc(c);
	vMapS.x -= 8;
	if (!isInVmap(vMapS)) {
		while (true)
			;
	}
	return vMapS;
}

/**
 * @fn coordinates vMapSRight(coordinates c)
 * @brief Moves the coordinate right within the virtual map.
 * @param c The coordinate to move.
 * @return The adjusted coordinate.
 */
coordinates vMapSRight(coordinates c) {
	coordinates vMapS = vMapSc(c);
	vMapS.x += 8;
	if (!isInVmap(vMapS)) {
		while (true)
			;
	}
	return vMapS;
}
}
