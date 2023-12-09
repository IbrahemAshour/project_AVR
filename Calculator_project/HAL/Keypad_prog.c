/*
 * Keypad_prog.c
 *
 *  Created on: 3 Nov 2023
 *      Author: Ibrahem Ashour
 */
#include<util/delay.h>


#include "Error_State.h"
#include "stdTypes.h"
#include "DIO_int.h"
#include "Keypad_config.h"
#include "Keypad_priv.h"
ES_t Keypad_enuInit(void)
{
	ES_t Local_enuErrorState=ES_NOK;

	DIO_enuSet_PinDirection(KPD_R1_PORT,KPD_R1_PIN, DIO_u8INPUT);
	DIO_enuSet_PinDirection(KPD_R2_PORT,KPD_R2_PIN, DIO_u8INPUT);
	DIO_enuSet_PinDirection(KPD_R3_PORT,KPD_R3_PIN, DIO_u8INPUT);
	DIO_enuSet_PinDirection(KPD_R4_PORT,KPD_R4_PIN, DIO_u8INPUT);

	DIO_enuSet_PinDirection(KPD_C1_PORT,KPD_C1_PIN, DIO_u8OUTPUT);
	DIO_enuSet_PinDirection(KPD_C2_PORT,KPD_C2_PIN, DIO_u8OUTPUT);
	DIO_enuSet_PinDirection(KPD_C3_PORT,KPD_C3_PIN, DIO_u8OUTPUT);
	DIO_enuSet_PinDirection(KPD_C4_PORT,KPD_C4_PIN, DIO_u8OUTPUT);

	DIO_enuSet_PinValue(KPD_R1_PORT,KPD_R1_PIN, DIO_u8PULLUP);
	DIO_enuSet_PinValue(KPD_R2_PORT,KPD_R2_PIN, DIO_u8PULLUP);
	DIO_enuSet_PinValue(KPD_R3_PORT,KPD_R3_PIN, DIO_u8PULLUP);
	DIO_enuSet_PinValue(KPD_R4_PORT,KPD_R4_PIN, DIO_u8PULLUP);

	DIO_enuSet_PinValue(KPD_C1_PORT,KPD_C1_PIN, DIO_u8HIGH);
	DIO_enuSet_PinValue(KPD_C2_PORT,KPD_C2_PIN, DIO_u8HIGH);
	DIO_enuSet_PinValue(KPD_C3_PORT,KPD_C3_PIN, DIO_u8HIGH);
	DIO_enuSet_PinValue(KPD_C4_PORT,KPD_C4_PIN, DIO_u8HIGH);

	Local_enuErrorState=ES_OK;

	return Local_enuErrorState;
}


