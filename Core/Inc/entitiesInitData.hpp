/*
 * entitiesInitData.hpp
 *
 *  Created on: Jan 2, 2025
 *      Author: Bartłomiej Głodek
 */

#ifndef INC_ENTITIESINITDATA_HPP_
#define INC_ENTITIESINITDATA_HPP_
#include <cstdint>

#include "coordinates.hpp"
#include "segment.hpp"
namespace EntitiesInitialData {
struct player {
	static constexpr inline std::array<std::uint8_t, 8> texture_data = { 0x04,
			0x03, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00 };
	static constexpr inline coordinates offset { 1, 0 };
	static constexpr inline coordinates texture_corner_1{0,0};
	static constexpr inline coordinates texture_corner_2{3,3};
	static constexpr inline std::uint8_t score_points = 1;
	static constexpr inline std::size_t max_number_at_time = 1;
};
struct enemy1 {
	static constexpr inline std::array<std::uint8_t, 8> texture_data { 0x07,
			0x02, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00 };
	static constexpr inline coordinates offset { 1, 1 };
	static constexpr inline coordinates texture_corner_1{0,0};
	static constexpr inline coordinates texture_corner_2{3,3};
	static constexpr inline std::uint8_t life_points = 1;
	static constexpr inline std::uint8_t score_points = 1;
	static constexpr inline std::size_t max_number_at_time = 16;
};
struct enemy2 {
	static constexpr inline std::array<std::uint8_t, 8> texture_data { 0x0B,
			0x0E, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00 };
	static constexpr inline coordinates offset { 1, 3 };
	static constexpr inline coordinates texture_corner_1{0,0};
	static constexpr inline coordinates texture_corner_2{3,4};
	static constexpr inline std::uint8_t life_points = 2;
	static constexpr inline std::uint8_t score_points = 2;
	static constexpr inline std::size_t max_number_at_time = 4;
};
struct enemy3 {
	static constexpr inline std::array<std::uint8_t, 8> texture_data { 0x0E,
			0x1C, 0x7F, 0x7E, 0x7F, 0x1C, 0x0E, 0x00 };
	static constexpr inline coordinates offset { 3, 3 };
	static constexpr inline coordinates texture_corner_1{0,0};
	static constexpr inline coordinates texture_corner_2{7,7};
	static constexpr inline std::uint8_t life_points = 6;
	static constexpr inline std::uint8_t score_points = 4;
	static constexpr inline std::size_t max_number_at_time = 1;
};
struct bullet {
	static constexpr inline std::array<std::uint8_t, 8> texture_data = { 0x01,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
	static constexpr inline coordinates offset { 0, 0 };
	static constexpr inline coordinates texture_corner_1{0,0};
	static constexpr inline coordinates texture_corner_2{3,3};
	static constexpr inline std::uint8_t demage_points = 1;
	static constexpr inline std::size_t max_number_at_time = 1;
};

};

#endif /* INC_ENTITIESINITDATA_HPP_ */
