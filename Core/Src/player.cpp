/*
 * player.cpp
 *
 *  Created on: Jan 5, 2025
 *      Author: dev
 */

#include "player.hpp"
#include "entitiesInitData.hpp"
#include "coordinatesTools.hpp"
using namespace EntitiesInitialData;

player::player()
:texture_(EntitiesInitialData::player1::texture_data)
,texture_corner_1_(EntitiesInitialData::player1::texture_corner_1)
,texture_corner_2_(EntitiesInitialData::player1::texture_corner_2)
,currentPosition_({10,10})
,prevousPosition_({10,10})
{}
player& player::GetInstance()
{
	static player instance;
	return instance;

}
void player::updatePosition(coordinates direction)
{
	using namespace coordinatesTools;
	prevousPosition_ = currentPosition_;
	currentPosition_ = currentPosition_ + direction;
	currentPosition_ = stopRectangleOnBorderMap(currentPosition_,currentPosition_ + texture_corner_2_);
}
coordinates& player::getCurrentPosition()
{
	return currentPosition_;
}
coordinates& player::getPrevousPosition()
{
	return prevousPosition_;
}
const coordinates& player::getTextureCorner1() const
{
	return texture_corner_1_;
}
const coordinates& player::getTextureCorner2() const
{
	return texture_corner_2_;
}
const segment& player::getTexture() const
{
	return texture_;
}

