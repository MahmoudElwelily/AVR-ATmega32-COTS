/********************************************************************/
/* Author  : Mahmoud Alaa Elwelily                                  */
/* Date    : 29 Jan 2019                                            */
/* Version : V01                                                    */
/********************************************************************/
/* Description                                                      */
/* ------------                                                     */
/* Program file for using DIO peripheral in AVR ATmega32             */
/*                                                                  */
/*                                                                  */
/********************************************************************/
#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "DIO_interface.h"
#include "DIO_priv.h"
#include "DIO_config.h"

/*
 * Description: Function to set the initialized direction and value of each pin in all ports
 * Inputs: none
 * Output: the Error state of the function
 */
void DIO_vInit (void)
{
	/*
	 * Setting the direction of pins of PORT(A-D) according to initialized direction assigned
	 * in the configuration file.
	 */
	DIO_PU_DDRA = (DIO_u8_PIN0_INIT_DIR << 0) | (DIO_u8_PIN1_INIT_DIR << 1) | (DIO_u8_PIN2_INIT_DIR << 2)
			| (DIO_u8_PIN3_INIT_DIR << 3) | (DIO_u8_PIN4_INIT_DIR << 4) | (DIO_u8_PIN5_INIT_DIR << 5)
			| (DIO_u8_PIN6_INIT_DIR << 6) | (DIO_u8_PIN7_INIT_DIR << 7);

	DIO_PU_DDRB = (DIO_u8_PIN8_INIT_DIR << 0) | (DIO_u8_PIN9_INIT_DIR << 1) | (DIO_u8_PIN10_INIT_DIR << 2)
				| (DIO_u8_PIN11_INIT_DIR << 3) | (DIO_u8_PIN12_INIT_DIR << 4) | (DIO_u8_PIN13_INIT_DIR << 5)
				| (DIO_u8_PIN14_INIT_DIR << 6) | (DIO_u8_PIN15_INIT_DIR << 7);

	DIO_PU_DDRC = (DIO_u8_PIN16_INIT_DIR << 0) | (DIO_u8_PIN17_INIT_DIR << 1) | (DIO_u8_PIN18_INIT_DIR << 2)
				| (DIO_u8_PIN19_INIT_DIR << 3) | (DIO_u8_PIN20_INIT_DIR << 4) | (DIO_u8_PIN21_INIT_DIR << 5)
				| (DIO_u8_PIN22_INIT_DIR << 6) | (DIO_u8_PIN23_INIT_DIR << 7);

	DIO_PU_DDRD = (DIO_u8_PIN24_INIT_DIR << 0) | (DIO_u8_PIN25_INIT_DIR << 1) | (DIO_u8_PIN26_INIT_DIR << 2)
				| (DIO_u8_PIN27_INIT_DIR << 3) | (DIO_u8_PIN28_INIT_DIR << 4) | (DIO_u8_PIN29_INIT_DIR << 5)
				| (DIO_u8_PIN30_INIT_DIR << 6) | (DIO_u8_PIN31_INIT_DIR << 7);
      /* Validation of the initialization values of all ports when if their directions are set as input */
  #if((DIO_u8_PIN0_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN0_INIT_VAL == DIO_u8_INIT_HIGH))
  #warning "The INIT direction of PIN0 is input so the pin init value will be automatically set as DIO_u8_INIT_LOW"
  #undef DIO_u8_PIN0_INIT_VAL
  #define DIO_u8_PIN0_INIT_VAL DIO_u8_INIT_LOW
  #endif

  #if((DIO_u8_PIN1_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN1_INIT_VAL == DIO_u8_INIT_HIGH))
  #warning "The INIT direction of PIN1 is input so the pin init value will be automatically set as DIO_u8_INIT_LOW"
  #undef DIO_u8_PIN1_INIT_VAL
  #define DIO_u8_PIN1_INIT_VAL DIO_u8_INIT_LOW
  #endif

  #if((DIO_u8_PIN2_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN2_INIT_VAL == DIO_u8_INIT_HIGH))
  #warning "The INIT direction of PIN2 is input so the pin init value will be automatically set as DIO_u8_INIT_LOW"
  #undef DIO_u8_PIN2_INIT_VAL
  #define DIO_u8_PIN2_INIT_VAL DIO_u8_INIT_LOW
  #endif

  #if((DIO_u8_PIN3_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN3_INIT_VAL == DIO_u8_INIT_HIGH))
  #warning "The INIT direction of PIN3 is input so the pin init value will be automatically set as DIO_u8_INIT_LOW"
  #undef DIO_u8_PIN3_INIT_VAL
  #define DIO_u8_PIN3_INIT_VAL DIO_u8_INIT_LOW
  #endif

  #if((DIO_u8_PIN4_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN4_INIT_VAL == DIO_u8_INIT_HIGH))
  #warning "The INIT direction of PIN4 is input so the pin init value will be automatically set as DIO_u8_INIT_LOW"
  #undef DIO_u8_PIN4_INIT_VAL
  #define DIO_u8_PIN4_INIT_VAL DIO_u8_INIT_LOW
  #endif

  #if((DIO_u8_PIN5_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN5_INIT_VAL == DIO_u8_INIT_HIGH))
  #warning "The INIT direction of PIN5 is input so the pin init value will be automatically set as DIO_u8_INIT_LOW"
  #undef DIO_u8_PIN5_INIT_VAL
  #define DIO_u8_PIN5_INIT_VAL DIO_u8_INIT_LOW
  #endif

  #if((DIO_u8_PIN6_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN6_INIT_VAL == DIO_u8_INIT_HIGH))
  #warning "The INIT direction of PIN6 is input so the pin init value will be automatically set as DIO_u8_INIT_LOW"
  #undef DIO_u8_PIN6_INIT_VAL
  #define DIO_u8_PIN6_INIT_VAL DIO_u8_INIT_LOW
  #endif

  #if((DIO_u8_PIN7_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN7_INIT_VAL == DIO_u8_INIT_HIGH))
  #warning "The INIT direction of PIN7 is input so the pin init value will be automatically set as DIO_u8_INIT_LOW"
  #undef DIO_u8_PIN7_INIT_VAL
  #define DIO_u8_PIN7_INIT_VAL DIO_u8_INIT_LOW
  #endif

  #if((DIO_u8_PIN8_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN8_INIT_VAL == DIO_u8_INIT_HIGH))
  #warning "The INIT direction of PIN8 is input so the pin init value will be automatically set as DIO_u8_INIT_LOW"
  #undef DIO_u8_PIN8_INIT_VAL
  #define DIO_u8_PIN8_INIT_VAL DIO_u8_INIT_LOW
  #endif

  #if((DIO_u8_PIN9_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN9_INIT_VAL == DIO_u8_INIT_HIGH))
  #warning "The INIT direction of PIN9 is input so the pin init value will be automatically set as DIO_u8_INIT_LOW"
  #undef DIO_u8_PIN9_INIT_VAL
  #define DIO_u8_PIN9_INIT_VAL DIO_u8_INIT_LOW
  #endif

  #if((DIO_u8_PIN10_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN10_INIT_VAL == DIO_u8_INIT_HIGH))
  #warning "The INIT direction of PIN10 is input so the pin init value will be automatically set as DIO_u8_INIT_LOW"
  #undef DIO_u8_PIN10_INIT_VAL
  #define DIO_u8_PIN10_INIT_VAL DIO_u8_INIT_LOW
  #endif

  #if((DIO_u8_PIN11_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN11_INIT_VAL == DIO_u8_INIT_HIGH))
  #warning "The INIT direction of PIN11 is input so the pin init value will be automatically set as DIO_u8_INIT_LOW"
  #undef DIO_u8_PIN11_INIT_VAL
  #define DIO_u8_PIN11_INIT_VAL DIO_u8_INIT_LOW
  #endif

  #if((DIO_u8_PIN12_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN12_INIT_VAL == DIO_u8_INIT_HIGH))
  #warning "The INIT direction of PIN12 is input so the pin init value will be automatically set as DIO_u8_INIT_LOW"
  #undef DIO_u8_PIN12_INIT_VAL
  #define DIO_u8_PIN12_INIT_VAL DIO_u8_INIT_LOW
  #endif

  #if((DIO_u8_PIN13_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN13_INIT_VAL == DIO_u8_INIT_HIGH))
  #warning "The INIT direction of PIN13 is input so the pin init value will be automatically set as DIO_u8_INIT_LOW"
  #undef DIO_u8_PIN13_INIT_VAL
  #define DIO_u8_PIN13_INIT_VAL DIO_u8_INIT_LOW
  #endif

  #if((DIO_u8_PIN14_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN14_INIT_VAL == DIO_u8_INIT_HIGH))
  #warning "The INIT direction of PIN14 is input so the pin init value will be automatically set as DIO_u8_INIT_LOW"
  #undef DIO_u8_PIN14_INIT_VAL
  #define DIO_u8_PIN14_INIT_VAL DIO_u8_INIT_LOW
  #endif

  #if((DIO_u8_PIN15_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN15_INIT_VAL == DIO_u8_INIT_HIGH))
  #warning "The INIT direction of PIN15 is input so the pin init value will be automatically set as DIO_u8_INIT_LOW"
  #undef DIO_u8_PIN15_INIT_VAL
  #define DIO_u8_PIN15_INIT_VAL DIO_u8_INIT_LOW
  #endif

  #if((DIO_u8_PIN16_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN16_INIT_VAL == DIO_u8_INIT_HIGH))
  #warning "The INIT direction of PIN16 is input so the pin init value will be automatically set as DIO_u8_INIT_LOW"
  #undef DIO_u8_PIN16_INIT_VAL
  #define DIO_u8_PIN16_INIT_VAL DIO_u8_INIT_LOW
  #endif

  #if((DIO_u8_PIN17_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN17_INIT_VAL == DIO_u8_INIT_HIGH))
  #warning "The INIT direction of PIN17 is input so the pin init value will be automatically set as DIO_u8_INIT_LOW"
  #undef DIO_u8_PIN17_INIT_VAL
  #define DIO_u8_PIN17_INIT_VAL DIO_u8_INIT_LOW
  #endif

  #if((DIO_u8_PIN18_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN18_INIT_VAL == DIO_u8_INIT_HIGH))
  #warning "The INIT direction of PIN18 is input so the pin init value will be automatically set as DIO_u8_INIT_LOW"
  #undef DIO_u8_PIN18_INIT_VAL
  #define DIO_u8_PIN18_INIT_VAL DIO_u8_INIT_LOW
  #endif

  #if((DIO_u8_PIN19_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN19_INIT_VAL == DIO_u8_INIT_HIGH))
  #warning "The INIT direction of PIN19 is input so the pin init value will be automatically set as DIO_u8_INIT_LOW"
  #undef DIO_u8_PIN19_INIT_VAL
  #define DIO_u8_PIN19_INIT_VAL DIO_u8_INIT_LOW
  #endif

  #if((DIO_u8_PIN20_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN20_INIT_VAL == DIO_u8_INIT_HIGH))
  #warning "The INIT direction of PIN20 is input so the pin init value will be automatically set as DIO_u8_INIT_LOW"
  #undef DIO_u8_PIN20_INIT_VAL
  #define DIO_u8_PIN20_INIT_VAL DIO_u8_INIT_LOW
  #endif

  #if((DIO_u8_PIN21_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN21_INIT_VAL == DIO_u8_INIT_HIGH))
  #warning "The INIT direction of PIN21 is input so the pin init value will be automatically set as DIO_u8_INIT_LOW"
  #undef DIO_u8_PIN21_INIT_VAL
  #define DIO_u8_PIN21_INIT_VAL DIO_u8_INIT_LOW
  #endif

  #if((DIO_u8_PIN22_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN22_INIT_VAL == DIO_u8_INIT_HIGH))
  #warning "The INIT direction of PIN22 is input so the pin init value will be automatically set as DIO_u8_INIT_LOW"
  #undef DIO_u8_PIN22_INIT_VAL
  #define DIO_u8_PIN22_INIT_VAL DIO_u8_INIT_LOW
  #endif

  #if((DIO_u8_PIN23_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN23_INIT_VAL == DIO_u8_INIT_HIGH))
  #warning "The INIT direction of PIN23 is input so the pin init value will be automatically set as DIO_u8_INIT_LOW"
  #undef DIO_u8_PIN23_INIT_VAL
  #define DIO_u8_PIN23_INIT_VAL DIO_u8_INIT_LOW
  #endif

  #if((DIO_u8_PIN24_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN24_INIT_VAL == DIO_u8_INIT_HIGH))
  #warning "The INIT direction of PIN24 is input so the pin init value will be automatically set as DIO_u8_INIT_LOW"
  #undef DIO_u8_PIN24_INIT_VAL
  #define DIO_u8_PIN24_INIT_VAL DIO_u8_INIT_LOW
  #endif

  #if((DIO_u8_PIN25_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN25_INIT_VAL == DIO_u8_INIT_HIGH))
  #warning "The INIT direction of PIN25 is input so the pin init value will be automatically set as DIO_u8_INIT_LOW"
  #undef DIO_u8_PIN25_INIT_VAL
  #define DIO_u8_PIN25_INIT_VAL DIO_u8_INIT_LOW
  #endif

  #if((DIO_u8_PIN26_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN26_INIT_VAL == DIO_u8_INIT_HIGH))
  #warning "The INIT direction of PIN26 is input so the pin init value will be automatically set as DIO_u8_INIT_LOW"
  #undef DIO_u8_PIN26_INIT_VAL
  #define DIO_u8_PIN26_INIT_VAL DIO_u8_INIT_LOW
  #endif

  #if((DIO_u8_PIN27_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN27_INIT_VAL == DIO_u8_INIT_HIGH))
  #warning "The INIT direction of PIN27 is input so the pin init value will be automatically set as DIO_u8_INIT_LOW"
  #undef DIO_u8_PIN27_INIT_VAL
  #define DIO_u8_PIN27_INIT_VAL DIO_u8_INIT_LOW
  #endif

  #if((DIO_u8_PIN28_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN28_INIT_VAL == DIO_u8_INIT_HIGH))
  #warning "The INIT direction of PIN28 is input so the pin init value will be automatically set as DIO_u8_INIT_LOW"
  #undef DIO_u8_PIN28_INIT_VAL
  #define DIO_u8_PIN28_INIT_VAL DIO_u8_INIT_LOW
  #endif

  #if((DIO_u8_PIN29_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN29_INIT_VAL == DIO_u8_INIT_HIGH))
  #warning "The INIT direction of PIN29 is input so the pin init value will be automatically set as DIO_u8_INIT_LOW"
  #undef DIO_u8_PIN29_INIT_VAL
  #define DIO_u8_PIN29_INIT_VAL DIO_u8_INIT_LOW
  #endif

  #if((DIO_u8_PIN30_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN30_INIT_VAL == DIO_u8_INIT_HIGH))
  #warning "The INIT direction of PIN30 is input so the pin init value will be automatically set as DIO_u8_INIT_LOW"
  #undef DIO_u8_PIN30_INIT_VAL
  #define DIO_u8_PIN30_INIT_VAL DIO_u8_INIT_LOW
  #endif

  #if((DIO_u8_PIN31_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN31_INIT_VAL == DIO_u8_INIT_HIGH))
  #warning "The INIT direction of PIN31 is input so the pin init value will be automatically set as DIO_u8_INIT_LOW"
  #undef DIO_u8_PIN31_INIT_VAL
  #define DIO_u8_PIN31_INIT_VAL DIO_u8_INIT_LOW
  #endif

	/*
	 * Setting the value of pins of PORT(A-D) according to initialized value assigned
	 * in the configuration file.
	 */
	DIO_PU_PORTA = ((DIO_u8_PIN0_INIT_VALUE << 0) | (DIO_u8_PIN1_INIT_VALUE << 1) | (DIO_u8_PIN2_INIT_VALUE << 2)
				| (DIO_u8_PIN3_INIT_VALUE << 3) | (DIO_u8_PIN4_INIT_VALUE << 4) | (DIO_u8_PIN5_INIT_VALUE << 5)
				| (DIO_u8_PIN6_INIT_VALUE << 6) | (DIO_u8_PIN7_INIT_VALUE << 7));

	DIO_PU_PORTB = ((DIO_u8_PIN8_INIT_DIR << 0) | (DIO_u8_PIN9_INIT_DIR << 1) | (DIO_u8_PIN10_INIT_DIR << 2)
				| (DIO_u8_PIN11_INIT_DIR << 3) | (DIO_u8_PIN12_INIT_DIR << 4) | (DIO_u8_PIN13_INIT_DIR << 5)
				| (DIO_u8_PIN14_INIT_DIR << 6) | (DIO_u8_PIN15_INIT_DIR << 7));

	DIO_PU_PORTC = ((DIO_u8_PIN16_INIT_DIR << 0) | (DIO_u8_PIN17_INIT_DIR << 1) | (DIO_u8_PIN18_INIT_DIR << 2)
				| (DIO_u8_PIN19_INIT_DIR << 3) | (DIO_u8_PIN20_INIT_DIR << 4) | (DIO_u8_PIN21_INIT_DIR << 5)
				| (DIO_u8_PIN22_INIT_DIR << 6) | (DIO_u8_PIN23_INIT_DIR << 7));

	DIO_PU_PORTD = ((DIO_u8_PIN24_INIT_DIR << 0) | (DIO_u8_PIN25_INIT_DIR << 1) | (DIO_u8_PIN26_INIT_DIR << 2)
				| (DIO_u8_PIN27_INIT_DIR << 3) | (DIO_u8_PIN28_INIT_DIR << 4) | (DIO_u8_PIN29_INIT_DIR << 5)
				| (DIO_u8_PIN30_INIT_DIR << 6) | (DIO_u8_PIN31_INIT_DIR << 7));
	return;
}

