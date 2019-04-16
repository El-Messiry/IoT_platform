/*
 * T_Transmit.c
 *
 *  Created on: Mar 9, 2019
 *      Author: messi
 */

#include "T_Transmit.h"


#include "../Service_Layer/TypeDefs.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"


#include "../MCAL/ADC.h"
#include "../MCAL/usart_driver.h"

extern DataStruct_t TempData,LightData ;
extern volatile u8 Pending_Data_F ;



/*
 * Task to Handle Data Transmission
 */
void T_Transmit(void *pvData){

	u8 data;

	while(1){





		vTaskDelay(2);
	}


}
