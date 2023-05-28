/*
 * main.c
 *
 *  Created on: Sep 28, 2021
 *      Author: taqwa
 */

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "SENSOR_interface.h"
#include "LCD_interface.h"
#include "glove_Interface.h"
#include "util/delay.h"
int main(void)
{

	ADC_voidInit();
	LCD_enuInit();
	FLEX_SENSOR_voidInit(ADC_0);
	FLEX_SENSOR_voidInit(ADC_1);
	FLEX_SENSOR_voidInit(ADC_2);
	FLEX_SENSOR_voidInit(ADC_3);
	FLEX_SENSOR_voidInit(ADC_4);

	u8 Local_u8ADC1=0 ,Local_u8ADC2=0,Local_u8ADC3=0,Local_u8ADC4=0,Local_u8ADC5=0;
	while(1)
	{

		Local_u8ADC1 = FLEX_SNESOR_u8Read(ADC_0);
		Local_u8ADC2 = FLEX_SNESOR_u8Read(ADC_1);
		Local_u8ADC3 = FLEX_SNESOR_u8Read(ADC_2);
		Local_u8ADC4 = FLEX_SNESOR_u8Read(ADC_3);
		Local_u8ADC5 = FLEX_SNESOR_u8Read(ADC_4);
		Gloves_VoidStartWork(Local_u8ADC1 , Local_u8ADC2 ,Local_u8ADC3 ,Local_u8ADC4 ,Local_u8ADC5);
		_delay_ms(500);
		LCD_voidClearScreen();
		_delay_ms(500);

	}



	return 0;

}
