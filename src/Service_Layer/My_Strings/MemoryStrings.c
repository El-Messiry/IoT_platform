/*
 * MemoryStrings.c
 *
 *  Created on: May 13, 2019
 *      Author: messi
 */

#include "MemoryStrings.h"


/*
 * Data Related Strings ************
 */

static const char DATA_string_1[]  PROGMEM = " ";
static const char DATA_string_2[]  PROGMEM = " ";
static const char DATA_string_3[]  PROGMEM = " ";
static const char DATA_string_4[]  PROGMEM = " ";
static const char DATA_string_5[]  PROGMEM = " ";
static const char DATA_string_6[]  PROGMEM = " ";
static const char DATA_string_7[]  PROGMEM = " ";
static const char DATA_string_8[]  PROGMEM = " ";
static const char DATA_string_9[]  PROGMEM = " ";
static const char DATA_string_10[] PROGMEM = " ";
static const char DATA_string_11[] PROGMEM = " ";

// Array of pointers to strings stored in ROM (PGM_P type)
static const PGM_P DATA_string_table[] PROGMEM =
{
		DATA_string_1,
		DATA_string_2,
		DATA_string_3,
		DATA_string_4,
		DATA_string_5,
		DATA_string_6,
		DATA_string_7,
		DATA_string_8,
		DATA_string_9,
		DATA_string_10,
		DATA_string_11
};

#if DIAGNOSTICS == ENABLE
/*
 * Diagnostic Related Strings ************
 */
static const char DIG_string_1[]  PROGMEM = "UART TEST";
static const char DIG_string_2[]  PROGMEM = "UART Running";
static const char DIG_string_3[]  PROGMEM = "UART FAIL";
static const char DIG_string_4[]  PROGMEM = "Wifi TEST";
static const char DIG_string_5[]  PROGMEM = "Wifi Connected";
static const char DIG_string_6[]  PROGMEM = "Wifi Conn FAIL";
static const char DIG_string_7[]  PROGMEM = " ";
static const char DIG_string_8[]  PROGMEM = " ";
static const char DIG_string_9[]  PROGMEM = " ";
static const char DIG_string_10[] PROGMEM = " ";
static const char DIG_string_11[] PROGMEM = " ";

// Array of pointers to strings stored in ROM (PGM_P type)
static const PGM_P DIG_string_table[] PROGMEM =
{
		DIG_string_1,
		DIG_string_2,
		DIG_string_3,
		DIG_string_4,
		DIG_string_5,
		DIG_string_6,
		DIG_string_7,
		DIG_string_8,
		DIG_string_9,
		DIG_string_10,
		DIG_string_11
};
#endif

/*
 * Wifi Related Strings ************
 */

static const char WIFI_string_1[]  PROGMEM = " ";
static const char WIFI_string_2[]  PROGMEM = " ";
static const char WIFI_string_3[]  PROGMEM = " ";
static const char WIFI_string_4[]  PROGMEM = " ";
static const char WIFI_string_5[]  PROGMEM = " ";
static const char WIFI_string_6[]  PROGMEM = " ";
static const char WIFI_string_7[]  PROGMEM = " ";
static const char WIFI_string_8[]  PROGMEM = " ";
static const char WIFI_string_9[]  PROGMEM = " ";
static const char WIFI_string_10[] PROGMEM = " ";
static const char WIFI_string_11[] PROGMEM = " ";

// Array of pointers to strings stored in ROM (PGM_P type)
static const PGM_P WIFI_string_table[] PROGMEM =
{
		WIFI_string_1,
		WIFI_string_2,
		WIFI_string_3,
		WIFI_string_4,
		WIFI_string_5,
		WIFI_string_6,
		WIFI_string_7,
		WIFI_string_8,
		WIFI_string_9,
		WIFI_string_10,
		WIFI_string_11
};



BufferStruct_st Get_ROM_String(u8 string_enum, u8 String_Table){
	/*
	 * Description :
	 * 		Function that takes string & table enums , returns string from ROM
	 * 		TABLES AVAILABLE:
	 * 			   1) TABLE_DATA
	 * 			   2) TABLE_DIAGNOSTIC
	 * 			   3) TABLE_WIFI
	 * Usage:
	 * 		I/P  : 1) String Enumeration (each enum start with 'STR_' )
	 * 			   2) String Table Enumeration (each start with 'TABLE_')
	 *
	 * 		O/P  : 1) Structure which holds string retrieved from ROM
	 */
	BufferStruct_st Ram_Buffer;

	switch(String_Table){	// every table has its own related strings
	case TABLE_DATA:
		strcpy_P(Ram_Buffer.content, (PGM_P)pgm_read_word(&(DATA_string_table[string_enum])));
		break;
#if DIAGNOSTICS == ENABLE
	case TABLE_DIAGNOSTIC:
		strcpy_P(Ram_Buffer.content, (PGM_P)pgm_read_word(&(DIG_string_table[string_enum])));
		break;
#endif
	case TABLE_WIFI:
		strcpy_P(Ram_Buffer.content, (PGM_P)pgm_read_word(&(WIFI_string_table[string_enum])));
		break;

	default:
		// do nothing
		break;
	}

	return Ram_Buffer;
}
