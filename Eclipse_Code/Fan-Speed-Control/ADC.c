/*
 ================================================================================================
 Name        : ADC.c
 Author      : Ahmed_Hossam
 Description : ADC Driver with and without configuration technique
 Date        : 23-5-2022
 ================================================================================================
 */


#include "common_macros.h"
#include <avr/io.h>
#include "ADC.h"


/*
 * Description:
 * Initialize ADC driver*/

void ADC_init(const ADC_ConfigType *Config_Ptr)
{
	/*REF VOLTAGE*/
	ADMUX |= (ADMUX & 0x3F)| ((Config_Ptr->REF_volt)<<6);

	/*ADLAR   = 0 right adjusted.*/
	CLEAR_BIT(ADMUX, ADLAR);

	/* ADEN    = 1 Enable ADC.*/
	SET_BIT(ADCSRA,ADEN);

#if (ADC_ENALBE_INTERRUPT)
	/* Enable interrupt */
	SET_BIT(ADCSRA, ADIE);
#else
	/* Disable interrupt */
	CLEAR_BIT(ADCSRA, ADIE);
#endif

	/*PRESCALER*/
	ADCSRA |= (ADCSRA & 0xF8)|(Config_Ptr->prescaler);


}


/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 * Input channel number must be from 0 --> 7 otherwise, Do Nothing.
 */
uint16 ADC_readChannel(uint8 ch_num)
{
	/* Description:
	 * Input channel number must be from 0 --> 7.
	 * Clear 1st 5 bits in ADMUX before set the required channel.
	 * Start conversion by set ABSC = 1 in ADCSRA register.
	 * Wait conversion to complete by polling technique.
	 * Clear the flag by set ADIF = 1 in ADCSRA.
	 * return the digital value from the data register.*/
	if(ch_num > 7)
	{
		/*Do Nothing */
	}
	else
	{
		ADMUX |= (ADMUX & 0xE0 )| (ch_num & 0x1F);

		SET_BIT(ADCSRA, ADSC);

		while(BIT_IS_CLEAR(ADCSRA, ADIF));

		SET_BIT(ADCSRA, ADIF);
	}
	return ADC;

}
