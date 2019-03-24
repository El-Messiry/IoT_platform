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
//declare Binary semaphore for Tempdata & LightData

/* Declaration of Globals  */
volatile DataStruct_t TempData ;
volatile DataStruct_t LightData ;

int main (void){

	/* Create Entry Initialization Task  */
	xTaskCreate(T_SysComm,NULL,400,NULL,5,NULL);

	/* Start OS/Scheduler */
	vTaskStartScheduler();

	return 0;
}






