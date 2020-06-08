/*
 * Interrupt.c
 *
 * Created: 24/10/2019 08:01:36 م
 *  Author: DR.LAP
 */ 

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include "Interrupt.h"
#include "std_macros.h"



void INT0_Init(uint8_t INT_MODE )
{ 
	/* Set Global Interrupt Enable */
	sei();
	
	/* Enable INT0 */
    SET_BIT(GICR,6);  // 6 INT0

	/* Choose Int Mode */
	if(INT_MODE == Low_Lvl)
	{
		CLR_BIT(MCUCR,0); // 0=ISC00
		CLR_BIT(MCUCR,1); // 1=ISC01
	}
	else if(INT_MODE == Logical_Change)
	{
		SET_BIT(MCUCR,0);
		CLR_BIT(MCUCR,1);
	}
	else if(INT_MODE == Falling_Edge)
	{
		CLR_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
	}
	else if(INT_MODE == Rising_Edge)
	{
		SET_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
	}
	else
	{
		/* DO NOTHING */
	}

}

void INT1_Init(uint8_t INT_MODE )
{
	/* Set Global Interrupt Enable */
	sei();
	
	/* Enable INT1 */
    SET_BIT(GICR,7);

	/* Choose Int Mode */
	if(INT_MODE == Low_Lvl)
	{
		CLR_BIT(MCUCR,2);
		CLR_BIT(MCUCR,3);
	}
	else if(INT_MODE == Logical_Change)
	{
		SET_BIT(MCUCR,2);
		CLR_BIT(MCUCR,3);
	}
	else if(INT_MODE == Falling_Edge)
	{
		CLR_BIT(MCUCR,2);
		SET_BIT(MCUCR,3);
	}
	else if(INT_MODE == Rising_Edge)
	{
		SET_BIT(MCUCR,2);
		SET_BIT(MCUCR,3);
	}
	else
	{
		/* DO NOTHING */
	}
}


void INT2_Init(uint8_t INT_MODE )
{
	/* Set Global Interrupt Enable */
	sei();

    /* Enable INT2 */
    SET_BIT(GICR,5);

	/* Choose Int Mode */
	if(INT_MODE == Falling_Edge)
	{
		CLR_BIT(MCUCR,2);
		SET_BIT(MCUCR,3);
	}
	else if(INT_MODE == Rising_Edge)
	{
		SET_BIT(MCUCR,2);
		SET_BIT(MCUCR,3);
	}
	else
	{
		/* DO NOTHING */
	}

}

