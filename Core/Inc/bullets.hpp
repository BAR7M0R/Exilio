/**
 * @file bullets.hpp
 * @author Bartłomiej Głodek
 * @date 2025-01-05
 *
 * @brief
 * @details
 *
 *
 */

#ifndef SRC_TASKS_BULLETS_HPP_
#define SRC_TASKS_BULLETS_HPP_
#include "coordinates.hpp"
#include "segment.hpp"
#include "coordinatesTools.hpp"
#include "entitiesInitData.hpp"


class BulletBase
{
public:
	BulletBase(const bullets typeOfEnemy,
			const coordinates startPoint,
			const segment& texture,
			const coordinates& texture_corner_1,
			const coordinates& texture_corner_2,
			const coordinates& moveDirection)
	:type_(typeOfEnemy)
	,currentPosition_(startPoint)
	,prevousPosition_(startPoint)
	,texture_(texture)
	,texture_corner_1_(texture_corner_1)
	,texture_corner_2_(texture_corner_2)
	,moveDirection_(moveDirection)
	,onMap_(true)
	{}
	void move()
	{
		prevousPosition_ = currentPosition_;
		currentPosition_ = currentPosition_ + moveDirection_;
	}
	void remove()
	{
 		currentPosition_ = coordinates({0,0});
 		prevousPosition_ = currentPosition_;
		onMap_ = false;
	}
	bullets getType()
	{
		return type_;
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
	coordinates currentPosition_;
	coordinates prevousPosition_;
	bool onMap_;
	const bullets type_;
	const segment texture_;
	const coordinates texture_corner_1_;
	const coordinates texture_corner_2_;
	const coordinates moveDirection_;
	static std::int8_t currentNumber_ = 0;
};
class BulletManager
{
private:
	BulletManager(){}
	BulletManager(const BulletManager&) = delete;
	BulletManager operator=(const BulletManager&) = delete;
public:
	static BulletManager& getInstance()
	{
		static BulletManager instance;
		return instance;
	}
	void add(const bullets typeOfBullet, const coordinates& startPoint)
		{
			if(BulletBase::currentNumberOfBullets_ != max_bullet_number)
			{
				std::unique_ptr<BulletBase> newInstance;
				switch (typeOfEnemy)
				{
					using namespace EntitiesInitialData;
					case bullets::b1:
					{
						newInstance = std::make_unique<BulletBase>(typeOfBullet,
					startPoint,
					bullet1::demage_points,
					bullet1::texture_data,
					bullet1::texture_corner_1,
					bullet1::texture_corner_2,
					coordinates({0,-1}));
					}break;

				}
				for(BulletBase& b : bullets_)
				{
					if (b == nullptr)
					{
						b = std::move(newInstance);
						enemyBase::currentNumberOfBullets_++;
						break;
					}
				}
			}

		}
	void move()
	{
		for(BulletBase& b: bullets_)
		{
			if(b != nullptr)
			{
				b.Move();
			}
		}
	}
	void remove()
	{
		for(BulletBase& b: bullets_)
		{
			if(b != nullptr)
			{
				b.Remove();
			}
		}
	}
    auto begin() { return bullets_.begin(); }
    auto end() { return bullets_.end(); }

    auto begin() const { return bullets_.begin(); }
    auto end() const { return bullets_.end(); }
private:
	std::array<std::unique_ptr<BulletBase>, max_bullet_number> bullets_;
};
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
