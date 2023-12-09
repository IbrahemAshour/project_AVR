///*
// * APP.c
// *
// *  Created on: 7 Dec 2023
// *      Author: Ibrahem Ashour
// */
#include "stdTypes.h"
#include "Error_State.h"
#include "APP.h"

u8 Local_u8IsDigit(u8 Copy_u8Digit)
{
	if(Copy_u8Digit >= '0' && Copy_u8Digit <= '9')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
u8 Local_u8IsOperand(u8 Copy_u8Operand)
{
	if(Copy_u8Operand == '+' ||Copy_u8Operand == '-' || Copy_u8Operand == '/' || Copy_u8Operand == '*'  )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


