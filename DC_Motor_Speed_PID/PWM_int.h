/*
 * PWM_int.h
 *
 *  Created on: Nov 23, 2018
 *      Author: abood
 */

#ifndef PWM_INT_H_
#define PWM_INT_H_

#define OC1A 0
#define OC1B 1


#define TIMER_PRESCALER_1 1
#define TIMER_PRESCALER_8 2
#define TIMER_PRESCALER_64 3
#define TIMER_PRESCALER_256 4
#define TIMER_PRESCALER_1024 5


void Fast_PWM0_init(uint8_t prescaler , uint8_t value);
void Fast_PWM1_init(uint8_t prescaler , uint16_t value , uint8_t pin);
void Fast_PWM2_init(uint8_t prescaler , uint8_t value);




#endif /* PWM_INT_H_ */
