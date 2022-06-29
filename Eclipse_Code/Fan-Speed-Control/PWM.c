/*
 ================================================================================================
 Name        : PWM.c
 Author      : Ahmed_Hossam
 Description : PWM Driver to control motor speed
 Date        : 23-5-2022
 ================================================================================================
 */

#include "PWM.h"
#include <avr/io.h>
#include "gpio.h"
#include "common_macros.h"

/*Description:
 * 1- The function responsible for trigger the Timer0 with the PWM Mode.
 * 2- Setup the PWM mode with Non-Inverting.
 * 3- Setup the prescaler with F_CPU/8.
 * 4- Setup the compare value based on the required input duty cycle.
 * 5- Setup the direction for OC0 as output pin through the GPIO driver.
 * 6- The generated PWM signal frequency will be 500Hz to control the DC Motor speed.
 * */
void PWM_Timer0_Start(uint8 duty_cycle) /*Mapping can be used try it*/
{ 
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	SET_BIT(TCCR0,COM01);
	SET_BIT(TCCR0,CS01);

	TCNT0 = 0;

	OCR0 = (duty_cycle*255)/100;

	GPIO_setupPinDirection(TIMER0_PORT_ID, TIMER0_PIN_ID, PIN_OUTPUT);



}

