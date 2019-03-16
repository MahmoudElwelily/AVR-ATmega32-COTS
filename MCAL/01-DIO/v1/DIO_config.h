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
/* Preprocessor Guard */
#ifndef CONFIG_H_
#define CONFIG_H_

/* Initial direction for DIO Pins 		  */
/* Range: DIO_u8_PIN_INIT_INPUT 	   	  */
/*        DIO_u8_PIN_INIT_OUTPUT	 	  */
#define DIO_u8_PIN0_INIT_DIR    DIO_u8_PIN_INIT_OUTPUT 		/*PINA0*/
#define DIO_u8_PIN1_INIT_DIR    DIO_u8_PIN_INIT_OUTPUT    	/*PINA1*/
#define DIO_u8_PIN2_INIT_DIR    DIO_u8_PIN_INIT_OUTPUT    	/*PINA2*/
#define DIO_u8_PIN3_INIT_DIR    DIO_u8_PIN_INIT_OUTPUT   	/*PINA3*/
#define DIO_u8_PIN4_INIT_DIR    DIO_u8_PIN_INIT_OUTPUT	    /*PINA4*/
#define DIO_u8_PIN5_INIT_DIR    DIO_u8_PIN_INIT_OUTPUT   	/*PINA5*/
#define DIO_u8_PIN6_INIT_DIR    DIO_u8_PIN_INIT_OUTPUT		/*PINA6*/
#define DIO_u8_PIN7_INIT_DIR    DIO_u8_PIN_INIT_OUTPUT		/*PINA7*/

#define DIO_u8_PIN8_INIT_DIR	DIO_u8_PIN_INIT_OUTPUT		/*PINB0*/
#define DIO_u8_PIN9_INIT_DIR	DIO_u8_PIN_INIT_OUTPUT		/*PINB1*/
#define DIO_u8_PIN10_INIT_DIR	DIO_u8_PIN_INIT_OUTPUT		/*PINB2*/
#define DIO_u8_PIN11_INIT_DIR	DIO_u8_PIN_INIT_OUTPUT		/*PINB3*/
#define DIO_u8_PIN12_INIT_DIR	DIO_u8_PIN_INIT_OUTPUT		/*PINB4*/
#define DIO_u8_PIN13_INIT_DIR	DIO_u8_PIN_INIT_OUTPUT		/*PINB5*/
#define DIO_u8_PIN14_INIT_DIR	DIO_u8_PIN_INIT_OUTPUT		/*PINB6*/
#define DIO_u8_PIN15_INIT_DIR	DIO_u8_PIN_INIT_OUTPUT		/*PINB7*/

#define DIO_u8_PIN16_INIT_DIR	DIO_u8_PIN_INIT_OUTPUT		/*PINC0*/
#define DIO_u8_PIN17_INIT_DIR	DIO_u8_PIN_INIT_OUTPUT		/*PINC1*/
#define DIO_u8_PIN18_INIT_DIR	DIO_u8_PIN_INIT_OUTPUT		/*PINC2*/
#define DIO_u8_PIN19_INIT_DIR	DIO_u8_PIN_INIT_OUTPUT		/*PINC3*/
#define DIO_u8_PIN20_INIT_DIR	DIO_u8_PIN_INIT_OUTPUT		/*PINC4*/
#define DIO_u8_PIN21_INIT_DIR	DIO_u8_PIN_INIT_OUTPUT		/*PINC5*/
#define DIO_u8_PIN22_INIT_DIR	DIO_u8_PIN_INIT_OUTPUT		/*PINC6*/
#define DIO_u8_PIN23_INIT_DIR	DIO_u8_PIN_INIT_OUTPUT		/*PINC7*/

#define DIO_u8_PIN24_INIT_DIR	DIO_u8_PIN_INIT_OUTPUT		/*PIND0*/
#define DIO_u8_PIN25_INIT_DIR	DIO_u8_PIN_INIT_OUTPUT		/*PIND1*/
#define DIO_u8_PIN26_INIT_DIR	DIO_u8_PIN_INIT_OUTPUT		/*PIND2*/
#define DIO_u8_PIN27_INIT_DIR	DIO_u8_PIN_INIT_OUTPUT		/*PIND3*/
#define DIO_u8_PIN28_INIT_DIR	DIO_u8_PIN_INIT_OUTPUT		/*PIND4*/
#define DIO_u8_PIN29_INIT_DIR	DIO_u8_PIN_INIT_OUTPUT		/*PIND5*/
#define DIO_u8_PIN30_INIT_DIR	DIO_u8_PIN_INIT_OUTPUT		/*PIND6*/
#define DIO_u8_PIN31_INIT_DIR	DIO_u8_PIN_INIT_OUTPUT		/*PIND7*/

