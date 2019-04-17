/*
 * T_Receive.c
 *
 *  Created on: Mar 9, 2019
 *      Author: messi
 */

#include "T_Receive.h"

#include "T_Display.h"
#include "T_DataInputs.h"
#include "T_Execute.h"
#include "T_Transmit.h"
#include "T_TX_Handler.h"


#include "../Service_Layer/TypeDefs.h"
#include "../Service_Layer/System_Diagnostic/diagnostic.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"

#include "../HAL/LCD.h"
#include "../HAL/LDR.h"
#include "../HAL/Temperature.h"

#include "../MCAL/ADC.h"
#include "../MCAL/usart_driver.h"


extern xQueueHandle Q_Uart_RX ;				// 1) queue used between RX ISR
extern xSemaphoreHandle BS_RXC_Interrupt;	// BinarySemaphore signal RX interrupt

extern void T_Display(void *pvData);
extern void T_DataInputs(void *pvData);
extern void T_Transmit(void *pvData);
extern void T_Execute(void *pvData);
/*
 * Task to Handle Data Reception
 */
void T_Receive(void *pvData){



	// Create Tasks
	xTaskCreate(T_Display,NULL,200,NULL,1,NULL);		// Display Task
	xTaskCreate(T_DataInputs,NULL,200,NULL,2,NULL);		// Data Inputs Task
	xTaskCreate(T_Execute,NULL,100,NULL,3,NULL);		// Transmit Task
	xTaskCreate(T_Transmit,NULL,100,NULL,4,NULL);		// Transmit Task
	xTaskCreate(T_TX_Handler,NULL,50,NULL,6,NULL);		// TX Task Interrupt Handler

	// Initializing Wifi Module ESP8266 .
	if(Init_Wifi()){
		Diagnostics_Display("Wifi connected");
	}
	else{
		Diagnostics_Display("Wifi conn fail");
	}


	while(1){

		// Block on Event Signal (BS_RXC_Interrupt) Indicating A Full String Received

		if(xSemaphoreTake(BS_RXC_Interrupt,0)){	// wait for signal
			while(uxQueueMessagesWaiting(Q_Uart_RX)!=0){
				// Process Queue Data while not empty
			}
		}

		vTaskDelay(2);
	}


}
