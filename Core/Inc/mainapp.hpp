/**
 * @file mainapp.hpp
 * @author Bartłomiej Głodek
 * @date 2024-12-22
 *
 * @copyright
 * Copyright (c) Bartłomiej Głodek 2025
 * Permission is granted to use, copy, modify, and distribute this software for any non-commercial purpose, free of charge.
 * For commercial use, you must notify the author and obtain permission before using this software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES, OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT, OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * @brief FreeRTOS application entry point.
 * @details This header declares the main application tasks and run scheduler.
 */

#ifndef INC_MAINAPP_HPP_
#define INC_MAINAPP_HPP_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @fn void mainapp()
 * @brief The main application function for seting up tasks and scheduler.
 * @note Ensure that all necessary hardware and software components are initialized before calling this function.
 */
void mainapp();

#ifdef __cplusplus
}
#endif

#endif /* INC_MAINAPP_HPP_ */
