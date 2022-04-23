/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the DC Motor driver
 *
 * Author: Hussam Eldin Wael
 *
 *******************************************************************************/
#include "adc.h"
#include "avr/io.h"
#include "Macros.h"


/*
 * Description :
 * Initializes the ADC according to the desired Reference Voltage and Prescaler.
 */
void ADC_init(ADC_ConfigType *ptr){

	/*Set the reference voltage to the desired value*/
	ADMUX = (ADMUX & 0x3F) |  ( (ptr->Vref)<<6) ;

	/*Set the pre-scaler to the desired value*/
	ADCSRA = (ADCSRA & 0xF8) | (ptr->prescaler);

	/*Enable the ADC Module*/
	SET_BIT(ADCSRA , ADEN);


}

/*
 * Description :
 * returns the output of the ADC after reading from the desired channel.
 */
uint16 ADC_readChannel( uint8 channel){

	/*Select the desired channel*/
	ADMUX  =(ADMUX & 0xE0)|(channel);

	/*Start Conversion*/
	SET_BIT(ADCSRA , ADSC);

	/*Wait until conversion is complete*/
	while(BIT_IS_CLEAR(ADCSRA , ADIF));

	/*Clear the flag*/
	SET_BIT(ADCSRA , ADIF);

	/*return the reading*/
	return ADC;
}
