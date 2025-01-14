/**
 * @file coordinatesTools.hpp
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
 * @brief This file contains tools combined with limits for coordinates data structure.
 * @details This header defines a collection of functions that provide various coordinate manipulations and boundary checks
 *          to ensure that coordinates stay within defined regions, such as maps and virtual maps.
 * @todo Update descriptions for each function.
 */
#include "coordinates.hpp"

#ifndef INC_COORDINATESTOOLS_HPP_
#define INC_COORDINATESTOOLS_HPP_

/**
 * @namespace coordinatesTools
 * @brief This namespace provides tools for working with coordinate data, including boundary checks and transformations.
 * @details Functions within this namespace allow for operations like verifying if coordinates are inside defined areas
 *          or adjusting coordinates to stay within specific limits.
 */
namespace coordinatesTools {
/**
 * @fn bool isInVmap(const coordinates c)
 * @brief Checks if the given coordinate is within the bounds of the virtual map.
 * @param c The coordinate to check.
 * @return true if the coordinate is inside the virtual map, false otherwise.
 */
bool isInVmap(const coordinates c);

/**
 * @fn bool isInMap(const coordinates c)
 * @brief Checks if the given coordinate is within the bounds of the actual map.
 * @param c The coordinate to check.
 * @return true if the coordinate is inside the map, false otherwise.
 */
bool isInMap(const coordinates c);

/**
 * @fn bool isInDownMargin(const coordinates c)
 * @brief Checks if the given coordinate is within the lower margin of the display.
 * @param c The coordinate to check.
 * @return true if the coordinate is outside the bottom margin, false otherwise.
 */
bool isInDownMargin(const coordinates c);

/**
 * @fn bool isPointInScope(const coordinates c, const coordinates scopePoint1, const coordinates scopePoint2)
 * @brief Checks if a point is within a rectangular scope.
 * @param c The coordinate to check.
 * @param scopePoint1 The first corner of the scope.
 * @param scopePoint2 The opposite corner of the scope.
 * @return true if the point is within the scope, false otherwise.
 */
bool isPointInScope(const coordinates c,
		const coordinates scopePoint1,
		const coordinates scopePoint2);
/**
 * @fn bool isScopeInScope(const coordinates scope1Point1, const coordinates scope1Point2, const coordinates scope2Point1, const coordinates scope2Point2)
 * @brief Checks if one rectangular scope is fully within another scope.
 * @param scope1Point1 The first corner of the first scope.
 * @param scope1Point2 The opposite corner of the first scope.
 * @param scope2Point1 The first corner of the second scope.
 * @param scope2Point2 The opposite corner of the second scope.
 * @return true if the first scope is fully within the second, false otherwise.
 */
bool isScopeInScope(const coordinates scope1Point1,
		const coordinates scope1Point2,
		const coordinates scope2Point1,
		const coordinates scope2Point2);

/**
 * @fn coordinates stopPointOnBorderMap(coordinates c)
 * @brief Adjusts a coordinate to be within the bounds of the map.
 * @param c The coordinate to adjust.
 * @return The adjusted coordinate.
 */
coordinates stopPointOnBorderMap(coordinates c);

/**
 * @fn coordinates stopPointOnBorderVmap(coordinates c)
 * @brief Adjusts a coordinate to be within the bounds of the virtual map.
 * @param c The coordinate to adjust.
 * @return The adjusted coordinate.
 */
coordinates stopPointOnBorderVmap(coordinates c);

/**
 * @fn coordinates stopRectangleOnBorderMap(coordinates c, coordinates c2)
 * @brief Adjusts two coordinates to be within the bounds of the map.
 * @param c The first coordinate to adjust.
 * @param c2 The second coordinate to adjust.
 * @return The adjusted coordinates.
 */
coordinates stopRectangleOnBorderMap(coordinates c, coordinates c2);

/**
 * @fn coordinates stopRectangleOnBorderVMap(coordinates c, coordinates c2)
 * @brief Adjusts two coordinates to be within the bounds of the virtual map.
 * @param c The first coordinate to adjust.
 * @param c2 The second coordinate to adjust.
 * @return The adjusted coordinates.
 */
coordinates stopRectangleOnBorderVMap(coordinates c, coordinates c2);
/**
 * @fn coordinates vMapSm(coordinates c)
 * @brief Adjusts the coordinates to be within a 8x8 grid in the virtual map.
 * @param c The coordinate to adjust.
 * @return The adjusted coordinate.
 */
coordinates vMapSm(coordinates c);

/**
 * @fn coordinates vMapSc(coordinates c)
 * @brief Converts the coordinate to the start of the 8x8 grid in the virtual map.
 * @param c The coordinate to convert.
 * @return The adjusted coordinate.
 */
coordinates vMapSc(coordinates c);

/**
 * @fn coordinates vMapCMove(coordinates c, uint8_t x, uint8_t y)
 * @brief Moves the coordinate within the 8x8 grid in the virtual map.
 * @param c The coordinate to move.
 * @param x The number of units to move in the x direction.
 * @param y The number of units to move in the y direction.
 * @return The adjusted coordinate.
 */
coordinates vMapCMove(coordinates c, uint8_t x, uint8_t y);

/**
 * @fn coordinates vMapSUp(coordinates c)
 * @brief Moves the coordinate up within the virtual map.
 * @param c The coordinate to move.
 * @return The adjusted coordinate.
 */
coordinates vMapSUp(coordinates c);

/**
 * @fn coordinates vMapSDown(coordinates c)
 * @brief Moves the coordinate down within the virtual map.
 * @param c The coordinate to move.
 * @return The adjusted coordinate.
 */
coordinates vMapSDown(coordinates c);
/**
 * @fn coordinates vMapSLeft(coordinates c)
 * @brief Moves the coordinate left within the virtual map.
 * @param c The coordinate to move.
 * @return The adjusted coordinate.
 */
coordinates vMapSLeft(coordinates c);

/**
 * @fn coordinates vMapSRight(coordinates c)
 * @brief Moves the coordinate right within the virtual map.
 * @param c The coordinate to move.
 * @return The adjusted coordinate.
 */
coordinates vMapSRight(coordinates c);
}

#endif /* INC_COORDINATESTOOLS_HPP_ */
