/*****************************************************************/
/* Author: Mahmoud Alaa Elwelily                                 */
/* Date: 28-Mar-19                                               */
/* Version: 01                                                   */
/* Description: Private file for Timer Driver for AVR ATmega32   */
/*****************************************************************/

/*Preprocessor Guard*/
#ifndef TMR_PRIV_H 
#define TMR_PRIV_H 

/*Private macro for the number of the availabe timers in AVR Atmega32*/
#define TMR_u8_NO_OF_TIMERS   	 	 (u8)3

/*Private macros for the initial state of the timers*/
#define TMR_u8_DISABLE        		 (u8)0
#define TMR_u8_ENABLE          		 (u8)1

/*Private macros for the available mode for the timer peripheral in AVR ATmega32*/
#define  TMR_u8_NORMAL               (u8)0
#define  TMR_u8_PWM_PHASE_CORRECT    (u8)1
#define  TMR_u8_CTC                  (u8)2
#define  TMR_u8_FASTPWM              (u8)3

/*Private macros for the available prescalers can be assigned for the timer peripheral*/
#define TMR_NO_PRESCALER    		0U
#define TMR_FREQ_OVER_8    		    1U
#define TMR_FREQ_OVER_32            2U
#define TMR_FREQ_OVER_64            3U
#define TMR_FREQ_OVER_128           4U
#define TMR_FREQ_OVER_256           5U
#define TMR_FREQ_OVER_1024          6U

/*Macros for enabling or disabling the timer interrupt*/
#define TMR_u8_DIS_INT    		 (u8)0
#define TMR_u8_EN_INT      		 (u8)1

/*Macros for available output mode on compare match timer */
#define TMR_u8_OCX_PIN_DISCOUNNECTED    (u8)0
#define TMR_u8_TOGGLE_OCX				(u8)1
#define TMR_u8_CLEAR_OCX				(u8)2
#define TMR_u8_SET_OCX			    	(u8)3
/*==========================================================*/
/*                  Timer Registers                         */
/*==========================================================*/
#define TMR_TCCR0  ((Register*) 0x53) -> ByteAccess
#define TMR_TCNT0  ((Register*) 0x52) -> ByteAccess
#define TMR_OCR0   ((Register*) 0x5C) -> ByteAccess

#define TMR_TCCR2  ((Register*) 0x45) -> ByteAccess
#define TMR_TCNT2  ((Register*) 0x44) -> ByteAccess
#define TMR_OCR2   ((Register*) 0x43) -> ByteAccess

#define TMR_TCCR1A ((Register*) 0x4F) -> ByteAccess
#define TMR_TCCR1B ((Register*) 0x4E) -> ByteAccess
#define TMR_TCNT1H ((Register*) 0x4D) -> ByteAccess
#define TMR_TCNT1L ((Register*) 0x4C) -> ByteAccess
#define OCR1AL     ((Register*) 0x4A) -> ByteAccess
#define OCR1AH     ((Register*) 0x4B) -> ByteAccess
#define OCR1BL     ((Register*) 0x48) -> ByteAccess
#define OCR1BH     ((Register*) 0x49) -> ByteAccess

#define TMR_TIMSK ((Register*) 0x59) -> ByteAccess

/************************************************************/
/*      ISRs of Overflow timer interrupts                   */
/************************************************************/
/*The ISR of Timer/Counter0 Overflow interrupt*/
void __vector_11 (void) __attribute__((signal));

/*The ISR of Timer/Counter1 Overflow interrupt*/
void __vector_9 (void) __attribute__((signal));

/*The ISR of Timer/Counter2 Overflow interrupt*/
void __vector_5 (void) __attribute__((signal));

/************************************************************/
/*      ISRs of Compare Match timer interrupts              */
/************************************************************/
/*The ISR of Timer/Counter0 Compare Match interrupt*/
void __vector_10 (void) __attribute__((signal));

/*The ISR of Timer/Counter1 Compare Match A interrupt*/
void __vector_7 (void) __attribute__((signal));

/*The ISR of Timer/Counter1 Compare Match B interrupt*/
void __vector_8 (void) __attribute__((signal));

/*The ISR of Timer/Counter2 Compare Match interrupt*/
void __vector_4 (void) __attribute__((signal));


/*************************************************************************************/
/*Static Functions to set the desired time needed in case of normal mode or CTC mode */
/*************************************************************************************/
static void TMR_vSetTIMER0OVFTime (f32 Copy_f32TimerCtr);
static void TMR_vSetTIMER1OVFTime (f32 Copy_f32TimerCtr);
static void TMR_vSetTIMER2OVFTime (f32 Copy_f32TimerCtr);

static void TMR_vSetTIMER0CTCTime (f32 Copy_f32TimerCtr);
static void TMR_vSetTIMER1CTCTime (f32 Copy_f32TimerCtr);
static void TMR_vSetTIMER2CTCTime (f32 Copy_f32TimerCtr);



#endif /* TMR_PRIV_H */ 
