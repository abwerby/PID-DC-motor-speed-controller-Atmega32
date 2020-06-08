/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
#ifndef _DIO_INT_H
#define _DIO_INT_H

/* Port Defines */
#define PORTA    0
#define PORTB    1
#define PORTC    2
#define PORTD    3

/* PIN Defines */
#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7

/* PIN Directions */
#define INPUT  0x00
#define OUTPUT 0xFF

/* PIN Value Options */
#define HIGH   0xFF
#define LOW    0x00

/* IO Pins */

uint8_t DIO_u8GetPinValue(uint8_t PortId , uint8_t PinNumber) ;
void DIO_VidSetPinValue(uint8_t PortId , uint8_t Pin , uint8_t Value);
void DIO_VidSetPinDirection(uint8_t PortId , uint8_t Pin , uint8_t Value);




/* IO Ports */

uint8_t DIO_u8GetPortValue(uint8_t PortId);
void DIO_VidSetPortValue(uint8_t PortId , uint8_t Value);
void DIO_VidSetPortDirection(uint8_t PortId , uint8_t Value);




#endif
