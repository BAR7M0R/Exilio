/**
 * @file enemy.hpp
 * @author Bartłomiej Głodek
 * @date 2025-01-05
 *
 * @brief
 * @details
 *
 */

#ifndef INC_ENEMY_HPP_
#define INC_ENEMY_HPP_

#include <memory>
#include <cstdint>
#include "enemyBase.hpp"
#include "coordinates.hpp"
#include "entitiesInitData.hpp"
#include "bulletsManager.hpp"

/**
 * @class enemysManager
 */
using namespace entitiesInitialData;

class enemysManager {
private:
	enemysManager();
	enemysManager(const enemysManager&) = delete;
	enemysManager& operator=(const enemysManager&) = delete;

public:
	static enemysManager& getInstance();
	void add(const entitiesInitialData::enemys typeOfEnemy, const coordinates& startPoint);
	void move();
	void remove();
	void chackCollisions();

	std::array<std::unique_ptr<enemyBase>, entitiesInitialData::max_number::enemys>::pointer begin();
    std::array<std::unique_ptr<enemyBase>, entitiesInitialData::max_number::enemys>::pointer end();
    std::array<std::unique_ptr<enemyBase>, entitiesInitialData::max_number::enemys>::const_pointer begin() const;
    std::array<std::unique_ptr<enemyBase>, entitiesInitialData::max_number::enemys>::const_pointer end() const;
private:
	std::array<std::unique_ptr<enemyBase>, entitiesInitialData::max_number::enemys> enemys_;
	bulletsManager& bManager_;
};

#endif /* INC_ENEMY_HPP_ */
