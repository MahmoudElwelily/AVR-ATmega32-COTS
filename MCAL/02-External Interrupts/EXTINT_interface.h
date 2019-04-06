/**********************************************************/
/* Author: Mahmoud Alaa Elwelily                          */
/* Date: 20-Mar-19                                        */
/* Version: 01                                            */
/* Description: Interface file for External INT Driver    */
/* supported by AVR ATmega32                              */
/* This driver is mainly for interrupts INT0,INT1,INT2    */
/* specified for pins D0,D1,D2                            */
/**********************************************************/

/*Preprocessor Guard*/
#ifndef EXTINT_INTERFACE_H
#define EXTINT_INTERFACE_H

/*Macro for the sense levels availabe for the external interrupt*/
#define EXTINT_u8_SENSE_LOW_LEVEL        (u8)0
#define EXTINT_u8_SENSE_ON_CHANGE        (u8)1
#define EXTINT_u8_SENSE_FALLING_EDG      (u8)2
#define EXTINT_u8_SENSE_RISING_EDG       (u8)3

/*Macro for each external interrupt (INT0,INT1,INT2)*/
#define EXTINT_u8_INT0    (u8)0
#define EXTINT_u8_INT1    (u8)1
#define EXTINT_u8_INT2    (u8)2

/*
 * Description: Function to initialize the external interrupts (INT0,INT1,INT2) according to the configurations
 * Inputs: void
 * Output: void
 */
void EXTINT_vInit (void);

/*
 * Description: Function to enable one of the required external interrupts (INT0,INT1,INT2)
 * Inputs: the number of the external interrupt (0,1,2)
 * Output: the Error state of the function
 */
u8 EXTINT_u8Enable  (u8 Copy_u8IntNb);

/*
 * Description: Function to disable one of the required external interrupts (INT0,INT1,INT2)
 * Inputs: the number of the external interrupt (0,1,2)
 * Output: the Error state of the function
 */
u8 EXTINT_u8Disable (u8 Copy_u8IntNb);

/*
 * Description: Function to set the sense level of the required external interrupts (INT0,INT1,INT2)
 * Inputs: the number of the external interrupt (0,1,2) and the required sense level
 * Output: the Error state of the function
 */
u8 EXTINT_u8SetSenseLevel(u8 Copy_u8IntNb,u8 Copy_u8SenseLevel);

/*
 * Description: Function to set the callback function for the required external interrupts (INT0,INT1,INT2)
 * Inputs: the number of the external interrupt (0,1,2) and the callback function
 * Output: the Error state of the function
 */
u8 EXTINT_u8SetCallBack(u8 Copy_u8IntNb,void(*Copy_PVCallBack)(void));

#endif /* EXTINT_INTERFACE_H */
