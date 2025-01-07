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
	:_segment({0}){}
segment::segment(std::initializer_list<uint8_t> init)
{
    std::copy(init.begin(), init.end(), _segment.begin());
}
segment::segment(std::array<uint8_t,8> data)
	:_segment(data){}
FIELD& segment::operator[](uint32_t index)
{
    return this->_segment[index];
}
segment& segment::operator=(const segment& other)
{
	if (this != &other) // Sprawdzenie, czy nie przypisujemy do samego siebie
	{
		_segment = other._segment;
	}
	return *this;
}
segment& segment::operator=(const std::array<uint8_t, 8>& arr)
{
	_segment = arr;
	return *this;
}
segment::operator std::array<uint8_t, 8>() const
{
	return _segment;
}
segment& segment::operator|=(const segment& second)
{
	for (uint32_t i = 0; i < _segment.size(); ++i)
	{
		_segment.at(i) |= second._segment.at(i);
	}
	return *this;
}
segment& segment::operator&=(const segment& second)
{
	for (uint32_t i = 0; i < _segment.size(); ++i)
	{
		_segment.at(i) &= second._segment.at(i);
	}
	return *this;
}
segment& segment::operator^=(const segment& second)
{
	for (uint32_t i = 0; i < _segment.size(); ++i)
	{
		_segment.at(i) ^= second._segment.at(i);
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
	for (uint32_t i = 0; i < _segment.size(); ++i)
	{
		result._segment.at(i) = ~_segment.at(i);
	}
	return result;
}
FIELD& segment::at(uint32_t index) {
    return _segment.at(index);
}
const FIELD& segment::at(uint32_t index) const {
    return _segment.at(index);
}
const uint8_t segment::size() const
{
	return _segment.size();
}
