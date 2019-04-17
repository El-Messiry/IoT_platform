/*
 * ESP8266.h
 *
 *  Created on: Mar 11, 2019
 *      Author: messi
 */

#ifndef HAL_WIFI_ESP8266_H_
#define HAL_WIFI_ESP8266_H_

#include "../Service_Layer/TypeDefs.h"

#define WIFI_CHECK ""

void Init_Wifi(void);
void Wifi_Send(DataStruct_t *pvdata);
DataStruct_t * Wifi_Receive(void);
static void Load_TX_Q(char *str);

#endif /* HAL_WIFI_ESP8266_H_ */
