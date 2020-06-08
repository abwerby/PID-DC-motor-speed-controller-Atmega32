/*
 * Timer.c
 *
 * Created: 06/11/2019 02:44:46 م
 *  Author: DR.LAP
 */ 

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include "std_macros.h"
#include "Timer.h"


void TIM0_CTC_Init(uint8_t prescaler, uint8_t Init_Ticks)
{

	/* set ctc mode */
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);

	/* set timer count */
	OCR0 = Init_Ticks ; // Example: 256 or 1024


	/* set  pin OC0 mode */
	CLR_BIT(TCCR0,COM00);
	CLR_BIT(TCCR0,COM01);


	/* set prescaller */

	switch (prescaler)
	{
		case 1 :
		SET_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
		break;
		case 2 :
		CLR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
		break;
		case 3 :
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
		break;

		case 4 :
		CLR_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;

		case 5 :
		SET_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;
	}

	SET_BIT(TIMSK,OCIE0);
	sei();
}


void TIM0_OVF_Init(uint8_t prescaler, uint8_t Init_Ticks)
{

	/* set normal mode */
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);

	/* set timer count */
	TCNT0 = Init_Ticks ;

	/* set prescaller */

	switch (prescaler)
	{
		case 1 :
		SET_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
		break;
		
		case 2 :
		CLR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
		break;
		
		case 3 :
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
		break;

		case 4 :
		CLR_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;

		case 5 :
		SET_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;
	}

	SET_BIT(TIMSK,TOIE0);
	sei();
}

void TIM0_Stop()
{
	TCCR0 = 0;
}


void TIM1_OVF_Init(uint8_t prescaler, uint16_t Init_Ticks)
{
	/* set normal mode */
	CLR_BIT(TCCR1A,WGM00);
	CLR_BIT(TCCR1A,WGM01);

	/* set timer count */
	TCNT1 = Init_Ticks ;

	/* set prescaller */

	switch (prescaler)
	{
		case 1 :
		SET_BIT(TCCR1B,CS10);
		CLR_BIT(TCCR1B,CS11);
		CLR_BIT(TCCR1B,CS12);
		break;

		case 2 :
		CLR_BIT(TCCR1B,CS00);
		SET_BIT(TCCR1B,CS11);
		CLR_BIT(TCCR1B,CS12);
		break;

		case 3 :
		SET_BIT(TCCR1B,CS00);
		SET_BIT(TCCR1B,CS11);
		CLR_BIT(TCCR1B,CS12);
		break;

		case 4 :
		CLR_BIT(TCCR1B,CS00);
		CLR_BIT(TCCR1B,CS11);
		SET_BIT(TCCR1B,CS12);
		break;

		case 5 :
		SET_BIT(TCCR1B,CS00);
		CLR_BIT(TCCR1B,CS11);
		SET_BIT(TCCR1B,CS12);
		break;
	}

	SET_BIT(TIMSK,TOIE1);
	sei();
}

void TIM1_CTC_Init(uint8_t prescaler, uint16_t Init_Ticks)
{
	/* set CTC mode */
	CLR_BIT(TCCR1A,WGM00);
	CLR_BIT(TCCR1A,WGM01);
	SET_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);

	/* set timer count */
	OCR1A = Init_Ticks ;

	/* set  pin OC0 mode */
	CLR_BIT(TCCR1A,COM1A0);
	CLR_BIT(TCCR1A,COM1A1);


	/* set prescaller */

	switch (prescaler)
	{
		case 1 :
		SET_BIT(TCCR1B,CS10);
		CLR_BIT(TCCR1B,CS11);
		CLR_BIT(TCCR1B,CS12);
		break;

		case 2 :
		CLR_BIT(TCCR1B,CS00);
		SET_BIT(TCCR1B,CS11);
		CLR_BIT(TCCR1B,CS12);
		break;

		case 3 :
		SET_BIT(TCCR1B,CS00);
		SET_BIT(TCCR1B,CS11);
		CLR_BIT(TCCR1B,CS12);
		break;

		case 4 :
		CLR_BIT(TCCR1B,CS00);
		CLR_BIT(TCCR1B,CS11);
		SET_BIT(TCCR1B,CS12);
		break;

		case 5 :
		SET_BIT(TCCR1B,CS00);
		CLR_BIT(TCCR1B,CS11);
		SET_BIT(TCCR1B,CS12);
		break;
	}

	SET_BIT(TIMSK,OCIE1A);
	sei();
}

void TIM1_Stop()
{
	TCCR1A = 0;
}
