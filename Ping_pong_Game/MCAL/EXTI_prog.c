/*
 * EXTI_prog.c
 *
 *  Created on: 17 Dec 2023
 *      Author: Alaraby
 */
#include"../LIBERARY/stdTypes.h"
#include "../LIBERARY/Error_State.h"
#include"EXTI_config.h"
#include"EXTI_priv.h"
#include"EXTI_int.h"
#include "interrupt.h"


static volatile void (*PtoFunc[3])(void)={NULL , NULL , NULL};

ES_t EXTI_enuInit(EXTI_t *Copy_PStr_StatesArray)
{
	u8 Local_u8ErrorState=ES_NOK;
	if(Copy_PStr_StatesArray != NULL)
	{
		u8 Local_u8Itel=0;
		for(Local_u8Itel = 0 ; Local_u8Itel <3 ; Local_u8Itel++)
		{
			if(Copy_PStr_StatesArray[Local_u8Itel].EXTI_u8State == ENABLE)
			{
				Local_u8ErrorState=ES_OK;
				switch(Local_u8Itel)
				{
				case 0:
					GICR |= (1<< GICR_INT0);
					MCUCR &=~(3<<0);
					switch(Copy_PStr_StatesArray[Local_u8Itel].EXTI_u8SenseLevel )
					{
					case FALLING_EDGE:
						MCUCR |= (1<< MCUCR_ISC01);
						break;
					case RISING_EDGE:
						MCUCR |= (1<< MCUCR_ISC01);
						MCUCR |= (1<< MCUCR_ISC00);
						break;
					case ONCHANGE:
						MCUCR &=~(1<< MCUCR_ISC01);
						MCUCR |= (1<< MCUCR_ISC00);
						break;
					case LOW_LEVEL:
						MCUCR &=~(1<< MCUCR_ISC01);
						break;
					}
					break;
					case 1:
						GICR |= (1<< GICR_INT1);
						MCUCR &=~(3<<0);
						switch(Copy_PStr_StatesArray[Local_u8Itel].EXTI_u8SenseLevel )
						{
						case FALLING_EDGE:
							MCUCR |= (1<< MCUCR_ISC11);
							break;
						case RISING_EDGE:
							MCUCR |= (1<< MCUCR_ISC11);
							MCUCR |= (1<< MCUCR_ISC10);
							break;
						case ONCHANGE:
							MCUCR &=~(1<< MCUCR_ISC11);
							MCUCR |= (1<< MCUCR_ISC10);
							break;
						case LOW_LEVEL:
							MCUCR &=~(1<< MCUCR_ISC11);
							break;
						}
						break;
						case 2:
							GICR |= (1<< GICR_INT2);
							switch(Copy_PStr_StatesArray[Local_u8Itel].EXTI_u8SenseLevel )
							{
							case FALLING_EDGE:
								MCUCSR &=~(1<<MCUCSR_ISC2);
								break;
							case RISING_EDGE:
								MCUCSR |= (1<< MCUCSR_ISC2);
								break;
							}
							break;
							default:
								Local_u8ErrorState=ES_OUT_OF_RANGE;
								break;
				}
			}
		}

	}
	else
	{
		Local_u8ErrorState=ES_NULL_POINTER;
	}

	return Local_u8ErrorState;
}
ES_t EXTI_enuChangeSense(u8 Copy_u8Interrupt_ID,u8 Copy_u8SenseLevel)
{
	u8 Local_u8ErrorState=ES_NOK;

	if(Copy_u8Interrupt_ID < 3)
	{
		Local_u8ErrorState=ES_OK;
		if(Copy_u8Interrupt_ID == 0)
		{

			GICR=(1<< GICR_INT0);
			MCUCR &=~(3<<0);
			switch(Copy_u8SenseLevel )
			{
			case FALLING_EDGE:
				MCUCR |= (1<< MCUCR_ISC01);
				break;
			case RISING_EDGE:
				MCUCR |= (1<< MCUCR_ISC01);
				MCUCR |= (1<< MCUCR_ISC00);
				break;
			case ONCHANGE:
				MCUCR &=~(1<< MCUCR_ISC01);
				MCUCR |= (1<< MCUCR_ISC00);
				break;
			case LOW_LEVEL:
				MCUCR &=~(1<< MCUCR_ISC01);
				break;

			}
		}
		if(Copy_u8Interrupt_ID == 1)
		{

			GICR |= (1<< GICR_INT1);
			MCUCR &=~(3<<0);
			switch(Copy_u8SenseLevel )
			{
			case FALLING_EDGE:
				MCUCR |= (1<< MCUCR_ISC11);
				break;
			case RISING_EDGE:
				MCUCR |= (1<< MCUCR_ISC11);
				MCUCR |= (1<< MCUCR_ISC10);
				break;
			case ONCHANGE:
				MCUCR &=~(1<< MCUCR_ISC11);
				MCUCR |= (1<< MCUCR_ISC10);
				break;
			case LOW_LEVEL:
				MCUCR &=~(1<< MCUCR_ISC11);
				break;
			}

		}

		if(Copy_u8Interrupt_ID == 2)
		{

			GICR |= (1<< GICR_INT2);
			switch(Copy_u8SenseLevel )
			{
			case FALLING_EDGE:
				MCUCSR &=~(1<<MCUCSR_ISC2);
				break;
			case RISING_EDGE:
				MCUCSR |= (1<< MCUCSR_ISC2);
				break;
			}

		}
	}

	else
	{
		Local_u8ErrorState = ES_OUT_OF_RANGE;
	}

	return Local_u8ErrorState;
}
ES_t EXTI_enuEnable(u8 Copy_u8Interrupt_ID)
{
	u8 Local_u8ErrorState=ES_NOK;

	switch(Copy_u8Interrupt_ID)
	{
	Local_u8ErrorState = ES_OK;
	case 0:
		GICR |=(1<<GICR_INT0);
		break;
	case 1:
		GICR |=(1<<GICR_INT1);
		break;
	case 2:
		GICR |=(1<<GICR_INT2);
		break;
	default:
		Local_u8ErrorState=ES_OUT_OF_RANGE;
		break;
	}


	return Local_u8ErrorState;
}
ES_t EXTI_enuDisable(u8 Copy_u8Interrupt_ID)
{
	u8 Local_u8ErrorState=ES_NOK;
	switch(Copy_u8Interrupt_ID)
	{
	Local_u8ErrorState = ES_OK;
	case 0:
		GICR &= ~(1<<GICR_INT0);
		break;
	case 1:
		GICR &= ~(1<<GICR_INT1);
		break;
	case 2:
		GICR &= ~(1<<GICR_INT2);
		break;
	default:
		Local_u8ErrorState=ES_OUT_OF_RANGE;
		break;
	}

	return Local_u8ErrorState;
}
ES_t EXTI_enuCall_Back(void (*Copy_PtoFunAPP)(void *),u8 Copy_u8Interrupt_ID)
{
	u8 Local_u8ErrorState=ES_NOK;
	if(Copy_PtoFunAPP != NULL)
	{
		if(Copy_u8Interrupt_ID<3)
		{
			Local_u8ErrorState = ES_OK;

			PtoFunc[Copy_u8Interrupt_ID] =  Copy_PtoFunAPP;
		}
		else
		{
			Local_u8ErrorState = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_u8ErrorState = ES_NULL_POINTER;
	}

	return Local_u8ErrorState;
}
ISR(INT0)
{
	if(PtoFunc[0] != NULL)
	{
		PtoFunc[0]();
	}
}
ISR(INT1)
{
	if(PtoFunc[1] != NULL)
	{
		PtoFunc[1]();
	}
}
ISR(INT2)
{
	if(PtoFunc[2] != NULL)
	{
		PtoFunc[2]();
	}

}
