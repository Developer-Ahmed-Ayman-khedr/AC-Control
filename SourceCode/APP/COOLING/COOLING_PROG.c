/*
 * COOLING_PROG.c
 *
 *  Created on: Jun 1, 2024
 *      Author: ahmed
 */


#include "COOLING_INT.h"

void CoolingInit(){

	DIO_setPinDir(DIO_PIND5,DIO_OUTPUT);

	//Control PINs
	DIO_setPinDir(DIO_PINC3,DIO_OUTPUT);

	DIO_setPinDir(DIO_PINC4,DIO_OUTPUT);
}

void CoolingChoise(u8 speed){
	if(speed>COOLINGSTOP){
		//Start Timer FPWM
		//TIMER1_initFastPwmMod14();

		//TIMER1_setFrequency(50);

		//TIMER1_setOcr(speed);

		//Start Motor
		DIO_setPinValue(DIO_PINC3,DIO_HIGH);
		DIO_setPinValue(DIO_PINC4,DIO_LOW);
	}
	else if(speed==COOLINGSTOP){
		//Stop Timer FPWM
		TIMER1_STOP();

		//Stop Motor
		DIO_setPinValue(DIO_PINC3,DIO_LOW);
		DIO_setPinValue(DIO_PINC4,DIO_LOW);
	}
}
