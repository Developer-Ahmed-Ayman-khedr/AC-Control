/*
 * COOLING_INT.h
 *
 *  Created on: Jun 1, 2024
 *      Author: ahmed
 */

#ifndef APP_COOLING_COOLING_INT_H_
#define APP_COOLING_COOLING_INT_H_

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

#define COOLINGSTART 0

#define COOLINGSTOP 1

/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/


/******************************************
  GLOBAL FUNCTIONS Prototypes
*******************************************/

void COOLINGInit();

void COOLINGChoise(u8 choise);

#endif /* APP_COOLING_COOLING_INT_H_ */
