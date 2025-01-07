/**
 * @file displaytask.cpp
 * @author Bartłomiej Głodek
 * @date 2024-12-24
 *
 * @brief Header file of display task that manages the virtual map on the GLCD screen.
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
