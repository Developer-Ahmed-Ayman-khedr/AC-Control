/*
 * COOLING_PROG.cc
 *
 *  Created on: May 30, 2024
 *      Author: ahmed
 */



#include "COOLING_INT.h"

void COOLINGInit(){
	//Enable PIN
	DIO_setPinDir(DIO_PINC5,DIO_OUTPUT);

	//Control PINs
	DIO_setPinDir(DIO_PINC3,DIO_OUTPUT);

	DIO_setPinDir(DIO_PINC4,DIO_OUTPUT);
}

void COOLINGChoise(u8 choise){
	if(choise==COOLINGSTART){
		//Start Enable
		DIO_setPinValue(DIO_PINC5,DIO_HIGH);

		//Start Motor
		DIO_setPinValue(DIO_PINC3,DIO_HIGH);
		DIO_setPinValue(DIO_PINC4,DIO_LOW);
	}
	else if(choise==COOLINGSTOP){
		//Stop Enable
		DIO_setPinValue(DIO_PINC5,DIO_LOW);

		//Stop Motor
		DIO_setPinValue(DIO_PINC3,DIO_LOW);
		DIO_setPinValue(DIO_PINC4,DIO_LOW);
	}
}
