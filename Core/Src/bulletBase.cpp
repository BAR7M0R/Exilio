/**
 * @file bulletBase.cpp
 * @author Bartłomiej Głodek
 * @date 2024-12-05
 *
 * @brief
 * @details
 *
 *
 */
#include <bulletBase.hpp>
std::int8_t bulletBase::currentNumber_ = 0;

bulletBase::bulletBase(const entitiesInitialData::bullets typeOfEnemy,
		const coordinates startPoint,
		const std::uint8_t demage,
		const segment& texture,
		const coordinates& texture_corner_1,
		const coordinates& texture_corner_2,
		const coordinates moveDirection)
:type_(typeOfEnemy)
,currentPosition_(startPoint)
,prevousPosition_(startPoint)
,demage_(demage)
,texture_(texture)
,texture_corner_1_(texture_corner_1)
,texture_corner_2_(texture_corner_2)
,moveDirection_(moveDirection)
,onMap_(true)
,toRemove_(false)
{++currentNumber_;}
void bulletBase::move()
{
	if(!toRemove_)
	{
	prevousPosition_ = currentPosition_;
	currentPosition_ = currentPosition_ + moveDirection_;
	}
	else
	{
		prevousPosition_ = currentPosition_;
		currentPosition_ = coordinates({0,0});
	}
}
entitiesInitialData::bullets bulletBase::getType()
{
	return type_;
}
uint8_t bulletBase::getDemage()
{
	return demage_;
}
const segment& bulletBase::getTexture() const
{
	return texture_;
}
coordinates& bulletBase::getCurrentCoords()
{
	return currentPosition_;
}
coordinates& bulletBase::getPrevousCoords()
{
	return prevousPosition_;
}
const coordinates& bulletBase::getTextureCorner1() const
{
	return texture_corner_1_;
}
const coordinates& bulletBase::getTextureCorner2() const
{
	return texture_corner_2_;
}
const bool bulletBase::isOnMap() const
{
	return onMap_;
}
const bool bulletBase::isToRemove() const
{
	return toRemove_;
}
void bulletBase::setToRemove()
{
	toRemove_ = true;
}
