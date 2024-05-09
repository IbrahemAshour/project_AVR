/*
 * EXTI_priv.h
 *
 *  Created on: 17 Dec 2023
 *      Author: Alaraby
 */

#ifndef MCAL_EXTI_PRIV_H_
#define MCAL_EXTI_PRIV_H_

#define SREG  		  *((volatile u8*)0X5F)

#define GICR  		  *((volatile u8*)0X5B)
#define GICR_INT1 	  7
#define GICR_INT0     6
#define GICR_INT2     5

#define GIFR   		  *((volatile u8*)0X5A)
#define GICR_INTF1 	  7
#define GICR_INTF0    6
#define GICR_INTF2    5

#define MCUCR  		  *((volatile u8*)0X55)
#define MCUCR_ISC11   3
#define MCUCR_ISC10   2
#define MCUCR_ISC01   1
#define MCUCR_ISC00   0

#define MCUCSR 		  *((volatile u8*)0X54)
#define MCUCSR_ISC2    6

/*Interrupt _States*/
#define ENABLE 1
#define DISEABLE 0

/*Interrupt Sense Level */
/*for all interrupt pin*/
#define FALLING_EDGE 1
#define RISING_EDGE  2

/*for INT0 & INT1 */
#define ONCHANGE     3
#define LOW_LEVEL    4


#endif /* MCAL_EXTI_PRIV_H_ */
