/**
 * @file player.hpp
 * @author Bartłomiej Głodek
 * @date 2025-01-05
 *
 * @copyright
 * Copyright (c) Bartłomiej Głodek 2025
 * Permission is granted to use, copy, modify, and distribute this software for any non-commercial purpose, free of charge.
 * For commercial use, you must notify the author and obtain permission before using this software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES, OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT, OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * @brief Defines the `player` class, which represents the player in the game.
 * @details Implements the Singleton pattern to ensure a single instance of the player.
 *          Manages player state including position, previous position, texture data, and movement.
 */

#ifndef INC_PLAYER_HPP_
#define INC_PLAYER_HPP_

#include "coordinates.hpp"
#include "segment.hpp"

/**
 * @class player
 * @brief Represents the player in the game.
 * @details This class is a Singleton that manages the player's state, including its position and visual representation.
 *          It provides methods to move the player and retrieve its attributes.
 */
class player
{
private:
    /**
     * @brief Default constructor (private for Singleton).
     */
    player();

    /**
     * @brief Deleted copy constructor to prevent duplication.
     */
    player(const player&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent duplication.
     */
    player& operator=(const player&) = delete;

public:
    /**
     * @brief Retrieves the Singleton instance of the player.
     * @return A reference to the `player` instance.
     */
    static player& getInstance();

    /**
     * @brief Moves the player to a new position based on the provided direction.
     * @param direction A `coordinates` object indicating the direction of movement.
     */
    void move(coordinates direction);

    /**
     * @brief Retrieves the current position of the player.
     * @return A reference to the `coordinates` object representing the current position.
     */
    coordinates& getCurrentPosition();

    /**
     * @brief Retrieves the previous position of the player.
     * @return A reference to the `coordinates` object representing the previous position.
     */
    coordinates& getPreviousPosition();

    /**
     * @brief Retrieves the player's texture data.
     * @return A constant reference to the `segment` object representing the player's texture.
     */
    const segment& getTexture() const;

    /**
     * @brief Retrieves the first corner of the player's texture.
     * @return A constant reference to the `coordinates` object representing the first corner.
     */
    const coordinates& getTextureCorner1() const;

    /**
     * @brief Retrieves the second corner of the player's texture.
     * @return A constant reference to the `coordinates` object representing the second corner.
     */
    const coordinates& getTextureCorner2() const;

    /**
     * @brief Retrieves the offset used for positioning the texture.
     * @return A constant reference to the `coordinates` object representing the offset.
     */
    const coordinates& getOffset() const;

private:
    const segment texture_; ///< The texture representing the player's appearance.
    const coordinates texture_corner_1_; ///< The first corner of the player's texture.
    const coordinates texture_corner_2_; ///< The second corner of the player's texture.
    const coordinates offset_; ///< The offset used for positioning the texture.
    coordinates currentPosition_; ///< The current position of the player.
    coordinates previousPosition_; ///< The previous position of the player.
};

#endif /* INC_PLAYER_HPP_ */
