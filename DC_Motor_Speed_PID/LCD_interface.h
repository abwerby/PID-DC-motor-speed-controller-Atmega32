

#ifndef LCD_H_
#define LCD_H_

#define lcd_Clear           0x01          /* replace all characters with ASCII 'space'                       */
#define lcd_Home            0x02          /* return cursor to first position on first line                   */
#define DataPort			PORTC
#define ControlPort			PORTA 



/***************************************************************************************/
/* Description! Apply initialization sequence for LCD module                           */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidInit(void);

/***************************************************************************************/
/* Description! Interface to send the configuration commands to the LCD Driver         */
/* Input      ! Command number                                                         */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidSendCommand(uint8_t uint8_tCmdCpy);

/***************************************************************************************/
/* Description! Interface to write character on LCD screen                             */
/* Input      ! Data to send                                                           */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteCharctr(uint8_t uint8_tDataCpy);

/***************************************************************************************/
/* Description! Interface to write string on LCD screen                                */
/* Input      ! Pointer to the string                                                  */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteString (uint8_t* puint8_tStringCpy, uint8_t uint8_tIndex);


void Gotoxy (uint8_t Y,uint8_t X);
void LCD_vidWriteExtraChar (uint8_t Y,uint8_t X);
void LCD_vidWriteNumber(long  Number);


#endif /* LCD_H_ */
