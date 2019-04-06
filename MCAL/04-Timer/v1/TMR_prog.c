/****************************************************************/
/* Author: Mahmoud Alaa Elwelily                                */
/* Date: 28-Mar-19                                              */
/* Version: 01                                                  */
/* Description: Program file for Timer Driver for AVR ATmega32  */
/****************************************************************/
#include "STD_TYPES.h" 
#include "BIT_CALC.h" 
#include "TMR_interface.h" 
#include "TMR_priv.h" 
#include "TMR_config.h" 

/*Static variables which save the value of TCCR register corresponding to each timer*/
static u8 TMR_u8Timer0CtrlRegValue;
static u8 TMR_u8Timer1CtrlRegValue;
static u8 TMR_u8Timer2CtrlRegValue;

/*Static variable needed in the ISR of each OVF timer interrupt*/
static u32 TMR_u32Timer0Counter = UNSIGNED_MIN;
static u32 TMR_u32Timer1Counter = UNSIGNED_MIN;
static u32 TMR_u32Timer2Counter = UNSIGNED_MIN;

/*Static array where each element is a pointer to function of each one of overflow interrupt
 * for timer 0,1,2*/
static void (*PVCallBack[TMR_u8_NO_OF_TIMERS]) (void) = {NULL,NULL,NULL};

/*
 * Description: Function to set the initialized state and prescaler for each timer (0,1,2)
 * Inputs: none
 * Output: void
 */
