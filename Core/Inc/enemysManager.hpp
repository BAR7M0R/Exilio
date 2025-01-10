/**
 * @file enemy.hpp
 * @author Bartłomiej Głodek
 * @date 2025-01-05
 *
 * @brief
 * @details
 * @todo spleat filet into two files first .hpp and second .cpp
 *
 */

#ifndef INC_ENEMY_HPP_
#define INC_ENEMY_HPP_

#include <memory>
#include <cstdint>
#include "enemyBase.hpp"
#include "coordinates.hpp"
#include "entitiesInitData.hpp"


/**
 * @class enemysManager
 */
using namespace EntitiesInitialData;

class enemysManager {
private:
	enemysManager();
	enemysManager(const enemysManager&) = delete;
	enemysManager& operator=(const enemysManager&) = delete;

public:
	static enemysManager& getInstance();
	void addEnemy(const enemys typeOfEnemy, const coordinates& startPoint);
	void moveEnemys();
	void killEntitys(bulletsManager bullets);
	void removeEnemys();
    auto begin();
    auto end();
    auto begin() const;
    auto end() const;
private:
	std::array<std::unique_ptr<enemyBase>, max_enemy_number> enemys_;
};

#endif /* INC_ENEMY_HPP_ */
