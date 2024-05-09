/*
 * EXTI_config.c
 *
 *  Created on: 17 Dec 2023
 *      Author: Alaraby
 */
#include "../LIBERARY/stdTypes.h"
#include "../LIBERARY/Error_State.h"

#include "EXTI_priv.h"
#include "EXTI_config.h"

EXTI_t EXTI_TArrStrInterrt_config[3]=
{
		{DISEABLE},
		{ENABLE,RISING_EDGE},
		{ENABLE,RISING_EDGE}

};
