/********************************************************************/
/* Author  : Mahmoud Alaa Elwelily                                  */
/* Date    : 29 Jan 2019                                            */
/* Version : V01                                                    */
/********************************************************************/
/* Description                                                      */
/* ------------                                                     */
/* Header file for using DIO peripheral in AVR ATmega32             */
/*                                                                  */
/*                                                                  */
/********************************************************************/

/* PreProcessor Guard */
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/* Direction Macros for pins */
#define DIO_u8_PIN_INPUT  (u8)0
#define DIO_u8_PIN_OUTPUT (u8)1

/* Macros for ports mapping */
#define DIO_u8_PORT_A   (u8)0
#define DIO_u8_PORT_B   (u8)1
#define DIO_u8_PORT_C   (u8)2
#define DIO_u8_PORT_D   (u8)3

/* Assignment Macros for pins */
#define DIO_u8_PIN_HIGH   (u8)1
#define DIO_u8_PIN_LOW    (u8)0

/* DIO Pins Macros */
#define DIO_u8_PIN0     (u8)0 		/*PINA0*/
#define DIO_u8_PIN1     (u8)1    	/*PINA1*/
#define DIO_u8_PIN2     (u8)2    	/*PINA2*/
#define DIO_u8_PIN3     (u8)3    	/*PINA3*/
#define DIO_u8_PIN4     (u8)4	    /*PINA4*/
#define DIO_u8_PIN5     (u8)5   	/*PINA5*/
#define DIO_u8_PIN6     (u8)6		/*PINA6*/
#define DIO_u8_PIN7     (u8)7		/*PINA7*/

#define DIO_u8_PIN8 	(u8)8		/*PINB0*/
#define DIO_u8_PIN9	    (u8)9		/*PINB1*/
#define DIO_u8_PIN10	(u8)10		/*PINB2*/
#define DIO_u8_PIN11	(u8)11		/*PINB3*/
#define DIO_u8_PIN12	(u8)12		/*PINB4*/
#define DIO_u8_PIN13	(u8)13		/*PINB5*/
#define DIO_u8_PIN14	(u8)14		/*PINB6*/
#define DIO_u8_PIN15	(u8)15		/*PINB7*/

#define DIO_u8_PIN16	(u8)16		/*PINC0*/
#define DIO_u8_PIN17	(u8)17		/*PINC1*/
#define DIO_u8_PIN18	(u8)18		/*PINC2*/
#define DIO_u8_PIN19	(u8)19		/*PINC3*/
#define DIO_u8_PIN20	(u8)20		/*PINC4*/
#define DIO_u8_PIN21	(u8)21		/*PINC5*/
#define DIO_u8_PIN22	(u8)22		/*PINC6*/
#define DIO_u8_PIN23	(u8)23		/*PINC7*/

#define DIO_u8_PIN24	(u8)24		/*PIND0*/
#define DIO_u8_PIN25	(u8)25		/*PIND1*/
#define DIO_u8_PIN26	(u8)26		/*PIND2*/
#define DIO_u8_PIN27	(u8)27		/*PIND3*/
#define DIO_u8_PIN28	(u8)28		/*PIND4*/
#define DIO_u8_PIN29	(u8)29		/*PIND5*/
#define DIO_u8_PIN30	(u8)30		/*PIND6*/
#define DIO_u8_PIN31	(u8)31		/*PIND7*/

/*
 * Description: Function to set the initialized direction and value of each pin in all ports
 * Inputs: none
 * Output: the Error state of the function
 */
void DIO_vInit (void);

/*
 * Description: Function to set the direction of a specific pin in a specified port
 * Inputs: the pin number , the pin direction
 * Output: the Error state of the function
 */
u8 DIO_u8SetPinDirection (u8 Copy_u8PinNB,u8 Copy_u8Direction);

/*
 * Description: Function to set a specific pin in a specified port with a specified value (INPUT = 0,OUTPUT = 1)
 * Inputs: the pin number , the pin value
 * Output: the Error state of the function
 */
u8 DIO_u8SetPinValue (u8 Copy_u8PinNB,u8 Copy_u8Value);

/*
 * Description: Function to get the value of a certain input pin in a specified port
 * Inputs: the pin number , the container variable which will hold the value on this pin
 * output: the Error state of the function
 */
u8 DIO_u8GetPinValue (u8 Copy_u8PinNB, u8 *Copy_u8PinValue);

/*
 * Description: Function to set the direction of the whole pins ins a specified port
 * Inputs: the port number and direction
 * Output: the Error state of the function
 */
u8 DIO_u8SetPortDirection (u8 Copy_u8PortNB,u8 Copy_u8Direction);

/*
 * Description: Function to set pins of a specified port with a specified value
 * Inputs: the port number , the port value
 * Output: the Error state of the function
 */
u8 DIO_u8SetPortValue (u8 Copy_u8PortNB, u8 Copy_u8Value);

/*
 * Description: Function to get the value of a specified port
 * Inputs: the port number , the container variable which will hold the value on this port
 * output: the Error state of the function
 */
u8 DIO_u8GetPortValue (u8 Copy_u8PortNB, u8 *Copy_u8PortValue);

#endif /* DIO_INTERFACE_H_ */
