/*
 * enemyBase1.cpp
 *
 *  Created on: Jan 10, 2025
 *      Author: dev
 */

#include <enemyBase.hpp>
#include "coordinatesTools.hpp"
static std::int8_t currentNumberOfEnemys_ = 0;

enemyBase::enemyBase(const enemys typeOfEnemy,
			const coordinates startPoint,
			const std::int8_t startLife,
			const std::int8_t scorePoint,
			const segment& texture,
			const coordinates& texture_corner_1,
			const coordinates& texture_corner_2,
			const coordinates& moveDirection)
	:type_(typeOfEnemy)
	,currentPosition_(startPoint)
	,prevousPosition_(startPoint)
	,lifeStatus_(startLife)
	,scorePoints_(scorePoint)
	,texture_(texture)
	,texture_corner_1_(texture_corner_1)
	,texture_corner_2_(texture_corner_2)
	,moveDirection_(moveDirection)
	,onMap_(true)
	{}
void enemyBase::move()
{
	prevousPosition_ = currentPosition_;
	currentPosition_ = currentPosition_ + moveDirection_;
}
void enemyBase::takeDamage(uint8_t value)
{
	if( lifeStatus_ > 0)
	{
		lifeStatus_ -= value;
	}
	else
	{
		remove();
	}
}
void enemyBase::remove()
{
	currentPosition_ = coordinates({0,0});
	prevousPosition_ = currentPosition_;
	onMap_ = false;
}
std::int8_t enemyBase::getScore()
{
	return scorePoints_;
}
std::int8_t enemyBase::getCurrentLife()
{
	return lifeStatus_;
}
bullets enemyBase::getType()
{
	return type_;
}
const segment& enemyBase::getTexture() const
{
	return texture_;
}
coordinates& enemyBase::getCurrentCoords()
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
const bool enemyBase::isOnMap() const
{
	return onMap_;
}
