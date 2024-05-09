/*
 * DIO_prorg.c
*/

#include "../LIBERARY/stdTypes.h"
#include "../LIBERARY/Error_State.h"
#include "DIO_int.h"
#include "DIO_private.h"
#include "DIO_config.h"


ES_t DIO_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	DDRA=Conc(PORTA_PIN7_DIR,PORTA_PIN6_DIR,PORTA_PIN5_DIR,PORTA_PIN4_DIR,PORTA_PIN3_DIR,PORTA_PIN2_DIR,PORTA_PIN1_DIR,PORTA_PIN0_DIR);

	DDRB=Conc(PORTB_PIN7_DIR,PORTB_PIN6_DIR,PORTB_PIN5_DIR,PORTB_PIN4_DIR,PORTB_PIN3_DIR,PORTB_PIN2_DIR,PORTB_PIN1_DIR,PORTB_PIN0_DIR);

	DDRC=Conc(PORTC_PIN7_DIR,PORTC_PIN6_DIR,PORTC_PIN5_DIR,PORTC_PIN4_DIR,PORTC_PIN3_DIR,PORTC_PIN2_DIR,PORTC_PIN1_DIR,PORTC_PIN0_DIR);

	DDRD=Conc(PORTD_PIN7_DIR,PORTD_PIN6_DIR,PORTD_PIN5_DIR,PORTD_PIN4_DIR,PORTD_PIN3_DIR,PORTD_PIN2_DIR,PORTD_PIN1_DIR,PORTD_PIN0_DIR);

	PORTA=Conc(PORTA_PIN7_VAL,PORTA_PIN6_VAL,PORTA_PIN5_VAL,PORTA_PIN4_VAL,PORTA_PIN3_VAL,PORTA_PIN2_VAL,PORTA_PIN1_VAL,PORTA_PIN0_VAL);

	PORTB=Conc(PORTB_PIN7_VAL,PORTB_PIN6_VAL,PORTB_PIN5_VAL,PORTB_PIN4_VAL,PORTB_PIN3_VAL,PORTB_PIN2_VAL,PORTB_PIN1_VAL,PORTB_PIN0_VAL);

	PORTC=Conc(PORTC_PIN7_VAL,PORTC_PIN6_VAL,PORTC_PIN5_VAL,PORTC_PIN4_VAL,PORTC_PIN3_VAL,PORTC_PIN2_VAL,PORTC_PIN1_VAL,PORTC_PIN0_VAL);

	PORTD=Conc(PORTD_PIN7_VAL,PORTD_PIN6_VAL,PORTD_PIN5_VAL,PORTD_PIN4_VAL,PORTD_PIN3_VAL,PORTD_PIN2_VAL,PORTD_PIN1_VAL,PORTD_PIN0_VAL);

	Local_enuErrorState=ES_OK;
	return Local_enuErrorState;
}

ES_t DIO_enuSet_PortValue(u8 copy_u8PortId,u8 copy_u8PortValue)//copy_u8PortValue-->HIGH-->LOW
{
	ES_t Local_enuErrorState = ES_NOK;

	if(copy_u8PortId<=DIO_PORTD)
	{
		switch(copy_u8PortId)
		{
		case(DIO_PORTA):
			PORTA=copy_u8PortValue;
			break;
		case(DIO_PORTB):
			PORTB=copy_u8PortValue;
			break;
		case(DIO_PORTC):
			PORTC=copy_u8PortValue;
			break;
		case(DIO_PORTD):
			PORTD=copy_u8PortValue;
		    break;
		}
		Local_enuErrorState=ES_OK;

	}
	else
	{
		Local_enuErrorState=ES_OUT_OF_RANGE;
	}



	return Local_enuErrorState;
}


ES_t DIO_enuSet_PortDirection(u8 copy_u8PortId,u8 copy_u8PortValue)//copy_u8PortValue-->INPUT-->OUTPUT
{
	ES_t Local_enuErrorState = ES_NOK;

	if(copy_u8PortId<=DIO_PORTD)
	{
		switch(copy_u8PortId)
		{
		case(DIO_PORTA):
			DDRA=copy_u8PortValue;
			break;
		case(DIO_PORTB):
			DDRB=copy_u8PortValue;
			break;
		case(DIO_PORTC):
			DDRC=copy_u8PortValue;
			break;
		case(DIO_PORTD):
			DDRD=copy_u8PortValue;
		    break;
		}
		Local_enuErrorState=ES_OK;
	}
	else
	{
		Local_enuErrorState=ES_OUT_OF_RANGE;
	}
	return Local_enuErrorState;
}


ES_t DIO_enuget_PortValue(u8 copy_u8PortId,u8 *copy_pu8PortValue)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(copy_pu8PortValue!=NULL )
	{
		if(copy_u8PortId<=DIO_PORTD)
			{
				switch(copy_u8PortId)
				{
				case(DIO_PORTA):
					*copy_pu8PortValue=PINA;
					break;
				case(DIO_PORTB):
					*copy_pu8PortValue=PINB;
					break;
				case(DIO_PORTC):
					*copy_pu8PortValue=PINC;
					break;
				case(DIO_PORTD):
					*copy_pu8PortValue=PIND;
				    break;
				}
				Local_enuErrorState=ES_OK;

			}
		else
		{
			Local_enuErrorState=ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorState=ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}


ES_t DIO_enuToggle_PortValue(u8 copy_u8PortId)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(copy_u8PortId<=DIO_PORTD)
		{
			switch(copy_u8PortId)
			{
			case(DIO_PORTA):
				PORTA=~PORTA;
				break;
			case(DIO_PORTB):
				PORTB=~PORTB;
				break;
			case(DIO_PORTC):
				PORTC=~PORTC;
				break;
			case(DIO_PORTD):
				PORTD=~PORTD;
			    break;
			}
			Local_enuErrorState=ES_OK;
		}
		else
		{
			Local_enuErrorState=ES_OUT_OF_RANGE;
		}

	return Local_enuErrorState;
}






