/*
 * SS_INT.h
 *
 *  Created on: May 28, 2024
 *      Author: ahmed
 */

#ifndef HAL_SS_SS_INT_H_
#define HAL_SS_SS_INT_H_


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

#define SS_S0 DIO_PINA4
#define SS_S1 DIO_PINA5
#define SS_S2 DIO_PINA6
#define SS_S3 DIO_PINA7

#define SS_ENABLE1 DIO_PINB2
#define SS_ENABLE2 DIO_PINB1

/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/


/******************************************
  GLOBAL FUNCTIONS Prototypes
*******************************************/
//Initialize
void SS_init();

//Send
void SS_writeNum(u8 num);

//Deinitialize
void SS_deinit();

#endif /* HAL_SS_SS_INT_H_ */
