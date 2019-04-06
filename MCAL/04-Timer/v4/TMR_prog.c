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

static u32 TMR_u32ReqTimer0Cntr = UNSIGNED_MIN;
static u32 TMR_u32ReqTimer1Cntr = UNSIGNED_MIN;
static u32 TMR_u32ReqTimer2Cntr = UNSIGNED_MIN;

static u32 TMR_u32Timer0Preload = UNSIGNED_MIN;
static u32 TMR_u32Timer1Preload = UNSIGNED_MIN;
static u32 TMR_u32Timer2Preload = UNSIGNED_MIN;

static u32 TMR_u32Timer0frstOcrVal = UNSIGNED_MIN;
static u32 TMR_u32Timer1AfrstOcrVal = UNSIGNED_MIN;
static u32 TMR_u32Timer1BfrstOcrVal = UNSIGNED_MIN;
static u32 TMR_u32Timer2frstOcrVal = UNSIGNED_MIN;

static u8 TMR_u8Timer0CTCFlag = 0;
static u8 TMR_u8Timer1CTCFlag = 0;
static u8 TMR_u8Timer2CTCFlag = 0;

/*Static array where each element is a pointer to function of each one of overflow interrupt for timer 0,1,2*/
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
			/* Checking Timer/Counter0 Overflow Interrupt Enable bit */
			if (TMR_u8_TIMER0_OVF_INT == TMR_u8_EN_INT)
			{
				SET_BIT(TMR_TIMSK,0);
			}
			else
			{
				CLEAR_BIT(TMR_TIMSK,0);
			}
		}
		else if (TMR_u8_TIMER0_MODE == TMR_u8_CTC)
		{
			SET_BIT(TMR_TCCR0,3);
			/* Checking Timer/Counter0 CTC Interrupt Enable bit */
			if (TMR_u8_TIMER0_CTC_INT == TMR_u8_EN_INT )
			{
				SET_BIT(TMR_TIMSK,1);
			}
			else
			{
				CLEAR_BIT(TMR_TIMSK,1);
			}
			switch (TMR_u8_TIMER0_COPT_MODE)
			{
				case TMR_u8_OCX_PIN_DISCOUNNECTED:
				{
				    CLEAR_BIT(TMR_TCCR0,4);
				    CLEAR_BIT(TMR_TCCR0,5);
					break;
				}
				case TMR_u8_TOGGLE_OCX:
				{
					SET_BIT(TMR_TCCR0,4);
					break;
				}
				case TMR_u8_CLEAR_OCX:
				{
					SET_BIT(TMR_TCCR0,5);
					break;
				}
				case TMR_u8_SET_OCX:
				{
					SET_BIT(TMR_TCCR0,4);
					SET_BIT(TMR_TCCR0,5);
					break;
				}
			}
		}
		/* Checking assigned Prescaler for Timer/Counter0 */
		switch (TMR_TIMER0_PRESCALER)
		{
			case TMR_NO_PRESCALER:
			{
				SET_BIT(TMR_TCCR0,0);
				break;
			}
			case TMR_FREQ_OVER_8:
			{
				SET_BIT(TMR_TCCR0,1);
				break;
			}
			case TMR_FREQ_OVER_64:
			{
				SET_BIT(TMR_TCCR0,0);
				SET_BIT(TMR_TCCR0,1);
				break;
			}
			case TMR_FREQ_OVER_256:
			{
				SET_BIT(TMR_TCCR0,2);
				break;
			}
			case TMR_FREQ_OVER_1024:
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
			/* Checking Timer/Counter1 Overflow Interrupt Enable bit */
			if (TMR_u8_TIMER1_OVF_INT == TMR_u8_EN_INT )
			{
				SET_BIT(TMR_TIMSK,2);
			}
			else
			{
				CLEAR_BIT(TMR_TIMSK,2);
			}
		}
		else if (TMR_u8_TIMER1_MODE == TMR_u8_CTC)
		{
			SET_BIT(TMR_TCCR1B,3);
			/* Checking Timer/Counter1A CTC Interrupt Enable bit */
			if (TMR_u8_TIMER1A_COMP_STATE == TMR_u8_ENABLE )
			{
				SET_BIT(TMR_TIMSK,4);
			}
			else
			{
				CLEAR_BIT(TMR_TIMSK,4);
			}
			/* Checking Timer/Counter1B CTC Interrupt Enable bit */
			if (TMR_u8_TIMER1A_COMP_STATE == TMR_u8_ENABLE )
			{
				SET_BIT(TMR_TIMSK,3);
			}
			else
			{
				CLEAR_BIT(TMR_TIMSK,3);
			}
			switch (TMR_u8_TIMER1_COPT_MODE)
			{
				case TMR_u8_OCX_PIN_DISCOUNNECTED:
				{
				    CLEAR_BIT(TMR_TCCR1A,4);
				    CLEAR_BIT(TMR_TCCR1A,5);
				    CLEAR_BIT(TMR_TCCR1A,6);
				    CLEAR_BIT(TMR_TCCR1A,7);
					break;
				}
				case TMR_u8_TOGGLE_OCX:
				{
					SET_BIT(TMR_TCCR1A,4);
					SET_BIT(TMR_TCCR1A,6);
					break;
				}
				case TMR_u8_CLEAR_OCX:
				{
					SET_BIT(TMR_TCCR1A,5);
					SET_BIT(TMR_TCCR1A,7);
					break;
				}
				case TMR_u8_SET_OCX:
				{
					SET_BIT(TMR_TCCR1A,4);
					SET_BIT(TMR_TCCR1A,5);
					SET_BIT(TMR_TCCR1A,6);
					SET_BIT(TMR_TCCR1A,7);
					break;
				}
			}
			/* Checking Timer/Counter1 CTC Interrupt Enable bit */
			if (TMR_u8_TIMER0_CTC_INT == TMR_u8_EN_INT )
			{
				SET_BIT(TMR_TIMSK,3);
				SET_BIT(TMR_TIMSK,4);
			}
			else
			{
				CLEAR_BIT(TMR_TIMSK,3);
				CLEAR_BIT(TMR_TIMSK,4);
			}
		}
		/* Checking assigned Prescaler for Timer/Counter1 */
		switch (TMR_TIMER1_PRESCALER)
		{
			case TMR_NO_PRESCALER:
			{
				SET_BIT(TMR_TCCR1B,0);
				break;
			}
			case TMR_FREQ_OVER_8:
			{
				SET_BIT(TMR_TCCR1B,1);
				break;
			}
			case TMR_FREQ_OVER_64:
			{
				SET_BIT(TMR_TCCR1B,0);
				SET_BIT(TMR_TCCR1B,1);
				break;
			}
			case TMR_FREQ_OVER_256:
			{
				SET_BIT(TMR_TCCR1B,2);
				break;
			}
			case TMR_FREQ_OVER_1024:
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
			/* Checking Timer/Counter0 Overflow Interrupt Enable bit */
			if (TMR_u8_TIMER2_OVF_INT == TMR_u8_EN_INT)
			{
				SET_BIT(TMR_TIMSK,6);
			}
			else
			{
				CLEAR_BIT(TMR_TIMSK,6);
			}
		}
		else if (TMR_u8_TIMER2_MODE == TMR_u8_CTC)
		{
			SET_BIT(TMR_TCCR2,3);
			/* Checking Timer/Counter2 CTC Interrupt Enable bit */
			if (TMR_u8_TIMER2_CTC_INT == TMR_u8_EN_INT )
			{
				SET_BIT(TMR_TIMSK,7);
			}
			else
			{
				CLEAR_BIT(TMR_TIMSK,7);
			}
			switch (TMR_u8_TIMER2_COPT_MODE)
			{
				case TMR_u8_OCX_PIN_DISCOUNNECTED:
				{
				    CLEAR_BIT(TMR_TCCR2,4);
				    CLEAR_BIT(TMR_TCCR2,5);
					break;
				}
				case TMR_u8_TOGGLE_OCX:
				{
					SET_BIT(TMR_TCCR2,4);
					break;
				}
				case TMR_u8_CLEAR_OCX:
				{
					SET_BIT(TMR_TCCR2,5);
					break;
				}
				case TMR_u8_SET_OCX:
				{
					SET_BIT(TMR_TCCR2,4);
					SET_BIT(TMR_TCCR2,5);
					break;
				}
			}
		}
		/* Checking assigned Prescaler for Timer/Counter2 */
		switch (TMR_TIMER2_PRESCALER)
		{
			case TMR_NO_PRESCALER:
			{
				SET_BIT(TMR_TCCR2,0);
				break;
			}
			case TMR_FREQ_OVER_8:
			{
				SET_BIT(TMR_TCCR2,1);
				break;
			}
			case TMR_FREQ_OVER_32:
			{
				SET_BIT(TMR_TCCR2,0);
				SET_BIT(TMR_TCCR2,1);
				break;
			}
			case TMR_FREQ_OVER_64:
			{
				SET_BIT(TMR_TCCR2,2);
				break;
			}
			case TMR_FREQ_OVER_128:
			{
				SET_BIT(TMR_TCCR2,0);
				SET_BIT(TMR_TCCR2,2);
				break;
			}
			case TMR_FREQ_OVER_256:
			{
				SET_BIT(TMR_TCCR2,1);
				SET_BIT(TMR_TCCR2,2);
				break;
			}
			case TMR_FREQ_OVER_1024:
			{
				SET_BIT(TMR_TCCR2,0);
				SET_BIT(TMR_TCCR2,1);
				SET_BIT(TMR_TCCR2,2);
				break;
			}
		}
		TMR_u8Timer2CtrlRegValue = TMR_TCCR2;
	}
	return;
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
 * Description: Function to set the delay time for the required timer
 * this function can be used for making delay (in case of Timer normal mode)
 * or for specifying a sampling time (in case of Timer CTC mode)
 * Inputs: the delay time in microsecond
 * Output: the Error state of the function
 */
