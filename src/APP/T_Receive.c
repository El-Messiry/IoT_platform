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



/*
 * Task to Handle Data Reception
 */
void T_Receive(void *pvData){



	// Create Tasks



	// Initializing Wifi Module ESP8266 .


	if(Init_Wifi()){
		Diagnostics_Display("Wifi connected");
	}
	else{
		Diagnostics_Display("Wifi conn fail");
	}



	while(1){



		vTaskDelay(2000);
	}


}
