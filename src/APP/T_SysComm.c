/*
 * SysComm.c
 *
 *  Created on: Mar 9, 2019
 *      Author: messi
 */

#include "T_SysComm.h"

#include "../Service_Layer/TypeDefs.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"


#include "../MCAL/ADC.h"
#include "../MCAL/usart_driver.h"

#include "../MHAL/LCD.h"
#include "../MHAL/LDR.h"
#include "../MHAL/Temperature.h"




extern DataStruct_t TempData,LightData ;
extern void T_Display(void *pvData);
extern void T_DataInputs(void *pvData);


void T_SysComm(void *pvData){

	// Initialize LCD
	LCD_Init();
	LCD_Clear_Display();

	//Initialize UART Baud 9600
	usart_init(9600);
	usart_puts("UART READY\r\n");

	// Initialize ADC Related Sensors
	InitLDR();
	InitTemperature();
	ADC_Init();

	// Initialize Globals
	// Temperature Data Type
	TempData.Type = DT_TEMP;
	TempData.CurrentValue  = 0;
	TempData.PreviousValue = 0;
	// Light Intensity Data Type
	LightData.Type = DT_LIGHT ;
	LightData.CurrentValue = 0;
	LightData.PreviousValue= 0;

	// Create Tasks
	xTaskCreate(T_Display,NULL,200,NULL,1,NULL);
	xTaskCreate(T_DataInputs,NULL,200,NULL,2,NULL);



	while(1){

		// implement all System Communication related code
		// to be implemented yet

		vTaskDelay(2);
	}


}
