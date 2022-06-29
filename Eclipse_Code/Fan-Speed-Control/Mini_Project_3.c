/*
 ================================================================================================
 Name        : Mini_Project_3.c
 Author      : Ahmed_Hossam
 Description : Fan Controller system using ADC, LCD, DCMOTOR, LM35_SENSOR and PWM Drivers
 Date        : 24-5-2022
 ================================================================================================
 */

#include "PWM.h"
#include "MOTOR.h"
#include "LCD.h"
#include "ADC.h"
#include "lm35_sensor.h"


int main(void)
{
	/* Read Temperature the sensor*/
	uint8 readingTemp;

	/* Create configuration structure for ADC driver */
	ADC_ConfigType ADC_Config = {INTERNAL,F_CPU_8};

	/*Initialize LCD Driver*/
	LCD_init();

	/*Initialize ADC Driver using configuration technique*/
	ADC_init(&ADC_Config);

	/*Initialize DC Motor Driver*/
	DcMotor_Init();

	/*Set the curser position  */
	LCD_displayStringRowColumn(0,3,"FAN is");
	LCD_displayStringRowColumn(1,3,"TEMP =     C");


	while(1)
	{
		/*Read data from the sensor. */
		readingTemp = LM35_getTemperature();

		if(readingTemp >= 100)
		{
			LCD_setCurser(1,10);
			LCD_intgerToString(readingTemp);
		}
		else
		{
			LCD_displayStringRowColumn(1,12," ");
			LCD_setCurser(1,10);
			LCD_intgerToString(readingTemp);
		}

		if(readingTemp < 30)
		{
			DcMotor_Rotate(MOTOR_STOP, 0);
			LCD_displayStringRowColumn(0,10,"OFF");

		}
		else if((readingTemp >=30 ) && (readingTemp < 60) )
		{
			DcMotor_Rotate(MOTOR_CCW, 25);
			LCD_displayStringRowColumn(0,10,"ON ");
		}
		else if((readingTemp >=60 ) && (readingTemp < 90) )
		{
			DcMotor_Rotate(MOTOR_CCW, 50);
			LCD_displayStringRowColumn(0,10,"ON ");
		}
		else if((readingTemp >=90 ) && (readingTemp < 120) )
		{
			DcMotor_Rotate(MOTOR_CCW, 75);
			LCD_displayStringRowColumn(0,10,"ON ");
		}
		else if(readingTemp >= 120  )
		{
			DcMotor_Rotate(MOTOR_CCW, 100);
			LCD_displayStringRowColumn(0,10,"ON ");
		}
	}
}
