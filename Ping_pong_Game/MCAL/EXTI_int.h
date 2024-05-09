/*
 * EXTI_int.h
 *
 *  Created on: 17 Dec 2023
 *      Author: Alaraby
 */

#ifndef MCAL_EXTI_INT_H_
#define MCAL_EXTI_INT_H_

ES_t EXTI_enuInit(EXTI_t *Copy_PStr_StatesArray);
ES_t EXTI_enuChangeSence(u8 Copy_u8Interrupt_ID,u8 Copy_u8SenseLevel);
ES_t EXTI_enuEnable(u8 Copy_u8Interrupt_ID);
ES_t EXTI_enuDisable(u8 Copy_u8Interrupt_ID);
ES_t EXTI_enuCall_Back(void (*Copy_PtoFunAPP)(void *),u8 Copy_u8Interrupt_ID);

#endif /* MCAL_EXTI_INT_H_ */