/*
 * Description: Function to set the direction of a specific pin in a specified port
 * Inputs: the pin number , the pin direction
 * Output: the Error state of the function
 */
u8 DIO_u8SetPinDirection (u8 Copy_u8PinNB,u8 Copy_u8Direction)
{
	/*Local Variables*/
	u8 Local_u8Error;
	u8 Local_u8PortId = Copy_u8PinNB/DIO_u8NUMBER_OF_PINS_IN_PORT;
	u8 Local_u8PinId = Copy_u8PinNB%DIO_u8NUMBER_OF_PINS_IN_PORT;

	/*checking the error possibilities of the inputs*/
	if ((Copy_u8PinNB >= DIO_u8MAXPINNB) ||
			((Copy_u8Direction != DIO_u8_PIN_OUTPUT) && (Copy_u8Direction != DIO_u8_PIN_INPUT)))
		Local_u8Error = ERROR_NOK;
	else
	{
		switch (Local_u8PortId)
		{
		case DIO_u8_PORT_A:
			ASSIGN_BIT (DIO_PU_DDRA,Local_u8PinId,Copy_u8Direction);
			break;
		case DIO_u8_PORT_B:
			ASSIGN_BIT (DIO_PU_DDRB,Local_u8PinId,Copy_u8Direction);
			break;
		case DIO_u8_PORT_C:
			ASSIGN_BIT (DIO_PU_DDRC,Local_u8PinId,Copy_u8Direction);
			break;
		case DIO_u8_PORT_D:
			ASSIGN_BIT (DIO_PU_DDRD,Local_u8PinId,Copy_u8Direction);
			break;
		}
		Local_u8Error = ERROR_OK;
	}
	/*Function return*/
	return Local_u8Error;
}

