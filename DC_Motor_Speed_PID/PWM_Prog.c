/*
 * PWM_Prog.c
 *
 *  Created on: Nov 23, 2018
 *      Author: abood
 */

#include <stdint.h>
#include "avr/io.h"
#include "std_macros.h"
#include "PWM_int.h"

void Fast_PWM0_init(uint8_t prescaler , uint8_t value)
{

	/* set PWM mode */
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);

	/* set timer count */
	OCR0 = value ;


	/* set  pin OC0 mode */
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);



	/* set prescaler */
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

}



void Fast_PWM1_init(uint8_t prescaler , uint16_t value , uint8_t pin)
{


	switch(pin)
	{
	case OC1A :
		CLR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);

		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);

		CLR_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);

		OCR1A = value ;

		break;
	case OC1B :
		CLR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);

		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);

		OCR1B = value ;

		CLR_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1B1);
		break;
	}



	/* set prescaler */
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

	/* set top value*/
	ICR1 = 1023 ;

}

void Fast_PWM2_init(uint8_t prescaler , uint8_t value)
{

	/* set PWM mode */
	SET_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);

	/* set timer count */
	OCR2 = value ;


	/* set  pin OC2 mode */
	CLR_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);



	/* set prescaler */
	switch (prescaler)
	{
		case 1 :
		SET_BIT(TCCR2,CS20);
		CLR_BIT(TCCR2,CS21);
		CLR_BIT(TCCR2,CS22);
		break;
		case 2 :
		CLR_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		CLR_BIT(TCCR2,CS22);
		break;
		case 3 :
		SET_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		CLR_BIT(TCCR2,CS22);
		break;

		case 4 :
		CLR_BIT(TCCR2,CS20);
		CLR_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);
		break;

		case 5 :
		SET_BIT(TCCR2,CS20);
		CLR_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);
		break;
	}

}
