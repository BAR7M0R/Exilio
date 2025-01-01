/*
 * claster.hpp
 *
 *  Created on: Dec 31, 2024
 *      Author: dev
 */

#ifndef SRC_CLASTER_HPP_
#define SRC_CLASTER_HPP_

#include <array>

#include "segment.hpp"

#include "coordinates.hpp"

class claster {
public:
	claster();
	claster(segment& s1, segment& s2, segment& s3, segment& s4);
	void putSegmentOnClaster(coordinates relativeCoords, segment s);
	void putBlackmaskSegmentOnClaster(coordinates relativeCoords, segment mask);
private:
	std::array<segment*,4> _claster; //2x2 to 1x4 array
};

#endif /* SRC_CLASTER_HPP_ */
