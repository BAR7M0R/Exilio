/**
 * @file claster.hpp
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
 * @brief
 * @details
 * @todo opis
 *
 *
 */

#ifndef INC_CLASTER_HPP_
#define INC_CLASTER_HPP_

#include <array>

#include "segment.hpp"

#include "coordinates.hpp"
/**
 * @class claster
 * @todo opis
 */
class claster {
public:
	claster();
	/**
	 * @fn  claster(segment&, segment&, segment&, segment&)
	 * @param s1
	 * @param s2
	 * @param s3
	 * @param s4
	 * @todo opis
	 */
	claster(segment& s1, segment& s2, segment& s3, segment& s4);
	/**
	 * @fn void putSegmentOnClaster(coordinates, segment)
	 * @param relativeCoords
	 * @param s
	 * @todo opis
	 */
	void putSegmentOnClaster(coordinates relativeCoords, segment s);
	/**
	 * @fn void putBlackmaskSegmentOnClaster(coordinates, segment)
	 * @param relativeCoords
	 * @param mask
	 * @todo opis
	 */
	void putBlackmaskSegmentOnClaster(coordinates relativeCoords, segment mask);
private:
	std::array<segment*,4> _claster; //2x2 to 1x4 array
};

#endif /* INC_CLASTER_HPP_ */
