/*
 * DIO_int.h
 *
 *  Created on: Oct 3, 2023
 *      Author: Alaraby
 */
#ifndef  DIO_INT_H_
#define  DIO_INT_H_

ES_t DIO_enuInit(void);

ES_t DIO_enuSet_PortValue(u8 copy_u8PortId,u8 copy_u8PortValue);
ES_t DIO_enuSet_PortDirection(u8 copy_u8PortId,u8 copy_u8PortValue);
ES_t DIO_enuget_PortValue(u8 copy_u8PortId,u8 *copy_pu8PortValue);
ES_t DIO_enuToggle_PortValue(u8 copy_u8PortId);



ES_t DIO_enuSet_PinValue(u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8PinValue);
ES_t DIO_enuSet_PinDirection(u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8PinValue);
ES_t DIO_enuget_PinValue(u8 copy_u8PortId,u8 copy_u8PinId,u8 *copy_pu8PinValue);
ES_t DIO_enuToggle_PinValue(u8 copy_u8PortId,u8 copy_u8PinId);

#define DIO_u8PORTA  0
#define DIO_u8PORTB  1
#define DIO_u8PORTC  2
#define DIO_u8PORTD  3

#define DIO_u8PIN0   0
#define DIO_u8PIN1   1
#define DIO_u8PIN2   2
#define DIO_u8PIN3   3
#define DIO_u8PIN4   4
#define DIO_u8PIN5   5
#define DIO_u8PIN6   6
#define DIO_u8PIN7   7

#define DIO_u8OUTPUT 1
#define DIO_u8INPUT  0

#define DIO_u8HIGH   1
#define DIO_u8LOW    0

#define DIO_u8FLOAT  0
#define DIO_u8PULLUP 1






#endif
