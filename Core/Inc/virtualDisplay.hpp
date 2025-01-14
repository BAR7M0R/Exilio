/**
 * @file virtulaDisplay.hpp
 * @author Bartłomiej Głodek
 * @date 2024-12-27
 *
 * @copyright
 * Copyright (c) Bartłomiej Głodek 2025
 * Permission is granted to use, copy, modify, and distribute this software for any non-commercial purpose, free of charge.
 * For commercial use, you must notify the author and obtain permission before using this software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES, OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT, OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * @brief This file contain declaration of virtualDisplay class.
 * ## Included Header Files
 * - `segment.hpp`: Contains the definition of the segment class.
 * - `coordinates.hpp`: Contains the definition of the coordinates class.
 * - `displayConstans.hpp`: Contains constants for display settings.
 */

#ifndef INC_VIRTUALDISPLAY_HPP_
#define INC_VIRTUALDISPLAY_HPP_
#include <array>
#include <cstdint>

#include "field.hpp"
#include "segment.hpp"
#include "coordinates.hpp"
#include "displayConstans.hpp"


using namespace displayConstans;
/**
 * @class virtualDisplay
 *
 * @brief This is singleton class based on the [memory model](pdf/memory_model.pdf).
 * @details Defines a two-dimensional array virtual map using the @link field.hpp fields alias type.@endlink
 * @details Since this class is Singleton and based on concept lazy initialization, the instance is initialized only upon the first usage of 'getInstance'.
 * @details User methods:
 * 		- 'getInstance' - Create and retrieves the Singleton instance.
 * 		- 'getMap' - Provides access to the map pointer array for display purposes.
 * 		- 'put' - Sets data on the virtual map.
 *
 * @details More information on the virtualDisplay class can be found in the @ref virtualDisplay class.
 *
 */
class virtualDisplay
{
private:
	virtualDisplay();
	virtualDisplay(const virtualDisplay&) = delete;
	virtualDisplay& operator=(const virtualDisplay&) = delete;
public:

    /**
     * @fn static virtualDisplay& getInstance()
     * @brief Creates and retrieves the singleton instance.
     * @details This method ensures that only one instance of virtualDisplay exists.
     * @return A reference to the singleton instance of virtualDisplay.
     */
	static virtualDisplay& getInstance();

	/**
	 * @fn std::uint8_t** getMap()
	 * @brief Retrieves a pointer to the virtual map.
	 * @details The size of the array is fixed and it is equal 1024 bytes(1024 @link field.hpp fields @endlink).
	 * @return A double pointer to an array of `std::uint8_t` representing the virtual map.
	 */
	std::uint8_t ** getMap();

	/**
	 * @fn void put(coordinates&, coordinates&, const segment&)
	 * @param nextPosition - The next position of the texture.
	 * @param currentPosition - The current position of the texture
	 * @param texture - The texture used to mask the current position and set the next position.
	 * @brief Update the texture's position on virtual map
	 */
	void put(coordinates& nextPosition, coordinates& currentPosition, const segment& texture);

private:
	/**
	 * @fn std::uint8_t checkNumberOfFields(coordinates&)
	 * @param pointPosition
	 * @return
	 */
	std::uint8_t checkNumberOfFields(coordinates& pointPosition);
	/**
	 * @fn segment takeSnap(coordinates)
	 * @param pointPosition
	 * @return
	 */
	segment takeSnap(coordinates pointPosition);
	/**
	 * @fn void putSegment(segment&, coordinates)
	 * @param s
	 * @param coords
	 */
	void putSegment(segment& s, coordinates coords);
	std::array<std::array<field, v_width>, v_height> vMap_;
	std::uint8_t * map_[height_lcd*width_lcd];
};
#endif /* INC_VIRTUALDISPLAY_HPP_ */
