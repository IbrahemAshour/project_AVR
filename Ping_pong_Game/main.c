/*
 * main.c
 *
 *  Created on: 3 Feb 2024
 *      Author: Alaraby
 */
#include"LIBERARY/stdTypes.h"
#include"LIBERARY/Error_State.h"
#include"MCAL/DIO_int.h"
#include"MCAL/EXTI_config.h"
#include"MCAL/EXTI_int.h"
#include"MCAL/GIE_int.h"
#include"HAL/LCD_int.h"
#include"APP/APP.h"
#include <util\delay.h>

#define N_goals 3 /* number of goals to win  match*/
void Forward(void);
void Backword(void);

extern EXTI_t EXTI_TArrStrInterrt_config[3];
extern int pos;
extern u8 dis;
u8 Pl_1=0;
u8 Pl_2 =0;

int main()
{

	DIO_enuInit();
	LCD_enuInit();
	EXTI_enuInit(EXTI_TArrStrInterrt_config);
	DIO_enuSet_PinDirection(DIO_u8PORTD , DIO_u8PIN2 , DIO_u8INPUT);
	DIO_enuSet_PinDirection(DIO_u8PORTD , DIO_u8PIN3 , DIO_u8INPUT);
	EXTI_enuCall_Back(Forward , 1);
	EXTI_enuCall_Back(Backword , 2 );
	GIE_enuEnable();

	while (1)
	{
		if(pos <= 0)
		{

			while(dis ==0){
				Pl_2++;
				LCD_voidClearDisplay();
				LCD_enuSendString("Player 2 Win");
				dis++;
			}
		}
		if(pos >= 15)
		{

			while(dis ==0){
				Pl_1++;
				LCD_voidClearDisplay();
				LCD_enuSendString("Player 1 Win");
				dis++;
			}
		}
		if((Pl_1 == N_goals || Pl_2 == N_goals) && dis == 1)
		{
			LCD_voidClearDisplay();
			LCD_enuSendString( "Match Ended ");
			LCD_voidClearDisplay();
			LCD_voidGotoXY(0 , 6);
			LCD_enuSendString( "Result ");
			LCD_voidGotoXY(1 ,6);
			LCD_voidDisplayIntegerNum(Pl_1);
			LCD_voidGotoXY(1 ,8);
			LCD_enuDisplayCharacter(':');
			LCD_voidGotoXY(1 ,10);
			LCD_voidDisplayIntegerNum(Pl_2);
			dis++;

		}
	}
	return 0;
}





