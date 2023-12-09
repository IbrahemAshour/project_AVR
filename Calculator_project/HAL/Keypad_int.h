/*
 * Keypad_int.h
 *
 *  Created on: 3 Nov 2023
 *      Author: Ibrahem Ashour
 */

#ifndef HAL_KEYPAD_INT_H_
#define HAL_KEYPAD_INT_H_

ES_t Keypad_enuInit(void);
ES_t Keypad_enuGetPressedKey(u8 *Copy_u8KPD_PrssedKey);

#endif /* HAL_KEYPAD_INT_H_ */
