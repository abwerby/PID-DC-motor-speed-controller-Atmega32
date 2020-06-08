
#include "util/delay.h"

#include "DIO_int.h"
#include "LCD_interface.h"
#include "LCD_Extra.h"
/***************************************************************************************/

/*
 -----------                   ----------
 | ATmega32  |                 |   LCD    |
 |           |                 |          |
 |        PD7|---------------->|D7        |
 |        PD6|---------------->|D6        |
 |        PD5|---------------->|D5        |
 |        PD4|---------------->|D4        |
 |        PD3|---------------->|D3        |
 |        PD2|---------------->|D2        |
 |        PD1|---------------->|D1        |
 |        PD0|---------------->|D0        |
 |           |                 |          |
 |        PA2|---------------->|E         |
 |        PA1|---------------->|RW        |
 |        PA0|---------------->|RS        |
 -----------                   ----------
 */



/***************************************************************************************/
/********************************** Macros *********************************************/
/***************************************************************************************/

#define lcd_Clear           0x01          /* replace all characters with ASCII 'space'                       */
#define lcd_Home            0x02          /* return cursor to first position on first line                   */
#define lcd_EntryMode       0x06          // shift cursor from left to right on read/write
#define lcd_DisplayOff      0x08          // turn display off
#define lcd_DisplayOn       0x0C          // display on, cursor off, don't blink character
#define lcd_FunctionReset   0x30          // reset the LCD
#define lcd_FunctionSet8bit 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor       0x80          // set cursor position

/***************************************************************************************/
/********************************** Constant Variables *********************************/
/***************************************************************************************/



/***************************************************************************************/
/* Description! Apply initialization sequence for LCD module                           */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidInit(void)
{
	/* Delay 30ms to ensure the initialization of the LCD driver */
	_delay_ms(30);

	/* Return Home  */
	LCD_vidSendCommand(lcd_Home);
	_delay_ms(15);

	/* Function Set  */
	LCD_vidSendCommand(lcd_FunctionSet8bit);
	_delay_ms(1);

	/* Display ON OFF Control */
	LCD_vidSendCommand(lcd_DisplayOn);
	_delay_ms(1);

	/* Clear Display */
	LCD_vidSendCommand(lcd_Clear);
	_delay_ms(15);

	/* Entry Mode Set  */
	LCD_vidSendCommand(lcd_EntryMode);
	_delay_ms(2);

}


/***************************************************************************************/
/* Description! Interface to send the configuration commands to the LCD Driver         */
/* Input      ! Command number                                                         */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidSendCommand(uint8_t uint8_tCmdCpy)
{

	/* Set RS to LOW */
	DIO_VidSetPinValue(ControlPort, 0, LOW);

	/* Set R/W to LOW */
	DIO_VidSetPinValue(ControlPort, 1, LOW);

	/* Set E to HIGH  */
	DIO_VidSetPinValue(ControlPort, 2, HIGH);

	/* Load Command on Data bus */
	DIO_VidSetPortValue(DataPort, uint8_tCmdCpy);

	/* Set E to LOW */
	DIO_VidSetPinValue(ControlPort, 2, LOW);

	/* Wait for E to settle */
	_delay_ms(5);

	/* Set E to HIGH */
	DIO_VidSetPinValue(ControlPort, 2, HIGH);

	/* Delay for 10ms to let the LCD execute command */
	_delay_ms(10);

}

/***************************************************************************************/
/* Description! Interface to write character on LCD screen                             */
/* Input      ! Data to send                                                           */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteCharctr(uint8_t uint8_tDataCpy)
{
	/* Set RS to HIG */
	DIO_VidSetPinValue(ControlPort, 0, HIGH);

	/* Set R/W to LOW */
	DIO_VidSetPinValue(ControlPort, 1, LOW);

	/* Set E to HIGH */
	DIO_VidSetPinValue(ControlPort, 2, HIGH);

	/* Load Command on Data bus */
	DIO_VidSetPortValue(DataPort, uint8_tDataCpy);

	/* Set E to LOW */
	DIO_VidSetPinValue(ControlPort, 2, LOW);

	/* Wait for E to settle */
	_delay_ms(5);

	/* Set E to HIGH */
	DIO_VidSetPinValue(ControlPort, 2, HIGH);

	/* Delay to let the LCD Display the character */
	_delay_ms(10);

}

/***************************************************************************************/
/* Description! Interface to write string on LCD screen                                */
/* Input      ! Pointer to the string                                                  */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteString (uint8_t* puint8_tStringCpy, uint8_t uint8_tIndex)
{

//	/* Local loop index */
//	uint8_t uint8_tIndex = 0;
	uint8_t iteration=0;
//	while (puint8_tStringCpy[uint8_tIndex] != '\0')
	for (iteration=0; iteration<uint8_tIndex ; iteration++)
	{

		/* Write Character on LCD */
		LCD_vidWriteCharctr(puint8_tStringCpy[iteration]);

//		/* Increment local loop index */
//		uint8_tIndex++;

		/* Delay to let the LCD show the character */
	}

}

/***************************************************************************************/
/* Description! Interface to start the writing process at certain digit in the LCD     */
/* Input      ! Y = Row position , X = Column position                                 */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void Gotoxy (uint8_t row,uint8_t col)
{
	if (row == 0)
	{
		LCD_vidSendCommand((unsigned) 0x80 | col);
	}
	else if (row == 1)
	{
		LCD_vidSendCommand((unsigned) 0xc0 | col);
	}
}

/***************************************************************************************/
/* Description! Interface to write extra characters saved in the CGRAM                 */
/* Input      ! Y = Row position , X = Column position                                 */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteExtraChar (uint8_t Y,uint8_t X)
{
    uint8_t iteration1,iteration2;

    /*DDRAM-->CGRAM*/
    LCD_vidSendCommand(64);
	for(iteration1=0 ; iteration1<64 ; iteration1++)
	{
		LCD_vidWriteCharctr(ExtraChar[iteration1]);
	}
	/*CGRAM-->DDRAM*/
	LCD_vidSendCommand(128);
	Gotoxy(Y,X);
	/*First eight character which saved at CGRAM*/
	for (iteration2=0; iteration2<=7 ; iteration2++)
	{
		/* Write bytes of DDRAM */
		LCD_vidWriteCharctr(iteration2);

		_delay_ms(5);
	}
}

void LCD_vidWriteNumber(long  Number)
{

	long Temp =1;

	if (Number <= 0)
	{
		LCD_vidWriteCharctr('0');
	}
	else
	{
		while (Number!=0)
		{
			uint8_t Reminder = Number % 10;
			Number = Number / 10 ;
			Temp = Temp * 10 + Reminder ;
		}
		while (Temp != 1)
		{
			uint8_t Reminder2 = Temp % 10 ;
			LCD_vidWriteCharctr(Reminder2 + 48);
			Temp = Temp / 10 ;
		}
	}


}
