/*
 * ESP8266.c
 *
 *  Created on: Mar 11, 2019
 *      Author: messi
 */


#include "Wifi_ESP8266.h"

#include "../MCAL/usart_driver.h"

extern xQueueHandle Q_Uart_RX ;				// 1) queue used For RX Buffer
extern xQueueHandle Q_Uart_TX ;				// 2) queue used For TX Buffer
extern xSemaphoreHandle BS_RXC_Interrupt;	// BinarySemaphore signal RX interrupt
extern xSemaphoreHandle BS_TXC_Interrupt;	// BinarySemaphore signal TX interrupt


static void Put_TX_Q(char *str){
	/*
	 * Description:
	 * Load String Bytes to Queue (Q_Uart_TX)
	 * to be sent By UART
	 */
	u8 index=0;
	while( str[index] ){						// while str[index] != '\0'
		xQueueSend(Q_Uart_TX,&str[index],0);	// send char to Queue
		index++;								// increment index
	}
	xQueueSend(Q_Uart_TX,&str[index],0);	// send '\0' (End of String) to Queue
	xSemaphoreGive(BS_TXC_Interrupt);		// Signal the First Byte to Transmit
	/*
	 * Task T_TX_Handler is Locked on Semaphore (BS_TXC_Interrupt)
	 * so Task will run transmitting First Byte
	 * after successful transmission of First Byte, TXC ISR
	 * will signalSemaphore (BS_TXC_Interrupt) to transmit remaining Bytes
	 */
}

static void Get_RX_Q(char *str,u8 TimeOut){
	/*
	 * Description:
	 * Get String Bytes from Queue (Q_Uart_RX)
	 * to be Decoded into Information, it returns
	 * if End of String operator reached
	 * NOTE: EOF '\0' could happen after
	 * carriage return & new line '\r\n' , but Wifi Module
	 * can send those between actual messages
	 * so it should be handled to discard those inter-messages
	 * carriage return and new line
	 */
	u8 byte,index=0;
	while(uxQueueMessagesWaiting(Q_Uart_RX)!=0){
		// Process Queue Data while not empty
		if(xQueueReceive(Q_Uart_RX,&byte,TIMEOUT_200ms)){	// receive byte
			str[index]=byte;		// copy byte into str
			index++;				// increment index
			if(byte == '\0'){		// if End of String Reached
				str[index] = '\0' ;	// put '\0' into str
				return ;			// return
			}
		}
	}
}

static u8 Check_Response(char *Expected_str , char *Given_str){
	/*
	 * Description:
	 * 		Checks if the response is the expected or not
	 * Return:
	 * 		(TRUE) if response is a match
	 * 		(FALSE) if response is a no match
	 */

	u8 index_expected=0,index_given=0,Match_F=FALSE;


	// implement function body


	return Match_F;

}


void Wifi_Send(DataStruct_t *pStructData){
	/*
	 * Description:
	 * Used to Send the Data Through Wifi Module
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


	//char *str = Encode_MQTT(*pStructData) ;

	char *str="wifi send : 0"; // str should point to the final URL

	Put_TX_Q(str);	// Load str to TX buffer

	/*
	 * ESP8266 Driver still to be implemented
	 */
	return;
}


DataStruct_t Wifi_Receive(void){
	/*
	 * Description:
	 *
	 * Used to Receive the Incoming Data from Wifi Module
	 *
	 */
	DataStruct_t data;


	//

	/*
	 * ESP8266 Driver still to be implemented
	 */
	return data;
}

u8 Init_Wifi(void){
	//Initialize UART Baud 9600
	usart_init(9600);
	// make enable TX&RX function
	// flush the receive buffer Q_Uart_RX & Q_Uart_TX

	/*
	 * 1) Connect to available wifi nearby
	 * 2) after successful Connection, Connect to the MQTT server
	 * 3) check for successful Connection
	 * 4) connection failure should be handles properly by trying 3 times
	 * 5) incase of connection failure a message should be displayed
	 */


	u8 rx_buffer[30],response;					// buffer to hold response

	Put_TX_Q("UART Running ..");		// send on uart channel
	vTaskDelay(1000);
	Put_TX_Q("Now trying WIFI");		// send on uart channel
	// wait for Signal ( BS_RXC_Interrupt )
	if(xSemaphoreTake(BS_RXC_Interrupt,TIMEOUT_200ms)){
		Get_RX_Q(rx_buffer,TIMEOUT_200ms);	// receive on rx buffer
		response = Check_Response("UART Running ..",rx_buffer); //loop back check
	}

	if(TRUE==response){
		// wifi is running
		return TRUE;
	}
	else{
		// wifi not responding
		return FALSE;
	}


	/*
	 * ESP8266 Driver still to be implemented
	 */
}
