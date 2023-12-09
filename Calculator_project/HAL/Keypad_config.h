/*
 * Keypad_config.h
 *
 *  Created on: 3 Nov 2023
 *      Author: Ibrahem Ashour
 */

#ifndef HAL_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_CONFIG_H_

/*		KEYPAD PINS			*/

#define KPD_C1_PORT  DIO_u8PORTD
#define KPD_C1_PIN	 DIO_u8PIN0

#define KPD_C2_PORT  DIO_u8PORTD
#define KPD_C2_PIN   DIO_u8PIN1

#define KPD_C3_PORT  DIO_u8PORTD
#define KPD_C3_PIN   DIO_u8PIN2

#define KPD_C4_PORT  DIO_u8PORTD
#define KPD_C4_PIN   DIO_u8PIN3

#define KPD_R1_PORT  DIO_u8PORTC
#define KPD_R1_PIN   DIO_u8PIN0

#define KPD_R2_PORT  DIO_u8PORTC
#define KPD_R2_PIN   DIO_u8PIN1

#define KPD_R3_PORT  DIO_u8PORTC
#define KPD_R3_PIN   DIO_u8PIN2

#define KPD_R4_PORT  DIO_u8PORTC
#define KPD_R4_PIN   DIO_u8PIN3

#define KPD_Arr_Val {\
		{'7', '8', '9', '/'},\
		{'4', '5', '6', '*'},\
		{'1', '2', '3', '-'},\
		{'c', '0', '=', '+'},\
}

#endif /* HAL_KEYPAD_CONFIG_H_ */