/*
 * Description: Function to set a specific pin in a specified port with a specified value (INPUT = 0,OUTPUT = 1)
 * Inputs: the pin number , the pin value
 * Output: the Error state of the function
*/
u8 DIO_u8SetPinValue (u8 Copy_u8PinNB, u8 Copy_u8Value)
{
	/*Local Variables*/
	u8 Local_u8Error;
	u8 Local_u8PortId = Copy_u8PinNB/DIO_u8NUMBER_OF_PINS_IN_PORT;
	u8 Local_u8PinId = Copy_u8PinNB%DIO_u8NUMBER_OF_PINS_IN_PORT;

	/*checking the error possibilities of the inputs*/
	if ((Copy_u8PinNB >= DIO_u8MAXPINNB) || ((Copy_u8PinNB != DIO_u8_HIGH) && (Copy_u8Value != DIO_u8_LOW)))
		Local_u8Error = ERROR_NOK;
	else
	{
		switch (Local_u8PortId)
		{
		case DIO_u8_PORT_A:
			ASSIGN_BIT (DIO_PU_PORTA,Local_u8PinId,Copy_u8Value);
			break;
		case DIO_u8_PORT_B:
			ASSIGN_BIT (DIO_PU_PORTB,Local_u8PinId,Copy_u8Value);
			break;
		case DIO_u8_PORT_C:
			ASSIGN_BIT (DIO_PU_PORTC,Local_u8PinId,Copy_u8Value);
			break;
		case DIO_u8_PORT_D:
			ASSIGN_BIT (DIO_PU_PORTD,Local_u8PinId,Copy_u8Value);
			break;
		}
		Local_u8Error = ERROR_OK;
	}
	/*Function return*/
	return Local_u8Error;
}

