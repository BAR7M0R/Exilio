/*
 * player.hpp
 *
 *  Created on: Jan 5, 2025
 *      Author: dev
 */

#ifndef INC_PLAYER_HPP_
#define INC_PLAYER_HPP_
#include "coordinates.hpp"
#include "segment.hpp"
class player
{
private:
	player();
	player(const player&) = delete;
	player& operator=(const player&) = delete;

public:
	static player& GetInstance();
	void updatePosition(coordinates direction);
	coordinates& getCurrentPosition();
	coordinates& getPrevousPosition();
	const segment& getTexture() const;
	const coordinates& getTextureCorner1() const;
	const coordinates& getTextureCorner2() const;

private:
	const segment texture_;
	const coordinates texture_corner_1_;
	const coordinates texture_corner_2_;

	coordinates currentPosition_;
	coordinates prevousPosition_;
	static player instance_;
};

#endif /* INC_PLAYER_HPP_ */
