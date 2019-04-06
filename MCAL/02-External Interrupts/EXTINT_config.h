/**********************************************************/
/* Author: Mahmoud Alaa Elwelily                          */
/* Date: 20-Mar-19                                        */
/* Version: 01                                            */
/* Description: Configuration file for External INT       */
/*  Driver supported by AVR ATmega32                      */
/* This driver is mainly for interrupts INT0,INT1,INT2    */
/* specified for pins D0,D1,D2                            */
/**********************************************************/

/*Preprocessor Guard*/
#ifndef EXTINT_CONFIG_H
#define EXTINT_CONFIG_H

/*
   Macros for setting the initialized state of each external interrupt
   for pins (D0->INT0 , D1->INT1 , D2->INT2)
   Ranges:   EXTINT_u8_ENABLE
          EXTINT_u8_DISABLE
*/
#define EXTINT_U8_INT0_INITSTATE    EXTINT_u8_ENABLE
#define EXTINT_U8_INT1_INITSTATE    EXTINT_u8_DISABLE
#define EXTINT_U8_INT2_INITSTATE    EXTINT_u8_DISABLE

/*
  Macros for setting the initialized sense level for each external interrupt
  for pins (D0->INT0 , D1->INT1 , D2->INT2)
  Ranges: EXTINT_u8_LOW_LEVEL
          EXTINT_u8_FALLING_EDG
          EXTINT_u8_RISING_EDG
          EXTINT_u8_ON_CHANGE
*/
#define EXTINT_U8_INT0_SNSLVL     EXTINT_u8_RISING_EDG
#define EXTINT_U8_INT1_SNSLVL     EXTINT_u8_FALLING_EDG
#define EXTINT_U8_INT2_SNSLVL     EXTINT_u8_FALLING_EDG

/*initialcallback for each vector*/

#endif /* EXTINT_CONFIG_H */

