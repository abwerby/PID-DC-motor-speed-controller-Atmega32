/*
 * DC_Motor_Speed_PID.c
 *
 * Created: 6/2/2020 9:22:52 PM
 * Author : abdelrhman
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdint.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include "Interrupt.h"
#include "std_macros.h"
#include "Timer.h"
#include "DIO_int.h"
#include "PWM_int.h"
#include "LCD_interface.h"

#define Init_ticks 100
#define Time_Interval 0.01
#define PPR 360.0
#define KP 10
#define KI 5
#define KD 0
#define Max_Volt_out 5000
#define Max_PWM_out 1023
#define PWM_VOLT_RATIO 0.2046


volatile uint16_t pulse_count = 0;
uint16_t input_speed = 0;

int16_t Last_Error = 0;
uint32_t speed_rpm ;
uint16_t PWM_Value = 0;
int32_t Volt_Out = 0 ;
uint16_t GOAL = 0;

uint16_t Set_Motor_Speed (uint16_t Req_Speed , uint16_t Motor_Speed );
void init_system();

int main(void)
{
	init_system();
	
    while (1) 
    {
		if (!DIO_u8GetPinValue(PORTB, PIN0))
		{
			while(!DIO_u8GetPinValue(PORTB, PIN0));
			GOAL = input_speed;
		}
		else if (!DIO_u8GetPinValue(PORTB, PIN1))
		{
			while(!DIO_u8GetPinValue(PORTB, PIN1));
			input_speed +=10;
		}
		else if (!DIO_u8GetPinValue(PORTB, PIN2))
		{
			while(!DIO_u8GetPinValue(PORTB, PIN2));
			if (input_speed > 0)
			{
				input_speed -=10;
			}
			else
			{
				input_speed = 0;
			}
			
		}
		Gotoxy(1,0);
		LCD_vidWriteNumber(input_speed);
		Gotoxy(1,4);
		LCD_vidWriteNumber(GOAL);
		Gotoxy(1,10);
		LCD_vidWriteNumber(speed_rpm);
		
    }
}


/* EX PIN ISR to count each pulse from encoder */
ISR(INT0_vect)
{
	pulse_count++;
}


/* TIM0 ISR (every 0.01 second) to calc speed and excute PID function*/
ISR(TIMER0_OVF_vect)
{

	speed_rpm = ((pulse_count/Time_Interval)/PPR)*60.0;   // Speed equation
	PWM_Value = Set_Motor_Speed(GOAL,speed_rpm);          // PID function
	Fast_PWM1_init(TIMER_PRESCALER_256, PWM_Value, OC1A); // PWM to PIN D5
	pulse_count = 0;									  // Reset encoder pulse counter
	TCNT0 = Init_ticks;									  // Reset the TIM0 register to the init ticks 

}


uint16_t Set_Motor_Speed (uint16_t Req_Speed , uint16_t Motor_Speed  )
{
	int16_t Error = 0 ;
	uint16_t PWM = 0 ;
	
	Error = Req_Speed - Motor_Speed ;
	
	int32_t PID = (KP * Error) + ( KI * (Error + Last_Error) * (Time_Interval/2)) + ((KD * (Error - Last_Error)) / Time_Interval);

	Volt_Out = Volt_Out + PID ;

	Last_Error = Error;

	if (Volt_Out >= Max_Volt_out)
	{
		Volt_Out = Max_Volt_out ;
	}
	else if (Volt_Out <=0)
	{
		Volt_Out = 0;
	}
	
	PWM = Volt_Out * PWM_VOLT_RATIO;
	
	return PWM ;
}

void init_system()
{
	DIO_VidSetPortDirection(PORTC, OUTPUT);
	DIO_VidSetPortDirection(PORTA, OUTPUT);
	DIO_VidSetPortDirection(PORTB, INPUT);
	DIO_VidSetPortValue(PORTB, HIGH);
	/* Set Interrupt pin to input */
	DIO_VidSetPinDirection(PORTD, PIN2, INPUT);
	/* active pull up resistor for encoder pin */
	DIO_VidSetPinDirection(PORTD, PIN5, OUTPUT);

	/* INT0 initialization for Rising edge */
	INT0_Init(Rising_Edge);

	/* set timer_0 prescaler to 1024 and init ticks to have 0.01 s sampling time */
	TIM0_OVF_Init(TIMER_PRESCALER_1024, Init_ticks);
		
	LCD_vidInit();
	LCD_vidWriteString("SET:GOAL:CURRENT", 16);
}