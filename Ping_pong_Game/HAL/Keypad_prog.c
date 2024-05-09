/*
 * Keypad_prog.c
 *
 *  Created on: 3 Nov 2023
 *      Author: Alaraby
 */
#include "../LIBERARY/stdTypes.h"
#include "../LIBERARY/Error_State.h"

#include "../MCAL/DIO_int.h"

#include "Keypad_priv.h"
#include "Keypad_config.h"

ES_t Keypad_enuInit(void)
{
	ES_t Local_enuErrorState=ES_NOK;
	u32 Local_u32ErrorCheck=0;
	Local_u32ErrorCheck=(DIO_enuSet_PinDirection(KPD_C1_PORT,KPD_C1_PIN, DIO_u8INPUT)<<2);
	Local_u32ErrorCheck|=(DIO_enuSet_PinDirection(KPD_C2_PORT,KPD_C2_PIN, DIO_u8INPUT)<<4);
	Local_u32ErrorCheck|=(DIO_enuSet_PinDirection(KPD_C3_PORT,KPD_C3_PIN, DIO_u8INPUT)<<6);
	Local_u32ErrorCheck|=(DIO_enuSet_PinDirection(KPD_C4_PORT,KPD_C4_PIN, DIO_u8INPUT)<<8);

	Local_u32ErrorCheck|=(DIO_enuSet_PinDirection(KPD_R1_PORT,KPD_R1_PIN, DIO_u8OUTPUT)<<10);
	Local_u32ErrorCheck|=(DIO_enuSet_PinDirection(KPD_R2_PORT,KPD_R2_PIN, DIO_u8OUTPUT)<<12);
	Local_u32ErrorCheck|=(DIO_enuSet_PinDirection(KPD_R3_PORT,KPD_R3_PIN, DIO_u8OUTPUT)<<14);
	Local_u32ErrorCheck|=(DIO_enuSet_PinDirection(KPD_R4_PORT,KPD_R4_PIN, DIO_u8OUTPUT)<<16);

	Local_u32ErrorCheck|=(DIO_enuSet_PinValue(KPD_C1_PORT,KPD_C1_PIN, DIO_u8PULLUP)<<18);
	Local_u32ErrorCheck|=(DIO_enuSet_PinValue(KPD_C2_PORT,KPD_C2_PIN, DIO_u8PULLUP)<<20);
	Local_u32ErrorCheck|=(DIO_enuSet_PinValue(KPD_C3_PORT,KPD_C3_PIN, DIO_u8PULLUP)<<22);
	Local_u32ErrorCheck|=(DIO_enuSet_PinValue(KPD_C4_PORT,KPD_C4_PIN, DIO_u8PULLUP)<<24);

	Local_u32ErrorCheck|=(DIO_enuSet_PinValue(KPD_R1_PORT,KPD_R1_PIN, DIO_u8HIGH)<<26);
	Local_u32ErrorCheck|=(DIO_enuSet_PinValue(KPD_R2_PORT,KPD_R2_PIN, DIO_u8HIGH)<<28);
	Local_u32ErrorCheck|=(DIO_enuSet_PinValue(KPD_R3_PORT,KPD_R3_PIN, DIO_u8HIGH)<<30);
	Local_u32ErrorCheck|=(DIO_enuSet_PinValue(KPD_R4_PORT,KPD_R4_PIN, DIO_u8HIGH)<<32);

	u8 Local_u8Itre=0;
	for(Local_u8Itre=0 ; (Local_u8Itre<=sizeof(Local_u32ErrorCheck)*8) ; Local_u8Itre+=2)
	{
		if( ( ( ( Local_u32ErrorCheck ) >>Local_u8Itre ) &7 )!=ES_OK )
		{
			return Local_enuErrorState;
		}
		else
		{
			Local_enuErrorState=ES_OK;
		}
	}

	return Local_enuErrorState;
}


ES_t Keypad_enuGetPressedKey(u8 *Copy_u8pKPD_PrssedKey)
{
	ES_t Local_enuErrorState=ES_NOK;

	static u8 Local_u8StKPDArr[Row_Num][Col_Num]=KPD_Arr_Val;
	u8 Local_u8ColItre=0;
	u8 Local_u8RowIter=0;
	u8 Local_u8PinState;
	*Copy_u8pKPD_PrssedKey=KPD_NotPress;
	static u8 Local_u8StKPDColumArr_Port[Col_Num]={KPD_C1_PORT,KPD_C2_PORT,KPD_C3_PORT,KPD_C4_PORT};
	static u8 Local_u8StKPDRowArr_Port[Row_Num]=  {KPD_R1_PORT,KPD_R2_PORT,KPD_R3_PORT,KPD_R4_PORT};

	static u8 Local_u8StKPDColumArr_Pin[Col_Num]={KPD_C1_PIN,KPD_C2_PIN,KPD_C3_PIN,KPD_C4_PIN};
	static u8 Local_u8StKPDRowArr_Pin[Row_Num]=  {KPD_R1_PIN,KPD_R2_PIN,KPD_R3_PIN,KPD_R4_PIN};

	for(Local_u8ColItre=0; Local_u8ColItre<Col_Num ; Local_u8ColItre++)
	{
		Local_enuErrorState=DIO_enuSet_PinValue(Local_u8StKPDColumArr_Port[Local_u8ColItre],Local_u8StKPDColumArr_Pin[Local_u8ColItre],DIO_u8LOW);
		for(Local_u8RowIter=0 ; Local_u8RowIter <Row_Num ; Local_u8RowIter++)
		{
			Local_enuErrorState=DIO_enuget_PinValue(Local_u8StKPDRowArr_Port[Local_u8RowIter] ,Local_u8StKPDRowArr_Pin[Local_u8RowIter], &Local_u8PinState);
			if(DIO_u8LOW == Local_u8PinState)
			{

				while(DIO_u8LOW == Local_u8PinState)/*polling for busy waiting until precsseing release*/
				{
					Local_enuErrorState=DIO_enuget_PinValue(Local_u8StKPDRowArr_Port[Local_u8RowIter] ,Local_u8StKPDRowArr_Pin[Local_u8RowIter], &Local_u8PinState);
				}
				*Copy_u8pKPD_PrssedKey=Local_u8StKPDArr[Local_u8RowIter][Local_u8ColItre];
				return Local_enuErrorState ;
			}

		}
		Local_enuErrorState=DIO_enuSet_PinValue(Local_u8StKPDColumArr_Port[Local_u8ColItre],Local_u8StKPDColumArr_Pin[Local_u8ColItre],DIO_u8HIGH);

	}


	return Local_enuErrorState;
}
