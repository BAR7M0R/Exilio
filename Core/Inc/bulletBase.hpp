/**
 * @file bulletBase.hpp
 * @author Bartłomiej Głodek
 * @date 2025-01-05
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

#ifndef INC_BULLETBASE_HPP_
#define INC_BULLETBASE_HPP_
#include "Coordinates.hpp"
#include "segment.hpp"
#include "coordinatesTools.hpp"
#include "entitiesInitData.hpp"

/**
 * @class bulletBase
 * @todo opis
 */
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

	/**
	 * @fn void move()
	 * @todo opis
	 */
	void move();


	entitiesInitialData::bullets getType();


	uint8_t getDemage();


	const segment& getTexture() const;


	coordinates& getCurrentPosition();


	coordinates& getPrevousPosition();
	/**
	 * @fn const coordinates getTextureCorner1&()const
	 * @return
	 * @todo opis
	 */
	const coordinates& getTextureCorner1() const;

	/**
	 * @fn const coordinates getTextureCorner2&()const
	 * @return
	 * @todo opis
	 */
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
