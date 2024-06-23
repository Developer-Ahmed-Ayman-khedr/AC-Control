/*
 * BUTTON_PROG.c
 *
 *  Created on: Jun 1, 2024
 *      Author: ahmed
 */


#include "BUTTONS_INT.h"

u8 EEPROM_counter;

BOOL onoffstate = FALSE;

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

void OnOff_Button(){
	if(onoffstate==FALSE){
		onoffstate = TRUE;
	}
	else if(onoffstate==TRUE){
		onoffstate = FALSE;
		SS_deinit();
	}
}

void ButtonsInit(){

	GI_enable();

	//Initialize External Interrupt 0 for Up Button
	DIO_setPinDir(DIO_PIND2,DIO_INPUT);
	EXT_int0Int(EXT_RISING);
	EXT_setcallbackInt0(Up_Button);

	//Initialize External Interrupt 1 for Down Button
	DIO_setPinDir(DIO_PIND3,DIO_INPUT);
	EXT_int1Int(EXT_RISING);
	EXT_setcallbackInt1(Down_Button);

	//Initialize External Interrupt 1 for ON-OFF Button
	DIO_setPinDir(DIO_PINB2,DIO_INPUT);
	EXT_int2Int(EXT_RISING);
	EXT_setcallbackInt2(OnOff_Button);

	//Set initial value for EEPROM
	//EEPROM_SendByte(30,0x10);

	//Get saved temperature
	EEPROM_ReadByteNACK(&EEPROM_counter,0x10);
	_delay_ms(100);
	UART_sendNum(EEPROM_counter);

}

u8 ButtunsReturnEEPROM(){
	return EEPROM_counter;
}

BOOL ButtunsReturnonoffstate(){
	return onoffstate;
}
