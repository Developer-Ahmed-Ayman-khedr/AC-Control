/*
 * OFFOPTION_PROG.c
 *
 *  Created on: Jun 5, 2024
 *      Author: ahmed
 */

#include "OFFOPTION_INT.h"

//Td = 5sec,//numOv = 4882
//Td = 2h -> 2*60*60sec,//numOv = 7031250

BOOL OffFlage = FALSE;

u32 OvCounter = 0;

void OffFunction(){
	if(OvCounter==4882)
	{
		OffFlage = TRUE;
	}
	DIO_togglePinValue(DIO_PIND6);
}

/*void OFFOPTION_init(){

	DIO_setPinDir(DIO_PIND6,DIO_OUTPUT);

	GI_enable();

	TIMER0_initNormal();

	TIMER_setcallbackOv(OffFunction);

	TIMER0_setPreload(0);

	TIMER0_start(TIMER0_DIV64);
}*/
