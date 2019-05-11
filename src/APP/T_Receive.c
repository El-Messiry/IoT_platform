/*
 * T_Receive.c
 *
 *  Created on: Mar 9, 2019
 *      Author: messi
 */

#include <avr/interrupt.h>


#include "T_TX_Handler.h"

#include "T_Receive.h"
#include "T_Transmit.h"
#include "T_DataInputs.h"
#include "T_Execute.h"
#include "T_Display.h"


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
#include "../HAL/Wifi_ESP8266.h"

#include "../MCAL/ADC.h"
#include "../MCAL/usart_driver.h"


extern xQueueHandle Q_Uart_RX ;				// 1) queue used between RX ISR
extern xSemaphoreHandle BS_MSG_RCVD;

extern void T_Display(void *pvData);
extern void T_DataInputs(void *pvData);
extern void T_Transmit(void *pvData);
extern void T_Execute(void *pvData);
extern void T_TX_Handler(void *pvData);

/*
 * Task to Handle Data Reception
 */
void T_Receive(void *pvData){



	// Create Tasks
//	xTaskCreate(T_Display,NULL,200,NULL,1,NULL);		// Display Task
//	xTaskCreate(T_DataInputs,NULL,200,NULL,2,NULL);		// Data Inputs Task
//	xTaskCreate(T_Execute,NULL,100,NULL,3,NULL);		// Transmit Task
//	xTaskCreate(T_Transmit,NULL,100,NULL,4,NULL);		// Transmit Task
	xTaskCreate(T_TX_Handler,NULL,50,NULL,6,NULL);		// TX Task Interrupt Handler


	// Initializing Wifi Module ESP8266 .

	LCD_Init();
	LCD_Clear_Display();

	if(Init_Wifi()){
		LCD_Send_String("TRUE");
		Diagnostics_Display("Wifi connected");
	}
	else{
		LCD_Send_String("FALSE");
		Diagnostics_Display("Wifi conn fail");
	}



	while(1){



		vTaskDelay(2000);
	}


}
