/*
 * TEMP_PROG.c
 *
 *  Created on: May 30, 2024
 *      Author: ahmed
 */

#include "TEMP_INT.h"

void TEMPCheckInit(){
	ADC_init();

	//ADC PIN
	DIO_setPinValue(DIO_PINA1,DIO_INPUT);
}

f32 TEMPCheckStart(){
	static f32 VAnalogTemperature;
	static u32 VDigitalTemperature;
	VDigitalTemperature = ADC_read(ADC_CH1);
	VAnalogTemperature = (ADC_convertAnalog(VDigitalTemperature))*100;
	return VAnalogTemperature;
}
