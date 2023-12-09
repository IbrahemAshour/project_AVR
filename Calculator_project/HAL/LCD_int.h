/*
 * LCD_int.h
 *
 *  Created on: 2 Nov 2023
 *      Author: Ibrahem Ashour
 */

#ifndef HAL_LCD_INT_H_
#define HAL_LCD_INT_H_

ES_t LCD_enuInit(void);

ES_t LCD_enuDisplayCharacter(u8 Copy_u8character);

ES_t LCD_enuSendCommond(u8 Copy_u8commond);

ES_t LCD_enuSendString(const char *Copy_pcString);

void LCD_voidGotoXY(u8 Copy_u8X_Pos , u8 Copy_u8Y_Pos);

void LCD_voidDisplaySpecialCharacter(u8 *Copy_pau8Array_Data , u8 Copy_u8Block_number ,u8 Copy_u8Xpos , u8 Copy_u8Ypos);
void LCD_voidDisplayIntegerNum(s32 Copy_s32Num);
void LCD_voidClearDisplay(void);
void LCD_voidGotoSecondLine(void);
void LCD_voidDisplayNumberIn4Digit(u16 Copy_u16Number);
#endif /* HAL_LCD_INT_H_ */
