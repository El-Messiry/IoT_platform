/*
 * LDR.h
 *
 *  Created on: Mar 6, 2019
 *      Author: messi
 */

#ifndef MHAL_LDR_H_
#define MHAL_LDR_H_

#include "../Service_Layer/TypeDefs.h"


#define LIGHT_SENSOR_CHANNEL 			ADC_CHANNEL_7
#define LIGHT_SENSOR_DIRECTION_PORT 	'A'
#define LIGHT_SENSOR_PIN				6

u8 InitLDR(void);

u16 GetLDR(void);


#endif /* MHAL_LDR_H_ */