void TMR_vInit (void)
{
	/* Setting the initialization for Timer0 */
	if (TMR_u8_TIMER0_INIT_STATE == TMR_u8_DISABLE)
	{
	   CLEAR_BIT(TMR_TCCR0,0);
	   CLEAR_BIT(TMR_TCCR0,1);
	   CLEAR_BIT(TMR_TCCR0,2);
	}
	else
	{
		if (TMR_u8_TIMER0_MODE == TMR_u8_NORMAL)
		{
			TMR_TCNT0 = TMR_u8_TIMER0_PRELOAD;

			/* Checking Timer/Counter0 Overflow Interrupt Enable bit */
			if (TMR_u8_TIMER0_OVF_INT == TMR_u8_EN_OVF_INT )
			{
				SET_BIT(TMR_TIMSK,0);
			}
			else
			{
				CLEAR_BIT(TMR_TIMSK,0);
			}

			/* Checking assigned Prescaler for Timer/Counter0 */
			switch (TMR_u8_TIMER0_PRESCALER)
			{
				case TMR_u8_NO_PRESCALER:
				{
					SET_BIT(TMR_TCCR0,0);
					break;
				}
				case TMR_u8_FREQ_OVER_8:
				{
					SET_BIT(TMR_TCCR0,1);
					break;
				}
				case TMR_u8_FREQ_OVER_64:
				{
					SET_BIT(TMR_TCCR0,0);
					SET_BIT(TMR_TCCR0,1);
					break;
				}
				case TMR_u8_FREQ_OVER_256:
				{
					SET_BIT(TMR_TCCR0,2);
					break;
				}
				case TMR_u8_FREQ_OVER_1024:
				{
					SET_BIT(TMR_TCCR0,0);
					SET_BIT(TMR_TCCR0,2);
					break;
				}
				default:
				{
					SET_BIT(TMR_TCCR0,0);
				}
			}
			TMR_u8Timer0CtrlRegValue = TMR_TCCR0;
		}
	}

	/* Setting the initialization for Timer1 */
	if (TMR_u8_TIMER1_INIT_STATE == TMR_u8_DISABLE)
	{
	   CLEAR_BIT(TMR_TCCR1B,0);
	   CLEAR_BIT(TMR_TCCR1B,1);
	   CLEAR_BIT(TMR_TCCR1B,2);
	}
	else
	{
		if (TMR_u8_TIMER1_MODE == TMR_u8_NORMAL)
		{
			TMR_TCNT1H = TMR_u8_TIMER1_PRELOAD>>8;
			TMR_TCNT1L = TMR_u8_TIMER1_PRELOAD;

			/* Checking Timer/Counter1 Overflow Interrupt Enable bit */
			if (TMR_u8_TIMER1_OVF_INT == TMR_u8_EN_OVF_INT )
			{
				SET_BIT(TMR_TIMSK,2);
			}
			else
			{
				CLEAR_BIT(TMR_TIMSK,2);
			}
			/* Checking assigned Prescaler for Timer/Counter1 */
			switch (TMR_u8_TIMER1_PRESCALER)
			{
				case TMR_u8_NO_PRESCALER:
				{
					SET_BIT(TMR_TCCR1B,0);
					break;
				}
				case TMR_u8_FREQ_OVER_8:
				{
					SET_BIT(TMR_TCCR1B,1);
					break;
				}
				case TMR_u8_FREQ_OVER_64:
				{
					SET_BIT(TMR_TCCR1B,0);
					SET_BIT(TMR_TCCR1B,1);
					break;
				}
				case TMR_u8_FREQ_OVER_256:
				{
					SET_BIT(TMR_TCCR1B,2);
					break;
				}
				case TMR_u8_FREQ_OVER_1024:
				{
					SET_BIT(TMR_TCCR1B,0);
					SET_BIT(TMR_TCCR1B,2);
					break;
				}
				default:
				{
					SET_BIT(TMR_TCCR1B,0);
				}
			}
			TMR_u8Timer1CtrlRegValue = TMR_TCCR1B;
		}
	}


	/* Setting the initialization for Timer2 */
	if (TMR_u8_TIMER2_INIT_STATE == TMR_u8_DISABLE)
	{
	   CLEAR_BIT(TMR_TCCR2,0);
	   CLEAR_BIT(TMR_TCCR2,1);
	   CLEAR_BIT(TMR_TCCR2,2);
	}
	else
	{
		if (TMR_u8_TIMER2_MODE == TMR_u8_NORMAL)
		{
			TMR_TCNT2 = TMR_u8_TIMER2_PRELOAD;

			/* Checking Timer/Counter0 Overflow Interrupt Enable bit */
			if (TMR_u8_TIMER2_OVF_INT == TMR_u8_EN_OVF_INT )
			{
				SET_BIT(TMR_TIMSK,6);
			}
			else
			{
				CLEAR_BIT(TMR_TIMSK,6);
			}

			/* Checking assigned Prescaler for Timer/Counter2 */
			switch (TMR_u8_TIMER2_PRESCALER)
			{
				case TMR_u8_NO_PRESCALER:
				{
					SET_BIT(TMR_TCCR2,0);
					break;
				}
				case TMR_u8_FREQ_OVER_8:
				{
					SET_BIT(TMR_TCCR2,1);
					break;
				}
				case TMR_u8_FREQ_OVER_32:
				{
					SET_BIT(TMR_TCCR2,0);
					SET_BIT(TMR_TCCR2,1);
					break;
				}
				case TMR_u8_FREQ_OVER_64:
				{
					SET_BIT(TMR_TCCR2,2);
					break;
				}
				case TMR_u8_FREQ_OVER_128:
				{
					SET_BIT(TMR_TCCR2,0);
					SET_BIT(TMR_TCCR2,2);
					break;
				}
				case TMR_u8_FREQ_OVER_256:
				{
					SET_BIT(TMR_TCCR2,1);
					SET_BIT(TMR_TCCR2,2);
					break;
				}
				case TMR_u8_FREQ_OVER_1024:
				{
					SET_BIT(TMR_TCCR2,0);
					SET_BIT(TMR_TCCR2,1);
					SET_BIT(TMR_TCCR2,2);
					break;
				}
			}
			TMR_u8Timer2CtrlRegValue = TMR_TCCR2;
		}
	}
}

/*
 * Description: Function to enable one of the available timers in AVR ATmega32 (0,1,2)
 * Inputs: Timer Number
 * Output: the Error state of the function
 */
u8 TMR_u8EnableTimer (u8 Copy_u8TimerNb)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error = ERROR_OK;
	if (Copy_u8TimerNb >= TMR_u8_NO_OF_TIMERS)
	{
		Local_u8Error = ERROR_NOK;
	}
	else
	{
		switch (Copy_u8TimerNb)
		{
		   case TMR_u8_TIMER0:
		   {
			   TMR_TCCR0 = TMR_u8Timer0CtrlRegValue;
			   break;
		   }
		   case TMR_u8_TIMER1:
		   {
			   TMR_TCCR1B = TMR_u8Timer1CtrlRegValue;
			   break;
		   }
		   case TMR_u8_TIMER2:
		   {
			   TMR_TCCR2 = TMR_u8Timer2CtrlRegValue;
			   break;
		   }
		}
	}
	/*Function return*/
	return Local_u8Error;
}

