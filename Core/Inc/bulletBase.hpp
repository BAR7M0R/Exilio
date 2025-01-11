/**
 * @file bulletBase.hpp
 * @author Bartłomiej Głodek
 * @date 2025-01-05
 *
 * @brief
 * @details
 *
 *
 */

#ifndef INC_BULLETBASE_HPP_
#define INC_BULLETBASE_HPP_
#include "Coordinates.hpp"
#include "segment.hpp"
#include "coordinatesTools.hpp"
#include "entitiesInitData.hpp"


class bulletBase
{
public:
	bulletBase(const entitiesInitialData::bullets typeOfEnemy,
			const coordinates startPoint,
			const std::uint8_t demage,
			const segment& texture,
			const coordinates& texture_corner_1,
			const coordinates& texture_corner_2,
			const coordinates moveDirection);
	void move();
	entitiesInitialData::bullets getType();
	uint8_t getDemage();
const segment& getTexture() const;
	coordinates& getCurrentCoords();
	coordinates& getPrevousCoords();
const coordinates& getTextureCorner1() const;
const coordinates& getTextureCorner2() const;
const bool isOnMap() const;
const bool isToRemove() const;
void setToRemove();
	static std::int8_t currentNumber_;
private:
	const entitiesInitialData::bullets type_;
	coordinates currentPosition_;
	coordinates prevousPosition_;
	const uint8_t demage_;
	const segment& texture_;
	const coordinates& texture_corner_1_;
	const coordinates& texture_corner_2_;
	const coordinates moveDirection_;
	bool onMap_;
	bool toRemove_;

};
#endif /* INC_BULLETBASE_HPP_ */
