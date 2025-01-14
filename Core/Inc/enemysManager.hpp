/**
 * @file enemy.hpp
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
 * @brief Header file defining the `enemysManager` class for managing enemy entities in the game.
 * @details This file declares the `enemysManager` class responsible for handling enemy entities, including adding, removing, and moving enemies, as well as checking for collisions.
 */

#ifndef INC_ENEMY_HPP_
#define INC_ENEMY_HPP_

#include <memory>
#include <cstdint>
#include "enemyBase.hpp"
#include "coordinates.hpp"
#include "entitiesInitData.hpp"
#include "bulletsManager.hpp"

using namespace entitiesInitialData;

/**
 * @class enemysManager
 * @brief A class to manage enemies in the game.
 * @details The `enemysManager` class is a singleton responsible for managing all the enemies in the game, such as adding new enemies, moving them, removing them, and checking for collisions with bullets.
 */
class enemysManager {
private:
	enemysManager();
	enemysManager(const enemysManager&) = delete;
	enemysManager& operator=(const enemysManager&) = delete;

public:
	/**
	 * @brief Retrieves the singleton instance of the `enemysManager`.
	 * @details This function returns the only instance of `enemysManager` (singleton pattern).
	 * @return A reference to the singleton instance of `enemysManager`.
	 */
	static enemysManager& getInstance();

	/**
	 * @brief Adds a new enemy to the game.
	 * @details This function adds a new enemy of the specified type at the given starting position.
	 * @param typeOfEnemy The type of enemy to add.
	 * @param startPoint The starting coordinates of the enemy.
	 */
	void add(const entitiesInitialData::enemys typeOfEnemy, const coordinates& startPoint);

	/**
	 * @brief Moves all the enemies in the game.
	 * @details This function updates the coordinates of all enemies in the game based on their movement direction.
	 */
	void move();

	/**
	 * @brief Removes an enemy from the game.
	 * @details This function removes an enemy from the game if flag toRemove is up; freeing any resources associated with it.
	 */
	void remove();

	/**
	 * @brief Checks for collisions between enemies and bullets.
	 * @details This function checks if any enemies have collided with bullets. If bullet collided with an enemy the flag to remove is set.
	 */
	void chackCollisions();

	/**
	 * @brief Returns an iterator to the beginning of the enemy array.
	 * @details This function returns an iterator to the beginning of the enemy array for iteration purposes.
	 * @return An iterator to the beginning of the enemy array.
	 */
	std::array<std::unique_ptr<enemyBase>, entitiesInitialData::max_number::enemys>::pointer begin();

	/**
	 * @brief Returns an iterator to the end of the enemy array.
	 * @details This function returns an iterator to the end of the enemy array for iteration purposes.
	 * @return An iterator to the end of the enemy array.
	 */
	std::array<std::unique_ptr<enemyBase>, entitiesInitialData::max_number::enemys>::pointer end();

	/**
	 * @brief Returns a const iterator to the beginning of the enemy array.
	 * @details This function returns a const iterator to the beginning of the enemy array, providing read-only access to the enemy data.
	 * @return A const iterator to the beginning of the enemy array.
	 */
	std::array<std::unique_ptr<enemyBase>, entitiesInitialData::max_number::enemys>::const_pointer begin() const;

	/**
	 * @brief Returns a const iterator to the end of the enemy array.
	 * @details This function returns a const iterator to the end of the enemy array, providing read-only access to the enemy data.
	 * @return A const iterator to the end of the enemy array.
	 */
	std::array<std::unique_ptr<enemyBase>, entitiesInitialData::max_number::enemys>::const_pointer end() const;

private:
	/**
	 * @brief Array storing all active enemies in the game.
	 * @details This array holds all active enemies managed by the `enemysManager`. It contains unique pointers to each enemy object.
	 */
	std::array<std::unique_ptr<enemyBase>, entitiesInitialData::max_number::enemys> enemys_;

	/**
	 * @brief Reference to the `bulletsManager` for managing bullets.
	 * @details This reference is used to interact with the `bulletsManager` class to check for bullet-enemy collisions.
	 */
	bulletsManager& bManager_;
};

#endif /* INC_ENEMY_HPP_ */
