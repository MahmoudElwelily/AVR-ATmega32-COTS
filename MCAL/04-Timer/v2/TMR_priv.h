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
#define TMR_u8_NO_OF_TIMERS    (u8)3

/*Private macros for the initial state of the timers*/
#define TMR_u8_DISABLE         (u8)0
#define TMR_u8_ENABLE          (u8)1

/*Private macros for the available mode for the timer peripheral in AVR ATmega32*/
#define  TMR_u8_NORMAL         (u8)0
#define  TMR_u8_PWM            (u8)1
#define  TMR_u8_CTC            (u8)2
#define  TMR_u8_FASTPWM        (u8)3

/*Private macros for the available prescalers can be assigned for the timer peripheral*/
#define TMR_u8_NO_PRESCALER    (u8)0
#define TMR_u8_FREQ_OVER_8     (u8)1
#define TMR_u8_FREQ_OVER_32    (u8)2
#define TMR_u8_FREQ_OVER_64    (u8)3
#define TMR_u8_FREQ_OVER_128   (u8)4
#define TMR_u8_FREQ_OVER_256   (u8)5
#define TMR_u8_FREQ_OVER_1024  (u8)6

/*Macros for enabling or disabling the overflow interrupt*/
#define TMR_u8_DIS_OVF_INT     (u8)0
#define TMR_u8_EN_OVF_INT      (u8)1

/*==========================================================*/
/*                  Timer Registers                         */
#define TMR_TCCR0 ((Register*) 0x53) -> ByteAccess
#define TMR_TCNT0 ((Register*) 0x52) -> ByteAccess

#define TMR_TCCR2 ((Register*) 0x45) -> ByteAccess
#define TMR_TCNT2 ((Register*) 0x44) -> ByteAccess

#define TMR_TCCR1A ((Register*) 0x4F) -> ByteAccess
#define TMR_TCCR1B ((Register*) 0x4E) -> ByteAccess
#define TMR_TCNT1H ((Register*) 0x4D) -> ByteAccess
#define TMR_TCNT1L ((Register*) 0x4C) -> ByteAccess

#define TMR_TIMSK ((Register*) 0x59) -> ByteAccess


/*The ISR of Timer/Counter0 Overflow interrupt*/
void __vector_11 (void) __attribute__((signal));

/*The ISR of Timer/Counter1 Overflow interrupt*/
void __vector_9 (void) __attribute__((signal));

/*The ISR of Timer/Counter2 Overflow interrupt*/
void __vector_5 (void) __attribute__((signal));

/*
 * Description: Function to return the overflow time for Timer0
 * Its calculation is based on this equation: Tov = 2^8*(1/Ftimer)
 * Inputs: void
 * Output: the overflow time in microsecond
 */
u32 GetTimer0_OverFlowTime (void);
/*
 * Description: Function to return the overflow time for Timer1
 * Its calculation is based on this equation: Tov = 2^8*(1/Ftimer)
 * Inputs: void
 * Output: the overflow time in microsecond
 */
u32 GetTimer1_OverFlowTime (void);
/*
 * Description: Function to return the overflow time for Timer2
 * Its calculation is based on this equation: Tov = 2^8*(1/Ftimer)
 * Inputs: void
 * Output: the overflow time in microsecond
 */
u32 GetTimer2_OverFlowTime (void);

#endif /* TMR_PRIV_H */ 
