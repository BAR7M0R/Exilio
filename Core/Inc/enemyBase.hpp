/**
 * @file enemyBase.hpp
 * @author Bartłomiej Głodek
 * @date 2025-01-10
 *
 * @brief
 * @details
 *
 *
 */
#ifndef INC_ENEMYBASE_HPP_
#define INC_ENEMYBASE_HPP_
#include <cstdint>
#include "coordinates.hpp"
#include "entitiesInitData.hpp"

class enemyBase
{
public:
	enemyBase(const entitiesInitialData::enemys typeOfEnemy,
			const coordinates startPoint,
			const std::int8_t startLife,
			const std::int8_t scorePoint,
			const segment& texture,
			const coordinates& texture_corner_1,
			const coordinates& texture_corner_2,
			const std::uint8_t slownest,
			const coordinates& moveDirection);
	void move();
	void takeDamage(uint8_t value);
	std::int8_t getScore();
	std::int8_t getCurrentLife();
	entitiesInitialData::enemys getType();
	const segment& getTexture() const;
	coordinates& getCurrentCoords();
	coordinates& getPrevousCoords();
	const coordinates& getTextureCorner1() const;
	const coordinates& getTextureCorner2() const;
	const bool isToRemove() const;
	void setToRemove();

	static std::int8_t currentNumber_;
private:
	const entitiesInitialData::enemys type_;
	coordinates currentPosition_;
	coordinates prevousPosition_;
	std::int8_t lifeStatus_;
	const std::int8_t scorePoints_;
	const segment& texture_;
	const coordinates& texture_corner_1_;
	const coordinates& texture_corner_2_;
	const std::uint8_t slownest_;
	const coordinates moveDirection_;
	bool toRemove_;
	std::uint8_t missMoveCtr_;
};
#endif /* INC_ENEMYBASE_HPP_ */
