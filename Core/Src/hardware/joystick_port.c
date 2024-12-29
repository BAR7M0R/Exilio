#include <joystick_port.h>


void joystick_port_init(void)
{
	//#warning Przyciski zainicjowane przez bilioteke HAL
}

uint8_t joystick_port_read(void)
{
	uint8_t key_state = 0;

	if (HAL_GPIO_ReadPin(JOY_DOWN_GPIO_Port, JOY_DOWN_Pin) == GPIO_PIN_RESET)
		key_state |= JOY_D;
	if (HAL_GPIO_ReadPin(JOY_UP_GPIO_Port, JOY_UP_Pin) == GPIO_PIN_RESET)
		key_state |= JOY_U;
	if (HAL_GPIO_ReadPin(JOY_LEFT_GPIO_Port, JOY_LEFT_Pin) == GPIO_PIN_RESET)
		key_state |= JOY_L;
	if (HAL_GPIO_ReadPin(JOY_RIGHT_GPIO_Port, JOY_RIGHT_Pin) == GPIO_PIN_RESET)
		key_state |= JOY_R;
	if (HAL_GPIO_ReadPin(JOY_OK_GPIO_Port, JOY_OK_Pin) == GPIO_PIN_RESET)
		key_state |= JOY_OK;

	return key_state;
}
