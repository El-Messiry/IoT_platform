/*
 * diagnostic.c
 *
 *  Created on: Apr 17, 2019
 *      Author: messi
 */

#include "diagnostic.h"
#include "../My_Strings/MemoryStrings.h"

#if DIAGNOSTICS == ENABLE
// Display Queue
xQueueHandle Q_Diagnostics ;

void Init_DisplayDiagnostic(void){
	/*
	 * Description:
	 * 		Initialize Empty Queue for Messages to be sent on
	 * Usage:
	 * 		1-create variable of type "BufferStruct_st"
	 * 		2-use "Diagnostics_Display('STR_Enumeration')" function
	 *
	 * NOTE: always keep Your messages below 16 character
	 */
	Q_Diagnostics   = xQueueCreate(5,sizeof(BufferStruct_st)); 	// Display Queue , up to 5 Messages
}

void Diagnostics_Display(char str_enum){
	/*
	 * Description:
	 * 		Used to send Diagnostic Messages to be displayed by Display Task
	 * 		Also used in case of an error message should be displayed
	 */

	BufferStruct_st Message;	// Buffer Structure
	// msg length should always be less than 16 characters
	Message = Get_ROM_String(str_enum,TABLE_DIAGNOSTIC);

	// Send Message into Queue (Q_Display)
	xQueueSend(Q_Diagnostics,&Message,TIMEOUT_200ms);
	// Now Display TASK will Handle all Diagnostic Messages Sent
}
#endif
