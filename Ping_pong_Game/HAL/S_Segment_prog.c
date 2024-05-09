/*
 * S_Segment_prog.c
 *
 *  Created on: 28 Oct 2023
 *      Author: Alaraby
 */
#include "E:\AVR_Projects\TAsk_Interuupt\stdTypes.h"
#include "E:\AVR_Projects\TAsk_Interuupt\Error_State.h"
#include "E:\AVR_Projects\TAsk_Interuupt\MCAL\DIO_int.h"
#include "S_Segment_config.h"
#include "S_Segment_priv.h"

ES_t S_Segment_enuInit(void)
{
	ES_t Local_enuErrorState=ES_NOK;
	u32 Local_u32Check=0;
	Local_u32Check  =  DIO_enuSet_PinDirection(SEG_APORT , SEG_APIN , DIO_u8OUTPUT);
	Local_u32Check |= (DIO_enuSet_PinDirection(SEG_BPORT , SEG_BPIN , DIO_u8OUTPUT)<<3);
	Local_u32Check |= (DIO_enuSet_PinDirection(SEG_CPORT , SEG_CPIN , DIO_u8OUTPUT)<<6);
	Local_u32Check |= (DIO_enuSet_PinDirection(SEG_DPORT , SEG_DPIN , DIO_u8OUTPUT)<<9);
	Local_u32Check |= (DIO_enuSet_PinDirection(SEG_EPORT , SEG_EPIN , DIO_u8OUTPUT)<<12);
	Local_u32Check |= (DIO_enuSet_PinDirection(SEG_FPORT , SEG_FPIN , DIO_u8OUTPUT)<<15);
	Local_u32Check |= ((u8)DIO_enuSet_PinDirection(SEG_GPORT , SEG_GPIN , DIO_u8OUTPUT)<<18);
 u8 Local_u8Ilit=0;
 for(Local_u8Ilit=0 ; Local_u8Ilit < sizeof(Local_u8Ilit)*8 ; Local_u8Ilit+=3)
 {
	 if( ( ( (Local_u32Check)>>Local_u8Ilit) &7 ) !=ES_OK )
	 {
		 return Local_enuErrorState;
	 }
	 else
	 {
		 Local_enuErrorState=ES_OK;
	 }
 }

#if SEG_CMN<=DIO_u8PIN7 && SEG_CMNPORT<=DIO_u8PORTD
	DIO_enuSet_PinDirection(SEG_CMNPORT , SEG_CMN , DIO_u8OUTPUT);
#elif SEG_CMN==NOT_CONNECTED && SEG_CMNPORT==NOT_CONNECTED
#else
#error"Your Input Common Pin is out of Range"
#endif

#if SEG_DOT<=DIO_u8PIN7 && SEG_DOTPORT<=DIO_u8PORTD
	DIO_enuSet_PinDirection(SEG_DOTPORT , SEG_DOT , DIO_u8OUTPUT);
#elif SEG_DOT==NOT_CONNECTED || SEG_DOTPORT==NOT_CONNECTED
#else
#error"Your Input Dot Pin is out of Range"
#endif

	return Local_enuErrorState;
}


