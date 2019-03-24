/*
 * DIO.c
 *
 *  Created on: Sep 22, 2018
 *      Author: messiry
 */


#include "DIO.h"
#include <avr/io.h>
#include "../Service_Layer/TypeDefs.h"



/*
 * input : (1) register ( a,A b,B ..etc ) ,
 * 		   (2) pin number(unsigned 0 ---t0---> 7) ,
 * 		   (3) direction (0,1)
 *
 * output: (1) OK
 * 		   (2) ERR
 *
 * desc  : used to init port direction output or input
 */
s8 DIO_InitPin(u8 reg , u8 pin , u8 dir)
{
	switch(reg)  // switching register name ( A,a B,b C,c D,d )
	{
		case 'A':
		case 'a':
			if(dir)
			{
				SETBIT(DDRA , pin); 	// set PIN direction OUTPUT
			}else
			{
				CLEARBIT(DDRA , pin); 	// set PIN direction INPUT
			}
			return OK;
			break;
		case 'B':
		case 'b':
			if(dir)
			{
				SETBIT(DDRB , pin);		// set PIN direction OUTPUT
			}else
			{
				CLEARBIT(DDRB , pin);	// set PIN direction INPUT
			}
			return OK;
			break;
		case 'D':
		case 'd':
			if(dir)
			{
				SETBIT(DDRD , pin);		// set PIN direction OUTPUT
			}else
			{
				CLEARBIT(DDRD , pin);	// set PIN direction INPUT
			}
			return OK;
			break;
		case 'C':
		case 'c':
			if(dir)
			{
				SETBIT(DDRC , pin);		// set PIN direction OUTPUT
			}else
			{
				CLEARBIT(DDRC , pin);	// set PIN direction INPUT
			}
			return OK;
			break;
		default:
			return ERR; 	// return error , wrong register param.
	}

}


/*
* input :  (1) register ( a,A b,B ..etc ) ,
 * 		   (2) pin number(unsigned 0 ---t0---> 7) ,
 * 		   (3) direction (0,1) *
 *
 * output: (1) OK
 * 		   (2) ERR
 *
 * desc  : used to write value to  a PIN  HIGH or LOW
 */
s8 DIO_WritePin(u8 reg , u8 pin , u8 dir)
{
	switch(reg)
	{

		case 'A':
		case 'a':
			if(dir)
			{
				SETBIT(PORTA , pin);	// make PIN HIGH
			}else
			{
				CLEARBIT(PORTA , pin);	// make PIN LOW
			}
			return OK;
			break;

		case 'B':
		case 'b':
			if(dir)
			{
				SETBIT(PORTB , pin);	// make PIN HIGH
			}else
			{
				CLEARBIT(PORTB , pin);	// make PIN LOW
			}
			return OK;
			break;

		case 'D':
		case 'd':
			if(dir)
			{
				SETBIT(PORTD , pin);	// make PIN HIGH
			}else
			{
				CLEARBIT(PORTD , pin);	// make PIN LOW
			}
			return OK;
			break;

		case 'C':
		case 'c':
			if(dir)
			{
				SETBIT(PORTC , pin);	// make PIN HIGH
			}else
			{
				CLEARBIT(PORTC , pin);	// make PIN LOW
			}
			return OK;
			break;

		default:
			return ERR;	// return error if , register param.
	}
}


/*
 * input : (1) register ( a,A b,B ..etc ) ,
 * 		   (2) value ( unsigned 8 bit value or hex )
 *
 * output: (1) OK
 * 		   (2) ERR
 *
 * desc  : used to init port direction output or input according to 8bit / hex value
 */
s8 DIO_InitPort(u8 reg , u8 value)
{
	switch(reg)
	{
		case 'A':
		case 'a':
			DDRA = value ;		// set PORT direction to the value
			return OK;
			break;

		case 'B':
		case 'b':
			DDRB = value ;		// set PORT direction to the value
			return OK;
			break;

		case 'D':
		case 'd':
			DDRC = value ;		// set PORT direction to the value
			return OK;
			break;

		case 'C':
		case 'c':
			DDRD = value ;		// set PORT direction to the value
			return OK;
			break;

		default:
			return ERR;			// return error , wrong register param.
	}



}

/*
 * input : (1) register ( a,A b,B ..etc ) ,
 * 		   (2) value ( unsigned 8 bit value or hex )
 *
 * output: (1) OK
 * 		   (2) ERR
 *
 * desc  : used to write port direction output or input according to 8bit / hex value
 */
s8 DIO_WritePort(u8 reg , u8 value)
{
	switch(reg)
	{
		case 'A':
		case 'a':
			PORTA = value ;		// Write value to PORTA
			return OK;
			break;

		case 'B':
		case 'b':
			PORTB = value ;		// Write value to PORTB
			return OK;
			break;

		case 'D':
		case 'd':
			PORTD = value ;		// Write value to PORTD
			return OK;
			break;

		case 'C':
		case 'c':
			PORTC = value ;		// Write value to PORTC
			return OK;
			break;

		default:
			return ERR;	// return error , wrong register param.
	}

}


/*
 * input :  (1) register ( a,A b,B ..etc ) ,
 *          (2) pin number(unsigned 0 ---t0---> 7)
 *
 * output:  (1) TRUE
 * 			(2) FALSE
 * 			(3) ERR
 *
 * desc  : used to read PIN direction (0,1) / (HIGH,LOW)
 */
s8 DIO_ReadPin(u8 reg , u8 pin)
{
	switch(reg)
		{
			case 'A':
			case 'a':
				if( READBIT(PINA , pin)) return HIGH;	// return True if PIN(n) is High
				break;

			case 'B':
			case 'b':
				if( READBIT(PINB , pin)) return HIGH;	// return True if PIN(n) is High
				break;

			case 'D':
			case 'd':
				if( READBIT(PIND , pin)) return HIGH;	// return True if PIN(n) is High
				break;

			case 'C':
			case 'c':
				if( READBIT(PINC , pin)) return HIGH;	// return True if PIN(n) is High
				break;

			default:
				return ERR ;	// return error , wrong register param.

		}
	return LOW ;
}
