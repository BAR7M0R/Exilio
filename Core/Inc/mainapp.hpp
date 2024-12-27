/*
 * mainapp.hpp
 *
 *  Created on: Dec 22, 2024
 *      Author: dev
 */

#ifndef SRC_MAINAPP_HPP_
#define SRC_MAINAPP_HPP_

#ifdef __cplusplus
extern "C" {
#endif

#include "queue.h"

void mainapp();

extern QueueHandle_t joystickDataQueue;

#ifdef __cplusplus
}
#endif
#endif /* SRC_MAINAPP_HPP_ */
