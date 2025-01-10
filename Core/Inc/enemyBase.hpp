/*
 * enemyBase.hpp
 *
 *  Created on: Jan 10, 2025
 *      Author: dev
 */

#ifndef INC_ENEMYBASE_HPP_
#define INC_ENEMYBASE_HPP_
#include <cstdint>
#include "coordinates.hpp"
#include "entitiesInitData.hpp"

class enemyBase
{
public:
	enemyBase(const enemys typeOfEnemy,
			const coordinates startPoint,
			const std::int8_t startLife,
			const std::int8_t scorePoint,
			const segment& texture,
			const coordinates& texture_corner_1,
			const coordinates& texture_corner_2,
			const coordinates& moveDirection);
	void move();
	void takeDamage(uint8_t value);
	void remove();
	std::int8_t getScore();
	std::int8_t getCurrentLife();
	bullets getType();
	const segment& getTexture() const;
	coordinates& getCurrentCoords();
	coordinates& getPrevousCoords();
	const coordinates& getTextureCorner1() const;
	const coordinates& getTextureCorner2() const;
	const bool isOnMap() const;
private:
	coordinates currentPosition_;
	coordinates prevousPosition_;
	std::int8_t lifeStatus_;
	bool onMap_;
	const enemys type_;
	const std::int8_t scorePoints_;
	const segment texture_;
	const coordinates texture_corner_1_;
	const coordinates texture_corner_2_;
	const coordinates moveDirection_;
	static std::int8_t currentNumberOfEnemys_;
};
#endif /* INC_ENEMYBASE_HPP_ */
