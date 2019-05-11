/*
 * ESP8266.c
 *
 *  Created on: Mar 11, 2019
 *      Author: messi
 */


#include "Wifi_ESP8266.h"

#include "../MCAL/usart_driver.h"
#include "LCD.h"

extern xQueueHandle Q_Uart_RX ;				// 1) queue used For RX Buffer
extern xQueueHandle Q_Uart_TX ;				// 2) queue used For TX Buffer

extern xSemaphoreHandle BS_TXC_Interrupt;	// BinarySemaphore signal TX interrupt
extern xSemaphoreHandle BS_MSG_RCVD;	// BinarySemaphore signal TX interrupt


static void Put_TX_Q(char *str){
	/*
	 * Description:
	 * 		Load String Bytes to Queue (Q_Uart_TX)
	 * 		to be sent By UART
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

static void Get_RX_Q(char *str,u32 TimeOut){
	/*
	 * Description:
	 * 		Get String Bytes from Queue (Q_Uart_RX)
	 * 		to be Decoded into Information, it returns
	 * 		if End of String('\0')or new line ('\n)operator received
	 * NOTE: EOF '\0' could happen after
	 * 		carriage return & new line '\r\n' , but Wifi Module
	 * 		can send those between actual messages
	 * 		so it should be handled to discard those inter-messages
	 * 		carriage return and new line
	 */
	u8 index=0, data=0, OnGoing_F=TRUE;
	while(OnGoing_F){
		if(xQueueReceive(Q_Uart_RX,&data,TimeOut)){
			if('\n'==data || '\0'==data){	// terminate if (new line)or(NuLL) is received
				OnGoing_F=FALSE;			// Exit Loop
				str[index]='\0'; 			// add null operator at the end of string
				return;
			}
			else{	// store characters into buffer
				str[index]=data;
				index++;
			}
		}
	}

}

static u8 Check_Response(char *Expected_str , char *Given_str){
	/*
	 * Description:
	 * 		Checks if the response is the expected or not
	 * Return:
	 * 		(TRUE)  if response is a match
	 * 		(FALSE) if response is a no match
	 */


	return strcmp(*Expected_str,*Given_str);
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


	LCD_Init();
	LCD_Clear_Display();

	char rx_buffer[50]={0},response=0;		// buffer to hold response

	Put_TX_Q("UART Running");			// send TEST on UART channel
	Get_RX_Q(rx_buffer,portMAX_DELAY);	// Receive TEST MSG mack to insure UART TX/RX is Valid
	LCD_Send_String(rx_buffer);

	if(strcmp("UART Runnin",rx_buffer)){
		LCD_GoTO_Row_Colunmn(1,0);
		LCD_Send_String("FALSE");
		return TRUE;
	}
	else{
		// wifi not responding
		LCD_GoTO_Row_Colunmn(1,0);
		LCD_Send_String("TRUE");
		return FALSE;
	}


	/*
	 * ESP8266 Driver still to be implemented
	 */
}
