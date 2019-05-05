/*
 * T_TX_Handler.c
 *
 *  Created on: Apr 16, 2019
 *      Author: messi
 */



#include "T_Transmit.h"


#include "../Service_Layer/TypeDefs.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"


extern xQueueHandle Q_Uart_TX ;				// 2) queue used between TX ISR
extern xSemaphoreHandle BS_TXC_Interrupt;	// BinarySemaphore signal TX interrupt

void T_TX_Handler(void *pvData){
	/*
	 * Description:
	 *
	 * T_TX_Handler is executed Right After the TXC Interrupt
	 * is Executed and Binary semaphore ( BS_TXC_Interrupt )
	 * is given so it can continue sending the remaining Bytes
	 * in the Queue ( Q_Uart_TX )
	 *
	 */

	u8 data;
	while(1){
		/* Block on BS_TXC_Interrupt Signal */
		if(xSemaphoreTake(BS_TXC_Interrupt,portMAX_DELAY)){
			xQueueReceive(Q_Uart_TX,&data,0);
			/* Put data into buffer, sends the data */
			UDR = data;
			if('\0'==data){
				// last byte of string sent , so must receive its TXC signal
				// so it won't stuck in a loop
				xSemaphoreTake(BS_TXC_Interrupt,TIMEOUT_50ms);
			}
		}
	}
}