/* Macros of initialized value for DIO Pins */
/* Range : DIO_u8_INIT_HIGH  */
/*	       DIO_u8_INIT_LOW   */
/*		     DIO_u8_INIT_DEF   */
#define DIO_u8_PIN0_INIT_VAL     DIO_u8_INIT_DEF    	/*PINA0*/
#define DIO_u8_PIN1_INIT_VAL     DIO_u8_INIT_DEF    	/*PINA1*/
#define DIO_u8_PIN2_INIT_VAL     DIO_u8_INIT_DEF    	/*PINA2*/
#define DIO_u8_PIN3_INIT_VAL     DIO_u8_INIT_DEF    	/*PINA3*/
#define DIO_u8_PIN4_INIT_VAL     DIO_u8_INIT_DEF	    /*PINA4*/
#define DIO_u8_PIN5_INIT_VAL     DIO_u8_INIT_DEF    	/*PINA5*/
#define DIO_u8_PIN6_INIT_VAL     DIO_u8_INIT_DEF		/*PINA6*/
#define DIO_u8_PIN7_INIT_VAL     DIO_u8_INIT_DEF		/*PINA7*/

#define DIO_u8_PIN8_INIT_VAL	 DIO_u8_INIT_DEF		/*PINB0*/
#define DIO_u8_PIN9_INIT_VAL	 DIO_u8_INIT_DEF		/*PINB1*/
#define DIO_u8_PIN10_INIT_VAL	 DIO_u8_INIT_DEF		/*PINB2*/
#define DIO_u8_PIN11_INIT_VAL	 DIO_u8_INIT_DEF		/*PINB3*/
#define DIO_u8_PIN12_INIT_VAL	 DIO_u8_INIT_DEF		/*PINB4*/
#define DIO_u8_PIN13_INIT_VAL	 DIO_u8_INIT_DEF		/*PINB5*/
#define DIO_u8_PIN14_INIT_VAL	 DIO_u8_INIT_DEF		/*PINB6*/
#define DIO_u8_PIN15_INIT_VAL	 DIO_u8_INIT_DEF		/*PINB7*/

#define DIO_u8_PIN16_INIT_VAL	 DIO_u8_INIT_DEF		/*PINC0*/
#define DIO_u8_PIN17_INIT_VAL	 DIO_u8_INIT_DEF		/*PINC1*/
#define DIO_u8_PIN18_INIT_VAL	 DIO_u8_INIT_DEF		/*PINC2*/
#define DIO_u8_PIN19_INIT_VAL	 DIO_u8_INIT_DEF		/*PINC3*/
#define DIO_u8_PIN20_INIT_VAL	 DIO_u8_INIT_DEF		/*PINC4*/
#define DIO_u8_PIN21_INIT_VAL	 DIO_u8_INIT_DEF		/*PINC5*/
#define DIO_u8_PIN22_INIT_VAL	 DIO_u8_INIT_DEF		/*PINC6*/
#define DIO_u8_PIN23_INIT_VAL	 DIO_u8_INIT_DEF		/*PINC7*/

#define DIO_u8_PIN24_INIT_VAL	 DIO_u8_INIT_DEF		/*PIND0*/
#define DIO_u8_PIN25_INIT_VAL	 DIO_u8_INIT_DEF		/*PIND1*/
#define DIO_u8_PIN26_INIT_VAL	 DIO_u8_INIT_DEF		/*PIND2*/
#define DIO_u8_PIN27_INIT_VAL	 DIO_u8_INIT_DEF		/*PIND3*/
#define DIO_u8_PIN28_INIT_VAL	 DIO_u8_INIT_DEF		/*PIND4*/
#define DIO_u8_PIN29_INIT_VAL	 DIO_u8_INIT_DEF		/*PIND5*/
#define DIO_u8_PIN30_INIT_VAL	 DIO_u8_INIT_DEF		/*PIND6*/
#define DIO_u8_PIN31_INIT_VAL	 DIO_u8_INIT_DEF		/*PIND7*/

#endif /* CONFIG_H_ */
