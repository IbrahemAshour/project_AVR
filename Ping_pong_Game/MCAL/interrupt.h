/*
 * interrupt.h
 *
 *  Created on: 17 Dec 2023
 *      Author: Alaraby
 */

#ifndef MCAL_INTERRUPT_H_
#define MCAL_INTERRUPT_H_

#define ISR(Interrupt)  void Interrupt(void)__attribute__((signal));\
						void Interrupt(void)

#define INT0    __vector_1
#define INT1    __vector_2
#define INT2    __vector_3
#endif /* MCAL_INTERRUPT_H_ */
