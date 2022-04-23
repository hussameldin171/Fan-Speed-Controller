/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: Header file for the ADC driver
 *
 * Author: Hussam Eldin Wael
 *
 *******************************************************************************/
#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"
#include "gpio.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define ADC0  0
#define ADC1  1
#define ADC2  2
#define ADC3  3
#define ADC4  4
#define ADC5  5
#define ADC6  6
#define ADC7  7

#define ADC_REF_VOLT_VALUE   	2.56
#define ADC_MAXIMUM_VALUE		1023


/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum{
	AREF , AVCC , INTERNAL_V = 3

}ADC_refVolt;


typedef enum{
	F_CPU_2 = 1, F_CPU_4, F_CPU_8 , F_CPU_16 , F_CPU_32 , F_CPU_64 ,F_CPU_128

}ADC_prescaler;


typedef struct{

	ADC_refVolt Vref ;
	ADC_prescaler prescaler;

}ADC_ConfigType;



/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * Initializes the ADC according to the desired Reference Voltage and Prescaler.
 */
void ADC_init(ADC_ConfigType *ptr);

/*
 * Description :
 * returns the output of the ADC after reading from the desired channel.
 */
uint16 ADC_readChannel( uint8 channel);


#endif /* ADC_H_ */
