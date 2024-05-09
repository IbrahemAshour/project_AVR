/*
 * LCD_prog.c
 *
 *  Created on: 2 Nov 2023
 *      Author: Alaraby
 */
#include "../LIBERARY/stdTypes.h"
#include "../LIBERARY/Error_State.h"

#include "../MCAL/DIO_int.h"

#include "LCD_priv.h"
#include "LCD_config.h"

#include "util/delay.h"


ES_t LCD_enuInit(void)
{
	ES_t Local_errorState=ES_NOK;
	/*wait for more than 30 ms to rise voltage up to 4.5 volt*/
	_delay_ms(35);

	DIO_enuSet_PinDirection(RS_PORT , RS_PIN ,DIO_u8OUTPUT);

	DIO_enuSet_PinDirection(RW_PORT , RW_PIN ,DIO_u8OUTPUT);

	DIO_enuSet_PinDirection(EN_PORT , EN_PIN ,DIO_u8OUTPUT);

	DIO_enuSet_PinDirection(D7_PORT , D7_PIN ,DIO_u8OUTPUT);
	DIO_enuSet_PinDirection(D6_PORT , D6_PIN ,DIO_u8OUTPUT);
	DIO_enuSet_PinDirection(D5_PORT , D5_PIN ,DIO_u8OUTPUT);
	DIO_enuSet_PinDirection(D4_PORT , D4_PIN ,DIO_u8OUTPUT);

	_delay_ms(35);
#if LCD_MODE == EIGHT_BIT

	DIO_enuSet_PinDirection(D3_PORT , D3_PIN ,DIO_u8OUTPUT);
	DIO_enuSet_PinDirection(D2_PORT , D2_PIN ,DIO_u8OUTPUT);
	DIO_enuSet_PinDirection(D1_PORT , D1_PIN ,DIO_u8OUTPUT);
	DIO_enuSet_PinDirection(D0_PORT , D0_PIN ,DIO_u8OUTPUT);
	/*for function set --> 8 mode 2 line 5*8 */
	LCD_invidSendCommond(Fun_Set_8b);

#elif LCD_MODE == FOUR_BIT
	_delay_ms(35);
	/*for function set --> 4 mode 2 line 5*8*/
	LCD_invidSendCommond(Fun_Set_4b );
#else
#error "Error Invalid LCD Mode"
#endif
	_delay_ms(1);
	/*Display on off control*/
	LCD_invidSendCommond(Display_On);
	_delay_ms(1);
	/*Clear Display */
	LCD_invidSendCommond(Clear_Display);
	_delay_ms(2);
	/*Entry mode --> increase cursor -- no shift */
	LCD_invidSendCommond(Entry_Mode);
	Local_errorState=ES_OK;
	return Local_errorState;
}

static void LCD_voidLatch(u8 Copy_u8Data )
{


	/* Set RW pin low for write*/

	DIO_enuSet_PinValue(RW_PORT , RW_PIN ,DIO_u8LOW);
	/*to start the pulse of send command or data*/
	DIO_enuSet_PinValue(EN_PORT , EN_PIN ,DIO_u8LOW);

	DIO_enuSet_PinValue(D7_PORT , D7_PIN ,(((Copy_u8Data>>D_D7)&GetMusk)));
	DIO_enuSet_PinValue(D6_PORT , D6_PIN ,(((Copy_u8Data>>D_D6)&GetMusk))) ;
	DIO_enuSet_PinValue(D5_PORT , D5_PIN ,(((Copy_u8Data>>D_D5)&GetMusk))) ;
	DIO_enuSet_PinValue(D4_PORT , D4_PIN ,(((Copy_u8Data>>D_D4)&GetMusk))) ;

#if LCD_MODE == EIGHT_BIT

	DIO_enuSet_PinValue(D3_PORT , D3_PIN ,(((Copy_u8Data>>D_D3)&GetMusk)));
	DIO_enuSet_PinValue(D2_PORT , D2_PIN ,(((Copy_u8Data>>D_D2)&GetMusk)));
	DIO_enuSet_PinValue(D1_PORT , D1_PIN ,(((Copy_u8Data>>D_D1)&GetMusk)));
	DIO_enuSet_PinValue(D0_PORT , D0_PIN ,(((Copy_u8Data>>D_D0)&GetMusk)));


#elif	LCD_MODE == FOUR_BIT
	if(Copy_u8Data==Fun_Set_4b)
	{
		/* give enable high to start duration of pulse*/
		DIO_enuSet_PinValue(EN_PORT , EN_PIN ,DIO_u8HIGH);
		_delay_ms(10);
		/*give zero to end the pulse */
		DIO_enuSet_PinValue(EN_PORT , EN_PIN ,DIO_u8LOW);
		_delay_ms(50);

		DIO_enuSet_PinValue(D7_PORT , D7_PIN ,(((Copy_u8Data>>D_D7)&GetMusk)));
		DIO_enuSet_PinValue(D6_PORT , D6_PIN ,(((Copy_u8Data>>D_D6)&GetMusk))) ;
		DIO_enuSet_PinValue(D5_PORT , D5_PIN ,(((Copy_u8Data>>D_D5)&GetMusk))) ;
		DIO_enuSet_PinValue(D4_PORT , D4_PIN ,(((Copy_u8Data>>D_D4)&GetMusk))) ;
	}
	/* give enable high to start duration of pulse*/
	DIO_enuSet_PinValue(EN_PORT , EN_PIN ,DIO_u8HIGH);
	_delay_ms(10);
	/*give zero to end the pulse */
	DIO_enuSet_PinValue(EN_PORT , EN_PIN ,DIO_u8LOW);
	_delay_ms(10);

	DIO_enuSet_PinValue(D7_PORT , D7_PIN ,(((Copy_u8Data>>D_D3)&GetMusk)));
	DIO_enuSet_PinValue(D6_PORT , D6_PIN ,(((Copy_u8Data>>D_D2)&GetMusk))) ;
	DIO_enuSet_PinValue(D5_PORT , D5_PIN ,(((Copy_u8Data>>D_D1)&GetMusk))) ;
	DIO_enuSet_PinValue(D4_PORT , D4_PIN ,(((Copy_u8Data>>D_D0)&GetMusk))) ;
#endif

	/* give enable high to start duration of pulse*/
	DIO_enuSet_PinValue(EN_PORT , EN_PIN ,DIO_u8HIGH);
	_delay_ms(10);
	/*give zero to end the pulse */
	DIO_enuSet_PinValue(EN_PORT , EN_PIN ,DIO_u8LOW);
	_delay_ms(10);


}
ES_t LCD_enuDisplayCharacter(u8 Copy_u8character)
{
	ES_t Local_errorState=ES_NOK;
	DIO_enuSet_PinValue(RS_PORT , RS_PIN ,DIO_u8HIGH);
	u8 Local_u8errorCheck=0;
	LCD_voidLatch( Copy_u8character );
	if(Local_u8errorCheck==1)
	{
		return Local_errorState;
	}
	else
	{
		Local_errorState=ES_OK;
	}

	return Local_errorState;
}

