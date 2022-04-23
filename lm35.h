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

#ifndef LM35_H_
#define LM35_H_

#include "std_types.h"
#include "adc.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define SENSOR_CHANNEL_ID         ADC2
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150
#define FLOATING_PIN 			  0xFF
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void);

#endif /* LM35_H_ */
