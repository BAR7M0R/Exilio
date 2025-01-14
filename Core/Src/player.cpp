/**
 * @file player.cpp
 * @author Bartłomiej Głodek
 * @date 2025-01-05
 *
 * @brief
 * @details
 *
 *
 */

#include "player.hpp"
#include "entitiesInitData.hpp"
#include "coordinatesTools.hpp"
using namespace entitiesInitialData;

player::player()
:texture_(entitiesInitialData::player1::texture_data)
,texture_corner_1_(entitiesInitialData::player1::texture_corner_1)
,texture_corner_2_(entitiesInitialData::player1::texture_corner_2)
,offset_(entitiesInitialData::player1::offset)
,currentPosition_({70,70})
,previousPosition_({10,10})
{}
player& player::getInstance()
{
	static player instance;
	return instance;

}
void player::move(coordinates direction)
{
	using namespace coordinatesTools;
	previousPosition_ = currentPosition_;
	currentPosition_ = currentPosition_ + direction;
	currentPosition_ = stopRectangleOnBorderMap(currentPosition_,currentPosition_ + texture_corner_2_);
}
coordinates& player::getCurrentPosition()
{
	return currentPosition_;
}
coordinates& player::getPreviousPosition()
{
	return previousPosition_;
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
const coordinates& player::getOffset() const
{
	return offset_;
}

