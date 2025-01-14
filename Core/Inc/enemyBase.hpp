/**
 * @file enemyBase.hpp
 * @author Bartłomiej Głodek
 * @date 2025-01-10
 *
 * @copyright
 * Copyright (c) Bartłomiej Głodek 2025
 * Permission is granted to use, copy, modify, and distribute this software for any non-commercial purpose, free of charge.
 * For commercial use, you must notify the author and obtain permission before using this software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES, OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT, OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * @brief
 * @details
 * @todo opis
 *
 */
#ifndef INC_ENEMYBASE_HPP_
#define INC_ENEMYBASE_HPP_
#include <cstdint>
#include "coordinates.hpp"
#include "entitiesInitData.hpp"
/**
 * @class enemyBase
 * @todo opis
 */
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
	/**
	 * @fn void move()
	 * @todo opis
	 */
	void move();
	/**
	 * @fn void takeDamage(uint8_t)
	 * @param value
	 * @todo opis
	 */
	void takeDamage(uint8_t value);
	std::int8_t getScore();
	std::int8_t getCurrentLife();
	entitiesInitialData::enemys getType();
	const segment& getTexture() const;
	coordinates& getCurrentPosition();
	coordinates& getPrevousCoords();
	const coordinates& getTextureCorner1() const;
	const coordinates& getTextureCorner2() const;
	const bool isToRemove() const;
	/**
	 * @fn void setToRemove()
	 * @todo opis
	 */
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
