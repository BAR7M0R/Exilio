#ifndef DRIVERKEY_H
#define DRIVERKEY_H

#include <stdint.h>
#include "main.h"
//#include <stm32f1xx_hal_gpio.h>

#define JOY_D  0b00000001
#define JOY_U  0b00000010
#define JOY_L  0b00000100
#define JOY_R  0b00001000
#define JOY_OK 0b00010000
//#define SW3    0b00100000
//#define SW4    0b01000000

#define KEYS_PRESSED	1
#define KEY_PRESSED	    1
#define KEYS_RELEASED	0

void driverKEY_init(void);
uint8_t driverKEY_read(void);

#endif//DRIVERKEY_H
