/*
 * enemyBase1.cpp
 *
 *  Created on: Jan 10, 2025
 *      Author: dev
 */

#include <enemyBase.hpp>
#include "coordinatesTools.hpp"
std::int8_t enemyBase::currentNumber_ = 0;
enemyBase::enemyBase(const entitiesInitialData::enemys typeOfEnemy,
			const coordinates startPoint,
			const std::int8_t startLife,
			const std::int8_t scorePoint,
			const segment& texture,
			const coordinates& texture_corner_1,
			const coordinates& texture_corner_2,
			const std::uint8_t slownest,
			const coordinates& moveDirection)
	:type_(typeOfEnemy)
	,currentPosition_(startPoint)
	,prevousPosition_(startPoint)
	,lifeStatus_(startLife)
	,scorePoints_(scorePoint)
	,texture_(texture)
	,texture_corner_1_(texture_corner_1)
	,texture_corner_2_(texture_corner_2)
	,slownest_(slownest)
	,moveDirection_(moveDirection)
	,toRemove_(false)
	,missMoveCtr_(0)
	{currentNumber_++;}
void enemyBase::move()
{
	if(!toRemove_)
	{

		if (missMoveCtr_++ == slownest_)
		{
			prevousPosition_ = currentPosition_;
			currentPosition_ = currentPosition_ + moveDirection_;
			missMoveCtr_ = 0;
		}
	}
	else
	{
		prevousPosition_ = currentPosition_;
		currentPosition_ = coordinates({0,0});
	}
}
void enemyBase::takeDamage(uint8_t value)
{
	if( lifeStatus_ > 0)
	{
		lifeStatus_ -= value;
	}
	if(lifeStatus_ == 0)
	{
		setToRemove();
	}
}
std::int8_t enemyBase::getScore()
{
	return scorePoints_;
}
std::int8_t enemyBase::getCurrentLife()
{
	return lifeStatus_;
}
entitiesInitialData::enemys enemyBase::getType()
{
	return type_;
}
const segment& enemyBase::getTexture() const
{
	return texture_;
}
coordinates& enemyBase::getCurrentPosition()
{
	return currentPosition_;
}
coordinates& enemyBase::getPrevousCoords()
{
	return prevousPosition_;
}
const coordinates& enemyBase::getTextureCorner1() const
{
	return texture_corner_1_;
}
const coordinates& enemyBase::getTextureCorner2() const
{
	return texture_corner_2_;
}
const bool enemyBase::isToRemove() const
{
	return toRemove_;
}
void enemyBase::setToRemove()
{
	toRemove_ = true;
}
