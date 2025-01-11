/**
 * @file segment.cpp
 * @author Bartłomiej Głodek
 * @date 2024-12-30
 *
 * @brief
 * @details
 *
 *
 */

#include <segment.hpp>

segment::segment()
	:segment_({0}){}
segment::segment(std::initializer_list<field> init)
{
    std::copy(init.begin(), init.end(), segment_.begin());
}
segment::segment(std::array<field,segment_size> data)
	:segment_(data){}
field& segment::operator[](uint32_t index)
{
    return this->segment_[index];
}
segment& segment::operator=(const segment& other)
{
	if (this != &other) // Sprawdzenie, czy nie przypisujemy do samego siebie
	{
		segment_ = other.segment_;
	}
	return *this;
}
segment& segment::operator=(const std::array<field, segment_size>& arr)
{
	segment_ = arr;
	return *this;
}
segment::operator std::array<field, segment_size>() const
{
	return segment_;
}
segment& segment::operator|=(const segment& second)
{
	for (uint32_t i = 0; i < segment_.size(); ++i)
	{
		segment_.at(i) |= second.segment_.at(i);
	}
	return *this;
}
segment& segment::operator&=(const segment& second)
{
	for (uint32_t i = 0; i < segment_.size(); ++i)
	{
		segment_.at(i) &= second.segment_.at(i);
	}
	return *this;
}
segment& segment::operator^=(const segment& second)
{
	for (uint32_t i = 0; i < segment_.size(); ++i)
	{
		segment_.at(i) ^= second.segment_.at(i);
	}
	return *this;
}
segment segment::operator|(const segment& second) const
{
	segment result = *this;
	result |= second;
	return result;
}
segment segment::operator&(const segment& second) const
{
	segment result = *this;
	result &= second;
	return result;
}
segment segment::operator^(const segment& second) const
{
	segment result = *this;
	result ^= second;
	return result;
}
segment segment::operator~() const
{
	segment result;
	for (uint32_t i = 0; i < segment_.size(); ++i)
	{
		result.segment_.at(i) = ~segment_.at(i);
	}
	return result;
}
field& segment::at(uint32_t index) {
    return segment_.at(index);
}
const field& segment::at(uint32_t index) const {
    return segment_.at(index);
}
const uint8_t segment::size() const
{
	return segment_.size();
}

std::array<field, segment_size>::pointer segment::begin() {
    return segment_.begin();
}

std::array<field, segment_size>::pointer segment::end() {
    return segment_.end();
}

std::array<field, segment_size>::const_pointer segment::begin() const {
    return segment_.begin();
}

std::array<field, segment_size>::const_pointer segment::end() const {
    return segment_.end();
}
