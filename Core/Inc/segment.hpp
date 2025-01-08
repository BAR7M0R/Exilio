/**
 * @file segment.hpp
 * @author Bartłomiej Głodek
 * @date 2024-12-30
 *
 * @brief
 * @details
 *
 *
 */
#ifndef INC_SEGMENT_HPP_
#define INC_SEGMENT_HPP_
#include <field.hpp>
#include <array>
#include <cstdint>

class segment
{
public:
	segment();
    segment(std::initializer_list<FIELD> init);
	segment(std::array<FIELD,8> data);
    FIELD& operator[](uint32_t index);
	operator std::array<uint8_t, 8>() const;
    segment& operator=(std::initializer_list<uint8_t> init);
    segment& operator=(const segment& other);
    segment& operator=(const std::array<uint8_t, 8>& arr);
	segment& operator|=(const segment& second);
	segment& operator&=(const segment& second);
	segment& operator^=(const segment& second);
	segment operator|(const segment& second) const;
	segment operator&(const segment& second) const;
	segment operator^(const segment& second) const;
	segment operator~() const;
	FIELD& at(uint32_t index);
    const uint8_t& at(uint32_t index) const;
    const uint8_t size() const;
private:
	std::array<FIELD, 8> _segment;
};

#endif /* INC_SEGMENT_HPP_ */
