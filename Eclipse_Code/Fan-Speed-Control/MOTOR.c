/*
 ================================================================================================
 Name        : MOTOR.c
 Author      : Ahmed_Hossam
 Description : DC motor driver control the speed by PWM and direction.
 Date        : 23-5-2022
 ================================================================================================
 */

#include "MOTOR.h"
#include "gpio.h"
#include "common_macros.h"
#include "PWM.h"

/*Description:
 * 1- The Function responsible for setup the direction for the two motor pins
 *  through the GPIO driver.
 * 2- Stop at the DC-Motor at the beginning through the GPIO driver. */
void DcMotor_Init(void)
{
	GPIO_setupPinDirection(MOTOR_PORT_ID, MOTOR_PIN0_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_PORT_ID, MOTOR_PIN1_ID, PIN_OUTPUT);
	GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN0_ID, LOGIC_LOW);
	GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN1_ID, LOGIC_LOW);
	return ;
}

/*Description:
 *1- The function responsible for rotate the DC Motor CW/ or A-CW or
 *   stop the motor based on the state input state value.
 *2- Send the required duty cycle to the PWM driver based on the
 *   required speed value.
 */
void DcMotor_Rotate(DCMOTOR_State state ,uint8 speed)
{
	if(state == MOTOR_CW)
	{
		GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN0_ID, LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN1_ID, LOGIC_HIGH);
		PWM_Timer0_Start(speed);
	}
	else if(state == MOTOR_CCW)
	{
		GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN0_ID, LOGIC_HIGH);
		GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN1_ID, LOGIC_LOW);
		PWM_Timer0_Start(speed);
	}
	else if (state == MOTOR_STOP)
	{
		GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN0_ID, LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN1_ID, LOGIC_LOW);
		PWM_Timer0_Start(speed);
	}
	return;
}



