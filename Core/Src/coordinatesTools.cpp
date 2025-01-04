/*
 * coordinatesTools.cpp
 *
 *  Created on: Jan 4, 2025
 *      Author: dev
 */
#include <cstdint>
#include "coordinatesTools.hpp"
#include "displayConstans.hpp"

namespace coordinatesTools {
using namespace displayConstans;
bool isInVmap(coordinates c) {
	bool isOK = true;
	if ((c.x < 0) and (c.x >= V_WIDTH)) {
		isOK = false;
	}
	if ((c.y >= 0) and (c.y < V_HEIGHT * 8)) {
		isOK = false;
	}
	return isOK;
}
bool isInMap(coordinates c) {
	bool isOK = true;
	if ((c.x < V_MARGIN_WIDTH) and (c.x >= V_MARGIN_WIDTH + WIDTH_LCD)) {
		isOK = false;
	}
	if ((c.y < V_MARGIN_HEIGHT * 8)
			and (c.y >= (V_MARGIN_HEIGHT + HEIGHT_LCD) * 8)) {
		isOK = false;
	}
	return isOK;
}

coordinates stopOnMap(coordinates c) {
	if (!isInMap(c)) {
		if (c.x < V_MARGIN_WIDTH)
			c.x = V_MARGIN_WIDTH;
		if (c.x >= V_MARGIN_WIDTH + WIDTH_LCD)
			c.x = V_MARGIN_WIDTH + WIDTH_LCD;
		if (c.y < V_MARGIN_HEIGHT * 8)
			c.y = V_MARGIN_HEIGHT * 8;
		if (c.y >= (V_MARGIN_HEIGHT + HEIGHT_LCD) * 8)
			c.y = (V_MARGIN_HEIGHT + HEIGHT_LCD) * 8;
	}
	return c;

}
coordinates stopOnVmap(coordinates c) {
	if (!isInVmap(c)) {
		if (c.x < 0)
			c.x = 0;
		if (c.x >= V_MARGIN_WIDTH)
			c.x = V_MARGIN_WIDTH;
		if (c.y < 0)
			c.y = 0;
		if (c.y >= V_MARGIN_HEIGHT * 8)
			c.y = V_MARGIN_HEIGHT * 8;
	}
	return c;
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

