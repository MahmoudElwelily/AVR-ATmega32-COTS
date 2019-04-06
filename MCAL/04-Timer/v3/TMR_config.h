/**********************************************************************/
/* Author: Mahmoud Alaa Elwelily                                      */
/* Date: 28-Mar-19                                                    */
/* Version: 01                                                        */
/* Description: Configuration file for Timer Driver for AVR ATmega32  */
/**********************************************************************/

/*Preprocessor Guard*/
#ifndef TMR_CONFIG_H 
#define TMR_CONFIG_H 

/*
Macros for the initial state of each timer (0,1,2)
Range:   TMR_u8_DISABLE
	   	  TMR_u8_ENABLE
*/
#define  TMR_u8_TIMER0_INIT_STATE     TMR_u8_ENABLE
#define  TMR_u8_TIMER1_INIT_STATE     TMR_u8_DISABLE
#define  TMR_u8_TIMER2_INIT_STATE     TMR_u8_DISABLE

/*
Macros for the mode of each timer (0,1,2)
Range:   TMR_u8_NORMAL
	   	 TMR_u8_PWM
	   	 TMR_u8_CTC
		 TMR_u8_FASTPWM
*/
#define  TMR_u8_TIMER0_MODE   TMR_u8_CTC
#define  TMR_u8_TIMER1_MODE   TMR_u8_NORMAL
#define  TMR_u8_TIMER2_MODE   TMR_u8_NORMAL

/*
Macros for the prescaler of each timer (0,1,2)
Range:   TMR_u8_NO_PRESCALER
	   	 TMR_u8_FREQ_OVER_8
	   	 TMR_u8_FREQ_OVER_32
	   	 TMR_u8_FREQ_OVER_64
	   	 TMR_u8_FREQ_OVER_128
		 TMR_u8_FREQ_OVER_256
		 TMR_u8_FREQ_OVER_1024
*/
#define  TMR_u8_TIMER0_PRESCALER    TMR_u8_FREQ_OVER_8
#define  TMR_u8_TIMER1_PRESCALER    TMR_u8_NO_PRESCALER
#define  TMR_u8_TIMER2_PRESCALER    TMR_u8_NO_PRESCALER

/*
Macros to enable or disable the overflow interrupt for each timer (0,1,2)
Range:   TMR_u8_EN_OVF_INT
	   	 TMR_u8_DIS_OVF_INT
*/
#define TMR_u8_TIMER0_OVF_INT        TMR_u8_EN_INT
#define TMR_u8_TIMER1_OVF_INT        TMR_u8_DIS_INT
#define TMR_u8_TIMER2_OVF_INT        TMR_u8_DIS_INT

/*
Macros to enable or disable the overflow interrupt for each timer (0,1,2)
Range:   TMR_u8_EN_OVF_INT
	   	 TMR_u8_DIS_OVF_INT
*/
#define TMR_u8_TIMER0_CTC_INT        TMR_u8_EN_INT
#define TMR_u8_TIMER1_CTC_INT        TMR_u8_DIS_INT
#define TMR_u8_TIMER2_CTC_INT        TMR_u8_DIS_INT

/*
Macros to set the Compare Output Mode for each timer (0,1,2)
Range:   TMR_u8_OCX_PIN_DISCOUNNECTED
	   	 TMR_u8_TOGGLE_OCX
	   	 TMR_u8_CLEAR_OCX
	   	 TMR_u8_SET_OCX
*/
#define TMR_u8_TIMER0_COPT_MODE    TMR_u8_OCX_PIN_DISCOUNNECTED
#define TMR_u8_TIMER1_COPT_MODE    TMR_u8_OCX_PIN_DISCOUNNECTED
#define TMR_u8_TIMER2_COPT_MODE    TMR_u8_OCX_PIN_DISCOUNNECTED

#endif /* TMR_CONFIG_H */ 

