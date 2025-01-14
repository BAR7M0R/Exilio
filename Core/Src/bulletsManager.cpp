/**
 * @file bulletsManager.cpp
 * @author Bartłomiej Głodek
 * @date 2025-01-10
 *
 * @brief
 * @details
 *
 *
 */
#include <bulletsManager.hpp>
#include <bulletBase.hpp>
#include "displayConstans.hpp"

bulletsManager::bulletsManager(){}
bulletsManager& bulletsManager::getInstance()
{
	static bulletsManager instance;
	return instance;
}
void bulletsManager::add(const entitiesInitialData::bullets typeOfBullet, const coordinates& startPoint)
	{
		if(bulletBase::currentNumber_ != entitiesInitialData::max_number::bullets)
		{
			for(std::unique_ptr<bulletBase>& b : bullets_)
			{
				if (!b->isOnMap())
				{
					std::unique_ptr<bulletBase> newInstance;
					switch (typeOfBullet)
					{
						using namespace entitiesInitialData;
						case bullets::bullet1:
						{
							newInstance = std::make_unique<bulletBase>(typeOfBullet,
								startPoint,
								bullet1::demage_points,
								bullet1::texture_data,
								bullet1::texture_corner_1,
								bullet1::texture_corner_2,
								coordinates({0,-1}));
						}break;

					}
					b = std::move(newInstance);
					break;
				}
			}
		}

	}
void bulletsManager::move()
{
	for(std::unique_ptr<bulletBase>& b : bullets_)
	{
		if(b != nullptr)
		{
			if(coordinatesTools::isInMap(b->getCurrentPosition()))
			{
				b->move();
			}
			else
			{
				b->setToRemove();
			}
		}
	}
}
void bulletsManager::remove()
{
	for(std::unique_ptr<bulletBase>& b : bullets_)
	{
		if(b != nullptr)
		{
			if(b->isToRemove())
			{
				--b->currentNumber_;
				b.reset();
			}
		}
	}
}
std::array<std::unique_ptr<bulletBase>, entitiesInitialData::max_number::bullets>::iterator bulletsManager::begin()
{ return bullets_.begin(); }
std::array<std::unique_ptr<bulletBase>, entitiesInitialData::max_number::bullets>::iterator bulletsManager::end()
{ return bullets_.end(); }
std::array<std::unique_ptr<bulletBase>, entitiesInitialData::max_number::bullets>::const_iterator bulletsManager::begin() const
{ return bullets_.begin(); }
std::array<std::unique_ptr<bulletBase>, entitiesInitialData::max_number::bullets>::const_iterator bulletsManager::end() const
{ return bullets_.end(); }
