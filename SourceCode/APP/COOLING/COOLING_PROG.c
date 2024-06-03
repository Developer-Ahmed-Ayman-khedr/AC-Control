/*
 * COOLING_PROG.c
 *
 *  Created on: Jun 1, 2024
 *      Author: ahmed
 */


#include "COOLING_INT.h"

void CoolingInit(){
	//Control PINs
	DIO_setPinDir(DIO_PINC3,DIO_OUTPUT);

	DIO_setPinDir(DIO_PINC4,DIO_OUTPUT);
}

void CoolingChoise(u8 speed){
	if(speed>COOLINGSTOP){
		//Start Timer
		TIMER0_initFPWM();

		TIMER0_start(TIMER0_DIV64);

		TIMER0_setOCR(speed);

		//Start Motor
		DIO_setPinValue(DIO_PINC3,DIO_HIGH);
		DIO_setPinValue(DIO_PINC4,DIO_LOW);
	}
	else if(speed==COOLINGSTOP){
		//Stop Enable
		TIMER0_start(TIMER0_STOP);

		//Stop Motor
		DIO_setPinValue(DIO_PINC3,DIO_LOW);
		DIO_setPinValue(DIO_PINC4,DIO_LOW);
	}
}
