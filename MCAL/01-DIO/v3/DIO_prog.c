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
	DIO_PU_DDRA = CONC_8BITS (DIO_u8_PIN0_INIT_DIR,
			DIO_u8_PIN1_INIT_DIR,
			DIO_u8_PIN2_INIT_DIR,
			DIO_u8_PIN3_INIT_DIR,
			DIO_u8_PIN4_INIT_DIR,
			DIO_u8_PIN5_INIT_DIR,
			DIO_u8_PIN6_INIT_DIR,
			DIO_u8_PIN7_INIT_DIR);

	DIO_PU_DDRB = CONC_8BITS (DIO_u8_PIN8_INIT_DIR,
			DIO_u8_PIN9_INIT_DIR,
			DIO_u8_PIN10_INIT_DIR,
			DIO_u8_PIN11_INIT_DIR,
			DIO_u8_PIN12_INIT_DIR,
			DIO_u8_PIN13_INIT_DIR,
			DIO_u8_PIN14_INIT_DIR,
			DIO_u8_PIN15_INIT_DIR);

	DIO_PU_DDRC = CONC_8BITS (DIO_u8_PIN16_INIT_DIR,
			DIO_u8_PIN17_INIT_DIR,
			DIO_u8_PIN18_INIT_DIR,
			DIO_u8_PIN19_INIT_DIR,
			DIO_u8_PIN20_INIT_DIR,
			DIO_u8_PIN21_INIT_DIR,
			DIO_u8_PIN22_INIT_DIR,
			DIO_u8_PIN23_INIT_DIR);

	DIO_PU_DDRD = CONC_8BITS (DIO_u8_PIN24_INIT_DIR,
			DIO_u8_PIN25_INIT_DIR,
			DIO_u8_PIN26_INIT_DIR,
			DIO_u8_PIN27_INIT_DIR,
			DIO_u8_PIN28_INIT_DIR,
			DIO_u8_PIN29_INIT_DIR,
			DIO_u8_PIN30_INIT_DIR,
			DIO_u8_PIN31_INIT_DIR);

	/*
	 * Setting the value of pins of PORT(A-D) according to the initialized states assigned in the configuration file.
	 */
	DIO_PU_PORTA = CONC_8BITS (DIO_u8_PIN0_INIT_STATE,
			DIO_u8_PIN1_INIT_STATE,
			DIO_u8_PIN2_INIT_STATE,
			DIO_u8_PIN3_INIT_STATE,
			DIO_u8_PIN4_INIT_STATE,
			DIO_u8_PIN5_INIT_STATE,
			DIO_u8_PIN6_INIT_STATE,
			DIO_u8_PIN7_INIT_STATE);

	DIO_PU_PORTB = CONC_8BITS (DIO_u8_PIN8_INIT_STATE,
			DIO_u8_PIN9_INIT_STATE,
			DIO_u8_PIN10_INIT_STATE,
			DIO_u8_PIN11_INIT_STATE,
			DIO_u8_PIN12_INIT_STATE,
			DIO_u8_PIN13_INIT_STATE,
			DIO_u8_PIN14_INIT_STATE,
			DIO_u8_PIN15_INIT_STATE);

	DIO_PU_PORTC = CONC_8BITS (DIO_u8_PIN16_INIT_STATE,
			DIO_u8_PIN17_INIT_STATE,
			DIO_u8_PIN18_INIT_STATE,
			DIO_u8_PIN19_INIT_STATE,
			DIO_u8_PIN20_INIT_STATE,
			DIO_u8_PIN21_INIT_STATE,
			DIO_u8_PIN22_INIT_STATE,
			DIO_u8_PIN23_INIT_STATE);

	DIO_PU_PORTD = CONC_8BITS (DIO_u8_PIN24_INIT_STATE,
			DIO_u8_PIN25_INIT_STATE,
			DIO_u8_PIN26_INIT_STATE,
			DIO_u8_PIN27_INIT_STATE,
			DIO_u8_PIN28_INIT_STATE,
			DIO_u8_PIN29_INIT_STATE,
			DIO_u8_PIN30_INIT_STATE,
			DIO_u8_PIN31_INIT_STATE);

	return;
}

