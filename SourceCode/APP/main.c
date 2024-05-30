/*
 * main.c
 *
 *  Created on: May 28, 2024
 *      Author: ahmed
 */

#include "main.h"

int main(){
	u8 MainFlage = 0, UserSetTemp;

	//Temprature initialize
	TEMPCheckInit();

	//SevenSegment initialize
	SS_init();

	//Heating Motor initialize
	HEATINGInit();

	//Cooling Motor initialize


	while(1){
		SS_writeNum(TEMPCheckStart());
		switch(MainFlage){
		case 1:
			if(TEMPCheckStart()<UserSetTemp){

			}
			MainFlage = 2;
			break;
		case 2:

			break;
		default:
			break;
		}
	}
	return 0;
}
