/*
 * diagnostic.c
 *
 *  Created on: Apr 17, 2019
 *      Author: messi
 */

#include "diagnostic.h"


// Display Queue
xQueueHandle Q_Display ;

void Init_DisplayDiagnostic(void){
	/*
	 * Description:
	 * 		Initialize Empty Queue for Messages to be sent on
	 * Usage:
	 * 		1-create variable of type "DisplayStruct_t"
	 * 		2-use "Diagnostics_Display('your message')" function
	 * 		NOTE: always keep ur message below 16 character
	 */
	Q_Display   = xQueueCreate(5,sizeof(DisplayStruct_t)); 	// Display Queue , up to 5 Messages
}

void Diagnostics_Display(char *str){
	/*
	 * Description:
	 * 		Used to send Diagnostic Messages to be displayed by Display Task
	 * 		Also used in case of an error message should be displayed
	 */

	DisplayStruct_t Message;	// Message Structure
	// msg length should always be less than 16 characters
	for(int index=0;index<16;index++){
		Message.content[index]=str[index]; // load message content
	}
	// Send Message into Queue (Q_Display)
	xQueueSend(Q_Display,&Message,TIMEOUT_200ms);
	// Now Display Function will Handle all incoming Messages
}