ES_t LCD_enuSendCommond(u8 Copy_u8commond)
{
	/* for check on error of functions */
	ES_t Local_errorState=ES_NOK;
	u8 Local_u8errorCheck=0;

	/* set RS pin low for command */

	DIO_enuSet_PinValue(RS_PORT , RS_PIN ,DIO_u8LOW);

	LCD_voidLatch( Copy_u8commond  );

	if(Local_u8errorCheck==1)
	{
		return Local_errorState;
	}
	else
	{
		Local_errorState=ES_OK;
	}


	return Local_errorState;
}

static inline void LCD_invidSendCommond(u8 Copy_u8commond)
{
	DIO_enuSet_PinValue(RS_PORT , RS_PIN ,DIO_u8LOW);

	DIO_enuSet_PinValue(RW_PORT , RW_PIN ,DIO_u8LOW);

	DIO_enuSet_PinValue(EN_PORT , EN_PIN ,DIO_u8LOW);

	DIO_enuSet_PinValue(D7_PORT , D7_PIN ,(((Copy_u8commond>>D_D7)&GetMusk)));
	DIO_enuSet_PinValue(D6_PORT , D6_PIN ,(((Copy_u8commond>>D_D6)&GetMusk)));
	DIO_enuSet_PinValue(D5_PORT , D5_PIN ,(((Copy_u8commond>>D_D5)&GetMusk)));
	DIO_enuSet_PinValue(D4_PORT , D4_PIN ,(((Copy_u8commond>>D_D4)&GetMusk)));

#if LCD_MODE==EIGHT_BIT

	DIO_enuSet_PinValue(D3_PORT , D3_PIN ,(((Copy_u8commond>>D_D3)&GetMusk)));
	DIO_enuSet_PinValue(D2_PORT , D2_PIN ,(((Copy_u8commond>>D_D2)&GetMusk)));
	DIO_enuSet_PinValue(D1_PORT , D1_PIN ,(((Copy_u8commond>>D_D1)&GetMusk)));
	DIO_enuSet_PinValue(D0_PORT , D0_PIN ,(((Copy_u8commond>>D_D0)&GetMusk)));

	DIO_enuSet_PinValue(EN_PORT , EN_PIN ,DIO_u8HIGH);
	_delay_ms(10);

	DIO_enuSet_PinValue(EN_PORT , EN_PIN ,DIO_u8LOW);
#elif LCD_MODE==FOUR_BIT
	if(Copy_u8commond==Fun_Set_4b)
	{
		DIO_enuSet_PinValue(EN_PORT , EN_PIN ,DIO_u8HIGH);
		_delay_ms(10);
		DIO_enuSet_PinValue(EN_PORT , EN_PIN ,DIO_u8LOW);

		DIO_enuSet_PinValue(D7_PORT , D7_PIN ,(((Copy_u8commond>>D_D7)&GetMusk)));
		DIO_enuSet_PinValue(D6_PORT , D6_PIN ,(((Copy_u8commond>>D_D6)&GetMusk)));
		DIO_enuSet_PinValue(D5_PORT , D5_PIN ,(((Copy_u8commond>>D_D5)&GetMusk)));
		DIO_enuSet_PinValue(D4_PORT , D4_PIN ,(((Copy_u8commond>>D_D4)&GetMusk)));
	}
	DIO_enuSet_PinValue(EN_PORT , EN_PIN ,DIO_u8HIGH);
	_delay_ms(10);
	DIO_enuSet_PinValue(EN_PORT , EN_PIN ,DIO_u8LOW);

	DIO_enuSet_PinValue(D7_PORT , D7_PIN ,(((Copy_u8commond>>D_D3)&GetMusk)));
	DIO_enuSet_PinValue(D6_PORT , D6_PIN ,(((Copy_u8commond>>D_D2)&GetMusk)));
	DIO_enuSet_PinValue(D5_PORT , D5_PIN ,(((Copy_u8commond>>D_D1)&GetMusk)));
	DIO_enuSet_PinValue(D4_PORT , D4_PIN ,(((Copy_u8commond>>D_D0)&GetMusk)));
#endif
	DIO_enuSet_PinValue(EN_PORT , EN_PIN ,DIO_u8HIGH);
	_delay_ms(10);
	DIO_enuSet_PinValue(EN_PORT , EN_PIN ,DIO_u8LOW);
}

