/*
 * BUTTON_INT.h
 *
 *  Created on: Jun 1, 2024
 *      Author: ahmed
 */

#ifndef APP_BUTTONS_BUTTONS_INT_H_
#define APP_BUTTONS_BUTTONS_INT_H_

/******************************************
  INCLUDES
*******************************************/

#include "DIO_INT.h"

#include "GI_INT.h"

#include "EXT_INT.h"

#include "UART_INT.h"

#include "EEPROM_INT.h"

/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/


/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/


/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/


/******************************************
  GLOBAL FUNCTIONS Prototypes
*******************************************/

void ButtonsInit();

void ButtonsPushed(u8* UserSetTemp_ptr);

#endif /* APP_BUTTONS_BUTTONS_INT_H_ */
