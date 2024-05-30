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

/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/


/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/

#define HEATINGSTART 0

#define HEATINGSTOP 1

/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/


/******************************************
  GLOBAL FUNCTIONS Prototypes
*******************************************/


void HEATINGInit();

void HEATINGChoise(u8 choise);

#endif /* APP_HEATING_HEATING_INT_H_ */
