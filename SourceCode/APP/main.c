/*
 * main.c
 *
 *  Created on: May 28, 2024
 *      Author: ahmed
 */

#include "main.h"

extern u8 EEPROM_counter;

extern BOOL OffFlage;

int main(){
	u8 UserSetTemp, set_speed;

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
	//ButtonsInit();

	//EEPROM initialize
	EEPROM_Init();

	//OFFOPTION initialize
	OFFOPTION_init();

	while(1){
		UserSetTemp = EEPROM_counter;

		SS_writeNum(UserSetTemp);

		//SS_writeNum(EEPROM_counter);
		set_speed = ((TEMPCheckStart()/(TEMPCheckStart()+UserSetTemp))*255);
		//Real temp is higher than User set temp
		if(TEMPCheckStart()>UserSetTemp){
			CoolingChoise(set_speed);
			HeatingChoise(HEATINGSTOP);
		}
		//Real temp is Lower than User set temp
		else if(TEMPCheckStart()<UserSetTemp){
			HeatingChoise(set_speed);
			CoolingChoise(COOLINGSTOP);
		}
		//Real temp is Equal to User set temp
		else if(TEMPCheckStart()==UserSetTemp || OffFlage==TRUE){
			HeatingChoise(HEATINGSTOP);
			CoolingChoise(COOLINGSTOP);
		}
	}
	return 0;
}
