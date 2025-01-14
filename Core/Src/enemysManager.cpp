/**
 * @file enemysManager.cpp
 * @author Bartłomiej Głodek
 * @date 2025-01-02
 *
 * @brief
 * @details
 *
 *
 */
#include <enemysManager.hpp>
#include <enemyBase.hpp>
#include <coordinatesTools.hpp>
#include "field.hpp"
#include "segment.hpp"
enemysManager::enemysManager()
:bManager_(bulletsManager::getInstance())
{}

enemysManager& enemysManager::getInstance()
{
	static enemysManager instance;
	return instance;
}
void enemysManager::add(const entitiesInitialData::enemys typeOfEnemy, const coordinates& startPoint)
{
	using namespace entitiesInitialData;
	if(enemyBase::currentNumber_ != max_number::enemys)
	{

		for(std::unique_ptr<enemyBase>& e : enemys_)
		{
			if (!e)
			{
				std::unique_ptr<enemyBase> newInstance;
				switch (typeOfEnemy)
				{

					case enemys::enemy1:
					{
						newInstance = std::make_unique<enemyBase>(typeOfEnemy,
											startPoint,
											enemy1::life_points,
											enemy1::score_points,
											enemy1::texture_data,
											enemy1::texture_corner_1,
											enemy1::texture_corner_2,
											enemy1::slownest,
											coordinates({0,1}));
					}break;
					case enemys::enemy2:
					{
						newInstance = std::make_unique<enemyBase>(typeOfEnemy,
											startPoint,
											enemy2::life_points,
											enemy2::score_points,
											enemy2::texture_data,
											enemy2::texture_corner_1,
											enemy2::texture_corner_2,
											enemy2::slownest,
											coordinates({0,1}));
					}break;
					case enemys::enemy3:
					{
						newInstance = std::make_unique<enemyBase>(typeOfEnemy,
											startPoint,
											enemy3::life_points,
											enemy3::score_points,
											enemy3::texture_data,
											enemy3::texture_corner_1,
											enemy3::texture_corner_2,
											enemy3::slownest,
											coordinates({0,1}));
					}break;
				}
				e = std::move(newInstance);
				break;
			}
		}
	}

}
void enemysManager::move()
{
	for(std::unique_ptr<enemyBase>& e : enemys_)
	{
		if(e != nullptr)
		{
			if(coordinatesTools::isInVmap(e->getCurrentPosition()))
			{
				e->move();
			}
		}
	}
}
void enemysManager::remove()
{
	for(std::unique_ptr<enemyBase>& e : enemys_)
	{
		if(e != nullptr)
		{
			if(e->isToRemove())
			{
				e.reset();
				--e->currentNumber_;
			}
		}

	}
}
void enemysManager::chackCollisions()
{
	for(std::unique_ptr<enemyBase>& e : enemys_)
	{
		if(e)
		{
			if(coordinatesTools::isInDownMargin(e->getCurrentPosition()))
			{
				e->setToRemove();
			}
			else
			{
				for(std::unique_ptr<bulletBase>& b : bManager_)
				{
					if(b)
					{
						coordinates t = b->getCurrentPosition() - e->getCurrentPosition();
						if((t.x >= e->getTextureCorner1().x and t.x < e->getTextureCorner2().x) and
						   (t.y >= e->getTextureCorner1().y and t.y < e->getTextureCorner2().y))
						{
							field f = e->getTexture().at(t.x);
							std::uint8_t shiftBitCounter = 0;
							constexpr std::uint8_t msbMask = 0x80;
							if(f != 0)
							{
								while(!((f & msbMask) == msbMask))
								{
									f = f<<1;
									++shiftBitCounter;
								}
								coordinates offset({t.x, static_cast<std::int16_t>(field_size - 1 - shiftBitCounter)});
								if ((b->getCurrentPosition().x) == (e->getCurrentPosition() + offset).x and
									(b->getCurrentPosition().y) <= (e->getCurrentPosition() + offset).y)
								{
									e->takeDamage(b->getDemage());
									b->setToRemove();
								}
							}
						}
					}
				}
			}
		}
	}
}

std::array<std::unique_ptr<enemyBase>, entitiesInitialData::max_number::enemys>::pointer enemysManager::begin()
{
	return enemys_.begin();
}
std::array<std::unique_ptr<enemyBase>, entitiesInitialData::max_number::enemys>::pointer enemysManager::end()
{
	return enemys_.end();
}
std::array<std::unique_ptr<enemyBase>, entitiesInitialData::max_number::enemys>::const_pointer enemysManager::begin() const
{
	return enemys_.begin();
}
std::array<std::unique_ptr<enemyBase>, entitiesInitialData::max_number::enemys>::const_pointer enemysManager::end() const
{
	return enemys_.end();
}