/*
 * Description: Function to get the value of a certain input pin in a specified port
 * Inputs: the pin number , the container variable which will hold the value on this pin
 * output: the Error state of the function
*/
u8 DIO_u8GetPinValue (u8 Copy_u8PinNB, u8 *Copy_u8PinValue)
{
	/*Local Variables*/
	u8 Local_u8Error;
	u8 Local_u8PortId = Copy_u8PinNB/DIO_u8NUMBER_OF_PINS_IN_PORT;
	u8 Local_u8PinId = Copy_u8PinNB%DIO_u8NUMBER_OF_PINS_IN_PORT;

	/*checking the error possibilities of the inputs*/
	if ((Copy_u8PinNB >= DIO_u8MAXPINNB) || (Copy_u8PinValue == NULL))
		Local_u8Error = ERROR_NOK;
	else
	{
		switch (Local_u8PortId)
		{
		case DIO_u8_PORT_A:
			*Copy_u8PinValue = GET_BIT(DIO_PU_PINA,Local_u8PinId);
			break;
		case DIO_u8_PORT_B:
			*Copy_u8PinValue = GET_BIT(DIO_PU_PINB,Local_u8PinId);
			break;
		case DIO_u8_PORT_C:
			*Copy_u8PinValue = GET_BIT(DIO_PU_PINC,Local_u8PinId);
			break;
		case DIO_u8_PORT_D:
			*Copy_u8PinValue = GET_BIT(DIO_PU_PIND,Local_u8PinId);
			break;
		}
		Local_u8Error = ERROR_OK;
	}
	/*Function return*/
	return Local_u8Error;
}

