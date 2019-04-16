/*
 * ESP8266.c
 *
 *  Created on: Mar 11, 2019
 *      Author: messi
 */


#include "Wifi_ESP8266.h"

#include "../MCAL/usart_driver.h"

extern xQueueHandle Q_Uart_RX ;				// 1) queue used between RX ISR
extern xQueueHandle Q_Uart_TX ;				// 2) queue used between TX ISR
extern xSemaphoreHandle BS_RXC_Interrupt;	// BinarySemaphore signal RX interrupt
extern xSemaphoreHandle BS_TXC_Interrupt;	// BinarySemaphore signal TX interrupt


void Init_Wifi(void){
	//Initialize UART Baud 9600
	usart_init(9600);


	/*
	 * 1) Connect to available wifi nearby
	 * 2) after successful Connection, Connect to the MQTT server
	 * 3) check for successful Connection
	 * 4) connection failure should be handles properly by trying 3 times
	 * 5) incase of connection failure a message should be displayed
	 */

	/*
	 * ESP8266 Driver still to be implemented
	 */

	return;

}


void Wifi_Send(DataStruct_t *pvdata){
	/*
	 * Description:
	 *
	 * Used to Send the Data Through Wifi Module
	 *
	 */

	/*
	 * Transmit Sequence:
	 *
	 * 1) Given the Data in Integer format, change it to Char format
	 * 2) String Concatenate the new data into the URL in MQTT format
	 * 3) check the complete url after concatenation
	 * 4) After Complete String Generation you pass pointer
	 *    to the string holding the Complete URL and push it to the queue
	 */

	char *str="wifi send : 0"; // str should point to the final URL
	u8 index=0;
	while( str[index] ){						// while str[index] != '\0'
		xQueueSend(Q_Uart_TX,&str[index],0);	// send char to Queue
		index++;								// increment index
	}
	xQueueSend(Q_Uart_TX,&str[index],0);	// send '\0' (End of String) to Queue
	xSemaphoreGive(BS_TXC_Interrupt);		// Signal the First Byte to Transmit
	/*
	 * T_TX_Handler will run transmitting First Byte
	 * after successful transmission of First Byte
	 * TXC ISR will signal to transmit remaining Bytes
	 */



	/*
	 * ESP8266 Driver still to be implemented
	 */
	return;
}


DataStruct_t * Wifi_Receive(void){
	/*
	 * Description:
	 *
	 * Used to Receive the Incoming Data from Wifi Module
	 *
	 */
	DataStruct_t * data;


	/*
	 * ESP8266 Driver still to be implemented
	 */
	return data;
}
