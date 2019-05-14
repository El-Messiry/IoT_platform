/*
 * MemoryStrings.h
 *
 *  Created on: May 13, 2019
 *      Author: messi
 */

#ifndef SERVICE_LAYER_MEMORYSTRINGS_H_
#define SERVICE_LAYER_MEMORYSTRINGS_H_

#include <avr/pgmspace.h>
#include "../TypeDefs.h"



/*
 * Data Related ENUMS ************
 */
enum{
	STR_TEMP
};


/*
 * Diagnostic Related ENUMS ************
 */
enum{
	STR_UartTest=0,
	STR_UartRunning,
	STR_UartConnFail,
	STR_WifiTest,
	STR_WifiConnected,
	STR_WifiConnFAIL
};


/*
 * Wifi Related ENUMs ************
 */
enum{
	STR_KeepAlive=0,
	STR_CheckConnection
};


/*
 * Strin TABLE Related ENUMs ************
 */
enum{
	TABLE_DATA,
	TABLE_DIAGNOSTIC,
	TABLE_WIFI
};

#define MAX_STRING_LENGTH 16
#define MAX_STRING_NUMBER 255



BufferStruct_st Get_ROM_String(u8 string_enum, u8 String_Table);


#endif /* SERVICE_LAYER_MEMORYSTRINGS_H_ */
