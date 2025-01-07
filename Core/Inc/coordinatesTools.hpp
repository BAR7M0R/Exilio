/*
 * coordinatesTools.hpp
 *
 *  Created on: Dec 31, 2024
 *      Author: Bartłomiej Głodek
 */

#include "coordinates.hpp"

#ifndef INC_COORDINATESTOOLS_HPP_
#define INC_COORDINATESTOOLS_HPP_



namespace coordinatesTools {

bool isInVmap(const coordinates c);
bool isInMap(const coordinates c);
bool isInDownMargin(const coordinates c);
bool isPointInScope(const coordinates c, const coordinates scopePoint1, const coordinates scopePoint2);
bool isScopeInScope(const coordinates scope1Point1, const coordinates scope1Point2, const coordinates scope2Point1, const coordinates scope2Point2);
coordinates stopPointOnMap(coordinates c);
coordinates stopPointOnVmap(coordinates c);
coordinates stopRectangleOnBorderMap(coordinates c, coordinates c2);
coordinates stopRectangleOnBorderVMap(coordinates c, coordinates c2);
coordinates vMapSm(coordinates c);
coordinates vMapSc(coordinates c);
coordinates vMapCMove(coordinates c, uint8_t x, uint8_t y);
coordinates vMapSUp(coordinates c);
coordinates vMapSDown(coordinates c);
coordinates vMapSLeft(coordinates c);
coordinates vMapSRight(coordinates c);
coordinates vMapSUpLeft(coordinates c);
coordinates vMapSUpRright(coordinates c);
coordinates vMapSDownLeft(coordinates c);
coordinates vMapSDownRigth(coordinates c);
}

#endif /* INC_COORDINATESTOOLS_HPP_ */
