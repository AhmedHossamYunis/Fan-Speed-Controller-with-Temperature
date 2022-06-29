/*
 ================================================================================================
 Name        : ADC.h
 Author      : Ahmed_Hossam
 Description : ADC Driver with and without configuration technique
 Date        : 23-5-2022
 ================================================================================================
 */

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum{
	AREF,AVCC,RESERVED,INTERNAL
}ADC_ReferenceVolatge;

typedef enum{
	F_CPU_OFF,F_CPU_2,F_CPU_4,F_CPU_8,F_CPU_26,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_Prescaler;

typedef struct{
	ADC_ReferenceVolatge REF_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define EXTERNAL_AREF_MODE 0
#define EXTERNAL_AVCC_MODE 0

#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*Enable = 1, Disable = 0*/
#define ADC_INTERRUPT  0

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description:
 * Initialize ADC driver*/
void ADC_init(const ADC_ConfigType *Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 * IInput channel number must be from 0 --> 7 otherwise, Do Nothing.
 */
uint16 ADC_readChannel(uint8 ch_num);




#endif /* ADC_H_ */
