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

u8 Init_Wifi(void);
void Wifi_Send(DataStruct_t *pStructData);
DataStruct_t Wifi_Receive(void);
u8 Wifi_Connect(void);
u8 Wifi_Disconnect(void);

#endif /* HAL_WIFI_ESP8266_H_ */
