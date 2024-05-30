/*
 * HEATING_PROG.c
 *
 *  Created on: May 30, 2024
 *      Author: ahmed
 */

#include "HEATING_INT.h"

void HEATINGInit(){
	//Enable PIN
	DIO_setPinDir(DIO_PINC2,DIO_OUTPUT);

	//Control PINs
	DIO_setPinDir(DIO_PINC0,DIO_OUTPUT);

	DIO_setPinDir(DIO_PINC1,DIO_OUTPUT);
}

void HEATINGChoise(u8 choise){
	if(choise==HEATINGSTART){
		//Start Enable
		DIO_setPinValue(DIO_PINC2,DIO_HIGH);

		//Start Motor
		DIO_setPinValue(DIO_PINC2,DIO_HIGH);
		DIO_setPinValue(DIO_PINC1,DIO_LOW);
	}
	else if(choise==HEATINGSTOP){
		//Stop Enable
		DIO_setPinValue(DIO_PINC2,DIO_LOW);

		//Stop Motor
		DIO_setPinValue(DIO_PINC2,DIO_LOW);
		DIO_setPinValue(DIO_PINC1,DIO_LOW);
	}
}
