/*
 * BUTTON_PROG.c
 *
 *  Created on: Jun 1, 2024
 *      Author: ahmed
 */


#include "BUTTONS_INT.h"

u8 counter = 0;

void Up_Button(){
	counter++;
	UART_sendNum(counter);
}

void Down_Button(){
	counter--;
	UART_sendNum(counter);
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
}


u8 ButtonsPushed(){
	return counter;
}
