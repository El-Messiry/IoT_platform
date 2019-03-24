/*
 * DIO.h
 *
 *  Created on: Sep 22, 2018
 *      Author: messiry
 */

#ifndef DIO_H_
#define DIO_H_

#include "../Service_Layer/TypeDefs.h"

// MACROS



/*
 * input : (1) register ( a,A b,B ..etc ) ,
 * 		   (2) pin number(unsigned 0 ---t0---> 7) ,
 * 		   (3) direction (0,1)
 * output: none
 * desc  : used to init port direction output or input
 */
s8 DIO_InitPin  (u8 reg , u8 pin , u8 dir);


/*
* input :  (1) register ( a,A b,B ..etc ) ,
 * 		   (2) pin number(unsigned 0 ---t0---> 7) ,
 * 		   (3) direction (0,1) * output: none
 * desc  : used to write value to  a PIN  HIGH or LOW
 */
s8 DIO_WritePin (u8 reg , u8 pin , u8 dir);


/*
 * input : (1) register ( a,A b,B ..etc ) ,
 * 		   (2) value ( unsigned 8 bit value or hex )
 * output: none
 * desc  : used to init port direction output or input according to 8bit / hex value
 */
s8 DIO_InitPort (u8 reg , u8 value);


/*
 * input : (1) register ( a,A b,B ..etc ) ,
 * 		   (2) value ( unsigned 8 bit value or hex )
 * output: none
 * desc  : used to write port direction output or input according to 8bit / hex value
 */
s8 DIO_WritePort(u8 reg , u8 value);


/*
 * input : (1) register ( a,A b,B ..etc ) ,
 *         (2) pin number(unsigned 0 ---t0---> 7)
 * output: none
 * desc  : used to read PIN direction (0,1) / (HIGH,LOW)
 */
s8 DIO_ReadPin  (u8 reg , u8 pin );


#endif /* DIO_H_ */
