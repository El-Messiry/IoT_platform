/*
 * TypeDefs.h
 *
 *  Created on: Sep 22, 2018
 *      Author: messiry
 */

#ifndef TYPEDEFS_H_
#define TYPEDEFS_H_

typedef unsigned char   u8 ;
typedef unsigned int    u16;
typedef unsigned long   u32;

typedef signed char   s8 ;
typedef signed int    s16;
typedef signed long   s32;



#define SETBIT(portname , pinnumber)     (portname |= (1 << pinnumber))		// Set Bit ( high )
#define CLEARBIT(portname , pinnumber)   (portname &= ~(1 << pinnumber))	// clear it( low  )
#define TOGGLEBIT(portname , pinnumber)  (portname ^= (1 << pinnumber))		// toggle bit
#define READBIT(portname , pinnumber)    (portname & (1 << pinnumber))		// read bit




#define OUTPUT 1
#define INPUT  0

#define HIGH 1
#define LOW  0

#define REV_HIGH   0
#define REV_LOW    1

#define ERR   -1
#define OK     1
#define NOK    0

#define TRUE   1
#define FALSE  0
#define NO_TIMEOUT 0


#define TIMEOUT_10ms	10
#define TIMEOUT_50ms	50
#define TIMEOUT_100ms	100
#define TIMEOUT_200ms	200


#define DT_TEMP 			1
#define DT_LIGHT			2

typedef struct {
	u8  Type;
	u16 CurrentValue;
	u16 PreviousValue;
}DataStruct_t;




#endif /* TYPEDEFS_H_ */
