/*
 * bullets.hpp
 *
 *  Created on: Jan 5, 2025
 *      Author: dev
 */

#ifndef SRC_TASKS_BULLETS_HPP_
#define SRC_TASKS_BULLETS_HPP_
#include "coordinates.hpp"
#include "segment.hpp"
#include "coordinatesTools.hpp"
#include "entitiesInitData.hpp"

class bullet
{
public:
	bullet()
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
		prevousPosition_ = currentPosition_;
		currentPosition_ = currentPosition_ + direction_;
		currentPosition_ = coordinatesTools::stopRectangleOnBorderVMap(currentPosition_,currentPosition_ + texture_corner_2_);
	}
	void remove()
	{
		currentPosition_ = coordinates({0,0});
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
class bullets {
private:
	bullets(){}
	bullets(const bullets&) = delete;
	bullets& operator=(const bullets&) = delete;
public:
	static bullets& GetInstance()
	{
		static bullets instance;
		return instance;

	}
	bullet at(std::size_t i)
	{
		return bullets_.at(i);
	}
	void add(coordinates c)
	{
		for(auto& i : bullets_)
		{
			if (i.isOnMap() ==false)
			{
				i.create(c, coordinates({0, -1}));
				break;
			}
		}
	}
	void move(/*enemys& toChack*/)
	{
		for(bullet& b : bullets_)
		{
			if (b.isOnMap())
			{
				if (coordinatesTools::isInMap(b.getCurrentCoords()))
				{
					//for (enemy& e : enemys)
					//{
						//if (!coordinatesTools::isScopeInScope(b.getCurrentCoords() + getTextureCorner1(), b.getCurrentCoords() + b.getTextureCorner2(),
								//e.getCurrentCoords() + getTextureCorner1(), e.getCurrentCoords() + e.getTextureCorner2());
						b.move();
					//}
				}
			}
		}
	}

	void remove()
	{
		for(bullet& b : bullets_)
		{
			if (!coordinatesTools::isInMap(b.getCurrentCoords()))
			{
				b.remove();
			}
		}
	}
    auto begin() { return bullets_.begin(); }
    auto end() { return bullets_.end(); }

    auto begin() const { return bullets_.begin(); }
    auto end() const { return bullets_.end(); }

private:
	std::array<bullet, 6> bullets_;
};

#endif /* SRC_TASKS_BULLETS_HPP_ */
