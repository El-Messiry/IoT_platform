/*
 * Temperature.h
 *
 *  Created on: Oct 6, 2018
 *      Author: messiry
 */

#ifndef TEMPERATURE_H_
#define TEMPERATURE_H_

#include "../Service_Layer/TypeDefs.h"


#define TEMP_SENSOR_CHANNEL 		ADC_CHANNEL_5
#define TEMP_SENSOR_DIRECTION_PORT 	'A'


u8 InitTemperature(void);
u16 GetTemperature(void);

#endif /* TEMPERATURE_H_ */