ES_t S_Segment_enuDisplayNum(u8 Copy_u8Num)
{
	ES_t Local_enuErrorState=ES_NOK;
	u32 Local_u32Check=0;
	if(Copy_u8Num<10)
	{
#if SEG_TYPE==COMMON_CATHODE
		Local_u32Check  =DIO_enuSet_PinValue(SEG_APORT , SEG_APIN , ((SEG_Au8DiaplayNum[Copy_u8Num]>>Pin0 ) &Get_State_Num));
		Local_u32Check |=DIO_enuSet_PinValue(SEG_BPORT , SEG_BPIN , ((SEG_Au8DiaplayNum[Copy_u8Num]>>Pin1 ) &Get_State_Num));
		Local_u32Check |=DIO_enuSet_PinValue(SEG_CPORT , SEG_CPIN , ((SEG_Au8DiaplayNum[Copy_u8Num]>>Pin2 ) &Get_State_Num));
		Local_u32Check |=DIO_enuSet_PinValue(SEG_DPORT , SEG_DPIN , ((SEG_Au8DiaplayNum[Copy_u8Num]>>Pin3 ) &Get_State_Num));
		Local_u32Check |=DIO_enuSet_PinValue(SEG_EPORT , SEG_EPIN , ((SEG_Au8DiaplayNum[Copy_u8Num]>>Pin4 ) &Get_State_Num));
		Local_u32Check |=DIO_enuSet_PinValue(SEG_FPORT , SEG_FPIN , ((SEG_Au8DiaplayNum[Copy_u8Num]>>Pin5 ) &Get_State_Num));
		Local_u32Check |=DIO_enuSet_PinValue(SEG_GPORT , SEG_GPIN , ((SEG_Au8DiaplayNum[Copy_u8Num]>>Pin6 ) &Get_State_Num));
#elif SEG_TYPE==COMMON_ANODE
		Local_u32Check  =DIO_enuSet_PinValue(SEG_APORT , SEG_APIN , !((SEG_Au8DiaplayNum[Copy_u8Num]>>Pin0 ) &Get_State_Num));
		Local_u32Check |=DIO_enuSet_PinValue(SEG_BPORT , SEG_BPIN , !((SEG_Au8DiaplayNum[Copy_u8Num]>>Pin1 ) &Get_State_Num));
		Local_u32Check |=DIO_enuSet_PinValue(SEG_CPORT , SEG_CPIN , !((SEG_Au8DiaplayNum[Copy_u8Num]>>Pin2 ) &Get_State_Num));
		Local_u32Check |=DIO_enuSet_PinValue(SEG_DPORT , SEG_DPIN , !((SEG_Au8DiaplayNum[Copy_u8Num]>>Pin3 ) &Get_State_Num));
		Local_u32Check |=DIO_enuSet_PinValue(SEG_EPORT , SEG_EPIN , !((SEG_Au8DiaplayNum[Copy_u8Num]>>Pin4 ) &Get_State_Num));
		Local_u32Check |=DIO_enuSet_PinValue(SEG_FPORT , SEG_FPIN , !((SEG_Au8DiaplayNum[Copy_u8Num]>>Pin5 ) &Get_State_Num));
		Local_u32Check |=DIO_enuSet_PinValue(SEG_GPORT , SEG_GPIN , !((SEG_Au8DiaplayNum[Copy_u8Num]>>Pin6 ) &Get_State_Num));
#else
#error "SEG TYPE NOT AVALILABLE !!"
#endif
		u8 Local_u8Ilit=0;
		 for(Local_u8Ilit=0 ; Local_u8Ilit < sizeof(Local_u8Ilit)*8 ; Local_u8Ilit+=3)
		 {
			 if( ( ( (Local_u32Check)>>Local_u8Ilit) &7 ) !=ES_OK )
			 {
				 return Local_enuErrorState;
			 }
			 else
			 {
				 Local_enuErrorState=ES_OK;
			 }
		 }

	}
	return Local_enuErrorState;
}



ES_t S_Segment_enuEnableCommon(void)
{
	ES_t Local_enuErrorState=ES_NOK;
#if SEG_CMN<=DIO_u8PIN7 && SEG_CMNPORT<=DIO_u8PORTD
	#if SEG_TYPE==COMMON_CATHODE
		Local_enuErrorState=DIO_enuSetPinValue(SEG_CMNPORT , SEG_CMN ,DIO_u8LOW );
	#elseif  SEG_TYPE==COMMON_ANODE
		Local_enuErrorState=DIO_enuSetPinValue(SEG_CMNPORT , SEG_CMN ,DIO_u8HIGH );
	#else
	#error "SEG TYPE NOT AVALILABLE !!"
	#endif
#elif SEG_CMN==NOT_CONNECTED || SEG_CMNPORT==NOT_CONNECTED
#else
#error"Your Input Common Pin is out of Range"
#endif
	return Local_enuErrorState;
}

ES_t S_Segment_enudisableCommon(void)
{
	ES_t Local_enuErrorState=ES_NOK;
#if SEG_CMN<=DIO_u8PIN7 && SEG_CMNPORT<=DIO_u8PORTD
	#if SEG_TYPE==COMMON_CATHODE
		Local_enuErrorState=DIO_enuSetPinValue(SEG_CMNPORT , SEG_CMN ,DIO_u8HIGH );
	#elseif  SEG_TYPE==COMMON_ANODE
		Local_enuErrorState=DIO_enuSetPinValue(SEG_CMNPORT , SEG_CMN ,DIO_u8LOW );
	#else
	#error "SEG TYPE NOT AVALILABLE !!"
	#endif
#elif SEG_CMN==NOT_CONNECTED || SEG_CMNPORT==NOT_CONNECTED
#else
#error"Your Input Common Pin is out of Range"
#endif
	return Local_enuErrorState;
}

