/*
 * BUTTON_PROG.c
 *
 *  Created on: Jun 1, 2024
 *      Author: ahmed
 */


#include "BUTTONS_INT.h"

u8 EEPROM_counter ;



void Up_Button(){
	EEPROM_ReadByteNACK(&EEPROM_counter,0x1);
	_delay_ms(100);
	EEPROM_counter++;
	EEPROM_SendByte(EEPROM_counter,0x1);
	_delay_ms(100);
	UART_sendNum(EEPROM_counter);
}

void Down_Button(){
	EEPROM_ReadByteNACK(&EEPROM_counter,0x1);
	_delay_ms(100);
	EEPROM_counter--;
	EEPROM_SendByte(EEPROM_counter,0x1);
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
	EEPROM_ReadByteNACK(&EEPROM_counter,0x1);
	_delay_ms(100);
	UART_sendNum(EEPROM_counter);

}


void ButtonsPushed(u8* UserSetTemp_ptr){
	*UserSetTemp_ptr = EEPROM_counter;
}
