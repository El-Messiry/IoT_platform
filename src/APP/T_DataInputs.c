/*
 * T_DataInputs.c
 *
 *  Created on: Mar 9, 2019
 *      Author: messi
 */

#include "T_DataInputs.h"

#include "../Service_Layer/TypeDefs.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"

// This should be removed as app layer should only call "MHAL"
// reblace uart send with "ESP driver or Communication Layer in HAL that uses "ESP"
#include "../MCAL/usart_driver.h"

#include "../MHAL/LDR.h"
#include "../MHAL/Temperature.h"

extern DataStruct_t TempData,LightData ;
extern volatile u8 Pending_Data_F ;




void T_DataInputs(void *pvData){


	while(1){

		// Get Tempreature
		TempData.CurrentValue = GetTemperature();
		LightData.CurrentValue= GetLDR();


		// take Mutex
		xSemaphoreTake( Mutex_Data, 1000 ); // Time out of 1 sec
		{
			/* The following lines will only execute once the mutex has been
			successfully obtained. */

			// see if data changed from previous reading
			if(TempData.CurrentValue != TempData.PreviousValue )
				Pending_Data_F = TRUE;
			else if(LightData.CurrentValue != LightData.PreviousValue)
				Pending_Data_F = TRUE;
			else
				Pending_Data_F = FALSE; // Data remained unchanged , do nothing

		}
		xSemaphoreGive( Mutex_Data );
		// Release Mutex

		vTaskDelay(1000); 	// Suspend Task for 1 Sec
	}
}

