/*
 * Timer.h
 *
 * Created: 06/11/2019 02:45:08 م
 *  Author: DR.LAP
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#define TIMER_PRESCALER_1 1
#define TIMER_PRESCALER_8 2
#define TIMER_PRESCALER_64 3
#define TIMER_PRESCALER_256 4
#define TIMER_PRESCALER_1024 5

void TIM0_OVF_Init(uint8_t prescaler, uint8_t Init_Ticks);
void TIM0_CTC_Init(uint8_t prescaler, uint8_t Init_Ticks);
void TIM1_OVF_Init(uint8_t prescaler, uint16_t Init_Ticks);
void TIM1_CTC_Init(uint8_t prescaler, uint16_t Init_Ticks);


#endif /* TIMER_H_ */