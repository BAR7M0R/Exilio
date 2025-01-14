/**
 * @file entitiesInitData.hpp
 * @author Bartłomiej Głodek
 * @date 2025-01-02
 *
 * @copyright
 * Copyright (c) Bartłomiej Głodek 2025
 * Permission is granted to use, copy, modify, and distribute this software for any non-commercial purpose, free of charge.
 * For commercial use, you must notify the author and obtain permission before using this software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES, OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT, OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * @brief This file contains initialization data and constants for various entities (enemies, player, bullets).
 * @details The file defines the maximum number of entities that can exist, their textures, positions, and attributes.
 * It also specifies various constants used in the game logic.
 *
 */
#ifndef INC_ENTITIESINITDATA_HPP_
#define INC_ENTITIESINITDATA_HPP_
#include <cstdint>

#include "coordinates.hpp"
#include "segment.hpp"

/**
 * @namespace entitiesInitialData
 * @brief This namespace contains the initial data for all game entities like enemies, bullets, and the player.
 */
namespace entitiesInitialData
{

	/**
	 * @namespace max_number
	 * @brief Contains constants defining the maximum number of entities like enemies and bullets.
	 */
	namespace max_number
	{
		static constexpr inline std::uint8_t enemys = 8; ///< Maximum number of enemies
		static constexpr inline std::uint8_t bullets = 15; ///< Maximum number of bullets
	};

	/**
	 * @enum enemys
	 * @brief Enumeration for different types of enemies in the game.
	 */
	enum class enemys
	{
		enemy1, ///< Enemy 1
		enemy2, ///< Enemy 2
		enemy3 ///< Enemy 3
	};

	/**
	 * @enum bullets
	 * @brief Enumeration for different types of bullets in the game.
	 */
	enum class bullets
	{
		bullet1 ///< Bullet 1
	};

	/**
	 * @struct enemiGen
	 * @brief Structure to represent enemy generation data, including type, position, and number.
	 */
	struct enemiGen
	{
		enemys type; ///< Enemy type
		coordinates position; ///< Enemy position
		std::size_t number; ///< Enemy number
		bool isGenerated; ///< Flag indicating whether the enemy is generated
	};

	/**
	 * @namespace player1
	 * @brief Contains data specific to player 1, including texture and position information.
	 */
	namespace player1 {
		static const segment texture_data({0x04,
				0x03, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00 }); ///< Player texture data
		static constexpr inline coordinates offset { 1, 0 }; ///< Texture offset
		static constexpr inline coordinates texture_corner_1{0,0}; ///< Texture corner 1
		static constexpr inline coordinates texture_corner_2{3,3}; ///< Texture corner 2
	};

	/**
	 * @namespace enemy1
	 * @brief Contains data specific to enemy 1, including texture, position, and attributes.
	 */
	namespace enemy1 {
		static const segment texture_data({0x07,
				0x02, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00 }); ///< Enemy 1 texture data
		static constexpr inline coordinates offset { 1, 1 }; ///< Texture offset
		static constexpr inline coordinates texture_corner_1{0,0}; ///< Texture corner 1
		static constexpr inline coordinates texture_corner_2{3,3}; ///< Texture corner 2
		static constexpr inline std::uint8_t life_points = 1; ///< Enemy 1 life points
		static constexpr inline std::uint8_t score_points = 1; ///< Enemy 1 score points
		static constexpr inline std::size_t max_number_at_time = 16; ///< Maximum number of enemy 1 at a time
		static constexpr inline std::uint8_t slownest = 0; ///< Enemy 1 speed
	};

	/**
	 * @namespace enemy2
	 * @brief Contains data specific to enemy 2, including texture, position, and attributes.
	 */
	namespace enemy2 {
		static const segment texture_data({0x0B,
				0x0E, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00 }); ///< Enemy 2 texture data
		static constexpr inline coordinates offset { 1, 3 }; ///< Texture offset
		static constexpr inline coordinates texture_corner_1{0,0}; ///< Texture corner 1
		static constexpr inline coordinates texture_corner_2{3,4}; ///< Texture corner 2
		static constexpr inline std::uint8_t life_points = 2; ///< Enemy 2 life points
		static constexpr inline std::uint8_t score_points = 2; ///< Enemy 2 score points
		static constexpr inline std::size_t max_number_at_time = 4; ///< Maximum number of enemy 2 at a time
		static constexpr inline std::uint8_t slownest = 2; ///< Enemy 2 speed
	};

	/**
	 * @namespace enemy3
	 * @brief Contains data specific to enemy 3, including texture, position, and attributes.
	 */
	namespace enemy3 {
		static const segment texture_data({0x0E,
				0x1C, 0x7F, 0x7E, 0x7F, 0x1C, 0x0E, 0x00 }); ///< Enemy 3 texture data
		static constexpr inline coordinates offset { 3, 3 }; ///< Texture offset
		static constexpr inline coordinates texture_corner_1{0,0}; ///< Texture corner 1
		static constexpr inline coordinates texture_corner_2{7,7}; ///< Texture corner 2
		static constexpr inline std::uint8_t life_points = 6; ///< Enemy 3 life points
		static constexpr inline std::uint8_t score_points = 4; ///< Enemy 3 score points
		static constexpr inline std::size_t max_number_at_time = 1; ///< Maximum number of enemy 3 at a time
		static constexpr inline std::uint8_t slownest = 6; ///< Enemy 3 speed
	};

	/**
	 * @namespace bullet1
	 * @brief Contains data specific to bullet 1, including texture, position, and attributes.
	 */
	namespace bullet1 {
		static const segment texture_data({0x01,
				0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}); ///< Bullet 1 texture data
		static constexpr inline coordinates offset { 0, 0 }; ///< Texture offset
		static constexpr inline coordinates texture_corner_1{0,0}; ///< Texture corner 1
		static constexpr inline coordinates texture_corner_2{3,3}; ///< Texture corner 2
		static constexpr inline std::uint8_t demage_points = 1; ///< Bullet 1 damage points
	};

};

#endif /* INC_ENTITIESINITDATA_HPP_ */
