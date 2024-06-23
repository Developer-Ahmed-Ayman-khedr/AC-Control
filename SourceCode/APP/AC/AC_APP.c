/*
 * AC_APP.c
 *
 *  Created on: Jun 23, 2024
 *      Author: ahmed
 */

#include "AC_APP.h"

void AC_APP(){

	u8 UserSetTemp, set_speed;

	BOOL PROG_STATE = FALSE;

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

	//EEPROM initialize
	EEPROM_Init();

	//Buttons initialize
	ButtonsInit();

	//OFFOPTION initialize
	OFFOPTION_init();

	while(1){

		if(ButtunsReturnonoffstate==TRUE){
			PROG_STATE = TRUE;
		}

		if(PROG_STATE==TRUE){UserSetTemp = ButtunsReturnEEPROM();

			SS_writeNum(UserSetTemp);

			//SS_writeNum(EEPROM_counter);
			set_speed = ((TEMPCheckStart()/(TEMPCheckStart()+UserSetTemp))*255);
			//Real temperature is higher than User set temperature
			if(TEMPCheckStart()>UserSetTemp){
				CoolingChoise(set_speed);
				HeatingChoise(HEATINGSTOP);
			}
			//Real temperature is Lower than User set temperature
			else if(TEMPCheckStart()<UserSetTemp){
				HeatingChoise(set_speed);
				CoolingChoise(COOLINGSTOP);
			}
			//Real temperature is Equal to User set temperature
			else if(TEMPCheckStart()==UserSetTemp || OFFOPTIONReturnOffFlage()==TRUE){
				HeatingChoise(HEATINGSTOP);
				CoolingChoise(COOLINGSTOP);
			}
		}

	}
}