ES_t DIO_enuSet_PinValue(u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8PinValue)

{
	ES_t Local_enuErrorState = ES_NOK;

	if(copy_u8PortId <= DIO_PORTD && copy_u8PinId <= DIO_PIN7 && copy_u8PinValue <= OUTPUT)
	{
		switch(copy_u8PortId)
		{
			case(DIO_PORTA):
			PORTA&=~(DIO_BIT_MUSK<<copy_u8PinId);
			PORTA|=(copy_u8PinValue<<copy_u8PinId);
			break;
			case(DIO_PORTB):
			PORTB&=~(DIO_BIT_MUSK<<copy_u8PinId);
			PORTB|=(copy_u8PinValue<<copy_u8PinId);
			break;
			case(DIO_PORTC):
			PORTC&=~(DIO_BIT_MUSK<<copy_u8PinId);
			PORTC|=(copy_u8PinValue<<copy_u8PinId);
			break;
			case(DIO_PORTD):
			PORTD&=~(DIO_BIT_MUSK<<copy_u8PinId);
			PORTD|=(copy_u8PinValue<<copy_u8PinId);
			break;
		}
		Local_enuErrorState=ES_OK;
	}
	else
	{
		Local_enuErrorState=ES_OUT_OF_RANGE;
	}


	return Local_enuErrorState;
}

ES_t DIO_enuSet_PinDirection(u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8PinValue)

{
	ES_t Local_enuErrorState = ES_NOK;
	if(copy_u8PortId <= DIO_PORTD && copy_u8PinId <= DIO_PIN7 && copy_u8PinValue <= OUTPUT)
	{
		switch(copy_u8PortId)
		{
			case(DIO_PORTA):
				DDRA&=~(DIO_BIT_MUSK<<copy_u8PinId);
				DDRA|=(copy_u8PinValue<<copy_u8PinId);
			break;
			case(DIO_PORTB):
				DDRB&=~(DIO_BIT_MUSK<<copy_u8PinId);
				DDRB|=(copy_u8PinValue<<copy_u8PinId);
			break;
			case(DIO_PORTC):
				DDRC&=~(DIO_BIT_MUSK<<copy_u8PinId);
				DDRC|=(copy_u8PinValue<<copy_u8PinId);
			break;
			case(DIO_PORTD):
				DDRD&=~(DIO_BIT_MUSK<<copy_u8PinId);
				DDRD|=(copy_u8PinValue<<copy_u8PinId);
			break;
		}
		Local_enuErrorState=ES_OK;
	}
	else
	{
		Local_enuErrorState=ES_OUT_OF_RANGE;
	}


	return Local_enuErrorState;
}

ES_t DIO_enuget_PinValue(u8 copy_u8PortId,u8 copy_u8PinId,u8 *copy_pu8PinValue)

{
	ES_t Local_enuErrorState = ES_NOK;
	if(copy_pu8PinValue==NULL){
	if(copy_u8PortId <= DIO_PORTD && copy_u8PinId <= DIO_PIN7 )
		{
		  switch(copy_u8PortId)
		{
		 case(DIO_PORTA):
			*copy_pu8PinValue=((PINA>>copy_u8PinId)&DIO_BIT_MUSK);
		    break;
		 case(DIO_PORTB):
			*copy_pu8PinValue=((PINB>>copy_u8PinId)&DIO_BIT_MUSK);
		    break;
		 case(DIO_PORTC):
			*copy_pu8PinValue=((PINC>>copy_u8PinId)&DIO_BIT_MUSK);
			break;
		 case(DIO_PORTD):
			*copy_pu8PinValue=((PIND>>copy_u8PinId)&DIO_BIT_MUSK);
			break;
		}
		Local_enuErrorState=ES_OK;
		}
	else
		{
			Local_enuErrorState=ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorState=ES_NULL_POINTER;
	}


	return Local_enuErrorState;
}
ES_t DIO_enuToggle_PinValue(u8 copy_u8PortId,u8 copy_u8PinId)
{

	ES_t Local_enuErrorState = ES_NOK;
	if(copy_u8PortId <= DIO_PORTD && copy_u8PinId <= DIO_PIN7 )
	{
		switch(copy_u8PortId)
		{
		case(DIO_PORTA):
		  PORTA^=(DIO_BIT_MUSK<<copy_u8PinId);
		  break;
		case(DIO_PORTB):
		 PORTB^=(DIO_BIT_MUSK<<copy_u8PinId);
		  break;
		case(DIO_PORTC):
		 PORTC^=(DIO_BIT_MUSK<<copy_u8PinId);
		  break;
		case(DIO_PORTD):
		 PORTD^=(DIO_BIT_MUSK<<copy_u8PinId);
		  break;
		}
		Local_enuErrorState=ES_OK;
	}
	else
	{
		Local_enuErrorState=ES_OUT_OF_RANGE;
	}


	return Local_enuErrorState;
}
