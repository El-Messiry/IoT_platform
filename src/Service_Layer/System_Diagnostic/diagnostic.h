/*
 * diagnostic.h
 *
 *  Created on: Apr 17, 2019
 *      Author: messi
 */

#ifndef SERVICE_LAYER_SYSTEM_DIAGNOSTIC_DIAGNOSTIC_H_
#define SERVICE_LAYER_SYSTEM_DIAGNOSTIC_DIAGNOSTIC_H_

#include "../TypeDefs.h"
#include "FreeRTOS.h"
#include "queue.h"


#define ENABLE 		1
#define DISABLE 	0
#define DIAGNOSTICS ENABLE

#if DIAGNOSTICS == ENABLE
typedef struct {
	char content[16];
}DisplayStruct_t;


extern xQueueHandle Q_Diagnostics ;


void Init_DisplayDiagnostic(void);
void Diagnostics_Display(char str_enum);
#endif
#endif /* SERVICE_LAYER_SYSTEM_DIAGNOSTIC_DIAGNOSTIC_H_ */
