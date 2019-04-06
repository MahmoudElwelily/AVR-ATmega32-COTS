/**************************************************************/
/* Author: Mahmoud Alaa Elwelily                              */
/* Date: 20-Mar-19                                            */
/* Version: 01                                                */
/* Description: Program file for MCU Driver for AVR ATmega32  */
/**************************************************************/
#include "STD_TYPES.h" 
#include "BIT_CALC.h" 
#include "MCU_interface.h" 
#include "MCU_priv.h" 
#include "MCU_config.h"    

/*Static variable used to check whether the interrupt enable or disable functions are called once or twice*/
static u8 Global_u8McuEnFlag = UNSIGNED_MIN;
static u8 Global_u8McuDisFlag = UNSIGNED_MIN;

u8 MCU_u8EnableGlobalINT(void)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error = ERROR_OK;
	if (Global_u8McuEnFlag != UNSIGNED_MIN)
	{
		Local_u8Error = ERROR_NOK;
	}
	else
	{
		SET_BIT(MCU_SREG,MCU_GLOBAL_INT_BIT);
		Global_u8McuEnFlag = 1;
		Global_u8McuDisFlag = 0;
	}
	/*Function return*/
	return Local_u8Error;
}

u8 MCU_u8DisableGlobalINT(void)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error = ERROR_OK;
	if (Global_u8McuDisFlag != UNSIGNED_MIN)
	{
		Local_u8Error = ERROR_NOK;
	}
	else
	{
		CLEAR_BIT(MCU_SREG,MCU_GLOBAL_INT_BIT);
		Global_u8McuDisFlag = 1;
		Global_u8McuEnFlag = 0;
	}
	/*Function return*/
	return Local_u8Error;
}
