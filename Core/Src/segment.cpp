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
/**
 * @fn  segment()
 */
segment::segment()
	:segment_({0}){}
/**
 * @fn  segment(std::initializer_list<field>)
 * @param init
 */
segment::segment(std::initializer_list<field> init)
{
    std::copy(init.begin(), init.end(), segment_.begin());
}

/**
 * @fn  segment(std::array<field,segment_size>)
 * @param data
 */
segment::segment(std::array<field,segment_size> data)
	:segment_(data){}

/**
 * @fn field operator []&(uint32_t)
 * @param index
 * @return
 */
field& segment::operator[](uint32_t index)
{
    return this->segment_[index];
}

/**
 * @fn segment operator =&(const segment&)
 * @param other
 * @return
 */
segment& segment::operator=(const segment& other)
{
	if (this != &other) // Sprawdzenie, czy nie przypisujemy do samego siebie
	{
		segment_ = other.segment_;
	}
	return *this;
}

/**
 * @fn segment operator =&(const std::array<field,segment_size>&)
 * @param arr
 * @return
 */
segment& segment::operator=(const std::array<field, segment_size>& arr)
{
	segment_ = arr;
	return *this;
}

/**
 * @fn  operator std::array<unsigned char,unsigned int8>()const
 */
segment::operator std::array<field, segment_size>() const
{
	return segment_;
}

/**
 * @fn segment operator |=&(const segment&)
 * @param second
 * @return
 */
segment& segment::operator|=(const segment& second)
{
	for (uint32_t i = 0; i < segment_.size(); ++i)
	{
		segment_.at(i) |= second.segment_.at(i);
	}
	return *this;
}

/**
 * @fn segment operator &=&(const segment&)
 * @param second
 * @return
 */
segment& segment::operator&=(const segment& second)
{
	for (uint32_t i = 0; i < segment_.size(); ++i)
	{
		segment_.at(i) &= second.segment_.at(i);
	}
	return *this;
}

/**
 * @fn segment operator ^=&(const segment&)
 * @param second
 * @return
 */
segment& segment::operator^=(const segment& second)
{
	for (uint32_t i = 0; i < segment_.size(); ++i)
	{
		segment_.at(i) ^= second.segment_.at(i);
	}
	return *this;
}

/**
 * @fn segment operator |(const segment&)const
 * @param second
 * @return
 */
segment segment::operator|(const segment& second) const
{
	segment result = *this;
	result |= second;
	return result;
}

/**
 * @fn segment operator &(const segment&)const
 * @param second
 * @return
 */
segment segment::operator&(const segment& second) const
{
	segment result = *this;
	result &= second;
	return result;
}

/**
 * @fn segment operator ^(const segment&)const
 * @param second
 * @return
 */
segment segment::operator^(const segment& second) const
{
	segment result = *this;
	result ^= second;
	return result;
}

/**
 * @fn segment operator ~()const
 * @return
 */
segment segment::operator~() const
{
	segment result;
	for (uint32_t i = 0; i < segment_.size(); ++i)
	{
		result.segment_.at(i) = ~segment_.at(i);
	}
	return result;
}

/**
 * @fn field at&(uint32_t)
 * @param index
 * @return
 */
field& segment::at(uint32_t index) {
    return segment_.at(index);
}

/**
 * @fn const field at&(uint32_t)const
 * @param index
 * @return
 */
const field& segment::at(uint32_t index) const {
    return segment_.at(index);
}

/**
 * @fn const field size()const
 * @return
 */
const field segment::size() const
{
	return segment_.size();
}

/**
 * @fn std::array<field,segment_size>::pointer begin()
 * @return
 */
std::array<field, segment_size>::pointer segment::begin() {
    return segment_.begin();
}

/**
 * @fn std::array<field,segment_size>::pointer end()
 * @return
 */
std::array<field, segment_size>::pointer segment::end() {
    return segment_.end();
}

/**
 * @fn std::array<field,segment_size>::const_pointer begin()const
 * @return
 */
std::array<field, segment_size>::const_pointer segment::begin() const {
    return segment_.begin();
}

/**
 * @fn std::array<field,segment_size>::const_pointer end()const
 * @return
 */
std::array<field, segment_size>::const_pointer segment::end() const {
    return segment_.end();
}
