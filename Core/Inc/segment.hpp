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
/**
 * @class segment
 * @brief this class base on model presented inside basicDataRelation.pdf pleas read that document before use.
 */
static constexpr inline std::uint8_t segment_size = 8;
class segment
{
public:
	segment();
    segment(std::initializer_list<field> init);
	segment(std::array<field,segment_size> data);
    field& operator[](uint32_t index);
	operator std::array<uint8_t, segment_size>() const;
    segment& operator=(std::initializer_list<uint8_t> init);
    segment& operator=(const segment& other);
    segment& operator=(const std::array<uint8_t, field_size>& arr);
	segment& operator|=(const segment& second);
	segment& operator&=(const segment& second);
	segment& operator^=(const segment& second);
	segment operator|(const segment& second) const;
	segment operator&(const segment& second) const;
	segment operator^(const segment& second) const;
	segment operator~() const;
	field& at(uint32_t index);
    const uint8_t& at(uint32_t index) const;
    const uint8_t size() const;
	std::array<field, segment_size>::pointer begin();
    std::array<field, segment_size>::pointer end();
    std::array<field, segment_size>::const_pointer begin() const;
    std::array<field, segment_size>::const_pointer end() const;

private:
	std::array<field, field_size> segment_;
};

#endif /* INC_SEGMENT_HPP_ */