/*
 * Description: Function to disable one of the available timers in AVR ATmega32 (0,1,2)
 * Inputs: Timer Number
 * Output: the Error state of the function
 */
u8 TMR_u8DisableTimer (u8 Copy_u8TimerNb)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error = ERROR_OK;
	if (Copy_u8TimerNb >= TMR_u8_NO_OF_TIMERS)
	{
		Local_u8Error = ERROR_NOK;
	}
	else
	{
		switch (Copy_u8TimerNb)
		{
		   case TMR_u8_TIMER0:
		   {
			   CLEAR_BIT(TMR_TCCR0,0);
			   CLEAR_BIT(TMR_TCCR0,1);
			   CLEAR_BIT(TMR_TCCR0,2);
			   break;
		   }
		   case TMR_u8_TIMER1:
		   {
			   CLEAR_BIT(TMR_TCCR1B,0);
			   CLEAR_BIT(TMR_TCCR1B,1);
			   CLEAR_BIT(TMR_TCCR1B,2);
			   break;
		   }
		   case TMR_u8_TIMER2:
		   {
			   CLEAR_BIT(TMR_TCCR2,0);
			   CLEAR_BIT(TMR_TCCR2,1);
			   CLEAR_BIT(TMR_TCCR2,2);
			   break;
		   }
		}
	}
	/*Function return*/
	return Local_u8Error;
}

/*
 * Description: Function to set the callback function for a certain timer in case of firing its interrupt
 * Inputs: the number of the available timer (0,1,2) and a pointer to its callback function
 * Output: the Error state of the function
 */
u8 TMR_u8SetCallBack (u8 Copy_u8TimerNb,void(*Copy_PVCallBack)(void))
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error = ERROR_OK;
	if (Copy_u8TimerNb >= TMR_u8_NO_OF_TIMERS)
	{
		Local_u8Error = ERROR_NOK;
	}
	else
	{
		PVCallBack[Copy_u8TimerNb] = Copy_PVCallBack;
	}
	/*Function return*/
	return Local_u8Error;
}

/*The ISR of Timer/Counter0 Overflow interrupt*/
void __vector_11 (void)
{
	if (PVCallBack[TMR_u8_TIMER0] != NULL)
	{
		TMR_u32Timer0Counter++;
		if (TMR_u32Timer0Counter == TMR_u32_TIMER0_REQ_OVF_CNT)
		{
			TMR_u32Timer0Counter = UNSIGNED_MIN;
			TMR_TCNT0 = TMR_u8_TIMER0_PRELOAD;
			PVCallBack[TMR_u8_TIMER0]();   /*The ISR action*/
		}
	}
    return;
}

/*The ISR of Timer/Counter1 Overflow interrupt*/
void __vector_9 (void)
{
	if (PVCallBack[TMR_u8_TIMER1] != NULL)
	{
		TMR_u32Timer1Counter++;
		if (TMR_u32Timer1Counter == TMR_u32_TIMER1_REQ_OVF_CNT)
		{
			TMR_u32Timer1Counter = UNSIGNED_MIN;
			TMR_TCNT1H = TMR_u8_TIMER1_PRELOAD>>8;
			TMR_TCNT1L = TMR_u8_TIMER1_PRELOAD;
			PVCallBack[TMR_u8_TIMER1]();   /*The ISR action*/
		}
	}
    return;
}

/*The ISR of Timer/Counter2 Overflow interrupt*/
void __vector_5 (void)
{
	if (PVCallBack[TMR_u8_TIMER2] != NULL)
	{
		TMR_u32Timer2Counter++;
		if (TMR_u32Timer2Counter == TMR_u32_TIMER2_REQ_OVF_CNT)
		{
			TMR_u32Timer2Counter = UNSIGNED_MIN;
			TMR_TCNT2 = TMR_u8_TIMER2_PRELOAD;
			PVCallBack[TMR_u8_TIMER2]();   /*The ISR action*/
		}
	}
    return;
}
