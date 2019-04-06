/*****************************************************************/
/* Author: Mahmoud Alaa Elwelily                                 */
/* Date: 28-Mar-19                                        		 */
/* Version: 01                                            	   	 */
/* Description: Interface file for Timer Driver for AVR ATmega32 */
/*****************************************************************/

/*Preprocessor Guard*/
#ifndef TMR_INTERFACE_H 
#define TMR_INTERFACE_H

/*Macro for defining the 3 availabe timers in AVR ATmega32*/
#define TMR_u8_TIMER0   (u8)0
#define TMR_u8_TIMER1   (u8)1
#define TMR_u8_TIMER2   (u8)2

/*
 * Description: Function to set the initialized state and prescaler for each timer (0,1,2)
 * Inputs: none
 * Output: void
 */
void TMR_vInit (void);

/*
 * Description: Function to enable one of the available timers in AVR ATmega32 (0,1,2)
 * Inputs: Timer Number
 * Output: the Error state of the function
 */
u8 TMR_u8EnableTimer (u8 Copy_u8TimerNb);

/*
 * Description: Function to disable one of the available timers in AVR ATmega32 (0,1,2)
 * Inputs: Timer Number
 * Output: the Error state of the function
 */
u8 TMR_u8DisableTimer (u8 Copy_u8TimerNb);

/*
 * Description: Function to set the delay time for the assigned timer
 * Inputs: the delay time in millisecond
 * Output: the Error state of the function
 */
u8 TMR_u8SetDesiredTime (u8 Copy_u8TimerNb,u32 Copy_u16TimeInMs);

/*
 * Description: Function to set the callback function for a certain timer in case of firing its interrupt
 * Inputs: the number of the available timer (0,1,2) and a pointer to its callback function
 * Output: the Error state of the function
 */
u8 TMR_u8SetCallBack (u8 Copy_u8TimerNb,void(*Copy_PVCallBack)(void));

#endif /* TMR_INTERFACE_H */ 
