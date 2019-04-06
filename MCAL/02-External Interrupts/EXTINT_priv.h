/**********************************************************/
/* Author: Mahmoud Alaa Elwelily                          */
/* Date: 20-Mar-19                                        */
/* Version: 01                                            */
/* Description: Private file for External INT             */
/* Driver supported by AVR ATmega32                      */
/* This driver is mainly for interrupts INT0,INT1,INT2    */
/* specified for pins D0,D1,D2                            */
/**********************************************************/

/*Preprocessor Guard*/
#ifndef INT_PRIV_H 
#define INT_PRIV_H 

/*Private Macro for the number of available external interrupts in AVR ATmega32*/
#define EXTINT_u8_NO_OF_EXTINT    (u8)3

/*Macros for the External interrupts state (Disabled/Enabled)*/
#define EXTINT_u8_DISABLE (u8)0
#define EXTINT_u8_ENABLE  (u8)1

/*Macros for the probable sense level for the external interrupt*/
#define EXTINT_u8_LOW_LEVEL      (u8)0
#define EXTINT_u8_ON_CHANGE      (u8)1
#define EXTINT_u8_FALLING_EDG    (u8)2
#define EXTINT_u8_RISING_EDG     (u8)3

/*Macros for the bit number of each external interrupt in GICR register*/
#define EXTINT_u8_INT0_BIT     (u8)6
#define EXTINT_u8_INT1_BIT     (u8)7
#define EXTINT_u8_INT2_BIT     (u8)5

/*Macro for the offset of INT0,INT1,INT2 in MCUCR and MCUCSR registers*/
#define EXTINT_u8_INT0_OFFS    (u8)0
#define EXTINT_u8_INT1_OFFS    (u8)2
#define EXTINT_u8_INT2_OFFS    (u8)6

/*AVR ATmega32 Registers needed for enabling/disabling or configurating the external interrupt*/
#define EXTINT_GICR ((Register*) 0x5B) -> ByteAccess
#define EXTINT_MCUCR ((Register*) 0x55) -> ByteAccess
#define EXTINT_MCUCSR ((Register*) 0x54) -> ByteAccess

/*The ISR of the external interrupt INT0*/
void __vector_1 (void) __attribute__((signal));

/*The ISR of the external interrupt INT1*/
void __vector_2 (void) __attribute__((signal));

/*The ISR of the external interrupt INT2*/
void __vector_3 (void) __attribute__((signal));

#endif /* INT_PRIV_H */ 
