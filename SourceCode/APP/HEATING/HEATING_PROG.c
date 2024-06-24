/*
 * HEATING_PROG.c
 *
 *  Created on: May 30, 2024
 *      Author: ahmed
 */

#include "HEATING_INT.h"

void HeatingInit(){

	DIO_setPinDir(DIO_PINC6,DIO_OUTPUT);


}

void HeatingChoise(u8 speed){
	if(speed>HEATINGSTOP){
		DIO_setPinValue(DIO_PINC6,DIO_HIGH);
	}
	else if(speed==HEATINGSTOP){
		DIO_setPinValue(DIO_PINC6,DIO_LOW);
	}
}
