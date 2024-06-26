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

#include "../../MCAL/TIMER1/TIMER1_INT.h"

/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/


/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/

#define COOLINGSTOP 0

#define COOLINGSTART 1

/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/


/******************************************
  GLOBAL FUNCTIONS Prototypes
*******************************************/

void CoolingInit();

void CoolingChoise(u8 speed);

#endif /* APP_COOLING_COOLING_INT_H_ */
