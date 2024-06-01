/*
 * main.c
 *
 *  Created on: May 28, 2024
 *      Author: ahmed
 */

#include "main.h"

int main(){

	//Temperature initialize
	TEMPCheckInit();

	//SevenSegment initialize
	SS_init();

	//UART initialize
	UART_init();

	//Heating Motor initialize
	HeatingInit();

	//Cooling Motor initialize
	CoolingInit();

	//Buttons initialize
	ButtonsInit();

	u8 MainFlage = 0, UserSetTemp;
	while(1){

		UserSetTemp = ButtonsPushed();

		SS_writeNum(TEMPCheckStart());

		switch(MainFlage){
		case 1:
			//Real temp is higher than User set temp
			if(TEMPCheckStart()>UserSetTemp){
				CoolingChoise(COOLINGSTART);
				HeatingChoise(HEATINGSTOP);
			}
			MainFlage = 2;
			break;
		case 2:
			//Real temp is Lower than User set temp
			if(TEMPCheckStart()<UserSetTemp){
				HeatingChoise(HEATINGSTART);
				CoolingChoise(COOLINGSTOP);
			}
			break;
		case 3:
			//Real temp is Equal to User set temp
			if(TEMPCheckStart()==UserSetTemp){
				HeatingChoise(HEATINGSTOP);
				CoolingChoise(COOLINGSTOP);
			}
			break;
		default:
			break;
		}
	}
	return 0;
}
