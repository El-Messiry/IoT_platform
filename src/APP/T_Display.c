/*
 * Display.c
 *
 *  Created on: Mar 9, 2019
 *      Author: messi
 */

#include "T_Display.h"


#include "../Service_Layer/TypeDefs.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"

#include "../HAL/LCD.h"

extern DataStruct_t TempData,LightData ;

void T_Display(void *pvData){

	LCD_GoTO_Row_Colunmn(0,0);
	LCD_Send_String("Temp :    C ");
	LCD_GoTO_Row_Colunmn(1,0);
	LCD_Send_String("Light:    %");

	while(1){



		//Display_Data();
		vTaskDelay(200);
	}
}

void Display_Data(void){


	if(TempData.CurrentValue != TempData.PreviousValue){
		// Store new Value
		TempData.PreviousValue = TempData.CurrentValue ;
		// Update Temperature
		char Temp_buffer[4];
		LCD_GoTO_Row_Colunmn(0,6);
		LCD_Send_String("   ");
		LCD_GoTO_Row_Colunmn(0,7);
		itoa(TempData.CurrentValue, Temp_buffer, 10);
		LCD_Send_String(Temp_buffer);

	}

	if(LightData.CurrentValue != LightData.PreviousValue){
		// Store new Value
		LightData.PreviousValue = LightData.CurrentValue ;
		char Light_buffer[4];
		//Update Light
		LCD_GoTO_Row_Colunmn(1,6);
		LCD_Send_String("   ");
		LCD_GoTO_Row_Colunmn(1,7);
		itoa(LightData.CurrentValue, Light_buffer, 10);
		LCD_Send_String(Light_buffer);
	}
}
