/*
 * LDR.c
 *
 *  Created on: Mar 6, 2019
 *      Author: messi
 */



#include "../HAL/LDR.h"

#include "../MCAL/ADC.h"
#include "../MCAL/DIO.h"

u8 InitLDR(void){
	DIO_InitPin( 'a' , 6, INPUT);
	return OK;
}

u16 GetLDR(void){
	float Light_Intensity = ADC_Read(6);
	Light_Intensity = ADC_Read(6);
	Light_Intensity = ADC_Read(6); // to ensure correct reading of the channel after selection

	Light_Intensity = ((Light_Intensity/800)*100) ;
	// "800" is the max value that LDR can reach when direct light is applied
	return (u16)Light_Intensity;
}
