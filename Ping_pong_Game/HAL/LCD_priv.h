/*
 * LCD_priv.h
 *
 *  Created on: 2 Nov 2023
 *      Author: Ibrahem Ashour
 */

#ifndef HAL_LCD_PRIV_H_
#define HAL_LCD_PRIV_H_

#define EIGHT_BIT	8

#define FOUR_BIT	5

static inline void LCD_invidSendCommond(u8 Copy_u8commond);

static void LCD_voidLatch(u8 Copy_u8Data );

#define GetMusk 	1

#define D_D7		7
#define D_D6		6
#define D_D5		5
#define D_D4		4
#define D_D3		3
#define D_D2		2
#define D_D1		1
#define D_D0		0


/*8 bit mode*/
#define Fun_Set_8b       0x38
/* 4 bit mode */
#define Fun_Set_4b       0x28
/*display screen -- cursor on -- blinking cursor on --> 0x0F */
/*display screen -- cursor on -- blinking cursor off -->0x0E */
/*display screen -- cursor off -- blinking cursor off-->0x0C */
#define Display_On    0x0C

#define Display_Off   0x00
#define Clear_Display 0x01
/*Entry mode --> increase cursor -- no shift */
#define Entry_Mode    0x06
#endif /* HAL_LCD_PRIV_H_ */
