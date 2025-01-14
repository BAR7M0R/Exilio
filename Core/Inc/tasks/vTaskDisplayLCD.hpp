/**
 * @file vTaskDisplayLCD.hpp
 * @author Bartłomiej Głodek
 * @date 2024-12-24
 *
 * @copyright
 * Copyright (c) Bartłomiej Głodek 2025
 * Permission is granted to use, copy, modify, and distribute this software for any non-commercial purpose, free of charge.
 * For commercial use, you must notify the author and obtain permission before using this software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES, OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT, OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * @brief Header file of display task that manages the virtual map on the GLCD screen.
 *
 */

#ifndef INC_VTASKDISPLAYLCD_HPP_
#define INC_VTASKDISPLAYLCD_HPP_
/**
 * @brief task function to set virtual map on GLCD screan.
 * @fn void vTaskDisplayLCD(void*)
 * @param[in] pvParameters Unused. Pass 'NULL' when creating the task.
 * @see mainapp.cpp
 */
extern "C" void vTaskDisplayLCD(void *pvParameters);

#endif /* INC_VTASKDISPLAYLCD_HPP_ */
