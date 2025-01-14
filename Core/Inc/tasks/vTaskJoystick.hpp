/**
 * @file vTaskJoystick.hpp
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
 * @brief
 * @details
 * @todo opis
 *
 */

#ifndef SRC_VTASKJOYSTICK_HPP_
#define SRC_VTASKJOYSTICK_HPP_
/**
 * @brief independent task function to handle joystick
 * @fn void vTaskJoystick(void*)
 * @param[in] pvParameters Unused. Pass 'NULL' when creating the task.
 *
 */
extern "C" void vTaskJoystick(void *pvParameters);

#endif /* SRC_VTASKJOYSTICK_HPP_ */