ES_t Keypad_enuGetPressedKey(u8 *Copy_u8pKPD_PrssedKey)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(Copy_u8pKPD_PrssedKey != NULL)
	{
		static u8 Local_u8StKPDArr[Row_Num][Col_Num]=KPD_Arr_Val;

		static u8 Local_u8StKPDColumArr_Port[Col_Num]={KPD_C1_PORT,KPD_C2_PORT,KPD_C3_PORT,KPD_C4_PORT};
		static u8 Local_u8StKPDRowArr_Port[Row_Num]=  {KPD_R1_PORT,KPD_R2_PORT,KPD_R3_PORT,KPD_R4_PORT};

		static u8 Local_u8StKPDColumArr_Pin[Col_Num]={KPD_C1_PIN,KPD_C2_PIN,KPD_C3_PIN,KPD_C4_PIN};
		static u8 Local_u8StKPDRowArr_Pin[Row_Num]=  {KPD_R1_PIN,KPD_R2_PIN,KPD_R3_PIN,KPD_R4_PIN};

		u8 Local_u8ColItre=0;
		u8 Local_u8RowIter=0;
		u8 Local_u8PinState;
		*Copy_u8pKPD_PrssedKey=KPD_NotPress;



		for(Local_u8ColItre=0; Local_u8ColItre<Col_Num ; Local_u8ColItre++)
		{
			DIO_enuSet_PinValue(Local_u8StKPDColumArr_Port[Local_u8ColItre],Local_u8StKPDColumArr_Pin[Local_u8ColItre],DIO_u8LOW);

			for(Local_u8RowIter=0 ; Local_u8RowIter <Row_Num ; Local_u8RowIter++)
			{
				DIO_enuget_PinValue(Local_u8StKPDRowArr_Port[Local_u8RowIter] ,Local_u8StKPDRowArr_Pin[Local_u8RowIter], &Local_u8PinState);
				if(!Local_u8PinState)
				{
					_delay_ms(10);
					DIO_enuget_PinValue(Local_u8StKPDRowArr_Port[Local_u8RowIter] ,Local_u8StKPDRowArr_Pin[Local_u8RowIter], &Local_u8PinState);
					if(!Local_u8PinState)
					{
						while(! Local_u8PinState)
						{
							DIO_enuget_PinValue(Local_u8StKPDRowArr_Port[Local_u8RowIter] ,Local_u8StKPDRowArr_Pin[Local_u8RowIter], &Local_u8PinState);
						}

						*Copy_u8pKPD_PrssedKey=Local_u8StKPDArr[Local_u8RowIter][Local_u8ColItre];
						return Local_enuErrorState=ES_OK;
					}

				}

			}
			DIO_enuSet_PinValue(Local_u8StKPDColumArr_Port[Local_u8ColItre],Local_u8StKPDColumArr_Pin[Local_u8ColItre],DIO_u8HIGH);

		}
	}
	else
	{
		Local_enuErrorState=ES_NULL_POINTER;
	}


	return Local_enuErrorState;
}
/*
//ES_t Keypad_enuGetPressedKey(u8 * Copy_pu8KeyValue)
{
	ES_t Local_enuErrorState =ES_NOK;

	if (Copy_pu8KeyValue != NULL)
	{
		u8 Local_Au8RowPins [ROWS_NUM] = { R1_PIN , R2_PIN , R3_PIN , R4_PIN };
		u8 Local_Au8ColPins [COLS_NUM] = { C1_PIN , C2_PIN , C3_PIN , C4_PIN };
		u8 Local_Au8RowPorts[ROWS_NUM] = { R1_PORT , R2_PORT , R3_PORT , R4_PORT };
		u8 Local_Au8ColPorts[COLS_NUM] = { C1_PORT , C2_PORT , C3_PORT , C4_PORT };

 *Copy_pu8KeyValue = KEY_NOT_PRESS;

		u8 Local_Au8KeyValues[ROWS_NUM][COLS_NUM] = KEYS_VALUES;

		u8 Local_u8PinValue = 0xff;

		u8 Local_u8RowIter , Local_u8ColIter;

		for (Local_u8ColIter =0; Local_u8ColIter < COLS_NUM ; Local_u8ColIter ++)
		{
			DIO_enuSetPinValue(Local_Au8ColPorts[Local_u8ColIter] , Local_Au8ColPins[Local_u8ColIter] , DIO_u8LOW);

			for (Local_u8RowIter =0 ; Local_u8RowIter <ROWS_NUM ; Local_u8RowIter ++)
			{
				DIO_enuGetPinValue(Local_Au8RowPorts[Local_u8RowIter], Local_Au8RowPins[Local_u8RowIter], &Local_u8PinValue);
				if (! Local_u8PinValue)
				{
					_delay_ms(10);
					DIO_enuGetPinValue(Local_Au8RowPorts[Local_u8RowIter], Local_Au8RowPins[Local_u8RowIter], &Local_u8PinValue);
					if (! Local_u8PinValue)
					{
						while (! Local_u8PinValue)
						{
							DIO_enuGetPinValue(Local_Au8RowPorts[Local_u8RowIter], Local_Au8RowPins[Local_u8RowIter], &Local_u8PinValue);
						}

 *Copy_pu8KeyValue = Local_Au8KeyValues[Local_u8RowIter][Local_u8ColIter];

						return Local_enuErrorState=ES_OK;
					}
				}
			}

			DIO_enuSetPinValue(Local_Au8ColPorts[Local_u8ColIter] , Local_Au8ColPins[Local_u8ColIter] , DIO_u8HIGH);
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}
 */

