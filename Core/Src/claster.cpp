/**
 * @file claster.cpp
 * @author Bartłomiej Głodek
 * @date 2024-12-31
 *
 * @brief
 * @details
 *
 *
 */
#include "claster.hpp"

#include <functional>
#include <bitset>


claster::claster()
:_claster{nullptr}
{}

claster::claster(segment& s1, segment& s2, segment& s3, segment& s4)
: _claster{&s1, &s2, &s3, &s4}
{}
void claster::putSegmentOnClaster(coordinates relativeCoords, segment s)
{
	if(0>relativeCoords.x and 7<relativeCoords.x)
	{
		while(true);
	}
	if(0>relativeCoords.y and 7<relativeCoords.y)
	{
		while(true);
	}
	const uint8_t xOffset = relativeCoords.x;
	const uint8_t firstEndIndex = xOffset + s.size();
	const uint8_t secondBeginIndex = firstEndIndex + s.size();
	const uint8_t secondEndIndex = secondBeginIndex + s.size();
	const uint8_t yOffset = relativeCoords.y;
	//const uint8_t firstOffset = relativeCoords.y;
	//const uint8_t secondOffset = FIELD_SIZE - relativeCoords.y;
	uint8_t currentFieldIndex = 0;
	int8_t sCounter = 0;
	while(currentFieldIndex < secondEndIndex)
	{
		std::bitset<8> tempBlackmask(~s[sCounter]);

		if ((currentFieldIndex >=xOffset) and (currentFieldIndex < firstEndIndex))
		{
			tempBlackmask.flip();
			tempBlackmask <<= yOffset;
			//tempBlackmask.flip();
			_claster[currentFieldIndex/8]->operator []((currentFieldIndex) % 8) |= static_cast<uint8_t>(tempBlackmask.to_ulong());
			++sCounter;
		}
		else if ((currentFieldIndex >=secondBeginIndex) and (currentFieldIndex <= secondEndIndex))
		{
			tempBlackmask.flip();
			tempBlackmask >>= (8 - yOffset);
			//tempBlackmask.flip();

			_claster[currentFieldIndex/8]->operator []((currentFieldIndex) % 8) |= static_cast<uint8_t>(tempBlackmask.to_ulong());
			++sCounter;
		}
		else
		{
			;//_claster[currentFieldIndex/8]->operator []((currentFieldIndex) % 16) = _claster[currentFieldIndex/8]->operator []((currentFieldIndex) % 16);
		}
		if (sCounter >= 8) sCounter =0;
		//if (currentFieldIndex == firstEndIndex) currentFieldIndex = secondBeginIndex;
		++currentFieldIndex;
	}
}
void claster::putBlackmaskSegmentOnClaster(coordinates relativeCoords, segment blackmask)
{
	if(0>relativeCoords.x and 7<relativeCoords.x)
	{
		while(true);
	}
	if(0>relativeCoords.y and 7<relativeCoords.y)
	{
		while(true);
	}
	const uint8_t xOffset = relativeCoords.x;
	const uint8_t firstEndIndex = xOffset + blackmask.size();
	const uint8_t secondBeginIndex = firstEndIndex + blackmask.size();
	const uint8_t secondEndIndex = secondBeginIndex + blackmask.size();
	const uint8_t yOffset = relativeCoords.y;
	//const uint8_t firstOffset = relativeCoords.y;
	//const uint8_t secondOffset = FIELD_SIZE - relativeCoords.y;
	uint8_t currentFieldIndex = 0;
	int8_t sCounter = 0;
	while(currentFieldIndex < secondEndIndex)
	{
		std::bitset<8> tempBlackmask(~blackmask[sCounter]);

		if ((currentFieldIndex >=xOffset) and (currentFieldIndex < firstEndIndex))
		{
			tempBlackmask <<= yOffset;
			std::bitset<8> tempField(_claster[currentFieldIndex/8]->operator []((currentFieldIndex) % 8));
			tempField |= tempBlackmask;
			tempField ^= tempBlackmask;
			_claster[currentFieldIndex/8]->operator []((currentFieldIndex) % 8) &= static_cast<uint8_t>(tempField.to_ulong());
			++sCounter;
		}
		else if ((currentFieldIndex >=secondBeginIndex) and (currentFieldIndex <= secondEndIndex))
		{
			tempBlackmask >>= (8 - yOffset);
			std::bitset<8> tempField(_claster[currentFieldIndex/8]->operator []((currentFieldIndex) % 8));
			tempField |= tempBlackmask;
			tempField ^= tempBlackmask;
			_claster[currentFieldIndex/8]->operator []((currentFieldIndex) % 8) &= static_cast<uint8_t>(tempField.to_ulong());
			++sCounter;
		}
		else
		{
			;//_claster[currentFieldIndex/8]->operator []((currentFieldIndex) % 16) = _claster[currentFieldIndex/8]->operator []((currentFieldIndex) % 16);
		}
		if (sCounter >= 8) sCounter =0;
		//if (currentFieldIndex == firstEndIndex) currentFieldIndex = secondBeginIndex;
		++currentFieldIndex;
	}

}
