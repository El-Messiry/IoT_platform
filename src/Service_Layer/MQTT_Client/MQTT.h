/*
 * MQTT.h
 *
 *  Created on: Apr 17, 2019
 *      Author: messi
 */

#ifndef SERVICE_LAYER_MQTT_H_
#define SERVICE_LAYER_MQTT_H_

#include "../TypeDefs.h"

void Encode_MQTT(DataStruct_t *pStructData,char *str);
DataStruct_t Decode_MQTT(char *str);


#endif /* SERVICE_LAYER_MQTT_H_ */
