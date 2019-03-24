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



void T_DataInputs(void *pvData){


	while(1){

		// Get Tempreature
		TempData.CurrentValue = GetTemperature();
		LightData.CurrentValue= GetLDR();

		vTaskDelay(500);
	}
}
