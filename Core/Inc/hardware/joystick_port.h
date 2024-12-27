#ifndef JOYSICK_PORT_H
#define JOYSICK_PORT_H

#include <stdint.h>
#include "main.h"

#define JOY_D  0b00000001
#define JOY_U  0b00000010
#define JOY_L  0b00000100
#define JOY_R  0b00001000
#define JOY_OK 0b00010000

#define KEYS_PRESSED	1
#define KEY_PRESSED	    1
#define KEYS_RELEASED	0

void joystick_port_init(void);
uint8_t joystick_port_read(void);

#endif//JOYSICK_PORT_H
