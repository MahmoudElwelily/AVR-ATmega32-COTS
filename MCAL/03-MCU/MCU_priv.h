/*************************************************************/
/* Author: Mahmoud Alaa Elwelily                             */
/* Date: 20-Mar-19                                           */
/* Version: 01                                               */
/* Description: Private file for MCU Driver for AVR ATmega32 */
/*************************************************************/

/*Preprocessor Guard*/
#ifndef MCU_PRIV_H 
#define MCU_PRIV_H 

/*Macro for the global interrupt bit in SREG register*/
#define MCU_GLOBAL_INT_BIT    (u8)7

/*AVR ATmega32 Register needed for enabling/disabling all interrupts*/
#define MCU_SREG ((Register*) 0x5F) -> ByteAccess

#endif /* MCU_PRIV_H */ 
