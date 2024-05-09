/*
 * S_Segment_config.h
 *
 *  Created on: 28 Oct 2023
 *      Author: Alaraby
 */

#ifndef S_SEGMENT_CONFIG_H_
#define S_SEGMENT_CONFIG_H_

#define SEG_APIN	 DIO_u8PIN3
#define SEG_APORT	 DIO_u8PORTA

#define SEG_BPIN     DIO_u8PIN4
#define SEG_BPORT    DIO_u8PORTA

#define SEG_CPIN     DIO_u8PIN3
#define SEG_CPORT    DIO_u8PORTB

#define SEG_DPIN     DIO_u8PIN4
#define SEG_DPORT    DIO_u8PORTB

#define SEG_EPIN     DIO_u8PIN2
#define SEG_EPORT    DIO_u8PORTC

#define SEG_FPIN   	 DIO_u8PIN3
#define SEG_FPORT  	 DIO_u8PORTC

#define SEG_GPIN  	 DIO_u8PIN0
#define SEG_GPORT  	 DIO_u8PORTD

#define SEG_CMN      NOT_CONNECTED
#define SEG_CMNPORT  NOT_CONNECTED

#define SEG_DOT      NOT_CONNECTED
#define SEG_DOTPORT  NOT_CONNECTED

#define SEG_TYPE	 COMMON_CATHODE

#endif /* S_SEGMENT_CONFIG_H_ */