/*
 * Description: Function to set the direction of the whole pins in a specified port
 * Inputs: the port number and direction
 * Output: the Error state of the function
 */
u8 DIO_u8SetPortDirection (u8 Copy_u8PortNB,u8 Copy_u8Direction)
{
	/*Local Variables*/
	u8 Local_u8Error;

	/*checking the error possibilities of the inputs*/
	if ((Copy_u8PortNB >= DIO_u8MAXPortNB) ||
			((Copy_u8Direction != DIO_u8_PORT_OUTPUT) && (Copy_u8Direction != DIO_u8_PORT_INPUT)))
		Local_u8Error = ERROR_NOK;
	else
	{
		switch (Copy_u8PortNB)
		{
		case DIO_u8_PORT_A:
			ASSIGN_8BITS(DIO_PU_DDRA,Copy_u8Direction);
			break;
		case DIO_u8_PORT_B:
			ASSIGN_8BITS(DIO_PU_DDRB,Copy_u8Direction);
			break;
		case DIO_u8_PORT_C:
			ASSIGN_8BITS(DIO_PU_DDRC,Copy_u8Direction);
			break;
		case DIO_u8_PORT_D:
			ASSIGN_8BITS(DIO_PU_DDRD,Copy_u8Direction);
			break;
		}
		Local_u8Error = ERROR_OK;
	}
	/*Function return*/
	return Local_u8Error;
}

