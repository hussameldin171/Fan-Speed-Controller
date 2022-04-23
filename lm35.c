 /******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: lm35.h
 *
 * Description: header file for the LM35 Temperature Sensor driver
 *
 * Author: Hussam Eldin Wael
 *
 *******************************************************************************/

#include "lm35.h"

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void){

	uint16 adc_reading = 0;

	/*Read ADC channel*/
	adc_reading = ADC_readChannel(SENSOR_CHANNEL_ID);

	/*If the reading is invalid, return a sensor error value*/
	if(adc_reading == ADC_MAXIMUM_VALUE) {
		return FLOATING_PIN ;
	}

	/*return the temperature after calculation*/
	return (uint8)(((uint32)adc_reading*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));



}
