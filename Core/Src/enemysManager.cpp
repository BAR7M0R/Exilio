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
#include <coordinatesTools.hpp>
enemysManager::enemysManager()
{}
enemysManager::enemysManager(const enemysManager&) = delete;
enemysManager& enemysManager::operator=(const enemysManager&) = delete;

static enemysManager& enemysManager::GetInstance()
{
	static enemysManager instance;
	return instance;
}
void enemysManager::addEnemy(const enemys typeOfEnemy, const coordinates& startPoint)
{
	if(enemyBase::currentNumberOfEnemys_ != max_enemy_number)
	{
		std::unique_ptr<enemyBase> newInstance;
		switch (typeOfEnemy)
		{

			case enemys::e1:
			{
				newInstance = std::make_unique<enemyBase>(typeOfEnemy,
			startPoint,
			enemy1::life_points,
			enemy1::score_points,
			enemy1::texture_data,
			enemy1::texture_corner_1,
			enemy1::texture_corner_2,
			coordinates({0,1}));
			}break;
			case enemys::e2:
			{
				newInstance = std::make_unique<enemyBase>(typeOfEnemy,
			startPoint,
			enemy2::life_points,
			enemy2::score_points,
			enemy2::texture_data,
			enemy2::texture_corner_1,
			enemy2::texture_corner_2,
			coordinates({0,1}));
			}break;
			case enemys::e3:
			{
				newInstance = std::make_unique<enemyBase>(typeOfEnemy,
			startPoint,
			enemy3::life_points,
			enemy3::score_points,
			enemy3::texture_data,
			enemy3::texture_corner_1,
			enemy3::texture_corner_2,
			coordinates({0,1}));
			}break;
		}
		for(auto& enemy : enemys_)
		{
			if (enemy == nullptr)
			{
				enemy = std::move(newInstance);
				enemyBase::currentNumberOfEnemys_++;
				break;
			}
		}
	}

}
void enemysManager::moveEnemys()
{
	for(enemyBase& enemy : enemys_)
	{
		if (enemy != nullptr)
		{
			if (coordinatesTools::isInVmap(e.getCurrentCoords()))
			{
				enemy.move();
			}
		}
	}
}
void enemysManager::killEntitys(bulletsManager bullets)
{
	for (enemyBase& e : enemys_)
	{
		if (e != nullptr)
		{
			for (bulletBase& b : bullets)
			{
				//if
			}
		}
	}
}
void enemysManager::removeEnemys()
{
	for(enemyBase& e : enemys_)
	{
		if (coordinatesTools::isInDownMargin(e.getCurrentCoords()))
		{
			e.remove();
		}
	}
}
auto enemysManager::begin()
{
	return enemys_.begin();
}
auto enemysManager::end()
{
	return enemys_.end();
}
auto enemysManager::begin() const
{
	return enemys_.begin();
}
auto enemysManager::end() const
{
	return enemys_.end();
}
