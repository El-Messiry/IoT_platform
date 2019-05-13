
#include <avr/io.h>
#include <avr/interrupt.h>
#include "usart_driver.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"


extern xQueueHandle Q_Uart_RX ;				// 1) queue used between RX ISR
extern xSemaphoreHandle BS_TXC_Interrupt;	// BinarySemaphore signal TX interrupt

void usart_init(unsigned  int baudrate)
{
	//Set baud rate
	unsigned short int UBRRVAL=(FCLK_SYSTEM/(baudrate*16UL))-1;
	UBRRL=UBRRVAL; 			//low byte
	UBRRH=(UBRRVAL>>8); 	//high byte

	//Set data frame format: asynchronous mode,no parity, 1 stop bit, 8 bit size
	UCSRC=(1<<URSEL)|(0<<UMSEL)|(0<<UPM1)|(0<<UPM0)|(0<<USBS)|(0<<UCSZ2)|(1<<UCSZ1)|(1<<UCSZ0); 

	//Enable Transmitter and Receiver
	UCSRB=(1<<RXEN)|(1<<TXEN);
#if UART_MODE == INTERRUPT
	UCSRB|= (1<<RXCIE)|(1<<TXCIE);
#endif
}


#if (UART_MODE == POLLING) //cad rc
unsigned char usart_getc( void )
{
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) );
	/* Get and return received data from buffer */
	return UDR;
}
void usart_putc( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)));
	/* Put data into buffer, sends the data */
	UDR = data;
}

void usart_puts( char* str )
{
	short int i=0;
	while(str[i])
	{
		usart_putc(str[i]);
		i++;
	}
}

void usart_gets( char* str )
{
	short int i=0;

	while(str[i-1]!="\n")
	{
		str[i]=usart_getc();
		i++;
	}

}

#elif UART_MODE == INTERRUPT

// RX Interrupt Handler
ISR(USART_RXC_vect){
	//xSemaphoreGiveFromISR(BS_RXC_Interrupt,FALSE);	// Give (BS_RXC_Interrupt) Signal
	u8 data ;
	data = UDR;
	xQueueSendFromISR(Q_Uart_RX,&data,FALSE);
}

// TX Interrupt Handler
ISR(USART_TXC_vect){
	xSemaphoreGiveFromISR(BS_TXC_Interrupt,FALSE);	// Give (BS_TXC_Interrupt) Signal
}

#endif
