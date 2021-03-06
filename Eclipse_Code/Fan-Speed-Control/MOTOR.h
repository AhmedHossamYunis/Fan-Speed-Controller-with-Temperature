/*
 ================================================================================================
 Name        : MOTOR.h
 Author      : Ahmed_Hossam
 Description : DC motor driver control the speed by PWM and direction.
 Date        : 23-5-2022
 ================================================================================================
 */

#include "std_types.h"

#ifndef MOTOR_H_
#define MOTOR_H_

#define MOTOR_PORT_ID PORTB_ID
#define MOTOR_PIN0_ID  PIN0_ID
#define MOTOR_PIN1_ID  PIN1_ID

typedef enum
{
	MOTOR_STOP,MOTOR_CW, MOTOR_CCW
}DCMOTOR_State;




/*Description:
 * 1- The Function responsible for setup the direction for the two motor pins
 *  through the GPIO driver.
 * 2- Stop at the DC-Motor at the beginning through the GPIO driver. */
void DcMotor_Init(void);

/*Description:
 *1- The function responsible for rotate the DC Motor CW/ or A-CW or
 *   stop the motor based on the state input state value.
 *2- Send the required duty cycle to the PWM driver based on the
 *   required speed value.
 */
void DcMotor_Rotate(DCMOTOR_State state,uint8 speed);

#endif /* MOTOR_H_ */
