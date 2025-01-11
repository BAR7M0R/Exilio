/**
 * @file bulletsManager.hpp
 * @author Bartłomiej Głodek
 * @date 2025-01-10
 *
 * @brief
 * @details
 *
 *
 */
#ifndef INC_BULLETSMANAGER_HPP_
#define INC_BULLETSMANAGER_HPP_

#include <cstdint>
#include <array>
#include <memory>
#include "coordinates.hpp"
#include "bulletBase.hpp"
#include "entitiesInitData.hpp"
class bulletsManager
{
private:
	bulletsManager();
	bulletsManager(const bulletsManager&) = delete;
	bulletsManager operator=(const bulletsManager&) = delete;
public:
	static bulletsManager& getInstance();
	void add(const entitiesInitialData::bullets typeOfBullet, const coordinates& startPoint);
	void move();
	void remove();
	std::array<std::unique_ptr<bulletBase>, entitiesInitialData::max_number::bullets>::iterator begin();
	std::array<std::unique_ptr<bulletBase>, entitiesInitialData::max_number::bullets>::iterator end();
	std::array<std::unique_ptr<bulletBase>, entitiesInitialData::max_number::bullets>::const_iterator begin() const;
	std::array<std::unique_ptr<bulletBase>, entitiesInitialData::max_number::bullets>::const_iterator end() const;

	static std::uint8_t currentNumberOfBullets_;
private:
	std::array<std::unique_ptr<bulletBase>, entitiesInitialData::max_number::bullets> bullets_;
};
#endif /* INC_BULLETSMANAGER_HPP_ */