/*
 * Description: Function to set pins of a specified port with a specified value
 * Inputs: the port number , the port value
 * Output: the Error state of the function
 */
u8 DIO_u8SetPortValue (u8 Copy_u8PortNB, u8 Copy_u8Value)
{
	/*Local Variables*/
	u8 Local_u8Error;

	/*checking the error possibilities of the inputs*/
	if (Copy_u8PortNB >= DIO_u8MAXPortNB)
		Local_u8Error = ERROR_NOK;
	else
	{
		switch (Copy_u8PortNB)
		{
		case DIO_u8_PORT_A:
			ASSIGN_8BITS(DIO_PU_PORTA,Copy_u8Value);
			break;
		case DIO_u8_PORT_B:
			ASSIGN_8BITS(DIO_PU_PORTB,Copy_u8Value);
			break;
		case DIO_u8_PORT_C:
			ASSIGN_8BITS(DIO_PU_PORTC,Copy_u8Value);
			break;
		case DIO_u8_PORT_D:
			ASSIGN_8BITS(DIO_PU_PORTD,Copy_u8Value);
			break;
		}
		Local_u8Error = ERROR_OK;
	}
	/*Function return*/
	return Local_u8Error;
}

/*
 * Description: Function to get the value of a specified port
 * Inputs: the port number , the container variable which will hold the value on this port
 * output: the Error state of the function
 */
u8 DIO_u8GetPortValue (u8 Copy_u8PortNB, u8 *Copy_u8PortValue)
{
	/*Local Variables*/
	u8 Local_u8Error;

	/*checking the error possibilities of the inputs*/
	if (Copy_u8PortNB >= DIO_u8MAXPortNB || Copy_u8PortValue == NULL)
		Local_u8Error = ERROR_NOK;
	else
	{
		switch (Copy_u8PortNB)
		{
		case DIO_u8_PORT_A:
			*Copy_u8PortValue = DIO_PU_PINA;
			break;
		case DIO_u8_PORT_B:
			*Copy_u8PortValue = DIO_PU_PINB;
			break;
		case DIO_u8_PORT_C:
			*Copy_u8PortValue = DIO_PU_PINC;
			break;
		case DIO_u8_PORT_D:
			*Copy_u8PortValue = DIO_PU_PIND;
			break;
		}
		Local_u8Error = ERROR_OK;
	}
	/*Function return*/
	return Local_u8Error;
}