u8 TMR_u8SetDesiredTime (u8 Copy_u8TimerNb,u32 Copy_u32TimeInUs)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error = ERROR_OK;
	f32 Local_f32TimerCtr;

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
			   Local_f32TimerCtr = ((f32)(Copy_u32TimeInUs)/TMR_u32_TIMER0_TOVF);
			   if (TMR_u8_TIMER0_MODE == TMR_u8_CTC)
			   {
				   TMR_vSetTIMER0CTCTime(Local_f32TimerCtr);
			   }
			   else if (TMR_u8_TIMER0_MODE == TMR_u8_NORMAL)
			   {
				   TMR_vSetTIMER0OVFTime (Local_f32TimerCtr);
			   }
			   break;
		   }
		   case TMR_u8_TIMER1:
		   {
			   Local_f32TimerCtr = ((f32)(Copy_u32TimeInUs)/TMR_u32_TIMER1_TOVF);
			   if (TMR_u8_TIMER1_MODE == TMR_u8_CTC)
			   {
				   TMR_vSetTIMER1CTCTime(Local_f32TimerCtr);
			   }
			   else if (TMR_u8_TIMER1_MODE == TMR_u8_NORMAL)
			   {
				   TMR_vSetTIMER1OVFTime (Local_f32TimerCtr);
			   }
			   break;
		   }
		   case TMR_u8_TIMER2:
		   {
			   Local_f32TimerCtr = ((f32)(Copy_u32TimeInUs)/TMR_u32_TIMER2_TOVF);
			   if (TMR_u8_TIMER2_MODE == TMR_u8_CTC)
			   {
				   TMR_vSetTIMER2CTCTime(Local_f32TimerCtr);
			   }
			   else if (TMR_u8_TIMER2_MODE == TMR_u8_NORMAL)
			   {
				   TMR_vSetTIMER2OVFTime (Local_f32TimerCtr);
			   }
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

/************************************************************/
/*      ISRs of Overflow timer interrupts                   */
/************************************************************/
/*The ISR of Timer/Counter0 Overflow interrupt*/
void __vector_11 (void)
{
	if (PVCallBack[TMR_u8_TIMER0] != NULL)
	{
		TMR_u32Timer0Counter++;
		if (TMR_u32Timer0Counter == TMR_u32ReqTimer0Cntr)
		{
			TMR_u32Timer0Counter = UNSIGNED_MIN;
			TMR_TCNT0 = TMR_u32Timer0Preload;
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
		if (TMR_u32Timer1Counter == TMR_u32ReqTimer1Cntr)
		{
			TMR_u32Timer1Counter = UNSIGNED_MIN;
			TMR_TCNT1H = TMR_u32Timer1Preload>>8;
			TMR_TCNT1L = TMR_u32Timer1Preload;
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
		if (TMR_u32Timer2Counter == TMR_u32ReqTimer2Cntr)
		{
			TMR_u32Timer2Counter = UNSIGNED_MIN;
			TMR_TCNT2 = TMR_u32Timer2Preload;
			PVCallBack[TMR_u8_TIMER2]();   /*The ISR action*/
		}
	}
    return;
}

/************************************************************/
/*      ISRs of Compare Match timer interrupts              */
/************************************************************/
/*The ISR of Timer/Counter0 Compare Match interrupt*/
void __vector_10 (void)
{
	if (PVCallBack[TMR_u8_TIMER0] != NULL)
	{
		TMR_u32Timer0Counter++;
		if (TMR_u32Timer0Counter == TMR_u32ReqTimer0Cntr)
		{
			TMR_u32Timer0Counter = UNSIGNED_MIN;
			TMR_OCR0 = TMR_u32Timer0frstOcrVal;
			PVCallBack[TMR_u8_TIMER0]();   /*The ISR action*/
		}
		if (TMR_u8Timer0CTCFlag == 0)
			TMR_OCR0 = 0xff;
	}
}

/*The ISR of Timer/Counter1 Compare Match A interrupt*/
void __vector_7 (void)
{
	if (PVCallBack[TMR_u8_TIMER1] != NULL)
	{
		TMR_u32Timer1Counter++;
		if (TMR_u32Timer1Counter == TMR_u32ReqTimer1Cntr)
		{
			TMR_u32Timer1Counter = UNSIGNED_MIN;
			OCR1AL = TMR_u32Timer1AfrstOcrVal;
			OCR1AH = (u32)TMR_u32Timer1AfrstOcrVal>>8;
			PVCallBack[TMR_u8_TIMER1]();   /*The ISR action*/
		}
		if (TMR_u8Timer1CTCFlag == 0)
		{
			OCR1AL = 0xff;
			OCR1AH = 0xff;
		}
	}
}

/*The ISR of Timer/Counter1 Compare Match B interrupt*/
void __vector_8 (void)
{
	if (PVCallBack[TMR_u8_TIMER1] != NULL)
	{
		TMR_u32Timer1Counter++;
		if (TMR_u32Timer1Counter == TMR_u32ReqTimer1Cntr)
		{
			TMR_u32Timer1Counter = UNSIGNED_MIN;
			OCR1BL = TMR_u32Timer1BfrstOcrVal;
			OCR1BH = (u32)TMR_u32Timer1BfrstOcrVal>>8;
			PVCallBack[TMR_u8_TIMER1]();   /*The ISR action*/
		}
		if (TMR_u8Timer1CTCFlag == 0)
		{
			OCR1BL = 0xff;
			OCR1BH = 0xff;
		}
	}
}

/*The ISR of Timer/Counter2 Compare Match interrupt*/
void __vector_4 (void)
{
	if (PVCallBack[TMR_u8_TIMER2] != NULL)
	{
		TMR_u32Timer2Counter++;
		if (TMR_u32Timer2Counter == TMR_u32ReqTimer2Cntr)
		{
			TMR_u32Timer2Counter = UNSIGNED_MIN;
			TMR_OCR2 = TMR_u32Timer2frstOcrVal;
			PVCallBack[TMR_u8_TIMER2]();   /*The ISR action*/
		}
		if (TMR_u8Timer2CTCFlag == 0)
			TMR_OCR2 = 0xff;
	}
}

/*************************************************************************************/
/*Static Functions to set the desired time needed in case of normal mode or CTC mode */
/*************************************************************************************/
static void TMR_vSetTIMER0OVFTime (f32 Copy_f32TimerCtr)
{
	f32 Local_f32FractionCount;
	u32 Local_u32preload;
	if (Copy_f32TimerCtr == 1)
	{
	   TMR_u32ReqTimer0Cntr = 1;
	   TMR_u32Timer0Preload = 0;
	   TMR_TCNT0 = 0;
	}
	else if (Copy_f32TimerCtr > 1)
	{
	   if (Copy_f32TimerCtr - (u32)Copy_f32TimerCtr == 0) /*if integar*/
	   {
		   TMR_u32ReqTimer0Cntr = (u32)Copy_f32TimerCtr;
		   TMR_u32Timer0Preload = 0;
		   TMR_TCNT0 = 0;
	   }
	   else /*if float*/
	   {
		   Local_f32FractionCount = 256*(Copy_f32TimerCtr-(u32)Copy_f32TimerCtr);
		   Local_u32preload = 256 - Local_f32FractionCount;
		   TMR_u32ReqTimer0Cntr = ((u32)Copy_f32TimerCtr)+1;
		   TMR_u32Timer0Preload = Local_u32preload;
		   TMR_TCNT0 = Local_u32preload;
	   }
	}
	else if (Copy_f32TimerCtr < 1)
	{
	   Local_f32FractionCount = 256*Copy_f32TimerCtr;
	   Local_u32preload = 256 - Local_f32FractionCount;
	   TMR_u32ReqTimer0Cntr = 1;
	   TMR_u32Timer0Preload = Local_u32preload;
	   TMR_TCNT0 = Local_u32preload;
	}
	return;
}
static void TMR_vSetTIMER1OVFTime (f32 Copy_f32TimerCtr)
{
	f32 Local_f32FractionCount;
	u32 Local_u32preload;
	if (Copy_f32TimerCtr == 1)
	{
	   TMR_u32ReqTimer1Cntr = 1;
	   TMR_u32Timer1Preload = 0;
	   TMR_TCNT1H = 0;
	   TMR_TCNT1L = 0;
	}
	else if (Copy_f32TimerCtr > 1)
	{
	   if (Copy_f32TimerCtr - (u32)Copy_f32TimerCtr == 0) /*if integar*/
	   {
		   TMR_u32ReqTimer1Cntr = (u32)Copy_f32TimerCtr;
		   TMR_u32Timer1Preload = 0;
		   TMR_TCNT1H = 0;
		   TMR_TCNT1L = 0;
	   }
	   else /*if float*/
	   {
		   Local_f32FractionCount = 65536*(Copy_f32TimerCtr-(u32)Copy_f32TimerCtr);
		   Local_u32preload = 65536 - Local_f32FractionCount;
		   TMR_u32ReqTimer1Cntr = ((u32)Copy_f32TimerCtr)+1;
		   TMR_u32Timer1Preload = Local_u32preload;
		   TMR_TCNT1H = Local_u32preload>>8;
		   TMR_TCNT1L = Local_u32preload;
	   }
	}
	else if (Copy_f32TimerCtr < 1)
	{
	   Local_f32FractionCount = 65536*Copy_f32TimerCtr;
	   Local_u32preload = 65536 - Local_f32FractionCount;
	   TMR_u32ReqTimer1Cntr = 1;
	   TMR_u32Timer1Preload = Local_u32preload;
	   TMR_TCNT1H = Local_u32preload>>8;
	   TMR_TCNT1L = Local_u32preload;
	}
	return;
}

static void TMR_vSetTIMER2OVFTime (f32 Copy_f32TimerCtr)
{
	f32 Local_f32FractionCount;
	u32 Local_u8preload;
	if (Copy_f32TimerCtr == 1)
	{
	   TMR_u32ReqTimer2Cntr = 1;
	   TMR_u32Timer2Preload = 0;
	   TMR_TCNT2 = 0;
	}
	else if (Copy_f32TimerCtr > 1)
	{
	   if ((Copy_f32TimerCtr - (u32)Copy_f32TimerCtr == 0)) /*if integar*/
	   {
		   TMR_u32ReqTimer2Cntr = (u32)Copy_f32TimerCtr;
		   TMR_u32Timer2Preload = 0;
		   TMR_TCNT2 = 0;
	   }
	   else /*if float*/
	   {
		   Local_f32FractionCount = 256*(Copy_f32TimerCtr-(u32)Copy_f32TimerCtr);
		   Local_u8preload = 256 - Local_f32FractionCount;
		   TMR_u32ReqTimer2Cntr = ((u32)Copy_f32TimerCtr)+1;
		   TMR_u32Timer2Preload = Local_u8preload;
		   TMR_TCNT2 = Local_u8preload;
	   }
	}
	else if (Copy_f32TimerCtr < 1)
	{
	   Local_f32FractionCount = 256*Copy_f32TimerCtr;
	   Local_u8preload = 256 - Local_f32FractionCount;
	   TMR_u32ReqTimer2Cntr = 1;
	   TMR_u32Timer2Preload = Local_u8preload;
	   TMR_TCNT2 = Local_u8preload;
	}
	return;
}

static void TMR_vSetTIMER0CTCTime (f32 Copy_f32TimerCtr)
{
    f32 Local_f32FractionCount;
 	if (Copy_f32TimerCtr == 1)
 	{
 		TMR_u32ReqTimer0Cntr = 1;
 		TMR_OCR0 = 0xff;
 	}
 	else if (Copy_f32TimerCtr > 1)
 	{
 		if (Copy_f32TimerCtr - (u32)Copy_f32TimerCtr == 0) /*if integar*/
		{
			 TMR_u32ReqTimer0Cntr = (u32)Copy_f32TimerCtr;
			 TMR_OCR0 = 0xff;
		}
 		else  /*if float*/
		{
 		     Local_f32FractionCount = 256*(Copy_f32TimerCtr-(u32)Copy_f32TimerCtr);
			 TMR_u32ReqTimer0Cntr = (u32)Copy_f32TimerCtr+1;
			 TMR_OCR0 = Local_f32FractionCount;
			 TMR_u32Timer0frstOcrVal = (u32)Local_f32FractionCount;
 		}
 	 }
     else if (Copy_f32TimerCtr < 1)
     {
 	    Local_f32FractionCount = 256*Copy_f32TimerCtr;
 	    TMR_u32ReqTimer0Cntr = 1;
 	    TMR_OCR0 = Local_f32FractionCount;
 	    TMR_u8Timer0CTCFlag = 1;
     }
     return;
}

static void TMR_vSetTIMER1CTCTime (f32 Copy_f32TimerCtr)
{
    f32 Local_f32FractionCount;
 	if (Copy_f32TimerCtr == 1)
 	{
 		TMR_u32ReqTimer1Cntr = 1;
 		if (TMR_u8_TIMER1A_COMP_STATE == TMR_u8_ENABLE)
 		{
 			OCR1AL = 0xff;
 			OCR1AH = 0xff;
 		}
 		if (TMR_u8_TIMER1B_COMP_STATE == TMR_u8_ENABLE)
 		{
 			OCR1BL = 0xff;
 			OCR1BH = 0xff;
 		}
 	}
 	else if (Copy_f32TimerCtr > 1)
 	{
 		if (Copy_f32TimerCtr - (u32)Copy_f32TimerCtr == 0) /*if integar*/
		{
			 TMR_u32ReqTimer1Cntr = (u32)Copy_f32TimerCtr;
			 if (TMR_u8_TIMER1A_COMP_STATE == TMR_u8_ENABLE)
			 {
				OCR1AL = 0xff;
				OCR1AH = 0xff;
			 }
			 if (TMR_u8_TIMER1B_COMP_STATE == TMR_u8_ENABLE)
			 {
				OCR1BL = 0xff;
				OCR1BH = 0xff;
			 }
		}
 		else  /*if float*/
 		{
 		     Local_f32FractionCount = 65536*(Copy_f32TimerCtr-(u32)Copy_f32TimerCtr);
			 TMR_u32ReqTimer1Cntr = (u32)Copy_f32TimerCtr+1;

			 if (TMR_u8_TIMER1A_COMP_STATE == TMR_u8_ENABLE)
			 {
				 TMR_u32Timer1AfrstOcrVal = Local_f32FractionCount;
				 OCR1AL = Local_f32FractionCount;
				 OCR1AH = (u32)Local_f32FractionCount>>8;
				 TMR_u32Timer1AfrstOcrVal = (u32)Local_f32FractionCount;
			 }
			 if (TMR_u8_TIMER1B_COMP_STATE == TMR_u8_ENABLE)
			 {
				 TMR_u32Timer1BfrstOcrVal = Local_f32FractionCount;
				 OCR1BL = Local_f32FractionCount;
				 OCR1BH = (u32)Local_f32FractionCount>>8;
				 TMR_u32Timer1BfrstOcrVal = (u32)Local_f32FractionCount;
			 }
 		}
 	 }
     else if (Copy_f32TimerCtr < 1)
     {
 	    Local_f32FractionCount = 256*Copy_f32TimerCtr;
 	    TMR_u32ReqTimer1Cntr = 1;
		 if (TMR_u8_TIMER1A_COMP_STATE == TMR_u8_ENABLE)
		 {
			 OCR1AH = (u32)Local_f32FractionCount>>8;
			 OCR1AL = Local_f32FractionCount;
		 }
		 if (TMR_u8_TIMER1B_COMP_STATE == TMR_u8_ENABLE)
		 {
			 OCR1BH = (u32)Local_f32FractionCount>>8;
			 OCR1BL = Local_f32FractionCount;
		 }
		 TMR_u8Timer1CTCFlag = 1;
     }
     return;
}

static void TMR_vSetTIMER2CTCTime (f32 Copy_f32TimerCtr)
{
    f32 Local_f32FractionCount;
 	if (Copy_f32TimerCtr == 1)
 	{
 		TMR_u32ReqTimer2Cntr = 1;
 		TMR_OCR2 = 0xff;
 	}
 	else if (Copy_f32TimerCtr > 1)
 	{
 		if (Copy_f32TimerCtr - (u32)Copy_f32TimerCtr == 0) /*if integar*/
		{
			 TMR_u32ReqTimer2Cntr = (u32)Copy_f32TimerCtr;
			 TMR_OCR2 = 0xff;
		}
 		else  /*if float*/
		{
		     Local_f32FractionCount = 256*(Copy_f32TimerCtr-(u32)Copy_f32TimerCtr);
			 TMR_u32ReqTimer2Cntr = (u32)Copy_f32TimerCtr+1;
			 TMR_OCR2 = Local_f32FractionCount;
			 TMR_u32Timer2frstOcrVal = (u32)Local_f32FractionCount;
 		}
 	 }
     else if (Copy_f32TimerCtr < 1)
     {
 	    Local_f32FractionCount = 256*Copy_f32TimerCtr;
 	    TMR_u32ReqTimer2Cntr = 1;
 	    TMR_OCR2 = Local_f32FractionCount;
		 TMR_u8Timer2CTCFlag = 1;
     }
     return;
}
