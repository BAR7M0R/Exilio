/*
 * vTaskDisplayLCD.hpp
 *
 *  Created on: Dec 24, 2024
 *      Author: bartłomiej Głodek
 */

#ifndef SRC_VTASKDISPLAYLCD_HPP_
#define SRC_VTASKDISPLAYLCD_HPP_

#include <cstdint>


#ifdef __cplusplus
extern "C" {
#endif

extern void glcd_ClearScreen();
extern void glcd_PutFrame(uint8_t frame[128][64]);

void vTaskDisplayLCD(void *pvParameters);


#ifdef __cplusplus
}
#endif

#endif /* SRC_DISPLAYTASK_HPP_ */
