 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: PWM.c
 *
 * Description:Source file for the PWM driver
 *
 * Author: Hussam Eldin Wael
 *
 *******************************************************************************/

#include "avr/io.h"
#include "Macros.h"
#include "PWM.h"
#include "gpio.h"

/*
 * Description :
 * Initializes Timer 0 with PWM Mode and sets the duty cycle of the output waveform.
 */
void  PWM_Timer0_init(uint8 dutyCycle) {

	/*Configure Fast PWM Mode*/

	SET_BIT(TCCR0 , WGM00);

	SET_BIT(TCCR0 , WGM01);


	/*Use non-inverting mode*/
	SET_BIT(TCCR0 , COM01) ;

	/*Use a pre-scaler of 8*/
	TCCR0 = (TCCR0 & 0xF8) | (PRESCALER) ;

	/*Initialize timer register*/
	TCNT0  = 0 ;
	/*Set the compare value*/
	OCR0 = dutyCycle * 0.01 * 255 ;

	/*Configure OC0 as output*/

	GPIO_setupPinDirection(PORTB_ID , PIN3_ID , PIN_OUTPUT);


}

