/*
 * S_Segment_int.h
 *
 *  Created on: 28 Oct 2023
 *      Author: Alaraby
 */

#ifndef S_SEGMENT_INT_H_
#define S_SEGMENT_INT_H_

ES_t S_Segment_enuInit(void);

ES_t S_Segment_enuDisplayNum(u8 Copy_u8Num);

ES_t S_Segment_enuEnableCommon(void);

ES_t S_Segment_enuEnableCathod(void);

ES_t S_Segment_enuEnableDot(void);

ES_t S_Segment_enuDisableDot(void);

ES_t S_Segmet_enuClearDisplay(void);
#endif /* S_SEGMENT_INT_H_ */
