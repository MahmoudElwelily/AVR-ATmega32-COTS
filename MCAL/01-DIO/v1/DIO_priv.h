/********************************************************************/
/* Author  : Mahmoud Alaa Elwelily                                  */
/* Date    : 29 Jan 2019                                            */
/* Version : V01                                                    */
/********************************************************************/
/* Description                                                      */
/* ------------                                                     */
/* Private header file for using DIO peripheral in AVR ATmega32     */
/* It is included by interface.c and it is completely hidden from   */
/* any file in HAL                                                  */
/********************************************************************/
/* PreProcessor Guard */
#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_

/*======================================================== */
/* Direction Macros for pins initialized direction */
/* their definition are specific to AVR */
#define DIO_u8_PIN_INIT_INPUT  0
#define DIO_u8_PIN_INIT_OUTPUT 1

/* Macros for pins initialized assignment */
#define DIO_u8_INIT_HIGH 1
#define DIO_u8_INIT_LOW  0
#define DIO_u8_INIT_DEF  0
/*======================================================== */
/* Macros for pin direction according to AVR */
#define DIO_u8_PRIV_PIN_OUTPUT 1
#define DIO_u8_PRIV_PIN_INPUT  0

/* Macros for pin assignment according to AVR */
#define DIO_u8_PRIV_PIN_HIGH 1
#define DIO_u8_PRIV_PIN_LOW  0
/*======================================================== */
/* Macro for maximum number of available DIO pins */
#define DIO_u8MAXPINNB (u8)32

/* Macro for maximum number of available ports */
#define DIO_u8MAXPortNB (u8)4

/* Macro for number of pins in a single port */
#define DIO_u8NUMBER_OF_PINS_IN_PORT (u8)8

/* AVR ATmega32 DIO registers */
#define DIO_PU_DDRA ((Register*) 0x3A) -> ByteAccess
#define DIO_PU_DDRB ((Register*) 0x37) -> ByteAccess
#define DIO_PU_DDRC ((Register*) 0x34) -> ByteAccess
#define DIO_PU_DDRD ((Register*) 0x31) -> ByteAccess

#define DIO_PU_PORTA ((Register*) 0x3B) -> ByteAccess
#define DIO_PU_PORTB ((Register*) 0x38) -> ByteAccess
#define DIO_PU_PORTC ((Register*) 0x35) -> ByteAccess
#define DIO_PU_PORTD ((Register*) 0x32) -> ByteAccess

#define DIO_PU_PINA ((Register*) 0x39) -> ByteAccess
#define DIO_PU_PINB ((Register*) 0x36) -> ByteAccess
#define DIO_PU_PINC ((Register*) 0x33) -> ByteAccess
#define DIO_PU_PIND ((Register*) 0x30) -> ByteAccess

#endif /* DIO_PRIV_H_ */
