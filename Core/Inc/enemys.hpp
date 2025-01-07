/*
 * enemy.hpp
 *
 *  Created on: Jan 5, 2025
 *      Author: Bartłomiej Głodek
 */

#ifndef INC_ENEMY_HPP_
#define INC_ENEMY_HPP_

#include "coordinates.hpp"
#include "segment.hpp"
#include "coordinatesTools.hpp"
#include "entitiesInitData.hpp"

class enemy
{
public:
	enemy()
	{

	}
	void create(coordinates c, coordinates direction)
	{
		onMap_ = true;
		currentPosition_ = c;
		prevousPosition_ = currentPosition_;
		direction_ = direction;
	}
	void move()
	{
		using namespace coordinatesTools;
		if (onMap_)
		{
			prevousPosition_ = currentPosition_;
			currentPosition_ = currentPosition_ + direction_;
			currentPosition_ = coordinatesTools::stopRectangleOnBorderVMap(currentPosition_,currentPosition_ + texture_corner_2_);
		}

	}
	void remove()
	{
		currentPosition_ = coordinates({0,0});
		move();
		onMap_ = false;
	}
const segment& getTexture() const
	{
		return texture_;
	}
	coordinates& getCurrentCoords()
	{
		return currentPosition_;
	}
	coordinates& getPrevousCoords()
	{
		return prevousPosition_;
	}
const coordinates& getTextureCorner1() const
	{
		return texture_corner_1_;
	}
const coordinates& getTextureCorner2() const
	{
		return texture_corner_2_;
	}
const bool isOnMap() const
	{
		return onMap_;
	}
private:

	bool onMap_ = false;
	static const segment texture_;
	static const coordinates texture_corner_1_;
	static const coordinates texture_corner_2_;
	coordinates direction_;
	coordinates currentPosition_;
	coordinates prevousPosition_;
};
class enemys {
private:
	enemys(){}
	enemys(const enemys&) = delete;
	enemys& operator=(const enemys&) = delete;
public:
	static enemys& GetInstance()
	{
		static enemys instance;
		return instance;

	}
	enemy at(std::size_t e)
	{
		return enemys_.at(e);
	}
	void add(coordinates c)
	{
		for(auto& e : enemys_)
		{
			if (e.isOnMap() ==false)
			{
				e.create(c, coordinates({0, 1}));
				break;
			}
		}
	}
	void move(/*enemys& toChack*/)
	{
		for(enemy& e : enemys_)
		{
			if (e.isOnMap())
			{
				if (coordinatesTools::isInVmap(e.getCurrentCoords()))
				{
					e.move();
				}
			}
		}
	}

	void remove()
	{
		for(enemy& e : enemys_)
		{
			if (coordinatesTools::isInDownMargin(e.getCurrentCoords()))
			{
				e.remove();
			}
		}
	}
    auto begin() { return enemys_.begin(); }
    auto end() { return enemys_.end(); }

    auto begin() const { return enemys_.begin(); }
    auto end() const { return enemys_.end(); }
private:
	std::array<enemy, 3> enemys_;
};

#endif /* INC_ENEMY_HPP_ */
