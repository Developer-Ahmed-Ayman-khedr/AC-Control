/*
 * HEATING_INT.h
 *
 *  Created on: May 30, 2024
 *      Author: ahmed
 */

#ifndef APP_HEATING_HEATING_INT_H_
#define APP_HEATING_HEATING_INT_H_

/******************************************
  INCLUDES
*******************************************/

#include "DIO_INT.h"

#include "TIMER1_INT.h"

/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/


/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/

#define HEATINGSTOP 0

#define HEATINGSTART 1

/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/


/******************************************
  GLOBAL FUNCTIONS Prototypes
*******************************************/

void HeatingInit();

void HeatingChoise(u8 speed);

#endif /* APP_HEATING_HEATING_INT_H_ */
