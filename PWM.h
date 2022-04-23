 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: PWM.h
 *
 * Description: Header file for the PWM driver
 *
 * Author: Hussam Eldin Wael
 *
 *******************************************************************************/

#ifndef PWM_H_
#define PWM_H_

#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define NO_CLOCK     0
#define F_CPU_1      1
#define F_CPU_8      2
#define F_CPU_64     3
#define F_CPU_256    4
#define F_CPU_1024   5

#define PRESCALER    F_CPU_8


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * Initializes Timer 0 with PWM Mode and sets the duty cycle of the output waveform.
 */
void PWM_Timer0_init(uint8 );


#endif /* PWM_H_ */
