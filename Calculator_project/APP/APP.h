/*
 * APP.h
 *
 *  Created on: 7 Dec 2023
 *      Author: Ibrahem Ashour
 */

#ifndef APP_H_
#define APP_H_
#define MAX_SIZE 16
u8 Local_u8IsDigit(u8 Copy_u8Digit);
u8 Local_u8IsOperand(u8 Copy_u8Operand);
s16 calculatePostfix(char postfix[]);
void infixToPostfix(char infix[], char postfix[]);
#endif /* APP_H_ */
