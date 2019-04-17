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

#include "../HAL/LCD.h"
#include "../HAL/LDR.h"
#include "../HAL/Temperature.h"
#include "../Service_Layer/TypeDefs.h"

/* Micro Controller Abstract Layers Includes  */
#include "../MCAL/ADC.h"
#include "../MCAL/usart_driver.h"

/* Hardware Abstract Layer Includes */
#include "T_Receive.h"

/* Declaration of OS Services */
/* Declare Mutex semaphore for Data Handling Resources */
xSemaphoreHandle Mutex_Data ;			// Mutex handle Data Resources
xSemaphoreHandle BS_RXC_Interrupt;		// BinarySemaphore signal RX interrupt
xSemaphoreHandle BS_TXC_Interrupt;		// BinarySemaphore signal TX interrupt

/* Declaration of Global Resources  */
volatile DataStruct_t TempData ;		// store data related to Temperature
volatile DataStruct_t LightData ;		// store data related to Light Intensity
volatile u8 Pending_Data_F ;			// Pending_Data_F flag to be used by T_SysComm

/* Declaration of Queues services */
xQueueHandle Q_Uart_RX ;				// 1) queue used for RX ISR
xQueueHandle Q_Uart_TX ;				// 2) queue used for TX ISR
xQueueHandle Q_Order ;					// 3) queue used to hold Orders to be Execute


void sys_init(void){
	/*
	 * Description :
	 *
	 * Used to Initialize All MCu Peripherals
	 * 1- LCD init
	 * 2- Wifi init
	 * 3- Light Module init
	 * 4- Temperature Module init
	 * 5- Initialize Values of TEMP & LIGHT Data Variables
	 *
	 */
	// Initializing LCD
	LCD_Init();
	LCD_Clear_Display();

	// Initializing Wifi Module ESP8266 .
	Init_Wifi();

	// Initializing Sensors
	InitLDR();
	InitTemperature();

	// Initializing Globals
	// Temperature Data Type
	TempData.Type = DT_TEMP;
	TempData.CurrentValue  = 0;
	TempData.PreviousValue = 0;
	// Light Intensity Data Type
	LightData.Type = DT_LIGHT ;
	LightData.CurrentValue = 0;
	LightData.PreviousValue= 0;

}

int main (void){

	/* Create Required Mutexs */
	Mutex_Data = xSemaphoreCreateMutex();				// Create Data Mutex
	vSemaphoreCreateBinary(BS_RXC_Interrupt,FALSE);		// Create RX Binary Semaphore
	vSemaphoreCreateBinary(BS_TXC_Interrupt,FALSE);		// Create TX Binary Semaphore

	/* Create Queues Needed */
	Q_Uart_RX = xQueueCreate(20,sizeof(char));	// UART RX queue create ,used by ISR
	Q_Uart_TX = xQueueCreate(20,sizeof(char));	// UART TX queue create ,used by T_Transmit
	Q_Order   = xQueueCreate(5,sizeof(DataStruct_t)); // Order Queue , up to 5 Orders

	/* Initialize System I/O Resources */
	//sys_init();

	/* Create Entry Initialization Task  */
	xTaskCreate(T_Receive,NULL,400,NULL,5,NULL);		// Create Task Receive

	/* Start OS/Scheduler */
	vTaskStartScheduler();

	return 0;
}







