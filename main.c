/* ============================================================================
 Name        : main.c
 Author      : Hussam Eldin Wael
 Description : Testing file
 Date        : 11/10/2021
 ===============================================================================
 */


#include "LCD.h"
#include "lm35.h"
#include "DcMotor.h"

/*******************************************************************************
 *                              Helpful Functions                              *
 *******************************************************************************/

/*
 * Description :
 * returns the number of digits of the temperature sensor reading,
 * which is between 0 and 150C.
 */
uint8 len(uint16 num) {
	if(num >=100)
		return 3 ;
	else if(num >=10)
		return 2 ;
	else
		return 1;

}

/*******************************************************************************
 *                              Main Program                                   *
 *******************************************************************************/

int main(void) {

	/*Initialize the LCD.*/
	LCD_init();

	/*Initialize the DC Motor.*/
	DcMotor_init();

	/*Configure the ADC to work with Internal 2.56V as reference voltage,
	 * and a pre-scaler = FCPU/8 */
	ADC_ConfigType lm35_config = {INTERNAL_V , F_CPU_8};

	ADC_init(&lm35_config);


	/*Initialize some needed variables.*/
	uint8 temperature = 0 , speed = 0 , state = STOP ;
	uint8 pin_flag = 0 ;
	while(1) {

		/*Read the value from the temperature sensor.*/
		temperature = LM35_getTemperature();

		/*If the value is out of bounds, display SENSOR ERROR and turn off the fan*/
		if(temperature == FLOATING_PIN) {
			if(pin_flag == 0) {
				LCD_clearScreen();
				LCD_displayString("  SENSOR ERROR  ");
				DcMotor_rotate(STOP , 0);

			}
			pin_flag = 1;



		}
		else{
			if(pin_flag == 1) {
				LCD_clearScreen();
			}

			/*Display the following Strings at the specified positions.*/
			LCD_displayStringRowColumn(0,3, "FAN IS ");

			LCD_moveCursor(1,2);
			LCD_displayString("Temp = ");

			/*Display the temperature value.*/
			pin_flag = 0;
			LCD_moveCursor(1,9);
			LCD_displayNumber(temperature);

			for(uint8 i = 0 ; i < (3-len(temperature)) ; i++) {
				LCD_displayCharacter(' ');
			}

			LCD_displayString("C");

			/*Adjust the state of the motor according to the temperature.*/
			if(temperature < 30) {
				speed = 0 ;
				state = STOP;
			}

			else if(temperature < 60) {

				speed = 25 ;
				state = CLOCKWISE ;
			}

			else if(temperature < 90) {

				speed = 50 ;
				state = CLOCKWISE ;
			}

			else if(temperature < 120) {

				speed = 75 ;
				state = CLOCKWISE ;
			}
			else{
				speed = 100 ;
				state = CLOCKWISE ;
			}

			DcMotor_rotate(state , speed);

			/*Display the Motor's state.*/
			LCD_displayStringRowColumn(0 ,10 ,(state == STOP)? "OFF" : "ON " );

		}
	}



}
