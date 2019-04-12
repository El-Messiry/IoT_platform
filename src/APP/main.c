/*
 * main.c
 *
 *  Created on: Feb 16, 2019
 *      Author: messiry
 */



/* include os header files */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"
#include "../Service_Layer/TypeDefs.h"

/* Micro Controller Abstract Layers Includes  */
#include "../MCAL/ADC.h"
#include "../MCAL/usart_driver.h"

/* Hardware Abstract Layer Includes */
#include "../MHAL/LCD.h"
#include "../MHAL/LDR.h"
#include "../MHAL/Temperature.h"


#include "T_SysComm.h"

/* Declaration of OS Services */
//declare Mutex semaphore for Data Handling Resources
xSemaphoreHandle Mutex_Data ;

/* Declaration of Global Resources  */
volatile DataStruct_t TempData ;		// store data related to Temperature
volatile DataStruct_t LightData ;		// store data related to Light Intensity
volatile u8 Pending_Data_F ;			// Pending_Data_F flag to be used by T_SysComm

/* Declaration of Queues services */
xQueueHandle Q_Uart_RX ;				// 1) queue used between RX ISR & T_SysComm
xQueueHandle Q_Uart_TX ;				// 2) queue used between TX ISR & T_SysComm


int main (void){

	/* Create Required Mutexs */
	Mutex_Data = xSemaphoreCreateMutex();

	/* Create Queues Needed */
	Q_Uart_RX = xQueueCreate(20,sizeof(char));	// UART RX queue created and used by ISR
	Q_Uart_RX = xQueueCreate(20,sizeof(char));	// UART TX queue created and used by ISR

	/* Create Entry Initialization Task  */
	xTaskCreate(T_SysComm,NULL,400,NULL,5,NULL);

	/* Start OS/Scheduler */
	vTaskStartScheduler();

	return 0;
}

void sys_init(void){
	// Initialize LCD
	LCD_Init();
	LCD_Clear_Display();

	//Initialize UART Baud 9600
	usart_init(9600);
	//usart_puts("UART READY\r\n");

	// Initialize ADC Related Sensors
	InitLDR();
	InitTemperature();


	// Initialize Globals
	// Temperature Data Type
	TempData.Type = DT_TEMP;
	TempData.CurrentValue  = 0;
	TempData.PreviousValue = 0;
	// Light Intensity Data Type
	LightData.Type = DT_LIGHT ;
	LightData.CurrentValue = 0;
	LightData.PreviousValue= 0;
}






