/*
 * Temperature.c
 *
 *  Created on: Oct 6, 2018
 *      Author: messiry
 */


#include "../HAL/Temperature.h"

#include "../MCAL/ADC.h"
#include "../MCAL/DIO.h"
#include <avr/io.h>


u8 InitTemperature(void){
	DIO_InitPin('a', 5, INPUT);
	return OK;
}

u16 GetTemperature(void){
	u16 Temperature = ADC_Read(5);
	Temperature = ADC_Read(5);
	Temperature = ADC_Read(5);	// to ensure correct reading of the channel after selection
	return ((Temperature * 4.88)/10);
}
