/**********************************************************/
/* Author: Mahmoud Alaa Elwelily                          */
/* Date: 20-Mar-19                                        */
/* Version: 01                                            */
/* Description: Program file for External INT Driver      */
/* supported by AVR ATmega32                            */
/* This driver is mainly for interrupts INT0,INT1,INT2    */
/* specified for pins D0,D1,D2                            */
/**********************************************************/
#include "STD_TYPES.h" 
#include "BIT_CALC.h" 
#include "EXTINT_interface.h"
#include "EXTINT_priv.h"
#include "EXTINT_config.h"

/*Static array where each element is a pointer to function of each one of the external int (INT0,INT1-INT2)*/
static void (*PVCallBack[EXTINT_u8_NO_OF_EXTINT]) (void) = {NULL,NULL,NULL};

/*
 * Description: Function to initialize the external interrupts (INT0,INT1,INT2) according to the configurations
 * Inputs: void
 * Output: void
 */
void EXTINT_vInit (void)
{
	ASSIGN_BIT(EXTINT_GICR,EXTINT_u8_INT0_BIT,EXTINT_U8_INT0_INITSTATE);
	ASSIGN_BIT(EXTINT_GICR,EXTINT_u8_INT1_BIT,EXTINT_U8_INT1_INITSTATE);
	ASSIGN_BIT(EXTINT_GICR,EXTINT_u8_INT2_BIT,EXTINT_U8_INT2_INITSTATE);

	EXTINT_MCUCR |= EXTINT_U8_INT0_SNSLVL<<EXTINT_u8_INT0_OFFS;
	EXTINT_MCUCR |= EXTINT_U8_INT1_SNSLVL<<EXTINT_u8_INT1_OFFS;

	if ((EXTINT_U8_INT2_SNSLVL == EXTINT_u8_LOW_LEVEL) || (EXTINT_U8_INT2_SNSLVL == EXTINT_u8_ON_CHANGE))
	{
		CLEAR_BIT(EXTINT_MCUCSR,EXTINT_u8_INT2_OFFS);
	}
	return;
}

/*
 * Description: Function to enable one of the required external interrupts (INT0,INT1,INT2)
 * Inputs: the number of the external interrupt (0,1,2)
 * Output: the Error state of the function
 */
u8 EXTINT_u8Enable (u8 Copy_u8IntNb)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error = ERROR_OK;
	if (Copy_u8IntNb >= EXTINT_u8_NO_OF_EXTINT)
	{
		Local_u8Error = ERROR_NOK;
	}
	else
	{
		switch (Copy_u8IntNb)
		{
		  case 0:
		  {
			  SET_BIT(EXTINT_GICR,EXTINT_u8_INT0_BIT);
			  break;
		  }
		  case 1:
		  {
			  SET_BIT(EXTINT_GICR,EXTINT_u8_INT1_BIT);
			  break;
		  }
		  case 2:
		  {
			  SET_BIT(EXTINT_GICR,EXTINT_u8_INT2_BIT);
			  break;
		  }
		}
	}
	/*Function return*/
	return Local_u8Error;
}

/*
 * Description: Function to disable one of the required external interrupts (INT0,INT1,INT2)
 * Inputs: the number of the external interrupt (0,1,2)
 * Output: the Error state of the function
 */
u8 EXTINT_u8Disable(u8 Copy_u8IntNb)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error = ERROR_OK;
	if (Copy_u8IntNb >= EXTINT_u8_NO_OF_EXTINT)
	{
		Local_u8Error = ERROR_NOK;
	}
	else
	{
		switch (Copy_u8IntNb)
		{
		  case 0:
		  {
			  CLEAR_BIT(EXTINT_GICR,EXTINT_u8_INT0_BIT);
			  break;
		  }
		  case 1:
		  {
			  CLEAR_BIT(EXTINT_GICR,EXTINT_u8_INT1_BIT);
			  break;
		  }
		  case 2:
		  {
			  CLEAR_BIT(EXTINT_GICR,EXTINT_u8_INT2_BIT);
			  break;
		  }
		}
	}
	/*Function return*/
	return Local_u8Error;
}

/*
 * Description: Function to set the sense level of the required external interrupts (INT0,INT1,INT2)
 * Inputs: the number of the external interrupt (0,1,2) and the required sense level
 * Output: the Error state of the function
 */
u8 EXTINT_u8SetSenseLevel(u8 Copy_u8IntNb,u8 Copy_u8SenseLevel)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error = ERROR_OK;
	if (Copy_u8IntNb >= EXTINT_u8_NO_OF_EXTINT)
	{
		Local_u8Error = ERROR_NOK;
	}
	else
	{
		switch (Copy_u8IntNb)
		{
		  case 0:
		  {
			  EXTINT_MCUCR |= Copy_u8SenseLevel<<EXTINT_u8_INT0_OFFS;
			  break;
		  }
		  case 1:
		  {
			  EXTINT_MCUCR |= Copy_u8SenseLevel<<EXTINT_u8_INT1_OFFS;
			  break;
		  }
		  case 2:
		  {
			  if ((Copy_u8SenseLevel == EXTINT_u8_LOW_LEVEL) || (Copy_u8SenseLevel == EXTINT_u8_ON_CHANGE))
			  {
				  Local_u8Error = ERROR_NOK;
				  break;
			  }
			  else if (Copy_u8SenseLevel == EXTINT_u8_FALLING_EDG)
			  {
				  CLEAR_BIT(EXTINT_MCUCSR,EXTINT_u8_INT2_OFFS);
				  break;
			  }
			  else if (Copy_u8SenseLevel == EXTINT_u8_RISING_EDG)
			  {
				  SET_BIT(EXTINT_MCUCSR,EXTINT_u8_INT2_OFFS);
				  break;
			  }
		  }
		}
	}
	/*Function return*/
	return Local_u8Error;
}

/*
 * Description: Function to set the callback function for the required external interrupts (INT0,INT1,INT2)
 * Inputs: the number of the external interrupt (0,1,2) and the callback function
 * Output: the Error state of the function
 */
u8 EXTINT_u8SetCallBack(u8 Copy_u8IntNb,void(*Copy_PVCallBack)(void))
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error = ERROR_OK;
	if (Copy_u8IntNb >= EXTINT_u8_NO_OF_EXTINT)
	{
		Local_u8Error = ERROR_NOK;
	}
	else
	{
		PVCallBack[Copy_u8IntNb] = Copy_PVCallBack;
	}
	/*Function return*/
	return Local_u8Error;
}

/*The ISR of the external interrupt INT0*/
void __vector_1 (void)
{
	if (PVCallBack[EXTINT_u8_INT0] != NULL)
		PVCallBack[EXTINT_u8_INT0]();
    return;
}

/*The ISR of the external interrupt INT1*/
void __vector_2 (void)
{
	if (PVCallBack[EXTINT_u8_INT1] != NULL)
		PVCallBack[EXTINT_u8_INT1]();
    return;
}

/*The ISR of the external interrupt INT2*/
void __vector_3 (void)
{
	if (PVCallBack[EXTINT_u8_INT2] != NULL)
		PVCallBack[EXTINT_u8_INT2]();
    return;
}
