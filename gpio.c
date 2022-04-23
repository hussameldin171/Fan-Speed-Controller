/******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: gpio.c
 *
 * Description: Source file for the AVR GPIO driver
 *
 * Author: Hussam Eldin Wael
 *
 *******************************************************************************/

#include "gpio.h"
#include "avr/io.h" /* To use the IO Ports Registers */
#include "Macros.h" /* To use the macros like SET_BIT */

/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction)
{
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		/* Setup the pin direction as required */
		switch(port_num)
		{
		case PORTA_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRA,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRA,pin_num);
			}
			break;
		case PORTB_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRB,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRB,pin_num);
			}
			break;
		case PORTC_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRC,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRC,pin_num);
			}
			break;
		case PORTD_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRD,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRD,pin_num);
			}
			break;
		}
	}
}

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value)
{
	if(port_num >= NUM_OF_PORTS || pin_num >= NUM_OF_PINS_PER_PORT) {

		/* Do Nothing */

	}

	else{

		/*Create an array of pointers to access the specified register*/
		uint8 *ports[4] = {&PORTA , &PORTB , &PORTC , &PORTD};

		/*Write the logical value to the specified pin in the specified port*/
		WRITE_BIT(*ports[port_num] , pin_num , value);

	}
}

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num)
{

	if(port_num >= NUM_OF_PORTS || pin_num >= NUM_OF_PINS_PER_PORT) {

		return LOGIC_LOW ;

	}

	else{
		/*Create an array of pointers to access the specified register*/
		uint8 *pins[4] = {&PINA , &PINB , &PINC , &PIND};

		/*return the bit read from the specified pin in the specified register*/
		return GET_BIT(*pins[port_num] , pin_num );

	}

}

/*
 * Description :
 * Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_setupPortDirection(uint8 port_num, GPIO_PortDirectionType direction)
{
	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		/* Setup the port direction as required */
		switch(port_num)
		{
		case PORTA_ID:
			DDRA = direction;
			break;
		case PORTB_ID:
			DDRB = direction;
			break;
		case PORTC_ID:
			DDRC = direction;
			break;
		case PORTD_ID:
			DDRD = direction;
			break;
		}
	}
}

/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_writePort(uint8 port_num, uint8 value)
{
	if(port_num >= NUM_OF_PORTS){


		/*Do Nothing*/

	}

	else{


		/*Create an array of pointers to access the specified register*/
		uint8 *ports[4] = {&PORTA , &PORTB , &PORTC , &PORTD};

		/*Write the logical value to the specified port*/
		*ports[port_num] =  value;


	}

}

/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */
uint8 GPIO_readPort(uint8 port_num)
{

	if(port_num >= NUM_OF_PORTS){

		return 0 ;

	}

	else{


		/*Create an array of pointers to access the specified register*/
		uint8 *pins[4] = {&PINA , &PINB , &PINC , &PIND};

		/*Return the logical value to the specified pin*/
		return *pins[port_num];


	}


}

#ifdef INTERNAL_PULL_UP_SUPPORTED
/*
 * Description :
 * Enables the internal pull up resistor for a specified pin in a specified port.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void GPIO_enableInternalPullUp(uint8 port_num , uint8 pin_num){

	if(port_num >= NUM_OF_PORTS || pin_num >= NUM_OF_PINS_PER_PORT) {

		/* Do Nothing */

	}

	else{
		/* Enable Internal Pull Up*/
		GPIO_writePin(port_num , pin_num , INTERNAL_PULL_UP_VALUE);
	}


}

#endif


#ifdef INTERNAL_PULL_DOWN_SUPPORTED
/*
 * Description :
 * Enables the internal pull down resistor for a specified pin in a specified port.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void GPIO_enableInternalPullDown(uint8 port_num , uint8 pin_num){
	if(port_num >= NUM_OF_PORTS || pin_num >= NUM_OF_PINS_PER_PORT) {

			/* Do Nothing */

		}

		else{
			/* Enable Internal Pull Down*/
			GPIO_writePin(port_num , pin_num , INTERNAL_PULL_DOWN_VALUE);
		}

}
#endif
