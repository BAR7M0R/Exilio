/**
 * @file claster.hpp
 * @author Bartłomiej Głodek
 * @date 2024-12-31
 *
 * @brief
 * @details
 *
 *
 */

#ifndef INC_CLASTER_HPP_
#define INC_CLASTER_HPP_

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

#endif /* INC_CLASTER_HPP_ */