ES_t LCD_enuSendString(const char *Copy_pcString)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(Copy_pcString != NULL)
	{
		s8 Local_s8_Iter_String=0;
		while(Copy_pcString[Local_s8_Iter_String]!= 0)
		{
			Local_enuErrorState=LCD_enuDisplayCharacter(Copy_pcString[Local_s8_Iter_String]);
			Local_s8_Iter_String++;
		}
	}
	else
	{
		Local_enuErrorState=ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}
void LCD_voidGotoXY(u8 Copy_u8X_Pos , u8 Copy_u8Y_Pos)
{

	u8 Local_u8Address;
	if(Copy_u8X_Pos == 0)
	{
		Local_u8Address=Copy_u8Y_Pos;
	}
	else if(Copy_u8X_Pos == 1)
	{
		Local_u8Address=Copy_u8Y_Pos + 0x40;
	}
	LCD_enuSendCommond(0x80 |Local_u8Address);

}
void LCD_voidDisplaySpecialCharacter(u8 *Copy_pau8Array_Data , u8 Copy_u8Block_number ,u8 Copy_u8Xpos , u8 Copy_u8Ypos)
{
	/*Calculate   CGRAM  Address */
	u8 Local_u8CGRAM_Address=Copy_u8Block_number*8;

	/* Send address CGROM command to Lcd ,With setting bit 6 , clearing bit 7 */
	LCD_enuSendCommond(Local_u8CGRAM_Address+64);

	/* Counter to block to loop of array character*/
	u8 Local_u8Block_Counter=0;

	/* Write the pattern in CGRam*/
	for(Local_u8Block_Counter = 0 ; Local_u8Block_Counter <8 ; Local_u8Block_Counter ++)
	{
		LCD_enuDisplayCharacter(Copy_pau8Array_Data[Local_u8Block_Counter]);
	}

	/*Go to DDRAM to display the pattern */
	LCD_voidGotoXY(Copy_u8Xpos,Copy_u8Ypos);

	/*Display the pattern  Written in CGRam*/
	LCD_enuDisplayCharacter(Copy_u8Block_number);
}


void LCD_voidDisplayIntegerNum(s32 Copy_s32Num)
{
	if(Copy_s32Num!=0)
	{
		if(Copy_s32Num<0)
		{
			Copy_s32Num*=-1;
			LCD_enuDisplayCharacter('-');

		}
		s8 Local_u8A_numbers[33];
		s8 *Local_u8pa_catchNumber=&Local_u8A_numbers[32];
		*Local_u8pa_catchNumber='\0';
		Local_u8pa_catchNumber--;
		while(Copy_s32Num)
		{
			*Local_u8pa_catchNumber=(Copy_s32Num % 10 )+48;/*to convert number to string */
			Local_u8pa_catchNumber--;
			Copy_s32Num /=10;
		}
		Local_u8pa_catchNumber++;
		LCD_enuSendString(Local_u8pa_catchNumber);
	}

	else
	{
		LCD_enuSendString("0");
	}
}
void LCD_voidClearDisplay(void)
{
	LCD_enuSendCommond(Clear_Display);
}

void LCD_voidGotoSecondLine(void)
{
	LCD_voidGotoXY(1,0);
}
void LCD_voidDisplayNumberIn4Digit(u16 Copy_u16Number)
{
	LCD_enuDisplayCharacter(((Copy_u16Number%10000)/1000)+'0');
	LCD_enuDisplayCharacter(((Copy_u16Number%1000)/100)+'0');
	LCD_enuDisplayCharacter(((Copy_u16Number%100)/10)+'0');
	LCD_enuDisplayCharacter(((Copy_u16Number%10)/1)+'0');
}
