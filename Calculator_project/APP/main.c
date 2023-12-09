/*
 * main.c
 *
 *  Created on: 1 Dec 2023
 *      Author: Ibrahem Ashour
 */

#include "Error_State.h"
#include "stdTypes.h"
#include "DIO_int.h"
#include "Keypad_int.h"
#include "LCD_int.h"
#include "APP.h"
#include <util/delay.h>
int main()
 {
	DIO_enuInit();
	LCD_enuInit();
	Keypad_enuInit();

	u8 Local_u8key=0;
	u8 *Local_u8pkey=&Local_u8key;
	s16 Local_u16NumOne=0,Local_u16NumTwo=0;
	char operand;
	s16 Local_s16Result=0;


	u8 Local_u8Iter=0;

	while(1)
	{

		do
		{
			Keypad_enuGetPressedKey(Local_u8pkey);
			Local_u8key=*Local_u8pkey;

		}while(Local_u8key == 0xff);



		if(Local_u8IsDigit(Local_u8key))
		{
			LCD_voidDisplayIntegerNum(Local_u8key-48);
			if(Local_u8Iter==0)
			{
				Local_u16NumOne=Local_u16NumOne*10+(Local_u8key-48);

			}
			else if(Local_u8Iter!=0)
			{
				Local_u16NumTwo=+Local_u16NumTwo*10+(Local_u8key-48);

			}

		}
		else if(Local_u8IsOperand(Local_u8key))
		{
			LCD_enuDisplayCharacter(Local_u8key);
			operand=Local_u8key;
			++Local_u8Iter;
		}
		else if(Local_u8key == '=')
		{

			LCD_voidClearDisplay();
			LCD_voidGotoXY(0,0);
			switch(operand)
			{
			case'+':
				Local_s16Result=(Local_u16NumOne + Local_u16NumTwo);
				break;
			case'-':
				Local_s16Result=((Local_u16NumOne - Local_u16NumTwo));
				break;
			case'/':
				if(Local_u16NumTwo==0){
					LCD_enuSendString("ERROR !!");
					_delay_ms(20);
					LCD_voidClearDisplay();

					Local_u8Iter=0;
				}
				else
				{
					Local_s16Result=((Local_u16NumOne / Local_u16NumTwo));
				}
				break;
			case'*':
				Local_s16Result=((Local_u16NumOne * Local_u16NumTwo));
				break;
			}
			if(Local_u16NumTwo!=0)
			{
			LCD_voidDisplayIntegerNum(Local_s16Result);
			}

			Local_u16NumOne=Local_s16Result;
			Local_s16Result=0;
			Local_u16NumTwo=0;
			operand=0;
		}
		else if(Local_u8key=='c')
		{
			LCD_voidClearDisplay();
		}

	}
}






