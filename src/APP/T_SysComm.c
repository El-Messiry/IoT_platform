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
extern volatile u8 Pending_Data_F ;
extern void T_Display(void *pvData);
extern void T_DataInputs(void *pvData);


void T_SysComm(void *pvData){

	// Create Tasks
	xTaskCreate(T_Display,NULL,200,NULL,1,NULL);
	xTaskCreate(T_DataInputs,NULL,200,NULL,2,NULL);



	while(1){

		// event based on received data from queue RX.
		// event based on transmitted data over queue TX.

		vTaskDelay(2);
	}


}
