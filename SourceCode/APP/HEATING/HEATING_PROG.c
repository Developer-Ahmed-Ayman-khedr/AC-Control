/*
 * HEATING_PROG.c
 *
 *  Created on: May 30, 2024
 *      Author: ahmed
 */

#include "HEATING_INT.h"

void HeatingInit(){
	//Control PINs
	DIO_setPinDir(DIO_PINC6,DIO_OUTPUT);

	DIO_setPinDir(DIO_PINC7,DIO_OUTPUT);
}

void HeatingChoise(u8 speed){
	if(speed>HEATINGSTOP){
		//Start Timer
		TIMER0_initFPWM();

		TIMER0_start(TIMER0_DIV64);

		TIMER0_setOCR(speed);

		//Start Motor
		DIO_setPinValue(DIO_PINC6,DIO_HIGH);
		DIO_setPinValue(DIO_PINC7,DIO_LOW);
	}
	else if(speed==HEATINGSTOP){
		//Stop Enable
		TIMER0_start(TIMER0_STOP);

		//Stop Motor
		DIO_setPinValue(DIO_PINC6,DIO_LOW);
		DIO_setPinValue(DIO_PINC7,DIO_LOW);
	}
}
