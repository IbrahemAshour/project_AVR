/*
 * GIE_prog.c
 *
 *  Created on: 17 Dec 2023
 *      Author: Alaraby
 */
#include "../LIBERARY/stdTypes.h"
#include "../LIBERARY/Error_State.h"
#include "GIE_priv.h"
#include "GIE_int.h"

ES_t GIE_enuEnable(void)
{
	u8 Local_u8ErrorState = ES_OK;

	SREG |=(1<<SREG_I);
	return Local_u8ErrorState;
}
ES_t GIE_enuDisable(void)
{
	u8 Local_u8ErrorState = ES_OK;
	SREG &= ~(1<< SREG_I);
	return Local_u8ErrorState;
}
