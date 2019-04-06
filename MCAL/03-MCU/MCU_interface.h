/***************************************************************/
/* Author: Mahmoud Alaa Elwelily                               */
/* Date: 20-Mar-19                                             */
/* Version: 01                                                 */
/* Description: Interface file for MCU Driver for AVR ATmega32 */
/***************************************************************/

/*Preprocessor Guard*/
#ifndef MCU_INTERFACE_H 
#define MCU_INTERFACE_H 

/*
 * Description: Function to enable all the interrupts for AVR ATmega32
 * Inputs: void
 * Output: the Error state of the function if the function is called twice
 */
u8 MCU_u8EnableGlobalINT(void);
//returns zero if it is called twice

/*
 * Description: Function to disable all the interrupts for AVR ATmega32
 * Inputs: void
 * Output: the Error state of the function if the function is called twice
 */
u8 MCU_u8DisableGlobalINT(void);

#endif /* MCU_INTERFACE_H */ 