ES_t S_Segment_enuEnableDot(void)
{
	ES_t Local_enuErrorState=ES_NOK;
#if SEG_DOT<=DIO_u8PIN7 && SEG_DOTPORT<=DIO_u8PORTD
	#if SEG_TYPE==COMMON_CATHODE
		Local_enuErrorState=DIO_enuSetPinValue(SEG_DOTPORT , SEG_DOT ,DIO_u8HIGH );
	#elseif  SEG_TYPE==COMMON_ANODE
		Local_enuErrorState=DIO_enuSetPinValue(SEG_DOTPORT , SEG_DOT ,DIO_u8LOW );
	#else
	#error "SEG TYPE NOT AVALILABLE !!"
	#endif
#elif SEG_CMN==NOT_CONNECTED || SEG_CMNPORT==NOT_CONNECTED
#else
#error"Your Input DOT Pin is out of Range"
#endif
	return Local_enuErrorState;
}

ES_t S_Segment_enuDisableDot(void)
{
	ES_t Local_enuErrorState=ES_NOK;
#if SEG_CMN<=DIO_u8PIN7 && SEG_CMNPORT<=DIO_u8PORTD
	#if SEG_TYPE==COMMON_CATHODE
		Local_enuErrorState=DIO_enuSetPinValue(SEG_CMNPORT , SEG_CMN ,DIO_u8LOW );
	#elseif  SEG_TYPE==COMMON_ANODE
		Local_enuErrorState=DIO_enuSetPinValue(SEG_CMNPORT , SEG_CMN ,DIO_u8HIGH );
	#else
	#error "SEG TYPE NOT AVALILABLE !!"
	#endif
#elif SEG_CMN==NOT_CONNECTED || SEG_CMNPORT==NOT_CONNECTED
#else
#error"Your Input Common Pin is out of Range"
#endif
	return Local_enuErrorState;
}

ES_t S_Segmet_enuClearDisplay(void)
{
	ES_t Local_enuErrorState=ES_NOK;
	u32 Local_u32Check=0;


	#if SEG_TYPE==COMMON_CATHODE
			Local_u32Check  =DIO_enuSet_PinValue(SEG_APORT , SEG_APIN , DIO_u8LOW);
			Local_u32Check |=DIO_enuSet_PinValue(SEG_BPORT , SEG_BPIN , DIO_u8LOW);
			Local_u32Check |=DIO_enuSet_PinValue(SEG_CPORT , SEG_CPIN , DIO_u8LOW);
			Local_u32Check |=DIO_enuSet_PinValue(SEG_DPORT , SEG_DPIN , DIO_u8LOW);
			Local_u32Check |=DIO_enuSet_PinValue(SEG_EPORT , SEG_EPIN , DIO_u8LOW);
			Local_u32Check |=DIO_enuSet_PinValue(SEG_FPORT , SEG_FPIN , DIO_u8LOW);
			Local_u32Check |=DIO_enuSet_PinValue(SEG_GPORT , SEG_GPIN , DIO_u8LOW);
	#elif SEG_TYPE==COMMON_ANODE
			Local_u32Check  =DIO_enuSet_PinValue(SEG_APORT , SEG_APIN , DIO_u8HIGH);
			Local_u32Check |=DIO_enuSet_PinValue(SEG_BPORT , SEG_BPIN , DIO_u8HIGH);
			Local_u32Check |=DIO_enuSet_PinValue(SEG_CPORT , SEG_CPIN , DIO_u8HIGH);
			Local_u32Check |=DIO_enuSet_PinValue(SEG_DPORT , SEG_DPIN , DIO_u8HIGH);
			Local_u32Check |=DIO_enuSet_PinValue(SEG_EPORT , SEG_EPIN , DIO_u8HIGH);
			Local_u32Check |=DIO_enuSet_PinValue(SEG_FPORT , SEG_FPIN , DIO_u8HIGH);
			Local_u32Check |=DIO_enuSet_PinValue(SEG_GPORT , SEG_GPIN , DIO_u8HIGH);
	#else
	#error "SEG TYPE NOT AVALILABLE !!"
	#endif
			u8 Local_u8Ilit=0;
			 for(Local_u8Ilit=0 ; Local_u8Ilit < sizeof(Local_u8Ilit)*8 ; Local_u8Ilit+=3)
			 {
				 if( ( ( (Local_u32Check)>>Local_u8Ilit) &7 ) !=ES_OK )
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