/*
 * Description: Function to set the direction of a specific pin in a specified port
 * Inputs: the pin number , the pin direction
 * Output: the Error state of the function
 */
u8 DIO_u8SetPinDirection (u8 Copy_u8PinNb,u8 Copy_u8Direction)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error;

	/*checking the error possibilities of the inputs*/
	if((Copy_u8PinNb >= DIO_u8MAXPINNB) ||
			((Copy_u8Direction != DIO_u8_PIN_OUTPUT) && (Copy_u8Direction != DIO_u8_PIN_INPUT)))
	{
		Local_u8Error = ERROR_NOK;
	}
	else
	{
		switch (Copy_u8Direction)
		{
		case (DIO_u8_PIN_OUTPUT):  /* if the port direction is output */
				{
			/* if the assigned pin is in PORT A */
			if(Copy_u8PinNb < DIO_u8_PIN8)
			{
				ASSIGN_BIT (DIO_PU_DDRA,Copy_u8PinNb,DIO_u8_PRIV_PIN_OUTPUT);
			}
			/* if the assigned pin is in PORT B */
			else if((Copy_u8PinNb >= DIO_u8_PIN8) && (Copy_u8PinNb < DIO_u8_PIN16))
			{
				ASSIGN_BIT (DIO_PU_DDRB,Copy_u8PinNb-DIO_u8_PIN8,DIO_u8_PRIV_PIN_OUTPUT);
			}
			/* if the assigned pin is in PORT C */
			else if((Copy_u8PinNb >= DIO_u8_PIN16) && (Copy_u8PinNb < DIO_u8_PIN24))
			{
				ASSIGN_BIT (DIO_PU_DDRC,Copy_u8PinNb-DIO_u8_PIN16,DIO_u8_PRIV_PIN_OUTPUT);
			}
			/* if the assigned pin is in PORT D */
			else
			{
				ASSIGN_BIT (DIO_PU_DDRD,Copy_u8PinNb-DIO_u8_PIN24,DIO_u8_PRIV_PIN_OUTPUT);
			}
			break;
				}
		case(DIO_u8_PIN_INPUT):  /* if the port direction is input */
				{
			/* if the assigned pin is in PORT A */
			if(Copy_u8PinNb < DIO_u8_PIN8)
			{
				ASSIGN_BIT (DIO_PU_DDRA,Copy_u8PinNb,DIO_u8_PRIV_PIN_INPUT);
			}
			/* if the assigned pin is in PORT B */
			else if((Copy_u8PinNb >= DIO_u8_PIN8) && (Copy_u8PinNb < DIO_u8_PIN16))
			{
				ASSIGN_BIT (DIO_PU_DDRB,Copy_u8PinNb-DIO_u8_PIN8,DIO_u8_PRIV_PIN_INPUT);
			}
			/* if the assigned pin is in PORT C */
			else if((Copy_u8PinNb >= DIO_u8_PIN16) && (Copy_u8PinNb < DIO_u8_PIN24))
			{
				ASSIGN_BIT (DIO_PU_DDRC,Copy_u8PinNb-DIO_u8_PIN16,DIO_u8_PRIV_PIN_INPUT);
			}
			/* if the assigned pin is in PORT D */
			else
			{
				ASSIGN_BIT (DIO_PU_DDRD,Copy_u8PinNb-DIO_u8_PIN24,DIO_u8_PRIV_PIN_INPUT);
			}
			break;
				}
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
u8 DIO_u8SetPinValue (u8 Copy_u8PinNb, u8 Copy_u8Value)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error;

	/*checking the error possibilities of the inputs*/
	if ((Copy_u8PinNb >= DIO_u8MAXPINNB) || ((Copy_u8Value != DIO_u8_PIN_HIGH) && (Copy_u8Value != DIO_u8_PIN_LOW)))
	{
		Local_u8Error = ERROR_NOK;
	}
	else
	{
		switch (Copy_u8Value)
		{
		case (DIO_u8_PIN_HIGH):   /* if the pin value is high */
				{
			/* if the assigned pin is in PORT A */
			if(Copy_u8PinNb < DIO_u8_PIN8)
			{
				ASSIGN_BIT (DIO_PU_PORTA,Copy_u8PinNb,DIO_u8_PRIV_PIN_HIGH);
			}
			/* if the assigned pin is in PORT B */
			else if((Copy_u8PinNb >= DIO_u8_PIN8) && (Copy_u8PinNb < DIO_u8_PIN16))
			{
				ASSIGN_BIT (DIO_PU_PORTB,Copy_u8PinNb-DIO_u8_PIN8,DIO_u8_PRIV_PIN_HIGH);
			}
			/* if the assigned pin is in PORT C */
			else if((Copy_u8PinNb >= DIO_u8_PIN16) && (Copy_u8PinNb < DIO_u8_PIN24))
			{
				ASSIGN_BIT (DIO_PU_PORTC,Copy_u8PinNb-DIO_u8_PIN16,DIO_u8_PRIV_PIN_HIGH);
			}
			/* if the assigned pin is in PORT D */
			else
			{
				ASSIGN_BIT (DIO_PU_PORTD,Copy_u8PinNb-DIO_u8_PIN24,DIO_u8_PRIV_PIN_HIGH);
			}
			break;
				}
		case(DIO_u8_PIN_LOW):   /* if the pin value is low */
				{
			/* if the assigned pin is in PORT A */
			if(Copy_u8PinNb < DIO_u8_PIN8)
			{
				ASSIGN_BIT (DIO_PU_PORTA,Copy_u8PinNb,DIO_u8_PRIV_PIN_LOW);
			}
			/* if the assigned pin is in PORT B */
			else if((Copy_u8PinNb >= DIO_u8_PIN8) && (Copy_u8PinNb < DIO_u8_PIN16))
			{
				ASSIGN_BIT (DIO_PU_PORTB,Copy_u8PinNb-DIO_u8_PIN8,DIO_u8_PRIV_PIN_LOW);
			}
			/* if the assigned pin is in PORT C */
			else if((Copy_u8PinNb >= DIO_u8_PIN16) && (Copy_u8PinNb < DIO_u8_PIN24))
			{
				ASSIGN_BIT (DIO_PU_PORTC,Copy_u8PinNb-DIO_u8_PIN16,DIO_u8_PRIV_PIN_LOW);
			}
			/* if the assigned pin is in PORT D */
			else
			{
				ASSIGN_BIT (DIO_PU_PORTD,Copy_u8PinNb-DIO_u8_PIN24,DIO_u8_PRIV_PIN_LOW);
			}
			break;
				}
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
u8 DIO_u8GetPinValue (u8 Copy_u8PinNb,u8 *Copy_u8PinValue)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error;

	/*checking the error possibilities of the inputs*/
	if ((Copy_u8PinNb >= DIO_u8MAXPINNB) || (Copy_u8PinValue == NULL))
	{
		Local_u8Error = ERROR_NOK;
	}
	else
	{
		/* if the assigned pin is in PORT A */
		if(Copy_u8PinNb < DIO_u8_PIN8)
		{
			*Copy_u8PinValue = GET_BIT(DIO_PU_PINA,Copy_u8PinNb);
		}
		/* if the assigned pin is in PORT B */
		else if((Copy_u8PinNb >= DIO_u8_PIN8) && (Copy_u8PinNb < DIO_u8_PIN16))
		{
			*Copy_u8PinValue = GET_BIT(DIO_PU_PINB,Copy_u8PinNb-DIO_u8_PIN8);
		}
		/* if the assigned pin is in PORT C */
		else if((Copy_u8PinNb >= DIO_u8_PIN16) && (Copy_u8PinNb < DIO_u8_PIN24))
		{
			*Copy_u8PinValue = GET_BIT(DIO_PU_PINC,Copy_u8PinNb-DIO_u8_PIN16);
		}
		/* if the assigned pin is in PORT D */
		else
		{
			*Copy_u8PinValue = GET_BIT(DIO_PU_PIND,Copy_u8PinNb-DIO_u8_PIN24);
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
u8 DIO_u8SetPortDirection (u8 Copy_u8PortNb,u8 Copy_u8Direction)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error;

	/*checking the error possibilities of the inputs*/
	if((Copy_u8PortNb >= DIO_u8MAXPortNB))
	{
		Local_u8Error = ERROR_NOK;
	}
	else
	{
		/* if the assigned port is PORT A */
		if(Copy_u8PortNb == DIO_u8_PORT_A)
		{
			ASSIGN_8BITS (DIO_PU_DDRA,Copy_u8Direction);
		}
		/* if the assigned port is PORT B */
		else if(Copy_u8PortNb == DIO_u8_PORT_B)
		{
			ASSIGN_8BITS (DIO_PU_DDRB,Copy_u8Direction);
		}
		/* if the assigned port is PORT C */
		else if(Copy_u8PortNb == DIO_u8_PORT_C)
		{
			ASSIGN_8BITS (DIO_PU_DDRC,Copy_u8Direction);
		}
		/* if the assigned port is PORT D */
		else if(Copy_u8PortNb == DIO_u8_PORT_D)
		{
			ASSIGN_8BITS (DIO_PU_DDRD,Copy_u8Direction);
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
u8 DIO_u8SetPortValue (u8 Copy_u8PortNb, u8 Copy_u8Value)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error;

	/*checking the error possibilities of the inputs*/
	if (Copy_u8PortNb >= DIO_u8MAXPortNB)
		Local_u8Error = ERROR_NOK;
	else
	{
		/* if the assigned port is PORT A */
		if(Copy_u8PortNb == DIO_u8_PORT_A)
		{
			ASSIGN_8BITS (DIO_PU_PORTA,Copy_u8Value);
		}
		/* if the assigned port is PORT B */
		else if(Copy_u8PortNb == DIO_u8_PORT_B)
		{
			ASSIGN_8BITS (DIO_PU_PORTB,Copy_u8Value);
		}
		/* if the assigned port is PORT C */
		else if(Copy_u8PortNb == DIO_u8_PORT_C)
		{
			ASSIGN_8BITS (DIO_PU_PORTC,Copy_u8Value);
		}
		/* if the assigned port is PORT D */
		else if(Copy_u8PortNb == DIO_u8_PORT_D)
		{
			ASSIGN_8BITS (DIO_PU_PORTD,Copy_u8Value);
		}
		Local_u8Error = ERROR_OK;
	}
  return Local_u8Error;
}

/*
 * Description: Function to get the value of a specified port
 * Inputs: the port number , the container variable which will hold the value on this port
 * output: the Error state of the function
 */
u8 DIO_u8GetPortValue (u8 Copy_u8PortNb, u8 *Copy_u8PortValue)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error;

	/*checking the error possibilities of the inputs*/
	if (Copy_u8PortNb >= DIO_u8MAXPortNB || Copy_u8PortValue == NULL)
		Local_u8Error = ERROR_NOK;
	else
	{
		/* if the assigned port is in PORT A */
		if(Copy_u8PortNb == DIO_u8_PORT_A)
		{
			*Copy_u8PortValue = DIO_PU_PINA;
		}
		/* if the assigned port is in PORT B */
		else if(Copy_u8PortNb == DIO_u8_PORT_B)
		{
			*Copy_u8PortValue = DIO_PU_PINB;
		}
		/* if the assigned port is in PORT C */
		else if(Copy_u8PortNb == DIO_u8_PORT_C)
		{
			*Copy_u8PortValue = DIO_PU_PINC;
		}
		/* if the assigned port is in PORT D */
		else if(Copy_u8PortNb == DIO_u8_PORT_D)
		{
			*Copy_u8PortValue = DIO_PU_PIND;
		}
		Local_u8Error = ERROR_OK;
	}

	/*Function return*/
	return Local_u8Error;
}
