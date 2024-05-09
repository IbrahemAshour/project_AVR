/*
 * S_Segment_priv.h
 *
 *  Created on: 28 Oct 2023
 *      Author: Alaraby
 */

#ifndef S_SEGMENT_PRIV_H_
#define S_SEGMENT_PRIV_H_

#define COMMON_ANODE   1
#define COMMON_CATHODE   4

#define NOT_CONNECTED  11
#define CONNECTED  	   22
u8 SEG_Au8DiaplayNum[]={0x3F,0x06,0x5B,
				  0x4F,0x66,0x6D,0x7D,
				  0x07,0x7F,0x6F
				 };
#define Pin0 0
#define Pin1 1
#define Pin2 2
#define Pin3 3
#define Pin4 4
#define Pin5 5
#define Pin6 6
#define Pin7 7

#define Get_State_Num 1
#endif /* S_SEGMENT_PRIV_H_ */
