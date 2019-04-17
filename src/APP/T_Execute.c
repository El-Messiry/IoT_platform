/*
 * T_Execute.c
 *
 *  Created on: Apr 16, 2019
 *      Author: messi
 */


#include "T_Execute.h"

#include "../Service_Layer/TypeDefs.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"


extern xQueueHandle Q_Order ;

/*
 * Task to Handle Order Execution
 */
void T_Execute(void *pvData){
	DataStruct_t order;
	u8 status;
	while(1){

		// Block on Q_Order
		status = xQueueReceive(Q_Order,&order,TIMEOUT_100ms);
		if(status == pdPASS){
			// Execute order
		}
		vTaskDelay(TIMEOUT_100ms); //Sleep for 100ms
	}


}
