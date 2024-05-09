/*
 * Keypad_config.h
 *
 *  Created on: 3 Nov 2023
 *      Author: Alaraby
 */

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

/*		KEYPAD PINS			*/

#define KPD_C1_PORT  DIO_u8PORTA
#define KPD_C1_PIN	 DIO_u8PIN0

#define KPD_C2_PORT  DIO_u8PORTA
#define KPD_C2_PIN   DIO_u8PIN1

#define KPD_C3_PORT  DIO_u8PORTA
#define KPD_C3_PIN   DIO_u8PIN2

#define KPD_C4_PORT  DIO_u8PORTB
#define KPD_C4_PIN   DIO_u8PIN0

#define KPD_R1_PORT  DIO_u8PORTB
#define KPD_R1_PIN   DIO_u8PIN1

#define KPD_R2_PORT  DIO_u8PORTB
#define KPD_R2_PIN   DIO_u8PIN2

#define KPD_R3_PORT  DIO_u8PORTC
#define KPD_R3_PIN   DIO_u8PIN0

#define KPD_R4_PORT  DIO_u8PORTC
#define KPD_R4_PIN   DIO_u8PIN1

#define KPD_Arr_Val {{'7' , '8' , '9' , '%'},{'4' , '5' , '6' , '*'},{'3' , '2' , '1' , '-'},{'o' , '0' , '=' , '+'}}

#endif /* KEYPAD_CONFIG_H_ */
