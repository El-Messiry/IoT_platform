/*
 * LDR.h
 *
 *  Created on: Mar 6, 2019
 *      Author: messi
 */

#ifndef HAL_LDR_H_
#define HAL_LDR_H_

#include "../Service_Layer/TypeDefs.h"


#define LIGHT_SENSOR_CHANNEL 			ADC_CHANNEL_7
#define LIGHT_SENSOR_DIRECTION_PORT 	'A'
#define LIGHT_SENSOR_PIN				6

u8 InitLDR(void);

u16 GetLDR(void);


#endif /* HAL_LDR_H_ */
