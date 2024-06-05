/*
 * BUTTON_PROG.c
 *
 *  Created on: Jun 1, 2024
 *      Author: ahmed
 */


#include "BUTTONS_INT.h"

u8 EEPROM_counter;

extern u32 OvCounter;

void Up_Button(){
	OvCounter = 0;
	EEPROM_ReadByteNACK(&EEPROM_counter,0x10);
	_delay_ms(100);
	EEPROM_counter++;
	EEPROM_SendByte(EEPROM_counter,0x10);
	_delay_ms(100);
	UART_sendNum(EEPROM_counter);
}

void Down_Button(){
	OvCounter = 0;
	EEPROM_ReadByteNACK(&EEPROM_counter,0x10);
	_delay_ms(100);
	EEPROM_counter--;
	EEPROM_SendByte(EEPROM_counter,0x10);
	_delay_ms(100);
	UART_sendNum(EEPROM_counter);
}

void ButtonsInit(){

	GI_enable();

	//Initialize External Interrupt 0 for Up Button
	EXT_int0Int(EXT_RISING);

	//Initialize External Interrupt 1 for Down Button
	EXT_int1Int(EXT_RISING);

	//Up Button
	EXT_setcallbackInt0(Up_Button);

	//Down Button
	EXT_setcallbackInt1(Down_Button);

	//Get saved temperature
	EEPROM_ReadByteNACK(&EEPROM_counter,0x10);
	_delay_ms(100);
	UART_sendNum(EEPROM_counter);

}
