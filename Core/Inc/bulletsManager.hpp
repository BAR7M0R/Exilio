/**
 * @file bulletsManager.hpp
 * @author Bartłomiej Głodek
 * @date 2025-01-10
 *
 * @copyright
 * Copyright (c) Bartłomiej Głodek 2025
 * Permission is granted to use, copy, modify, and distribute this software for any non-commercial purpose, free of charge.
 * For commercial use, you must notify the author and obtain permission before using this software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES, OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT, OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * @brief Manages bullet instances, providing methods to add, move, and remove bullets in the game.
 */

#ifndef INC_BULLETSMANAGER_HPP_
#define INC_BULLETSMANAGER_HPP_

#include <cstdint>
#include <array>
#include <memory>
#include "coordinates.hpp"
#include "bulletBase.hpp"
#include "entitiesInitData.hpp"

/**
 * @class bulletsManager
 * @brief Singleton class that manages a collection of bullets in the game.
 * @details The bulletsManager class handles operations such as adding, moving, and removing bullets. It uses a fixed-size array
 * of unique pointers to manage bullet objects efficiently.
 */
class bulletsManager
{
private:
    /**
     * @brief Private constructor to enforce the singleton pattern.
     */
    bulletsManager();

    /**
     * @brief Deleted copy constructor to prevent copying of the singleton instance.
     */
    bulletsManager(const bulletsManager&) = delete;

    /**
     * @brief Deleted assignment operator to prevent assignment of the singleton instance.
     */
    bulletsManager& operator=(const bulletsManager&) = delete;

public:
    /**
     * @brief Retrieves the singleton instance of bulletsManager.
     * @return Reference to the singleton instance.
     */
    static bulletsManager& getInstance();

    /**
     * @brief Adds a new bullet to the manager.
     * @param typeOfBullet Type of bullet to add, defined in entitiesInitialData::bullets.
     * @param startPoint Starting coordinates of the bullet.
     */
    void add(const entitiesInitialData::bullets typeOfBullet, const coordinates& startPoint);

    /**
     * @brief Moves all bullets managed by the bulletsManager.
     * @details Updates the positions of all active bullets based on their movement logic.
     */
    void move();

    /**
     * @brief Removes bullets that are no longer active or have left the valid game area.
     */
    void remove();

    /**
     * @brief Provides an iterator to the beginning of the bullets collection.
     * @return Iterator to the first element.
     */
    std::array<std::unique_ptr<bulletBase>, entitiesInitialData::max_number::bullets>::iterator begin();

    /**
     * @brief Provides an iterator to the end of the bullets collection.
     * @return Iterator to the position after the last element.
     */
    std::array<std::unique_ptr<bulletBase>, entitiesInitialData::max_number::bullets>::iterator end();

    /**
     * @brief Provides a constant iterator to the beginning of the bullets collection.
     * @return Constant iterator to the first element.
     */
    std::array<std::unique_ptr<bulletBase>, entitiesInitialData::max_number::bullets>::const_iterator begin() const;

    /**
     * @brief Provides a constant iterator to the end of the bullets collection.
     * @return Constant iterator to the position after the last element.
     */
    std::array<std::unique_ptr<bulletBase>, entitiesInitialData::max_number::bullets>::const_iterator end() const;

    /**
     * @brief Tracks the current number of active bullets managed by bulletsManager.
     */
    static std::uint8_t currentNumberOfBullets_;

private:
    /**
     * @brief Fixed-size array storing unique pointers to bullet objects.
     * @details The size of the array is determined by entitiesInitialData::max_number::bullets.
     */
    std::array<std::unique_ptr<bulletBase>, entitiesInitialData::max_number::bullets> bullets_;
};

#endif /* INC_BULLETSMANAGER_HPP_ */
