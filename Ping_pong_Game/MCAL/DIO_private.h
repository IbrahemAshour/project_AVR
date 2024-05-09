/*
 * DIO_private.h
 *
 *  Created on: Oct 3, 2023
 *      Author: Alaraby
 */
#ifndef  DIO_PRIVATE_H_
#define  DIO_PRIVATE_H_

#define DDRA   *((volatile u8*)0x3A)
#define PORTA  *((volatile u8*)0x3B)
#define PINA   *((volatile u8*)0x39)

#define DDRB   *((volatile u8*)0x37)
#define PORTB  *((volatile u8*)0x38)
#define PINB   *((volatile u8*)0x36)

#define DDRC   *((volatile u8*)0x34)
#define PORTC  *((volatile u8*)0x35)
#define PINC   *((volatile u8*)0x33)

#define DDRD   *((volatile u8*)0x31)
#define PORTD  *((volatile u8*)0x32)
#define PIND   *((volatile u8*)0x30)

#define INPUT  0
#define OUTPUT 1

#define HIGH   1
#define LOW    0
#define FLOAT  0
#define PULLUP 1

#define DIO_BIT_MUSK 1

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0	0
#define DIO_PIN1	1
#define DIO_PIN2	2
#define DIO_PIN3	3
#define DIO_PIN4	4
#define DIO_PIN5	5
#define DIO_PIN6	6
#define DIO_PIN7	7



#define ConcHelp(b7,b6,b5,b4,b3,b2,b1,b0)  0b##b7##b6##b5##b4##b3##b2##b1##b0
#define Conc(b7,b6,b5,b4,b3,b2,b1,b0)      ConcHelp(b7,b6,b5,b4,b3,b2,b1,b0)


#endif

